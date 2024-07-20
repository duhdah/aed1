#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CARACTERE * ( char * ) ( pBuffer )
#define ENTRADA  * ( int * ) ( pBuffer + sizeof ( char ) )
#define N_DE_PESSOAS  * ( int * ) ( pBuffer + sizeof ( char ) + sizeof ( int ) )
#define INDICE * ( int * ) ( pBuffer + sizeof ( char ) + 2 * sizeof ( int ) )
#define INICIO_DA_AGENDA * ( void ** ) ( pBuffer + sizeof ( char ) + 3 * sizeof ( int ) )
#define FIM_DA_AGENDA * ( void ** ) ( pBuffer + sizeof ( char ) + 3 * sizeof ( int ) + sizeof ( void * ) )
#define NOME_BUSCADO pBuffer + ( sizeof ( char ) + 3 * sizeof ( int ) + 2 * sizeof ( void * ) )
#define INICIO_DA_AUXILIAR * ( void ** ) ( pBuffer + 21 *sizeof(char) + 3 * sizeof(int) + 2 * sizeof ( void * ) )
#define FIM_DA_AUXILIAR * ( void ** ) ( pBuffer + 21 *sizeof ( char ) + 3 * sizeof(int) + 3 * sizeof ( void * ) )
#define NODO_AUXILIAR pBuffer + ( 21 * sizeof(char) + 3 * sizeof ( int ) + 4 * sizeof ( void * ) )
#define ANT ( int ) ( 40 * sizeof ( char ) + sizeof ( int ) )
#define PROX ( int ) ( 40 * sizeof ( char ) + sizeof ( int ) + sizeof ( char * ) )

