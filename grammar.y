%{
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>
#include "defs.h"
#include "common.h"
#include "mips_inst.h"
#define couleur(param) printf("\033[%sm",param)


/* Global variables */
/* A completer */
extern bool stop_after_syntax;
extern bool stop_after_verif;
extern char * infile;
extern char * outfile;
extern int nbtraces;
extern int nbregistres;
extern int sflag;
extern int vflag;
extern int cptnodes;
extern int mainflag;
node_type typetemp;
int cptenfants = 1;//nombre de vardecl quand il y a plusieurs declaration en liste
int cptvar = 0;//compteur de declaration de variables ligne apres ligne

/* prototypes */
int yylex(void);
extern int yylineno;

void yyerror(node_t * program_root, char * s);
void analyse_tree(node_t root);
node_t make_node(node_nature nature, int nops, ...);
/* A completer */

%}

/* DEFINITIONS */
%parse-param { node_t * program_root }

%union {
    int32_t intval;
    char * strval;
    node_t ptr;
};

/*se réfèrent au point IV/1) du sujet page 14 :*/

/* Definir les token ici avec leur associativite, dans le bon ordre */
%token TOK_VOID     TOK_INT     TOK_INTVAL  TOK_BOOL    TOK_TRUE    TOK_FALSE
%token TOK_IDENT    TOK_IF      TOK_ELSE    TOK_WHILE   TOK_FOR     TOK_PRINT
%token TOK_AFFECT   TOK_GE      TOK_LE      TOK_GT      TOK_LT      TOK_EQ
%token TOK_NE       TOK_PLUS    TOK_MINUS   TOK_MUL     TOK_DIV     TOK_MOD
%token TOK_UMINUS   TOK_SEMICOL TOK_COMMA   TOK_LPAR    TOK_RPAR    TOK_LACC
%token TOK_RACC     TOK_STRING  TOK_DO      TOK_STRINGVAL

/*non associativité*/
%nonassoc TOK_THEN
%nonassoc TOK_ELSE /* d'après la description de la non associativité il semblerait qu'il y aie une erreur dans le sujet*/

/* a = b = c + d <=> b = c + d ; a = b; */
%right TOK_AFFECT /*l'affectation sera faite en dernier*/

%left TOK_OR
%left TOK_AND
%left TOK_BOR
%left TOK_BXOR
%left TOK_BAND
%left TOK_EQ TOK_NE
%left TOK_GT TOK_LT TOK_GE TOK_LE
%left TOK_SRL TOK_SRA TOK_SLL

/* a / b / c = (a / b) / c et a - b - c = (a - b) - c */

%left TOK_PLUS TOK_MINUS
%left TOK_MUL TOK_DIV TOK_MOD
%left TOK_UMINUS TOK_NOT TOK_BNOT



%type <intval> TOK_INTVAL
%type <strval> TOK_IDENT TOK_STRING TOK_STRINGVAL
%type <ptr> vardecl ident type listtypedecl decl
%type <ptr> maindecl listinst listinstnonnull inst
%type <ptr> block expr listparamprint paramprint
%type <ptr> program listdecl listdeclnonnull

%start program
%%

/* REGLES */
program:
        listdeclnonnull maindecl /* presence de variables globales*/
        {
            //printf("<REGLE> program : liste non nulle et main\n");
            $$ = make_node(NODE_PROGRAM, 2, $1, $2);
			*program_root = $$;

        }
        | maindecl /* presence de variables locales seulement*/
        {
            //printf("<REGLE> program : main\n");
            $$ = make_node(NODE_PROGRAM, 2, NULL, $1);
			*program_root = $$;

        }
        ;
listdecl: listdeclnonnull
        {
            //printf("<REGLE> listdecl : listdeclnonnull\n");
            $$ = $1;
		}
        |
        {
			//printf("<REGLE> listdecl : epsilon");
			$$ = NULL;
		}

