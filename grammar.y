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


/* prototypes */
int yylex(void);
extern int yylineno;

void yyerror(node_t * program_root, char * s);
void analyse_tree(node_t root);
node_t make_node(node_nature nature, int nops, ...);
/* A completer */

%}

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

/* Regles ici */
program:
        listdeclnonnull maindecl /* presence de variables globales*/
        {
            printf("liste non nulle et main\n");
            $$ = make_node(NODE_PROGRAM, 2, $1, $2); // Erreur : $$ is untyped
			printf("program 1\n");
            *program_root = $$;
			printf("program 2\n");
        }
        | maindecl // presence de variables locales seulement
        {
            printf("main\n");
            $$ = make_node(NODE_PROGRAM, 2, NULL, $1);
			printf("program 3\n");
            *program_root = $$;
			printf("program 4\n");
        }
        ;
listdecl: listdeclnonnull
        {
            printf("listdecl\n");
            // combien d'enfants pour un node list?
            $$ = make_node(NODE_LIST, 1, $1 );
			printf("listdecl 1\n");
            *program_root = $$;
			printf("listdecl 2\n");
        }
        |
        { $$ = NULL; }

listdeclnonnull: vardecl
            {
                printf("listdecl non nulle\n");
				$$ = make_node(NODE_LIST, 1, $1);
            	*program_root = $$;
			}
            | listdeclnonnull vardecl
            {
				$$ = make_node(NODE_LIST, 2, $1, $2);
            	*program_root = $$;
			}
        ;
vardecl : type listtypedecl TOK_SEMICOL
            {
                printf("vardecl\n");
				$$ = make_node(NODE_LIST, 1, $1);
            	*program_root = $$;
			}
        ;
type : TOK_INT
        {
            printf("int\n");
			$$ = make_node(NODE_TYPE, 0, TYPE_INT);
        	*program_root = $$;
		}
        | TOK_BOOL
        {
            printf("bool\n");
			$$ = make_node(NODE_TYPE, 0, TYPE_BOOL);
			*program_root = $$;
		}
        | TOK_VOID
        {
            printf("void\n");
			$$ = make_node(NODE_TYPE, 0, TYPE_VOID);
			*program_root = $$;
		}
        ;
listtypedecl : decl
                {
                    printf("listtypedecl : decl\n");
					$$ = make_node(NODE_LIST, 1 ,$1);
                	*program_root = $$;
				}
                | listtypedecl TOK_COMMA decl
                {
                    printf("listtypedecl : listtypedecl, decl\n");
					$$ = make_node(NODE_LIST, 2 , $1, $3);
                	*program_root = $$;
				}
                ;
decl : ident
       	{
            printf("decl : ident\n");
	   		$$ = make_node(NODE_DECL, 2, $1, NULL );
       		*program_root = $$;
		}
       	| ident TOK_AFFECT expr
       	{
			$$ = make_node(NODE_DECL, 2 ,$1, $3);
       		*program_root = $$;
		}
       	;

maindecl: type ident TOK_LPAR TOK_RPAR block
            {
				$$ = make_node(NODE_FUNC, 3, $1, $2, $5);
            	*program_root = $$;
			}
        ;
listinst : listinstnonnull
            {
				$$ = make_node(NODE_LIST, 1, $1);
            	*program_root = $$;
			}
            |
            {
				$$ = NULL;
			}
listinstnonnull : inst
                {
					$$ = make_node(NODE_LIST, 1, $1);
                	*program_root = $$;
				}
                | listinstnonnull inst
                {
					$$ = make_node(NODE_LIST, 2, $1, $2);
                	*program_root = $$;
				}
                ;
inst: expr TOK_SEMICOL
        {
			$$ = make_node(NODE_BLOCK, 1, $1); // NODE_BLOCK ?
        	*program_root = $$;
		}
        | TOK_IF TOK_LPAR expr TOK_RPAR inst TOK_ELSE inst
        {
			$$ = make_node(NODE_IF, 3, $3, $5, $7);
			*program_root = $$;
		}
        | TOK_IF TOK_LPAR expr TOK_RPAR inst %prec TOK_THEN
        {
			$$ = make_node(NODE_IF, 2, $3, $5);
        	*program_root = $$;
		}
        | TOK_WHILE TOK_LPAR expr TOK_RPAR inst
        {
			$$ = make_node(NODE_WHILE, 2, $3, $5);
        	*program_root = $$;
		}
        | TOK_FOR TOK_LPAR expr TOK_SEMICOL expr TOK_SEMICOL expr TOK_RPAR inst
        {
			$$ = make_node(NODE_FOR, 4, $3 ,$5, $7, $9);
        	*program_root = $$;
		}
        | TOK_DO inst TOK_WHILE TOK_PAR expr TOK_RPAR TOK_SEMICOL
        {
			$$ = make_node(NODE_DOWHILE, 2, $2, $5);
        	*program_root = $$;
		}
        | block
        {
			$$ = make_node(NODE_BLOCK, 1, $1);
        	*program_root = $$;
		}
        | TOK_SEMICOL
        {
			$$ = NULL;
		}
        | TOK_PRINT TOK_LPAR listparamprint TOK_RPAR TOK_SEMICOL
        {
			$$ = make_node(NODE_PRINT, 1, $3);
        	*program_root = $$;
		}
        ;
