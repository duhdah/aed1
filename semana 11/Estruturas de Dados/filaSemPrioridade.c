
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct STipoFila{
    int info;
    struct STipoFila *next;
}STipoFila;

typedef struct SFila{
    STipoFila *pFirst;
    STipoFila *pLast;
}SFila;

void Reset(SFila *fila);
void Clear(SFila *fila);
bool Empty(SFila *fila);
bool Push(SFila *fila, int num);
int Pop (SFila *fila);
void Listar (SFila *fila);

int main(){
    SFila *fila = (SFila *)malloc(sizeof(SFila));
    Reset(fila);
    Push(fila,1);
    Push(fila,2);
    Push(fila,3);
    Pop(fila);    
    Listar(fila);
    Clear(fila);
    return 0;
}

void Reset(SFila *fila){
    //if(!Empty(fila)) Clear(fila); nao ta funcionando
    fila->pFirst = NULL;
    fila->pLast = NULL;
}

void Clear(SFila *fila){
    if(!fila){
        printf("A fila ja esta vazia.");
    }else{
        while(!Empty(fila)){
            Pop(fila);
        }
    }
}   

bool Empty(SFila *fila){
    return fila->pFirst == NULL;
}

bool Push(SFila *fila, int num){
    STipoFila *nodo = (STipoFila *)malloc(sizeof(STipoFila));
    nodo->info = num;
    nodo->next = NULL;
    if(fila->pLast!=NULL){
        fila->pLast->next = nodo;
    }else{
        fila->pFirst = nodo;
    }
    fila->pLast = nodo;
    return true;
}

int Pop (SFila *fila){
    if(Empty(fila)) return false;
    int n;
    n = fila->pFirst->info;
    STipoFila *inicio = fila->pFirst;
    fila->pFirst = fila->pFirst->next;
    if(fila->pFirst == NULL) fila->pLast = NULL; 
    free(inicio);
    return n;
}

// imprime do primeiro ao ultimo
void Listar(SFila *fila) {
    STipoFila *temp = fila->pFirst;
    while (temp) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
}