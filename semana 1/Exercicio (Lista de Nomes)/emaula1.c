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
        CÓDIGO 1:
        SEM LISTAS ENCADEADAS
    */

void removenome(char *l,char *n, int t, int tamanhoLista);
void listar (char *l, int tamanhoLista);

int main(){

   char *lista = NULL,a;
   int entrada = 0,tamanhoLista=0,n=0;
   while(entrada!=4){
        printf("1) Adicionar nome\n2) Remover nome\n3) Listar\n4) Sair\n");
        scanf("%d",&entrada);
        getchar();
        if(entrada == 1){
            printf("Digite o nome a ser adicionado na lista: ");
            while(((a = getchar()) != '\n') && (a != EOF)){
                lista[tamanhoLista] = (char *)malloc(sizeof(char)); // faltou corrigir
                lista[tamanhoLista] = a;
                tamanhoLista++;
            }
            // Usei & como char separador de nomes.
            lista[tamanhoLista] = '&';

            tamanhoLista++;
        }
        if(entrada == 2){
                if(!tamanhoLista){
                    printf("Nao ha nenhum nome na lista.\n");
                }else{
                    printf("Digite o tamanho do nome a ser removido da lista e o nome: ");
                    scanf("%d",&n);
                    getchar();
                    char *nomeRemovido;
                    nomeRemovido = (char *)malloc(n*sizeof(char)+1);
                    for(int i = 0; i < n; i++){
                        scanf("%c",nomeRemovido+i);
                    }
                    removenome(lista,nomeRemovido,n,tamanhoLista);
                }
                
        }
        if(entrada == 3){
                if(!tamanhoLista){
                    printf("Nao ha nenhum nome na lista.\n");
                }else{
                    listar(lista,tamanhoLista);
                }
        }
   }
   free(lista);
   return 0;
}

void removenome(char *l,char *n, int t, int tamanhoLista){
    int inicio, igual;
    for(int i = 0; i < tamanhoLista; i++){
        igual= 0;
        if(l[i]==n){
            inicio = i;
            igual = 1;
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
        for(int i = 0; i<t+1; i++){
            l[inicio+i]=l[t+1+inicio+i];
        }
        for(int i = 0; i<t+1; i++){
            free(l[tamanhoLista-i]);
        }
    }else{
        printf("Nome nao encontrado na lista.\n");
    }
}

void listar (char *l, int tamanhoLista){
    if(!tamanhoLista){
        printf("Lista vazia.\n");
    }else{
        for(int i = 0; i < tamanhoLista; i++){
            if((*(l+i))=='&'){
                printf("\n");
            }else{
                printf("%c",*(l+i));
            }
        }
    }

}