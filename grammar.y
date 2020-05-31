%{
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>
#include "defs.h"
#include "env.h"
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
bool globalpasse1 = false; // false: main, true: declarations globales
bool errorflag = false; //flag d'erreur dans la passe 1
/* prototypes */
int yylex(void);
extern int yylineno;

void yyerror(node_t * program_root, char * s);
void yyerror_passe1(node_t * noeud, char * s);
void analyse_tree(node_t root);
node_t make_node(node_nature nature, int nops, ...);
void print_context(char * msg);
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
            $$ = make_node(NODE_PROGRAM, 2, $1, $2);
			*program_root = $$;
            bool global = true;

        }
        | maindecl /* presence de variables locales seulement*/
        {
            $$ = make_node(NODE_PROGRAM, 2, NULL, $1);
			*program_root = $$;
            bool global = false;
        }
        ;
listdecl: listdeclnonnull
        {
            $$ = $1;
		}
        |
        {
			$$ = NULL;
		}

listdeclnonnull: vardecl
            {
                $$ = $1;
			}
            | listdeclnonnull vardecl
            {
                $$ = make_node(NODE_LIST, 2, $1, $2);
			}
        ;
vardecl : type listtypedecl TOK_SEMICOL
            {
                $$ = make_node(NODE_DECLS, 2, $1, $2);
			}
        ;
type : TOK_INT
        {
			$$ = make_node(NODE_TYPE, 0, TYPE_INT);
            typetemp = TYPE_INT;
		}
        | TOK_BOOL
        {
			$$ = make_node(NODE_TYPE, 0, TYPE_BOOL);
            typetemp = TYPE_BOOL;
		}
        | TOK_VOID
        {
			$$ = make_node(NODE_TYPE, 0, TYPE_VOID);
            typetemp = TYPE_VOID;
		}
        ;
listtypedecl : decl
                {
					$$ = $1;
				}
                | listtypedecl TOK_COMMA decl
                {
					$$ = make_node(NODE_LIST, 2 , $1, $3);
				}
                ;
decl : ident
       	{
	   		$$ = make_node(NODE_DECL, 2, $1, NULL );
		}
       	| ident TOK_AFFECT expr
       	{
			$$ = make_node(NODE_DECL, 2 ,$1, $3);
		}
       	;

