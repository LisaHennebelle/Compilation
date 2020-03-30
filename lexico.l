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
/*//un token pour toutes les définitions? ça dépend faut checke le sujet*/
LETTRE          [a-zA-Z]
CHIFFRE			[0-9]
ENTIER			('-'|'')[1-9]{CHIFFRE}*
IDF             {LETTRE}({LETTRE}|{CHIFFRE}|'_')*
ASCII           [\040-\176]
CHAINE          ({LETTRE}|{CHIFFRE}|{CARAC_SPECIAUX})+
COMMENTAIRE     "//"({CHAINE})*[\n]

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
                if ((strcmp(yytext,"if"))
                {
                    return TOK_IF;
                }
                else if((strcmp(yytext,"int")) /* heureusement tu es là, par contre tok_void est déjà défnini :/ */
					//ah oui mmm
                {
                    return TOK_INT; /* ligne 45, peut ètre faut pas mettre celui la */
                }
                else if((strcmp(yytext,"bool"))
                {
                    return TOK_BOOL;
                }
                else if((strcmp(yytext,"true"))
                {
                    return TOK_TRUE;
                }
                else if((strcmp(yytext,"false"))
                {
                    return TOK_FALSE;
                }
                else if((strcmp(yytext,"else"))
                {
                    return TOK_ELSE;
                }
                else if((strcmp(yytext,"while"))
                {
                    return TOK_WHILE;
                }
                else if((strcmp(yytext,"for"))
                {
                    return TOK_FOR;
                }
                else if((strcmp(yytext,"do"))
                {
                    return TOK_DO;
                }
                else if((strcmp(yytext,"print"))
                {
                    return TOK_PRINT;
                }
                else
                {return TOK_STRING;}







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
