#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int info;
    struct Node* prev;
    struct Node* next;
} Node;

Node* criaNodo(int info);
void insereInicio(Node** head, int info);
void insereFim(Node** head, int info);
void apagaNodo(Node** head, int posicao);
void imprime(Node* node);
void ordenaLista(Node** head);

int main() {
    Node* head = NULL;
    int escolha, info, posicao;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Incluir dado no final\n");
        printf("2. Incluir dado no início\n");
        printf("3. Excluir dado (posicao)\n");
        printf("4. Listar dados\n");
        printf("5. Ordenar em ordem crescente\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o dado a ser incluído no final: ");
                scanf("%d", &info);
                insereFim(&head, info);
                break;
            case 2:
                printf("Digite o dado a ser incluído no inicio: ");
                scanf("%d", &info);
                insereInicio(&head, info);
                break;
            case 3:
                printf("Digite a posição do dado a ser excluído: ");
                scanf("%d", &posicao);
                apagaNodo(&head, posicao);
                break;
            case 4:
                printf("Dados da lista: ");
                imprime(head);
                break;
            case 5:
                ordenaLista(&head);
                printf("A lista foi ordenada.\n");
                break;
            case 6:
                printf("Fim do codigo.");
                return 0;
            default:
                printf("Opcao invalida.\n");
        }
    }
    return 0;
}


Node* criaNodo(int info) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->info = info;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insereFim(Node** head, int info) {
    Node* newNode = criaNodo(info);
    Node* ultimo = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (ultimo->next != NULL) {
        ultimo = ultimo->next;
    }
    ultimo->next = newNode;
    newNode->prev = ultimo;
}

void insereInicio(Node** head, int info) {
    Node* newNode = criaNodo(info);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

void apagaNodo(Node** head, int posicao) {
    if (*head == NULL || posicao <= 0) {
        return;
    }
    Node* atual = *head;
    for (int i = 1; atual != NULL && i < posicao; i++) {
        atual = atual->next;
    }
    if (atual == NULL) {
        return;
    }
    if (*head == atual) {
        *head = atual->next;
    }
    if (atual->next != NULL) {
        atual->next->prev = atual->prev;
    }
    if (atual->prev != NULL) {
        atual->prev->next = atual->next;
    }
    free(atual);
}

void imprime(Node* node) {
    while (node != NULL) {
        printf("%d ", node->info);
        node = node->next;
    }
    printf("\n");
}

void ordenaLista(Node** head) {
    if (*head == NULL) {
        return;
    }
    Node* atual, *index;
    int temp;
    for (atual = *head; atual->next != NULL; atual = atual->next) {
        for (index = atual->next; index != NULL; index = index->next) {
            if (atual->info > index->info) {
                temp = atual->info;
                atual->info = index->info;
                index->info = temp;
            }
        }
    }
}
