#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *pBuffer;

// Tamanho de um "nodo" de Pessoa:
// 20 char (nome) + 1 int (idade) + 20 char (email) + 2 char *(next e prev)
// Total em bytes: 20 + 4 + 20 + 8 + 8 = 60

/*
Nesse código, NÃO FUNCIONA A REMOVERPESSOAS.
No entanto, o problema de memory leak causado pelo BuscarPessoa foi corrigido.
*/



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

int main () {
    pBuffer = malloc ( 53 ); // inicializa pBuffer com o numero exato de bytes usados

    * (int * ) ( pBuffer + 1 ) = 0; // para ler a entrada:
    *( int * ) ( pBuffer + 5 ) = 0; // numero de pessoas na agenda
    * ( void ** ) ( pBuffer + 13 ) = NULL; // inicio da fila principal
    * ( void ** ) ( pBuffer + 37 ) = NULL; // inicio da fila auxiliar

    while ( * ( int * ) ( pBuffer + 1 ) != 5 ) {
        printf( "Escolha uma opcao:\n1) Adicionar pessoa\n2) Remover pessoa\n3) Buscar pessoa\n4) Listar pessoas\n5) Sair\nEntrada: " );
        scanf( "%d", ( int * ) ( pBuffer + 1 ) );
        getchar ( );

        // adiciona pessoa se escolha = 1
        if ( * ( int * ) ( pBuffer + 1 ) == 1 ) {
            AdicionarPessoa ( ) ;
        }

        // remove pessoa se escolha = 2
        if ( * ( int * ) ( pBuffer + 1 ) == 2 ) {
            RemoverPessoa ( );
        }

        // busca pessoa se escolha = 3
        // OBS: BuscarPessoa retorna NULL se não encontrar a pessoa
        if ( * ( int * ) ( pBuffer + 1 ) == 3 ) {
            void *busca = * ( void ** ) ( pBuffer + 13 );
            busca = BuscarPessoa ( );
            if ( busca == NULL ) {
                printf ( "Pessoa nao encontrada na agenda.\n" );
            } else {
                printf ( "Nome: %s\n", ( char * ) busca );
                printf ( "Idade: %d\n", * ( int * ) ( busca + 20 ) );
                printf ( "Email: %s\n", ( char * ) busca + 24 );
            }
        }

        // lista pessoas se escolha = 4
        if ( * ( int * ) ( pBuffer + 1 ) == 4 ) {
            ListarPessoas ( );
        }

        // sai da agenda se escolha = 5
        if ( * ( int * ) ( pBuffer + 1 ) == 5 ) {
            printf ( "Agenda encerrada." );
            LimparAgenda ( ); // função para dar free nos nodos da agenda
            LimparAuxiliar ( ); // função para dar free nos nodos da fila auxiliar
            free ( pBuffer ); 
            return 0;
        }
    }
    return 0;
}

