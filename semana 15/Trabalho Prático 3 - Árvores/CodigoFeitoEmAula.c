/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// calcula a altura de um nodo (tentei usar para encontrar os nodos mais profundos)
// problema: todos as folhas tem altura 1, e não necessariamente serão as mais profundas

int Altura(struct TreeNode *raiz){ 
    if(raiz == NULL){
        return 0;
    }
    int alturaEsq, alturaDir;
    alturaEsq = Altura(raiz->left);
    alturaDir = Altura(raiz->right);
    if (alturaEsq > alturaDir) return alturaEsq + 1;
    else return alturaDir + 1;
}


// consegui encontrar os nodos mais profundos! (coloquei eles em um vetor)
void Profundidade(struct TreeNode *root, struct TreeNode **nodosMaisProfundos, int *nNodos,int altura){
    struct TreeNode *nodo = root;
    if(nodo != NULL){
        Profundidade(nodo->left,nodosMaisProfundos, nNodos, altura-1);
        Profundidade(nodo->right,nodosMaisProfundos, nNodos, altura-1);
        if(altura == 1){
            nodosMaisProfundos[(*nNodos)++] = nodo;
        }
    }
}

// encontra a menor subarvore quando ela é formada por um nodo e seus dois filhos
void Subarvore(struct TreeNode *root, struct TreeNode **nodosMaisProfundos, int *nNodos,int altura){
    struct TreeNode *nodo = root;
    if(nodo != NULL){
        Subarvore(nodo->left,nodosMaisProfundos, nNodos, altura-1);
        Subarvore(nodo->right,nodosMaisProfundos, nNodos, altura-1);
        if(altura == 2 && nodo->left && nodo->right){
            nodosMaisProfundos[(*nNodos)++] = nodo;
            nodosMaisProfundos[(*nNodos)++] = nodo->left;
            nodosMaisProfundos[(*nNodos)++] = nodo->right;
            return;
        }
    }
}

struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root) {
    if(root == NULL) return root;
    if(root->left == NULL && root->right == NULL) return root;
    int alturaDaArvore = Altura(root), nNodos = 0; 
    struct TreeNode **nodosMaisProfundos = (struct TreeNode**)malloc(sizeof(struct TreeNode *) * 100);
    Profundidade(root, nodosMaisProfundos, &nNodos, alturaDaArvore);
    for(int i = 0; i < nNodos; i++){
        printf("Nodo mais profundo: %d\n", (nodosMaisProfundos[i])->val);
    }
    if(nNodos == 1) return *nodosMaisProfundos; 
    // tentativa para resolver quando a subarvore é formada por um nodo e seus dois filhos:
    if(nNodos == 2){
        nNodos = 0;
        Subarvore(root,nodosMaisProfundos,&nNodos,alturaDaArvore);
        return *nodosMaisProfundos;
    }
    // faltou resolver para os outros casos
    return root;
}



// TENTATIVAS QUE DERAM ERRADO:

/*
primeira tentativa de achar os nodos mais profundos: usei a altura como parâmetro e percebi que dava errado (encontrava todas as folhas)

void EncontraProfundos (struct TreeNode *raiz, struct TreeNode **nodosMaisProfundos,int *nNodos, int alturaDaArvore){
    if(raiz != NULL){
        if(Altura(raiz) == 1){
            // tá encontrando 6, 7, 4, 0 e 8 como altura = 1 no primeiro exemplo (altura nao funciona, encontra todas as folhas)
            printf("Altura de %d na arvore: %d",raiz->val,Altura(raiz));
            nodosMaisProfundos[(*nNodos)++] = raiz;
        }
        if(raiz->left){
            EncontraProfundos(raiz->left,nodosMaisProfundos,nNodos,alturaDaArvore);
        }
        if(raiz->right){
            EncontraProfundos(raiz->right,nodosMaisProfundos,nNodos,alturaDaArvore);
        }
    }
}
*/

// tentativa de calcular a profundidade que não deu certo:
/*int Profundidade(struct TreeNode *root, struct TreeNode **nodosMaisProfundos, int *nNodos){
    int altura = Altura(root);
    struct TreeNode *nodo = root;
    if(nodo == NULL) return 0;
    altura--;
    int pEsq = Profundidade(nodo->left,nodosMaisProfundos, nNodos);
    int pDir = Profundidade(nodo->right,nodosMaisProfundos, nNodos);
    if(pEsq == 1 || pDir == 1){
        nodosMaisProfundos[(*nNodos)++] = nodo;
    }
}*/



/*
// tentativa de encontrar a subarvore no caso que a menor subarvore é composta por um nodo, seu filho esquerdo e seu filho direito
void EncontraSubarvore(struct TreeNode *root, struct TreeNode **subarvore,struct TreeNode **nodosMaisProfundos){
    if(root == NULL) return;
    EncontraSubarvore(root->left,subarvore,nodosMaisProfundos);
    EncontraSubarvore(root->right,subarvore,nodosMaisProfundos);
    if(((root->left == nodosMaisProfundos[0]) && (root->right == nodosMaisProfundos[1]))||((root->left == nodosMaisProfundos[1] && root->right == nodosMaisProfundos[0]))){
        subarvore[0] = root;
        subarvore[1] = nodosMaisProfundos[0];
        subarvore[2] = nodosMaisProfundos[1];
        return;
    }
}
*/