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


"void"		{	//printf("Detecté 'void' TOK_VOID genere\n");
				print_token("TOK VOID");
				return TOK_VOID;
			}
"int"		{	//printf("Detecté 'int' TOK_INT généré\n");
				print_token("TOK INT");
				return TOK_INT;
			}
"bool"		{	//printf("Detecté 'bool' TOK_BOOL généré\n");
				print_token("TOK BOOL");
				return TOK_BOOL;
			}
"if"		{	//printf("Detecté 'if' TOK_IF genere\n");
				print_token("TOK IF");
				return TOK_IF;
			}
"true"		{	//printf("Detecté 'true' TOK_TRUE genere\n");
				print_token("TOK TRUE");
				return TOK_TRUE;
			}
"false"		{	//printf("Detecté 'false' TOK_FALSE genere\n");
				print_token("TOK FALSE");
				return TOK_FALSE;
			}
"else"		{	//printf("Detecté 'else' TOK_ELSE genere\n");
				print_token("TOK ELSE");
				return TOK_ELSE;
			}
"while"		{	//printf("Detecté 'while' TOK_WHILE genere\n");
				print_token("TOK WHILE");
				return TOK_WHILE;
			}
"for"		{	//printf("Detecté 'for' TOK_FOR genere\n");
				print_token("TOK FOR");
				return TOK_FOR;
			}
"do"		{	//printf("Detecté 'do' TOK_DO genere\n");
				print_token("TOK DO");
				return TOK_DO;
			}
"print"		{	//printf("Detecté 'print' TOK_PRINT genere\n");
				print_token("TOK PRINT");
				return TOK_PRINT;
			}
"+" 		{	//printf("Detecté '+' TOK_PLUS généré\n");
				print_token("TOK PLUS");
				return TOK_PLUS;
			}
"-"			{	//printf("Detecté '-' TOK_MINUS généré\n");
				print_token("TOK MINUS");
				return TOK_MINUS;
			}
"*"			{	//printf("Detecté '*' TOK_MUL généré\n");
				print_token("TOK MUL");
				return TOK_MUL;
			}
"/"			{	//printf("Detecté '/' TOK_DIV généré\n");
				print_token("TOK DIV");
				return TOK_DIV;
			}
"%"			{	//printf("Detecté '%%' TOK_MOD généré\n");
				print_token("TOK MOD");
				return TOK_MOD;
			}
">"			{	//printf("Detecté '>' TOK_GT généré\n");
				print_token("TOK GT");
				return TOK_GT;
			}
"<"			{	//printf("Detecté '<' TOK_LT généré\n");
				print_token("TOK LT");
				return TOK_LT;
			}
"!"			{ /*c'est la negation boolenne*/
				//printf("Detecté '!' TOK_NOT généré\n");
				print_token("TOK NOT");
				return TOK_NOT;
			}
"~"			{	//printf("Detecté '~' TOK_BNOT généré\n");
				print_token("TOK BNOT");
				return TOK_BNOT;
			}
"&"			{	//printf("Detecté '&' TOK_BAND généré\n");
				print_token("TOK BAND");
				return TOK_BAND;
			}
"|"			{	//printf("Detecté '|' TOK_BOR généré\n");
				print_token("TOK BOR");
				return TOK_BOR;
			}
"^"			{	//printf("Detecté '^' TOK_BXOR généré\n");
				print_token("TOK BXOR");
				return TOK_BXOR;
			}
"="			{	//printf("Detecté '=' TOK_AFFECT généré\n");
				print_token("TOK AFFECT");
				return TOK_AFFECT;
			}
";"			{	//printf("Detecté ';' TOK_SEMICOL généré\n");
				print_token("TOK SEMICOL");
				return TOK_SEMICOL;
			}
","			{	//printf("Detecté ',' TOK_COMMA généré\n");
				print_token("TOK COMMA");
				return TOK_COMMA;
			}
"("			{	//printf("Detecté '(' TOK_LPAR généré\n");
				print_token("TOK LPAR");
				return TOK_LPAR;
			}
")"			{	//printf("Detecté ')' TOK_RPAR généré\n");
				print_token("TOK RPAR");
				return TOK_RPAR;
			}
"{"			{	//printf("Detecté '{' TOK_LACC généré\n");
				print_token("TOK LACC");
				return TOK_LACC;
			}
"}"			{	//printf("Detecté '}' TOK_RACC généré\n");
				print_token("TOK RACC");
				return TOK_RACC;
			}
">>"		{	//printf("Detecté '>>' TOK_SRL généré\n");
				print_token("TOK SRL");
				return TOK_SRL;
			}
">>>"		{	//printf("Detecté '>>>' TOK_SRA généré\n");
				print_token("TOK SRA");
				return TOK_SRA;
			}
"<<"		{	//printf("Detecté '<<' TOK_SLL généré\n");
				print_token("TOK SLL");
				return TOK_SLL;
			}
">="		{	//printf("Detecté '>=' TOK_GE généré\n");
				print_token("TOK GE");
				return TOK_GE;
			}
"<="		{	//printf("Detecté '<=' TOK_LE généré\n");
				print_token("TOK LE");
				return TOK_LE;
			}
"=="		{	//printf("Detecté '==' TOK_EQ généré\n");
				print_token("TOK EQ");
				return TOK_EQ;
			}
"!="		{	//printf("Detecté '!=' TOK_NE généré\n");
				print_token("TOK NE");
				return TOK_NE;
			}
"&&"		{	//printf("Detecté '&&' TOK_AND généré\n");
				print_token("TOK AND");
				return TOK_AND;
			}
"||"		{	//printf("Detecté '||' TOK_OR généré\n");
				print_token("TOK OR");
				return TOK_OR;
			}



{IDF} {
				yylval.strval = strdup(yytext);
				if (strcmp (strdup(yytext), "main") == 0 )
				{
					 mainflag = 1 ;
				 }
                //printf("Detecté idf '%s' TOK_IDENT généré\n",yytext);
				print_token("TOK IDENT");
                return TOK_IDENT;
}

{ENTIER} {
                yylval.intval = atoi(yytext);
                //printf("Detecté entier %s, TOK_INTVAL généré\n",yytext );
				print_token("TOK INTVAL");
                return TOK_INTVAL;
}

{CHAINE} {
                yylval.strval = strdup(yytext);
                //printf("Detecté chaine %c TOK_STRING généré",*yytext);
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
    /* A completer */
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
	free_tree(program_root, 0);
    return 0;
}
