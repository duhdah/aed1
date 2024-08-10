/*
450. Delete Node in a BST

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.

Link: https://leetcode.com/problems/delete-node-in-a-bst/description/

Dificuldade: Médio

*/

// Funcionou (18 ms)
struct TreeNode *Pesquisa (struct TreeNode *p, int x){
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

void Antecessor(struct TreeNode *p, struct TreeNode **q){
    struct TreeNode *aux;
    if((*q)->right != NULL){
        return Antecessor(p,&(*q)->right);
    }
    p->val = (*q)->val;
    aux = *q;
    *q = (*q)->left;
    free(aux);
    return;
}

void Remove(struct TreeNode **p, int x){
    struct TreeNode *aux;
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

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    struct TreeNode *remover = Pesquisa(root, key);
    if(remover == NULL) return root;
    Remove(&root,remover->val);
    return root;
}

// Outra forma de estruturar a Remove:
/*
void Remove(struct TreeNode **p, int x){
    struct TreeNode *aux;
    if((*p) == NULL){
        printf("O nodo nao foi encontrado na arvore.");
        return;
    }
    if(x < (*p)->val){
        return Remove(&(*p)->left,x);
    }
    else if(x > (*p)->val){
        return Remove(&(*p)->right,x);
    }
    else{
        if ((*p)->left == NULL && (*p)->right == NULL) {
            free(*p);
            *p = NULL;
        } else if ((*p)->left == NULL) {
            aux = *p;
            *p = (*p)->right;
            free(aux);
        } else if ((*p)->right == NULL) {
            aux = *p;
            *p = (*p)->left;
            free(aux);
        } else {
            Antecessor(*p, &(*p)->left);
        }
    }
}
*/