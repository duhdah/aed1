// treinando fazer pilha mais uma vez

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Pilha{
    int topo;
    int base;
    int limite;
    int elementos[10];
}pilha;


void Reset(pilha *p, int lim);
bool Empty(pilha *p);
bool Full(pilha *p);
bool Push(pilha *p, int elemento);
void Pop (pilha *p, int *valor);
void Listar (pilha *p);

int main(){
    pilha *p;
    p = (pilha *)malloc(sizeof(pilha));
    int valor;
    Reset(p, 10);
    Push(p, 10);
    Push(p, 5);
    Push(p, 2);
    Pop(p, &valor);
    Listar(p);
    return 0;
}

void Reset(pilha *p, int lim){
    p->topo = 0;  
    p->base = 0;
    p->limite = lim;    
}

bool Empty(pilha *p){
    return p->topo == 0;
}

bool Full(pilha *p){
    return p->limite == p->topo;
}

bool Push(pilha *p, int elemento){
    if(Full(p)){
        printf("A pilha esta cheia!");
        return false;
    }else{
        p->elementos[p->topo] = elemento;
        p->topo++;
        return true;
    }
}

void Pop (pilha *p, int *valor){
    if(Empty(p)){
        printf("A pilha esta vazia!");
    }else{
        p->topo--;
        *valor = p->elementos[p->topo];
    }
}

void Listar (pilha *p){
    pilha *auxiliar;
    auxiliar = p;
    while(!Empty(auxiliar)){
        int valor;
        Pop(auxiliar,&valor);
        printf("Elemento %d: %d",auxiliar->topo,valor);
    }
}