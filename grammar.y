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

#define couleur(param) printf("\033[%sm",param)
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
%token TOK_RACC     TOK_STRING  TOK_DO

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
%type <strval> TOK_IDENT TOK_STRING
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
            printf("program : liste non nulle et main\n");
            $$ = make_node(NODE_PROGRAM, 2, $1, $2);
			couleur("34"); printf("NODE_PROGRAM\n");couleur("0");
            *program_root = $$;

        }
        | maindecl // presence de variables locales seulement
        {
            printf("program : main\n");
            $$ = make_node(NODE_PROGRAM, 2, NULL, $1);
			couleur("34"); printf("NODE_PROGRAM\n");couleur("0");
            *program_root = $$;

        }
        ;
listdecl: listdeclnonnull
        {
            printf("listdecl : listdeclnonnull\n");
            $$ = $1//make_node(NODE_LIST, 1, $1 );
			couleur("34"); printf("NODE_LIST\n");couleur("0");
            //*program_root = $$;

        }
        |
        { printf("listdecl : epsilon");$$ = NULL; }

listdeclnonnull: vardecl
            {
                printf("listdecl non nulle : vardecl\n");
				$$ = make_node(NODE_LIST, 1, $1);
                couleur("34"); printf("NODE_LIST\n");couleur("0");
            	//*program_root = $$;
			}
            | listdeclnonnull vardecl
            {
                printf("listdecl non nulle : list + vardecl\n");
				make_node(NODE_LIST, 2, $1, $2);
                couleur("34"); printf("NODE_LIST\n");couleur("0");
            	//*program_root = $$;
			}
        ;
vardecl : type listtypedecl TOK_SEMICOL
            {
                printf("vardecl\n");
				$$ = make_node(NODE_DECLS, 2, $1, $2);
                couleur("34"); printf("NODE_LIST\n");couleur("0");
            	//*program_root = $$;
			}
        ;
type : TOK_INT
        {
            printf("type : TOK_INT\n");
			$$ = make_node(NODE_TYPE, 0, TYPE_INT);
        	couleur("34"); printf("NODE_TYPE\n");couleur("0");//*program_root = $$;
		}
        | TOK_BOOL
        {
            printf("type : TOK_BOOL\n");
			$$ = make_node(NODE_TYPE, 0, TYPE_BOOL);
			couleur("34"); printf("NODE_TYPE\n");couleur("0");//*program_root = $$;
		}
        | TOK_VOID
        {
            printf("type : TOK_VOID\n");
			$$ = make_node(NODE_TYPE, 0, TYPE_VOID);
			couleur("34"); printf("NODE_TYPE\n");couleur("0");//*program_root = $$;
		}
        ;
listtypedecl : decl
                {
                    printf("listtypedecl : decl\n");
					$$ = $1;//make_node(NODE_LIST, 1 ,$1);
					//printf("listtypedecl : decl bis\n");
                	couleur("34"); printf(" go decl\n");couleur("0");//*program_root = $$;
				}
                | listtypedecl TOK_COMMA decl
                {
                    printf("listtypedecl : listtypedecl, decl\n");
					$$ = make_node(NODE_LIST, 2 , $1, $3);
                	couleur("34"); printf("NODE_LIST\n");couleur("0");//*program_root = $$;
				}
                ;
decl : ident
       	{
            printf("decl : ident\n");
	   		$$ = make_node(NODE_DECL, 2, $1, NULL );
       		couleur("34"); printf("NODE_DECL\n");couleur("0");//*program_root = $$;
			printf("decl : ident bis\n");
		}
       	| ident TOK_AFFECT expr
       	{
			printf("decl : ident TOK_AFFECT expr\n");
			$$ = make_node(NODE_DECL, 2 ,$1, $3);
       		couleur("34"); printf("NODE_DECL\n");couleur("0");//*program_root = $$;
		}
       	;

maindecl: type ident TOK_LPAR TOK_RPAR block
            {
				$$ = make_node(NODE_FUNC, 3, $1, $2, $5);
            	couleur("34"); printf("NODE_FUNC\n");couleur("0");//*program_root = $$;
			}
        ;
