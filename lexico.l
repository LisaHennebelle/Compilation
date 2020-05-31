%{

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#define couleur(param) printf("\033[%sm",param)
#include "defs.h"
#include "common.h"
#include "context.h"
#include "y.tab.h"

void print_token(char*);
void yyerror(char *);
int yyparse(node_t * program_root);
int fileno(FILE * stream);
void analyse_tree(node_t root);
void free_tree(node_t root, int tab);

char * infile = NULL;
char * outfile = NULL;
int nbtraces = 0;
int nbregistres;
int vflag;
int sflag;
int mainflag = 0 ;
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




LETTRE          [a-zA-Z]
CHIFFRE         [0-9]
ENTIER          [0-9]{CHIFFRE}*
IDF             {LETTRE}({LETTRE}|{CHIFFRE}|'_')*
ASCII           [\040-\176]
CHAINE_CAR      ({ASCII})+
CHAINE          '"'({CHAINE_CAR}|'\"'|'\n')*'"'
COMMENTAIRE     "//"({ASCII})*[\n]

%%


"void"		{
				print_token("TOK VOID");
				return TOK_VOID;
			}
"int"		{
				print_token("TOK INT");
				return TOK_INT;
			}
"bool"		{
				print_token("TOK BOOL");
				return TOK_BOOL;
			}
"if"		{
				print_token("TOK IF");
				return TOK_IF;
			}
"true"		{
				print_token("TOK TRUE");
				return TOK_TRUE;
			}
"false"		{
				print_token("TOK FALSE");
				return TOK_FALSE;
			}
"else"		{
				print_token("TOK ELSE");
				return TOK_ELSE;
			}
"while"		{
				print_token("TOK WHILE");
				return TOK_WHILE;
			}
"for"		{
				print_token("TOK FOR");
				return TOK_FOR;
			}
"do"		{
				print_token("TOK DO");
				return TOK_DO;
			}
"print"		{
				print_token("TOK PRINT");
				return TOK_PRINT;
			}
"+" 		{
				print_token("TOK PLUS");
				return TOK_PLUS;
			}
"-"			{
				print_token("TOK MINUS");
				return TOK_MINUS;
			}
"*"			{
				print_token("TOK MUL");
				return TOK_MUL;
			}
"/"			{
				print_token("TOK DIV");
				return TOK_DIV;
			}
"%"			{
				print_token("TOK MOD");
				return TOK_MOD;
			}
">"			{
				print_token("TOK GT");
				return TOK_GT;
			}
"<"			{
				print_token("TOK LT");
				return TOK_LT;
			}
"!"			{
				print_token("TOK NOT");
				return TOK_NOT;
			}
"~"			{
				print_token("TOK BNOT");
				return TOK_BNOT;
			}
"&"			{
				print_token("TOK BAND");
				return TOK_BAND;
			}
"|"			{
				print_token("TOK BOR");
				return TOK_BOR;
			}
"^"			{
				print_token("TOK BXOR");
				return TOK_BXOR;
			}
"="			{
				print_token("TOK AFFECT");
				return TOK_AFFECT;
			}
";"			{
				print_token("TOK SEMICOL");
				return TOK_SEMICOL;
			}
","			{
				print_token("TOK COMMA");
				return TOK_COMMA;
			}
"("			{
				print_token("TOK LPAR");
				return TOK_LPAR;
			}
")"			{
				print_token("TOK RPAR");
				return TOK_RPAR;
			}
"{"			{
				print_token("TOK LACC");
				return TOK_LACC;
			}
"}"			{
				print_token("TOK RACC");
				return TOK_RACC;
			}
">>"		{
				print_token("TOK SRL");
				return TOK_SRL;
			}
">>>"		{
				print_token("TOK SRA");
				return TOK_SRA;
			}
"<<"		{
				print_token("TOK SLL");
				return TOK_SLL;
			}
">="		{
				print_token("TOK GE");
				return TOK_GE;
			}
"<="		{
				print_token("TOK LE");
				return TOK_LE;
			}
"=="		{
				print_token("TOK EQ");
				return TOK_EQ;
			}
"!="		{	print_token("TOK NE");
				return TOK_NE;
			}
"&&"		{
				print_token("TOK AND");
				return TOK_AND;
			}
"||"		{
				print_token("TOK OR");
				return TOK_OR;
			}



{IDF} {
				yylval.strval = strdup(yytext);
				if (strcmp (strdup(yytext), "main") == 0 )
				{
					 mainflag = 1 ;
				 }
                print_token("TOK IDENT");
                return TOK_IDENT;
}

{ENTIER} {
                yylval.intval = atoi(yytext);
                print_token("TOK INTVAL");
                return TOK_INTVAL;
}

{CHAINE} {
                yylval.strval = strdup(yytext);
                print_token("TOK STRING");
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

void print_token(char* tok)
{
	if(nbtraces == 1)
		printf("%s\n", tok);
}

int main(int argc, char ** argv) {
	const char* txtname;

	parse_args(argc, argv);
    #if YYDEBUG
    yydebug = 1;
    #endif

	node_t program_root;
    yyin = fopen(infile, "r");
	yyparse(&program_root);
	analyse_tree(program_root);

	fclose(yyin);
    yylex_destroy();
    return 0;
}
