
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *pBuffer;

// Tamanho de um "nodo" de Pessoa:
// 20 char (nome) + 1 int (idade) + 20 char (email) + 2 char *(next e prev)
// Total em bytes: 20 + 4 + 20 + 8 = 52

/*
TERCEIRA TENTATIVA:
    Deixei de usar o pAgenda, porém, não havia me dado conta que precisava implementar as funções BuscarPessoas e ListarPessoas
    usando as regras da heap também. Tinha focado apenas na inserção.
*/

/*

pBuffer[0] = getchar (char = 1 byte)  -> pBuffer
pBuffer[1] = ler entrada (int = 4 bytes)  -> pBuffer + 1
pBuffer[2] = numero de pessoas na agenda (int = 4 bytes)  -> pBuffer + 5
pBuffer[3] = numero de letras em uma string (int = 4 bytes)  -> pBuffer + 9
pBuffer[4] = int auxiliar (int = 4 bytes)  -> pBuffer + 13
pBuffer[5] = inicio da agenda (char * = 4 bytes) - > pBuffer + 17
pBuffer[6] = fim da agenda (char * = 4 bytes) - > pBuffer + 25      
pBuffer[7] = le string de buscar (20 char = 20 bytes) - > pBuffer + 29

*/

void AdicionarPessoa ( );
void RemoverPessoa ( );
void *BuscarPessoa ( );
void ListarPessoas ( );

int main ( ) {

    pBuffer = malloc ( 49 );

    * ( int * )( pBuffer + 1 ) = 0; // para ler a entrada:
    * ( int * )( pBuffer + 5) = 0; // numero de pessoas na agenda

    while ( * ( int * )( pBuffer + 1 ) != 5 ) {

        printf ( "Escolha uma opcao:\n1) Adicionar pessoa\n2) Remover pessoa\n3) Buscar pessoa\n4) Listar pessoas\n5) Sair\nEntrada: " );
        scanf ( "%d", ( int * )( pBuffer + 1 ) ); 
        getchar ( );

        if( * ( int * )( pBuffer + 1 ) == 1 ) {  
            AdicionarPessoa ( );
        }

        // Remover pessoa:
        if ( * ( int * )( pBuffer + 1 ) == 2 ){
            RemoverPessoa ( );
        }

        // Buscar pessoa:
        if ( * ( int * )( pBuffer + 1 ) == 3 ){
            void *busca = * ( void ** )( pBuffer + 17 );
            busca = BuscarPessoa ( );
            if ( busca == NULL ) {
                printf( "Pessoa nao encontrada na agenda.\n" );
            } else {
                printf( "Nome: %s\n", (char * ) busca );
                printf( "Idade: %d\n", * ( int * )( busca + 20 ));
                printf( "Email: %s\n", ( char * ) busca + 24 );
            }
        }

        // Listar pessoas:
        if ( * ( int * )( pBuffer + 1 ) == 4 ) {
            ListarPessoas ( );
        }
        
        // Sair
        if ( * ( int * )( pBuffer + 1 ) == 5 ) {
            printf ( "Agenda encerrada." );
            free ( pBuffer );
            return 0;
        }
    }
    return 0;
}