void *pBuffer;

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
                    * ( char * ) ( NODO_AUXILIAR + INDICE ) = CARACTERE; 
                    INDICE += 1;
                }
                CARACTERE = getchar ( );
            }
            * ( char * ) (  NODO_AUXILIAR + INDICE ) = '\0';

            printf ( "Digite a idade: " );
            scanf ( "%d", ( int * ) (  NODO_AUXILIAR + 20 ) );
            getchar ( );

            INDICE = 0; 

            printf( "Digite o email: " );
            CARACTERE = getchar ( );
            while ( CARACTERE != '\n' && CARACTERE != EOF ) {
                if ( INDICE < 20 ) { 
                    * (char * ) ( NODO_AUXILIAR + INDICE + 24 ) = CARACTERE;
                    INDICE += 1;
                }
                CARACTERE = getchar ( );
            }
            * ( char * ) ( NODO_AUXILIAR + INDICE + 24 ) = '\0';

            * ( void ** ) (  NODO_AUXILIAR + ANT ) = NULL; 
            * ( void ** ) (  NODO_AUXILIAR + PROX ) = NULL; 
            AdicionarPessoa ( NODO_AUXILIAR );

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
    void *novaPessoa = malloc ( ( int ) (40 * sizeof(char) + sizeof(int) + 2*sizeof(char *) ) );
    if(novaPessoa == NULL){
        printf("Erro ao alocar memoria.");
        exit(1);
    }

    memcpy ( novaPessoa, nodo, ( int ) (40 * sizeof(char) + sizeof(int) + 2*sizeof(char *) )  );

    if ( N_DE_PESSOAS == 0 ) {

        INICIO_DA_AGENDA = novaPessoa;
        FIM_DA_AGENDA = novaPessoa;
        
    } else {

        void *atual = INICIO_DA_AGENDA; 
        void *anterior = NULL;

        while ( atual != NULL && strcmp ( ( char * ) novaPessoa, ( char * ) atual ) > 0 ) {

            anterior = atual;
            atual = * ( void ** ) ( atual + PROX );

        }

        if ( anterior == NULL ) {

            * ( void ** ) ( novaPessoa + PROX ) = atual; 

            if ( atual != NULL ) {
                * ( void ** ) ( atual + ANT ) = novaPessoa;
            }

            INICIO_DA_AGENDA = novaPessoa;

        } else {

            * ( void ** ) ( novaPessoa + ANT ) = anterior;
            * ( void ** ) ( novaPessoa + PROX ) = atual;
            * ( void ** ) ( anterior + PROX ) = novaPessoa;
            
            if ( atual != NULL ) {
                * ( void ** ) ( atual + ANT ) = novaPessoa;
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

    if ( N_DE_PESSOAS == 0 ) {

        printf ( "Agenda esta vazia.\n" );

    } else {

        // LE O NOME DA PESSOA A BUSCAR

        printf ( "Digite o nome da pessoa a remover: " );

        INDICE = 0; 
        CARACTERE = getchar ( );

        while ( CARACTERE != '\n' && CARACTERE != EOF ) {
            if ( INDICE < 20 ) {
                * ( char * ) ( NOME_BUSCADO + INDICE ) = CARACTERE;
                INDICE += 1;
            }
            CARACTERE = getchar(); 
        }

        * ( char * ) ( NOME_BUSCADO + INDICE ) = '\0';

        // PERCORRE A AGENDA PRA PROCURAR A PESSOA

        void *atual = INICIO_DA_AGENDA; 

        while ( atual != NULL && strcmp ( ( char * ) atual, ( char * ) ( NOME_BUSCADO ) ) != 0 ) {

            // NÃO ENCONTROU = COLOCA O NODO NO AUXILIAR E TIRA DA AGENDA

            void *novoNodo = malloc ( ( int ) ( 40 * sizeof ( char ) + sizeof ( int ) + 2 * sizeof ( char * ) ) );
            
            void *proximo = * ( void ** ) ( atual + PROX );
            memcpy ( novoNodo, atual, ( int ) ( 40 * sizeof ( char ) + sizeof ( int ) + 2 * sizeof ( char * ) ) );

            // INSERE NA AUXILIAR

            if ( INICIO_DA_AUXILIAR == NULL ) {
                
                * ( void ** ) ( novoNodo + ANT ) = NULL;
                * ( void ** ) ( novoNodo + PROX ) = NULL;
                INICIO_DA_AUXILIAR = novoNodo;
                FIM_DA_AUXILIAR = novoNodo;
            
            } else {
                
                void *p = INICIO_DA_AUXILIAR;
                void *anterior = NULL;
                while ( p != NULL && strcmp ( ( char * ) novoNodo, ( char * ) p ) > 0 ) {
                    anterior = p;
                    p = * ( void ** ) ( p + PROX );
                }
                if ( anterior == NULL ) {
                    * ( void ** ) ( novoNodo + PROX ) = p; 
                    if ( p != NULL ) {
                        * ( void ** ) ( p + ANT ) = novoNodo;
                    }
                    INICIO_DA_AUXILIAR = novoNodo;
                } else {
                    * ( void ** ) ( novoNodo + ANT ) = anterior;
                    * ( void ** ) ( novoNodo + PROX ) = p;
                    * ( void ** ) ( anterior + PROX ) = novoNodo;
                    if ( p != NULL ) {
                        * ( void ** ) ( p + ANT ) = novoNodo;
                    }
                }
                if ( p == NULL ) {
                    FIM_DA_AUXILIAR = novoNodo;
                    * ( void ** ) ( novoNodo + PROX ) = NULL;

                }
            }

            // TIRA O NODO DA AGENDA

            INICIO_DA_AGENDA = proximo;
            if ( proximo != NULL ) {
                * ( void ** ) ( proximo + ANT ) = NULL;
                free ( atual );
                atual = proximo;
            } else {
                free ( atual );
                atual = NULL;
            }

        }

        // IMPRIME O RESULTADO DA BUSCA
        if ( atual == NULL ) {
            printf ( "A pessoa %s nao foi encontrada na agenda.\n" , ( char * ) NOME_BUSCADO );
            free ( atual );
        } else {
            void *proximo = * ( void ** ) ( atual + PROX );
            INICIO_DA_AGENDA = proximo;
            if ( proximo != NULL ) {
                * ( void ** ) ( proximo + ANT ) = NULL;
                free ( atual );
                atual = proximo;
            } else {
                free ( atual );
                atual = NULL;
            }
        }

        // COLOCA OS NODOS DE VOLTA NA AGENDA
        if ( atual != NULL ) { 
            * ( void ** ) ( atual + ANT ) = NULL; 
        } else {
            FIM_DA_AGENDA = NULL; 
        }

        void *pessoa = INICIO_DA_AUXILIAR;
        while ( pessoa != NULL ) {
            void * prox = * ( void ** ) ( pessoa + PROX );
            AdicionarPessoa ( pessoa );
            pessoa = prox;
        }

        // LIMPA A AUXILIAR AO FINAL DE CADA BUSCA
        LimparAuxiliar ( );
        N_DE_PESSOAS -= 1;
    }
}


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

        printf ( "Digite o nome da pessoa a buscar: " );

        INDICE = 0; 
        CARACTERE = getchar ( );

        while ( CARACTERE != '\n' && CARACTERE != EOF ) {
            if ( INDICE < 20 ) {
                * ( char * ) ( NOME_BUSCADO + INDICE ) = CARACTERE;
                INDICE += 1;
            }
            CARACTERE = getchar(); 
        }

        * ( char * ) ( NOME_BUSCADO + INDICE ) = '\0';

        // PERCORRE A AGENDA PRA PROCURAR A PESSOA

        void *atual = INICIO_DA_AGENDA; 

        while ( atual != NULL && strcmp ( ( char * ) atual, ( char * ) ( NOME_BUSCADO ) ) != 0 ) {

            // NÃO ENCONTROU = COLOCA O NODO NO AUXILIAR E TIRA DA AGENDA

            void *novoNodo = malloc ( ( int ) ( 40 * sizeof ( char ) + sizeof ( int ) + 2 * sizeof ( char * ) ) );
            
            void *proximo = * ( void ** ) ( atual + PROX );
            memcpy(novoNodo, atual, ( int ) ( 40 * sizeof ( char ) + sizeof ( int ) + 2 * sizeof ( char * ) ) );

            // INSERE NA AUXILIAR

            if ( INICIO_DA_AUXILIAR == NULL ) {
                
                * ( void ** ) ( novoNodo + ANT ) = NULL;
                * ( void ** ) ( novoNodo + PROX ) = NULL;
                INICIO_DA_AUXILIAR = novoNodo;
                FIM_DA_AUXILIAR = novoNodo;
            
            } else {
                
                void *p = INICIO_DA_AUXILIAR;
                void *anterior = NULL;
                while ( p != NULL && strcmp ( ( char * ) novoNodo, ( char * ) p ) > 0 ) {
                    anterior = p;
                    p = * ( void ** ) ( p + PROX );
                }
                if ( anterior == NULL ) {
                    * ( void ** ) ( novoNodo + PROX ) = p; 
                    if ( p != NULL ) {
                        * ( void ** ) ( p + ANT ) = novoNodo;
                    }
                    INICIO_DA_AUXILIAR = novoNodo;
                } else {
                    * ( void ** ) ( novoNodo + ANT ) = anterior;
                    * ( void ** ) ( novoNodo + PROX ) = p;
                    * ( void ** ) ( anterior + PROX ) = novoNodo;
                    if ( p != NULL ) {
                        * ( void ** ) ( p + ANT ) = novoNodo;
                    }
                }
                if ( p == NULL ) {
                    FIM_DA_AUXILIAR = novoNodo;
                    * ( void ** ) ( novoNodo + PROX ) = NULL;

                }
            }

            // TIRA O NODO DA AGENDA

            INICIO_DA_AGENDA = proximo;
            if ( proximo != NULL ) {
                * ( void ** ) ( proximo + ANT ) = NULL;
                free ( atual );
                atual = proximo;
                N_DE_PESSOAS -=1;
            } else {
                free ( atual );
                atual = NULL;
                N_DE_PESSOAS -=1;
            }

        }

        // IMPRIME O RESULTADO DA BUSCA
        if ( atual == NULL ) {
            printf ( "A pessoa %s nao foi encontrada na agenda.\n" , ( char * ) NOME_BUSCADO );
            free ( atual );
        } else {
            printf ( "Nome: %s\n", ( char * ) atual );
            printf ( "Idade: %d\n", * ( int * ) ( atual + 20 ) );
            printf ( "Email: %s\n", ( char * ) ( atual + 24 ) );
        }

        // COLOCA OS NODOS DE VOLTA NA AGENDA
        if ( atual != NULL ) { 
            * ( void ** ) ( atual + ANT ) = NULL; 
        } else {
            FIM_DA_AGENDA = NULL; 
        }

        void *pessoa = INICIO_DA_AUXILIAR;
        while ( pessoa != NULL ) {
            void * prox = * ( void ** ) ( pessoa + PROX );
            AdicionarPessoa ( pessoa );
            pessoa = prox;
        }

        // LIMPA A AUXILIAR AO FINAL DE CADA BUSCA
        LimparAuxiliar ( );

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

    void *atual = INICIO_DA_AGENDA; 

    while ( atual != NULL ) {
        
        void *novoNodo = malloc ( ( int ) ( 40 * sizeof ( char ) + sizeof ( int ) + 2 * sizeof ( char * ) ) );
        if(novoNodo == NULL){
            printf ( "Erro ao alocar memoria." );
            exit ( 1 );
        }
        memcpy ( novoNodo, atual, 40 * sizeof ( char ) + sizeof ( int ) + 2 * sizeof ( char * ) );

        void *proximo = * ( void ** ) ( atual + PROX );

        printf ( "Nome: %s\n", ( char * ) atual );
        printf ( "Idade: %d\n", * ( int * ) ( atual + 20 ) );
        printf ( "Email: %s\n\n", ( char * ) ( atual + 24 ) );

        // INSERE NA AUXILIAR

        if ( INICIO_DA_AUXILIAR == NULL ) {
            
            * ( void ** ) ( novoNodo + ANT ) = NULL;
            * ( void ** ) ( novoNodo + PROX ) = NULL;
            INICIO_DA_AUXILIAR = novoNodo;
            FIM_DA_AUXILIAR = novoNodo;
        
        } else {
            
            void *p = INICIO_DA_AUXILIAR;
            void *anterior = NULL;
            while ( p != NULL && strcmp ( ( char * ) novoNodo, ( char * ) p ) > 0 ) {
                anterior = p;
                p = * ( void ** ) ( p + PROX );
            }
            if ( anterior == NULL ) {
                * ( void ** ) ( novoNodo + PROX ) = p; 
                if ( p != NULL ) {
                    * ( void ** ) ( p + ANT ) = novoNodo;
                }
                INICIO_DA_AUXILIAR = novoNodo;
            } else {
                * ( void ** ) ( novoNodo + ANT ) = anterior;
                * ( void ** ) ( novoNodo + PROX ) = p;
                * ( void ** ) ( anterior + PROX ) = novoNodo;
                if ( p != NULL ) {
                    * ( void ** ) ( p + ANT ) = novoNodo;
                }
            }
            if ( p == NULL ) {
                FIM_DA_AUXILIAR = novoNodo;
                * ( void ** ) ( novoNodo + PROX ) = NULL;

            }
        }

        // TIRA O NODO DA AGENDA

        INICIO_DA_AGENDA = proximo;
        if ( proximo != NULL ) {
            * ( void ** ) ( proximo + ANT ) = NULL;
            free ( atual );
            atual = proximo;
        } else {
            free ( atual );
            atual = NULL;
        }
    }
    // COLOCA OS NODOS DE VOLTA NA AGENDA
    if ( atual != NULL ) { 
        * ( void ** ) ( atual + ANT ) = NULL; 
    } else {
        FIM_DA_AGENDA = NULL; 
    }
    void *pessoa = INICIO_DA_AUXILIAR;
    while ( pessoa != NULL ) {
        void * prox = * ( void ** ) ( pessoa + PROX );
        AdicionarPessoa ( pessoa );
        pessoa = prox;
    }
    LimparAuxiliar();
}


/* ====================================================================================== 
LimparAgenda
    Percorre as pessoas na agenda ao fim da execução para dar free em cada uma e não
    gerar memory leak.
====================================================================================== */
void LimparAgenda ( ) {

    void *pessoaAtual = INICIO_DA_AGENDA;

    while ( pessoaAtual != NULL ) {
        void *proximaPessoa = * ( void ** ) ( pessoaAtual + PROX );
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
        void *proximaPessoa = * ( void ** ) ( pessoaAtual + PROX );
        free ( pessoaAtual );
        pessoaAtual = proximaPessoa;
    }

    INICIO_DA_AUXILIAR = NULL;
    FIM_DA_AUXILIAR = NULL;

}