void AdicionarPessoa ( ) {
    void *novaPessoa = malloc ( 60 ); // pode dar malloc pq é um "nodo" da agenda
    * ( int * ) ( pBuffer + 9 ) = 0; // usado como índice da string

    printf( "Digite o nome: " );
    * ( char * ) pBuffer = getchar ( ); // posição pBuffer é usada como getchar()
    while ( * ( char * ) pBuffer != '\n' && * ( char * ) pBuffer != EOF ) {
        if (* (int * ) ( pBuffer + 9)  < 20 ) { // se passar de 20 char, não armazena
            * ( char * ) ( novaPessoa + * ( int * ) ( pBuffer + 9 ) ) = * ( char * ) pBuffer; 
                // armazena no endereço do nodo somado com o indice do char atual
            * ( int * ) ( pBuffer + 9 ) += 1;
        }
        * ( char * ) pBuffer = getchar ( );
    }
    * ( char * ) ( novaPessoa + * ( int * ) ( pBuffer + 9 ) ) = '\0';

    printf ( "Digite a idade: " );
    scanf ( "%d", ( int * ) ( novaPessoa + 20 ) ); // lê em novaPessoa + 20 pq 20 bytes são reservados para o nome!
    getchar ( );

    * ( int * ) ( pBuffer + 9 ) = 0; // zera o índice para ler outra string (email)

    printf( "Digite o email: " );
    * ( char * ) pBuffer = getchar ( );
    while ( * ( char * ) pBuffer != '\n' && * ( char * ) pBuffer != EOF ) {
        if ( * ( int * ) ( pBuffer + 9 ) < 20 ) {
            * (char * ) ( novaPessoa + * ( int * ) ( pBuffer + 9 ) + 24 ) = * ( char * ) pBuffer;
            * ( int * ) ( pBuffer + 9 ) += 1;
        }
        * ( char * ) pBuffer = getchar ( );
    }
    * ( char * ) ( novaPessoa + * ( int * ) ( pBuffer + 9 ) + 24 ) = '\0';

    * ( void ** ) ( novaPessoa + 44 ) = NULL; // inicializa o ponteiro anterior do nodo como NULL
    * ( void ** ) ( novaPessoa + 52 ) = NULL; // inicializa o ponteiro próximo do nodo como NULL

    if ( * ( int * ) ( pBuffer + 5 ) == 0 ) { // verifica se a agenda está vazia

        // se a agenda está vazia, os ponteiros de início e fim da agenda são atualizados para o nodo atual
        * ( void ** ) ( pBuffer + 13 ) = novaPessoa;
        * ( void ** ) ( pBuffer + 21 ) = novaPessoa;
        
    } else {

        // se a agenda já tem pessoas, precisamos achar a posição certa para inserir a pessoa em ordem alfabética

        void *atual = * ( void ** ) ( pBuffer + 13 ); // ponteiro para a primeira pessoa da agenda
        void *anterior = NULL; // ponteiro para a pessoa anterior do nosso ponteiro atual

        // compara o nome da pessoa atual com o nome da pessoa no nodo a ser inserido enquanto o nome da pessoa que queremos inserir for maior que a do ponteiro
        while ( atual != NULL && strcmp ( ( char * ) novaPessoa, ( char * ) atual) > 0) {
            anterior = atual;
            atual = * ( void ** )( atual + 52 ); // basicamente, atual=atual->prox
        }

        // quando sair do while, é pq encontrou a posição onde deve inserir e devemos atualizar os ponteiros!

        if ( anterior == NULL ) {

            // inserindo no começo:
            * ( void ** ) ( novaPessoa + 52 ) = atual; // novaPessoa->prox = atual;
            if ( atual != NULL ) { // se atual não for o fim da agenda
                * ( void ** ) ( atual + 44 ) = novaPessoa; // atual->ant = novaPessoa;
            }
            * ( void ** ) ( pBuffer + 13 ) = novaPessoa; // atualiza o começo da agenda!

        } else {
            // inserindo no meio ou no fim da agenda
            * ( void ** ) ( novaPessoa + 44 ) = anterior; // novaPessoa->ant = ant;
            * ( void ** ) ( novaPessoa + 52 ) = atual; //novaPessoa->prox = atual;
            * ( void ** ) ( anterior + 52 ) = novaPessoa; // anterior->prox = novaPessoa;
            if ( atual != NULL ) { // se atual não for o fim da agenda
                * ( void ** ) ( atual + 44 ) = novaPessoa; // atual->ant = novaPessoa;
            }
        }

        // verifica se o atual é nulo para atualizar o fim da agenda se for:
        if ( atual == NULL ) {
            * ( void ** ) ( pBuffer + 21 ) = novaPessoa;
        }
        
    }
    * ( int * ) ( pBuffer + 5 ) += 1; // aumenta o número de pessoas na agenda (pBuffer+5 guarda o número de pessoas na agenda)
}

