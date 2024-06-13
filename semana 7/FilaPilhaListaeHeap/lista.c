#include <stdio.h>

// AULA GRAVADA SOBRE LISTA ENCADEADA:

/*

Vetores são de fácil acesso, mas seu custo computacional é alto.
É contínua na memória (Se precisar aumentar e não tiver espaço, tem que mover de lugar da memória e copiar todos elementos).
As listas encadeadas otimizam a alocação dinâmica da memória.
-> Mas é mais rápido acessar um elemento no meio de um vetor do que no meio da lista.

NODO: Elemento da lista encadeada.
Cada novo nodo precisa ser alocado na memória.
-> É mais fácil inserir no meio da lista do que no vetor.

A lista tem acesso irrestrito.
-> Pode inserir ou remover nodos em qualquer lugar da lista.

POP: Remover um nodo da lista.
PUSH: Colocar um nodo na lista.
-> Não é necessário deslocar ninguém que nem nos vetores.

O nodo é representado por uma STRUCT com dois campos:
-> Dado ou informação;
-> Um ponteiro para o próximo nodo da lista.

A lista é guardada na forma de ponteiro (link para o primeiro nó).

*/

// Implementação: 

    typedef struct{
        SDado info;
        struct SNodo *pNext;
    }SNodo;

    typedef struct{
        int cod;
        char nome[40];
        float preco;
    }SDado;

    typedef struct{
        SNodo *pFirst;
    }SLista;

/*

OBS: Essa ultima struct é denotada SENTINELA
Guarda informações de toda a struct, por exemplo, podemos ter um campo em SLista para contar o número de nodos da lista.
Uma estrutura sem sentinela usa apenas SDado e SLista.

Vantagens da implementação:
-> É possível incluir informações extras no nodo sem grandes modificações no código.

Sempre que excluir ou incluir algo, os ponteiros precisam ser atualizados.

No POP: if para ver se é o primeiro nodo que será excluido.
No PUSH: ifs para ver se o novo nodo está no começo, meio ou fim da lista.

*/

// Função RESET:

void Reset (SLista *pLista){

    Clear(pLista);

    pLista = (SLista *)malloc(sizeof(SLista));
}

// Implementando Clear:

void Clear (SLista *pLista){
    SNodo *current = pLista->pFirst;
    SNodo *nextNode;
    
    while (current != NULL) {
        nextNode = current->pNext;
        free(current);
        current = nextNode;
    }

    pLista->pFirst = NULL;

}

// Função PUSH:

int PUSH (SLista *pLista, SNodo *pNodo, unsigned int nIndex){
    SNodo *pAtual, *pAnterior;
    int nPos;
    if(pLista->pFirst == NULL && nIndex != 0){
        return 0;
    }
    else if(pLista->pFirst == NULL & nIndex == 0){
        pLista->pFirst = pNodo;
        pLista->pFirst->pNext = NULL;
        return 1;
    }
    else if(nIndex == 0){
        pNodo->pNext = pLista->pFirst;
        pLista->pFirst = pNodo;
    }

    // Se os ifs anteriores derem falso, será adicionado um elemento no meio da lista, portanto:

    pAtual = pLista->pFirst;
    for(int nPos = 0; nPos <= nIndex && pAtual != NULL; nPos++){
        pAnterior = pAtual;
        pAtual = pAtual->pNext;
    }
    if(!pAtual) return 0;

    pNodo->pNext = pAtual;
    pAnterior->pNext = pNodo;

    return 1;
}

// Função POP:

int POP(SLista *pLista, SNodo *pNodo, unsigned int nIndex){
    
    SNodo *pAnterior, *pAtual;
    int nPos;

    if(pLista->pFirst == NULL) return 0;
    if(nIndex == 0){
        pNodo = pLista->pFirst;
        pLista->pFirst = pLista->pFirst->pNext;
        return 1;
    }

    // Se os ifs deram falso, o elemento a ser retirado está no meio da lista.

    pAtual = pLista->pFirst;
    for(int nPos = 0; nPos < nIndex && pAtual != NULL; nPos++){
        pAnterior = pAtual;
        pAtual = pAtual->pNext;
    }

    if(!pAtual) return 0;

    pAnterior->pNext = pAtual->pNext;
    pNodo = pAtual;

    return 1;
    
}


// Link do vídeo extra para assistir depois: https://www.youtube.com/watch?v=t5NszbIerYc&ab_channel=Computerphile
