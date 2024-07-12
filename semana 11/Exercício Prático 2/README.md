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
  
A minha ideia foi que eu precisava identificar tanto a ocorrência de 'ab' e de 'ba' e priorizar uma delas conforme x ou y, sendo o foco no que representa o valor mais alto.
A parte difícil foi implementar isso de maneira correta, pois nos testes costumava faltar contabilzar algum deles.

Fiz várias tentativas em aula (fiquei a tarde inteira no lab!). No começo, tentei implementar com pilha, pois parecia a estrutura de dados mais adequada, mas não soube como lidar com o código e decidi tentar sem usar as estruturas de dados, apenas modificando a string com uma função e buscando as substrings com outra função.

OBS: No arquivo codigoFeitoEmAula.c está a minha última tentativa e também todas as outras formas de tentar resolver e funções que escrevi. Fiquei com a que mais deu certo. As outras, não consegui desenvolver tão bem quanto.

* Submissão no LeetCode

O código não foi aceito no LeetCode, tendo passado em 46 dos 76 casos de teste.
Passei bastante tempo tentando me acertar sobre qual formato do código deveria focar em desenvolver e depois o resto da tarde tentando resolver esses casos que não deram certo.
Infelizmente, não consegui, mas me esforcei bastante e acredito que pelo menos na lógica, eu estava indo no caminho certo.

Print da minha última submissão:
![image](https://github.com/user-attachments/assets/12dec7c7-307c-448f-a56b-942cb08c2365)

## Código feito em casa




## Casos de Teste

### Teste 1 (LeetCode)

Entrada:

Saída:

### Teste 2  (LeetCode)

Entrada:

Saída:

### Teste 3

Entrada:

Saída:

## Valgrind
