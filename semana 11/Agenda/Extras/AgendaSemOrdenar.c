
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
void BuscarPessoa( );
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
            BuscarPessoa( );
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

void AdicionarPrimeiraPessoa(){

    pAgenda = malloc ( 52 );

    * ( int * )( pBuffer + 9 ) = 0; // indice das strings

    printf ( "Digite o nome: " );

    * ( char * ) pBuffer = getchar( );
    while ( ( * ( char * ) pBuffer != '\n' ) && ( * ( char * ) pBuffer != EOF ) ) {
        * ( char * )( pAgenda + * ( int * )( pBuffer + 9 )) = * ( char * ) pBuffer;
        * ( int * )( pBuffer + 9 ) += 1;
        * ( char * ) pBuffer = getchar( );
    }
    * ( char * )( pAgenda + * ( int * )( pBuffer + 9 )) = '\0';

    printf ( "Digite a idade: " );

    scanf("%d",(int *)(pAgenda + 20));
    getchar ( );

    * ( int * )( pBuffer + 9 ) = 0; // zera o indice para ler o email

    printf ( "Digite o email: " );

    * ( char * ) pBuffer = getchar( );
    while ( ( * ( char * ) pBuffer != '\n' ) && ( * ( char * ) pBuffer != EOF ) ) {
        * ( char * )( pAgenda + * ( int * )( pBuffer + 9 ) + 24) = * ( char * ) pBuffer;
        * ( int * )( pBuffer + 9 ) += 1;
        * ( char * ) pBuffer = getchar( );
    }
    * ( char * )( pAgenda + * ( int * )( pBuffer + 9 ) + 24) = '\0';

    // Anterior e proximo:
    *(char **)(pAgenda + 44) = NULL;
    *(char **)(pAgenda + 48) = NULL;

    * ( int * )( pBuffer + 5 ) = * ( int * )( pBuffer + 5 ) + 1; // aumenta o numero de pessoas na pAgenda
    *(char **)(pBuffer + 17) = (char *)pAgenda; // atualiza o primeiro nodo
    *(char **)(pBuffer + 21) = (char *)pAgenda; // atualiza o ultimo nodo

}

void AdicionarPessoa(){
    * ( int * )( pBuffer + 5 ) += 1; // aumenta o numero de pessoas para o realloc
    pAgenda = realloc(pAgenda, (* ( int * )( pBuffer + 5 )) * 52);
    
    * ( int * )( pBuffer + 13 ) = * ( int * )( pBuffer + 5 ) - 1; // auxiliar - guarda o indice da pessoa atual

   * ( int * )( pBuffer + 9 ) = 0; // indice das strings

    printf ( "Digite o nome: " );
    * ( char * )pBuffer = getchar( );
    while ( ( * ( char * ) pBuffer != '\n' ) && ( * ( char * ) pBuffer != EOF ) ) {
        * ( char * )( pAgenda + ( * ( int * )( pBuffer + 9 ) + 52 * ( * ( int * )( pBuffer + 13 )))) = * ( char * ) pBuffer;
        * ( int * )( pBuffer + 9 ) += 1;
        * ( char * ) pBuffer = getchar( );
    }
    * ( char * )( pAgenda + ( * ( int * )( pBuffer + 9 ) + 52 * ( * ( int * )( pBuffer + 13 )))) = '\0';

    printf ( "Digite a idade: " );
    scanf ( "%d", ( int * )( pAgenda + 20 + 52 * ( * ( int * )( pBuffer + 13 ))));
    getchar ( );
    
    * ( int * )( pBuffer + 9 ) = 0; // zera o indice para ler o email

    printf ( "Digite o email: " );
    * ( char * )pBuffer = getchar( );
    while ( ( * ( char * ) pBuffer != '\n' ) && ( * ( char * ) pBuffer != EOF ) ) {
        * ( char * )( pAgenda + ( * ( int * )( pBuffer + 9 ) + 24 + 52 * ( * ( int * )( pBuffer + 13 )))) = * ( char * ) pBuffer;
        * ( int * )( pBuffer + 9 ) += 1;
        * ( char * ) pBuffer = getchar( );
    }

    // atualizando os ponteiros
    if (*(int *)(pBuffer + 5) > 1) {
        *(char **)(pAgenda + (52 * (*(int *)(pBuffer + 13))) + 44) = pAgenda + (52 * ((*(int *)(pBuffer + 13)) - 1));
        *(char **)(pAgenda + (52 * ((*(int *)(pBuffer + 13)) - 1)) + 48) = pAgenda + (52 * (*(int *)(pBuffer + 13)));
    } else {
        *(char **)(pAgenda + 44) = NULL;
    }
    *(char **)(pAgenda + (52 * (*(int *)(pBuffer + 13))) + 48) = NULL;

}

void RemoverPessoa(){
    printf("Nome: %s\n", (char *)pAgenda + 52 * (*(int *)(pBuffer + 13)));
}

void BuscarPessoa(){
    if ( * ( int * )( pBuffer + 5 ) == 0 ) {
        printf( "Agenda está vazia.\n" );
        return;
    }

    printf ( "Digite o nome da pessoa a ser buscada: " );
    // vai armazenar a string em pBuffer + 29

    * ( int * )( pBuffer + 9 ) = 0; 
    * ( char * )pBuffer = getchar( );
    while ( ( * ( char * ) pBuffer != '\n' ) && ( * ( char * ) pBuffer != EOF ) ) {
        * ( char * )( pBuffer + 29 + ( * ( int * )( pBuffer + 9 ))) = * ( char * ) pBuffer;
        * ( int * )( pBuffer + 9 ) += 1;
        * ( char * ) pBuffer = getchar( );
    }
    * ( char * )( pBuffer + 29 + ( * ( int * )( pBuffer + 9 ))) = '\0';

    /**(char **)(pBuffer + 25) = ( char * )( pAgenda);// ponteiro para percorrer as pessoas: pBuffer + 25
    * ( char * )( pBuffer + 25 + ( * ( int * )( pBuffer + 9 ))) = '\0';
    for (*(int *)(pBuffer + 25) = 0; *(int *)(pBuffer + 25) < *(int *)(pBuffer + 5) && (strcmp(*(char **)(pBuffer + 25),* ( char * )( pBuffer + 29))!=0); (*(int *)(pBuffer + 25)) += 1){
        *(char **)(pBuffer + 25) += 52;
    }*/
   
    void *current = *(void **)(pBuffer + 17); // Ponteiro para a primeira pessoa
    while (current != NULL && strcmp((char *)current, (char *)(pBuffer + 29)) != 0) {
        current = *(void **)(current + 48); // Próxima pessoa
    }

    if(*(int *)(pBuffer + 25) == *(int *)(pBuffer + 5)){
        printf("Pessoa nao encontrada na agenda.'\n'");
    }
    printf("Nome: %s\n", (char *)pAgenda + 52 * (*(int *)(pBuffer + 13)));
}

void ListarPessoas(){
    if ( * ( int * )( pBuffer + 5 ) == 0 ) {
        printf( "Agenda está vazia.\n" );
        return;
    }
    for (*(int *)(pBuffer + 13) = 0; *(int *)(pBuffer + 13) < *(int *)(pBuffer + 5); (*(int *)(pBuffer + 13)) += 1) {
        printf("Nome: %s\n", (char *)pAgenda + 52 * (*(int *)(pBuffer + 13)));
        printf("Idade: %d\n", *(int *)((char *)pAgenda + 20 + 52 * (*(int *)(pBuffer + 13))));
        printf("Email: %s\n", (char *)pAgenda + 24 + 52 * (*(int *)(pBuffer + 13)));
    }
}



