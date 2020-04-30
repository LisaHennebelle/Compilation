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
#line 71 "y.tab.c"

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
#define TOK_SRL 295
#define TOK_SRA 296
#define TOK_SLL 297
#define TOK_NOT 298
#define TOK_BNOT 299
#define ident 300
#define listparamprint 301
#define paramprint 302
#define TOK_PAR 303
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,   11,   11,   12,   12,    1,    2,    2,    2,
    3,    3,    4,    4,    5,    6,    6,    7,    7,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    9,   10,
   10,   10,   10,   10,   10,   10,   10,   10,
};
static const YYINT yylen[] = {                            2,
    2,    1,    1,    0,    1,    2,    3,    1,    1,    1,
    1,    3,    1,    3,    5,    1,    0,    1,    2,    2,
    7,    5,    5,    9,    7,    1,    1,    5,    4,    3,
    3,    3,    3,    3,    3,    3,    2,    3,
};
static const YYINT yydefred[] = {                         0,
   10,    8,    9,    0,    5,    0,    2,    0,    0,    0,
   11,    6,    1,    0,    0,    7,    0,    0,    0,    0,
    0,   12,   37,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   15,    0,    0,    0,    0,    0,   30,   31,
   34,    0,    0,    0,    0,    0,    0,    0,   27,    0,
    0,    0,   18,   26,    0,    0,    0,    0,    0,    0,
   29,   19,   20,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   23,    0,   28,    0,    0,    0,
    0,   21,    0,   25,    0,   24,
};
static const YYINT yydgoto[] = {                          4,
    5,    6,   10,   11,    7,   51,   52,   53,   54,   55,
   43,    8,
};
static const YYINT yysindex[] = {                      -232,
    0,    0,    0,    0,    0, -298,    0, -232, -249, -236,
    0,    0,    0, -270, -252,    0, -266, -270,  -45, -247,
 -228,    0,    0, -270, -270, -270, -270, -270, -270, -270,
 -270, -232,    0,  -40,  -40,  -40, -218, -218,    0,    0,
    0, -266, -179, -232, -226, -221, -219, -217,    0, -179,
 -239, -179,    0,    0,  -78, -270, -270, -270, -245, -191,
    0,    0,    0, -164, -153,  -67, -202, -211, -179, -179,
 -270, -200, -270, -181,    0,  -56,    0, -142, -179, -270,
 -188,    0, -131,    0, -179,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0, -205,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -203,    0,
 -205,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -237,    0, -264,  -98,  -92, -120, -106,    0,    0,
    0,    0, -192, -213,    0,    0,    0,    0,    0,    0,
    0, -190,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -196,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   -7,   -8,    0,   79,   91,    0,    0,  -47,   80,  -14,
    0,   69,
};
#define YYTABLESIZE 240
static const YYINT yytable[] = {                         19,
   12,    9,   60,   23,   62,   38,   18,   38,   38,   34,
   35,   36,   37,   38,   39,   40,   41,   38,   38,   14,
   38,   74,   75,   42,    1,    2,    4,    3,    4,    4,
    4,   82,   20,   21,   15,   42,   12,   86,   32,    4,
   14,   64,   65,   66,    4,   16,   17,   61,    4,    4,
    3,    4,    3,    3,    3,   67,   76,   56,   78,   29,
   30,   31,   57,    3,   58,   83,   59,   22,    3,   22,
   22,   22,    3,    3,   68,    3,   13,   13,   14,   14,
   22,   77,   72,   79,   45,   22,   46,   47,   48,   22,
   22,   73,   22,   84,   17,   22,   16,   18,   13,   33,
   44,    0,   49,    0,    0,   24,   32,   25,   26,   50,
    0,   27,   28,   29,   30,   31,   24,    0,   25,   26,
   69,    0,   27,   28,   29,   30,   31,   24,    0,   25,
   26,   70,    0,   27,   28,   29,   30,   31,   24,    0,
   25,   26,   81,    0,   27,   28,   29,   30,   31,   32,
    0,   32,   32,   85,    0,   32,   32,    0,    0,    0,
    0,   32,   32,   33,   32,   33,   33,    0,    0,   33,
   33,   36,    0,   36,   36,   33,   33,   35,   33,   35,
   35,    0,    0,   36,   36,    0,   36,    0,    0,   35,
   35,   24,   35,   25,   26,    0,    0,   27,   28,   29,
   30,   31,   24,   63,   25,   26,    0,    0,   27,   28,
   29,   30,   31,   24,   71,   25,   26,    0,    0,   27,
   28,   29,   30,   31,   24,   80,   25,   26,    0,    0,
   27,   28,   29,   30,   31,   27,   28,   29,   30,   31,
};
static const YYINT yycheck[] = {                         14,
    8,  300,   50,   18,   52,  270,  277,  272,  273,   24,
   25,   26,   27,   28,   29,   30,   31,  282,  283,  269,
  285,   69,   70,   32,  257,  258,  264,  260,  266,  267,
  268,   79,  285,  300,  284,   44,   44,   85,  286,  277,
  269,   56,   57,   58,  282,  282,  283,  287,  286,  287,
  264,  289,  266,  267,  268,  301,   71,  284,   73,  278,
  279,  280,  284,  277,  284,   80,  284,  264,  282,  266,
  267,  268,  286,  287,  266,  289,  282,  283,  282,  283,
  277,  282,  285,  265,  264,  282,  266,  267,  268,  286,
  287,  303,  289,  282,  287,   17,  287,  277,    8,   20,
   32,   -1,  282,   -1,   -1,  270,  286,  272,  273,  289,
   -1,  276,  277,  278,  279,  280,  270,   -1,  272,  273,
  285,   -1,  276,  277,  278,  279,  280,  270,   -1,  272,
  273,  285,   -1,  276,  277,  278,  279,  280,  270,   -1,
  272,  273,  285,   -1,  276,  277,  278,  279,  280,  270,
   -1,  272,  273,  285,   -1,  276,  277,   -1,   -1,   -1,
   -1,  282,  283,  270,  285,  272,  273,   -1,   -1,  276,
  277,  270,   -1,  272,  273,  282,  283,  270,  285,  272,
  273,   -1,   -1,  282,  283,   -1,  285,   -1,   -1,  282,
  283,  270,  285,  272,  273,   -1,   -1,  276,  277,  278,
  279,  280,  270,  282,  272,  273,   -1,   -1,  276,  277,
  278,  279,  280,  270,  282,  272,  273,   -1,   -1,  276,
  277,  278,  279,  280,  270,  282,  272,  273,   -1,   -1,
  276,  277,  278,  279,  280,  276,  277,  278,  279,  280,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 303
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
"TOK_SRL","TOK_SRA","TOK_SLL","TOK_NOT","TOK_BNOT","ident","listparamprint",
"paramprint","TOK_PAR",0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"inst : TOK_DO inst TOK_WHILE TOK_PAR expr TOK_RPAR TOK_SEMICOL",
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
#line 302 "grammar.y"
/* A completer et/ou remplacer avec d'autres fonctions */

node_t make_node(node_nature nature, int nops, ...) {
    printf("NODE CREE");

    //cptnodes ++;
    //printf("on make le node n°%d\n", cptnodes);
    va_list ap; /*liste des arguments supplémentaires*/
    va_start(ap,nops);
    node_t retour;/* malloc?*/
    //retour->node_num = cptnodes;
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
#line 446 "y.tab.c"

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
#line 94 "grammar.y"
	{
            printf("liste non nulle et main\n");
            yyval.ptr = make_node(NODE_PROGRAM, 2, yystack.l_mark[-1].ptr, yystack.l_mark[0].ptr); /* Erreur : $$ is untyped*/
            *program_root = yyval.ptr;
        }
break;
case 2:
#line 100 "grammar.y"
	{
            printf("main\n");
            yyval.ptr = make_node(NODE_PROGRAM, 2, NULL, yystack.l_mark[0].ptr);
            *program_root = yyval.ptr;
        }
break;
case 3:
#line 107 "grammar.y"
	{
            printf("listdecl\n");
            /* combien d'enfants pour un node list?*/
            yyval.ptr = make_node(NODE_LIST, 1, yystack.l_mark[0].ptr );
            *program_root = yyval.ptr;
        }
break;
case 4:
#line 114 "grammar.y"
	{ yyval.ptr = NULL; }
break;
case 5:
#line 117 "grammar.y"
	{
                printf("listdecl non nulle\n");
				yyval.ptr = make_node(NODE_LIST, 1, yystack.l_mark[0].ptr);
            	*program_root = yyval.ptr;
			}
break;
case 6:
#line 123 "grammar.y"
	{
				yyval.ptr = make_node(NODE_LIST, 2, yystack.l_mark[-1].ptr, yystack.l_mark[0].ptr);
            	*program_root = yyval.ptr;
			}
break;
case 7:
#line 129 "grammar.y"
	{
                printf("vardecl\n");
				yyval.ptr = make_node(NODE_LIST, 1, yystack.l_mark[-2].ptr);
            	*program_root = yyval.ptr;
			}
break;
case 8:
#line 136 "grammar.y"
	{
            printf("int\n");
			yyval.ptr = make_node(NODE_TYPE, 0, TYPE_INT);
        	*program_root = yyval.ptr;
		}
break;
case 9:
#line 142 "grammar.y"
	{
            printf("bool\n");
			yyval.ptr = make_node(NODE_TYPE, 0, TYPE_BOOL);
			*program_root = yyval.ptr;
		}
break;
case 10:
#line 148 "grammar.y"
	{
            printf("void\n");
			yyval.ptr = make_node(NODE_TYPE, 0, TYPE_VOID);
			*program_root = yyval.ptr;
		}
break;
case 11:
#line 155 "grammar.y"
	{
                    printf("\n");
					yyval.ptr = make_node(NODE_LIST, 1 ,yystack.l_mark[0].ptr);
                	*program_root = yyval.ptr;
				}
break;
case 12:
#line 161 "grammar.y"
	{
					yyval.ptr = make_node(NODE_LIST, 2 , yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
                	*program_root = yyval.ptr;
				}
break;
case 13:
#line 167 "grammar.y"
	{
	   		yyval.ptr = make_node(NODE_DECL, 2, yystack.l_mark[0].ptr, NULL );
       		*program_root = yyval.ptr;
		}
break;
case 14:
#line 172 "grammar.y"
	{
			yyval.ptr = make_node(NODE_DECL, 2 ,yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
       		*program_root = yyval.ptr;
		}
break;
case 15:
#line 179 "grammar.y"
	{
				yyval.ptr = make_node(NODE_FUNC, 3, yystack.l_mark[-4].ptr, yystack.l_mark[-3].ptr, yystack.l_mark[0].ptr);
            	*program_root = yyval.ptr;
			}
break;
case 16:
#line 185 "grammar.y"
	{
				yyval.ptr = make_node(NODE_LIST, 1, yystack.l_mark[0].ptr);
            	*program_root = yyval.ptr;
			}
break;
case 17:
#line 190 "grammar.y"
	{
				yyval.ptr = NULL;
			}
break;
case 18:
#line 194 "grammar.y"
	{
					yyval.ptr = make_node(NODE_LIST, 1, yystack.l_mark[0].ptr);
                	*program_root = yyval.ptr;
				}
break;
case 19:
#line 199 "grammar.y"
	{
					yyval.ptr = make_node(NODE_LIST, 2, yystack.l_mark[-1].ptr, yystack.l_mark[0].ptr);
                	*program_root = yyval.ptr;
				}
break;
case 20:
#line 205 "grammar.y"
	{
			yyval.ptr = make_node(NODE_BLOCK, 1, yystack.l_mark[-1].ptr); /* NODE_BLOCK ?*/
        	*program_root = yyval.ptr;
		}
break;
case 21:
#line 210 "grammar.y"
	{
			yyval.ptr = make_node(NODE_IF, 3, yystack.l_mark[-4].ptr, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
			*program_root = yyval.ptr;
		}
break;
case 22:
#line 215 "grammar.y"
	{
			yyval.ptr = make_node(NODE_IF, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	*program_root = yyval.ptr;
		}
break;
case 23:
#line 220 "grammar.y"
	{
			yyval.ptr = make_node(NODE_WHILE, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	*program_root = yyval.ptr;
		}
break;
case 24:
#line 225 "grammar.y"
	{
			yyval.ptr = make_node(NODE_FOR, 4, yystack.l_mark[-6].ptr ,yystack.l_mark[-4].ptr, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	*program_root = yyval.ptr;
		}
break;
case 25:
#line 230 "grammar.y"
	{
			yyval.ptr = make_node(NODE_DOWHILE, 2, yystack.l_mark[-5].ptr, yystack.l_mark[-2].ptr);
        	*program_root = yyval.ptr;
		}
break;
case 26:
#line 235 "grammar.y"
	{
			yyval.ptr = make_node(NODE_BLOCK, 1, yystack.l_mark[0].ptr);
        	*program_root = yyval.ptr;
		}
break;
case 27:
#line 240 "grammar.y"
	{
			yyval.ptr = NULL;
		}
break;
case 28:
#line 244 "grammar.y"
	{
			yyval.ptr = make_node(NODE_PRINT, 1, yystack.l_mark[-2].ptr);
        	*program_root = yyval.ptr;
		}
break;
case 29:
#line 250 "grammar.y"
	{
			yyval.ptr = make_node(NODE_BLOCK, 2, yystack.l_mark[-2].ptr, yystack.l_mark[-1].ptr);
        	*program_root = yyval.ptr;
		}
break;
case 30:
#line 256 "grammar.y"
	{
			yyval.ptr = make_node(NODE_MUL, 2,yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	*program_root = yyval.ptr;
		}
break;
case 31:
#line 261 "grammar.y"
	{
			yyval.ptr = make_node(NODE_DIV, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	*program_root = yyval.ptr;
		}
break;
case 32:
#line 266 "grammar.y"
	{
			yyval.ptr = make_node(NODE_PLUS, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	*program_root = yyval.ptr;
		}
break;
case 33:
#line 271 "grammar.y"
	{
			yyval.ptr = make_node(NODE_MINUS, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	*program_root = yyval.ptr;
		}
break;
case 34:
#line 276 "grammar.y"
	{
			yyval.ptr = make_node(NODE_MOD, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	*program_root = yyval.ptr;
		}
break;
case 35:
#line 281 "grammar.y"
	{
			yyval.ptr = make_node(NODE_LT, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	*program_root = yyval.ptr;
		}
break;
case 36:
#line 286 "grammar.y"
	{
			yyval.ptr = make_node(NODE_GT, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	*program_root = yyval.ptr;
		}
break;
case 37:
#line 291 "grammar.y"
	{
			yyval.ptr = make_node(NODE_UMINUS, 1, yystack.l_mark[0].ptr);
        	*program_root = yyval.ptr;
		}
break;
case 38:
#line 296 "grammar.y"
	{
			yyval.ptr = make_node(NODE_GE, 2, yystack.l_mark[-2].ptr, yystack.l_mark[0].ptr);
        	*program_root = yyval.ptr;
		}
break;
#line 919 "y.tab.c"
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
