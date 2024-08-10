#include <stdio.h>
#include <stdlib.h>

// Testando se a árvore é balanceada corretamente

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
int FB (nodo *p);
int Altura(nodo *p);
void RSE(nodo **p);
void RSD(nodo **p);
void BalancaEsquerda(nodo **p);
void BalancaDireita(nodo **p);
void Balanceamento(nodo **p);
int EhArvoreAVL(nodo *p);

int main(){
    nodo *raiz = NULL;
    Insere(10, &raiz);
    Insere(20, &raiz);
    Insere(5, &raiz);
    Insere(6, &raiz);
    Insere(15, &raiz);
    Insere(7, &raiz); // RSE
    Insere(17, &raiz); // RDD

    ImprimeOrdemCentral(raiz); // testando o balanceamento (RSD)

    return 0;
}
    /*nodo *arvore = NULL;

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

    return 0;*/


int FB (nodo *p){
    if(p == NULL){
        return 0;
    }
    return Altura(p->left) - Altura(p->right);
}

int Altura(nodo *p){
    int iEsq, iDir;
    if(p == NULL){
        return 0;
    }
    iEsq = Altura(p->left);
    iDir = Altura(p->right);
    if(iEsq > iDir) return iEsq + 1;
    else return iDir + 1;
}

// CASOS DE BALANCEAMENTO:
/*

Caso 1: Rotação simples pra direita
    FB > 1 (Subarvore esquerda > Direita)
    Subarvore esquerda da subarvore esquerda é maior que a subarvore direita dela
    
Caso 2: Rotação simples pra esquerda
    FB < -1 (Subarvore esquerda < Direita)
    Subarvore direita da subarvore direita é maior que a subarvore esquerda dela

Caso 3: Rotação dupla pra direita
    FB > 1 (Subarvore esquerda > Direita)
    Subarvore esquerda da subarvore esquerda é menor ou igual a subarvore direita dela
    
Caso 4: Rotação dupla pra esquerda
    FB < -1 (Subarvore esquerda < Direita)
    Subarvore direita da subarvore direita é menor ou igual a subarvore esquerda dela
    */

void RSE(nodo **p){
    nodo *aux;
    aux = (*p)->right; // aux recebe o que está a direita de p
    (*p)->right = aux->left; // o nodo a direita de p recebe o nodo a esquerda de aux
    aux->left = (*p); // o nodo a esquerda de aux recebe p
    (*p) = aux; // p recebe aux 
}

void RSD(nodo **p){
    nodo *aux;
    aux = (*p)->left;
    (*p)->left = aux->right;
    aux->right = (*p);
    (*p) = aux; 
}

void BalancaEsquerda(nodo **p){
    int fbe = FB((*p)->left);
    if (fbe>0){
        printf("Rotacao simples para a direita.\n");
        RSD(p);
        return;
    }else if(fbe < 0){
        printf("Rotacao dupla para a direita.\n");
        // rotação dupla direita
        RSE(&((*p)->left));
        RSD(p); // &(*p)->raiz
        return;
    }
    return;
}

void BalancaDireita(nodo **p){
    int fbe = FB((*p)->right);
    if (fbe < 0){
        printf("Rotacao simples para a esquerda.\n");
        RSE(p);
        return;
    }else if(fbe > 0){
        printf("Rotacao dupla para a esquerda.\n");
        RSD(&((*p)->right));
        RSE(p); // &(*p)->raiz
        return;
    }
    return;
}

void Balanceamento(nodo **p){
    int fb = FB(*p);
    if(fb>1)
        return BalancaEsquerda(p);
    else if(fb<-1)
        return BalancaDireita(p);
    else
        return;
}

int EhArvoreAVL(nodo *p){
    int fb;
    if(p == NULL) return 1;
    if(!EhArvoreAVL(p->left)) return 0;
    if(!EhArvoreAVL(p->right)) return 0;
    fb = FB(p);
    if((fb>1) || (fb<-1)) return 0;
    else return 1;
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
    else if((*p)->reg > x){
        Insere(x,&(*p)->left);
        Balanceamento(p);
        return;
    }
    else if((*p)->reg < x){
        Insere(x,&(*p)->right);
        Balanceamento(p);
        return;
    }
    return; // valor já presente
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