listdeclnonnull: vardecl
            {
                cptvar ++;
                //printf ("nombre d'enfants de la liste : %d\n", cptvar);
                //printf("<REGLE> listdecl non nulle : vardecl $$ = %s\n", node_nature2string($$->nature));
				$$ = make_node(NODE_LIST, cptvar, $1);
			}
            | listdeclnonnull vardecl
            {
                //printf("<REGLE> listdeclnonnulle : listdeclnonnull vardecl\n");
                //printf("$1 = %s\n$2 = %s\n", node_nature2string($1->nature), node_nature2string($2->nature));
                cptenfants++;
                //printf("nombre d'enfant de la liste : %d\n", cptenfants);
                $$ = make_node(NODE_LIST, cptenfants, $1, $2);
			}
        ;
vardecl : type listtypedecl TOK_SEMICOL
            {
                //printf("<REGLE> vardecl : type listtypedecl;\n");
                //printf("$1 = %s\n$2 = %s\n", node_nature2string($1->nature), node_nature2string($2->nature));
				$$ = make_node(NODE_DECLS, 2, $1, $2);
			}
        ;
type : TOK_INT
        {
            //printf("<REGLE> type : TOK_INT\n");
			$$ = make_node(NODE_TYPE, 0, TYPE_INT);
            typetemp = TYPE_INT;
		}
        | TOK_BOOL
        {
            //printf("<REGLE> type : TOK_BOOL\n");
			$$ = make_node(NODE_TYPE, 0, TYPE_BOOL);
            typetemp = TYPE_BOOL;
		}
        | TOK_VOID
        {
            //printf("<REGLE> type : TOK_VOID\n");
			$$ = make_node(NODE_TYPE, 0, TYPE_VOID);
            typetemp = TYPE_VOID;
		}
        ;
listtypedecl : decl
                {
                    //printf("<REGLE> listtypedecl : decl\n");
					$$ = $1;
				}
                | listtypedecl TOK_COMMA decl
                {
                    //printf("<REGLE> listtypedecl : listtypedecl, decl\n");
                    //printf("$1 = %s\n$3 = %s\n", node_nature2string($1->nature), node_nature2string($3->nature));
					$$ = make_node(NODE_LIST, 2 , $1, $3);
				}
                ;
decl : ident
       	{
            //printf("<REGLE> decl : ident\n");
            //printf("$1 = %s\n", node_nature2string($1->nature));
	   		$$ = make_node(NODE_DECL, 2, $1, NULL );
		}
       	| ident TOK_AFFECT expr
       	{
			//printf("<REGLE> decl : ident = expr\n");
            //printf("$1 = %s\n$3 = %s\n", node_nature2string($1->nature), node_nature2string($3->nature));
			$$ = make_node(NODE_DECL, 2 ,$1, $3);
		}
       	;

maindecl: type ident TOK_LPAR TOK_RPAR block
            {
    			//printf("<REGLE> maindecl: type ident ( ) block\n");
                //printf("$1 = %s\n$2 = %s\n$5 = %s\n", node_nature2string($1->nature), node_nature2string($2->nature), node_nature2string($5->nature));
                cptenfants = 1;
                cptvar = 0;
                $$ = make_node(NODE_FUNC, 3, $1, $2, $5, 8, 8);
			}
        ;
listinst : listinstnonnull
            {
				$$ = $1;
			}
            |
            {
				$$ = NULL;
			}
listinstnonnull : inst
                {
					$$ = $1;
				}
                | listinstnonnull inst
                {
					$$ = make_node(NODE_LIST, 2, $1, $2);
				}
                ;
inst: expr TOK_SEMICOL
        {
			$$ = $1;
		}
        | TOK_IF TOK_LPAR expr TOK_RPAR inst TOK_ELSE inst
        {
			$$ = make_node(NODE_IF, 3, $3, $5, $7);
		}
        | TOK_IF TOK_LPAR expr TOK_RPAR inst %prec TOK_THEN
        {
			$$ = make_node(NODE_IF, 2, $3, $5);
		}
        | TOK_WHILE TOK_LPAR expr TOK_RPAR inst
        {
			$$ = make_node(NODE_WHILE, 2, $3, $5);
		}
        | TOK_FOR TOK_LPAR expr TOK_SEMICOL expr TOK_SEMICOL expr TOK_RPAR inst
        {
			$$ = make_node(NODE_FOR, 4, $3 ,$5, $7, $9);
		}
        | TOK_DO inst TOK_WHILE TOK_LPAR expr TOK_RPAR TOK_SEMICOL
        {
			$$ = make_node(NODE_DOWHILE, 2, $2, $5);
		}
        | block
        {
			$$ = $1;
		}
        | TOK_SEMICOL
        {
			$$ = NULL;
		}
        | TOK_PRINT TOK_LPAR listparamprint TOK_RPAR TOK_SEMICOL
        {
			$$ = make_node(NODE_PRINT, 1, $3);
		}
        ;
