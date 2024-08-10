#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* SubtreeWithAllDeepest ( struct TreeNode* root );
struct TreeNode* EncontraSubarvore ( struct TreeNode *root, int* profundidadeMax );
struct TreeNode* NovoNodo ( int valor );
void ImprimirFormatoLista(struct TreeNode* root);

int main ( ) {

    // Teste 5: root = [0,3,1,4,null,2,null,null,6,null,5]

    /*
    Árvore de teste:
               0 (3) 
            /        \
        3 (2)         1(2)
        /             /   
     4 (1)          2(1) 
       \               \
        6 (0)          5(0)
    */
    
    struct TreeNode* root = NovoNodo ( 0 );
    root->left = NovoNodo ( 3 );
    root->right = NovoNodo ( 1 );
    root->left->left = NovoNodo ( 4 );
    root->left->left->right = NovoNodo ( 6 );
    root->right->left = NovoNodo ( 2 );
    root->right->left->right = NovoNodo ( 5 );

    struct TreeNode* resultado = SubtreeWithAllDeepest ( root );
    printf ( "Menor subarvore com os nodos mais profundos: " );
    if ( resultado != NULL ) {
        ImprimirFormatoLista ( resultado );
    } else printf ( "[]" );
    printf ( "\n" );

    free ( root->left->left->right );
    free ( root->right->left->right );
    free ( root->left->left );
    free ( root->right->left );
    free ( root->left );
    free ( root->right );
    free ( root );

    return 0;

}

struct TreeNode* NovoNodo ( int valor ) {
    struct TreeNode* nodo = ( struct TreeNode * ) malloc ( sizeof ( struct TreeNode ) );
    nodo->val = valor;
    nodo->left = NULL;
    nodo->right = NULL;
    return nodo;
}

void ImprimirFormatoLista ( struct TreeNode* root ) {
    if ( root == NULL ) {
        printf ( "[]\n" );
        return;
    }
    struct TreeNode** fila = ( struct TreeNode** ) malloc ( sizeof ( struct TreeNode* ) * 15 );
    int inicio = 0, fim = 0, nNodos = 1; // nNodos inclui null
    fila [ fim++ ] = root;
    printf ( "[" );
    while ( inicio < fim ) {
        struct TreeNode* atual = fila [ inicio++ ];
        if ( atual != NULL ) {
            printf ( "%d", atual->val );
            fila [ fim++ ] = atual->left;
            fila [ fim++ ] = atual->right;
            nNodos += 2;
        } else {
            printf ( "null" );
        }
        if ( inicio < fim ) {
            printf( ", " );
        }
    }
    printf ( "]\n" );
    free ( fila );
}

struct TreeNode* EncontraSubarvore ( struct TreeNode *root, int* profundidadeMax ) {
    if ( root == NULL ) {
        *profundidadeMax = 0;
        return NULL;
    }
    int profundidadeEsq, profundidadeDir;
    struct TreeNode* subArvoreEsq = EncontraSubarvore ( root->left, &profundidadeEsq );
    struct TreeNode* subArvoreDir = EncontraSubarvore ( root->right, &profundidadeDir );

    if ( profundidadeEsq > profundidadeDir ) *profundidadeMax = profundidadeEsq + 1;
    else *profundidadeMax = profundidadeDir + 1;

    if ( profundidadeEsq == profundidadeDir ) {
        return root;
    } else if ( profundidadeEsq > profundidadeDir ) {
        return subArvoreEsq;
    } else {
        return subArvoreDir;
    }
}

struct TreeNode* SubtreeWithAllDeepest ( struct TreeNode* root ) {
    int profundidadeMax;
    return EncontraSubarvore ( root, &profundidadeMax );
}
