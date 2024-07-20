#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// É a mesma agenda, mas usa define pra ficar mais legível!

#define CARACTERE * ( char * ) ( pBuffer )
#define ENTRADA  * ( int * ) ( pBuffer + 1 )
#define N_DE_PESSOAS  * ( int * ) ( pBuffer + 5 )
#define INDICE * ( int * ) ( pBuffer + 9)
#define INICIO_DA_AGENDA * ( void ** ) ( pBuffer + 13 )
#define FIM_DA_AGENDA * ( void ** ) ( pBuffer + 21 )
#define NOME_BUSCADO (pBuffer + 29)
#define INICIO_DA_AUXILIAR * ( void ** ) ( pBuffer + 49 )
#define FIM_DA_AUXILIAR * ( void ** ) ( pBuffer + 57 )
#define NODO_AUXILIAR * (void **) (pBuffer + 65)

void *pBuffer;

// Tamanho de um "nodo" de Pessoa:
// 20 char (nome) + 1 int (idade) + 20 char (email) + 2 char *(next e prev)
// Total em bytes: 20 + 4 + 20 + 8 + 8 = 60

/*
pBuffer[0] = getchar (char = 1 byte)  -> pBuffer                                       OK
pBuffer[1] = ler ENTRADA (int = 4 bytes)  -> pBuffer + 1                               OK
pBuffer[2] = numero de pessoas na agenda (int = 4 bytes)  -> pBuffer + 5               OK
pBuffer[3] = numero de letras em uma string (int = 4 bytes)  -> pBuffer + 9            OK
pBuffer[4] = inicio da agenda (char * = 8 bytes) - > pBuffer + 13                      OK
pBuffer[5] = fim da agenda (char * = 4 bytes) - > pBuffer + 21                         OK
pBuffer[6] = le string de buscar (20 char = 20 bytes) - > pBuffer + 29                 OK
pBuffer[7] = inicio da fila auxiliar (char * = 8 bytes) - > pBuffer + 37               OK
pBuffer[8] = fim da fila auxiliar (char * = 8 bytes) - > pBuffer + 45                  OK
pBuffer[9] = nodo auxiliar (60 bytes) - > pBuffer + 53                  OK
         

*/


// tamanho do buffer:
// char: 1 + 20 + 40 = 61
// char *: 6 = 48
// int: 4 = 24

void AdicionarPessoa ( void *nodo);
void RemoverPessoa ( );
void BuscarPessoa ( );
void ListarPessoas ( );
void LimparAgenda ( );
void LimparAuxiliar ( );

int main ( ) {

    pBuffer = malloc ( sizeof(char) + 3 * sizeof(int) + 2 * sizeof(char *) + 20 * sizeof(char) + 2 * sizeof(char *) + 20 * sizeof(char) + sizeof(int) + 20 * sizeof(char) + 2 * sizeof(char *)); 
    ENTRADA = 0;
    N_DE_PESSOAS = 0; 
    INICIO_DA_AGENDA = NULL;
    FIM_DA_AGENDA = NULL;
    INICIO_DA_AUXILIAR = NULL; 
    FIM_DA_AUXILIAR = NULL;

    while ( ENTRADA != 5 ) {
        printf( "Escolha uma opcao:\n1) Adicionar pessoa\n2) Remover pessoa\n3) Buscar pessoa\n4) Listar pessoas\n5) Sair\nEntrada: " );
        scanf( "%d", &ENTRADA );
        getchar ( );

        if ( ENTRADA == 1 ) {
            INDICE = 0; 
            printf( "Digite o nome: " );
            CARACTERE = getchar ( ); 
            while ( CARACTERE != '\n' && CARACTERE != EOF ) {
                if ( INDICE < 20 ) { 
                    * ( char * ) ( pBuffer + 65 + INDICE ) = CARACTERE; 
                    INDICE += 1;
                }
                CARACTERE = getchar ( );
            }
            * ( char * ) (  pBuffer + 65 + INDICE ) = '\0';

            printf ( "Digite a idade: " );
            scanf ( "%d", ( int * ) (  pBuffer + 65 + 20 ) );
            getchar ( );

            INDICE = 0; 

            printf( "Digite o email: " );
            CARACTERE = getchar ( );
            while ( CARACTERE != '\n' && CARACTERE != EOF ) {
                if ( INDICE < 20 ) { 
                    * (char * ) ( pBuffer + 65 + INDICE + 24 ) = CARACTERE;
                    INDICE += 1;
                }
                CARACTERE = getchar ( );
            }
            * ( char * ) ( pBuffer + 65 + INDICE + 24 ) = '\0';

            * ( void ** ) (  pBuffer + 65 + 44 ) = NULL; 
            * ( void ** ) (  pBuffer + 65 + 52 ) = NULL; 
            AdicionarPessoa ( pBuffer+65 );

        }

        if ( ENTRADA  == 2 ) {
            RemoverPessoa ( );
        }

        if ( ENTRADA  == 3 ) {
            BuscarPessoa ( );
        }

        if ( ENTRADA  == 4 ) {
            ListarPessoas ( );
        }

        if ( ENTRADA == 5 ) {
            printf ( "Agenda encerrada." );
            LimparAgenda ( );
            LimparAuxiliar ( );
            free ( pBuffer ); 
            return 0;
        }
    }
    return 0;
}

