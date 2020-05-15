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
#define TOK_STRINGVAL 301
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
   57,    0,    0,    0,    0,   58,    0,    0,    0,    0,
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
static const YYINT yysindex[] = {                      -245,
    0,    0,    0,    0,    0, -252,    0, -245,    0, -266,
 -277,    0,    0,    0,  -86, -269,    0, -252,    0,    0,
    0,  -86,  -86,  -86,  -86,    0, -216,  207, -229, -204,
    0,    0,  -25,    0,    0,  -86,  -86,  -86,  -86,  -86,
  -86,  -86,  -86,  -86,  -86,  -86,  -86,  -86,  -86,  -86,
  -86,  -86,  -86,  -86,  -86, -245,    0,    0,  207,  317,
  317,  317,  317,  472,  472, -177, -177,    0,    0,    0,
  294,  305,  421,  432,  461,  -68,  -68,  -68, -252, -115,
 -245, -267, -217, -214, -211,    0, -115, -203, -115,    0,
    0,    4,  -86,  -86,  -86, -259, -161,    0,    0,    0,
   33,   62,   91,    0,    0, -198,    0, -174, -115, -115,
  -86, -259, -170,  -86, -140,    0,  120,    0,    0,  149,
 -115,  -86, -153,    0,  178,    0, -115,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -263,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -54, -206,    0, -263,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -218,    0,    0, -227,  490,
  516,  542,  568,  573,  595,  236,  265,    0,    0,    0,
 -185,  261,  232, -231,  -88,  334,  363,  392,    0, -166,
 -173,    0,    0,    0,    0,    0,    0,    0, -157,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -144,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   -7,   -4,   -9,    0,  113,  124,    0,    0,   72,  105,
  -15,    0,   23,    0,   80,
};
#define YYTABLESIZE 890
static const YYINT yytable[] = {                         28,
   13,   10,   15,    9,   17,   18,   32,   33,   34,   35,
    9,    1,    2,   30,    3,   29,   93,   16,   13,   13,
   59,   60,   61,   62,   63,   64,   65,   66,   67,   68,
   69,   70,   71,   72,   73,   74,   75,   76,   77,   78,
    4,  104,    4,    4,    4,    4,   79,    4,    4,    4,
   46,   46,   36,   46,   53,   53,   56,   53,    4,   46,
   46,   46,   46,    4,   15,    4,   94,    4,    4,   95,
    4,   79,   96,   13,   30,   14,   14,  101,  102,  103,
    4,    4,    4,   98,  112,    3,  113,    3,    3,    3,
    3,  105,    3,    3,    3,  117,   43,   43,  120,   43,
   45,   46,   47,    3,  108,   43,  125,  105,    3,  114,
    3,  119,    3,    3,   22,    3,   22,   22,   22,   22,
   17,   22,   22,   22,  121,    3,    3,    3,  126,   16,
   31,   14,   22,   57,  118,   81,    0,   22,    0,   22,
    0,   22,   22,   19,   22,   20,   21,    9,   82,    0,
   83,   84,   85,    0,   22,   22,   22,    0,   97,    0,
   99,   22,    0,    0,    0,    0,   86,    0,   23,    0,
   56,    0,   19,   87,   20,   21,    9,    0,    0,    0,
  115,  116,    0,   24,   25,   26,    0,    0,    0,    0,
   22,    0,  124,   44,   44,    0,   44,   23,  128,    0,
    0,    0,   44,   44,   44,   44,   44,   43,   44,   45,
   46,   47,   24,   25,   26,   55,   55,   55,   55,   55,
   55,   55,   55,   55,   55,   55,    0,   55,   55,    0,
   55,    0,    0,    0,    0,    0,   55,   55,   55,   55,
   55,   55,   55,   55,   37,   38,   39,   40,   41,   42,
   43,   44,   45,   46,   47,    0,    0,    0,    0,   58,
    0,    0,    0,    0,    0,   48,   49,   50,   51,   52,
   53,   54,   55,   37,   38,   39,   40,   41,   42,   43,
   44,   45,   46,   47,    0,  100,    0,    0,    0,    0,
    0,    0,    0,    0,   48,   49,   50,   51,   52,   53,
   54,   55,   37,   38,   39,   40,   41,   42,   43,   44,
   45,   46,   47,    0,    0,    0,    0,  109,    0,    0,
    0,    0,    0,   48,   49,   50,   51,   52,   53,   54,
   55,   37,   38,   39,   40,   41,   42,   43,   44,   45,
   46,   47,    0,    0,    0,    0,  110,    0,    0,    0,
    0,    0,   48,   49,   50,   51,   52,   53,   54,   55,
   37,   38,   39,   40,   41,   42,   43,   44,   45,   46,
   47,    0,  111,    0,    0,    0,    0,    0,    0,    0,
    0,   48,   49,   50,   51,   52,   53,   54,   55,   37,
   38,   39,   40,   41,   42,   43,   44,   45,   46,   47,
    0,  122,    0,    0,    0,    0,    0,    0,    0,    0,
   48,   49,   50,   51,   52,   53,   54,   55,   37,   38,
   39,   40,   41,   42,   43,   44,   45,   46,   47,    0,
    0,    0,    0,  123,    0,    0,    0,    0,    0,   48,
   49,   50,   51,   52,   53,   54,   55,   37,   38,   39,
   40,   41,   42,   43,   44,   45,   46,   47,    0,    0,
    0,    0,  127,    0,    0,    0,    0,    0,   48,   49,
   50,   51,   52,   53,   54,   55,   37,   38,   39,   40,
   41,   42,   43,   44,   45,   46,   47,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   48,   49,   50,
   51,   52,   53,   54,   55,   32,   32,   32,   32,   32,
   32,   32,   32,   45,   45,    0,   45,   32,   32,    0,
   32,    0,   45,   45,   45,    0,   32,   32,   32,   32,
   32,   32,   32,   32,   33,   33,   33,   33,   33,   33,
   33,   33,   42,   42,    0,   42,   33,   33,    0,   33,
    0,   42,   42,    0,    0,   33,   33,   33,   33,   33,
   33,   33,   33,   37,   38,   39,   40,   41,   42,   43,
   44,   45,   46,   47,   37,   38,   39,   40,   41,   42,
   43,   44,   45,   46,   47,   49,   50,   51,   52,   53,
   54,   55,   43,   44,   45,   46,   47,   50,   51,   52,
   53,   54,   55,   47,   47,   47,   47,   47,   47,    0,
    0,    0,   53,   54,   55,   47,   47,    0,   47,    0,
    0,    0,    0,    0,   47,   47,   47,   47,   47,   47,
   47,   47,   48,   48,   48,   48,   48,   48,    0,    0,
    0,    0,    0,    0,   48,   48,    0,   48,    0,    0,
    0,    0,    0,   48,   48,   48,   48,   48,   48,   48,
   48,   49,   49,   49,   49,   49,   49,    0,    0,    0,
    0,    0,    0,   49,   49,    0,   49,    0,    0,    0,
    0,    0,   49,   49,   49,   49,   49,   49,   49,   49,
   37,   38,   39,   40,   41,   42,   43,   44,   45,   46,
   47,   37,   38,   39,   40,   41,   42,   43,   44,   45,
   46,   47,    0,    0,   51,   52,   53,   54,   55,    0,
    0,    0,    0,    0,    0,    0,   52,   53,   54,   55,
   37,   38,   39,   40,   41,   42,   43,   44,   45,   46,
   47,   37,   38,   39,   40,    0,    0,   43,   44,   45,
   46,   47,    0,    0,    0,    0,   53,   54,   55,   38,
   38,   38,   38,   38,   38,    0,    0,   53,   54,   55,
    0,   38,   38,    0,   38,    0,    0,    0,    0,    0,
   38,   38,   38,   38,   38,   39,   39,   39,   39,   39,
   39,    0,    0,    0,    0,    0,    0,   39,   39,    0,
   39,    0,    0,    0,    0,    0,   39,   39,   39,   39,
   39,   36,   36,   36,   36,   36,   36,    0,    0,    0,
    0,    0,    0,   36,   36,    0,   36,    0,    0,    0,
    0,    0,   36,   36,   36,   36,   36,   35,   35,   35,
   35,   35,   35,    0,    0,    0,   40,   40,    0,   35,
   35,    0,   35,    0,   40,   40,    0,   40,   35,   35,
   35,   35,   35,   40,   40,   40,   40,   40,   41,   41,
    0,    0,    0,    0,    0,    0,   41,   41,    0,   41,
    0,    0,    0,    0,    0,   41,   41,   41,   41,   41,
};
static const YYINT yycheck[] = {                         15,
    8,    6,  269,  263,  282,  283,   22,   23,   24,   25,
  263,  257,  258,   18,  260,  285,  284,  284,  282,  283,
   36,   37,   38,   39,   40,   41,   42,   43,   44,   45,
   46,   47,   48,   49,   50,   51,   52,   53,   54,   55,
  259,  301,  261,  262,  263,  264,   56,  266,  267,  268,
  282,  283,  269,  285,  282,  283,  286,  285,  277,  291,
  292,  293,  294,  282,  269,  284,  284,  286,  287,  284,
  289,   81,  284,   81,   79,  282,  283,   93,   94,   95,
  299,  300,  301,  287,  283,  259,  285,  261,  262,  263,
  264,   96,  266,  267,  268,  111,  282,  283,  114,  285,
  278,  279,  280,  277,  266,  291,  122,  112,  282,  284,
  284,  282,  286,  287,  259,  289,  261,  262,  263,  264,
  287,  266,  267,  268,  265,  299,  300,  301,  282,  287,
   18,    8,  277,   29,  112,   56,   -1,  282,   -1,  284,
   -1,  286,  287,  259,  289,  261,  262,  263,  264,   -1,
  266,  267,  268,   -1,  299,  300,  301,   -1,   87,   -1,
   89,  277,   -1,   -1,   -1,   -1,  282,   -1,  284,   -1,
  286,   -1,  259,  289,  261,  262,  263,   -1,   -1,   -1,
  109,  110,   -1,  299,  300,  301,   -1,   -1,   -1,   -1,
  277,   -1,  121,  282,  283,   -1,  285,  284,  127,   -1,
   -1,   -1,  291,  292,  293,  294,  295,  276,  277,  278,
  279,  280,  299,  300,  301,  270,  271,  272,  273,  274,
  275,  276,  277,  278,  279,  280,   -1,  282,  283,   -1,
  285,   -1,   -1,   -1,   -1,   -1,  291,  292,  293,  294,
  295,  296,  297,  298,  270,  271,  272,  273,  274,  275,
  276,  277,  278,  279,  280,   -1,   -1,   -1,   -1,  285,
   -1,   -1,   -1,   -1,   -1,  291,  292,  293,  294,  295,
  296,  297,  298,  270,  271,  272,  273,  274,  275,  276,
  277,  278,  279,  280,   -1,  282,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  291,  292,  293,  294,  295,  296,
  297,  298,  270,  271,  272,  273,  274,  275,  276,  277,
  278,  279,  280,   -1,   -1,   -1,   -1,  285,   -1,   -1,
   -1,   -1,   -1,  291,  292,  293,  294,  295,  296,  297,
  298,  270,  271,  272,  273,  274,  275,  276,  277,  278,
  279,  280,   -1,   -1,   -1,   -1,  285,   -1,   -1,   -1,
   -1,   -1,  291,  292,  293,  294,  295,  296,  297,  298,
  270,  271,  272,  273,  274,  275,  276,  277,  278,  279,
  280,   -1,  282,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  291,  292,  293,  294,  295,  296,  297,  298,  270,
  271,  272,  273,  274,  275,  276,  277,  278,  279,  280,
   -1,  282,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  291,  292,  293,  294,  295,  296,  297,  298,  270,  271,
  272,  273,  274,  275,  276,  277,  278,  279,  280,   -1,
   -1,   -1,   -1,  285,   -1,   -1,   -1,   -1,   -1,  291,
  292,  293,  294,  295,  296,  297,  298,  270,  271,  272,
  273,  274,  275,  276,  277,  278,  279,  280,   -1,   -1,
   -1,   -1,  285,   -1,   -1,   -1,   -1,   -1,  291,  292,
  293,  294,  295,  296,  297,  298,  270,  271,  272,  273,
  274,  275,  276,  277,  278,  279,  280,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  291,  292,  293,
  294,  295,  296,  297,  298,  270,  271,  272,  273,  274,
  275,  276,  277,  282,  283,   -1,  285,  282,  283,   -1,
  285,   -1,  291,  292,  293,   -1,  291,  292,  293,  294,
  295,  296,  297,  298,  270,  271,  272,  273,  274,  275,
  276,  277,  282,  283,   -1,  285,  282,  283,   -1,  285,
   -1,  291,  292,   -1,   -1,  291,  292,  293,  294,  295,
  296,  297,  298,  270,  271,  272,  273,  274,  275,  276,
  277,  278,  279,  280,  270,  271,  272,  273,  274,  275,
  276,  277,  278,  279,  280,  292,  293,  294,  295,  296,
  297,  298,  276,  277,  278,  279,  280,  293,  294,  295,
  296,  297,  298,  270,  271,  272,  273,  274,  275,   -1,
   -1,   -1,  296,  297,  298,  282,  283,   -1,  285,   -1,
   -1,   -1,   -1,   -1,  291,  292,  293,  294,  295,  296,
  297,  298,  270,  271,  272,  273,  274,  275,   -1,   -1,
   -1,   -1,   -1,   -1,  282,  283,   -1,  285,   -1,   -1,
   -1,   -1,   -1,  291,  292,  293,  294,  295,  296,  297,
  298,  270,  271,  272,  273,  274,  275,   -1,   -1,   -1,
   -1,   -1,   -1,  282,  283,   -1,  285,   -1,   -1,   -1,
   -1,   -1,  291,  292,  293,  294,  295,  296,  297,  298,
  270,  271,  272,  273,  274,  275,  276,  277,  278,  279,
  280,  270,  271,  272,  273,  274,  275,  276,  277,  278,
  279,  280,   -1,   -1,  294,  295,  296,  297,  298,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  295,  296,  297,  298,
  270,  271,  272,  273,  274,  275,  276,  277,  278,  279,
  280,  270,  271,  272,  273,   -1,   -1,  276,  277,  278,
  279,  280,   -1,   -1,   -1,   -1,  296,  297,  298,  270,
  271,  272,  273,  274,  275,   -1,   -1,  296,  297,  298,
   -1,  282,  283,   -1,  285,   -1,   -1,   -1,   -1,   -1,
  291,  292,  293,  294,  295,  270,  271,  272,  273,  274,
  275,   -1,   -1,   -1,   -1,   -1,   -1,  282,  283,   -1,
  285,   -1,   -1,   -1,   -1,   -1,  291,  292,  293,  294,
  295,  270,  271,  272,  273,  274,  275,   -1,   -1,   -1,
   -1,   -1,   -1,  282,  283,   -1,  285,   -1,   -1,   -1,
   -1,   -1,  291,  292,  293,  294,  295,  270,  271,  272,
  273,  274,  275,   -1,   -1,   -1,  274,  275,   -1,  282,
  283,   -1,  285,   -1,  282,  283,   -1,  285,  291,  292,
  293,  294,  295,  291,  292,  293,  294,  295,  274,  275,
   -1,   -1,   -1,   -1,   -1,   -1,  282,  283,   -1,  285,
   -1,   -1,   -1,   -1,   -1,  291,  292,  293,  294,  295,
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
"TOK_STRING","TOK_DO","TOK_THEN","TOK_OR","TOK_AND","TOK_BOR","TOK_BXOR",
"TOK_BAND","TOK_SRL","TOK_SRA","TOK_SLL","TOK_NOT","TOK_BNOT","TOK_STRINGVAL",0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
#line 470 "grammar.y"
/* A completer et/ou remplacer avec d'autres fonctions */

node_t make_node(node_nature nature, int32_t nops, ...) {
	couleur("30"); printf("NODE CREE\n");
    couleur("0");
    //cptnodes ++;
    //printf("on make le node n°%d\n", cptnodes);
    va_list ap; /*liste des arguments supplémentaires*/
				//printf("make_node 1\n");
    va_start(ap,nops);
                //printf("make_node 2\n");

    node_t retour = malloc(sizeof(node_t));
				//printf("make_node 3\n");
    //retour->node_num = cptnodes;
	retour->nature = nature;
    printf("node nature : %s \n",node_nature2string(retour->nature));
				//printf("make_node 4\n");
	retour->nops = nops;
    printf("nops vaut %d \n", nops);
	printf("sizeof(retour->nops): %d %d (int32_t)\n", sizeof(retour->nops), sizeof(nops));
				//printf("make_node 5\n");
    //node_t *hop;
    //retour->opr= hop;
	//printf("sizeof(retour->opr): %d %d\n", sizeof(retour->opr), sizeof(hop));
			// !! sizeof(hop) > sizeof(retour->opr)
	/*for(int i = 0; i < nops; i++)
	{
		hop[i] = (node_s*)malloc(sizeof(node_s));
	}*/
				printf("make_node 6\n");
				//printf("nops=%d\n",nops);

    for (int i = 0; i < nops; i++)
    {
				//printf("make_node for 1\n");
        				//printf("make_node for 2\n");
			//printf("arg supp n°%d = %d\n ", i+1 , va_arg(ap, node_t));
				//printf("make_node for 3\n");
            retour->opr[i] = va_arg(ap,node_t);
                //printf("make node for 3 s'est bien passe\n");
    }
				//printf("make_node for 4\n");
			//printf("hop affecté! contient %d\n" , retour->opr[i]);

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
            retour->offset    =8; // argument supp à la position nops + 1 = declaration de l'emplacement mémoire de la variable
            retour->stack_size=8; // argument supp à la position nops + 2 = declaration de
            printf("offset: %d\nstack_size: %d\n",retour->offset,retour->stack_size);
            break;
        case NODE_TYPE:
				printf("make_node node_type 1\n");
                switch(va_arg(ap,node_type)) // print type associé
                {
                    //   type =  TYPE_NONE,TYPE_INT,TYPE_BOOL,TYPE_STRING,TYPE_VOID
                    case TYPE_NONE:
                        printf("TYPE_NONE\n");
                        break;
                    case TYPE_INT:
                        printf("TYPE_INT\n");
                        break;
                    case TYPE_BOOL:
                        printf("TYPE_BOOL\n");
                        break;
                    case TYPE_STRING:
                        printf("TYPE_STRING\n");
                        break;
                    case TYPE_VOID:
                        printf("TYPE_VOID\n");
                        break;
                    default :
                        printf("defaut\n");
                        break;
                }
            retour->type = va_arg(ap,node_type);
				printf("make_node node_type réussi\n");
            break;
        case NODE_INTVAL:
                printf("make_node intval affectation: %d\n", va_arg(ap,int64_t));
            retour->value = va_arg(ap,int64_t);
            break;
		case NODE_BOOLVAL:
                printf("make_node boolval affectation \n");
			if (va_arg(ap,int)== 1)
                {   printf("true\n");
                    retour->value = 1;}
            else if(va_arg(ap,char*)==0)
                {   printf("false\n");
                    retour->value = 0;}
            break;
        case NODE_STRINGVAL :
                printf("make_node stringval affectation\n");
            retour->str = va_arg(ap,char*);
			retour->offset = va_arg(ap,int32_t);
                printf("stringval affecté: %s\noffset: %d\n",retour->str, retour->offset);
            break;
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
                //printf("retour : %s\n", &retour);
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
#line 694 "y.tab.c"

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
			couleur("34"); printf("NODE_PROGRAM %s\n", yyval.ptr);couleur("0");
            printf("node nature de $$ : %s\n",node_nature2string(yyval.ptr->nature) );
            *program_root = yyval.ptr;

        }
break;
case 2:
#line 104 "grammar.y"
	{
            printf("program : main\n");
            yyval.ptr = make_node(NODE_PROGRAM, 2, NULL, yystack.l_mark[0].ptr);
			couleur("34"); printf("NODE_PROGRAM %s\n", yyval.ptr);couleur("0");
            printf("node nature de $$ : %s\n",node_nature2string(yyval.ptr->nature) );
            *program_root = yyval.ptr;

        }
break;
case 3:
#line 114 "grammar.y"
	{
            printf("listdecl : listdeclnonnull\n");
            yyval.ptr = yystack.l_mark[0].ptr;/*make_node(NODE_LIST, 1, $1 );*/
			couleur("34"); printf("NODE_LIST $$ = %s\n", yyval.ptr);("0");
            /**program_root = $$;*/

        }
break;
case 4:
#line 122 "grammar.y"
	{ printf("listdecl : epsilon");yyval.ptr = NULL; }
break;
case 5:
#line 125 "grammar.y"
	{
                printf("listdecl non nulle : vardecl $1 = %s\n", yyval.ptr);
				yyval.ptr = make_node(NODE_LIST, 1, yystack.l_mark[0].ptr);
                couleur("34"); printf("NODE_LIST $$ = %s\n", yyval.ptr);couleur("0");
            	/**program_root = $$;*/
			}
break;
case 6:
#line 132 "grammar.y"
	{
                printf("listdecl non nulle : list + vardecl\n");
                printf("$1 = %s\n$2 = %s", yystack.l_mark[-1].ptr, yystack.l_mark[0].ptr);
				make_node(NODE_LIST, 2, yystack.l_mark[-1].ptr, yystack.l_mark[0].ptr);
                couleur("34"); printf("NODE_LIST $$ = %s\n", yyval.ptr);couleur("0");
            	/**program_root = $$;*/
			}
break;
case 7:
#line 141 "grammar.y"
	{
                printf("vardecl\n");
                printf("$1 = %s\n$2 = %s", yystack.l_mark[-2].ptr, yystack.l_mark[-1].ptr);
				yyval.ptr = make_node(NODE_DECLS, 2, yystack.l_mark[-2].ptr, yystack.l_mark[-1].ptr);
                couleur("34"); printf("NODE_LIST $$ = %s\n", yyval.ptr);couleur("0");
            	/**program_root = $$;*/
			}
break;
case 8:
#line 150 "grammar.y"
	{
            printf("type : TOK_INT\nsizeof(0): %d\n", sizeof(0));
			yyval.ptr = make_node(NODE_TYPE, 0, TYPE_INT);
        	couleur("34"); printf("NODE_TYPE $$ = %s\n", yyval.ptr);couleur("0");/**program_root = $$;*/
		}
break;
case 9:
#line 156 "grammar.y"
	{
            printf("type : TOK_BOOL\n");
			yyval.ptr = make_node(NODE_TYPE, 0, TYPE_BOOL);
			couleur("34"); printf("NODE_TYPE $$ = %s\n", yyval.ptr);couleur("0");/**program_root = $$;*/
		}
break;
case 10:
#line 162 "grammar.y"
	{
            printf("type : TOK_VOID\n");
			yyval.ptr = make_node(NODE_TYPE, 0, TYPE_VOID);
			couleur("34"); printf("NODE_TYPE $$ = %s\n", yyval.ptr);couleur("0");/**program_root = $$;*/
		}
break;
case 11:
#line 169 "grammar.y"
	{
                    printf("listtypedecl : decl\n");
					yyval.ptr = yystack.l_mark[0].ptr;/*make_node(NODE_LIST, 1 ,$1);*/
					/*printf("listtypedecl : decl bis\n");*/
                	couleur("34"); printf(" go decl $$ = %s\n" ,yyval.ptr);couleur("0");/**program_root = $$;*/
				}
break;
case 12:
#line 176 "grammar.y"
	{
                    printf("$1 = %s\n$3 = %s", yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
                    printf("listtypedecl : listtypedecl, decl\n");
					yyval.ptr = make_node(NODE_LIST, 2 , yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
                	couleur("34"); printf("NODE_LIST $$ = %s\n", yyval.ptr);couleur("0");/**program_root = $$;*/
				}
break;
case 13:
#line 184 "grammar.y"
	{
            printf("decl : ident\n");
            printf("$1 = %s\n", yystack.l_mark[0].ptr);
	   		yyval.ptr = make_node(NODE_DECL, 2, yystack.l_mark[0].ptr, NULL );
       		couleur("34"); printf("NODE_DECL $$ = %s\n, $$");couleur("0");/**program_root = $$;*/
			printf("decl : ident bis\n");
		}
break;
case 14:
#line 192 "grammar.y"
	{
			printf("decl : ident TOK_AFFECT expr\n");
            printf("$1 = %s\n$3 = %s", yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
			yyval.ptr = make_node(NODE_DECL, 2 ,yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
       		couleur("34"); printf("NODE_DECL $$ = %s\n", yyval.ptr);couleur("0");/**program_root = $$;*/
		}
break;
case 15:
#line 201 "grammar.y"
	{
                printf("$1 = %s\n$2 = %s\n$$5 = %s\n", yystack.l_mark[-4].ptr, yystack.l_mark[-3].ptr, yystack.l_mark[0].ptr);
                couleur("34"); printf("NODE_FUNC %s %s %s\n", yystack.l_mark[-4].ptr, yystack.l_mark[-3].ptr, yystack.l_mark[0].ptr);couleur("0");/**program_root = $$;*/
				yyval.ptr = make_node(NODE_FUNC, 3, yystack.l_mark[-4].ptr, yystack.l_mark[-3].ptr, yystack.l_mark[0].ptr, 8, 8);
                printf("$$ = %s\n", yyval.ptr);
			}
break;
case 16:
#line 209 "grammar.y"
	{
				yyval.ptr = yystack.l_mark[0].ptr;/*make_node(NODE_LIST, 1, $1);*/
            	couleur("34"); printf("NODE_LIST\n");couleur("0");/**program_root = $$;*/
			}
break;
case 17:
#line 214 "grammar.y"
	{
				yyval.ptr = NULL;
			}
break;
case 18:
#line 218 "grammar.y"
	{
					yyval.ptr = yystack.l_mark[0].ptr;/*$$ = make_node(NODE_LIST, 1, $1);*/
                	couleur("34"); printf("NODE_LIST $$ = %s\n", yyval.ptr);couleur("0");/**program_root = $$;*/
				}
break;
case 19:
#line 223 "grammar.y"
	{
					yyval.ptr = make_node(NODE_LIST, 2, yystack.l_mark[-1].ptr, yystack.l_mark[0].ptr);
                	couleur("34"); printf("NODE_LIST $$ = %s\n", yyval.ptr);couleur("0");/**program_root = $$;*/
				}
break;
case 20:
#line 229 "grammar.y"
	{
			yyval.ptr = yystack.l_mark[-1].ptr;
        	couleur("34"); printf("semicol\n");couleur("0");/**program_root = $$;*/
		}
break;
case 21:
#line 234 "grammar.y"
	{
			yyval.ptr = make_node(NODE_IF, 3, yystack.l_mark[-4].ptr, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
			couleur("34"); printf("NODE_IF $$ = %s\n", yyval.ptr);couleur("0");/**program_root = $$;*/
		}
break;
case 22:
#line 239 "grammar.y"
	{
			yyval.ptr = make_node(NODE_IF, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	couleur("34"); printf("NODE_IF $$ = %s\n", yyval.ptr);couleur("0");/**program_root = $$;*/
		}
break;
case 23:
#line 244 "grammar.y"
	{
			yyval.ptr = make_node(NODE_WHILE, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	couleur("34"); printf("NODE_WHILE $$ = %s\n", yyval.ptr);couleur("0");/**program_root = $$;*/
		}
break;
case 24:
#line 249 "grammar.y"
	{
			yyval.ptr = make_node(NODE_FOR, 4, yystack.l_mark[-6].ptr ,yystack.l_mark[-4].ptr, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	couleur("34"); printf("NODE_FOR $$ = %s\n", yyval.ptr);couleur("0");/**program_root = $$;*/
		}
break;
case 25:
#line 254 "grammar.y"
	{
			yyval.ptr = make_node(NODE_DOWHILE, 2, yystack.l_mark[-5].ptr, yystack.l_mark[-2].ptr);
        	couleur("34"); printf("NODE_DOWHILE $$ = %s\n", yyval.ptr);couleur("0");/**program_root = $$;*/
		}
break;
case 26:
#line 259 "grammar.y"
	{
			yyval.ptr = yystack.l_mark[0].ptr;
        	/**program_root = $$;*/
		}
break;
case 27:
#line 264 "grammar.y"
	{
			yyval.ptr = NULL;
		}
break;
case 28:
#line 268 "grammar.y"
	{
			yyval.ptr = make_node(NODE_PRINT, 1, yystack.l_mark[-2].ptr);
        	couleur("34"); printf("NODE_PRINT $$ = %s\n", yyval.ptr);couleur("0");/**program_root = $$;*/
		}
break;
case 29:
#line 274 "grammar.y"
	{
			yyval.ptr = make_node(NODE_BLOCK, 2, yystack.l_mark[-2].ptr, yystack.l_mark[-1].ptr);
        	couleur("34"); printf("NODE_BLOCK $$ = %s\n", yyval.ptr);couleur("0");/**program_root = $$;*/
		}
break;
case 30:
#line 280 "grammar.y"
	{
			yyval.ptr = make_node(NODE_MUL, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	couleur("34"); printf("NODE_MUL $$ = %s\n", yyval.ptr);couleur("0");/**program_root = $$;*/
		}
break;
case 31:
#line 285 "grammar.y"
	{
			yyval.ptr = make_node(NODE_DIV, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	couleur("34"); printf("NODE_DIV $$ = %s\n", yyval.ptr);couleur("0");/**program_root = $$;*/
		}
break;
case 32:
#line 290 "grammar.y"
	{
			yyval.ptr = make_node(NODE_PLUS, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	couleur("34"); printf("NODE_PLUS $$ = %s\n", yyval.ptr);couleur("0");/**program_root = $$;*/
		}
break;
case 33:
#line 295 "grammar.y"
	{
			yyval.ptr = make_node(NODE_MINUS, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	couleur("34"); printf("NODE_MINUS $$ = %s\n", yyval.ptr);couleur("0");/**program_root = $$;*/
		}
break;
case 34:
#line 300 "grammar.y"
	{
			yyval.ptr = make_node(NODE_MOD, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	couleur("34"); printf("NODE_MOD $$ = %s\n", yyval.ptr);couleur("0");/**program_root = $$;*/
		}
break;
case 35:
#line 305 "grammar.y"
	{
			yyval.ptr = make_node(NODE_LT, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	couleur("34"); printf("NODE_LT $$ = %s\n", yyval.ptr);couleur("0");/**program_root = $$;*/
		}
break;
case 36:
#line 310 "grammar.y"
	{
			yyval.ptr = make_node(NODE_GT, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	couleur("34"); printf("NODE_GT $$ = %s\n", yyval.ptr);couleur("0");/**program_root = $$;*/
		}
break;
case 37:
#line 315 "grammar.y"
	{
			yyval.ptr = make_node(NODE_UMINUS, 1, yystack.l_mark[0].ptr);
        	couleur("34"); printf("NODE_UMINUS $$ = %s\n", yyval.ptr);couleur("0");/**program_root = $$;*/
		}
break;
case 38:
#line 320 "grammar.y"
	{
			yyval.ptr = make_node(NODE_GE, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	couleur("34"); printf("NODE_GE $$ = %s\n", yyval.ptr);couleur("0");/**program_root = $$;*/
		}
break;
case 39:
#line 325 "grammar.y"
	{
            printf("$1 = %s\n$3 = %s", yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
			yyval.ptr = make_node(NODE_LE, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 40:
#line 330 "grammar.y"
	{
            printf("$1 = %s\n$3 = %s", yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
			yyval.ptr = make_node(NODE_EQ, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 41:
#line 335 "grammar.y"
	{
            printf("$1 = %s\n$3 = %s", yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
			yyval.ptr = make_node(NODE_NE, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 42:
#line 340 "grammar.y"
	{
            printf("$1 = %s\n$3 = %s", yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
			yyval.ptr = make_node(NODE_AND, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 43:
#line 345 "grammar.y"
	{
            printf("$1 = %s\n$3 = %s", yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
			yyval.ptr = make_node(NODE_OR, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 44:
#line 350 "grammar.y"
	{
            printf("$1 = %s\n$3 = %s", yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
			yyval.ptr = make_node(NODE_BAND, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 45:
#line 355 "grammar.y"
	{
            printf("$1 = %s\n$3 = %s", yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
			yyval.ptr = make_node(NODE_BOR, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 46:
#line 360 "grammar.y"
	{
            printf("$1 = %s\n$3 = %s", yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
			yyval.ptr = make_node(NODE_BXOR, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 47:
#line 365 "grammar.y"
	{
            printf("$1 = %s\n$3 = %s", yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
			yyval.ptr = make_node(NODE_SRL, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 48:
#line 370 "grammar.y"
	{
            printf("$1 = %s\n$3 = %s", yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
			yyval.ptr = make_node(NODE_SRA, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 49:
#line 375 "grammar.y"
	{
            printf("$1 = %s\n$3 = %s", yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
			yyval.ptr = make_node(NODE_SLL, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 50:
#line 380 "grammar.y"
	{
            printf("$2 = %s\n",yystack.l_mark[0].ptr);
			yyval.ptr = make_node(NODE_NOT, 1, yystack.l_mark[0].ptr);
		}
break;
case 51:
#line 385 "grammar.y"
	{
            printf("$2 = %s\n",yystack.l_mark[0].ptr);
			yyval.ptr = make_node(NODE_BNOT, 1, yystack.l_mark[0].ptr);
		}
break;
case 52:
#line 390 "grammar.y"
	{
			printf("expr : TOK_LPAR expr TOK_RPAR\n");
            printf("$2 = %s\n",yystack.l_mark[-1].ptr);
			/*$$ = make_node(NODE_, 2, $1, $3)*/
		}
break;
case 53:
#line 396 "grammar.y"
	{
			yyval.ptr = make_node(NODE_AFFECT, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr); /* arg supp : type de noeud*/
            printf("expr : ident TOK_AFFECT expr $$ = %s\n", yyval.ptr);
            printf("$1 = %s\$3 = %s\n",yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
		}
break;
case 54:
#line 402 "grammar.y"
	{
			yyval.ptr = make_node(NODE_INTVAL, 0, yylval.intval );
            printf("expr : TOK_INTVAL $$ = %s\n", yyval.ptr);
		}
break;
case 55:
#line 407 "grammar.y"
	{
			printf("expr : ident\n");
			yyval.ptr = yystack.l_mark[0].ptr;
		}
break;
case 56:
#line 412 "grammar.y"
	{
            yyval.ptr = make_node(NODE_BOOLVAL, 0,1);
            printf("expr: BOOLVAL TRUE $$ = %s\n", yyval.ptr);
        }
break;
case 57:
#line 417 "grammar.y"
	{
            yyval.ptr = make_node(NODE_BOOLVAL, 0,0 );
            printf("expr:BOOLVAL false $$ = %s\n", yyval.ptr);
        }
break;
case 58:
#line 422 "grammar.y"
	{
            yyval.ptr = make_node(NODE_STRINGVAL, 0, yylval.strval, sizeof(yylval.strval) );
            couleur("34"); printf("expr : NODE_STRINGVAL $$ = %s\n", yyval.ptr);couleur("0");/**program_root = $$;*/
        }
break;
case 59:
#line 429 "grammar.y"
	{
					yyval.ptr = make_node(NODE_LIST, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr); /* a verifier*/
					couleur("34"); printf("NODE_PRINT $$ = %s\n", yyval.ptr);couleur("0");/**program_root = $$;*/
				}
break;
case 60:
#line 434 "grammar.y"
	{
					yyval.ptr = yystack.l_mark[0].ptr;
				}
break;
case 61:
#line 440 "grammar.y"
	{
				yyval.ptr = yystack.l_mark[0].ptr;
			}
break;
case 62:
#line 444 "grammar.y"
	{ /* make node (node print, )*/
				yyval.ptr = make_node(NODE_STRINGVAL, 0, yylval.strval, sizeof(yylval.strval) );
				couleur("34"); printf("paramprint : NODE_STRINGVAL $$ = %s\n", yyval.ptr);couleur("0");/**program_root = $$;*/
			}
break;
case 63:
#line 451 "grammar.y"
	{
			printf("ident : TOK_IDENT\n");
			yyval.ptr = make_node(NODE_IDENT, 0);/* //   type =  TYPE_NONE,TYPE_INT,TYPE_BOOL,TYPE_STRING,TYPE_VOID

    				printf("make_node node_ident 1\n");
                retour->type      =va_arg(ap,node_type); // argument supp à la position nops + 1 = type de noeud
    				printf("make_node node_ident 2\n");
                retour->decl_node =va_arg(ap,node_t); // argument supp à la position nops + 2 = declaration de noeud
    				printf("make_node node_ident 3\n");
                retour->offset    =va_arg(ap,int32_t ); // argument supp à la position nops + 3 = declaration de l'emplacement mémoire de la variable int32_t
    				printf("make_node node_ident 4\n");
                retour->global_decl=va_arg(ap,int); // argument supp à la position nops + 4 = declaration globale?
    				printf("make_node node_ident 5\n");*/
			couleur("34"); printf("NODE_IDENT $$ = %s\n", yyval.ptr);couleur("0");/**program_root = $$;*/
		}
break;
#line 1376 "y.tab.c"
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
