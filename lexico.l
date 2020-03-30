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


LETTRE          [a-zA-Z]
IDF             {LETTRE}({LETTRE}|{ENTIER}|_)*
ENTIER          [0-9]
ASCII           [\040-\176]
CHAINE          ({ASCII})+
COMMENTAIRE     "//"({ASCII})*[\n]
/*
[] = ensemble d'une valeur à une autre
{} = contenu d'un autre identificateur
() je pense que tu peux le repeter
B'd'acc*/
%%


"void"          return TOK_VOID;






{IDF} {
                yylval.strval = strdup(yytext);
                return TOK_IDENT;
}

{ENTIER} {
                /* A completer : affecter yylval.intval et faire des verifications */
                return TOK_INTVAL;
}

{CHAINE} {
                /* A completer : affecter yylval.strval */
                return TOK_STRING; /*c'est bien une chaine de caractères*/
}

{COMMENTAIRE} {
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