block: TOK_LACC listdecl listinst TOK_RACC
        {
			$$ = make_node(NODE_BLOCK, 2, $2, $3);
		}
        ;
expr : expr TOK_MUL expr
        {
			$$ = make_node(NODE_MUL, 2, $1, $3);
		}
        | expr TOK_DIV expr
        {
			$$ = make_node(NODE_DIV, 2, $1, $3);
		}
        | expr TOK_PLUS expr
        {
			$$ = make_node(NODE_PLUS, 2, $1, $3);
		}
        | expr TOK_MINUS expr
        {
			$$ = make_node(NODE_MINUS, 2, $1, $3);
		}
        | expr TOK_MOD expr
        {
			$$ = make_node(NODE_MOD, 2, $1, $3);
		}
        | expr TOK_LT expr
        {
			$$ = make_node(NODE_LT, 2, $1, $3);
		}
        | expr TOK_GT expr
        {
			$$ = make_node(NODE_GT, 2, $1, $3);
		}
        | TOK_MINUS expr %prec TOK_UMINUS
        {
			$$ = make_node(NODE_UMINUS, 1, $2);
		}
        | expr TOK_GE expr
        {
			$$ = make_node(NODE_GE, 2, $1, $3);
		}
		| expr TOK_LE expr
		{
            //printf("$1 = %s\n$3 = %s\n", node_nature2string($1->nature), node_nature2string($3->nature));
			$$ = make_node(NODE_LE, 2, $1, $3);
		}
		| expr TOK_EQ expr
		{
            //printf("$1 = %s\n$3 = %s\n", node_nature2string($1->nature), node_nature2string($3->nature));
			$$ = make_node(NODE_EQ, 2, $1, $3);
		}
		| expr TOK_NE expr
		{
            //printf("$1 = %s\n$3 = %s\n", node_nature2string($1->nature), node_nature2string($3->nature));
			$$ = make_node(NODE_NE, 2, $1, $3);
		}
		| expr TOK_AND expr
		{
            //printf("$1 = %s\n$3 = %s\n", node_nature2string($1->nature), node_nature2string($3->nature));
			$$ = make_node(NODE_AND, 2, $1, $3);
		}
		| expr TOK_OR expr
		{
            //printf("$1 = %s\n$3 = %s\n", node_nature2string($1->nature), node_nature2string($3->nature));
			$$ = make_node(NODE_OR, 2, $1, $3);
		}
		| expr TOK_BAND expr
		{
            //printf("$1 = %s\n$3 = %s\n", node_nature2string($1->nature), node_nature2string($3->nature));
			$$ = make_node(NODE_BAND, 2, $1, $3);
		}
		| expr TOK_BOR expr
		{
            //printf("$1 = %s\n$3 = %s\n", node_nature2string($1->nature), node_nature2string($3->nature));
			$$ = make_node(NODE_BOR, 2, $1, $3);
		}
		| expr TOK_BXOR expr
		{
            //printf("$1 = %s\n$3 = %s\n", node_nature2string($1->nature), node_nature2string($3->nature));
			$$ = make_node(NODE_BXOR, 2, $1, $3);
		}
		| expr TOK_SRL expr
		{
            //printf("$1 = %s\n$3 = %s\n", node_nature2string($1->nature), node_nature2string($3->nature));
			$$ = make_node(NODE_SRL, 2, $1, $3);
		}
		| expr TOK_SRA expr
		{
            //printf("$1 = %s\n$3 = %s\n", node_nature2string($1->nature), node_nature2string($3->nature));
			$$ = make_node(NODE_SRA, 2, $1, $3);
		}
		| expr TOK_SLL expr /*pas trouve*/
		{
            //printf("$1 = %s\n$3 = %s\n", node_nature2string($1->nature), node_nature2string($3->nature));
			$$ = make_node(NODE_SLL, 2, $1, $3);
		}
		| TOK_NOT expr
		{
            //printf("$2 = %s\n", node_nature2string($2->nature));
			$$ = make_node(NODE_NOT, 1, $2);
		}
		| TOK_BNOT expr
		{
            //printf("$2 = %s\n",node_nature2string($2->nature));
			$$ = make_node(NODE_BNOT, 1, $2);
		}
		| TOK_LPAR expr TOK_RPAR /*pas trouve*/
		{
			//printf("<REGLE> expr : TOK_LPAR expr TOK_RPAR\n");
            //printf("$2 = %s\n",node_nature2string($2->nature));
			//$$ = make_node(NODE_, 2, $1, $3)
		}
		| ident TOK_AFFECT expr
		{
			//printf("<REGLE> expr : ident TOK_AFFECT expr $$ = %s\n", node_nature2string($$->nature));
            //printf("$1 = %s\n$3 = %s\n", node_nature2string($1->nature), node_nature2string($3->nature));
			$$ = make_node(NODE_AFFECT, 2, $1, $3); // arg supp : type de noeud
		}
		| TOK_INTVAL
		{
			//printf("<REGLE> expr : TOK_INTVAL $$ = %s\n", node_nature2string($$->type));
			$$ = make_node(NODE_INTVAL, 0, yylval.intval );
		}
		| ident
		{
			//printf("<REGLE> expr : ident\n");
			$$ = $1;
		}
        | TOK_TRUE
        {
			//printf("<REGLE> expr: BOOLVAL TRUE $$ = %s\n", node_nature2string($$->nature));
            $$ = make_node(NODE_BOOLVAL, 0,1);
        }
        | TOK_FALSE
        {
			//printf("<REGLE> expr:BOOLVAL false $$ = %s\n", node_nature2string($$->nature));
            $$ = make_node(NODE_BOOLVAL, 0,0 );
        }
        | TOK_STRINGVAL
        {
            $$ = make_node(NODE_STRINGVAL, 0, yylval.strval, sizeof(yylval.strval) );
        }
        ;

