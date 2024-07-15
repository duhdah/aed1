
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *pAgenda;
void *pBuffer;

// Tamanho de um "nodo" de Pessoa:
// 20 char (nome) + 1 int (idade) + 20 char (email) + 2 char *(next e prev)
// Total em bytes: 20 + 4 + 20 + 8 = 52

/*
pBuffer[0] = getchar (char = 1 byte)  -> pBuffer
pBuffer[1] = ler entrada (int = 4 bytes)  -> pBuffer + 1
pBuffer[2] = numero de pessoas na agenda (int = 4 bytes)  -> pBuffer + 5
pBuffer[3] = numero de letras em uma string (int = 4 bytes)  -> pBuffer + 9
pBuffer[4] = int auxiliar (int = 4 bytes)  -> pBuffer + 13
pBuffer[5] = inicio da agenda (char * = 4 bytes) - > pBuffer + 17
pBuffer[6] = fim da agenda (char * = 4 bytes) - > pBuffer + 21
pBuffer[7] = ponteiro auxiliar (char * = 4 bytes) - > pBuffer + 25
pBuffer[8] = le string de buscar (20 char = 20 bytes) - > pBuffer + 29

*/

void AdicionarPrimeiraPessoa( );
void AdicionarPessoa( );
void RemoverPessoa( );
void *BuscarPessoa( );
void ListarPessoas( );

int main ( ) {

    pBuffer = malloc(100);
    pAgenda = NULL; 

    * ( int * )( pBuffer + 1 ) = 0; // para ler a entrada:
    * ( int * )( pBuffer + 5) = 0; // numero de pessoas na agenda

    while( * ( int * )( pBuffer + 1 ) != 5 ){

        printf ( "Escolha uma opcao:\n1) Adicionar pessoa\n2) Remover pessoa\n3) Buscar pessoa\n4) Listar pessoas\n5) Sair\nEntrada: " );
        scanf ( "%d", ( int * )( pBuffer + 1 ) ); 
        getchar ( );

        if( * ( int * )( pBuffer + 1 ) == 1 ) {  
            if ( pAgenda == NULL ) {
                AdicionarPrimeiraPessoa();
            } else {
                AdicionarPessoa();
            }
        }

        // Remover pessoa:
        if ( * ( int * )( pBuffer + 1 ) == 2 ){
            RemoverPessoa( );
        }

        // Buscar pessoa:
        if ( * ( int * )( pBuffer + 1 ) == 3 ){
            void *busca = * ( void ** )( pBuffer + 17 );
            busca = BuscarPessoa( );
            if (busca == NULL) {
                printf( "Pessoa nao encontrada na agenda.\n" );
            } else {
                printf( "Nome: %s\n", (char * ) busca );
                printf( "Idade: %d\n", * ( int * )( busca + 20 ));
                printf( "Email: %s\n", ( char * ) busca + 24 );
            }
        }

        // Listar pessoas:
        if ( * ( int * )( pBuffer + 1 ) == 4 ){
            ListarPessoas( );
        }
        
        // Sair
        if ( * ( int * )( pBuffer + 1 ) == 5 ){
            printf ( "Agenda encerrada." );
            free ( pAgenda );
            free ( pBuffer );
            return 0;
        }
    }
    return 0;
}

