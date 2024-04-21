#include <stdio.h>
#include <stdlib.h>

    /*
    Faça um programa que armazena nomes.
    O programa deve armazenar todos os nomes na mesma string.
    O tamanho da string deve crescer e diminuir conforme nomes forem colocados ou removidos.
    Não pode ter desperdício de memória.
    Faça o seguinte menu: 1) Adicionar nome 2) Remover nome 3) Listar 4) Sair
    */

    /*
        CÓDIGO 2:
        COM LISTAS ENCADEADAS
    */

typedef struct Cel{
    char letra;
    struct Cel *prox;
}celula;

celula *cria(void);
void adiciona(celula *c, char a);
int encontraNome(celula *c, char *a, int t);
void remove(celula *c, int inicio);
void listar (celula *c);

int main(){

    celula *lista;
    char a;
    int entrada = 0, tamanhoLista = 0;

    lista = cria();
    while(entrada!=4){
        printf("1) Adicionar nome\n");
        printf("2) Remover nome\n");
        printf("3) Listar\n");
        printf("4) Sair\n");
        scanf("%d",&entrada);
   }
   if(entrada == 1){
        printf("Digite o nome a ser adicionado na lista: ");
        while(((a = getchar()) != '\n') && !EOF){
            adiciona(lista, a);
            tamanhoLista++;
        }
        adiciona(lista, '&');
        tamanhoLista++;
   }
   if(entrada == 2){
        char *remover;
        int n,busca=0;
        printf("Digite o tamanho do nome a ser removido e o nome:");
        scanf("%d",&n);
        remover = (char *)malloc(n*sizeof(char)+1);
        for(int i = 0; i < n; i++){
            scanf("%c",remover+i);
        }
        busca = encontraNome(lista, *remover, n);
        if(busca){
            remove(lista, busca);
        }

   }
   if(entrada == 3){
        listar(lista);
   }
   free(lista);
   return 0;
}

celula *cria(void){
    celula *inicio;
    inicio = (celula *)malloc(sizeof(celula));
    inicio->prox = NULL;
    return inicio;
}

void adiciona(celula *c, char a){ //adicionando no final
    celula *caractere,*p;
    caractere = (celula *)malloc(sizeof(celula));
    caractere->letra = a;
    for(p = c; p->prox!=NULL;p=p->prox);
    p->prox = caractere;
    caractere->prox = NULL;
}

int encontraNome(celula *c, char *a, int t){
    celula *p;
    int igual=0, inicio, i;
    for(p = c, i=0; p != NULL, i++; p=p->prox){
            igual = 0;
            if(p->letra==a){
                inicio = i;
                igual = 1;
                // faltou adaptar para a sintaxe de listas encadeadas:
                for(int p = i; p < i+t; p++){
                    for(int k = 0; k < t; k++){
                        if(l[p]!=n[k]){
                            igual = 0;
                        }
                    }
                }
            }
            if(igual==1){
                break;
            }
        }
        if(igual){
            return inicio;
        }else{
            return -1;
        }
    }

void remove(celula *c, int inicio){
    celula *p,*q, *ini;
    int i;
    for(p=c,i=0; i<inicio; p=p->prox,i++);
    ini = p;
    for(q=p; q->letra!='&'; q=q->prox){
        free(p);
    }
    ini->prox = q;

}

void listar (celula *c){
    celula *p;
    for(p = c->prox; p!= NULL; p=p->prox){
        if((p->letra)=='&'){
            printf("\n");
        }else{
            printf("%c",p->letra);
        }
    }
    printf("\n");
}