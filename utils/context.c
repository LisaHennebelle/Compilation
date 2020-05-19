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
    printf("create_context\n");
    cont->root = malloc(sizeof(noeud_s));
    (cont->root)->idf_existant = false;
    //cont->root->suite_idf = malloc(sizeof(noeud_s*)*NB_ELEM_ALPHABET);
    /*if(cont->root) printf("cont->root\n");
    if(cont->root->suite_idf) printf("cont->root->suite_idf\n");*/
    for(int i = 0; i < NB_ELEM_ALPHABET; i++)
    {
        /*if(cont->root->suite_idf[i])
            printf("cont->root->suite_idf[%d]\n", i);*/
        cont->root->suite_idf[i] = NULL;
    }
    (cont->root)->lettre = 0;
    (cont->root)->data = NULL;
    return cont;
}

noeud_t init_noeud_context()
{
  noeud_t noeud = malloc(sizeof(noeud_s));
  noeud->idf_existant = false;
  //printf("init_noeud_context 1\n");
  for(int i = 0; i < NB_ELEM_ALPHABET; i++)
  {
      noeud->suite_idf[i] = NULL;

      if(i >= 0 && i < 26)
      {
          //printf("hola2\n");
          noeud->lettre = i + 'a';
          //printf("hola3\n");
          //printf("suivant = %c\n", ((cont->root)->suite_idf[i])->lettre);
      }
      else if(i >=26 && i < 52){
          //printf("hola4\n");
          noeud->lettre = (i-26) + 'A';
          //printf("hola5\n");
          //printf("suivant = %c\n", ((cont->root)->suite_idf[i])->lettre);
      }
      else if(i >=52 && i < 62){
          //printf("hola6\n");
          noeud->lettre = (i-52) + '0';
          //printf("hola7\n");
          //printf("suivant = %c\n", (cont->root)->suite_idf[i]->lettre);
      }
      else // i = 63
      {
          //printf("hola8\n");
          noeud->lettre = '_';
          //printf("hola9\n");
      }
      //(noeud->suite_idf[i])->idf_existant = false;
      //((cont->root)->suite_idf[i])->suite_idf = NULL;
      //(noeud->suite_idf[i])->data = NULL;
      //printf("fin i %d\n", i);
  }
  noeud->data = NULL;
  return noeud;
}

void free_noeud(noeud_t noeud) //free recursif d'un noeud_t
{
    for(int i = 0; i < NB_ELEM_ALPHABET; i++)
    {
        if(noeud->suite_idf[i])
        {
            //printf("noeud->suite_idf[%d]\n", i);
            free_noeud(noeud->suite_idf[i]);
        }
    }
    noeud->data = NULL;
    free(noeud);
}

void free_context(context_t context) // liberer la memoire allouée pour le contexte
{
    // parcourir le contexte pour tout liberer
    //(context->root)->idf_existant = false;
    //printf("avant for\n");
    free_noeud(context->root);
    /*for(int i = 0; i < NB_ELEM_ALPHABET; i++)
    {
        free((context->root)->suite_idf[i]);
    }*/
    //printf("free(suite_idf[i])");
    //(context->root)->data = NULL;
    //free(context->root);
    free(context);
}

bool context_add_element(context_t context, char * idf, void * data)// ajoute l’as-
//sociation entre le nom idf et le noeud data dans le contexte context. Si le nom idf est
//déjà présent, l’ajout échoue et la fonction retourne false. Sinon, la fonction retourne true.
{

    //char c = idf[0];
    noeud_t nac = context->root;
    int idf_len = strlen(idf);
    //printf("RECURSIVITE\n");
    for(int i = 0; i < idf_len; i++)
    {
        printf("suite idf : %c %d\n" , idf[i], idf[i]-'a');
        for(int j = 0; j < 63; j++)
        { //VERIFICATION des noeuds déjà créés dans le noeud actuel
            if(nac->suite_idf[j])
                printf("nac->suite_idf[%d]\n", j);
        }
        if(!(nac->suite_idf[idf[i]-'a']))
        {
            nac->suite_idf[idf[i]-'a'] = init_noeud_context();
            printf("MALLOOOOOCCC\n");
        }
        nac = nac->suite_idf[idf[i]-'a'];
    }
    /*i=0;
    while( c != '\0')
    {
        printf("suite idf : %c\n" , c);
        nac = nac->suite_idf[c - 'a'];
        if(nac == NULL)
        {
            nac = malloc(sizeof(noeud_t));
            nac->idf_existant = false;
            printf("MALLOOOOOCCC\n");
        }
        c = idf[i];
        i++;
    }*/
    if( nac->idf_existant == true){
        return false;
    }
    else
    {
        nac->data = data;
        nac->idf_existant = true;
        return true;
    }

}

void * get_data(context_t context, char * idf)//retourne le noeud précédemment
//associé à idf dans context, ou null si idf n’existe pas dans context.
{
    noeud_t noeud = context->root;
    int i = 0, idf_len = strlen(idf);
    int car = idf[i] - 'a';
    // parcours de contextes à la chaine
    while(i < idf_len && noeud->suite_idf[car])
    {
        noeud = noeud->suite_idf[car];
        //printf("car=%c i=%d\n", car+'a', i);
        i++;
        car = idf[i] - 'a';
    }
    if(i < idf_len)
    {
        printf("idf non trouve\n");
        return NULL;
    }
    if (noeud->idf_existant == true)
    {
        printf("idf trouve !\n");
        return (context->root)->data;
    }
    return NULL;

}

int main(void)
{
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
    char *idf = "girafe";
    bool test = context_add_element(context, idf, data);
    if (test){printf("1er test ok\n");}
    bool test2 = context_add_element(context, idf, data);
    if(!test2){printf("2eme test ok\n");}
    //if(context_add_element(context, (void*)"girasol", data)) printf("3eme test ok\n");
    //printf("fini init context\n");
    char *test_data = get_data(context, idf);
    free_context(context);
    return 0;}
