#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "context.h"

context_t create_context() // cree un contexte et lui alloue de la mémoire
{
    context_t cont = malloc(sizeof(context_t));
    if (cont == NULL)
    {
        //printf("il y a eu un problème dans la création d'un contexte\n");
    }
    cont->root = malloc(sizeof(noeud_t));
    (cont->root)->idf_existant == false;
    for(int i = 0; i < NB_ELEM_ALPHABET; i++)
    {
        (cont->root)->suite_idf[i] = malloc(sizeof(noeud_t));
        if(i >= 0 && i < 26)
        {
            ((cont->root)->suite_idf[i])->lettre = i + 'a';
            //printf("suivant = %c\n", ((cont->root)->suite_idf[i])->lettre);
        }
        else if(i >=26 && i < 52){
            ((cont->root)->suite_idf[i])->lettre = (i-26) + 'A';
            //printf("suivant = %c\n", ((cont->root)->suite_idf[i])->lettre);
        }
        else if(i >=52 && i < 62){
            ((cont->root)->suite_idf[i])->lettre = (i-52) + '0';
            //printf("suivant = %c\n", (cont->root)->suite_idf[i]->lettre);
        }
        else // i = 63
        {
            ((cont->root)->suite_idf[i])->lettre = '_';
        }
        ((cont->root)->suite_idf[i])->idf_existant == false;
        //((cont->root)->suite_idf[i])->suite_idf = NULL;
        ((cont->root)->suite_idf[i])->data == NULL;
    }
    (cont->root)->lettre = 0;
    (cont->root)->data = NULL;
    return cont;
}

void free_context(context_t context) // liberer la memoire allouée pour le contexte
{
    // parcourir le contexte pour tout liberer
    (context->root)->idf_existant == false;
    //printf("avant for\n");
    for(int i = 0; i < NB_ELEM_ALPHABET; i++)
    {
        //printf("boucle for free, avec i=%d\n", i);
/*
        if(i >= 0 && i < 26)
        {
            (context->root)->suite_idf[i]->lettre = 0;
            (context->root)->suite_idf[i]->idf_existant == false;
        }
        else if(i >=26 && i < 52){
            (context->root)->suite_idf[i]->lettre = 0;
            (context->root)->suite_idf[i]->idf_existant == false;
        }
        else if(i >=52 && i < 62){
            (context->root)->suite_idf[i]->lettre = 0;
            (context->root)->suite_idf[i]->idf_existant == false;
        }
        else // i = 63
        {
            (context->root)->suite_idf[i]->lettre = 0;
            (context->root)->suite_idf[i]->idf_existant == false;
        }*/
        //free((context->root)->suite_idf[i]);

    }
    //printf("free(suite_idf[i])");
    (context->root)->data = NULL;
    (context->root)->lettre = 0;
    free(context->root);
    free(context);
}

bool context_add_element(context_t context, char * idf, void * data)// ajoute l’as-
//sociation entre le nom idf et le noeud data dans le contexte context. Si le nom idf est
//déjà présent, l’ajout échoue et la fonction retourne false. Sinon, la fonction retourne true.
{

    char c = idf[0];
    noeud_t nac = (context->root);//->suite_idf[c - 'a'];
    int i = 1;
    printf("recursivite\n");
    while( c != '\0')
    {
        printf("suite idf : %c\n" , c);
        nac = nac->suite_idf[c - 'a'];
        if(nac == NULL)
        {
            nac = malloc(sizeof(noeud_t));
            printf("MALLOOOOOCCC\n");
        }
        c = idf[i];
        i++;
    }
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
    // parcours de contextesà la chaine?
    if ((context->root)->idf_existant == true)
    {
        return (context->root)->data;
    }
    return NULL;

}

int main(void)
{
    //printf("hello context\n");
    context_t context = create_context();
    char * data = "patate";
    char*idf = "girafe";
    bool test = context_add_element(context, idf, data);
    if (test){printf("1er test ok\n");}
    bool test2 = context_add_element(context, idf, data);
    if(!test2){printf("2eme test ok\n");}
    //printf("fini init context\n");
    free_context(context);
    return 0;}
