#include <stdio.h>
#include <stdlib.h>

typedef struct SNodo{
    int info;
    struct SNodo *prox;
}SNodo;

typedef struct SLista{
    struct SNodo *head;
    int tamanho;
}SLista;

void adicionaInicio(SLista *lista, int num);
void adicionaFim(SLista *lista, int num);
void adicionaPos(SLista *lista, int pos, int num);
void removeInicio(SLista *lista);
void removeFim(SLista *lista);
void removePosicao(SLista *lista, int pos);
void imprimir (SLista *lista);

int main(){

    SLista *lista;
    lista = (SLista *)malloc(sizeof(SLista));
    lista->head = (SNodo *)malloc(sizeof(SNodo));
    lista->head->prox = NULL;
    lista->tamanho = 0;

    imprimir(lista);
    adicionaInicio(lista,2);
    imprimir(lista);
    adicionaInicio(lista,1);
    imprimir(lista);
    adicionaFim(lista,3);
    imprimir(lista);
    adicionaPos(lista,2,2);
    imprimir(lista);
    removeInicio(lista);
    imprimir(lista);
    removeFim(lista);
    imprimir(lista);
    adicionaFim(lista,4);
    adicionaFim(lista,5);
    adicionaFim(lista,6);
    imprimir(lista);
    removePosicao(lista,3);
    imprimir(lista);
    free(lista);
    return 0;
}

void adicionaInicio(SLista *lista, int num){
    SNodo *novo = (SNodo *)malloc(sizeof(SNodo));
    novo->prox = lista->head->prox;
    lista->head->prox = novo;
    novo->info = num;
    lista->tamanho++;
}   

void adicionaFim(SLista *lista, int num){
    SNodo *novo = (SNodo *)malloc(sizeof(SNodo)), *p;
    int i = 0;
    p = lista->head;
    while(i<lista->tamanho){
        p = p->prox;
        i++;
    }
    p->prox = novo;
    novo->prox = NULL;
    novo->info = num;
    lista->tamanho++;
}

void adicionaPos(SLista *lista, int pos, int num){
    if(lista->tamanho-1 < pos){
        printf("A lista nao e longa o suficiente.\n");
    }else if(pos < 0){
        printf("Posicao invalida.\n"); 
    }else{
        SNodo *novo, *p;
        novo = (SNodo *)malloc(sizeof(SNodo));
        int i = 0;
        p = lista->head;
        while(i<pos){
            p = p->prox;
            i++;
        }
        novo->prox = p->prox;
        p->prox = novo;
        novo->info = num;
        lista->tamanho++;
    }
}

void removeInicio(SLista *lista){
    if(lista->head->prox == NULL){
        printf("Lista vazia.");
    }else{
        SNodo *p = lista->head->prox;
        lista->head->prox = p->prox;
        free(p);
        lista->tamanho--;
    }
}

void removeFim(SLista *lista){
    if(lista->head->prox == NULL){
        printf("Lista vazia.");
    }else if(lista->tamanho == 1){
        SNodo *p = lista->head->prox;
        lista->head->prox = NULL;
        free(p);
    }
    else{
        SNodo *pAnterior = lista->head, *p;
        int i = 0;
        while(i<lista->tamanho-1){ // pega o penultimo
            pAnterior = pAnterior->prox;
            i++;
        }
        p = pAnterior->prox;
        pAnterior->prox = p->prox;
        free(p);
        lista->tamanho--;
    }
}

void removePosicao(SLista *lista, int pos){
    if(lista->tamanho-1 < pos){
        printf("A lista nao e longa o suficiente.\n");
    }else if(pos < 0){
        printf("Posicao invalida.\n"); 
    }else{
        SNodo *pAnterior = lista->head, *p;
        int i = 0;
        while(i<pos-1){ // pega o penultimo
            pAnterior = pAnterior->prox;
            i++;
        }
        p = pAnterior->prox;
        pAnterior->prox = p->prox;
        free(p);
        lista->tamanho--;
    }
}

void imprimir (SLista *lista){
    if(lista->head->prox == NULL){
        printf("A lista esta vazia.\n");
    }else{
        printf("///////////////////\n");
        int i = 0;
        SNodo *p = lista->head->prox;
        while(i<lista->tamanho){
            printf("Elemento %d: %d\n",i+1,p->info);
            p = p->prox;
            i++;
        }
    }
}