void AdicionarPessoa ( ) {
    void *novaPessoa = malloc ( 52 );
    * ( int * )( pBuffer + 9 ) = 0; // índice das strings

    printf( "Digite o nome: " );
    * ( char * ) pBuffer = getchar ( );
    while ( * ( char * ) pBuffer != '\n' && * ( char * ) pBuffer != EOF ) {
        if ( * ( int * )( pBuffer + 9 ) < 20) { // para não passar de 20 char
            * ( char * )( novaPessoa + * ( int * )( pBuffer + 9 ) ) = * ( char * ) pBuffer;
            * ( int * )( pBuffer + 9 ) += 1;
        }
        * ( char * ) pBuffer = getchar ( );
    }
    * ( char * )( novaPessoa + * ( int * )( pBuffer + 9 ) ) = '\0';

    printf( "Digite a idade: " );
    scanf( "%d", ( int * )( novaPessoa + 20 ));
    getchar ( );

    * ( int * )( pBuffer + 9 ) = 0; // zera o índice para ler o email

    printf( "Digite o email: " );
    * ( char * ) pBuffer = getchar ( );
    while ( * ( char * ) pBuffer != '\n' && * ( char * ) pBuffer != EOF ) {
        if ( * ( int * )( pBuffer + 9 ) < 20 ) {
            * ( char * )( novaPessoa + * ( int * )( pBuffer + 9 ) + 24 ) = * ( char * ) pBuffer;
            * ( int * )( pBuffer + 9 ) += 1;
        }
        * ( char * ) pBuffer = getchar();
    }
    * ( char * )( novaPessoa + * ( int * )( pBuffer + 9 ) + 24 ) = '\0';

    * ( void ** )( novaPessoa + 44 ) = NULL; // inicializa o ponteiro anterior
    * ( void ** )( novaPessoa + 48 ) = NULL; // inicializa o ponteiro próximo

    if ( * ( int * )( pBuffer + 5 ) == 0 ) {
        // Se a lista estiver vazia, novaPessoa é a primeira e única pessoa na lista
        * ( void ** )( pBuffer + 17 ) = novaPessoa;
        * ( void ** )( pBuffer + 25 ) = novaPessoa;
    } else {
        void *atual = * ( void ** )( pBuffer + 17 ); // ponteiro para a primeira pessoa da lista
        void *anterior = NULL; // ponteiro para a pessoa anterior

        // encontra a posição correta para inserir novaPessoa alfabeticamente
        while ( atual != NULL && strcmp ( ( char * ) novaPessoa, ( char * ) atual) > 0) {
            anterior = atual;
            atual = * ( void ** )( atual + 48 );
        }

        if (anterior == NULL) {
            // insere no começo
            * ( void ** )( novaPessoa + 48 ) = atual;
            if (atual != NULL) {
                * ( void ** )( atual + 44 ) = novaPessoa;
            }
            * ( void ** )( pBuffer + 17 ) = novaPessoa;
        } else {
            // insere no meio ou no fim
            * ( void ** )( novaPessoa + 44 ) = anterior;
            * ( void ** )( novaPessoa + 48 ) = atual;
            * ( void ** )( anterior + 48 ) = novaPessoa;
            if (atual != NULL) {
                * ( void ** )( atual + 44 ) = novaPessoa;
            }
        }

        // se for a última pessoa, atualiza o fim da lista
        if ( atual == NULL ) {
            * ( void ** )( pBuffer + 25 ) = novaPessoa;
        }
    }

    * ( int * )( pBuffer + 5 ) += 1; // aumenta o número de pessoas na lista
}



