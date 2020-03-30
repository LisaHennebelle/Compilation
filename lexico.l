%{
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "defs.h"
#include "common.h"

#include "y.tab.h"

void yyerror(char *);
int yyparse(node_t * program_root);
int fileno(FILE * stream);
void analyse_tree(node_t root);


char * infile = NULL;
char * outfile = NULL;
bool stop_after_syntax = false;
bool stop_after_verif = false;
/* A completer */

#if YYDEBUG
extern int yydebug;
#endif

%}

%option yylineno
CARAC_SPECIAUX [\040-\057\072-100\133-\140\173-\176]

/*Super <3  il faut regarder les tokens à générer  aussi je pense ==> dès qu'on en génére un il faut le caler dans 'grammar.y' */
//un token pour toutes les définitions?
LETTRE          [a-zA-Z]
CHIFFRE			[0-9]
ENTIER			('-'|'')[1-9]{CHIFFRE}*
IDF             {LETTRE}({LETTRE}|{CHIFFRE}|'_')*
ASCII           [\040-\176]
CHAINE          ({ASCII})+
COMMENTAIRE     "//"({ASCII})*[\n]

%%


"void"          return TOK_VOID;






{IDF} {
                yylval.strval = strdup(yytext);
                printf("idf %c",*yytext);
                return TOK_IDENT;
}

{ENTIER} {      /* complété mais pas testé */ /* tu veux qu'on ecrive un fichier minic et qu'on fasse des printf pour tester ? */
				//comment on fait ça ? Le test? je sais pas XD mdr
                yylval.intval = atoi(yytext);
                printf("entier %c",*yytext);
                return TOK_INTVAL;


{CHAINE} {                      /*  complété mais pas testé */
                yylval.strval = strdup(yytext);
                printf("chaine %c",*yytext);
                /*switch pour vérifier qu'il ne s'agit pas d'un mot réservé, sinon génération du token correspondant*/
                switch (yytext)
                {
                    case "main":
                        return
                    default:
                        return TOK_STRING;

                }
}

{COMMENTAIRE} { /* y a un token pour les commentaires ?*/ /* ça compile btw*/
                yylval.strval = strdup(yytext);
                printf("%c",*yytext);
}


[ \t\n]+

. {
                fprintf(stderr, "Error line %d: Lexical error\n", yylineno);
                exit(1);
}


%%

int yywrap(void) {
    return 1;
}


int main(int argc, char ** argv) {
    /* A completer */
    node_t program_root;
    parse_args(argc, argv);
    #if YYDEBUG
    yydebug = 1;
    #endif

    yyin = fopen(infile, "r");
    yyparse(&program_root);
    fclose(yyin);
    analyse_tree(program_root);
    yylex_destroy();
    return 0;
}
