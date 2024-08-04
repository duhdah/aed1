#include <stdio.h>
#include <stdlib.h>

// Escrevendo as funções dos slides de árvores para assimilar o código:
// Coloquei as funções de imprimir e o main para testar

// Essa não é uma árvore balanceada

typedef struct Nodo {
    int reg;
    struct Nodo *left;
    struct Nodo *right;
} nodo;

nodo *Pesquisa(int x, nodo *p);
void Insere (int x, nodo **p);
void Retira (int x, nodo **p);
void Antecessor (nodo *q, nodo **r);
void ImprimePreOrdem(nodo *p);
void ImprimePosOrdem(nodo *p);
void ImprimeOrdemCentral(nodo *p);   

int main(){
    nodo *arvore = NULL;

    int reg1, reg2, reg3, reg4, reg5, reg6;
    reg1 = 6; 
    reg2 = 8; 
    reg3 = 2; 
    reg4 = 1; 
    reg5 = 4; 
    reg6 = 3; 

    Insere(reg1, &arvore);
    Insere(reg2, &arvore);
    Insere(reg3, &arvore);
    Insere(reg4, &arvore);
    Insere(reg5, &arvore);
    Insere(reg6, &arvore);

    printf("Impressao em pre-ordem: ");
    ImprimePreOrdem(arvore);
    printf("\n");

    printf("Impressao em ordem central: ");
    ImprimeOrdemCentral(arvore);
    printf("\n");

    printf("Impressao em pos-ordem: ");
    ImprimePosOrdem(arvore);
    printf("\n");

    return 0;
}

// Recursiva: Chama a própria função até encontrar o registro ou NULL
nodo *Pesquisa(int x, nodo *p){
    if (p == NULL){
        printf("Erro: Registro nao esta presente na arvore! \n");
        return NULL;
    }
    if (x < p->reg){
        return Pesquisa(x, p->left);
    }
    if (x > p->reg){
        return Pesquisa(x, p->right);
    }
    return p;
}

// Recursiva: Chama a Insere até encontrar NULL, ou seja, a posição onde deve inserir.
// Não pode inserir o mesmo registro, então se o valor não for menor nem maior, será igual e não insere.
void Insere (int x, nodo **p){
    if(*p == NULL){
        *p = (nodo *)malloc(sizeof(nodo));
        (*p)->reg = x;
        (*p)->left = NULL;
        (*p)->right = NULL;
        return;
    }
    if (x < (*p)->reg){
        Insere(x,&(*p)->left);
        return;
    }
    else if(x > (*p)->reg){
        Insere(x,&(*p)->right);
        return;
    }
    else{
        printf("Erro: Registro ja existe na arvore!");
    }
}

// Se p for NULL, o registro não está na árvore e não tem como remover
// Enquanto o valor for maior ou menor que o do nó comparado, não é igual e continua buscando
// Se ele não é NULL, menor ou maior, vai ser igual. Daí só falta remover o nó. 
// Se ele só tem um filho, vai ser substituído pelo filho.  
void Retira (int x, nodo **p){
    nodo *Aux;
    if (*p == NULL){
        printf("Erro: Registro nao esta na arvore\n");
        return;
    }
    if (x < (*p)->reg){
        Retira(x,&(*p)->left);
        return;
    }
    if (x > (*p)->reg){
        Retira(x, &(*p)->right);
        return;
    }
    if((*p)->right == NULL){
        Aux = *p;
        *p = (*p)->left;
        free(Aux);
        return;
    }
    // observando a ordem:
    // se entra no if abaixo, é pq nem pEsq e nem pDir são nulos!
    if((*p)->left != NULL){
        Antecessor (*p, &(*p)->left);
        return;
    }
    // se pEsq for NULL e pDir não for:
    Aux = *p;
    *p = (*p)->right;
    free(Aux);
}

// Encontra o nó de maior valor na subárvore esquerda
// Passa o valor desse nó para q
// Remove o nó de maior valor
// **r é um nodo da subarvore esquerda
void Antecessor (nodo *q, nodo **r){
    nodo *aux;
    if((*r)->right != NULL){
        Antecessor(q, &(*r)->right);
        return;
    }
    q->reg = (*r)->reg;
    aux = *r;
    *r = (*r)->left;
    free(aux);
}

void ImprimePreOrdem(nodo *p) {
    if (p != NULL) {
        printf("%d ", p->reg);
        ImprimePreOrdem(p->left);
        ImprimePreOrdem(p->right);
    }
}

void ImprimeOrdemCentral(nodo *p) {
    if (p != NULL) {
        ImprimeOrdemCentral(p->left);
        printf("%d ", p->reg);
        ImprimeOrdemCentral(p->right);
    }
}

void ImprimePosOrdem(nodo *p) {
    if (p != NULL) {
        ImprimePosOrdem(p->left);
        ImprimePosOrdem(p->right);
        printf("%d ", p->reg);
    }
}