void AdicionarPrimeiraPessoa ( ) {

    pAgenda = malloc ( 52 );

    * ( int * )( pBuffer + 9 ) = 0; // índice das strings

    printf ( "Digite o nome: " );

    * ( char * ) pBuffer = getchar ( );
    while ( ( * ( char * ) pBuffer != '\n' ) && ( * ( char * ) pBuffer != EOF ) ) {
        if ( * ( int * )( pBuffer + 9 ) < 20 ) { // pra não passar de 20 char
            * ( char * )( pAgenda + * ( int * )( pBuffer + 9 )) = * ( char * ) pBuffer;
            * ( int * )( pBuffer + 9 ) += 1; 
        }
        * ( char * ) pBuffer = getchar ( );
    }
    * ( char * )( pAgenda + * ( int * )( pBuffer + 9 )) = '\0';

    printf ( "Digite a idade: " );

    scanf("%d", ( int * ) (pAgenda + 20 ));
    getchar ( );

    * ( int * )( pBuffer + 9 ) = 0; // zera o indice para ler o email

    printf ( "Digite o email: " );

    * ( char * ) pBuffer = getchar ( );
    while ( ( * ( char * ) pBuffer != '\n' ) && ( * ( char * ) pBuffer != EOF ) ) {
        if ( * ( int * )( pBuffer + 9 ) < 20 ){
            * ( char * )( pAgenda + * ( int * )( pBuffer + 9 ) + 24) = * ( char * ) pBuffer;
            * ( int * )( pBuffer + 9 ) += 1; 
        }
        * ( char * ) pBuffer = getchar ( );
    }
    * ( char * )( pAgenda + * ( int * )( pBuffer + 9 ) + 24) = '\0';

    // Ponteiros anterior e proximo:
    * ( char ** )( pAgenda + 44 ) = NULL;
    * ( char ** )( pAgenda + 48 ) = NULL;

    * ( int * )( pBuffer + 5 ) += 1; // aumenta o numero de pessoas na pAgenda
    * ( char ** )( pBuffer + 17 ) = ( char * ) pAgenda;

}

void AdicionarPessoa(){
    
    pAgenda = realloc(pAgenda, (* ( int * )( pBuffer + 5 ) + 1) * 52); // aloca espaço para +1 pessoa
    
    * ( int * )( pBuffer + 13 ) = * ( int * )( pBuffer + 5 ); // auxiliar - guarda o indice da pessoa atual
    * ( int * )( pBuffer + 5 ) += 1; // aumenta o numero de pessoas para o realloc
    * ( int * )( pBuffer + 9 ) = 0; // indice das strings

    printf ( "Digite o nome: " );
    * ( char * ) pBuffer = getchar ( );
    while ( ( * ( char * ) pBuffer != '\n' ) && ( * ( char * ) pBuffer != EOF ) ) {
        if ( * ( int * )( pBuffer + 9 ) < 20 ){
            * ( char * )( pAgenda + ( * ( int * )( pBuffer + 9 ) + 52 * ( * ( int * )( pBuffer + 13 )))) = * ( char * ) pBuffer;
            * ( int * )( pBuffer + 9 ) += 1;
        }
        * ( char * ) pBuffer = getchar ( ); 
    }
    * ( char * )( pAgenda + ( * ( int * )( pBuffer + 9 ) + 52 * ( * ( int * )( pBuffer + 13 )))) = '\0';

    printf ( "Digite a idade: " );
    scanf ( "%d", ( int * )( pAgenda + 20 + 52 * ( * ( int * )( pBuffer + 13 ))));
    getchar ( );
    
    * ( int * )( pBuffer + 9 ) = 0; // zera o indice para ler o email

    printf ( "Digite o email: " );
    * ( char * ) pBuffer = getchar ( );
    while ( ( * ( char * ) pBuffer != '\n' ) && ( * ( char * ) pBuffer != EOF ) ) {
        if ( * ( int * )( pBuffer + 9 ) < 20 ){
            * ( char * )( pAgenda + ( * ( int * )( pBuffer + 9 ) + 24 + 52 * ( * ( int * )( pBuffer + 13 )))) = * ( char * ) pBuffer;
            * ( int * )( pBuffer + 9 ) += 1;
        }
        * ( char * ) pBuffer = getchar ( );
    }
    * ( char * )( pAgenda + ( 52 * ( * ( int * )( pBuffer + 13 ))) + 24 + * ( int * )( pBuffer + 9 )) = '\0';

    // mexendo nos ponteiros:
    // troquei * ( char ** ) para * ( void ** ) para usar o ponteiro mais generico e evitar possiveis erros

    // declaração de novos ponteiros do tipo void para ficar mais fácil de referenciar as posições e mais legivel
    void *novaPessoa = pAgenda + 52 * ( * ( int * )( pBuffer + 13 )); // ponteiro que aponta para o nodo atual
    void *atual = * ( void ** )( pBuffer + 17 ); // ponteiro auxiliar para encontrar a posicao correta para o nodo atual
    void *anterior = NULL; // ponteiro auxiliar anterior ao atual

    // encontra a posição certa pra inserir alfabeticamente
    while (atual != NULL && strcmp((char *)novaPessoa, (char *)atual) > 0) {
        anterior = atual;
        atual = * ( void ** )( atual + 48 );
    }

    // teste pra ver onde inserir
    if (anterior == NULL) {

        // insere no começo
        * ( void ** )( novaPessoa + 44 ) = NULL; // novaPessoa->prev = NULL;
        * ( void ** )( novaPessoa + 48 ) = atual; // novaPessoa->next = atual;
        if (atual != NULL) {
            * ( void **)(atual + 44 ) = novaPessoa; // atual->prev = novaPessoa;
        }
        * ( void ** )( pBuffer + 17 ) = novaPessoa; // atualiza o começo da agenda

    } else {

        // insere no meio ou no fim
        * ( void ** )( novaPessoa + 44 ) = anterior; // novaPessoa-> prev = anterior;
        * ( void ** )( novaPessoa + 48 ) = atual; // novaPessoa->next = 
        * ( void ** )( anterior + 48 ) = novaPessoa;
    
        if ( atual != NULL ) {
            * ( void ** )( atual + 44 ) = novaPessoa;
        }

    }

    // se for a ultima pessoa, atualiza o fim da lista
    if ( atual == NULL ) {
        * ( void ** )( pBuffer + 21 ) = novaPessoa;
    }

}