void RemoverPessoa () {
    // verificando se a agenda está vazia:
    if ( * ( int * )( pBuffer + 5 ) == 0 ) {
        printf ( "Agenda esta vazia.\n" );
        return;
    }

    // usei a função buscarPessoa para retornar o ponteiro para o que devemos remover da fila
    void *busca = BuscarPessoa ( );
    if ( busca == NULL ) {
        // se não encontrar a pessoa, avisa e não faz nada
        printf( "Pessoa nao encontrada na agenda.\n" );
    } else {
        if ( busca == * ( void ** ) ( pBuffer + 13 ) ) { // se a pessoa for a primeira da fila
            if ( * ( int * ) ( pBuffer + 5 ) == 1 ) {  // e se só tem uma pessoa na fila
                * ( void ** ) ( pBuffer + 13 ) = NULL; // atualiza o inicio da fila
                * ( void ** ) ( pBuffer + 21 ) = NULL; // atualiza o fim da fila
                * ( int * ) ( pBuffer + 5 ) = 0; // zera o número de pessoas na agenda
                free ( busca );
            } else { // se temos que remover a primeira pessoa e tem mais de uma pessoa na fila
                * ( void ** ) ( * ( void ** ) ( busca + 52 ) + 44 ) = NULL; // busca->prox->ant = NULL; 
                * ( void ** ) ( pBuffer + 13 ) = * ( void ** ) ( busca + 52 ); // inicio da lista vira busca->prox
                * ( int * ) ( pBuffer + 5 ) -= 1; // diminui o tamanho da lista
                free ( busca );
            }
        } else if ( busca == * ( void ** ) ( pBuffer + 21 ) ) { // se a pessoa for a última da lista
            // se só tivesse 1 pessoa na lista, teria entrado no primeiro if, então só pode ter mais de uma
            * ( void ** ) ( * ( void ** ) ( busca + 44 ) + 52 ) = NULL; // busca->ant->prox = NULL;
            * ( void ** ) ( pBuffer + 21 ) = * ( void ** ) ( busca + 44 ); // fim da lista vira busca->ant
            * ( int * ) ( pBuffer + 5 ) -= 1; // diminui o tamanho da lista
            free ( busca );
        } else { // removendo no meio da lista
            * ( void ** ) ( * ( void ** ) ( busca + 44 ) + 52 ) = * ( void ** ) ( busca + 52 ); // busca->ant->prox = busca->prox;
            * ( void ** ) ( * ( void ** ) ( busca + 52 ) + 44) = * ( void ** ) ( busca + 44 ); // busca->prox->ant = busca->ant;
            * ( int * ) ( pBuffer + 5 ) -= 1; // diminui o tamanho da lista
            free ( busca );
        }
        printf ( "Pessoa removida da lista.\n" );
    }
}



