/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "grammar.y"
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
int cptenfants = 1;/*nombre de vardecl quand il y a plusieurs declaration en liste*/
int cptvar = 0;/*compteur de declaration de variables ligne apres ligne*/
bool globalpasse1 = false; /* false: main, true: declarations globales*/
bool errorflag = false; /*flag d'erreur dans la passe 1*/
/* prototypes */
int yylex(void);
extern int yylineno;

void yyerror(node_t * program_root, char * s);
void yyerror_passe1(node_t * noeud, char * s);
void analyse_tree(node_t root);
node_t make_node(node_nature nature, int nops, ...);
void print_context(char * msg);
/* A completer */

#line 49 "grammar.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
    int32_t intval;
    char * strval;
    node_t ptr;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 77 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(node_t *  program_root)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(node_t *  program_root, const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(program_root, msg)
#endif

extern int YYPARSE_DECL();

#define TOK_VOID 257
#define TOK_INT 258
#define TOK_INTVAL 259
#define TOK_BOOL 260
#define TOK_TRUE 261
#define TOK_FALSE 262
#define TOK_IDENT 263
#define TOK_IF 264
#define TOK_ELSE 265
#define TOK_WHILE 266
#define TOK_FOR 267
#define TOK_PRINT 268
#define TOK_AFFECT 269
#define TOK_GE 270
#define TOK_LE 271
#define TOK_GT 272
#define TOK_LT 273
#define TOK_EQ 274
#define TOK_NE 275
#define TOK_PLUS 276
#define TOK_MINUS 277
#define TOK_MUL 278
#define TOK_DIV 279
#define TOK_MOD 280
#define TOK_UMINUS 281
#define TOK_SEMICOL 282
#define TOK_COMMA 283
#define TOK_LPAR 284
#define TOK_RPAR 285
#define TOK_LACC 286
#define TOK_RACC 287
#define TOK_STRING 288
#define TOK_DO 289
#define TOK_STRINGVAL 290
#define TOK_THEN 291
#define TOK_OR 292
#define TOK_AND 293
#define TOK_BOR 294
#define TOK_BXOR 295
#define TOK_BAND 296
#define TOK_SRL 297
#define TOK_SRA 298
#define TOK_SLL 299
#define TOK_NOT 300
#define TOK_BNOT 301
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,   14,   14,   15,   15,    1,    3,    3,    3,
    4,    4,    5,    5,    6,    7,    7,    8,    8,    9,
    9,    9,    9,    9,    9,    9,    9,    9,   10,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   12,   12,
   13,   13,    2,
};
static const YYINT yylen[] = {                            2,
    2,    1,    1,    0,    1,    2,    3,    1,    1,    1,
    1,    3,    1,    3,    5,    1,    0,    1,    2,    2,
    7,    5,    5,    9,    7,    1,    1,    5,    4,    3,
    3,    3,    3,    3,    3,    3,    2,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    2,
    2,    3,    3,    1,    1,    1,    1,    1,    3,    1,
    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
   10,    8,    9,    0,    5,    0,    2,    0,   63,    0,
    0,   11,    6,    1,    0,    0,    7,    0,   54,   56,
   57,    0,    0,   58,    0,    0,    0,    0,    0,    0,
   12,   37,    0,   50,   51,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   15,   52,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   30,   31,   34,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   27,    0,    0,    0,   18,
   26,    0,    0,    0,    0,    0,    0,   29,   19,   20,
    0,    0,    0,   62,   61,    0,   60,    0,    0,    0,
    0,    0,    0,    0,    0,   23,    0,   59,   28,    0,
    0,    0,    0,   21,    0,   25,    0,   24,
};
static const YYINT yydgoto[] = {                          4,
    5,   27,    6,   11,   12,    7,   88,   89,   90,   91,
   92,  106,  107,   80,    8,
};
static const YYINT yysindex[] = {                      -241,
    0,    0,    0,    0,    0, -254,    0, -241,    0, -266,
 -270,    0,    0,    0,  -55, -265,    0, -254,    0,    0,
    0,  -55,  -55,    0,  -55,  -55, -222,  247, -221, -208,
    0,    0,    7,    0,    0,  -55,  -55,  -55,  -55,  -55,
  -55,  -55,  -55,  -55,  -55,  -55,  -55,  -55,  -55,  -55,
  -55,  -55,  -55,  -55,  -55, -241,    0,    0,  247, -134,
 -134, -134, -134,  -61,  -61, -274, -274,    0,    0,    0,
  337,  348,  468,  479,  258, -158, -158, -158, -254,  -87,
 -241, -214, -211, -207, -203,    0,  -87, -187,  -87,    0,
    0,   37,  -55,  -55,  -55, -248, -164,    0,    0,    0,
   67,   97,  127,    0,    0, -229,    0, -174,  -87,  -87,
  -55, -248, -170,  -55, -150,    0,  157,    0,    0,  187,
  -87,  -55, -157,    0,  217,    0,  -87,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -185,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -23, -177,    0, -185,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -218,    0,    0, -198,  498,
  514,  530,  546,  561,  576,  277,  307,    0,    0,    0,
 -225, -230, -100,  303,  -62,  378,  408,  438,    0, -161,
 -173,    0,    0,    0,    0,    0,    0,    0, -148,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -130,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   -7,   -4,   -5,    0,  112,  132,    0,    0,   14,  119,
  -15,    0,   38,    0,   93,
};
#define YYTABLESIZE 872
static const YYINT yytable[] = {                         28,
   13,   10,   15,   45,   46,   47,   32,   33,    9,   34,
   35,   17,   18,   30,    9,    1,    2,   16,    3,   29,
   59,   60,   61,   62,   63,   64,   65,   66,   67,   68,
   69,   70,   71,   72,   73,   74,   75,   76,   77,   78,
    4,  104,    4,    4,    4,    4,   36,    4,    4,    4,
   79,   42,   42,  112,   42,  113,   43,   43,    4,   43,
   15,   42,   42,    4,   56,    4,   43,    4,    4,   93,
    4,    4,   94,   13,   30,   79,   95,  101,  102,  103,
   96,    4,    4,   53,   53,    3,   53,    3,    3,    3,
    3,  105,    3,    3,    3,  117,   13,   13,  120,   98,
   97,  108,   99,    3,   14,   14,  125,  105,    3,  114,
    3,  119,    3,    3,  121,    3,    3,   43,   44,   45,
   46,   47,  115,  116,  126,   17,    3,    3,   22,   31,
   22,   22,   22,   22,  124,   22,   22,   22,   16,   14,
  128,   43,   44,   45,   46,   47,   22,   57,   81,  118,
    0,   22,    0,   22,    0,   22,   22,    0,   22,   22,
    0,    0,   53,   54,   55,    0,    0,    0,    0,   22,
   22,   19,    0,   20,   21,    9,   82,    0,   83,   84,
   85,   45,   45,    0,   45,    0,    0,    0,    0,   22,
    0,   45,   45,   45,   86,    0,   23,    0,   56,    0,
    0,   87,   24,   19,    0,   20,   21,    9,   37,   38,
   39,   40,   25,   26,   43,   44,   45,   46,   47,   44,
   44,   22,   44,    0,    0,    0,    0,    0,   23,   44,
   44,   44,   44,   44,   24,   53,   54,   55,    0,    0,
    0,    0,    0,    0,   25,   26,   55,   55,   55,   55,
   55,   55,   55,   55,   55,   55,   55,    0,   55,   55,
    0,   55,    0,    0,    0,    0,    0,    0,   55,   55,
   55,   55,   55,   55,   55,   55,   37,   38,   39,   40,
   41,   42,   43,   44,   45,   46,   47,    0,    0,    0,
    0,   58,    0,    0,    0,    0,    0,    0,   48,   49,
   50,   51,   52,   53,   54,   55,   37,   38,   39,   40,
   41,   42,   43,   44,   45,   46,   47,    0,  100,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   48,   49,
   50,   51,   52,   53,   54,   55,   37,   38,   39,   40,
   41,   42,   43,   44,   45,   46,   47,    0,    0,    0,
    0,  109,    0,    0,    0,    0,    0,    0,   48,   49,
   50,   51,   52,   53,   54,   55,   37,   38,   39,   40,
   41,   42,   43,   44,   45,   46,   47,    0,    0,    0,
    0,  110,    0,    0,    0,    0,    0,    0,   48,   49,
   50,   51,   52,   53,   54,   55,   37,   38,   39,   40,
   41,   42,   43,   44,   45,   46,   47,    0,  111,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   48,   49,
   50,   51,   52,   53,   54,   55,   37,   38,   39,   40,
   41,   42,   43,   44,   45,   46,   47,    0,  122,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   48,   49,
   50,   51,   52,   53,   54,   55,   37,   38,   39,   40,
   41,   42,   43,   44,   45,   46,   47,    0,    0,    0,
    0,  123,    0,    0,    0,    0,    0,    0,   48,   49,
   50,   51,   52,   53,   54,   55,   37,   38,   39,   40,
   41,   42,   43,   44,   45,   46,   47,    0,    0,    0,
    0,  127,    0,    0,    0,    0,    0,    0,   48,   49,
   50,   51,   52,   53,   54,   55,   37,   38,   39,   40,
   41,   42,   43,   44,   45,   46,   47,   37,   38,   39,
   40,   41,   42,   43,   44,   45,   46,   47,   48,   49,
   50,   51,   52,   53,   54,   55,   32,   32,   32,   32,
   32,   32,   32,   32,   53,   54,   55,    0,   32,   32,
    0,   32,    0,    0,    0,    0,    0,    0,   32,   32,
   32,   32,   32,   32,   32,   32,   33,   33,   33,   33,
   33,   33,   33,   33,   46,   46,    0,   46,   33,   33,
    0,   33,    0,    0,   46,   46,   46,   46,   33,   33,
   33,   33,   33,   33,   33,   33,   37,   38,   39,   40,
   41,   42,   43,   44,   45,   46,   47,   37,   38,   39,
   40,   41,   42,   43,   44,   45,   46,   47,    0,   49,
   50,   51,   52,   53,   54,   55,    0,    0,    0,    0,
    0,   50,   51,   52,   53,   54,   55,   47,   47,   47,
   47,   47,   47,    0,    0,    0,    0,    0,    0,   47,
   47,    0,   47,    0,    0,    0,    0,    0,    0,   47,
   47,   47,   47,   47,   47,   47,   47,   48,   48,   48,
   48,   48,   48,    0,    0,    0,    0,    0,    0,   48,
   48,    0,   48,    0,    0,    0,    0,    0,    0,   48,
   48,   48,   48,   48,   48,   48,   48,   49,   49,   49,
   49,   49,   49,    0,    0,    0,    0,    0,    0,   49,
   49,    0,   49,    0,    0,    0,    0,    0,    0,   49,
   49,   49,   49,   49,   49,   49,   49,   37,   38,   39,
   40,   41,   42,   43,   44,   45,   46,   47,   37,   38,
   39,   40,   41,   42,   43,   44,   45,   46,   47,    0,
    0,    0,   51,   52,   53,   54,   55,   38,   38,   38,
   38,   38,   38,    0,   52,   53,   54,   55,    0,   38,
   38,    0,   38,   39,   39,   39,   39,   39,   39,   38,
   38,   38,   38,   38,    0,   39,   39,    0,   39,   36,
   36,   36,   36,   36,   36,   39,   39,   39,   39,   39,
    0,   36,   36,    0,   36,   35,   35,   35,   35,   35,
   35,   36,   36,   36,   36,   36,    0,   35,   35,    0,
   35,    0,    0,    0,   40,   40,    0,   35,   35,   35,
   35,   35,   40,   40,    0,   40,    0,    0,    0,   41,
   41,    0,   40,   40,   40,   40,   40,   41,   41,    0,
   41,    0,    0,    0,    0,    0,    0,   41,   41,   41,
   41,   41,
};
static const YYINT yycheck[] = {                         15,
    8,    6,  269,  278,  279,  280,   22,   23,  263,   25,
   26,  282,  283,   18,  263,  257,  258,  284,  260,  285,
   36,   37,   38,   39,   40,   41,   42,   43,   44,   45,
   46,   47,   48,   49,   50,   51,   52,   53,   54,   55,
  259,  290,  261,  262,  263,  264,  269,  266,  267,  268,
   56,  282,  283,  283,  285,  285,  282,  283,  277,  285,
  269,  292,  293,  282,  286,  284,  292,  286,  287,  284,
  289,  290,  284,   81,   79,   81,  284,   93,   94,   95,
  284,  300,  301,  282,  283,  259,  285,  261,  262,  263,
  264,   96,  266,  267,  268,  111,  282,  283,  114,  287,
   87,  266,   89,  277,  282,  283,  122,  112,  282,  284,
  284,  282,  286,  287,  265,  289,  290,  276,  277,  278,
  279,  280,  109,  110,  282,  287,  300,  301,  259,   18,
  261,  262,  263,  264,  121,  266,  267,  268,  287,    8,
  127,  276,  277,  278,  279,  280,  277,   29,   56,  112,
   -1,  282,   -1,  284,   -1,  286,  287,   -1,  289,  290,
   -1,   -1,  297,  298,  299,   -1,   -1,   -1,   -1,  300,
  301,  259,   -1,  261,  262,  263,  264,   -1,  266,  267,
  268,  282,  283,   -1,  285,   -1,   -1,   -1,   -1,  277,
   -1,  292,  293,  294,  282,   -1,  284,   -1,  286,   -1,
   -1,  289,  290,  259,   -1,  261,  262,  263,  270,  271,
  272,  273,  300,  301,  276,  277,  278,  279,  280,  282,
  283,  277,  285,   -1,   -1,   -1,   -1,   -1,  284,  292,
  293,  294,  295,  296,  290,  297,  298,  299,   -1,   -1,
   -1,   -1,   -1,   -1,  300,  301,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  280,   -1,  282,  283,
   -1,  285,   -1,   -1,   -1,   -1,   -1,   -1,  292,  293,
  294,  295,  296,  297,  298,  299,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  280,   -1,   -1,   -1,
   -1,  285,   -1,   -1,   -1,   -1,   -1,   -1,  292,  293,
  294,  295,  296,  297,  298,  299,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  280,   -1,  282,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  292,  293,
  294,  295,  296,  297,  298,  299,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  280,   -1,   -1,   -1,
   -1,  285,   -1,   -1,   -1,   -1,   -1,   -1,  292,  293,
  294,  295,  296,  297,  298,  299,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  280,   -1,   -1,   -1,
   -1,  285,   -1,   -1,   -1,   -1,   -1,   -1,  292,  293,
  294,  295,  296,  297,  298,  299,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  280,   -1,  282,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  292,  293,
  294,  295,  296,  297,  298,  299,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  280,   -1,  282,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  292,  293,
  294,  295,  296,  297,  298,  299,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  280,   -1,   -1,   -1,
   -1,  285,   -1,   -1,   -1,   -1,   -1,   -1,  292,  293,
  294,  295,  296,  297,  298,  299,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  280,   -1,   -1,   -1,
   -1,  285,   -1,   -1,   -1,   -1,   -1,   -1,  292,  293,
  294,  295,  296,  297,  298,  299,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  280,  270,  271,  272,
  273,  274,  275,  276,  277,  278,  279,  280,  292,  293,
  294,  295,  296,  297,  298,  299,  270,  271,  272,  273,
  274,  275,  276,  277,  297,  298,  299,   -1,  282,  283,
   -1,  285,   -1,   -1,   -1,   -1,   -1,   -1,  292,  293,
  294,  295,  296,  297,  298,  299,  270,  271,  272,  273,
  274,  275,  276,  277,  282,  283,   -1,  285,  282,  283,
   -1,  285,   -1,   -1,  292,  293,  294,  295,  292,  293,
  294,  295,  296,  297,  298,  299,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  280,  270,  271,  272,
  273,  274,  275,  276,  277,  278,  279,  280,   -1,  293,
  294,  295,  296,  297,  298,  299,   -1,   -1,   -1,   -1,
   -1,  294,  295,  296,  297,  298,  299,  270,  271,  272,
  273,  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,  282,
  283,   -1,  285,   -1,   -1,   -1,   -1,   -1,   -1,  292,
  293,  294,  295,  296,  297,  298,  299,  270,  271,  272,
  273,  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,  282,
  283,   -1,  285,   -1,   -1,   -1,   -1,   -1,   -1,  292,
  293,  294,  295,  296,  297,  298,  299,  270,  271,  272,
  273,  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,  282,
  283,   -1,  285,   -1,   -1,   -1,   -1,   -1,   -1,  292,
  293,  294,  295,  296,  297,  298,  299,  270,  271,  272,
  273,  274,  275,  276,  277,  278,  279,  280,  270,  271,
  272,  273,  274,  275,  276,  277,  278,  279,  280,   -1,
   -1,   -1,  295,  296,  297,  298,  299,  270,  271,  272,
  273,  274,  275,   -1,  296,  297,  298,  299,   -1,  282,
  283,   -1,  285,  270,  271,  272,  273,  274,  275,  292,
  293,  294,  295,  296,   -1,  282,  283,   -1,  285,  270,
  271,  272,  273,  274,  275,  292,  293,  294,  295,  296,
   -1,  282,  283,   -1,  285,  270,  271,  272,  273,  274,
  275,  292,  293,  294,  295,  296,   -1,  282,  283,   -1,
  285,   -1,   -1,   -1,  274,  275,   -1,  292,  293,  294,
  295,  296,  282,  283,   -1,  285,   -1,   -1,   -1,  274,
  275,   -1,  292,  293,  294,  295,  296,  282,  283,   -1,
  285,   -1,   -1,   -1,   -1,   -1,   -1,  292,  293,  294,
  295,  296,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 301
#define YYUNDFTOKEN 319
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"TOK_VOID","TOK_INT","TOK_INTVAL",
"TOK_BOOL","TOK_TRUE","TOK_FALSE","TOK_IDENT","TOK_IF","TOK_ELSE","TOK_WHILE",
"TOK_FOR","TOK_PRINT","TOK_AFFECT","TOK_GE","TOK_LE","TOK_GT","TOK_LT","TOK_EQ",
"TOK_NE","TOK_PLUS","TOK_MINUS","TOK_MUL","TOK_DIV","TOK_MOD","TOK_UMINUS",
"TOK_SEMICOL","TOK_COMMA","TOK_LPAR","TOK_RPAR","TOK_LACC","TOK_RACC",
"TOK_STRING","TOK_DO","TOK_STRINGVAL","TOK_THEN","TOK_OR","TOK_AND","TOK_BOR",
"TOK_BXOR","TOK_BAND","TOK_SRL","TOK_SRA","TOK_SLL","TOK_NOT","TOK_BNOT",0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : listdeclnonnull maindecl",
"program : maindecl",
"listdecl : listdeclnonnull",
"listdecl :",
"listdeclnonnull : vardecl",
"listdeclnonnull : listdeclnonnull vardecl",
"vardecl : type listtypedecl TOK_SEMICOL",
"type : TOK_INT",
"type : TOK_BOOL",
"type : TOK_VOID",
"listtypedecl : decl",
"listtypedecl : listtypedecl TOK_COMMA decl",
"decl : ident",
"decl : ident TOK_AFFECT expr",
"maindecl : type ident TOK_LPAR TOK_RPAR block",
"listinst : listinstnonnull",
"listinst :",
"listinstnonnull : inst",
"listinstnonnull : listinstnonnull inst",
"inst : expr TOK_SEMICOL",
"inst : TOK_IF TOK_LPAR expr TOK_RPAR inst TOK_ELSE inst",
"inst : TOK_IF TOK_LPAR expr TOK_RPAR inst",
"inst : TOK_WHILE TOK_LPAR expr TOK_RPAR inst",
"inst : TOK_FOR TOK_LPAR expr TOK_SEMICOL expr TOK_SEMICOL expr TOK_RPAR inst",
"inst : TOK_DO inst TOK_WHILE TOK_LPAR expr TOK_RPAR TOK_SEMICOL",
"inst : block",
"inst : TOK_SEMICOL",
"inst : TOK_PRINT TOK_LPAR listparamprint TOK_RPAR TOK_SEMICOL",
"block : TOK_LACC listdecl listinst TOK_RACC",
"expr : expr TOK_MUL expr",
"expr : expr TOK_DIV expr",
"expr : expr TOK_PLUS expr",
"expr : expr TOK_MINUS expr",
"expr : expr TOK_MOD expr",
"expr : expr TOK_LT expr",
"expr : expr TOK_GT expr",
"expr : TOK_MINUS expr",
"expr : expr TOK_GE expr",
"expr : expr TOK_LE expr",
"expr : expr TOK_EQ expr",
"expr : expr TOK_NE expr",
"expr : expr TOK_AND expr",
"expr : expr TOK_OR expr",
"expr : expr TOK_BAND expr",
"expr : expr TOK_BOR expr",
"expr : expr TOK_BXOR expr",
"expr : expr TOK_SRL expr",
"expr : expr TOK_SRA expr",
"expr : expr TOK_SLL expr",
"expr : TOK_NOT expr",
"expr : TOK_BNOT expr",
"expr : TOK_LPAR expr TOK_RPAR",
"expr : ident TOK_AFFECT expr",
"expr : TOK_INTVAL",
"expr : ident",
"expr : TOK_TRUE",
"expr : TOK_FALSE",
"expr : TOK_STRINGVAL",
"listparamprint : listparamprint TOK_COMMA paramprint",
"listparamprint : paramprint",
"paramprint : ident",
"paramprint : TOK_STRINGVAL",
"ident : TOK_IDENT",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 405 "grammar.y"

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
#line 956 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 102 "grammar.y"
	{
            yyval.ptr = make_node(NODE_PROGRAM, 2, yystack.l_mark[-1].ptr, yystack.l_mark[0].ptr);
			*program_root = yyval.ptr;
            bool global = true;

        }
break;
case 2:
#line 109 "grammar.y"
	{
            yyval.ptr = make_node(NODE_PROGRAM, 2, NULL, yystack.l_mark[0].ptr);
			*program_root = yyval.ptr;
            bool global = false;
        }
break;
case 3:
#line 116 "grammar.y"
	{
            yyval.ptr = yystack.l_mark[0].ptr;
		}
break;
case 4:
#line 120 "grammar.y"
	{
			yyval.ptr = NULL;
		}
break;
case 5:
#line 125 "grammar.y"
	{
                yyval.ptr = yystack.l_mark[0].ptr;
			}
break;
case 6:
#line 129 "grammar.y"
	{
                yyval.ptr = make_node(NODE_LIST, 2, yystack.l_mark[-1].ptr, yystack.l_mark[0].ptr);
			}
break;
case 7:
#line 134 "grammar.y"
	{
                yyval.ptr = make_node(NODE_DECLS, 2, yystack.l_mark[-2].ptr, yystack.l_mark[-1].ptr);
			}
break;
case 8:
#line 139 "grammar.y"
	{
			yyval.ptr = make_node(NODE_TYPE, 0, TYPE_INT);
            typetemp = TYPE_INT;
		}
break;
case 9:
#line 144 "grammar.y"
	{
			yyval.ptr = make_node(NODE_TYPE, 0, TYPE_BOOL);
            typetemp = TYPE_BOOL;
		}
break;
case 10:
#line 149 "grammar.y"
	{
			yyval.ptr = make_node(NODE_TYPE, 0, TYPE_VOID);
            typetemp = TYPE_VOID;
		}
break;
case 11:
#line 155 "grammar.y"
	{
					yyval.ptr = yystack.l_mark[0].ptr;
				}
break;
case 12:
#line 159 "grammar.y"
	{
					yyval.ptr = make_node(NODE_LIST, 2 , yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
				}
break;
case 13:
#line 164 "grammar.y"
	{
	   		yyval.ptr = make_node(NODE_DECL, 2, yystack.l_mark[0].ptr, NULL );
		}
break;
case 14:
#line 168 "grammar.y"
	{
			yyval.ptr = make_node(NODE_DECL, 2 ,yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 15:
#line 174 "grammar.y"
	{
    			cptenfants = 1;
                cptvar = 0;
                yyval.ptr = make_node(NODE_FUNC, 3, yystack.l_mark[-4].ptr, yystack.l_mark[-3].ptr, yystack.l_mark[0].ptr, 8, 8);
			}
break;
case 16:
#line 181 "grammar.y"
	{
				yyval.ptr = yystack.l_mark[0].ptr;
			}
break;
case 17:
#line 185 "grammar.y"
	{
				yyval.ptr = NULL;
			}
break;
case 18:
#line 189 "grammar.y"
	{
					yyval.ptr = yystack.l_mark[0].ptr;
				}
break;
case 19:
#line 193 "grammar.y"
	{
					yyval.ptr = make_node(NODE_LIST, 2, yystack.l_mark[-1].ptr, yystack.l_mark[0].ptr);
				}
break;
case 20:
#line 198 "grammar.y"
	{
			yyval.ptr = yystack.l_mark[-1].ptr;
		}
break;
case 21:
#line 202 "grammar.y"
	{
			yyval.ptr = make_node(NODE_IF, 3, yystack.l_mark[-4].ptr, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 22:
#line 206 "grammar.y"
	{
			yyval.ptr = make_node(NODE_IF, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 23:
#line 210 "grammar.y"
	{
			yyval.ptr = make_node(NODE_WHILE, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 24:
#line 214 "grammar.y"
	{
			yyval.ptr = make_node(NODE_FOR, 4, yystack.l_mark[-6].ptr ,yystack.l_mark[-4].ptr, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 25:
#line 218 "grammar.y"
	{
			yyval.ptr = make_node(NODE_DOWHILE, 2, yystack.l_mark[-5].ptr, yystack.l_mark[-2].ptr);
		}
break;
case 26:
#line 222 "grammar.y"
	{
			yyval.ptr = yystack.l_mark[0].ptr;
		}
break;
case 27:
#line 226 "grammar.y"
	{
			yyval.ptr = NULL;
		}
break;
case 28:
#line 230 "grammar.y"
	{
			yyval.ptr = make_node(NODE_PRINT, 1, yystack.l_mark[-2].ptr);
		}
break;
case 29:
#line 235 "grammar.y"
	{
			yyval.ptr = make_node(NODE_BLOCK, 2, yystack.l_mark[-2].ptr, yystack.l_mark[-1].ptr);
		}
break;
case 30:
#line 240 "grammar.y"
	{
			yyval.ptr = make_node(NODE_MUL, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 31:
#line 244 "grammar.y"
	{
			yyval.ptr = make_node(NODE_DIV, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 32:
#line 248 "grammar.y"
	{
			yyval.ptr = make_node(NODE_PLUS, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 33:
#line 252 "grammar.y"
	{
			yyval.ptr = make_node(NODE_MINUS, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 34:
#line 256 "grammar.y"
	{
			yyval.ptr = make_node(NODE_MOD, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 35:
#line 260 "grammar.y"
	{
			yyval.ptr = make_node(NODE_LT, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 36:
#line 264 "grammar.y"
	{
			yyval.ptr = make_node(NODE_GT, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 37:
#line 268 "grammar.y"
	{
			yyval.ptr = make_node(NODE_UMINUS, 1, yystack.l_mark[0].ptr);
		}
break;
case 38:
#line 272 "grammar.y"
	{
			yyval.ptr = make_node(NODE_GE, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 39:
#line 276 "grammar.y"
	{
            yyval.ptr = make_node(NODE_LE, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 40:
#line 280 "grammar.y"
	{
            yyval.ptr = make_node(NODE_EQ, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 41:
#line 284 "grammar.y"
	{
            yyval.ptr = make_node(NODE_NE, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 42:
#line 288 "grammar.y"
	{
            yyval.ptr = make_node(NODE_AND, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 43:
#line 292 "grammar.y"
	{
            yyval.ptr = make_node(NODE_OR, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 44:
#line 296 "grammar.y"
	{
            yyval.ptr = make_node(NODE_BAND, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 45:
#line 300 "grammar.y"
	{
            yyval.ptr = make_node(NODE_BOR, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 46:
#line 304 "grammar.y"
	{
            yyval.ptr = make_node(NODE_BXOR, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 47:
#line 308 "grammar.y"
	{
			yyval.ptr = make_node(NODE_SRL, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 48:
#line 312 "grammar.y"
	{
			yyval.ptr = make_node(NODE_SRA, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 49:
#line 316 "grammar.y"
	{
            yyval.ptr = make_node(NODE_SLL, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 50:
#line 320 "grammar.y"
	{
			yyval.ptr = make_node(NODE_NOT, 1, yystack.l_mark[0].ptr);
		}
break;
case 51:
#line 324 "grammar.y"
	{
			yyval.ptr = make_node(NODE_BNOT, 1, yystack.l_mark[0].ptr);
		}
break;
case 52:
#line 328 "grammar.y"
	{
			yyval.ptr = yystack.l_mark[-1].ptr;
		}
break;
case 53:
#line 332 "grammar.y"
	{
			yyval.ptr = make_node(NODE_AFFECT, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr); /* arg supp : type de noeud*/
		}
break;
case 54:
#line 336 "grammar.y"
	{
			yyval.ptr = make_node(NODE_INTVAL, 0, yylval.intval );
		}
break;
case 55:
#line 340 "grammar.y"
	{
			yyval.ptr = yystack.l_mark[0].ptr;
		}
break;
case 56:
#line 344 "grammar.y"
	{
			yyval.ptr = make_node(NODE_BOOLVAL, 0,1);
        }
break;
case 57:
#line 348 "grammar.y"
	{
            yyval.ptr = make_node(NODE_BOOLVAL, 0,0 );
        }
break;
case 58:
#line 352 "grammar.y"
	{
            yyval.ptr = make_node(NODE_STRINGVAL, 0, yylval.strval, sizeof(yylval.strval) );
            free(yylval.strval);
        }
break;
case 59:
#line 359 "grammar.y"
	{
					yyval.ptr = make_node(NODE_LIST, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
				}
break;
case 60:
#line 363 "grammar.y"
	{
					yyval.ptr = yystack.l_mark[0].ptr;
				}
break;
case 61:
#line 369 "grammar.y"
	{
				yyval.ptr = yystack.l_mark[0].ptr;
			}
break;
case 62:
#line 373 "grammar.y"
	{
				yyval.ptr = make_node(NODE_STRINGVAL, 0, yylval.strval, sizeof(yylval.strval) );
                free(yylval.strval);
			}
break;
case 63:
#line 380 "grammar.y"
	{
			node_t nident;
            if (mainflag != 1)
            {
                yyval.ptr = make_node(NODE_IDENT, 0, typetemp, nident, -1, 1, yylval.strval);
                free(yylval.strval);
            }
            else
            {
                if (strcmp (yylval.strval, "main") == 0)
                {
                    yyval.ptr = make_node(NODE_IDENT, 0, typetemp, nident,-1, 1, yylval.strval);
                    free(yylval.strval);
                }
                else
                {
                    yyval.ptr = make_node(NODE_IDENT, 0, typetemp, nident, -1, 0, yylval.strval);
                    free(yylval.strval);
                }
            }
		}
break;
#line 1566 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
