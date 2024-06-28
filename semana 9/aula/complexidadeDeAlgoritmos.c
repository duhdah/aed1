#include <stdio.h>

/*
Qual a importância de saber qual algoritmo de ordenação e busca usar?
Quantas vezes temos que escolher?
O que acontece se escolher o errado?
    -> Vai ser menor eficiente
    -> Afeta o usuário
    -> "Sistema lento" 
    -> Desperdício de energia
*/

// ORDENAÇÃO (SORT)
// Dado um conjunto de dados armazenados em ordem aleatória, reordená-los com base em uma regra de precedência.
// -> Qual a regra de precedência para números? Mais próximo de 0 é menor, mais dígitos é maior
// -> Qual a regra de precedência para nomes? Pode ser ordem alfabética, por idade, por tamanho do nome...

// => MÉTODO DE INSERÇÃO (INSERTION SORT)
/*
Método do jogador de cartas: Verifica as cartas em ordem se são menores que o número a colocar, e se não forem, o número entra antes dessa posição.

7, 2, 8, 5, 9
O 2 em relação ao 7. Quem vem antes? O 2
2, 7, 8, 5, 9
O 7 em relação ao 8. Quem vem antes? O 7
Vai comparando um com o outro...

*/

void InsertionSort (int data[], int n);

int main(){
    int valores[5];
    printf("Digite 5 inteiros:");
    for(int i = 0; i < 5; i++){
        scanf("%d",&valores[i]);
    }
    InsertionSort(valores,5);
    printf("Lista ordenada: ");
    for(int i = 0; i < 5; i++){
        printf("%d ",valores[i]);
    }
}

void InsertionSort (int data[], int n){
    int tmp, i, j; // leva sempre a mesma quantidade de tempo (não depende de n) tempo levado = 1
    for(j = 1; j < n; j++){ // faz n iterações.  tempo levado = n + 1 (soma com o de cima)
        i = j - 1; // essa linha é executada uma vez a cada execução. tempo levado (1)n + 1
        tmp = data[j]; // a linha é executada uma vez a cada execução. (1 + 1)n + 1
        while((i>=0)&&(tmp<data[i])){ // (T + 1 + 1)N+1
            data[i+1] = data[i];// ((1)T + 1 + 1)N+1
            i--;// ((1+1)T + 1 + 1)N+1
        }
        data[i+1] = tmp;// ((1+1)T + 1 + 1)N+1
    } // No final, leva o tempo TN. (desconsidera constantes)
}
// No melhor caso, T = 1 -> 1N -> O(N)
// A cada elemento, o tempo levado é multiplicado por N
// No pior caso, T = N -> NN -> O(N²)




// MELHOR CASO: Dados já ordenados
// PIOR CASO: Dados na ordem inversa


/*
Eficiência de um algoritmo:
    Complexidade de tempo: Quanto tempo é necessário para computar o resultado de uma instância de um problema de tamanho n
        Falando de complexidade de algoritmos, 'n' é sempre o tamanho do vetor.
        -> Pior caso: O caso que leva mais tempo, funciona mais lentamente
        -> Caso médio: Todas as possíveis instâncias, medindo o tempo médio

Eficiência de uma estrutura de dados:
    Complexidade de espaço: Quanto "espaço de memória/disco" é preciso para armazenar a estrutura.

A complexidade de espaço e de tempo estão frequentemente relacionadas!

A eficiência medida objetivamente depende de:
    Como o programador implementou o algoritmo/ED (Tudo depende do algoritmo e da escolha de ED)
    Características do computador usado para fazer experimentos (Velocidade da CPU, capacidade e velocidade de acesso à memória)
    Linguagem, compilador, SO...

Quanto maior a amostra de dados lidos, mais impacto tem o algoritmo/ED escolhidos.
Com poucos dados, um algoritmo ruim num computador bom roda mais rápido.
Com muitos dados, um algoritmo bom em um computador ruim roda mais rápido.

Portanto, a medição formal de complexidade tem que ser subjetiva, porém matematicamente consistente (Complexidade assintótica)
*/

/*
COMPLEXIDADE ASSINTÓTICA:

O tempo/espaço é medido em números de passos do algoritmo/palavras de memória ao invés de segundos ou bytes
Análise do algoritmo/ED permite estimar uma função que depende do tamanho da entrada/número de dados armazenados (n).
    ex: T(n) = 13n³ + 2n² + 6nlogn
Percebe-se que a medida que n aumenta, o termo cúbico começa a dominar (Verificar a diferença dos gráficos)
A constante que multiplica o termo cúbico tem relativamente a mesma importância que a velocidade da CPU / Memória (não faz muita diferença)
O que realmente importa são as potẽncias.
Diz-se que T(n) = O(n³)
*/

/*
Limites:
    Definição: T(n) = O(f(n)) se existem constanes c e no tais que T(n) = c * f(n) para todo n > no  (gráfico)
    Limite superior:  Pior caso
    Limite inferior: Melhor caso
    Deve-se comparar os gráficos de algoritmos diferentes e escolher o que fica mais pra baixo.
    Se os dados são aleatórios e o pior caso é uma ordem específica, ele é bastante improvável.

    Limites justos: Observe que T(n) = O(n³), então:
        T(n) = 
*/