void *BuscarPessoa ( ) {
    if ( * ( int * ) ( pBuffer + 5 ) == 0 ) {
        printf ( "Agenda esta vazia.\n" );
        return NULL;
    }

    printf ( "Digite o nome da pessoa: " );

    // a string de busca é armazenada em pBuffer + 29
    // pBuffer novamente é usado como getchar e índice da string
     
    * ( int * ) ( pBuffer + 9 ) = 0; 
    * ( char * ) pBuffer = getchar ( );
    while ( * ( char * ) pBuffer != '\n' && * ( char * ) pBuffer != EOF ) {
        if ( * ( int * ) ( pBuffer + 9 ) < 20 ) {
            * ( char * ) ( pBuffer + 29 + * ( int * ) ( pBuffer + 9 ) ) = * ( char * ) pBuffer;
            * ( int * ) ( pBuffer + 9 ) += 1;
        }
        * ( char * ) pBuffer = getchar(); 
    }
    * ( char * ) ( pBuffer + 29 + * ( int * ) ( pBuffer + 9 ) ) = '\0';

    // inicializa os ponteiros da fila auxiliar:
    * ( void ** ) ( pBuffer + 37 ) = NULL; // ponteiro de inicio
    * ( void ** ) ( pBuffer + 45 ) = NULL; // ponteiro do fim

    void *atual = * ( void ** ) ( pBuffer + 13 ); // percorre a fila principal
    while ( * ( void ** ) ( pBuffer + 13 ) != NULL && strcmp ( ( char * ) atual, ( char * ) ( pBuffer + 29 ) ) != 0 ) {
        
        
        // remove o nodo do início da fila principal
        * ( void ** ) ( pBuffer + 13 ) = * ( void ** ) ( atual + 52 ); // atualiza o início da fila principal para a próxima pessoa da agenda
        if ( * ( void ** ) ( pBuffer + 13 ) != NULL ) {
            * ( void ** ) ( * ( void ** ) ( pBuffer + 13 ) + 44 ) = NULL; // se a fila principal não estiver vazia, atualiza o inicio dela
        } else {
            * ( void ** ) ( pBuffer + 21 ) = NULL; // se a fila principal estiver vazia, atualiza o fim
        }

        // diminui o tamanho da lista principal
        * ( int * ) (pBuffer + 5) -= 1;

        // adiciona o nodo na fila auxiliar
        if ( * ( void ** ) ( pBuffer + 37 ) == NULL ) { // se a fila auxiliar estiver vazia:

            * ( void ** ) ( pBuffer + 37 ) = atual; // o nodo vira o inicio da fila auxiliar
            * ( void ** ) ( pBuffer + 45 ) = atual; // o nodo vira o fim da fila auxiliar
            * ( void ** ) ( atual + 44 ) = NULL; // atual->ant = NULL
            * ( void ** ) ( atual + 52 ) = NULL; // atual->prox = NULL
            
        } else { // se a fila auxiliar não estiver vazia:

            * ( void ** ) ( atual + 52 ) = * ( void ** ) ( pBuffer + 37 ); // atual->prox = inicio da fila auxiliar
            * ( void ** ) ( * ( void ** ) ( pBuffer + 37 ) + 44 ) = atual; //inicio da fila auxiliar ->prox = atual
            * ( void ** ) ( atual + 44 ) = NULL; // atual->ant = NULL
            * ( void ** ) ( pBuffer + 37 ) = atual; // o nodo vira o inicio da fila auxiliar
        
        }
        atual = * ( void ** ) ( pBuffer + 13 ); 
    }


    // insere as pessoas da fila auxiliar na fila principal novamente
    void *pessoaAtual = * ( void ** ) ( pBuffer + 37 ); // o ponteiro auxiliar começa no inicio da fila auxiliar
    while ( pessoaAtual != NULL ) {
        void *proximaAuxiliar = * ( void ** ) ( pessoaAtual + 52 ); // pessoaAtual->prox

        if ( * ( void ** ) ( pBuffer + 13 ) == NULL ) { // se não tiver ninguém na fila
            * ( void ** ) ( pBuffer + 13 ) = pessoaAtual; // pessoaAtual vira inicio da fila
            * ( void ** ) ( pBuffer + 21 ) = pessoaAtual; // pessoaAtual vira fim da fila
            * ( void ** ) ( pessoaAtual + 44 ) = NULL; // pessoaAtual->ant = NULL
            * ( void ** ) ( pessoaAtual + 52 ) = NULL; // pessoaAtual->prox = NULL
        } else {
            void * inicio = * ( void ** ) ( pBuffer + 13 ); // ponteiro para o fim da fila princiapl
            * ( void ** ) ( pessoaAtual + 52 ) = inicio; // pessoaAtual->prox = inicio
            * ( void ** ) ( pessoaAtual + 44 ) = NULL; // pesssoaAtual->ant = NULL
            * ( void ** ) ( pBuffer + 13 ) = pessoaAtual; // pessoaAtual vira inicio da fila principal
        }

        // aumenta o número de pessoas na fila principal
        * ( int * ) ( pBuffer + 5 ) += 1;

        pessoaAtual = proximaAuxiliar;
    }

    // zera os ponteiros da fila auxiliar
    * ( void ** ) ( pBuffer + 37 ) = NULL;
    * ( void ** ) ( pBuffer + 45 ) = NULL;
    
    return atual;
    
}