listparamprint : listparamprint TOK_COMMA paramprint
				{
					$$ = make_node(NODE_LIST, 2, $1, $3); // a verifier
				}
				| paramprint
				{
					$$ = $1;
				}
				;

paramprint : ident /*probleme*/
			{
				$$ = $1;
			}
			| TOK_STRINGVAL
			{ // make node (node print, )
				$$ = make_node(NODE_STRINGVAL, 0, yylval.strval, sizeof(yylval.strval) );
			}
			;

ident : TOK_IDENT
		{
			//printf("ident : TOK_IDENT\n");
            // argument supp à la position nops:
            //+ 1 = type de noeud
            //+ 2 = declaration de noeud
            //+ 3 = declaration de l'emplacement mémoire de la variable, int32_t
            //+ 4 = declaration globale? bool = int => recuperer ?
            //+ 5 =  identifiant
            node_t nident;
            if (mainflag != 1)
            {
                //printf("global idf %s\n", yylval.strval);
                $$ = make_node(NODE_IDENT, 0, typetemp,nident , -1, 1, yylval.strval);
            } //   type =  TYPE_NONE,TYPE_INT,TYPE_BOOL,TYPE_STRING,TYPE_VOID
            else
            {
                if (strcmp (yylval.strval, "main") == 0)
                {
                    //printf("main idf %s\n", yylval.strval);
                    $$ = make_node(NODE_IDENT, 0, typetemp,nident ,-1, 1, yylval.strval);
                }
                else
                {
                    //printf("local idf %s\n", yylval.strval);
                    $$ = make_node(NODE_IDENT, 0, typetemp,nident , -1, 0, yylval.strval);
                }
            }
		}
		;


%%
/* A completer et/ou remplacer avec d'autres fonctions */

