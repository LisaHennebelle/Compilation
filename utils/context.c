#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "context.h"

context_t create_context() // cree un contexte et lui alloue de la mémoire
{
    context_t cont = malloc(sizeof(context_t));
    if (cont == NULL)
    {
        printf("il y a eu un problème dans la création d'un contexte\n");
    }
    (context->root)->idf_existant == false;
    //(cont->root)->suite_idf = NULL;
    for(int i = 0; i < NB_ELEM_ALPHABET; i++)
    {
        (control->root)->suite_idf[i] = malloc(sizeof(_noeud_s));
        if(i >= 0 && i < 26)
        {
            (control->root)->suite_idf[i]->lettre = i + 'a';
            printf("suivant = %c\n", (control->root)->suite_idf[i]->lettre);
        }
        else if(i >=26 && i < 52){
            (control->root)->suite_idf[i]->lettre = (i-26) + 'A';
            printf("suivant = %c\n", (control->root)->suite_idf[i]->lettre);
        }
        else if(i >=52 && i < 62){
            (control->root)->suite_idf[i]->lettre = (i-52) + '0';
            printf("suivant = %c\n", (control->root)->suite_idf[i]->lettre);
        }
        else // i = 63
        {
            (control->root)->suite_idf[i]->lettre = '_';
        }

    }
    (cont->root)->lettre = NULL;
    (cont->root)->data = NULL;
    return cont;
}

void free_context(context_t context) // liberer la memoire allouée pour le contexte
{
    // parcourir le contexte pour tout liberer
    (context->root)->idf_existant == false;
    for(int i = 0; i < NB_ELEM_ALPHABET; i++)
    {
        free((context->root)->suite_idf[i]);
    }
    (context->root)->data = NULL;
    (context->root)->lettre = NULL;
    free(context);
}

bool context_add_element(context_t context, char * idf, void * data)// ajoute l’as-
//sociation entre le nom idf et le noeud data dans le contexte context. Si le nom idf est
//déjà présent, l’ajout échoue et la fonction retourne false. Sinon, la fonction retourne true.
{
    //parcours des contextes à la chaine?
    if ((context->root)->idf_existant == true){
        return NULL;
    }
    else
    {
        (context->root)->idf = idf;
        (context->root)->data = data;
    }

}

void * get_data(context_t context, char * idf)//retourne le noeud précédemment
//associé à idf dans context, ou null si idf n’existe pas dans context.
{
    // parcours de contextesà la chaine?
    if (strcmp((context->root)->idf,idf) == 0)
    {
        return (context->root)->data;
    }
    return NULL;

}
