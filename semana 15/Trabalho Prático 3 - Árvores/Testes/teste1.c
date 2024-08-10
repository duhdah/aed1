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
void ImprimirPreOrdem ( struct TreeNode* root );

int main() {

    // Teste 1: root = [3,5,1,6,2,0,8,null,null,7,4]
    
    /*
    Árvore de teste:
                3 (4) 
            /          \
        5 (3)           1(2)
        /    \         /    \
    6 (1)  2 (2)  0 (1)   8 (1)
            /   \
        7(1)   4 (1)

    */
   
    struct TreeNode* root = NovoNodo ( 3 );
    root->left = NovoNodo ( 5 );
    root->right = NovoNodo ( 1 );
    root->left->left = NovoNodo ( 6 );
    root->left->right = NovoNodo ( 2 );
    root->right->left = NovoNodo ( 0 );
    root->right->right = NovoNodo ( 8 );
    root->left->right->left = NovoNodo ( 7 );
    root->left->right->right = NovoNodo ( 4 );
    
    struct TreeNode* resultado = SubtreeWithAllDeepest ( root );
    printf ( "Menor subarvore com os nodos mais profundos: " );
    if ( resultado != NULL ) {
        ImprimirPreOrdem ( resultado );
    } else printf ( "[]" );
    printf ( "\n" );
    
    free ( root->left->right->left );
    free ( root->left->right->right );
    free ( root->left->right );
    free ( root->left->left );
    free ( root->right->left );
    free ( root->right->right );
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

void ImprimirPreOrdem ( struct TreeNode* root ) {
    if ( root != NULL){
        printf( "%d ", root->val );
        ImprimirPreOrdem ( root->left );
        ImprimirPreOrdem ( root->right );
    }
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