maindecl: type ident TOK_LPAR TOK_RPAR block
            {
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
		| expr TOK_SLL expr
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
		| TOK_LPAR expr TOK_RPAR
		{
			$$ = $2;
		}
		| ident TOK_AFFECT expr
		{
			$$ = make_node(NODE_AFFECT, 2, $1, $3); // arg supp : type de noeud
		}
		| TOK_INTVAL
		{
			$$ = make_node(NODE_INTVAL, 0, yylval.intval );
		}
		| ident
		{
			$$ = $1;
		}
        | TOK_TRUE
        {
			$$ = make_node(NODE_BOOLVAL, 0,1);
        }
        | TOK_FALSE
        {
            $$ = make_node(NODE_BOOLVAL, 0,0 );
        }
        | TOK_STRINGVAL
        {
            $$ = make_node(NODE_STRINGVAL, 0, yylval.strval, sizeof(yylval.strval) );
            free(yylval.strval);
        }
        ;

listparamprint : listparamprint TOK_COMMA paramprint
				{
					$$ = make_node(NODE_LIST, 2, $1, $3);
				}
				| paramprint
				{
					$$ = $1;
				}
				;

paramprint : ident
			{
				$$ = $1;
			}
			| TOK_STRINGVAL
			{
				$$ = make_node(NODE_STRINGVAL, 0, yylval.strval, sizeof(yylval.strval) );
                free(yylval.strval);
			}
			;

ident : TOK_IDENT
		{
			node_t nident;
            if (mainflag != 1)
            {
                $$ = make_node(NODE_IDENT, 0, typetemp, nident, -1, 1, yylval.strval);
                free(yylval.strval);
            }
            else
            {
                if (strcmp (yylval.strval, "main") == 0)
                {
                    $$ = make_node(NODE_IDENT, 0, typetemp, nident,-1, 1, yylval.strval);
                    free(yylval.strval);
                }
                else
                {
                    $$ = make_node(NODE_IDENT, 0, typetemp, nident, -1, 0, yylval.strval);
                    free(yylval.strval);
                }
            }
		}
		;


%%

node_t make_node(node_nature nature, int32_t nops, ...) {
	va_list ap; /*liste des arguments supplémentaires*/
    va_start(ap,nops);
    node_t retour, aux;
    retour = (node_s *) malloc(sizeof(node_s));
	retour->nature = nature;
	retour->nops = nops;
    retour->opr = (node_s **)malloc(sizeof(node_s*) * nops);
    retour->ident = malloc(sizeof(char)*30);
    retour->str = malloc(sizeof(char)*30);
    retour->decl_node = NULL;
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
            strcpy(retour->ident,va_arg(ap, char*)); // argument supp à la position nops + 5 =  identifiant
            break;
        case NODE_AFFECT :
            retour->type      =va_arg(ap,node_type); // argument supp à la position nops + 1 = type de noeud
            break;
        case NODE_FUNC :
            retour->offset    =8; // argument supp à la position nops + 1 = declaration de l'emplacement mémoire de la variable
            retour->stack_size=8; // argument supp à la position nops + 2 = declaration de
            break;
        case NODE_TYPE:
			retour->type = va_arg(ap,node_type);
            break;
        case NODE_INTVAL:
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
            strcpy(retour->str, va_arg(ap,char*));
			retour->offset = va_arg(ap,int32_t);
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
            break;
    }

    va_end(ap);

	if(nbtraces == 2)
	{
		couleur("34");
		printf("NODE %s\n", node_nature2string(retour->nature));
		couleur("0");
	}
    retour->lineno = yylineno;

    return retour;
}

////////////// Fonctions destinees à la passe 1 ///////////////////