node_t make_node(node_nature nature, int32_t nops, ...) {
	va_list ap; /*liste des arguments supplémentaires*/
    va_start(ap,nops);
    node_t retour;
    /*if(nature == NODE_LIST && nops == 0) // mise à jour d'une liste
    {
        retour = va_arg(ap, node_t);
        printf("nops actuel: %d\n", retour->nops);
        retour->nops++;// augmentation du nombre d'enfants
        printf("nops modifié: %d\n", retour->nops);
        retour->opr[nops-1] = va_arg(ap, node_t);
        printf("Ajout de %s dans %s\n", node_nature2string((retour->opr[nops-1])->nature),
                                        node_nature2string(retour->nature));
        return retour;
    }*/
    retour = (node_s *) malloc(sizeof(node_s));
	retour->nature = nature;
	retour->nops = nops;
    for (int i = 0; i < nops; i++)
    {
            retour->opr[i] = va_arg(ap,node_t);
    }
    switch(nature)
    {
        case NODE_IDENT ://   type =  TYPE_NONE,TYPE_INT,TYPE_BOOL,TYPE_STRING,TYPE_VOID
            retour->type      =va_arg(ap,node_type); // argument supp à la position nops + 1 = type de noeud
            retour->decl_node =va_arg(ap,node_t); // argument supp à la position nops + 2 = declaration de noeud
            retour->offset    =va_arg(ap,int32_t ); // argument supp à la position nops + 3 = declaration de l'emplacement mémoire de la variable int32_t + 4 = declaration globale?
            retour->global_decl=(bool)va_arg(ap,int); // argument supp à la position nops + 4 = declaration globale?
            retour->ident   = va_arg(ap, char*); // argument supp à la position nops + 5 =  identifiant
            break;
        case NODE_AFFECT :
            retour->type      =va_arg(ap,node_type); // argument supp à la position nops + 1 = type de noeud
            break;
        case NODE_FUNC :
            retour->offset    =8; // argument supp à la position nops + 1 = declaration de l'emplacement mémoire de la variable
            retour->stack_size=8; // argument supp à la position nops + 2 = declaration de
            //printf("offset: %d\nstack_size: %d\n",retour->offset,retour->stack_size);
            break;
        case NODE_TYPE:
			retour->type = va_arg(ap,node_type);
			//printf("make_node node_type réussi %s\n", node_type2string(retour->type));
            break;
        case NODE_INTVAL:
                //printf("make_node intval affectation: %ld\n", va_arg(ap,int64_t));
            retour->type = TYPE_INT;
            retour->value = va_arg(ap,int64_t);
            break;
		case NODE_BOOLVAL:
            retour->type = TYPE_BOOL;
			if (va_arg(ap,int)== 1)
                {
                    retour->value = 1;
				}
            else if(va_arg(ap,int)==0)
                {
                    retour->value = 0;
				}
            break;
        case NODE_STRINGVAL :
            retour->type = TYPE_STRING;
            retour->str = va_arg(ap,char*);
			retour->offset = va_arg(ap,int32_t);
                //printf("stringval affecté: %s\noffset: %d\n",retour->str, retour->offset);
            break;
        case NODE_PLUS:
        case NODE_MINUS:
        case NODE_MUL:
        case NODE_DIV:
        case NODE_MOD:
        case NODE_LT:
        case NODE_GT:
        case NODE_LE:
        case NODE_GE:
        case NODE_EQ:
        case NODE_NE:
        case NODE_AND:
        case NODE_OR:
        case NODE_BAND:
        case NODE_BOR:
        case NODE_BXOR:
        case NODE_SRA:
        case NODE_SRL:
        case NODE_SLL:
        case NODE_NOT:
        case NODE_BNOT:
        case NODE_UMINUS:
            retour->type = TYPE_NONE;
            break;
        default:
            //printf("nature default\n");
            break;
    }

    va_end(ap);

	if(nbtraces >= 2)
	{
		couleur("34");
		printf("NODE %s\n", node_nature2string(retour->nature));
		couleur("0");
	}
    return retour;
}



/* A completer */
void analyse_tree(node_t root) {

        if (!stop_after_syntax) {
        // Appeler la passe 1

        if (!stop_after_verif) {
            create_program();
            // Appeler la passe 2

            //dump_mips_program(outfile);
            free_program();
        }
        free_global_strings();
    }
}



void yyerror(node_t * program_root, char * s) {
    fprintf(stderr, "Error line %d: %s\n", yylineno, s);
    exit(1);
}
