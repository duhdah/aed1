#include <stdio.h>

// Faz uma busca binaria e tenta manter a árvore balanceada que nem o AVL
// Ele tenta manter a árvore balanceada (Não garante), por isso, o custo é menor, mas o desempenho é menor
    // É um algorismo heurístico (Não garante que está balanceada)
    // A AVL é determinística (Funciona)
    // A AVL tem que fazer mais rotações do que o rubro-negra.
    // Usa o rubro-negra quando consulta menos e insere mais e o AVL no caso inverso.
    // Se usa mais inserção que busca, é pra usar a rubro-negra.
// Algoritmos de coloração: Geralmente heurísticos
// Na árvore rubro-negra, ela tenta manter os nós nas cores preto e vermelho.
// A raiz sempre é preta.
// Ambos os filhos de todos os nós vermelhos são pretos.
// Todas as folhas são pretas.
// Todo caminho de um dado nó para suas folhas descendentes contém o mesmo número de nós pretos, sem contar a sua cor.
// O caminho mais longo da raiz a qualquer folha não seja mais do que duas vezes o caminho mais curto da raiz a qualquer outra folha naquela árvore.
// É aproximadamente balanceada.

/*
Regras da inserção:
    Testa o conjunto de propriedades descrito anteriormente.
    Efetua rotações e ajusta as cores até satisfazer as regras.
    A rotação é realizada para garantir o balanceamento e pode ser a direita ou a esquerda, alterando os ponteiros.
    O rubro-negra usa rotações, mas ele faz rotações conforme as regras descritas dele.
    A AVL fazia conforme o fator de balanceamento.
    No melhor dos casos, o rubro-negro fica entre o AVL e o dobro de nós em um lado comparado com o outro.
    Ao inserir um elemento, ele é sempre da cor vermelha, exceto se for raiz.

    Existem casos de inserção diferentes.
    Ele testa qual caso vai ser antes de inserir. 
    Os casos são recursivos.
    O caso 1 é quando não tem ninguém na árvore.
    O caso 2 é quando o nodo colocado não desbalanceia a árvore.
    O caso 3 é a tentativa de recolorir a árvore para a balancear. (Se o tio do elemento inserido é VERMELHO)
    O caso 4 aplica a rotação. (O tio do elemento inserido é PRETO e o elemento inserido é um filho da esquerda)
    O caso 5 aplica a rotação, mas precisa recolorir. (O tio do elemento inserido é PRETO e o elemento inserido é um filho da esquerda)

    RECOLORIR: Outra opção mais amena do que rotacionar. É quando a árvore não está tão desbalanceada.
    Depois de recolorir, chama o caso 1 para garantir que as regras ainda estão sendo seguidas. 

    AS REGRAS QUE ELE CUIDA:
    //  A raiz sempre é preta.
    // Ambos os filhos de todos os nós vermelhos são pretos.
    // O caminho mais longo da raiz a qualquer folha não seja mais do que duas vezes o caminho mais curto da raiz a qualquer outra folha naquela árvore.O caminho mais longo da raiz a qualquer folha não seja mais do que duas vezes o caminho mais curto da raiz a qualquer outra folha naquela árvore.
*/

/*
    PESQUISA:
    Nas duas é a mesma.
    O que muda é o que confere (regras no rubro-negra, FB no AVL)
*/


// Exercicios:
// 1) Abre no site e faz uma árvore rubro-negra
// 2) Abre no site e faz simultaneamente a rubro-negra e a AVL
// 3) Olha pro código e tenta fazer a mão
// 4) Tenta implementar
// 5) Tenta fazer a mão sem olhar pro código

// NA PROVA: Dá um caso e pergunta o que acontece se colocar um nó na árvore.
// Não vai pedir pra montar a árvore inteira.
// Provavelmente ele dá o desenho da árvore e pede pra inserir só um nodo.
// Aqui um código: Corrija um bug nele
// Tem um código e ele tem uns printfs: Dizer o que vai ser impresso no printf
// Em algoritmos de ordenação: ele dá um vetor e pede pra usar um algoritmo de ordenação pra ordenar (desenha)
// Mostrar um código e perguntar qual a complexidade de um código, e se mudar a linha, qual fica a complexidade
// No final do livro do Cormen, tem vários exercícios

// No LeetCode, fazer exercícios de árvores balanceadas e de busca binária.

// Ideia: Fazer um programa que execute uma árvore rubro-negra e outra AVL

// Funções:

#define BLACK 0
#define RED 1

typedef struct Node{
    int conteudo;
    node *left;
    node *right;
    node *parent;
    int color; // 0 = BLACK, 1 = RED
}node;

node *grandparent(node *n){
    if ((n != NULL) && (n->parent != NULL))
        return n->parent->parent;
    else
        return NULL;
}

node *uncle(node *n){
    node *g = grandparent(n);
    if(g == NULL)
        return NULL;
    if(n->parent == g-> left)
        return g->right;
    else
        return g->left;
}

void insert_case1(node *n){
    if(n->parent == NULL)
        n->color = BLACK;
    else
        insert_case2(n);
}

void insert_case2(node *n){
    if(n->parent->color == BLACK)
        return;
    else
        insert_case3(n);
}

void insert_case3(node *n){
    node *u = uncle(n), *g;
    if((u != NULL) && (u->color == RED)){
        n->parent->color = BLACK;
        u->color = BLACK;
        g = grandparent(n);
        g->color = RED;
        insert_case1(g);
    } else {
        insert_case4(n);
    }
}

void insert_case4(node *n){
    node *g = grandparent(n);
    if((n == n->parent->right) && (n->parent == g->left)){
        rotate_left(n->parent); // implementar rotate
        n = n->left;
    }else if ((n == n->parent->left) && (n->parent == g->right)){
        rotate_right(n->parent);
        n = n->right;
    }
    insert_case5(n);
}

void insert_case5(node *n){
    node *g = grandparent(n);
    if((n == n->parent->left) && (n->parent == g->left)){
        rotate_right(g);
    }else{
        // aqui, (n == n->parent->right) && (n->parent == g->right)
        rotate_left(g);
    }
    n->parent->color = BLACK;
    g->color = RED;
}















