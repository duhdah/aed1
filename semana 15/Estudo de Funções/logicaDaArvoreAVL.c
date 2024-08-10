

// fiz anotações para compreender e lembrar das funções de uma árvore (desconsiderando o balanceamento)



// Struct: Deve ter o conteudo do nodo, o left e o right.

// Main: Deve inicializar a arvore como nodo *arvore = NULL;

// Pesquisa: tipo nodo*
    // verifica se o nodo é NULL, se for, não encontrou o valor
    // verifica se o valor buscado é menor que o do nodo atual, se for, vai pra esquerda
    // depois verifica se o valor buscado é maior que o do nodo atual, se for, vai pra direita
    // se não for maior nem menor, é igual, retorna o nodo atual.
    // recursão: Pesquisa(x, p->left);

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int val;
    struct Nodo *left;
    struct Nodo *right;
}nodo;

nodo *Pesquisa (nodo *p, int x){
    if(p == NULL){
        printf("Nodo nao encontrado.");
        return NULL;
    }
    if(x < p->val){
        return Pesquisa(p->left,x);
    }
    if(x > p->val){
        return Pesquisa(p->right,x);
    }
    return p;
}

// Insere: tipo void
    // verifica se o nodo é NULL, se for, dá malloc e insere
    // verifica se o valor do nodo a ser inserido é menor que o do nodo atual, se for, chama insere pra esquerda
    // verifica se o valor do nodo a ser inserido é menor que o do nodo atual, se for, chama insere pra direita
    // recursão: Insere(x,&(*p)->right);

void Insere(nodo **p, int x){
    if((*p) == NULL){
        (*p) = (nodo *)malloc(sizeof(nodo));
        (*p)->val = x;
        (*p)->left = NULL;
        (*p)->right = NULL;
        return;
    }
    if(x < (*p)->val){
        return Insere(&(*p)->left,x);
    }
    if(x > (*p)->val){
        return Insere(&(*p)->right,x);
    }
    printf("Erro: O nodo ja esta na arvore");
    return;
}

// Remove: tipo void
    // verifica se o nodo é NULL, se for, não encontrou o valor
    // verifica se o valor do nodo a ser inserido é menor que o do nodo atual, se for, chama remove pra esquerda 
    // verifica se o valor do nodo a ser inserido é maior que o do nodo atual, se for, chama remove pra direita 
    // verifica se o right é NULL, e se for, aux = p, p = p->left e free(aux)
    // verifica se o left é diferente de NULL, e se for, chama Antecessor (remove maior nodo da subarvore esquerda)
    // se não entrar em nenhum if, no final aux = p, p = p->right e free(aux)

void Remove(nodo **p, int x){
    nodo *aux;
    if((*p) == NULL){
        printf("O nodo nao foi encontrado na arvore.");
        return;
    }
    if(x < (*p)->val){
        return Remove(&(*p)->left,x);
    }
    if(x > (*p)->val){
        return Remove(&(*p)->right,x);
    }
    if((*p)->right == NULL){
        aux = *p;
        *p = (*p)->left;
        free(aux);
        return;
    }
    if((*p)->left != NULL){
        Antecessor(*p, &(*p)->left);
        return;
    }
    aux = *p;
    *p = (*p)->right;
    free(aux);
    return;
}


// Antecessor: tipo void
    // recebe como parâmetro um nodo em que vai salvar o nodo removido e um nodo da subarvore esquerda
    // busca o maior valor da subarvore esquerda e remove ele
    // aux = p, p = p->left, free(p)

void Antecessor(nodo *p, nodo **q){
    nodo *aux;
    if((*q)->right != NULL){
        return Antecessor(p,&(*q)->right);
    }
    p->val = (*q)->val;
    aux = *q;
    *q = (*q)->left;
    free(aux);
    return;
}