/* ====================================================================================== 
AdicionarPessoa

    Adiciona uma pessoa na agenda, coletando o nome, idade e email e então, 
    comparando o nome com as demais pessoas na agenda para saber onde inserir a pessoa.
    Ajusta os ponteiros da pessoa, o inicio e fim da agenda se necessário e incrementa
    o número de pessoas na agenda em 1.
====================================================================================== */

void AdicionarPessoa ( void *nodo ){
    void *novaPessoa = malloc ( 60 );
    memcpy ( novaPessoa, nodo, 60 );

    if ( N_DE_PESSOAS == 0 ) {

        INICIO_DA_AGENDA = novaPessoa;
        FIM_DA_AGENDA = novaPessoa;
        
    } else {

        void *atual = INICIO_DA_AGENDA; 
        void *anterior = NULL;

        while ( atual != NULL && strcmp ( ( char * ) novaPessoa, ( char * ) atual ) > 0 ) {

            anterior = atual;
            atual = * ( void ** ) ( atual + 52 );

        }

        if ( anterior == NULL ) {

            * ( void ** ) ( novaPessoa + 52 ) = atual; 

            if ( atual != NULL ) {
                * ( void ** ) ( atual + 44 ) = novaPessoa;
            }

            INICIO_DA_AGENDA = novaPessoa;

        } else {

            * ( void ** ) ( novaPessoa + 44 ) = anterior;
            * ( void ** ) ( novaPessoa + 52 ) = atual;
            * ( void ** ) ( anterior + 52 ) = novaPessoa;
            
            if ( atual != NULL ) {
                * ( void ** ) ( atual + 44 ) = novaPessoa;
            }

        }

        if ( atual == NULL ) {
            FIM_DA_AGENDA = novaPessoa;
        }
        
    }
    N_DE_PESSOAS += 1;

}

/* ====================================================================================== 
RemoverPessoa

    Confere se a agenda está vazia. Se não estiver, chama a função BuscarPessoa que 
    retorna um ponteiro para a pessoa procurada a partir do nome dela. Se não for 
    encontrada, BuscarPessoa retorna NULL. Então, arruma os ponteiros referentes ao nodo
    e à agenda para poder tirar o nodo corretamente, decrementa o número de pessoas na
    agenda e libera a memória.
====================================================================================== */

void RemoverPessoa ( ) {
    printf("Funcao em construcao");
}


/*
void RemoverPessoa ( ) {

    if ( N_DE_PESSOAS == 0 ) {
        printf ( "Agenda esta vazia.\n" );
        return;
    }

    void *busca = BuscarPessoa ( );

    if ( busca == NULL ) {

        printf( "Pessoa nao encontrada na agenda.\n" );

    } else {

        if ( busca == INICIO_DA_AGENDA ) {

            if ( N_DE_PESSOAS == 1 ) {
                INICIO_DA_AGENDA = NULL;
                FIM_DA_AGENDA = NULL;
                N_DE_PESSOAS = 0;
                free ( busca );

            } else {

                * ( void ** ) ( * ( void ** ) ( busca + 52 ) + 44 ) = NULL;
                INICIO_DA_AGENDA = * ( void ** ) ( busca + 52 );
                N_DE_PESSOAS -= 1;
                free ( busca );
            }

        } else if ( busca == FIM_DA_AGENDA ) {
            * ( void ** ) ( * ( void ** ) ( busca + 44 ) + 52 ) = NULL;
            FIM_DA_AGENDA = * ( void ** ) ( busca + 44 ); 
            N_DE_PESSOAS -= 1; 
            free ( busca );

        } else {

            * ( void ** ) ( * ( void ** ) ( busca + 44 ) + 52 ) = * ( void ** ) ( busca + 52 );
            * ( void ** ) ( * ( void ** ) ( busca + 52 ) + 44) = * ( void ** ) ( busca + 44 );
            N_DE_PESSOAS -= 1;
            free ( busca );
            
        }

        printf ( "Pessoa removida da lista.\n" );

    }

}

*/