void RemoverPessoa ( ) {
    if ( * ( int * )( pBuffer + 5 ) == 0) {
        printf( "Agenda esta vazia.\n" );
        return;
    }

    void *busca = BuscarPessoa ( );
    if ( busca == NULL ) {
        printf( "Pessoa nao encontrada na agenda.\n" );
    } else {
        if ( busca == * ( void ** )( pBuffer + 17 ) ) { // se a pessoa for a primeira da lista
            if ( * ( int * )( pBuffer + 5 ) == 1 ) {
                * ( void ** )( pBuffer + 17 ) = NULL;
                * ( void ** )( pBuffer + 25 ) = NULL;
                * ( int * )( pBuffer + 5 ) = 0;
                free ( busca );
            } else {
                * ( void ** )( * ( void ** )( busca + 48 ) + 44 ) = NULL; // busca->prox->ant = NULL; 
                * ( void ** )( pBuffer + 17 ) = * ( void ** )( busca + 48 ); // inicio da lista vira busca->prox
                * ( int * )( pBuffer + 5 ) -= 1; // diminui o tamanho da lista
                free ( busca );
            }
        } else if ( busca == * ( void ** )( pBuffer + 25 ) ) { // se a pessoa for a ultima da lista
            // se só tivesse 1 pessoa na lista, teria entrado no primeiro if, então só pode ter mais de uma
            * ( void ** )( * ( void ** )( busca + 44 ) + 48 ) = NULL; // busca->ant->prox = NULL;
            * ( void ** )( pBuffer + 25 ) = * ( void ** )( busca + 44 ); // fim da lista vira busca->ant
            * ( int * )( pBuffer + 5 ) -= 1; // diminui o tamanho da lista
            free ( busca );
        } else {
            * ( void ** )( * ( void ** )( busca + 44 ) + 48 ) = * ( void ** )( busca + 48 ); // busca->ant->prox = busca->prox;
            * ( void ** )( * ( void ** )( busca + 48 ) + 44 ) = * ( void ** )( busca + 44 ); // busca->prox->ant = busca->ant;
            * ( int * )( pBuffer + 5 ) -= 1; // diminui o tamanho da lista
            free ( busca );
        }
        printf( "Pessoa removida da lista.\n" );
    }
}


void *BuscarPessoa () {
    if ( * ( int * )( pBuffer + 5 ) == 0 ) {
        printf( "Agenda esta vazia.\n" );
        return NULL;
    }

    printf( "Digite o nome da pessoa: " );

    // a string de busca é armazenda em pBuffer + 33

    * ( int * )( pBuffer + 9 ) = 0; 
    * ( char * ) pBuffer = getchar ( );
    while ( * ( char * ) pBuffer != '\n' && * ( char * ) pBuffer != EOF ) {
        if ( * ( int * )( pBuffer + 9 ) < 20 ){
            * ( char * )( pBuffer + 33 + * ( int * )( pBuffer + 9 ) ) = * ( char * ) pBuffer;
            * ( int * )( pBuffer + 9 ) += 1;
        }
        * ( char * ) pBuffer = getchar ( ); 
    }
    * ( char * )( pBuffer + 33 + * ( int * )( pBuffer + 9 ) ) = '\0';

    // o ponteiro é um ponteiro auxiliar para a busca
    void *atual = * ( void ** )( pBuffer + 17 ); // inicia com a primeira pessoa da lista
    while ( atual != NULL && strcmp ( ( char * ) atual, ( char * )( pBuffer + 33 ) ) != 0 ) {
        atual = * ( void ** )( atual + 48 );
    }
    return atual;
}


void ListarPessoas ( ) {

    if ( * ( int * )( pBuffer + 5 ) == 0 ) {
        printf( "Agenda esta vazia.\n" );
        return;
    }

    void *pessoaAtual = * ( char ** )( pBuffer + 17 );
    while ( pessoaAtual != NULL ) {
        printf( "Nome: %s\n", (char * ) pessoaAtual );
        printf( "Idade: %d\n", * ( int * )( pessoaAtual + 20 ) );
        printf( "Email: %s\n\n", (char *) pessoaAtual + 24 );
        pessoaAtual = * ( char ** )( pessoaAtual + 48 );
    }
    
}

void LimparAgenda ( ) {
    if ( * ( int * )( pBuffer + 5 ) == 0 ) {
        printf ( "Agenda esta vazia.\n" );
        return;
    }

    void *pessoaAtual = * ( void ** )( pBuffer + 17 );

    while ( pessoaAtual != NULL ) {
        void *proximaPessoa = * ( void ** )( pessoaAtual + 48 ); 
        free ( pessoaAtual );
        pessoaAtual = proximaPessoa;
    }

    * (void ** )( pBuffer + 17 ) = NULL;
    * ( void ** )( pBuffer + 25 ) = NULL;
    * ( int * )( pBuffer + 5 ) = 0;

    printf( "Agenda limpa.\n" );
}