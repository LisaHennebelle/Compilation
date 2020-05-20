
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
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



int main ()
{
    node_t test1 = make_nodemalloc();
    printf("nature de test 1 : %s\n", node_nature2string(test1->nature));

    node_t test2 = make_node_arg(NODE_TYPE);
    printf("nature de test 2 : %s\n", node_nature2string(test2->nature));

    free(test1);
    free(test2);
}
