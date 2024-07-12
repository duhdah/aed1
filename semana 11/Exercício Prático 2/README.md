# Exercício Prático 2

## Eduarda Pereira Medeiros (M5)

## Enunciado 

**1717. Maximum Score From Removing Substrings**

You are given a string s and two integers x and y. You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".

Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".

Return the maximum points you can gain after applying the above operations on s.

**Link do problema: https://leetcode.com/problems/lemonade-change/description/**

## Código feito em aula

* Lógica do código desenvolvido
  
A ideia foi a de que eu precisava identificar tanto a ocorrência de 'ab' e de 'ba' e priorizar uma delas conforme x ou y, sendo o foco no que representa o valor mais alto.
A parte difícil foi implementar isso de maneira correta, pois nos testes costumava faltar contabilzar um deles.
Fiz várias tentativas em aula. Tentei implementar com pilha, pois parecia a estrutura de dados mais adequada, mas não soube como lidar com o código e decidi tentar sem usar as estruturas de dados, apenas modificando a string com uma função e buscando as substrings com outra função.

* Submissão no LeetCode

O código não foi aceito no LeetCode, tendo passado em 46 dos 76 casos de teste.
Passei bastante tempo tentando me acertar sobre qual formato do código deveria focar em desenvolver e depois o resto da tarde tentando resolver esses casos que não deram certo.
Infelizmente, não consegui, mas me esforcei bastante e acredito que pelo menos na lógica, eu estava indo no caminho certo.

## Código feito em casa

Já que o código funcionou em aula, não precisei fazer muito em casa. 
Ajustei para o padrão do DOOM 3 da melhor forma que consegui.
Como o runtime e a memória usada por submissões distintas do mesmo código variavam, foi difícil entender se as outras soluções eram mais
eficentes mesmo ou se era apenas o LeetCode variando os dados. Por isso, mantive o meu código do jeito que escrevi, já que todas as
outras soluções que vi usavam a mesma lógica de maneiras sutilmente diferentes.

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
(O que era esperado, já que a alocação dinâmica não foi usada)
