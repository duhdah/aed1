#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

Essa é a agenda final, mas com a ideia de fazer o realloc adaptado conforme necessidade.

*/


// DEFINE REFERENTE ÀS POSIÇÕES DAS INFORMAÇÕES NOS NODOS DAS PESSOAS:
#define IDADE ( int ) ( 20 * sizeof ( char ) )
#define EMAIL ( int ) ( 20 * sizeof ( char ) + sizeof ( int ) )
#define ANT ( int ) ( 40 * sizeof ( char ) + sizeof ( int ) )
#define PROX ( int ) ( 40 * sizeof ( char ) + sizeof ( int ) + sizeof ( char * ) )

void *pBuffer = NULL;

void AdicionarPessoa ( void * nodo );
void RemoverPessoa ( );
void BuscarPessoa ( );
void ListarPessoas ( );
void LimparAgenda ( );
void LimparAuxiliar ( );

int main ( ) {
    pBuffer = malloc ( sizeof ( int ) + 2 * sizeof ( char * ) );
    if ( pBuffer == NULL ) {
        printf ( "Erro ao alocar memoria de pBuffer." );
        exit ( 1 );
    }
    int *entrada = ( int * )( pBuffer );
    void **inicioDaAgenda = ( void ** ) ( pBuffer + sizeof ( int ) );
    void **fimDaAgenda = ( void ** ) ( pBuffer + sizeof ( int ) + sizeof ( void * ) );
    *entrada = 0;
    inicioDaAgenda = NULL;
    fimDaAgenda = NULL;

    while ( *entrada != 5 ) {
        printf( "Escolha uma opcao:\n1) Adicionar pessoa\n2) Remover pessoa\n3) Buscar pessoa\n4) Listar pessoas\n5) Sair\nEntrada: " );
        scanf ( "%d", entrada );
        getchar ( );
        
        if ( *entrada == 1 ) {
            // ordem: entrada, caractere, indice, nodo, inicioDaAgenda, fimDaAgenda
            pBuffer = realloc ( pBuffer, 41 * sizeof ( char ) + 3 * sizeof (int ) + 4 * sizeof ( void * ) );
            entrada = (int *)(pBuffer);
            char *caractere = ( char * ) ( pBuffer + sizeof ( int ) );
            int *indice = ( int * )( pBuffer + sizeof ( char ) + sizeof ( int ) );
            void *nodoAuxiliar = ( pBuffer + sizeof (char) + 2 * sizeof ( int ) );
            inicioDaAgenda = ( void ** ) ( pBuffer + 41 * sizeof (char) + 3 * sizeof ( int ) + 2 * sizeof ( void * ) );
            fimDaAgenda = ( void ** ) ( pBuffer + 41 * sizeof (char) + 3 * sizeof ( int ) + 3 * sizeof ( void * ) );
            *indice = 0;
            
            printf ( "\nDigite o nome: " );
            *caractere = getchar ( ); 
            while ( *caractere != '\n' && *caractere != EOF ) {
                if ( *indice < 20 ) { 
                    * ( char * ) ( nodoAuxiliar + *indice ) = *caractere; 
                    *indice += 1;
                }
                *caractere = getchar ( );
            }
            * ( char * ) (  nodoAuxiliar + *indice ) = '\0';

            printf ( "Digite a idade: " );
            scanf ( "%d", ( int * ) (  nodoAuxiliar + IDADE ) );
            getchar ( );

            *indice = 0; 

            printf ( "Digite o email: " );
            *caractere = getchar ( );
            while ( *caractere != '\n' && *caractere != EOF ) {
                if ( *indice < 20 ) { 
                    * (char * ) ( nodoAuxiliar + *indice + EMAIL ) = *caractere;
                    *indice += 1;
                }
                *caractere = getchar ( );
            }
            * ( char * ) ( nodoAuxiliar + *indice + EMAIL ) = '\0';

            * ( void ** ) (  nodoAuxiliar + ANT ) = NULL; 
            * ( void ** ) (  nodoAuxiliar + PROX ) = NULL; 
            AdicionarPessoa ( nodoAuxiliar );
            printf( "\n" );

        }

        if ( *entrada  == 2 ) {
            RemoverPessoa ( );
        }

        if ( *entrada  == 3 ) {
            BuscarPessoa ( );
        }

        if ( *entrada  == 4 ) {
            ListarPessoas ( );
        }

        if ( *entrada == 5 ) {
            printf ( "Agenda encerrada." );
            LimparAgenda ( );
            LimparAuxiliar ( );
            free ( pBuffer ); 
            return 0;
        }
    }
}
    
void AdicionarPessoa ( void *nodo ){
    // antiga ordem: entrada, caractere, indice, nodo, inicioDaAgenda, fimDaAgenda
    // nova ordem: nodo, inicioDaAgenda, fimDaAgenda
    void *novoBuffer = malloc ( 40 * sizeof ( char ) + sizeof ( int ) + 4 * sizeof ( void * ) );
    memcpy ( novoBuffer, ( pBuffer + 2 * sizeof ( int ) + sizeof ( char ) ) , 40 * sizeof ( char ) + sizeof ( int ) + 4 * sizeof ( void * ) );
    pBuffer = novoBuffer;
    free(novoBuffer);
    void *nodoAuxiliar = pBuffer;
    void **inicioDaAgenda = ( void ** ) ( pBuffer + sizeof ( 40 * sizeof ( char ) + sizeof ( int ) + 2 * sizeof ( void * ) ) );
    void **fimDaAgenda = ( void ** ) ( pBuffer + sizeof ( 40 * sizeof ( char ) + sizeof ( int ) + 2 * sizeof ( void * ) ) );

    void *novaPessoa = malloc ( 40 * sizeof ( char ) + sizeof ( int ) + 3 * sizeof ( void * ) );
    if ( novaPessoa == NULL ) {
        printf ( "Erro ao alocar memoria." );
        exit ( 1 );
    }
    memcpy ( novaPessoa, nodo, ( int ) ( 40 * sizeof ( char ) + sizeof ( int ) + 2 * sizeof (char * ) ) );

    if ( *inicioDaAgenda == NULL ) {
        *inicioDaAgenda = novaPessoa;
        *fimDaAgenda = novaPessoa;
    } else {

        void *atual = *inicioDaAgenda; 
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

            *inicioDaAgenda = novaPessoa;

        } else {

            * ( void ** ) ( novaPessoa + ANT ) = anterior;
            * ( void ** ) ( novaPessoa + PROX ) = atual;
            * ( void ** ) ( anterior + PROX ) = novaPessoa;
            
            if ( atual != NULL ) {
                * ( void ** ) ( atual + ANT ) = novaPessoa;
            }

        }

        if ( atual == NULL ) {
            *fimDaAgenda = novaPessoa;
        }
        
    }
    pBuffer = realloc ( pBuffer, sizeof (int ) + 2 * sizeof ( void * ) );
    int *entrada = ( int * ) ( pBuffer );
    *entrada = 0;
    inicioDaAgenda = ( pBuffer + sizeof ( int ) );
    fimDaAgenda = ( pBuffer + sizeof ( int ) + sizeof ( void * ) );

}

void RemoverPessoa ( ){
    // fazendo
}

void BuscarPessoa ( ){
    // fazendo
}

void ListarPessoas ( ){
    // fazendo
}

void LimparAgenda ( ) {
    // fazendo
}

void LimparAuxiliar ( ) {
    // fazendo
}
