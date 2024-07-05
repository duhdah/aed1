
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct STipoFila{
    int info;
    STipoFila *next;
}STipoFila;

typedef struct SFila{
    STipoFila *pFirst;
    STipoFila *pLast;
}SFila;

SFila *Reset(SFila *fila);
void *Clear(SFila *fila);
bool Empty(SFila *fila);
bool Push(SFila *fila, int num);
void Pop (SFila *fila, int *valor);
void Listar (SFila *fila);

int main(){
    SFila *fila;
    fila = Reset(fila);

}

SFila *Reset(SFila *fila){
    if(fila){
        Clear(fila);
    }
    SFila *novaFila;
    novaFila = (SFila *)malloc(sizeof(SFila));
    novaFila->pFirst = NULL;
    novaFila->pLast = NULL;
    return novaFila;
}

void *Clear(SFila *fila){
    if(!fila){
        printf("A fila ja esta vazia.");
    }else{
        while(fila){
            Pop(fila);
        }
    }
}   