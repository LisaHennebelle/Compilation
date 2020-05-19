%{

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#define couleur(param) printf("\033[%sm",param)
#include "defs.h"
#include "common.h"
#include "context.h"
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
ENTIER          ("-")?[0-9]{CHIFFRE}*
IDF             {LETTRE}({LETTRE}|{CHIFFRE}|'_')*
ASCII           [\040-\176]
/* cf sujet : CHAINE_CAR est l’ensemble de tous les caractères imprimables, à l’exception des caractères ’"’ et ’\’.*/
CHAINE_CAR      ({ASCII})+
/*({LETTRE}|{CHIFFRE}|{CARACSPECIAUX})+*/
CHAINE          '"'({CHAINE_CAR}|'\"'|'\n')*'"'
COMMENTAIRE     "//"({ASCII})*[\n]

%%


"void"          {printf("Detecté 'void' TOK_VOID genere\n");return TOK_VOID;}
"if"            {printf("Detecté 'if' TOK_IF genere\n");return TOK_IF;}
"bool"          {printf("Detecté 'bool' TOK_BOOL genere\n");return TOK_BOOL;}
"true"          {printf("Detecté 'true' TOK_TRUE genere\n");return TOK_TRUE;}
"false"         {printf("Detecté 'false' TOK_FALSE genere\n");return TOK_FALSE;}
"else"          {printf("Detecté 'else' TOK_ELSE genere\n");return TOK_ELSE;}
"while"         {printf("Detecté 'while' TOK_WHILE genere\n");return TOK_WHILE;}
"for"           {printf("Detecté 'for' TOK_FOR genere\n");return TOK_FOR;}
"do"            {printf("Detecté 'do' TOK_DO genere\n");return TOK_DO;}
"print"         {printf("Detecté 'print' TOK_PRINT genere\n");return TOK_PRINT;}
"int"           {printf("Detecté 'int' TOK_INT généré\n");return TOK_INT;}
"+" 			{printf("Detecté '+' TOK_PLUS généré\n");return TOK_PLUS;}
"-"				{printf("Detecté '-' TOK_MINUS généré\n");return TOK_MINUS;}
"*"				{printf("Detecté '*' TOK_MUL généré\n");return TOK_MUL;}
"/"				{printf("Detecté '/' TOK_DIV généré\n");return TOK_DIV;}
"%"				{printf("Detecté '%' TOK_MOD généré\n");return TOK_MOD;}
">"				{printf("Detecté '>' TOK_GT généré\n");return TOK_GT;}
"<"				{printf("Detecté '<' TOK_LT généré\n");return TOK_LT;}
"!"				{printf("Detecté '!' TOK_NOT généré\n");return TOK_NOT;} /*c'est la negation boolenne*/
"~"				{printf("Detecté '~' TOK_BNOT généré\n");return TOK_BNOT;}
"&"				{printf("Detecté '&' TOK_BAND généré\n");return TOK_BAND;}
"|"				{printf("Detecté '|' TOK_BOR généré\n");return TOK_BOR;}
"^"				{printf("Detecté '^' TOK_BXOR généré\n");return TOK_BXOR;}
"="				{printf("Detecté '=' TOK_AFFECT généré\n");return TOK_AFFECT;}
";"				{printf("Detecté ';' ROK_SEMICOL généré\n");return TOK_SEMICOL;}
","				{printf("Detecté ',' TOK_COMMA généré\n");return TOK_COMMA;}
"("				{printf("Detecté '(' TOK_LPAR généré\n");return TOK_LPAR;}
")"				{printf("Detecté ')' TOK_RPAR généré\n");return TOK_RPAR;}
"{"				{printf("Detecté '{' TOK_LACC généré\n");return TOK_LACC;}
"}"				{printf("Detecté '}' TOK_RACC généré\n");return TOK_RACC;}
">>"			{printf("Detecté '>>' TOK_SRL généré\n");return TOK_SRL;}
">>>"			{printf("Detecté '>>>' TOK_SRA généré\n");return TOK_SRA;}
"<<"			{printf("Detecté '<<' TOK_SLL généré\n");return TOK_SLL;}
">="			{printf("Detecté '>=' TOK_GE généré\n");return TOK_GE;}
"<="			{printf("Detecté '<=' TOK_LE généré\n");return TOK_LE;}
"=="			{printf("Detecté '==' TOK_EQ généré\n");return TOK_EQ;}
"!="			{printf("Detecté '!=' TOK_NE généré\n");return TOK_NE;}
"&&"			{printf("Detecté '&&' TOK_AND généré\n");return TOK_AND;}
"||"			{printf("Detecté '||' TOK_OR généré\n");return TOK_OR;}



{IDF} {
				yylval.strval = strdup(yytext);
                printf("Detecté idf '%s' TOK_IDENT généré\n",yytext);
                return TOK_IDENT;
}

{ENTIER} {      /* complété mais pas testé */
                yylval.intval = atoi(yytext);
                printf("Detecté entier %s TOK_INTVAL généré\n",yytext);
                return TOK_INTVAL;
}

{CHAINE} {
                yylval.strval = strdup(yytext);
                printf("Detecté chaine %c TOK_STRING généré",*yytext);

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


	printf("-----parse args-----\n");
    parse_args(argc, argv);
    #if YYDEBUG
    yydebug = 1;
    #endif

	node_t program_root;
    yyin = fopen(infile, "r");
	printf("main2\n");
	//while(yylex());
	//printf("lex fin\n");
	//printf("program root : %s\n" ,*program_root);
	yyparse(&program_root);
	printf("yacc fin\n");
	//creation de contexte pour le test
	context_t cont_test= create_context();
	free_context(cont_test);
	printf("yyparse FINI\n");
	printf("nops du noeud dans lex: %d\n", program_root->nops);
	printf("nature du noeud dans lex : %s\n",node_nature2string(program_root->nature));
	const char* txtname = "tree.dot";
	//dump_tree(program_root,txtname ); // afficher le tree


	printf("program root : %s\n" ,program_root);
	printf("main3\n");
    fclose(yyin);
	printf("main4\n");
    analyse_tree(program_root);
	printf("main5\n");
    yylex_destroy();
	//printf("main6\n");
    return 0;
}