/* ====================================================================================== 
BuscarPessoa

    Confere se a agenda está vazia. Se não estiver, lê o nome no pBuffer para saber 
    quem buscar. Percorre a agenda a partir do início comparando o nome com as pessoas 
    e cada nodo não correspondente, coloca o nodo no início da fila auxiliar e quando 
    sai do while que busca a pessoa, tendo encontrado ou não, coloca os nodos de volta 
    na fila principal e retorna o ponteiro para a pessoaou NULL se não encontrou a pessoa.
====================================================================================== */


void BuscarPessoa ( ) {

    if ( N_DE_PESSOAS == 0 ) {

        printf ( "Agenda esta vazia.\n" );

    } else {

        // LE O NOME DA PESSOA A BUSCAR

        printf ( "Digite o nome da pessoa: " );

        INDICE = 0; 
        CARACTERE = getchar ( );
        while ( CARACTERE != '\n' && CARACTERE != EOF ) {
            if ( INDICE < 20 ) {
                * ( char * ) ( NOME_BUSCADO + INDICE ) = * ( char * ) pBuffer;
                INDICE += 1;
            }
            CARACTERE = getchar(); 
        }
        * ( char * ) ( NOME_BUSCADO + INDICE ) = '\0';

        // PERCORRE A AGENDA PRA PROCURAR A PESSOA

        void *atual = INICIO_DA_AGENDA; 
        void *novoNodo = malloc ( 60 );

        while ( atual != NULL && strcmp ( ( char * ) atual, ( char * ) ( NOME_BUSCADO ) ) != 0 ) {
            // NÃO ENCONTROU = COLOCA O NODO NO AUXILIAR E TIRA DA AGENDA
            
            void *proximo = * ( void ** ) ( atual + 52 );
            memcpy(novoNodo, atual, 60);

            /*
            strcpy ( ( char * ) novoNodo, ( char * ) atual );
            * ( int * ) ( novoNodo + 20 ) = * ( int * ) ( atual + 20 );
            strcpy ( ( char * ) ( novoNodo + 24 ), ( char * ) ( atual + 24 ) );
            */

            // INSERE NA AUXILIAR

            if ( INICIO_DA_AUXILIAR == NULL ) {
                * ( void ** ) ( novoNodo + 44 ) = NULL;
                * ( void ** ) ( novoNodo + 52 ) = NULL;
                INICIO_DA_AUXILIAR = novoNodo;
                FIM_DA_AUXILIAR = novoNodo;
            } else {
                void *p = INICIO_DA_AUXILIAR;
                void *anterior = NULL;
                while ( p != NULL && strcmp ( ( char * ) novoNodo, ( char * ) p ) > 0 ) {
                    anterior = p;
                    p = * ( void ** ) ( p + 52 );
                }
                if ( anterior == NULL ) {
                    * ( void ** ) ( novoNodo + 52 ) = p; 
                    if ( p != NULL ) {
                        * ( void ** ) ( p + 44 ) = novoNodo;
                    }
                    INICIO_DA_AUXILIAR = novoNodo;
                } else {
                    * ( void ** ) ( novoNodo + 44 ) = anterior;
                    * ( void ** ) ( novoNodo + 52 ) = p;
                    * ( void ** ) ( anterior + 52 ) = novoNodo;
                    if ( p != NULL ) {
                        * ( void ** ) ( p + 44 ) = novoNodo;
                    }
                }
                if ( p == NULL ) {
                    FIM_DA_AUXILIAR = novoNodo;
                }
            }

            // TIRA O NODO DA AGENDA
            INICIO_DA_AGENDA = proximo;
            if(proximo != NULL){
                * ( void ** ) ( proximo + 44 ) = NULL;
                free(atual);
                atual = proximo; // proximo nodo
            }else{
                atual = NULL; // sai do while
            }
        }
        // IMPRIME A RESPOSTA
        if ( atual == NULL ) {
            printf("A pessoa %s nao foi encontrada na agenda.\n",( char * ) NOME_BUSCADO);
            free(atual);
        } else {
            printf ( "Nome: %s\n", ( char * ) atual );
            printf ( "Idade: %d\n", * ( int * ) ( atual + 20 ) );
            printf ( "Email: %s\n", ( char * ) ( atual + 24 ) );
        }

        // COLOCA OS NODOS DE VOLTA NA AGENDA
        //INICIO_DA_AGENDA = atual;
        if ( atual != NULL ) { 
            * ( void ** ) ( atual + 44 ) = NULL; 
        } else {
            FIM_DA_AGENDA = NULL; 
        }

        void *pessoa = INICIO_DA_AUXILIAR;
        //printf("Pessoa prox: %s", * ( char ** ) ( pessoa + 52 ));

        // Usar AdicionarPessoa(pessoa) para colocar de volta na agenda!
        while ( pessoa != NULL ) {
            void *prox = * ( void ** ) ( pessoa + 52 );
            AdicionarPessoa(pessoa);
            pessoa = prox;
        }
    }

    
}