void parcours_rec(node_t n) {
    int32_t offset;
    if (n == NULL) {
        return ;
    }
    char str[32];
    int i, pos;
    bool decl;
    node_t previousdef;
    //debut de contexte
    switch (n->nature) {
        case NODE_PROGRAM:
            if ( n->opr[0] != NULL ) // si il y a des déclarations globales
            {
                push_global_context();
                print_context("Pushing global context\n");
                globalpasse1 = true;
            }
            break;
        case NODE_BLOCK:
            push_context();
            print_context("Pushing simple context\n");
            break;
        case NODE_IDENT:
            if(!globalpasse1) // dans le main
            {
                previousdef = get_decl_node(n->ident);
                if ( previousdef == NULL || previousdef == n->decl_node)
                {
                    if( strcmp(n->ident, "main") != 0)
                    {
                        printf("Erreur près du signe %s\n", n->ident);
                        yyerror_passe1(&n,"pas de declaration précédente de l'ident");
                    }
                }
                else
                {
                    n->type = previousdef->type;
                }
            }
            break;
        case NODE_STRINGVAL:
            offset = add_string(n->str);
            n->offset = offset;
            break;
        case NODE_DECLS:
	        if ((n->opr[0])->type == TYPE_VOID)
	        {
	            yyerror_passe1(&n, "Déclaration de variable de type void");
	        }
            break;
        case NODE_DECL:
            offset = env_add_element(n->opr[0]->ident, n->opr[0], 4);
            if (offset < 0)
            {
                printf("Probleme offset\n");
            }
            else
            {
                n->opr[0]->offset = offset;
            }
            for (i = 0 ; i < n->nops; i++)
            {
                if ((n->opr[i]) && (n->opr[i])->nature == NODE_IDENT)
                {
                    (n->opr[i])->decl_node = n;
                }
            }
            break;

        case NODE_FUNC:
            if (globalpasse1)
            {
                print_context("Poping global context\n");
                globalpasse1 = false;
            }
            reset_env_current_offset();
            print_context("Resetting current context\n");
            if ((n->opr[1])->type != TYPE_VOID)
            {
                yyerror_passe1(&(n->opr[1]), "Le main n'a pas le bon type, type void attendu \n");
            }
            if (strcmp( ((n->opr[1])->ident), "main") != 0)
            {
                printf("nature du noeud: %s\n", node_nature2string((n->opr[1])->nature));
                printf("nom du main: %s\n", (n->opr[1])->ident);
                yyerror_passe1(&(n->opr[1]), "La fonction principale ne s'appelle pas main \n");
            }
            break;

        default:
            break;
    }
    //appel a la fonction recursive sur tous les enfants
   for (int32_t i = 0; i < n->nops; i += 1) {
        parcours_rec(n->opr[i]);
    }

    switch(n->nature) //fin de contexte
    {
        case NODE_BLOCK:
            pop_context();
            print_context("poping context\n");
            break;

        case NODE_AFFECT:
            n->type = (n->opr[0])->type;
            if (((n->opr[0])->type) != ((n->opr[1])->type))
            {
                yyerror_passe1(&n, "Affectation entre deux opérandes de type différents\n");
                printf(">Type et nature a gauche : %s et %s\n", node_type2string((n->opr[0])->type), node_nature2string((n->opr[0])->nature));
                printf(">Type et nature a droite : %s et %s\n", node_type2string((n->opr[1])->type), node_nature2string((n->opr[1])->nature));
            }
            break;

        case NODE_PLUS:
        case NODE_MINUS:
        case NODE_MUL:
        case NODE_DIV:
        case NODE_MOD:
        case NODE_BAND:
        case NODE_BOR:
        case NODE_BXOR:
        case NODE_SLL:
        case NODE_SRL:
        case NODE_SRA:
            /* type_op_binaire(int,int) = int */
            if(n->opr[0]->type != TYPE_INT)
            {
                yyerror_passe1(&n, "Le premier élément de l'opération n'est pas entier\n");
            }
            if(n->opr[1]->type != TYPE_INT)
            {
                yyerror_passe1(&n, "Le deuxième élément de l'opération n'est pas entier\n");
            }
            n->type = TYPE_INT;
            break;
        case NODE_EQ:
        case NODE_NE:
            /* type_op_binaire(int,int) = bool */
            /* type_op_binaire(bool,bool) = bool */
            if( (n->opr[0]->type == TYPE_INT && n->opr[1]->type != TYPE_INT) ||
                (n->opr[0]->type == TYPE_BOOL && n->opr[1]->type != TYPE_BOOL) )
            {
                if (nbtraces == 5)
                {
                    printf("types de op1 : %s et op2 : %s \n", node_type2string((n->opr[0])->type) , node_type2string((n->opr[1])->type));
                }

                yyerror_passe1(&n, "Les éléments ne sont pas de même type\n");
            }
            n->type = TYPE_BOOL;
            break;
        case NODE_LT:
        case NODE_GT:
        case NODE_LE:
        case NODE_GE:
            /* type_op_binaire(int,int) = bool */
            if (nbtraces == 5)
            {
                printf("NODE %s types de op1  : %s et op2 : %s \n", node_nature2symb(n->nature),
                node_type2string((n->opr[0])->type) , node_type2string((n->opr[1])->type));
            }
            if(n->opr[0]->type != TYPE_INT)
            {
                yyerror_passe1(&n, "Le premier élément de l'opération n'est pas entier\n");
            }
            if(n->opr[1]->type != TYPE_INT)
            {
                yyerror_passe1(&n, "Le deuxième élément de l'opération n'est pas entier\n");
            }
            n->type = TYPE_BOOL;
            break;
        case NODE_AND:
        case NODE_OR:
            if (nbtraces == 5)
            {
                printf("NODE %s types de op1  : %s et op2 : %s \n", node_nature2symb(n->nature),
                    node_type2string((n->opr[0])->type) , node_type2string((n->opr[1])->type));
            }
            /* type_op_binaire(bool,bool) = bool */
            if(n->opr[0]->type != TYPE_BOOL)
            {
                yyerror_passe1(&n, "Le premier élément de l'opération n'est pas booléen\n");
            }
            if(n->opr[1]->type != TYPE_BOOL)
            {
                yyerror_passe1(&n, "Le deuxième élément de l'opération n'est pas booléen\n");
            }
            n->type = TYPE_BOOL;
            break;
        case NODE_UMINUS:
        case NODE_BNOT:
            /* type_op_unaire(int) = int */
            if((n->opr[0])->type != TYPE_INT)
            {
                yyerror_passe1(&n ,"Essai de operation unaire sur un non int\n");
            }
            n->type= TYPE_INT;
            break;
        case NODE_NOT:
            /* type_op_unaire(bool) = bool */
            if(n->opr[0]->type != TYPE_BOOL)
            {
                yyerror_passe1(&n, "Essai de operation unaire sur un non bool\n");
            }
            n->type = TYPE_BOOL;
            break;
        case NODE_IF:
        case NODE_WHILE:
            if((n->opr[0])->type != TYPE_BOOL)
            {
                yyerror_passe1(&n, "Expression dans une boucle n'est pas booleenne\n");
            }
            break;
        case NODE_DOWHILE:
        case NODE_FOR:

            if((n->opr[1])->type != TYPE_BOOL)
            {
                yyerror_passe1(&n, "Expression dans une boucle n'est pas booleenne\n");
            }
            break;
        case NODE_DECL:
            if( n->opr[1] && (n->opr[0])->type != (n->opr[1])->type )
            {
                yyerror_passe1(&n,"Erreur de type dans la declaration\n");
            }

            break;
        default:
            break;
    }

}