void RemoverPessoa(){

}

void *BuscarPessoa() {
    if ( * ( int * )( pBuffer + 5 ) == 0 ) {
        printf( "Agenda esta vazia.\n" );
        return NULL;
    }

    printf( "Digite o nome da pessoa a ser buscada: " );

    // a string de busca é armazenda em pBuffer + 29

    * ( int * )( pBuffer + 9 ) = 0; 
    * ( char * ) pBuffer = getchar ( );
    while ( * ( char * ) pBuffer != '\n' && * ( char * ) pBuffer != EOF ) {
        if ( * ( int * )( pBuffer + 9 ) < 20 ){
            * ( char * )( pBuffer + 29 + * ( int * )( pBuffer + 9 )) = * ( char * ) pBuffer;
            * ( int * )( pBuffer + 9 ) += 1;
        }
        * ( char * ) pBuffer = getchar ( ); 
    }
    * ( char * )( pBuffer + 29 + * ( int * )( pBuffer + 9 )) = '\0';

    // o ponteiro é um ponteiro auxiliar para a busca
    void *atual = * ( void ** )( pBuffer + 17 ); // inicia com a primeira pessoa da lista
    while ( atual != NULL && strcmp ( ( char * ) atual, ( char * )( pBuffer + 29 )) != 0 ) {
        atual = * ( void ** )( atual + 48 );
    }
    return atual;
}


/* Lista na ordem da memoria pra ver se alocou (nao na alfabetica):
void ListarPessoas(){
    if ( * ( int * )( pBuffer + 5 ) == 0) {
        printf( "Agenda esta vazia.\n" );
        return;
    }
    for ( * ( int * )( pBuffer + 13 ) = 0; * ( int * )( pBuffer + 13 ) < * ( int * )( pBuffer + 5 ); (*(int *)(pBuffer + 13)) += 1) {
        printf("Nome: %s\n", (char *)pAgenda + 52 * (*(int *)(pBuffer + 13)));
        printf("Idade: %d\n", *(int *)((char *)pAgenda + 20 + 52 * (*(int *)(pBuffer + 13))));
        printf("Email: %s\n", (char *)pAgenda + 24 + 52 * (*(int *)(pBuffer + 13)));
    }
}
*/

void ListarPessoas() {

    if ( * ( int * )( pBuffer + 5 ) == 0 ) {
        printf( "Agenda esta vazia.\n" );
        return;
    }

    void *pessoaAtual = * ( char ** )( pBuffer + 17 );
    while ( pessoaAtual != NULL ) {
        printf( "Nome: %s\n", (char * ) pessoaAtual );
        printf( "Idade: %d\n", * ( int * )( pessoaAtual + 20 ));
        printf( "Email: %s\n\n", (char *) pessoaAtual + 24 );
        pessoaAtual = * ( char ** )( pessoaAtual + 48 );
    }
    
}


