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

    // Teste 4: root = []
    
    struct TreeNode* root = NULL;
    
    struct TreeNode* resultado = SubtreeWithAllDeepest ( root );
    printf ( "Menor subarvore com os nodos mais profundos: " );
    if ( resultado != NULL ) {
        ImprimirPreOrdem ( resultado );
    } else printf ( "[]" );
    printf ( "\n" );
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
