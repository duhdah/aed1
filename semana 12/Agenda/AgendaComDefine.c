#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// É a mesma agenda, mas usa define pra ficar mais legível!

#define caractere * ( char * ) ( pBuffer )
#define entrada  * ( int * ) ( pBuffer + 1 )
#define nPessoas  * ( int * ) ( pBuffer + 5 )
#define indice * ( int * ) ( pBuffer + 9)
#define inicioAgenda * ( void ** ) ( pBuffer + 13 )
#define fimAgenda * ( void ** ) ( pBuffer + 21 )
#define stringBusca pBuffer + 29 
#define inicioAuxiliar * ( void ** ) ( pBuffer + 37 )
#define fimAuxiliar * ( void ** ) ( pBuffer + 45 )

void *pBuffer;

// Tamanho de um "nodo" de Pessoa:
// 20 char (nome) + 1 int (idade) + 20 char (email) + 2 char *(next e prev)
// Total em bytes: 20 + 4 + 20 + 8 + 8 = 60

/*
pBuffer[0] = getchar (char = 1 byte)  -> pBuffer                                       OK
pBuffer[1] = ler entrada (int = 4 bytes)  -> pBuffer + 1                               OK
pBuffer[2] = numero de pessoas na agenda (int = 4 bytes)  -> pBuffer + 5               OK
pBuffer[3] = numero de letras em uma string (int = 4 bytes)  -> pBuffer + 9            OK
pBuffer[4] = inicio da agenda (char * = 8 bytes) - > pBuffer + 13                      OK
pBuffer[5] = fim da agenda (char * = 4 bytes) - > pBuffer + 21                         OK
pBuffer[6] = le string de buscar (20 char = 20 bytes) - > pBuffer + 29                 OK
pBuffer[7] = inicio da fila auxiliar (char * = 8 bytes) - > pBuffer + 37               OK
pBuffer[8] = fim da fila auxiliar (char * = 8 bytes) - > pBuffer + 45                  OK

TOTAL: 53 BYTES           

*/

void AdicionarPessoa ( );
void RemoverPessoa ( );
void *BuscarPessoa ( );
void ListarPessoas ( );
void LimparAgenda ( );
void LimparAuxiliar ( );

