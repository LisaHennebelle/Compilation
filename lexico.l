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
int nbtraces;
int nbregistres;
int vflag;
int sflag;

bool stop_after_syntax = false;
bool stop_after_verif = false;
/* A completer */

#if YYDEBUG
extern int yydebug;
#endif

%}

%option yylineno

CARACSPECIAUX [\040-\057\072-100\133-\140\173-\176]

/*je pose là les carcacteres speciaux et les token correspondant, je sais pas encore comment faire le lien*/
/* "+" : TOK_PLUS "-": TOK_MINUS "*" : TOK_MUL  "/" :TOK_DIV "%" : TOK_MOD    ">":TOK_GT      "<": TOK_LT     "!": TOK_? : c'est la negation boolenne*/
/* "~" : TOK_BNOT "&": TOK_BAND  "|" : TOK_BOR  "^" :TOK_BXOR "=": TOK_AFFECT ";":TOK_SEMICOL ",": TOK_COMMA  "(": TOK_LPAR */
/* ")" : TOK_RPAR "{" : TOK_LACC "}" : TOK_RACC ">>":TOK_SRL ">>>": TOK_SRA   "<<":TOK_SLL    ">=":TOK_GE     "<=":TOK_LE*/
/* "==": TOK_EQ   "!=": TOK_NE   "&&": TOK_AND  "||": TOK_OR*/




LETTRE          [a-zA-Z]
CHIFFRE         [0-9]
ENTIER          ('-'|'')[1-9]{CHIFFRE}*
IDF             {LETTRE}({LETTRE}|{CHIFFRE}|'_')*
ASCII           [\040-\176]
/* cf sujet : CHAINE_CAR est l’ensemble de tous les caractères imprimables, à l’exception des caractères ’"’ et ’\’.*/
CHAINE_CAR      ({LETTRE}|{CHIFFRE}|{CARACSPECIAUX})+
CHAINE          """({CHAINE_CAR} | '\"' | '\n')*"""
COMMENTAIRE     "//"({CHAINE})*[\n]

%%


"void"          return TOK_VOID;
"if"            return TOK_IF;
"bool"          return TOK_BOOL;
"true"          return TOK_TRUE;
"false"         return TOK_FALSE;
"else"          return TOK_ELSE;
"while"         return TOK_WHILE;
"for"           return TOK_FOR;
"do"            return TOK_DO;
"print"         return TOK_PRINT;
"int"           return TOK_INT;



{IDF} {
                yylval.strval = strdup(yytext);
                printf("idf %c\n",*yytext);
                return TOK_IDENT;
}

{ENTIER} {      /* complété mais pas testé */
                yylval.intval = atoi(yytext);
                printf("entier %c",*yytext);
                return TOK_INTVAL;
}

{CHAINE} {
                yylval.strval = strdup(yytext);
                printf("chaine %c",*yytext);

                return TOK_STRING;

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