static void lancer_parcours(node_t root) {
    assert(root->nature == NODE_PROGRAM);
    parcours_rec(root);
}
//////////////////////////////////////////////////////////////////
void free_tree(node_t node, int tab)
{

    if (node == NULL) {
        return;
    }
    if(nbtraces == 4)
    {
        for(int i = 0; i < tab; i++) printf("    ");
        printf("freeing node %s\n", node_nature2string(node->nature));
        if(node->nature == NODE_IDENT) {
            for(int i = 0; i < tab; i++) printf("    ");
            printf("%s\n", node_type2string(node->type));
        }
        for(int i = 0; i < tab; i++) printf("    ");
        printf("nops = %d\n", node->nops);
        tab++;
    }
    for (int32_t i = 0; i < node->nops; i += 1) {
            free_tree(node->opr[i], tab);
    }
    free(node->opr);
    free(node->ident);
    free(node->str);
    free(node);
    if(nbtraces == 4)
    {
        for(int i = 0; i < tab-1; i++) printf("    ");
        printf("free was successful\n");
    }
}

void analyse_tree(node_t root) {

        if (!stop_after_syntax) {
        // Appeler la passe 1
        lancer_parcours(root);
        //si jamais il y a eu une detection d'erreur au cours de la passe 1
        if(errorflag)
        {
            exit(1);
        }
    	if(nbtraces == 3)
    	{
    		char * txtname = "tree.dot";
    		dump_tree(root,txtname); // afficher le tree
    	}

        if (!stop_after_verif) {
            create_program();
            // Appeler la passe 2

            //dump_mips_program(outfile);
            free_program();
        }
        free_global_strings();
        free_tree(root, 0);
    }
}


void yyerror(node_t * program_root, char * s) {
    fprintf(stderr, "Error line %d: %s\n", yylineno, s);
    exit(1);
}

void yyerror_passe1(node_t * noeud, char * s) {
    couleur("31");
    errorflag = true;
    printf( "Error line %d: %s\n", (*noeud)->lineno, s);
    couleur("0");
}

void print_context(char* msg)
{
    if(nbtraces == 5)
    {
        printf("%s", msg);
    }
}