listinst : listinstnonnull
            {
				$$ = $1;//make_node(NODE_LIST, 1, $1);
            	couleur("34"); printf("NODE_LIST\n");couleur("0");//*program_root = $$;
			}
            |
            {
				$$ = NULL;
			}
listinstnonnull : inst
                {
					$$ = $1;//$$ = make_node(NODE_LIST, 1, $1);
                	couleur("34"); printf("NODE_LIST\n");couleur("0");//*program_root = $$;
				}
                | listinstnonnull inst
                {
					$$ = make_node(NODE_LIST, 2, $1, $2);
                	couleur("34"); printf("NODE_LIST\n");couleur("0");//*program_root = $$;
				}
                ;
inst: expr TOK_SEMICOL
        {
			$$ = $1//make_node(NODE_BLOCK, 1, $1); // NODE_BLOCK ?
        	couleur("34"); printf("NODE_BLOCK\n");couleur("0");//*program_root = $$;
		}
        | TOK_IF TOK_LPAR expr TOK_RPAR inst TOK_ELSE inst
        {
			$$ = make_node(NODE_IF, 3, $3, $5, $7);
			couleur("34"); printf("NODE_IF\n");couleur("0");//*program_root = $$;
		}
        | TOK_IF TOK_LPAR expr TOK_RPAR inst %prec TOK_THEN
        {
			$$ = make_node(NODE_IF, 2, $3, $5);
        	couleur("34"); printf("NODE_IF\n");couleur("0");//*program_root = $$;
		}
        | TOK_WHILE TOK_LPAR expr TOK_RPAR inst
        {
			$$ = make_node(NODE_WHILE, 2, $3, $5);
        	couleur("34"); printf("NODE_WHILE\n");couleur("0");//*program_root = $$;
		}
        | TOK_FOR TOK_LPAR expr TOK_SEMICOL expr TOK_SEMICOL expr TOK_RPAR inst
        {
			$$ = make_node(NODE_FOR, 4, $3 ,$5, $7, $9);
        	couleur("34"); printf("NODE_FOR\n");couleur("0");//*program_root = $$;
		}
        | TOK_DO inst TOK_WHILE TOK_LPAR expr TOK_RPAR TOK_SEMICOL
        {
			$$ = make_node(NODE_DOWHILE, 2, $2, $5);
        	couleur("34"); printf("NODE_DOWHILE\n");couleur("0");//*program_root = $$;
		}
        | block
        {
			$$ = $1;
        	//*program_root = $$;
		}
        | TOK_SEMICOL
        {
			$$ = NULL;
		}
        | TOK_PRINT TOK_LPAR listparamprint TOK_RPAR TOK_SEMICOL
        {
			$$ = make_node(NODE_PRINT, 1, $3);
        	couleur("34"); printf("NODE_PRINT\n");couleur("0");//*program_root = $$;
		}
        ;
block: TOK_LACC listdecl listinst TOK_RACC
        {
			$$ = make_node(NODE_BLOCK, 2, $2, $3);
        	couleur("34"); printf("NODE_BLOCK\n");couleur("0");//*program_root = $$;
		}
        ;
