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


/*je pose là les carcacteres speciaux et les token correspondant, je sais pas encore comment faire le lien*/
/* "+" : TOK_PLUS "-": TOK_MINUS "*" : TOK_MUL  "/" :TOK_DIV "%" : TOK_MOD    ">":TOK_GT      "<": TOK_LT     "!": TOK_? : c'est la negation boolenne*/
/* "~" : TOK_BNOT "&": TOK_BAND  "|" : TOK_BOR  "^" :TOK_BXOR "=": TOK_AFFECT ";":TOK_SEMICOL ",": TOK_COMMA  "(": TOK_LPAR */
/* ")" : TOK_RPAR "{" : TOK_LACC "}" : TOK_RACC ">>":TOK_SRL ">>>": TOK_SRA   "<<":TOK_SLL    ">=":TOK_GE     "<=":TOK_LE*/
/* "==": TOK_EQ   "!=": TOK_NE   "&&": TOK_AND  "||": TOK_OR*/




CARACSPECIAUX	[\040-\057\072-\100\133-\140\173-\176]
LETTRE          [a-zA-Z]
CHIFFRE         [0-9]
ENTIER          ('-'|'')[1-9]{CHIFFRE}*
IDF             {LETTRE}({LETTRE}|{CHIFFRE}|'_')*
ASCII           [\040-\176]
/* cf sujet : CHAINE_CAR est l’ensemble de tous les caractères imprimables, à l’exception des caractères ’"’ et ’\’.*/
CHAINE_CAR      ({ASCII})+
/*({LETTRE}|{CHIFFRE}|{CARACSPECIAUX})+*/
CHAINE          '"'({CHAINE_CAR} | '\"' | '\n')*'"'
COMMENTAIRE     "//"({ASCII})*[\n]

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
"int"           {printf("Detecté 'int'\n");return TOK_INT;}
"+" 			return TOK_PLUS;
"-"				return TOK_MINUS;
"*"				return TOK_MUL;
"/"				return TOK_DIV;
"%"				return TOK_MOD;
">"				return TOK_GT;
"<"				return TOK_LT;
"!"				return TOK_NOT; /*c'est la negation boolenne*/
"~"				return TOK_BNOT; /*difference entre '!' et '~' ?*/
"&"				return TOK_BAND;
"|"				return TOK_BOR;
"^"				return TOK_BXOR;
"="				{printf("Detecté '='\n");return TOK_AFFECT;}
";"				return TOK_SEMICOL;
","				return TOK_COMMA;
"("				return TOK_LPAR;
")"				return TOK_RPAR;
"{"				return TOK_LACC;
"}"				return TOK_RACC;
">>"			return TOK_SRL;
">>>"			return TOK_SRA;
"<<"			return TOK_SLL;
">="			return TOK_GE;
"<="			return TOK_LE;
"=="			return TOK_EQ;
"!="			return TOK_NE;
"&&"			return TOK_AND;
"||"			return TOK_OR;



{IDF} {
				yylval.strval = strdup(yytext);
                printf("Detecté idf '%s'\n",yytext);
                return TOK_IDENT;
}

{ENTIER} {      /* complété mais pas testé */
                yylval.intval = atoi(yytext);
                printf("Detecté entier %c",*yytext);
                return TOK_INTVAL;
}

{CHAINE} {
                yylval.strval = strdup(yytext);
                printf("Detecté chaine %c",*yytext);

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


	printf("main1\n");
    yyin = fopen(infile, "r");
	printf("main2\n");
    yyparse(&program_root);
	printf("main3\n");
    fclose(yyin);
	printf("main4\n");
    analyse_tree(program_root);
	printf("main5\n");
    yylex_destroy();
	printf("main6\n");
    return 0;
}