int main ( ) {

    pBuffer = malloc ( 53 ); 
    entrada = 0;
    nPessoas = 0; 
    inicioAgenda = NULL;
    inicioAuxiliar = NULL; 

    while ( entrada != 5 ) {
        printf( "Escolha uma opcao:\n1) Adicionar pessoa\n2) Remover pessoa\n3) Buscar pessoa\n4) Listar pessoas\n5) Sair\nEntrada: " );
        scanf( "%d", ( int * ) ( pBuffer + 1 ) );
        getchar ( );

        if ( entrada == 1 ) {
            AdicionarPessoa ( ) ;
        }

        if ( entrada  == 2 ) {
            RemoverPessoa ( );
        }

        if ( entrada  == 3 ) {
            void *busca = inicioAgenda;
            busca = BuscarPessoa ( );
            if ( busca == NULL ) {
                printf ( "Pessoa nao encontrada na agenda.\n" );
            } else {
                printf ( "Nome: %s\n", ( char * ) busca );
                printf ( "Idade: %d\n", * ( int * ) ( busca + 20 ) );
                printf ( "Email: %s\n", ( char * ) busca + 24 );
            }
        }

        if ( entrada  == 4 ) {
            ListarPessoas ( );
        }

        if ( entrada == 5 ) {
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

void AdicionarPessoa ( ) {
    void *novaPessoa = malloc ( 60 );
    indice = 0; 

    printf( "Digite o nome: " );
    caractere = getchar ( ); 
    while ( * ( char * ) pBuffer != '\n' && * ( char * ) pBuffer != EOF ) {
        if ( indice < 20 ) { 
            * ( char * ) ( novaPessoa + indice ) = * ( char * ) pBuffer; 
            indice += 1;
        }
        caractere = getchar ( );
    }
    * ( char * ) ( novaPessoa + indice ) = '\0';

    printf ( "Digite a idade: " );
    scanf ( "%d", ( int * ) ( novaPessoa + 20 ) );
    getchar ( );

    indice = 0; 

    printf( "Digite o email: " );
    caractere = getchar ( );
    while ( * ( char * ) pBuffer != '\n' && * ( char * ) pBuffer != EOF ) {
        if ( indice < 20 ) { 
            * (char * ) ( novaPessoa + indice + 24 ) = * ( char * ) pBuffer;
            indice += 1;
        }
        caractere = getchar ( );
    }
    * ( char * ) ( novaPessoa + indice + 24 ) = '\0';

    * ( void ** ) ( novaPessoa + 44 ) = NULL; 
    * ( void ** ) ( novaPessoa + 52 ) = NULL; 

    if ( nPessoas == 0 ) {

        inicioAgenda = novaPessoa;
        fimAgenda = novaPessoa;
        
    } else {

        void *atual = inicioAgenda; 
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

            inicioAgenda = novaPessoa;

        } else {

            * ( void ** ) ( novaPessoa + 44 ) = anterior;
            * ( void ** ) ( novaPessoa + 52 ) = atual;
            * ( void ** ) ( anterior + 52 ) = novaPessoa;
            
            if ( atual != NULL ) {
                * ( void ** ) ( atual + 44 ) = novaPessoa;
            }

        }

        if ( atual == NULL ) {
            fimAgenda = novaPessoa;
        }
        
    }

    nPessoas += 1;

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

    if ( nPessoas == 0 ) {
        printf ( "Agenda esta vazia.\n" );
        return;
    }

    void *busca = BuscarPessoa ( );

    if ( busca == NULL ) {

        printf( "Pessoa nao encontrada na agenda.\n" );

    } else {

        if ( busca == inicioAgenda ) {

            if ( nPessoas == 1 ) {
                inicioAgenda = NULL;
                fimAgenda = NULL;
                nPessoas = 0;
                free ( busca );

            } else {

                * ( void ** ) ( * ( void ** ) ( busca + 52 ) + 44 ) = NULL;
                inicioAgenda = * ( void ** ) ( busca + 52 );
                nPessoas -= 1;
                free ( busca );
            }

        } else if ( busca == fimAgenda ) {
            * ( void ** ) ( * ( void ** ) ( busca + 44 ) + 52 ) = NULL;
            * (void ** ) ( pBuffer + 21 ) = * ( void ** ) ( busca + 44 ); 
            nPessoas -= 1; 
            free ( busca );

        } else {

            * ( void ** ) ( * ( void ** ) ( busca + 44 ) + 52 ) = * ( void ** ) ( busca + 52 );
            * ( void ** ) ( * ( void ** ) ( busca + 52 ) + 44) = * ( void ** ) ( busca + 44 );
            nPessoas -= 1;
            free ( busca );
            
        }

        printf ( "Pessoa removida da lista.\n" );

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


void *BuscarPessoa ( ) {
    if ( nPessoas == 0 ) {
        printf ( "Agenda esta vazia.\n" );
        return NULL;
    }

    printf ( "Digite o nome da pessoa: " );

    indice = 0; 
    caractere = getchar ( );
    while ( caractere != '\n' && caractere != EOF ) {
        if ( indice < 20 ) {
            * ( char * ) ( stringBusca + indice ) = * ( char * ) pBuffer;
            indice += 1;
        }
        caractere = getchar(); 
    }
    * ( char * ) ( stringBusca + indice ) = '\0';

    void *atual = inicioAgenda; 
    void *filaAuxInicio = NULL; 
    
    while ( atual != NULL && strcmp ( ( char * ) atual, ( char * ) ( stringBusca ) ) != 0 ) {

        void *novoNodo = malloc ( 60 );
        
        strcpy ( ( char * ) novoNodo, ( char * ) atual );
        * ( int * ) ( novoNodo + 20 ) = * ( int * ) ( atual + 20 );
        strcpy ( ( char * ) ( novoNodo + 24 ), ( char * ) ( atual + 24 ) );

        if ( filaAuxInicio == NULL ) {
            * ( void ** ) ( novoNodo + 44 ) = NULL;
            * ( void ** ) ( novoNodo + 52 ) = NULL;
        } else {
            * ( void ** ) ( novoNodo + 52 ) = filaAuxInicio;
            * ( void ** ) ( filaAuxInicio + 44 ) = novoNodo;
            * ( void ** ) ( novoNodo + 44 ) = NULL;
        }

        filaAuxInicio = novoNodo; 
        atual = * ( void ** ) ( atual + 52 ); 

    }

    inicioAgenda = atual;
    if ( atual != NULL ) { 
        * ( void ** ) ( atual + 44 ) = NULL; 
    } else {
        fimAgenda = NULL; 
    }

    while ( filaAuxInicio != NULL ) {

        void *proximaAux = * ( void ** ) ( filaAuxInicio + 52 );

        if ( inicioAgenda == NULL) {

            inicioAgenda = filaAuxInicio;
            fimAgenda = filaAuxInicio;
            * ( void ** ) ( filaAuxInicio + 44 ) = NULL;
            * ( void ** ) ( filaAuxInicio + 52 ) = NULL;
        
        } else {

            * ( void ** ) ( filaAuxInicio + 52 ) = inicioAgenda; 
            * ( void ** ) ( inicioAgenda + 44 ) = filaAuxInicio; 
            * ( void ** ) ( filaAuxInicio + 44 ) = NULL;
            inicioAgenda = filaAuxInicio; 
        }

        filaAuxInicio = proximaAux;

    }

    return atual;
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

    if ( nPessoas == 0 ) {
        printf ( "Agenda está vazia.\n" );
        return;
    }

    inicioAuxiliar = NULL; 
    fimAuxiliar = NULL; 

    while ( inicioAgenda != NULL ) {

        void *atual = inicioAgenda; 

        printf ( "Nome: %s\n", ( char * ) atual );
        printf ( "Idade: %d\n", * ( int * ) ( atual + 20 ) );
        printf ( "Email: %s\n\n", ( char * ) ( atual + 24 ) );

        inicioAgenda = * ( void ** ) ( atual + 52 ); 

        if ( inicioAgenda != NULL ) {
            * ( void ** ) ( inicioAgenda + 44 ) = NULL;
        } else {
            fimAgenda = NULL;
        }

        * ( int * ) (pBuffer + 5) -= 1;

        if ( inicioAuxiliar == NULL ) { 

            inicioAuxiliar = atual; 
            fimAuxiliar = atual; 
            * ( void ** ) ( atual + 44 ) = NULL;
            * ( void ** ) ( atual + 52 ) = NULL;
            
        } else {

            * ( void ** ) ( fimAuxiliar + 52 ) = atual;
            * ( void ** ) ( atual + 44 ) = fimAuxiliar; 
            * ( void ** ) ( atual + 52 ) = NULL;
            fimAuxiliar = atual;
            
        }
    }

    void *pessoaAtual = inicioAuxiliar;

    while ( pessoaAtual != NULL ) {

        void *proximaAuxiliar = * ( void ** ) ( pessoaAtual + 52 );

        if ( inicioAgenda == NULL ) { 
            inicioAgenda = pessoaAtual; 
            fimAgenda = pessoaAtual; 
            * ( void ** ) ( pessoaAtual + 44 ) = NULL; 
            * ( void ** ) ( pessoaAtual + 52 ) = NULL; 
            
        } else {

            void * fim = fimAgenda;
            * ( void ** ) ( fim + 52 ) = pessoaAtual; 
            * ( void ** ) ( pessoaAtual + 44 ) = fim;
            * ( void ** ) ( pessoaAtual + 52 ) = NULL;
            fimAgenda = pessoaAtual;
            
        }

        nPessoas += 1;

        pessoaAtual = proximaAuxiliar;

    }

    inicioAuxiliar = NULL;
    fimAuxiliar = NULL;

}


/* ====================================================================================== 
LimparAgenda

    Percorre as pessoas na agenda ao fim da execução para dar free em cada uma e não
    gerar memory leak.
====================================================================================== */
void LimparAgenda ( ) {

    void *pessoaAtual = inicioAgenda;

    while ( pessoaAtual != NULL ) {
        void *proximaPessoa = * ( void ** ) ( pessoaAtual + 52 );
        free ( pessoaAtual );
        pessoaAtual = proximaPessoa;
    }

    inicioAgenda = NULL;
    fimAgenda = NULL;

}

/* ====================================================================================== 
LimparAuxiliar

    Percorre as pessoas na fila auxiliar ao fim da execução para dar free em cada uma e 
    não gerar memory leak.
====================================================================================== */
void LimparAuxiliar ( ) {

    void *pessoaAtual = inicioAuxiliar;

    while ( pessoaAtual != NULL ) {
        void *proximaPessoa = * ( void ** ) ( pessoaAtual + 52 );
        free ( pessoaAtual );
        pessoaAtual = proximaPessoa;
    }

    inicioAuxiliar = NULL;
    fimAuxiliar = NULL;

}
