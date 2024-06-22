# Exercício Prático 1: Programação

## Eduarda Pereira Medeiros (M5)

## Enunciado 

860. Lemonade Change

At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

Note that you do not have any change in hand at first.

Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.

Link do problema: https://leetcode.com/problems/lemonade-change/description/

## Código feito em aula

A lógica usada foi a de contar quantas notas de 5, 10 e 20 reais eram obtidas.
Se, ao receber 10 ou 20 reais, não houvessem notas suficientes para o troco, a função retornava 'falso'.
Caso contrário, o retorno era verdadeiro.

Ainda em aula, percebi que o número de notas de 20 não importava, então utilizei apenas as variáveis num5 e num 10,
que correspondem ao número de notas de 5 e de 10 disponíveis, respectivamente.

O código foi aceito pelo LeetCode em aula, tendo o runtime e a memória usada variando conforme as submissões.

* Como o tamanho de bills é especificado como maior que 1, o código não se preocupa com a entrada de valores menores que 1.
* Da mesma forma, é considerado que apenas notas de 5, 10 e 20 serão usadas.

## Código feito em casa

Já que o código funcionou em aula, não precisei fazer muito em casa. 
Ajustei para o padrão do DOOM 3 da melhor forma que consegui.
Busquei outras formas de resolver o problema para buscar algo mais otimizado, mas todas as maneiras eram muito semelhantes.

## Casos de Teste

### Teste 1 (LeetCode)

Entrada: bills [5,5,5,10,20]
Saída: true

### Teste 2  (LeetCode)

Input: bills = [5,5,10,10,20]
Output: false

### Teste 3

Input: bills = [5]
Output: true

## Valgrind

Nenhum erro foi encontrado.