void ListarPessoas ( ) {
    // verifica se a agenda está vazia:
    if ( * ( int * ) ( pBuffer + 5 ) == 0 ) {
        printf ( "Agenda está vazia.\n" );
        return;
    }

    // inicializa os ponteiros da fila auxiliar:
    * ( void ** ) ( pBuffer + 37 ) = NULL; // ponteiro de inicio
    * ( void ** ) ( pBuffer + 45 ) = NULL; // ponteiro do fim

    // verifica se a fila já estava vazia e imprime os nodos enquanto não estiver:
    while ( * ( void ** ) ( pBuffer + 13 ) != NULL ) {
        void *atual = * ( void ** ) ( pBuffer + 13 ); // percorre a fila principal

        // imprime o conteúdo da pessoa atual
        printf ( "Nome: %s\n", ( char * ) atual );
        printf ( "Idade: %d\n", * ( int * ) ( atual + 20 ) );
        printf ( "Email: %s\n\n", ( char * ) ( atual + 24 ) );

        // remove o nodo do início da fila principal
        * ( void ** ) ( pBuffer + 13 ) = * ( void ** ) ( atual + 52 ); // atualiza o início da fila principal para a próxima pessoa da agenda
        if ( * ( void ** ) ( pBuffer + 13 ) != NULL ) {
            * ( void ** ) ( * ( void ** ) ( pBuffer + 13 ) + 44 ) = NULL; // se a fila principal não estiver vazia, atualiza o inicio dela
        } else {
            * ( void ** ) ( pBuffer + 21 ) = NULL; // se a fila principal estiver vazia, atualiza o fim
        }

        // diminui o tamanho da lista principal
        * ( int * ) (pBuffer + 5) -= 1;

        // adiciona o nodo na fila auxiliar
        if ( * ( void ** ) ( pBuffer + 37 ) == NULL ) { // se a fila auxiliar estiver vazia:

            * ( void ** ) ( pBuffer + 37 ) = atual; // o nodo vira o inicio da fila auxiliar
            * ( void ** ) ( pBuffer + 45 ) = atual; // o nodo vira o fim da fila auxiliar
            * ( void ** ) ( atual + 44 ) = NULL; // atual->ant = NULL
            * ( void ** ) ( atual + 52 ) = NULL; // atual->prox = NULL
            
        } else { // se a fila auxiliar não estiver vazia:

            * ( void ** ) ( * ( void ** ) ( pBuffer + 45 ) + 52 ) = atual; // fim->prox = atual
            * ( void ** ) ( atual + 44 ) = * ( void ** ) ( pBuffer + 45 ); // atual->ant = fim
            * ( void ** ) ( atual + 52 ) = NULL; // atual->prox = NULL
            * ( void ** ) ( pBuffer + 45 ) = atual; // o nodo vira o fim da fila auxiliar
            
        }
    }

    // insere as pessoas da fila auxiliar na fila principal novamente
    void *pessoaAtual = * ( void ** ) ( pBuffer + 37 ); // o ponteiro auxiliar começa no inicio da fila auxiliar
    while ( pessoaAtual != NULL ) {
        void *proximaAuxiliar = * ( void ** ) ( pessoaAtual + 52 ); // pessoaAtual->prox

        if ( * ( void ** ) ( pBuffer + 13 ) == NULL ) { // se não tiver ninguém na fila
            * ( void ** ) ( pBuffer + 13 ) = pessoaAtual; // pessoaAtual vira inicio da fila
            * ( void ** ) ( pBuffer + 21 ) = pessoaAtual; // pessoaAtual vira fim da fila
            * ( void ** ) ( pessoaAtual + 44 ) = NULL; // pessoaAtual->ant = NULL
            * ( void ** ) ( pessoaAtual + 52 ) = NULL; // pessoaAtual->prox = NULL
        } else {
            void * fim = * ( void ** ) ( pBuffer + 21 ); // ponteiro para o fim da fila princiapl
            * ( void ** ) ( fim + 52 ) = pessoaAtual; // fim->prox = pessoaAtual
            * ( void ** ) ( pessoaAtual + 44 ) = fim; // pessoaAtual-> ant = fim
            * ( void ** ) ( pessoaAtual + 52 ) = NULL; // pesssoaProx = NULL
            * ( void ** ) ( pBuffer + 21 ) = pessoaAtual; // pessoaAtual vira fim da fila principal
        }

        // aumenta o número de pessoas na fila principal
        * ( int * ) ( pBuffer + 5 ) += 1;

        pessoaAtual = proximaAuxiliar;
    }

    // zera os ponteiros da fila auxiliar
    * ( void ** ) ( pBuffer + 37 ) = NULL;
    * ( void ** ) ( pBuffer + 45 ) = NULL;
}

void LimparAgenda ( ) {

    void *pessoaAtual = * ( void ** ) ( pBuffer + 13 );

    while ( pessoaAtual != NULL ) {
        void *proximaPessoa = * ( void ** ) ( pessoaAtual + 52 );
        free ( pessoaAtual );
        pessoaAtual = proximaPessoa;
    }

    * ( void ** ) ( pBuffer + 13 ) = NULL;
    * ( void ** ) ( pBuffer + 21 ) = NULL;

    printf ( "A agenda foi limpa.\n" );
}


void LimparAuxiliar ( ) {
    void *pessoaAtual = * ( void ** ) ( pBuffer + 37 );

    while ( pessoaAtual != NULL ) {
        void *proximaPessoa = * ( void ** ) ( pessoaAtual + 52 );
        free ( pessoaAtual );
        pessoaAtual = proximaPessoa;
    }

    * ( void ** ) ( pBuffer + 37 ) = NULL;
    * ( void ** ) ( pBuffer + 45 ) = NULL;

    printf ( "A fila auxiliar foi limpa.\n" );
}
