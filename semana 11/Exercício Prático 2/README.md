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

**Link do problema: https://leetcode.com/problems/maximum-score-from-removing-substrings/description/**

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

No teste que aparece, faltou somar um x, ou seja, não deve ter lido um 'ab' corretamente.

![image](https://github.com/user-attachments/assets/8b92d84a-f6a1-448e-8544-56c6852b99db)

Uma hipótese que pensei em aula foi que o problema estava dando na hora de remover 'aabb', pois fiz o teste manual de como 'ab' e 'ba' seriam retirados dessa string e percebi que essa sequência parecia um problema.

![image](https://github.com/user-attachments/assets/4cca26ea-679a-4141-ac8f-152586636316)


## Código feito em casa

Li o editorial do exercício e entendi as soluções propostas. Antes de partir para uma nova abordagem, no entando, pedi para o Chat GPT corrigir meu código e, apesar de ele funcionar para mais casos (55/76), realmente não funciona para entradas maiores: dá time limit exceeded. Deixei o código na pasta como melhoradoPeloGPT.c para constar.

Portanto, decidi tentar implementar com pilhas e com a versão mais parecida com a minha, que também modifica a string em si, para ter uma noção melhor de como eu poderia ter feito.

Fiz das duas maneiras e coloquei ambas no código que vou entregar como final. No entanto, vou considerar a solução principal a feita com pilhas, pois fez mais sentido para mim depois de entender como elas funcionam e também porque imagino que a implementação de uma pilha tenha sido o objetivo do trabalho.

A versão com pilhas demonstrou um desempenho melhor do que a com modificação de strings.

O arquivo **codigoCorrigidoEmC.c** corresponde ao codigo que estou entregando como a minha solução do trabalho, sendo a parte comentada apenas adicional. 

Submissão do primeiro código (Pilhas):

![image](https://github.com/user-attachments/assets/e20e51d9-6439-4edc-bd0f-666e9ecfc379)

Submissão do segundo código (Modificação de strings):

![image](https://github.com/user-attachments/assets/478bc7fa-bc77-41ec-98cf-abf89cde13f2)

## Casos de Teste

### Teste 1

Entrada: s = "cdbcbbaaabab", x = 4, y = 5

Saída: 19

### Teste 2

Entrada: s = "aabbaaxybbaabb", x = 5, y = 4

Saída: 20

### Teste 3

Entrada: s = "aabbabkbbbfvybssbtaobaaaabataaadabbbmakgabbaoapbbbbobaabvqhbbzbbkapabaavbbeghacabamdpaaqbqabbjbababmbakbaabajabasaabbwabrbbaabbafubayaazbbbaababbaaha", x = 1926, y = 4320

Saída: 112374

## Valgrind

Nenhum memory leak foi apontado nos 3 testes.
