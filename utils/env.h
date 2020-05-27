
#ifndef _ENV_H_
#define _ENV_H_


#include "context.h"


typedef struct _env_s {
    struct _env_s * next;
    context_t context;
} env_s;

typedef env_s * env_t;



void push_global_context();//PASSE 1 initialise un contexte pour les variables globales
void push_context();//PASSE 1  initialise un contexte pour les variables locales
void pop_context();//PASSE 1  depile et libere le contexte courant, à appeler à la fin d'un bloc qui déclare des variables
void * get_decl_node(char * ident);// def de ident dans l'empilement des contextes, s'arrete au premier contexte trouvé
int32_t env_add_element(char * ident, void * node, int32_t size);// associe ident et noeud node. size = taille a allouer
                                                                // valeur de retour : taille a allouer si positive ou nulle, pb si negative, a associer à l'offset d'un element
void reset_env_current_offset();// reinitialise l'offset courant à 0,a appeler au debut de l'analyse d'une fonction
int32_t get_env_current_offset();//PASSE 1 donne l'offset courant du context
int32_t add_string(char * str);//PASSE 1 ajoute la declaration dans le .data de string et retourne l'offset a associer a un string
int32_t get_global_strings_number(); // donne le nombre de string afin de les declarer dans le .data
char * get_global_string(int32_t index); //retourne la string à l'index index
void free_global_strings();// libere la memoire allouee pour les strings

#endif
