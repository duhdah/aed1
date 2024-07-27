#include <stdio.h>
#include <stdlib.h>

// Escrevendo as funções dos slides de árvores para assimilar o código:
// Coloquei as funções de imprimir e o main para testar

typedef long TipoChave;

typedef struct Registro {
    TipoChave Chave;
    // outros componentes
} Registro;

typedef struct No *Apontador;

typedef struct No {
    Registro Reg;
    Apontador pEsq, pDir;
} No;

void Pesquisa(Registro *x, Apontador p);
void Insere (Registro x, Apontador *p);
void Inicializa(Apontador *Dicionario);
void Retira (Registro x, Apontador *p);
void Antecessor (Apontador q, Apontador *r);
void ImprimePreOrdem(Apontador p);
void ImprimePosOrdem(Apontador p);
void ImprimeOrdemCentral(Apontador p);   

int main(){
    Apontador arvore;
    Inicializa(&arvore);

    Registro reg1, reg2, reg3, reg4, reg5, reg6;
    reg1.Chave = 6; 
    reg2.Chave = 8; 
    reg3.Chave = 2; 
    reg4.Chave = 1; 
    reg5.Chave = 4; 
    reg6.Chave = 3; 

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
void Pesquisa(Registro *x, Apontador p){
    if (p == NULL){
        printf("Erro: Registro nao esta presente na arvore! \n");
        return;
    }
    if (x->Chave < p->Reg.Chave){
        Pesquisa(x, p->pEsq);
        return;
    }
    if (x->Chave > p->Reg.Chave)
        Pesquisa(x,p->pDir);
    else *x = p->Reg;   
}

// Recursiva: Chama a Insere até encontrar NULL, ou seja, a posição onde deve inserir.
// Não pode inserir o mesmo registro, então se o valor não for menor nem maior, será igual e não insere.
void Insere (Registro x, Apontador *p){
    if(*p == NULL){
        *p = (Apontador)malloc(sizeof(No));
        (*p)->Reg = x;
        (*p)->pEsq = NULL;
        (*p)->pDir = NULL;
        return;
    }
    if (x.Chave < (*p)->Reg.Chave){
        Insere(x,&(*p)->pEsq);
        return;
    }
    if(x.Chave > (*p)->Reg.Chave)
        Insere(x,&(*p)->pDir);
    else
        printf("Erro: Registro ja existe na arvore!");
}

// Só inicializa, torna a árvore vazia
void Inicializa(Apontador *Dicionario){
    *Dicionario = NULL;
}

// Se p for NULL, o registro não está na árvore e não tem como remover
// Enquanto o valor for maior ou menor que o do nó comparado, não é igual e continua buscando
// Se ele não é NULL, menor ou maior, vai ser igual. Daí só falta remover o nó. 
// Se ele só tem um filho, vai ser substituído pelo filho.  
void Retira (Registro x, Apontador *p){
    Apontador Aux;
    if (*p == NULL){
        printf("Erro: Registro nao esta na arvore\n");
        return;
    }
    if (x.Chave < (*p)->Reg.Chave){
        Retira(x,&(*p)->pEsq);
        return;
    }
    if (x.Chave > (*p)->Reg.Chave){
        Retira(x, &(*p)->pDir);
        return;
    }
    if((*p)->pDir == NULL){
        Aux = *p;
        *p = (*p)->pEsq;
        free(Aux);
        return;
    }
    // observando a ordem:
    // se entra no if abaixo, é pq nem pEsq e nem pDir são nulos!
    if((*p)->pEsq != NULL){
        Antecessor (*p, &(*p)->pEsq);
        return;
    }
    // se pEsq for NULL e pDir não for:
    Aux = *p;
    *p = (*p)->pDir;
    free(Aux);
}

// Encontra o nó de maior valor na subárvore esquerda
// Passa o valor desse nó para q
// Remove o nó de maior valor
void Antecessor (Apontador q, Apontador *r){
    Apontador aux;
    if((*r)->pDir != NULL){
        Antecessor(q, &(*r)->pDir);
        return;
    }
    q->Reg = (*r)->Reg;
    aux = *r;
    *r = (*r)->pEsq;
    free(aux);
}

void ImprimePreOrdem(Apontador p) {
    if (p != NULL) {
        printf("%ld ", p->Reg.Chave);
        ImprimePreOrdem(p->pEsq);
        ImprimePreOrdem(p->pDir);
    }
}

void ImprimeOrdemCentral(Apontador p) {
    if (p != NULL) {
        ImprimeOrdemCentral(p->pEsq);
        printf("%ld ", p->Reg.Chave);
        ImprimeOrdemCentral(p->pDir);
    }
}

void ImprimePosOrdem(Apontador p) {
    if (p != NULL) {
        ImprimePosOrdem(p->pEsq);
        ImprimePosOrdem(p->pDir);
        printf("%ld ", p->Reg.Chave);
    }
}