expr : expr TOK_MUL expr
        {
			$$ = make_node(NODE_MUL, 2, $1, $3);
        	couleur("34"); printf("NODE_MUL\n");couleur("0");//*program_root = $$;
		}
        | expr TOK_DIV expr
        {
			$$ = make_node(NODE_DIV, 2, $1, $3);
        	couleur("34"); printf("NODE_DIV\n");couleur("0");//*program_root = $$;
		}
        | expr TOK_PLUS expr
        {
			$$ = make_node(NODE_PLUS, 2, $1, $3);
        	couleur("34"); printf("NODE_PLUS\n");couleur("0");//*program_root = $$;
		}
        | expr TOK_MINUS expr
        {
			$$ = make_node(NODE_MINUS, 2, $1, $3);
        	couleur("34"); printf("NODE_MINUS\n");couleur("0");//*program_root = $$;
		}
        | expr TOK_MOD expr
        {
			$$ = make_node(NODE_MOD, 2, $1, $3);
        	couleur("34"); printf("NODE_MOD\n");couleur("0");//*program_root = $$;
		}
        | expr TOK_LT expr
        {
			$$ = make_node(NODE_LT, 2, $1, $3);
        	couleur("34"); printf("NODE_LT\n");couleur("0");//*program_root = $$;
		}
        | expr TOK_GT expr
        {
			$$ = make_node(NODE_GT, 2, $1, $3);
        	couleur("34"); printf("NODE_GT\n");couleur("0");//*program_root = $$;
		}
        | TOK_MINUS expr %prec TOK_UMINUS
        {
			$$ = make_node(NODE_UMINUS, 1, $2);
        	couleur("34"); printf("NODE_UMINUS\n");couleur("0");//*program_root = $$;
		}
        | expr TOK_GE expr
        {
			$$ = make_node(NODE_GE, 2, $1, $3);
        	couleur("34"); printf("NODE_GE\n");couleur("0");//*program_root = $$;
		}
		| expr TOK_LE expr
		{
			$$ = make_node(NODE_LE, 2, $1, $3);
		}
		| expr TOK_EQ expr
		{
			$$ = make_node(NODE_EQ, 2, $1, $3);
		}
		| expr TOK_NE expr
		{
			$$ = make_node(NODE_NE, 2, $1, $3);
		}
		| expr TOK_AND expr
		{
			$$ = make_node(NODE_AND, 2, $1, $3);
		}
		| expr TOK_OR expr
		{
			$$ = make_node(NODE_OR, 2, $1, $3);
		}
		| expr TOK_BAND expr
		{
			$$ = make_node(NODE_BAND, 2, $1, $3);
		}
		| expr TOK_BOR expr
		{
			$$ = make_node(NODE_BOR, 2, $1, $3);
		}
		| expr TOK_BXOR expr
		{
			$$ = make_node(NODE_BXOR, 2, $1, $3);
		}
		| expr TOK_SRL expr
		{
			$$ = make_node(NODE_SRL, 2, $1, $3);
		}
		| expr TOK_SRA expr
		{
			$$ = make_node(NODE_SRA, 2, $1, $3);
		}
		| expr TOK_SLL expr /*pas trouve*/
		{
			$$ = make_node(NODE_SLL, 2, $1, $3);
		}
		| TOK_NOT expr
		{
			$$ = make_node(NODE_NOT, 1, $2);
		}
		| TOK_BNOT expr
		{
			$$ = make_node(NODE_BNOT, 1, $2);
		}
		| TOK_LPAR expr TOK_RPAR /*pas trouve*/
		{
			printf("expr : TOK_LPAR expr TOK_RPAR\n");
			//$$ = make_node(NODE_, 2, $1, $3)
		}
		| ident TOK_AFFECT expr
		{
			printf("expr : ident TOK_AFFECT expr\n");
			$$ = make_node(NODE_AFFECT, 2, $1, $3);
		}
		| TOK_INTVAL
		{
			printf("expr : TOK_INTVAL\n");
			$$ = make_node(NODE_AFFECT, 0);
		}
		| TOK_TRUE /*pas trouve*/
		{
			printf("expr : TOK_TRUE\n");
			$$ = NULL;
		}
		| TOK_FALSE /*pas trouve*/
		{
			printf("expr : TOK_FALSE\n");
			$$ = NULL;
		}
		| ident
		{
			printf("expr : ident\n");
			$$ = $1;
		}
        ;