/* ====================================================================================== 
ListarPessoas

    Confere se a agenda está vazia. Se não estiver, a partir do inicio da fila principal,
    passa por cada nodo, imprime suas informações, retira da fila pricipal e o insere no
    final da fila auxiliar, decrementando o número de pessoas na agenda. Depois de imprimir
    todos os nodos, a partir do início da fila auxiliar, retira os nodos e os adiciona
    de volta na fila principal.
====================================================================================== */


void ListarPessoas ( ) {

    if ( N_DE_PESSOAS == 0 ) {
        printf ( "Agenda está vazia.\n" );
        return;
    }

    INICIO_DA_AUXILIAR = NULL; 
    FIM_DA_AUXILIAR = NULL; 

    while ( INICIO_DA_AGENDA != NULL ) {

        void *atual = INICIO_DA_AGENDA; 

        printf ( "Nome: %s\n", ( char * ) atual );
        printf ( "Idade: %d\n", * ( int * ) ( atual + 20 ) );
        printf ( "Email: %s\n\n", ( char * ) ( atual + 24 ) );

        INICIO_DA_AGENDA = * ( void ** ) ( atual + 52 ); 

        if ( INICIO_DA_AGENDA != NULL ) {
            * ( void ** ) ( INICIO_DA_AGENDA + 44 ) = NULL;
        } else {
            FIM_DA_AGENDA = NULL;
        }

        * ( int * ) (pBuffer + 5) -= 1;

        if ( INICIO_DA_AUXILIAR == NULL ) { 

            INICIO_DA_AUXILIAR = atual; 
            FIM_DA_AUXILIAR = atual; 
            * ( void ** ) ( atual + 44 ) = NULL;
            * ( void ** ) ( atual + 52 ) = NULL;
            
        } else {

            * ( void ** ) ( FIM_DA_AUXILIAR + 52 ) = atual;
            * ( void ** ) ( atual + 44 ) = FIM_DA_AUXILIAR; 
            * ( void ** ) ( atual + 52 ) = NULL;
            FIM_DA_AUXILIAR = atual;
            
        }
    }

    void *pessoaAtual = INICIO_DA_AUXILIAR;

    while ( pessoaAtual != NULL ) {

        void *proximaAuxiliar = * ( void ** ) ( pessoaAtual + 52 );

        if ( INICIO_DA_AGENDA == NULL ) { 
            INICIO_DA_AGENDA = pessoaAtual; 
            FIM_DA_AGENDA = pessoaAtual; 
            * ( void ** ) ( pessoaAtual + 44 ) = NULL; 
            * ( void ** ) ( pessoaAtual + 52 ) = NULL; 
            
        } else {

            void * fim = FIM_DA_AGENDA;
            * ( void ** ) ( fim + 52 ) = pessoaAtual; 
            * ( void ** ) ( pessoaAtual + 44 ) = fim;
            * ( void ** ) ( pessoaAtual + 52 ) = NULL;
            FIM_DA_AGENDA = pessoaAtual;
            
        }

        N_DE_PESSOAS += 1;

        pessoaAtual = proximaAuxiliar;

    }

    INICIO_DA_AUXILIAR = NULL;
    FIM_DA_AUXILIAR = NULL;

}


/* ====================================================================================== 
LimparAgenda

    Percorre as pessoas na agenda ao fim da execução para dar free em cada uma e não
    gerar memory leak.
====================================================================================== */
void LimparAgenda ( ) {

    void *pessoaAtual = INICIO_DA_AGENDA;

    while ( pessoaAtual != NULL ) {
        void *proximaPessoa = * ( void ** ) ( pessoaAtual + 52 );
        free ( pessoaAtual );
        pessoaAtual = proximaPessoa;
    }

    INICIO_DA_AGENDA = NULL;
    FIM_DA_AGENDA = NULL;

}

/* ====================================================================================== 
LimparAuxiliar

    Percorre as pessoas na fila auxiliar ao fim da execução para dar free em cada uma e 
    não gerar memory leak.
====================================================================================== */
void LimparAuxiliar ( ) {

    void *pessoaAtual = INICIO_DA_AUXILIAR;

    while ( pessoaAtual != NULL ) {
        void *proximaPessoa = * ( void ** ) ( pessoaAtual + 52 );
        free ( pessoaAtual );
        pessoaAtual = proximaPessoa;
    }

    INICIO_DA_AUXILIAR = NULL;
    FIM_DA_AUXILIAR = NULL;

}