block: TOK_LACC listdecl listinst TOK_RACC
        {
			$$ = make_node(NODE_BLOCK, 2, $2, $3);
        	*program_root = $$;
		}
        ;
expr : expr TOK_MUL expr
        {
			$$ = make_node(NODE_MUL, 2,$1, $3);
        	*program_root = $$;
		}
        |expr TOK_DIV expr
        {
			$$ = make_node(NODE_DIV, 2, $1, $3);
        	*program_root = $$;
		}
        | expr TOK_PLUS expr
        {
			$$ = make_node(NODE_PLUS, 2, $1, $3);
        	*program_root = $$;
		}
        | expr TOK_MINUS expr
        {
			$$ = make_node(NODE_MINUS, 2, $1, $3);
        	*program_root = $$;
		}
        | expr TOK_MOD expr
        {
			$$ = make_node(NODE_MOD, 2, $1, $3);
        	*program_root = $$;
		}
        | expr TOK_LT expr
        {
			$$ = make_node(NODE_LT, 2, $1, $3);
        	*program_root = $$;
		}
        | expr TOK_GT expr
        {
			$$ = make_node(NODE_GT, 2, $1, $3);
        	*program_root = $$;
		}
        | TOK_MINUS expr %prec TOK_UMINUS
        {
			$$ = make_node(NODE_UMINUS, 1, $2);
        	*program_root = $$;
		}
        | expr TOK_GE expr
        {
			$$ = make_node(NODE_GE, 2, $1, $3);
        	*program_root = $$;
		}
        ;
%%
/* A completer et/ou remplacer avec d'autres fonctions */

node_t make_node(node_nature nature, int nops, ...) {
    printf("NODE CREE\n");

    //cptnodes ++;
    //printf("on make le node n°%d\n", cptnodes);
    va_list ap; /*liste des arguments supplémentaires*/
	printf("make_node 1\n");
    va_start(ap,nops);
	printf("make_node 2\n");
    node_t retour = malloc (sizeof(node_t));
	printf("make_node 3\n");
    //retour->node_num = cptnodes;
    retour->nature = nature;
	printf("make_node 4\n");
    retour->nops = nops;
	printf("make_node 5\n");
    node_s **hop;
	printf("make_node 6\n");

    for (int i = 0; i < nops; i++)
    {
        printf("arg supp n°%d = %d\n ", i , va_arg(ap, node_t));
        if(va_arg(ap, node_t) == NULL)
        {
            continue;
        }
        *(hop + i) = va_arg(ap,node_t);
        printf("hop affecté!, hop =%d et contient %d\n", hop , *(hop + i));
    }
    retour->opr = hop;
    // recherche des arguments supplementaires en fonction de la nature du noeud
    switch(nature)
    {
        case NODE_IDENT ://   type =  TYPE_NONE,TYPE_INT,TYPE_BOOL,TYPE_STRING,TYPE_VOID

            retour->type      =va_arg(ap,node_type); // argument supp à la position nops + 1 = type de noeud
            retour->decl_node =va_arg(ap,node_t); // argument supp à la position nops + 2 = declaration de noeud
            retour->offset    =va_arg(ap,int32_t ); // argument supp à la position nops + 3 = declaration de l'emplacement mémoire de la variable int32_t
            retour->global_decl=va_arg(ap,bool); // argument supp à la position nops + 4 = declaration globale?
            break;
        case NODE_AFFECT :
            retour->type      =va_arg(ap,node_type); // argument supp à la position nops + 1 = type de noeud
            break;
        case NODE_FUNC :
            retour->offset    =va_arg(ap,int32_t); // argument supp à la position nops + 1 = declaration de l'emplacement mémoire de la variable int32_t
            retour->stack_size=va_arg(ap,int32_t); // argument supp à la position nops + 2 = declaration de
            break;
        case NODE_TYPE:
            retour->type = va_arg(ap,node_type);
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

    va_end(ap);
    return retour;
}



/* A completer */
void analyse_tree(node_t root) {
        if (!stop_after_syntax) {
        // Appeler la passe 1

        if (!stop_after_verif) {
            create_program();
            // Appeler la passe 2

            dump_mips_program(outfile);
            free_program();
        }
        free_global_strings();
    }
}



void yyerror(node_t * program_root, char * s) {
    fprintf(stderr, "Error line %d: %s\n", yylineno, s);
    exit(1);
}