listparamprint : listparamprint TOK_COMMA paramprint
				{
					$$ = make_node(NODE_LIST, 2, $1, $3); // a verifier
					couleur("34"); printf("NODE_PRINT\n");couleur("0");//*program_root = $$;
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
			| TOK_STRING
			{
				$$ = make_node(NODE_PRINT, 1, $1);
				couleur("34"); printf("NODE_PRINT\n");couleur("0");//*program_root = $$;
			}
			;

ident : TOK_IDENT
		{
			printf("ident : TOK_IDENT\n");
			$$ = make_node(NODE_IDENT, 0);
			couleur("34"); printf("NODE_IDENT\n");couleur("0");//*program_root = $$;
		}
		;


%%
/* A completer et/ou remplacer avec d'autres fonctions */

node_t make_node(node_nature nature, int nops, ...) {
	couleur("30"); printf("NODE CREE\n");

    //cptnodes ++;
    //printf("on make le node n°%d\n", cptnodes);
    va_list ap; /*liste des arguments supplémentaires*/
				//printf("make_node 1\n");
    va_start(ap,nops);
				//printf("make_node 2\n");
    node_t retour = malloc (sizeof(node_t));
				//printf("make_node 3\n");
    //retour->node_num = cptnodes;
	retour->nature = nature;
				//printf("make_node 4\n");
    retour->nops = nops;
				//printf("make_node 5\n");
    node_s **hop;
	retour->opr= (node_s**)malloc(sizeof(node_s*)*nops);
	/*for(int i = 0; i < nops; i++)
	{
		hop[i] = (node_s*)malloc(sizeof(node_s));
	}*/
				//printf("make_node 6\n");
				//printf("nops=%d\n",nops);

    for (int i = 0; i < nops; i++)
    {
				//printf("make_node for 1\n");
        if(va_arg(ap, node_t) == NULL)
        {
				//printf("make_node for if\n");
            continue;
        }
				//printf("make_node for 2\n");
			//printf("arg supp n°%d = %d\n ", i+1 , va_arg(ap, node_t));
				//printf("make_node for 3\n");
        retour->opr[i] = va_arg(ap,node_t);
				//printf("make_node for 4\n");
			printf("hop affecté! contient %d\n" , retour->opr[i]);
    }
				//printf("make_node 7\n");
    //retour->opr = hop;
				//printf("make_node 8\n");
    // recherche des arguments supplementaires en fonction de la nature du noeud
    switch(nature)
    {
        case NODE_IDENT ://   type =  TYPE_NONE,TYPE_INT,TYPE_BOOL,TYPE_STRING,TYPE_VOID

				//printf("make_node node_ident 1\n");
            retour->type      =va_arg(ap,node_type); // argument supp à la position nops + 1 = type de noeud
				//printf("make_node node_ident 2\n");
            retour->decl_node =va_arg(ap,node_t); // argument supp à la position nops + 2 = declaration de noeud
				//printf("make_node node_ident 3\n");
            retour->offset    =va_arg(ap,int32_t ); // argument supp à la position nops + 3 = declaration de l'emplacement mémoire de la variable int32_t
				//printf("make_node node_ident 4\n");
            retour->global_decl=va_arg(ap,int); // argument supp à la position nops + 4 = declaration globale?
				//printf("make_node node_ident 5\n");
            break;
        case NODE_AFFECT :
            retour->type      =va_arg(ap,node_type); // argument supp à la position nops + 1 = type de noeud
            break;
        case NODE_FUNC :
            retour->offset    =va_arg(ap,int32_t); // argument supp à la position nops + 1 = declaration de l'emplacement mémoire de la variable int32_t
            retour->stack_size=va_arg(ap,int32_t); // argument supp à la position nops + 2 = declaration de
            break;
        case NODE_TYPE:
				//printf("make_node node_type 1\n");
            retour->type = va_arg(ap,node_type);
				//printf("make_node node_type 2\n");
        case NODE_INTVAL:
            retour->value = va_arg(ap,int64_t);
		case NODE_BOOLVAL:
			retour->value = va_arg(ap,int64_t);
        case NODE_STRINGVAL :
            retour->str = va_arg(ap,char*);
			retour->offset = va_arg(ap,int32_t);
		default:
            break;
    }
/*
	for(int i = 0; i < nops; i++)
	{
		printf("free%d\n",i+1);
		free(hop[i]);
		printf("free%d\n",i+1);
	}*/
    //free(hop);

				//printf("make_node 20\n");
    va_end(ap);
				//printf("make_node 21\n");
    couleur("0");
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
