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


/* prototypes */
int yylex(void);
extern int yylineno;

void yyerror(node_t * program_root, char * s);
void analyse_tree(node_t root);
node_t make_node(node_nature nature, int nops, ...);
/* A completer */

#line 42 "grammar.y"
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
#line 70 "y.tab.c"

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
#define TOK_THEN 290
#define TOK_OR 291
#define TOK_AND 292
#define TOK_BOR 293
#define TOK_BXOR 294
#define TOK_BAND 295
#define TOK_SRL 296
#define TOK_SRA 297
#define TOK_SLL 298
#define TOK_NOT 299
#define TOK_BNOT 300
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,   14,   14,   15,   15,    1,    3,    3,    3,
    4,    4,    5,    5,    6,    7,    7,    8,    8,    9,
    9,    9,    9,    9,    9,    9,    9,    9,   10,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   12,   12,   13,
   13,    2,
};
static const YYINT yylen[] = {                            2,
    2,    1,    1,    0,    1,    2,    3,    1,    1,    1,
    1,    3,    1,    3,    5,    1,    0,    1,    2,    2,
    7,    5,    5,    9,    7,    1,    1,    5,    4,    3,
    3,    3,    3,    3,    3,    3,    2,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    2,
    2,    3,    3,    1,    1,    1,    1,    3,    1,    1,
    1,    1,
};
static const YYINT yydefred[] = {                         0,
   10,    8,    9,    0,    5,    0,    2,    0,   62,    0,
    0,   11,    6,    1,    0,    0,    7,    0,   54,   55,
   56,    0,    0,    0,    0,    0,    0,    0,    0,   12,
   37,    0,   50,   51,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   15,   52,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   30,   31,   34,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   27,    0,    0,    0,   18,   26,
    0,    0,    0,    0,    0,    0,   29,   19,   20,    0,
    0,    0,   61,   60,    0,   59,    0,    0,    0,    0,
    0,    0,    0,    0,   23,    0,   58,   28,    0,    0,
    0,    0,   21,    0,   25,    0,   24,
};
static const YYINT yydgoto[] = {                          4,
    5,   26,    6,   11,   12,    7,   87,   88,   89,   90,
   91,  105,  106,   79,    8,
};
static const YYINT yysindex[] = {                      -245,
    0,    0,    0,    0,    0, -252,    0, -245,    0, -266,
 -207,    0,    0,    0, -128, -268,    0, -252,    0,    0,
    0, -128, -128, -128, -128, -250,  189, -234, -213,    0,
    0,  -43,    0,    0, -128, -128, -128, -128, -128, -128,
 -128, -128, -128, -128, -128, -128, -128, -128, -128, -128,
 -128, -128, -128, -128, -245,    0,    0,  189, -102, -102,
 -102, -102,  454,  454, -274, -274,    0,    0,    0,  276,
  287,  403,  414,  443,  -91,  -91,  -91, -252, -116, -245,
 -220, -218, -215, -212,    0, -116, -204, -116,    0,    0,
  -14, -128, -128, -128, -247, -180,    0,    0,    0,   15,
   44,   73,    0,    0, -201,    0, -175, -116, -116, -128,
 -247, -178, -128, -163,    0,  102,    0,    0,  131, -116,
 -128, -171,    0,  160,    0, -116,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -182,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -72, -155,    0, -182,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -219,    0,    0, -228,  472,  498,
  524,  550,  555,  577,  218,  247,    0,    0,    0, -186,
  243,  214, -232,  311,  316,  345,  374,    0, -167, -174,
    0,    0,    0,    0,    0,    0,    0, -158,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -145,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   -7,   -4,   -9,    0,  106,  122,    0,    0,   71,  108,
  -15,    0,   27,    0,   85,
};
#define YYTABLESIZE 872
static const YYINT yytable[] = {                         27,
   13,   10,   15,   44,   45,   46,   31,   32,   33,   34,
    9,    1,    2,   29,    3,    9,   28,   16,   35,   58,
   59,   60,   61,   62,   63,   64,   65,   66,   67,   68,
   69,   70,   71,   72,   73,   74,   75,   76,   77,    4,
  103,    4,    4,    4,    4,   78,    4,    4,    4,   46,
   46,   55,   46,   53,   53,   15,   53,    4,   46,   46,
   46,   46,    4,   92,    4,   93,    4,    4,   94,    4,
   78,   95,   13,   29,   17,   18,  100,  101,  102,    4,
    4,  111,   97,  112,    3,  107,    3,    3,    3,    3,
  104,    3,    3,    3,  116,   43,   43,  119,   43,   13,
   13,  120,    3,  118,   43,  124,  104,    3,  113,    3,
  125,    3,    3,   22,    3,   22,   22,   22,   22,   17,
   22,   22,   22,   30,    3,    3,   14,   14,   16,   14,
   19,   22,   20,   21,    9,   56,   22,  117,   22,   80,
   22,   22,   19,   22,   20,   21,    9,   81,   22,   82,
   83,   84,    0,   22,   22,   23,   96,    0,   98,    0,
   22,    0,    0,    0,    0,   85,    0,   23,    0,   55,
   24,   25,   86,   42,   43,   44,   45,   46,  114,  115,
    0,    0,   24,   25,   42,   43,   44,   45,   46,    0,
  123,    0,    0,   52,   53,   54,  127,   57,   57,   57,
   57,   57,   57,   57,   57,   57,   57,   57,    0,   57,
   57,    0,   57,    0,    0,    0,    0,    0,   57,   57,
   57,   57,   57,   57,   57,   57,   36,   37,   38,   39,
   40,   41,   42,   43,   44,   45,   46,    0,    0,    0,
    0,   57,    0,    0,    0,    0,    0,   47,   48,   49,
   50,   51,   52,   53,   54,   36,   37,   38,   39,   40,
   41,   42,   43,   44,   45,   46,    0,   99,    0,    0,
    0,    0,    0,    0,    0,    0,   47,   48,   49,   50,
   51,   52,   53,   54,   36,   37,   38,   39,   40,   41,
   42,   43,   44,   45,   46,    0,    0,    0,    0,  108,
    0,    0,    0,    0,    0,   47,   48,   49,   50,   51,
   52,   53,   54,   36,   37,   38,   39,   40,   41,   42,
   43,   44,   45,   46,    0,    0,    0,    0,  109,    0,
    0,    0,    0,    0,   47,   48,   49,   50,   51,   52,
   53,   54,   36,   37,   38,   39,   40,   41,   42,   43,
   44,   45,   46,    0,  110,    0,    0,    0,    0,    0,
    0,    0,    0,   47,   48,   49,   50,   51,   52,   53,
   54,   36,   37,   38,   39,   40,   41,   42,   43,   44,
   45,   46,    0,  121,    0,    0,    0,    0,    0,    0,
    0,    0,   47,   48,   49,   50,   51,   52,   53,   54,
   36,   37,   38,   39,   40,   41,   42,   43,   44,   45,
   46,    0,    0,    0,    0,  122,    0,    0,    0,    0,
    0,   47,   48,   49,   50,   51,   52,   53,   54,   36,
   37,   38,   39,   40,   41,   42,   43,   44,   45,   46,
    0,    0,    0,    0,  126,    0,    0,    0,    0,    0,
   47,   48,   49,   50,   51,   52,   53,   54,   36,   37,
   38,   39,   40,   41,   42,   43,   44,   45,   46,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   47,
   48,   49,   50,   51,   52,   53,   54,   32,   32,   32,
   32,   32,   32,   32,   32,   45,   45,    0,   45,   32,
   32,    0,   32,    0,   45,   45,   45,    0,   32,   32,
   32,   32,   32,   32,   32,   32,   33,   33,   33,   33,
   33,   33,   33,   33,   42,   42,    0,   42,   33,   33,
    0,   33,    0,   42,   42,    0,    0,   33,   33,   33,
   33,   33,   33,   33,   33,   36,   37,   38,   39,   40,
   41,   42,   43,   44,   45,   46,   36,   37,   38,   39,
   40,   41,   42,   43,   44,   45,   46,   48,   49,   50,
   51,   52,   53,   54,    0,    0,    0,    0,    0,   49,
   50,   51,   52,   53,   54,   47,   47,   47,   47,   47,
   47,    0,   44,   44,    0,   44,    0,   47,   47,    0,
   47,   44,   44,   44,   44,   44,   47,   47,   47,   47,
   47,   47,   47,   47,   48,   48,   48,   48,   48,   48,
    0,    0,    0,    0,    0,    0,   48,   48,    0,   48,
    0,    0,    0,    0,    0,   48,   48,   48,   48,   48,
   48,   48,   48,   49,   49,   49,   49,   49,   49,    0,
    0,    0,    0,    0,    0,   49,   49,    0,   49,    0,
    0,    0,    0,    0,   49,   49,   49,   49,   49,   49,
   49,   49,   36,   37,   38,   39,   40,   41,   42,   43,
   44,   45,   46,   36,   37,   38,   39,   40,   41,   42,
   43,   44,   45,   46,    0,    0,   50,   51,   52,   53,
   54,    0,    0,    0,    0,    0,    0,    0,   51,   52,
   53,   54,   36,   37,   38,   39,   40,   41,   42,   43,
   44,   45,   46,   36,   37,   38,   39,    0,    0,   42,
   43,   44,   45,   46,    0,    0,    0,    0,   52,   53,
   54,   38,   38,   38,   38,   38,   38,    0,    0,   52,
   53,   54,    0,   38,   38,    0,   38,    0,    0,    0,
    0,    0,   38,   38,   38,   38,   38,   39,   39,   39,
   39,   39,   39,    0,    0,    0,    0,    0,    0,   39,
   39,    0,   39,    0,    0,    0,    0,    0,   39,   39,
   39,   39,   39,   36,   36,   36,   36,   36,   36,    0,
    0,    0,    0,    0,    0,   36,   36,    0,   36,    0,
    0,    0,    0,    0,   36,   36,   36,   36,   36,   35,
   35,   35,   35,   35,   35,    0,    0,    0,   40,   40,
    0,   35,   35,    0,   35,    0,   40,   40,    0,   40,
   35,   35,   35,   35,   35,   40,   40,   40,   40,   40,
   41,   41,    0,    0,    0,    0,    0,    0,   41,   41,
    0,   41,    0,    0,    0,    0,    0,   41,   41,   41,
   41,   41,
};
static const YYINT yycheck[] = {                         15,
    8,    6,  269,  278,  279,  280,   22,   23,   24,   25,
  263,  257,  258,   18,  260,  263,  285,  284,  269,   35,
   36,   37,   38,   39,   40,   41,   42,   43,   44,   45,
   46,   47,   48,   49,   50,   51,   52,   53,   54,  259,
  288,  261,  262,  263,  264,   55,  266,  267,  268,  282,
  283,  286,  285,  282,  283,  269,  285,  277,  291,  292,
  293,  294,  282,  284,  284,  284,  286,  287,  284,  289,
   80,  284,   80,   78,  282,  283,   92,   93,   94,  299,
  300,  283,  287,  285,  259,  266,  261,  262,  263,  264,
   95,  266,  267,  268,  110,  282,  283,  113,  285,  282,
  283,  265,  277,  282,  291,  121,  111,  282,  284,  284,
  282,  286,  287,  259,  289,  261,  262,  263,  264,  287,
  266,  267,  268,   18,  299,  300,  282,  283,  287,    8,
  259,  277,  261,  262,  263,   28,  282,  111,  284,   55,
  286,  287,  259,  289,  261,  262,  263,  264,  277,  266,
  267,  268,   -1,  299,  300,  284,   86,   -1,   88,   -1,
  277,   -1,   -1,   -1,   -1,  282,   -1,  284,   -1,  286,
  299,  300,  289,  276,  277,  278,  279,  280,  108,  109,
   -1,   -1,  299,  300,  276,  277,  278,  279,  280,   -1,
  120,   -1,   -1,  296,  297,  298,  126,  270,  271,  272,
  273,  274,  275,  276,  277,  278,  279,  280,   -1,  282,
  283,   -1,  285,   -1,   -1,   -1,   -1,   -1,  291,  292,
  293,  294,  295,  296,  297,  298,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  280,   -1,   -1,   -1,
   -1,  285,   -1,   -1,   -1,   -1,   -1,  291,  292,  293,
  294,  295,  296,  297,  298,  270,  271,  272,  273,  274,
  275,  276,  277,  278,  279,  280,   -1,  282,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  291,  292,  293,  294,
  295,  296,  297,  298,  270,  271,  272,  273,  274,  275,
  276,  277,  278,  279,  280,   -1,   -1,   -1,   -1,  285,
   -1,   -1,   -1,   -1,   -1,  291,  292,  293,  294,  295,
  296,  297,  298,  270,  271,  272,  273,  274,  275,  276,
  277,  278,  279,  280,   -1,   -1,   -1,   -1,  285,   -1,
   -1,   -1,   -1,   -1,  291,  292,  293,  294,  295,  296,
  297,  298,  270,  271,  272,  273,  274,  275,  276,  277,
  278,  279,  280,   -1,  282,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  291,  292,  293,  294,  295,  296,  297,
  298,  270,  271,  272,  273,  274,  275,  276,  277,  278,
  279,  280,   -1,  282,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  291,  292,  293,  294,  295,  296,  297,  298,
  270,  271,  272,  273,  274,  275,  276,  277,  278,  279,
  280,   -1,   -1,   -1,   -1,  285,   -1,   -1,   -1,   -1,
   -1,  291,  292,  293,  294,  295,  296,  297,  298,  270,
  271,  272,  273,  274,  275,  276,  277,  278,  279,  280,
   -1,   -1,   -1,   -1,  285,   -1,   -1,   -1,   -1,   -1,
  291,  292,  293,  294,  295,  296,  297,  298,  270,  271,
  272,  273,  274,  275,  276,  277,  278,  279,  280,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  291,
  292,  293,  294,  295,  296,  297,  298,  270,  271,  272,
  273,  274,  275,  276,  277,  282,  283,   -1,  285,  282,
  283,   -1,  285,   -1,  291,  292,  293,   -1,  291,  292,
  293,  294,  295,  296,  297,  298,  270,  271,  272,  273,
  274,  275,  276,  277,  282,  283,   -1,  285,  282,  283,
   -1,  285,   -1,  291,  292,   -1,   -1,  291,  292,  293,
  294,  295,  296,  297,  298,  270,  271,  272,  273,  274,
  275,  276,  277,  278,  279,  280,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  280,  292,  293,  294,
  295,  296,  297,  298,   -1,   -1,   -1,   -1,   -1,  293,
  294,  295,  296,  297,  298,  270,  271,  272,  273,  274,
  275,   -1,  282,  283,   -1,  285,   -1,  282,  283,   -1,
  285,  291,  292,  293,  294,  295,  291,  292,  293,  294,
  295,  296,  297,  298,  270,  271,  272,  273,  274,  275,
   -1,   -1,   -1,   -1,   -1,   -1,  282,  283,   -1,  285,
   -1,   -1,   -1,   -1,   -1,  291,  292,  293,  294,  295,
  296,  297,  298,  270,  271,  272,  273,  274,  275,   -1,
   -1,   -1,   -1,   -1,   -1,  282,  283,   -1,  285,   -1,
   -1,   -1,   -1,   -1,  291,  292,  293,  294,  295,  296,
  297,  298,  270,  271,  272,  273,  274,  275,  276,  277,
  278,  279,  280,  270,  271,  272,  273,  274,  275,  276,
  277,  278,  279,  280,   -1,   -1,  294,  295,  296,  297,
  298,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  295,  296,
  297,  298,  270,  271,  272,  273,  274,  275,  276,  277,
  278,  279,  280,  270,  271,  272,  273,   -1,   -1,  276,
  277,  278,  279,  280,   -1,   -1,   -1,   -1,  296,  297,
  298,  270,  271,  272,  273,  274,  275,   -1,   -1,  296,
  297,  298,   -1,  282,  283,   -1,  285,   -1,   -1,   -1,
   -1,   -1,  291,  292,  293,  294,  295,  270,  271,  272,
  273,  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,  282,
  283,   -1,  285,   -1,   -1,   -1,   -1,   -1,  291,  292,
  293,  294,  295,  270,  271,  272,  273,  274,  275,   -1,
   -1,   -1,   -1,   -1,   -1,  282,  283,   -1,  285,   -1,
   -1,   -1,   -1,   -1,  291,  292,  293,  294,  295,  270,
  271,  272,  273,  274,  275,   -1,   -1,   -1,  274,  275,
   -1,  282,  283,   -1,  285,   -1,  282,  283,   -1,  285,
  291,  292,  293,  294,  295,  291,  292,  293,  294,  295,
  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,  282,  283,
   -1,  285,   -1,   -1,   -1,   -1,   -1,  291,  292,  293,
  294,  295,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 300
#define YYUNDFTOKEN 318
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
"TOK_STRING","TOK_DO","TOK_THEN","TOK_OR","TOK_AND","TOK_BOR","TOK_BXOR",
"TOK_BAND","TOK_SRL","TOK_SRA","TOK_SLL","TOK_NOT","TOK_BNOT",0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"illegal-symbol",
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
"expr : TOK_TRUE",
"expr : TOK_FALSE",
"expr : ident",
"listparamprint : listparamprint TOK_COMMA paramprint",
"listparamprint : paramprint",
"paramprint : ident",
"paramprint : TOK_STRING",
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
#line 432 "grammar.y"
/* A completer et/ou remplacer avec d'autres fonctions */

node_t make_node(node_nature nature, int nops, ...) {
	couleur("30"); printf("NODE CREE\n");
    couleur("0"); printf("make_node 1");
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
    retour->opr= (node_s**)malloc(sizeof(node_s*)*nops);
	/*for(int i = 0; i < nops; i++)
	{
		hop[i] = (node_s*)malloc(sizeof(node_s));
	}*/
				printf("make_node 6\n");
				//printf("nops=%d\n",nops);

    for (int i = 0; i < nops; i++)
    {
				printf("make_node for 1\n");
        if(va_arg(ap, node_t) == NULL)
        {
				printf("make_node for if\n");
            continue;
        }
				printf("make_node for 2\n");
			//printf("arg supp n°%d = %d\n ", i+1 , va_arg(ap, node_t));
				printf("make_node for 3\n");
                printf("enfant n° %d est %s\n" ,i,va_arg(ap,node_t) );
        retour->opr[i] = va_arg(ap,node_t);
    }
				printf("make_node for 4\n");
			//printf("hop affecté! contient %d\n" , retour->opr[i]);

				printf("make_node 7\n");
    //retour->opr = hop;
				printf("make_node 8\n");
    // recherche des arguments supplementaires en fonction de la nature du noeud
    switch(nature)
    {
        case NODE_IDENT ://   type =  TYPE_NONE,TYPE_INT,TYPE_BOOL,TYPE_STRING,TYPE_VOID

				printf("make_node node_ident 1\n");
            retour->type      =va_arg(ap,node_type); // argument supp à la position nops + 1 = type de noeud
				printf("make_node node_ident 2\n");
            retour->decl_node =va_arg(ap,node_t); // argument supp à la position nops + 2 = declaration de noeud
				printf("make_node node_ident 3\n");
            retour->offset    =va_arg(ap,int32_t ); // argument supp à la position nops + 3 = declaration de l'emplacement mémoire de la variable int32_t
				printf("make_node node_ident 4\n");
            retour->global_decl=va_arg(ap,int); // argument supp à la position nops + 4 = declaration globale?
				printf("make_node node_ident 5\n");
            break;
        case NODE_AFFECT :
            retour->type      =va_arg(ap,node_type); // argument supp à la position nops + 1 = type de noeud
            break;
        case NODE_FUNC :
            retour->offset    =va_arg(ap,int32_t); // argument supp à la position nops + 1 = declaration de l'emplacement mémoire de la variable
            retour->stack_size=va_arg(ap,int32_t); // argument supp à la position nops + 2 = declaration de
            break;
        case NODE_TYPE:
				printf("make_node node_type 1\n");
            retour->type = va_arg(ap,node_type);
				printf("make_node node_type 2\n");
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

				printf("make_node 20\n");
    va_end(ap);
				printf("make_node 21\n");
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
#line 652 "y.tab.c"

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
#line 95 "grammar.y"
	{
            printf("program : liste non nulle et main\n");
            yyval.ptr = make_node(NODE_PROGRAM, 2, yystack.l_mark[-1].ptr, yystack.l_mark[0].ptr);
			couleur("34"); printf("NODE_PROGRAM\n");couleur("0");
            /**program_root = $$;*/

        }
break;
case 2:
#line 103 "grammar.y"
	{
            printf("program : main\n");
            yyval.ptr = make_node(NODE_PROGRAM, 2, NULL, yystack.l_mark[0].ptr);
			couleur("34"); printf("NODE_PROGRAM\n");couleur("0");
            /**program_root = $$;*/

        }
break;
case 3:
#line 112 "grammar.y"
	{
            printf("listdecl : listdeclnonnull\n");
            yyval.ptr = yystack.l_mark[0].ptr;/*make_node(NODE_LIST, 1, $1 );*/
			couleur("34"); printf("NODE_LIST\n");("0");
            /**program_root = $$;*/

        }
break;
case 4:
#line 120 "grammar.y"
	{ printf("listdecl : epsilon");yyval.ptr = NULL; }
break;
case 5:
#line 123 "grammar.y"
	{
                printf("listdecl non nulle : vardecl\n");
				yyval.ptr = make_node(NODE_LIST, 1, yystack.l_mark[0].ptr);
                couleur("34"); printf("NODE_LIST\n");couleur("0");
            	/**program_root = $$;*/
			}
break;
case 6:
#line 130 "grammar.y"
	{
                printf("listdecl non nulle : list + vardecl\n");
				make_node(NODE_LIST, 2, yystack.l_mark[-1].ptr, yystack.l_mark[0].ptr);
                couleur("34"); printf("NODE_LIST\n");couleur("0");
            	/**program_root = $$;*/
			}
break;
case 7:
#line 138 "grammar.y"
	{
                printf("vardecl\n");
				yyval.ptr = make_node(NODE_DECLS, 2, yystack.l_mark[-2].ptr, yystack.l_mark[-1].ptr);
                couleur("34"); printf("NODE_LIST\n");couleur("0");
            	/**program_root = $$;*/
			}
break;
case 8:
#line 146 "grammar.y"
	{
            printf("type : TOK_INT\n");
			yyval.ptr = make_node(NODE_TYPE, 0, TYPE_INT);
        	couleur("34"); printf("NODE_TYPE\n");couleur("0");/**program_root = $$;*/
		}
break;
case 9:
#line 152 "grammar.y"
	{
            printf("type : TOK_BOOL\n");
			yyval.ptr = make_node(NODE_TYPE, 0, TYPE_BOOL);
			couleur("34"); printf("NODE_TYPE\n");couleur("0");/**program_root = $$;*/
		}
break;
case 10:
#line 158 "grammar.y"
	{
            printf("type : TOK_VOID\n");
			yyval.ptr = make_node(NODE_TYPE, 0, TYPE_VOID);
			couleur("34"); printf("NODE_TYPE\n");couleur("0");/**program_root = $$;*/
		}
break;
case 11:
#line 165 "grammar.y"
	{
                    printf("listtypedecl : decl\n");
					yyval.ptr = yystack.l_mark[0].ptr;/*make_node(NODE_LIST, 1 ,$1);*/
					/*printf("listtypedecl : decl bis\n");*/
                	couleur("34"); printf(" go decl\n");couleur("0");/**program_root = $$;*/
				}
break;
case 12:
#line 172 "grammar.y"
	{
                    printf("listtypedecl : listtypedecl, decl\n");
					yyval.ptr = make_node(NODE_LIST, 2 , yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
                	couleur("34"); printf("NODE_LIST\n");couleur("0");/**program_root = $$;*/
				}
break;
case 13:
#line 179 "grammar.y"
	{
            printf("decl : ident\n");
	   		yyval.ptr = make_node(NODE_DECL, 2, yystack.l_mark[0].ptr, NULL );
       		couleur("34"); printf("NODE_DECL\n");couleur("0");/**program_root = $$;*/
			printf("decl : ident bis\n");
		}
break;
case 14:
#line 186 "grammar.y"
	{
			printf("decl : ident TOK_AFFECT expr\n");
			yyval.ptr = make_node(NODE_DECL, 2 ,yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
       		couleur("34"); printf("NODE_DECL\n");couleur("0");/**program_root = $$;*/
		}
break;
case 15:
#line 194 "grammar.y"
	{
                couleur("34"); printf("NODE_FUNC\n");couleur("0");/**program_root = $$;*/
				yyval.ptr = make_node(NODE_FUNC, 3, yystack.l_mark[-4].ptr, yystack.l_mark[-3].ptr, yystack.l_mark[0].ptr, 35, 4);

			}
break;
case 16:
#line 201 "grammar.y"
	{
				yyval.ptr = yystack.l_mark[0].ptr;/*make_node(NODE_LIST, 1, $1);*/
            	couleur("34"); printf("NODE_LIST\n");couleur("0");/**program_root = $$;*/
			}
break;
case 17:
#line 206 "grammar.y"
	{
				yyval.ptr = NULL;
			}
break;
case 18:
#line 210 "grammar.y"
	{
					yyval.ptr = yystack.l_mark[0].ptr;/*$$ = make_node(NODE_LIST, 1, $1);*/
                	couleur("34"); printf("NODE_LIST\n");couleur("0");/**program_root = $$;*/
				}
break;
case 19:
#line 215 "grammar.y"
	{
					yyval.ptr = make_node(NODE_LIST, 2, yystack.l_mark[-1].ptr, yystack.l_mark[0].ptr);
                	couleur("34"); printf("NODE_LIST\n");couleur("0");/**program_root = $$;*/
				}
break;
case 20:
#line 221 "grammar.y"
	{
			yyval.ptr = yystack.l_mark[-1].ptr;
        	couleur("34"); printf("semicol\n");couleur("0");/**program_root = $$;*/
		}
break;
case 21:
#line 226 "grammar.y"
	{
			yyval.ptr = make_node(NODE_IF, 3, yystack.l_mark[-4].ptr, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
			couleur("34"); printf("NODE_IF\n");couleur("0");/**program_root = $$;*/
		}
break;
case 22:
#line 231 "grammar.y"
	{
			yyval.ptr = make_node(NODE_IF, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	couleur("34"); printf("NODE_IF\n");couleur("0");/**program_root = $$;*/
		}
break;
case 23:
#line 236 "grammar.y"
	{
			yyval.ptr = make_node(NODE_WHILE, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	couleur("34"); printf("NODE_WHILE\n");couleur("0");/**program_root = $$;*/
		}
break;
case 24:
#line 241 "grammar.y"
	{
			yyval.ptr = make_node(NODE_FOR, 4, yystack.l_mark[-6].ptr ,yystack.l_mark[-4].ptr, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	couleur("34"); printf("NODE_FOR\n");couleur("0");/**program_root = $$;*/
		}
break;
case 25:
#line 246 "grammar.y"
	{
			yyval.ptr = make_node(NODE_DOWHILE, 2, yystack.l_mark[-5].ptr, yystack.l_mark[-2].ptr);
        	couleur("34"); printf("NODE_DOWHILE\n");couleur("0");/**program_root = $$;*/
		}
break;
case 26:
#line 251 "grammar.y"
	{
			yyval.ptr = yystack.l_mark[0].ptr;
        	/**program_root = $$;*/
		}
break;
case 27:
#line 256 "grammar.y"
	{
			yyval.ptr = NULL;
		}
break;
case 28:
#line 260 "grammar.y"
	{
			yyval.ptr = make_node(NODE_PRINT, 1, yystack.l_mark[-2].ptr);
        	couleur("34"); printf("NODE_PRINT\n");couleur("0");/**program_root = $$;*/
		}
break;
case 29:
#line 266 "grammar.y"
	{
			yyval.ptr = make_node(NODE_BLOCK, 2, yystack.l_mark[-2].ptr, yystack.l_mark[-1].ptr);
        	couleur("34"); printf("NODE_BLOCK\n");couleur("0");/**program_root = $$;*/
		}
break;
case 30:
#line 272 "grammar.y"
	{
			yyval.ptr = make_node(NODE_MUL, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	couleur("34"); printf("NODE_MUL\n");couleur("0");/**program_root = $$;*/
		}
break;
case 31:
#line 277 "grammar.y"
	{
			yyval.ptr = make_node(NODE_DIV, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	couleur("34"); printf("NODE_DIV\n");couleur("0");/**program_root = $$;*/
		}
break;
case 32:
#line 282 "grammar.y"
	{
			yyval.ptr = make_node(NODE_PLUS, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	couleur("34"); printf("NODE_PLUS\n");couleur("0");/**program_root = $$;*/
		}
break;
case 33:
#line 287 "grammar.y"
	{
			yyval.ptr = make_node(NODE_MINUS, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	couleur("34"); printf("NODE_MINUS\n");couleur("0");/**program_root = $$;*/
		}
break;
case 34:
#line 292 "grammar.y"
	{
			yyval.ptr = make_node(NODE_MOD, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	couleur("34"); printf("NODE_MOD\n");couleur("0");/**program_root = $$;*/
		}
break;
case 35:
#line 297 "grammar.y"
	{
			yyval.ptr = make_node(NODE_LT, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	couleur("34"); printf("NODE_LT\n");couleur("0");/**program_root = $$;*/
		}
break;
case 36:
#line 302 "grammar.y"
	{
			yyval.ptr = make_node(NODE_GT, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	couleur("34"); printf("NODE_GT\n");couleur("0");/**program_root = $$;*/
		}
break;
case 37:
#line 307 "grammar.y"
	{
			yyval.ptr = make_node(NODE_UMINUS, 1, yystack.l_mark[0].ptr);
        	couleur("34"); printf("NODE_UMINUS\n");couleur("0");/**program_root = $$;*/
		}
break;
case 38:
#line 312 "grammar.y"
	{
			yyval.ptr = make_node(NODE_GE, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	couleur("34"); printf("NODE_GE\n");couleur("0");/**program_root = $$;*/
		}
break;
case 39:
#line 317 "grammar.y"
	{
			yyval.ptr = make_node(NODE_LE, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 40:
#line 321 "grammar.y"
	{
			yyval.ptr = make_node(NODE_EQ, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 41:
#line 325 "grammar.y"
	{
			yyval.ptr = make_node(NODE_NE, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 42:
#line 329 "grammar.y"
	{
			yyval.ptr = make_node(NODE_AND, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 43:
#line 333 "grammar.y"
	{
			yyval.ptr = make_node(NODE_OR, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 44:
#line 337 "grammar.y"
	{
			yyval.ptr = make_node(NODE_BAND, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 45:
#line 341 "grammar.y"
	{
			yyval.ptr = make_node(NODE_BOR, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 46:
#line 345 "grammar.y"
	{
			yyval.ptr = make_node(NODE_BXOR, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 47:
#line 349 "grammar.y"
	{
			yyval.ptr = make_node(NODE_SRL, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 48:
#line 353 "grammar.y"
	{
			yyval.ptr = make_node(NODE_SRA, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 49:
#line 357 "grammar.y"
	{
			yyval.ptr = make_node(NODE_SLL, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 50:
#line 361 "grammar.y"
	{
			yyval.ptr = make_node(NODE_NOT, 1, yystack.l_mark[0].ptr);
		}
break;
case 51:
#line 365 "grammar.y"
	{
			yyval.ptr = make_node(NODE_BNOT, 1, yystack.l_mark[0].ptr);
		}
break;
case 52:
#line 369 "grammar.y"
	{
			printf("expr : TOK_LPAR expr TOK_RPAR\n");
			/*$$ = make_node(NODE_, 2, $1, $3)*/
		}
break;
case 53:
#line 374 "grammar.y"
	{
			printf("expr : ident TOK_AFFECT expr\n");
			yyval.ptr = make_node(NODE_AFFECT, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 54:
#line 379 "grammar.y"
	{
			printf("expr : TOK_INTVAL\n");
			yyval.ptr = make_node(NODE_AFFECT, 0);
		}
break;
case 55:
#line 384 "grammar.y"
	{
			printf("expr : TOK_TRUE\n");
			yyval.ptr = NULL;
		}
break;
case 56:
#line 389 "grammar.y"
	{
			printf("expr : TOK_FALSE\n");
			yyval.ptr = NULL;
		}
break;
case 57:
#line 394 "grammar.y"
	{
			printf("expr : ident\n");
			yyval.ptr = yystack.l_mark[0].ptr;
		}
break;
case 58:
#line 401 "grammar.y"
	{
					yyval.ptr = make_node(NODE_LIST, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr); /* a verifier*/
					couleur("34"); printf("NODE_PRINT\n");couleur("0");/**program_root = $$;*/
				}
break;
case 59:
#line 406 "grammar.y"
	{
					yyval.ptr = yystack.l_mark[0].ptr;
				}
break;
case 60:
#line 412 "grammar.y"
	{
				yyval.ptr = yystack.l_mark[0].ptr;
			}
break;
case 61:
#line 416 "grammar.y"
	{
				yyval.ptr = make_node(NODE_PRINT, 1, yystack.l_mark[0].strval);
				couleur("34"); printf("NODE_PRINT\n");couleur("0");/**program_root = $$;*/
			}
break;
case 62:
#line 423 "grammar.y"
	{
			printf("ident : TOK_IDENT\n");
			yyval.ptr = make_node(NODE_IDENT, 0);
			couleur("34"); printf("NODE_IDENT\n");couleur("0");/**program_root = $$;*/
		}
break;
#line 1294 "y.tab.c"
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