// Imprime: tipo void
    // é o mesmo codigo para as tres ordens, o que muda é onde fica o printf
    // Na pre-ordem, fica aqui
    // Imprime(p->left);
    // Na ordem central, fica aqui
    // Imprime(p->right);
    // Na pos-ordem, fica aqui

void Imprimir(nodo *p){
    if(p != NULL){
        // printf("%d ",p->val); PRE ORDEM
        if(p->left) Imprimir(p->left);
        // printf("%d ",p->val); ORDEM CENTRAL
        if(p->right) Imprimir(p->right);
        // printf("%d ",p->val); POS ORDEM
    }
}


// FB: int
// Calcula o fator de balanceamento de p (altura da subarvore esquerda - direita) chamando Altura
int FB(nodo *p){
    if(p == NULL) return 0;
    return Altura(p->left) - Altura(p->right);
} 

// Altura: int
// Calcula recursivamente a altura de uma subarvore
int Altura(nodo *p){
    if(p == NULL) return 0;
    int pEsq, pDir;
    pEsq = Altura(p->left);
    pDir = Altura(p->right);
    if(pEsq > pDir) return pEsq + 1;
    else return pDir + 1;
}

// RSE: void
// Recebe um nodo **p, troca ele e o seu filho direito de lugar e ajusta os filhos de acordo
void RSE(nodo **p){
    nodo *aux = (*p)->right;
    (*p)->right = aux->left;
    aux->left = *p;
    (*p) = aux;

}

// RSD: void
// Recebe um nodo **p, troca ele e o seu filho esquerdo de lugar e ajusta os filhos de acordo
void RSD(nodo **p){
    nodo *aux = (*p)->left;
    (*p)->left = aux->right;
    aux->right = *p;
    (*p) = aux;
}

// BalancaEsquerda: void
// Calcula o FB da subarvore esquerda e efetua as rotações necessarias
void BalancaEsquerda(nodo **p){
    int fbe = FB((*p)->left);
    if(fbe>0){ // rotação simples a direita
        RSD(p);
    }
    if(fbe<0){ // rotação dupla a direita
        RSE(&(*p)->left);
        RSD(p);
    }
    return;
}

// BalancaDireita: void
// Calcula o FB da subarvore direita e efetua as rotações necessarias
void BalancaDireita(nodo **p){
    int fbd = FB((*p)->right);
    if(fbd<0){ // rotação simples a direita
        RSE(p);
    }
    else if(fbd>0){ // rotação dupla a direita
        RSD(&(*p)->right);
        RSE(p);
    }
    return;
}

// Balanceamento: void
// Verifica o FB da arvore e chama BalancaDireita ou BalancaEsquerda conforme necessario
void Balanceamento(nodo **p){
    int fb = FB(*p);
    if(fb > 1){
        return BalancaEsquerda(*p);
    }
    if(fb < -1){
        return BalancaDireita(*p);
    }
}

// EhArvoreAVL: int
// Verifica o FB da arvore e retorna se ela está balanceada
int EhArvoreAVL(nodo *p){
    if (p == NULL) return 1;
    int fb;
    if(!EhArvoreAVL(p->left)) return 0;
    if(!EhArvoreAVL(p->right)) return 0;
    fb = FB(p);
    if(fb > 1 || fb < -1) return 0;
    else return 1;
}

// Inserção: Mesma coisa, mas testar se a inserção funcionou e chamar Balanceamento a cada inserção.

int Insere (int x, nodo **p){
    if(*p == NULL){
        *p = (nodo *)malloc(sizeof(nodo));  
        (*p)->reg = x;
        (*p)->left = NULL;
        (*p)->right = NULL;
        return 1;
    }else if ((*p)->reg > x){
        if (Insere(x, &(*p)->left)){
            Balanceamento(p);
            return 1;
        }
    } else if ((*p)->reg < x){
        if (Insere(x, &(*p)->right)){
            Balanceamento(p);
            return 1;
        }
    }
    return 0; // valor já presente
}