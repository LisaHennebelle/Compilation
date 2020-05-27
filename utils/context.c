#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "context.h"

context_t create_context() // cree un contexte et lui alloue de la mémoire
{
    context_t cont = malloc(sizeof(context_s));
    if (cont == NULL)
    {
        printf("il y a eu un problème dans la création d'un contexte\n");
    }
    cont->root = malloc(sizeof(noeud_s));
    (cont->root)->idf_existant = false;
    for(int i = 0; i < NB_ELEM_ALPHABET; i++)
    {
        cont->root->suite_idf[i] = NULL;
    }
    (cont->root)->lettre = 0;
    (cont->root)->data = NULL;
    return cont;
}

int caractere_indice(char lettre)
{
    int car;
    if(lettre >= 'a' && lettre <= 'z')
    {
        car = lettre - 'a';
    }
    else if(lettre >= 'A' && lettre <= 'Z')
    {
        car = lettre - 'A' + 26;
    }
    else if(lettre >= '0' && lettre <= '9')
    {
        car = lettre - '0' + 52;
    }
    else if(lettre == '_')
    {
        car = 62;
    }
    else
    {
        printf("ERROR dans l'evaluation d'un caractere %d\n", lettre);
    }
    return car;
}

noeud_t init_noeud_context(int lettre)
{
  noeud_t noeud = malloc(sizeof(noeud_s));
  noeud->idf_existant = false;
  //printf("init_noeud_context 1\n");
  for(int i = 0; i < NB_ELEM_ALPHABET; i++)
  {
      noeud->suite_idf[i] = NULL;
  }
  noeud->lettre = lettre;
  noeud->data = NULL;
  return noeud;
}

bool context_add_element(context_t context, char * idf, void * data)// ajoute l’as-
//sociation entre le nom idf et le noeud data dans le contexte context. Si le nom idf est
//déjà présent, l’ajout échoue et la fonction retourne false. Sinon, la fonction retourne true.
{
    noeud_t actuel = context->root;
    int idf_len = strlen(idf);
    int lettre, let_indice;
    //printf("RECURSIVITE\n");
    for(int i = 0; i < idf_len; i++)
    {
        lettre = idf[i];
        let_indice = caractere_indice(lettre);
        //////// juste verification
        /*printf("suite idf : %c %d\n" , lettre, let_indice);
        for(int j = 0; j < 63; j++)
        { //VERIFICATION des noeuds déjà créés dans le noeud actuel
            if(actuel->suite_idf[j])
                printf("actuel->suite_idf[%d]\n", j);
        }*/
        /////// juste verification
        if(!(actuel->suite_idf[let_indice]))
        {
            //printf("MALLOOOOOCCC\n");
            actuel->suite_idf[let_indice] = init_noeud_context(lettre);
        }
        actuel = actuel->suite_idf[let_indice];
    }
    if( actuel->idf_existant == true){
        return false;
    }
    else
    {
        actuel->data = data;
        actuel->idf_existant = true;
        return true;
    }

}

void * get_data(context_t context, char * idf)//retourne le noeud précédemment
//associé à idf dans context, ou null si idf n’existe pas dans context.
{
    noeud_t noeud = context->root;
    int i = 0, idf_len = strlen(idf);
    int car = caractere_indice(idf[i]);
    // parcours de contextes à la chaine
    while(i < idf_len && noeud->suite_idf[car])
    {
        noeud = noeud->suite_idf[car];
        //printf("car=%d\t%c i=%d\n", car, idf[i], i);
        if(idf[++i])
            car = caractere_indice(idf[i]);
    }
    if(i < idf_len)
    {
        printf("IDF non trouve\n");
        return NULL;
    }
    if(noeud->idf_existant == true)
    {
        printf("IDF trouve !\n");
        return (context->root)->data;
    }
    return NULL;

}

void free_noeud(noeud_t noeud) //free recursif d'un noeud_t
{
    for(int i = 0; i < NB_ELEM_ALPHABET; i++)
    {
        if(noeud->suite_idf[i])
        {
            free_noeud(noeud->suite_idf[i]);
        }
    }
    noeud->data = NULL;
    free(noeud);
}

void free_context(context_t context) // liberer la memoire allouée pour le contexte
{
    free_noeud(context->root);
    free(context);
}

int main(void)
{
    ///////////VERIFICATION DE CONTEXT
    //printf("hello context\n");
    context_s *context = create_context();
    printf("MAIN\n");
    /*if(context->root) printf("context->root\n");
    if(context->root->suite_idf) printf("context->root->suite_idf\n");*/
    int i = 0;
    while(context->root->suite_idf[i])
    {
      printf("context->root->suite_idf[%d]\n", i++);
    }
    char *data = "patate";
    char *idf = "Gira_fe";
    bool test = context_add_element(context, idf, data);
    if (test){printf("\t1er test ok\n");}
    bool test2 = context_add_element(context, idf, data);
    if(!test2){printf("\t2eme test ok\n");}
    if(context_add_element(context, (void*)"Girasol", data)) printf("\t3eme test ok\n");
    printf("fini init context\n");
    char *test_data = get_data(context, idf);
    free_context(context);
    return 0;}
