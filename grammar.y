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
%nonassoc TOK_UMINUS /* d'après la description de la non associativité il semblerait qu'il y aie une erreur dans le sujet*/

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
%left TOK_ELSE TOK_NOT TOK_BNOT



%type <intval> TOK_INTVAL
%type <strval> TOK_IDENT TOK_STRING
%type <ptr> vardecl ident type listtypedecl decl
%type <ptr> maindecl listinst listinstnonnull inst
%type <ptr> block expr listparamprint paramprint

%%

/* Regles ici */
program:
        listdeclnonnull maindecl
        {
            $$ = make_node(NODE_PROGRAM, 2, $1, $2);
            *program_root = $$;
        }
        | maindecl
        {
            $$ = make_node(NODE_PROGRAM, 2, NULL, $1);
            *program_root = $$;
        }
        ;
listdecl: listdeclnonnull
        {
            /*$$ = make_node();*/
        }
        |
        { $$ = NULL; }

listdeclnonnull: vardecl
            { $$ = NULL; }
            | listdeclnonnull vardecl
            { $$ = NULL; }
        ;
vardecl : type listtypedecl TOK_SEMICOL
            { $$ = NULL; }
            ;
type : TOK_INT
        { $$ = NULL; }
        | TOK_BOOL
        { $$ = NULL; }
        | TOK_VOID
        { $$ = NULL; }
        ;
listtypedecl : decl
                { $$ = NULL; }
                | listtypedecl TOK_COMMA decl
                { $$ = NULL; }
                ;
decl : ident
       { $$ = NULL; }
       | ident TOK_AFFECT expr
       { $$ = NULL; }
       ;

maindecl: type ident TOK_LPAR TOK_RPAR block
            { $$ = NULL; }
        ;
listinst : listinstnonnull
            { $$ = NULL; }
            |
            { $$ = NULL; }
listinstnonnull : inst
                 { $$ = NULL; }
                 | listinstnonnull inst
                 { $$ = NULL; }
                 ;
inst: expr TOK_SEMICOL
        { $$ = NULL; }
        | TOK_IF TOK_LPAR expr TOK_RPAR inst TOK_ELSE inst
        { $$ = NULL; }
        | TOK_IF TOK_LPAR expr TOK_RPAR inst %prec TOK_THEN
        { $$ = NULL; }
        | TOK_WHILE TOK_LPAR expr TOK_RPAR inst
        { $$ = NULL; }
        |TOK_FOR TOK_LPAR expr TOK_SEMICOL expr TOK_SEMICOL expr TOK_RPAR inst
        { $$ = NULL; }
        |TOK_DO inst TOK_WHLE TOK_PAR expr TOK_RPAR TOK_SEMICOL
        { $$ = NULL; }
        | block
        { $$ = NULL; }
        | TOK_SEMICOL
        { $$ = NULL; }
        | TOK_PRINT TOK_LPAR lisparamprint TOK_RPAR TOK_SEMICOL
        { $$ = NULL; }
        ;
block: TOK_LACC listdecl listinst TOK_RACC
        { $$ = NULL; }
        ;
expr : expr TOK_MUL expr
        { $$ = NULL; }
        |expr TOK_DIV expr
        { $$ = NULL; }
        | expr TOK_PLUS expr
        { $$ = NULL; }
        | expr TOK_MINUS expr
        { $$ = NULL; }
        | expr TOK_MOD expr
        { $$ = NULL; }
        | expr TOK_LT expr
        { $$ = NULL; }
        | expr TOK_GT expr
        { $$ = NULL; }
        | TOK_MINUS expr %prec TOK_UMINUS
        { $$ = NULL; }
        | expr TOK_GE expr
        { $$ = NULL; }
        ;

/* A completer et/ou remplacer avec d'autres fonctions */

node_t make_node(node_nature nature, int nops, ...) {
    va_list ap; /*liste des arguments supplémentaires*/
    va_start(ap,nops);
    node_t retour;/* malloc?*/
    retour->nature = nature;
    retour->nops = nops;
    node_s **hop;

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
