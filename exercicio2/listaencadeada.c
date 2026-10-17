#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct lista{
    char* str;
    struct lista* prox;
};
typedef struct lista Lista;

Lista* retira(Lista* l, char* n);
Lista* insere_ordenado(Lista* l, char* n);
void imprime_lista(Lista* l);

int main(void) {
    Lista* l = NULL;

    l = insere_ordenado(l, "sol");
    l = insere_ordenado(l, "casa");
    l = insere_ordenado(l, "lua");

    // Imprimir a lista
    imprime_lista(l);

    l = retira(l, "casa");

    imprime_lista(l);

    return 0;
}



Lista* retira(Lista* l, char* n){
    Lista* ant= NULL;
    Lista* p=l;
    while (p!=NULL)
    {
        if (!strcmp(p->str, n))
        {
            if(ant==NULL){
                l=p->prox;
                free(p);
                p=l;
            }
            else{
                ant->prox=p->prox;
                free(p);
                p=ant->prox;
            }
        }
        else{
            ant=p;
            p=p->prox;
        }
        
    }
    return l;
}
Lista* insere_ordenado(Lista* l, char* n){
    Lista* novo=malloc(sizeof(Lista));
    novo->str=n;
    novo->prox=NULL;
    Lista* p=l;
    if(l==NULL || strcmp(n,  l->str)<0){
        novo->prox=l;
        l=novo;
    }
    else{
        while(p->prox!=NULL && strcmp(n, p->prox->str)>0){
            p=p->prox;
        }
        novo->prox=p->prox;
        p->prox=novo;
    }
    return l;
}
void imprime_lista(Lista* l){
    Lista* p=l;
    while(p!=NULL){
        printf("[%s]-> ", p->str);
        p=p->prox;
    }
    printf("NULL\n");
}