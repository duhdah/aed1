#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int entrada=0;
    char *string,a,*p;
    string = (char *)malloc(sizeof(char));
    string = '\0';
    while(entrada!=3){
        printf("Escolha uma opcao:\n1) Nova palavra\n2) Listar palavras\n3) Sair");
        scanf("%d",&entrada);
        getchar();
        if(entrada == 1){
        printf("Digite a sua frase:");
            p = string;
            while(((a=getchar())!='\n') && a!=EOF){
                *p=a;
                realloc(string,sizeof(char)*strlen(string)+1);
                p++;
            }
        *p = '&';
        realloc(string,sizeof(char)*strlen(string)+1);
        p++;
        *p = '\0';
        }else if(entrada == 2){
            if(!string){
                printf("Lista vazia.\n");
            }else{
                char *l;
                l = string;
                int tam = strlen(string);
                for(int i = 0; i < tam; i++, l++){
                    if(*l == '&'){
                        printf("\n");
                    }else{
                        printf("%c",*l);
                    }
                }
            }

        }else if(entrada == 3){
            break;
        }else{
            printf("Entrada invalida.");
        }
    }
    free(string);
        return 0;
}