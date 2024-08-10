
// Complexidade do código: O(n), em que n representa o número de nodos em uma árvore

/*
==================================================================
EncontraSubarvore
    
    Calcula recursivamente a "profundidade" dos nodos das árvore 
    (usando um conceito mais semelhante a altura) e compara as 
    profundidades para encontrar a menor subárvore com
    os nodos mais profundos.
=================================================================
*/

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


/*
==================================================================
subtreeWithAllDeepest

    Função principal do LeetCode.

        OBS: Como essa versão do código é feita para ser testada
    no LeetCode, o nome da função foi mantido com letra
    inicial minúscula.
=================================================================
*/


struct TreeNode* subtreeWithAllDeepest ( struct TreeNode* root ) {
    int profundidadeMax;
    return EncontraSubarvore ( root, &profundidadeMax );
}


/*

Versão alternativa implementando a mesma logic, mas usando a altura dos nodos diretamente:

int Altura ( struct TreeNode *raiz ) { 
    if ( raiz == NULL ) {
        return 0;
    }
    int alturaEsq, alturaDir;
    alturaEsq = Altura ( raiz->left );
    alturaDir = Altura ( raiz->right );
    if (alturaEsq > alturaDir) return alturaEsq + 1;
    else return alturaDir + 1;
}

struct TreeNode* EncontraSubarvore (struct TreeNode* root) {
    if ( root == NULL ) {
        return NULL;
    }

    int alturaEsq = Altura ( root->left );
    int alturaDir = Altura ( root->right );

    if ( alturaEsq == alturaDir ) {
        return root;
    }

    if ( alturaEsq > alturaDir ) {
        return EncontraSubarvore ( root->left );
    } else {
        return EncontraSubarvore ( root->right );
    }
}

struct TreeNode* subtreeWithAllDeepest ( struct TreeNode* root ) {
    struct TreeNode *subarvore = EncontraSubarvore ( root );
    return subarvore;
}

*/