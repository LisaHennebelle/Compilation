
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#define couleur(param) printf("\033[%sm",param)
#include <stdbool.h>
#include <inttypes.h>
#include <unistd.h>
#include <getopt.h>
#include "defs.h"

node_t make_nodemalloc()
{
    node_t nodetest = (node_s *) malloc(sizeof(node_s));
    nodetest->nature = NODE_TYPE;
    return nodetest;
}


node_t make_node_arg(node_type type)
{
    node_t nodetest = (node_s *) malloc(sizeof(node_s));
    nodetest->nature = type;
    return nodetest;
}
const char * node_nature2string(node_nature t) {
    switch (t) {
        case NONE:
            return "NONE";
        case NODE_PROGRAM:
            return "PROGRAM";
        case NODE_BLOCK:
            return "BLOCK";
        case NODE_LIST:
            return "LIST";
        case NODE_DECLS:
            return "DECLS";
        case NODE_DECL:
            return "DECL";
        case NODE_IDENT:
            return "IDENT";
        case NODE_TYPE:
            return "TYPE";
        case NODE_INTVAL:
            return "INTVAL";
        case NODE_BOOLVAL:
            return "BOOLVAL";
        case NODE_STRINGVAL:
            return "STRINGVAL";
        case NODE_FUNC:
            return "FUNC";
        case NODE_IF:
            return "IF";
        case NODE_WHILE:
            return "WHILE";
        case NODE_FOR:
            return "FOR";
        case NODE_DOWHILE:
            return "DOWHILE";
        case NODE_PLUS:
            return "PLUS";
        case NODE_MINUS:
            return "MINUS";
        case NODE_MUL:
            return "MUL";
        case NODE_DIV:
            return "DIV";
        case NODE_MOD:
            return "MOD";
        case NODE_LT:
            return "LT";
        case NODE_GT:
            return "GT";
        case NODE_LE:
            return "LE";
        case NODE_GE:
            return "GE";
        case NODE_EQ:
            return "EQ";
        case NODE_NE:
            return "NE";
        case NODE_AND:
            return "AND";
        case NODE_OR:
            return "OR";
        case NODE_BAND:
            return "BAND";
        case NODE_BOR:
            return "BOR";
        case NODE_BXOR:
            return "BXOR";
        case NODE_SLL:
            return "SLL";
        case NODE_SRA:
            return "SRA";
        case NODE_SRL:
            return "SRL";
        case NODE_NOT:
            return "NOT";
        case NODE_BNOT:
            return "BNOT";
        case NODE_UMINUS:
            return "UMINUS";
        case NODE_AFFECT:
            return "AFFECT";
        case NODE_PRINT:
            return "PRINT";
        default:
            fprintf(stderr, "*** Error in %s: Unknown node nature: %d\n", __func__, t);
            exit(1);
    }
}

node_t make_node(node_nature nature, int32_t nops, ...) {
	couleur("30"); printf("NODE CREE\n");
    couleur("0");
    //cptnodes ++;
    //printf("on make le node n°%d\n", cptnodes);
    va_list ap; /*liste des arguments supplémentaires*/
				//printf("make_node 1\n");
    va_start(ap,nops);
                //printf("make_node 2\n");

    node_t retour = (node_s *) malloc(sizeof(node_s));
				//printf("make_node 3\n");
    //retour->node_num = cptnodes;
	retour->nature = nature;
    //printf("node nature make_node : %s \n",node_nature2string(retour->nature));
				//printf("make_node 4\n");
	retour->nops = nops;
    printf("nops vaut %d \n", nops);
	//printf("sizeof(retour->nops): %ld %ld (int32_t)\n", sizeof(retour->nops), sizeof(nops));
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
                printf("make_node intval affectation: %ld\n", va_arg(ap,int64_t));
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
            printf("nature default\n");
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


int main ()
{
    node_t test1 = make_nodemalloc();
    printf("nature de test 1 : %s\n", node_nature2string(test1->nature));

    node_t test2 = make_node_arg(NODE_TYPE);
    printf("nature de test 2 : %s\n", node_nature2string(test2->nature));
    node_t intval = make_node(NODE_TYPE,0, TYPE_INT);
    printf("nature de intval : %s\n", node_nature2string(intval->nature));
    free(test1);
    free(test2);
    free(intval);
}
