# Trabalho da Agenda
## Eduarda Pereira Medeiros (M5)

## Enunciado
Desenvolver uma agenda sem alocar variáveis, utilizando apenas *pBuffer e uma lista duplamente encadeada para inserir as pessoas em ordem alfabética conforme as regras da fila ordenada (heap). O objetivo é aprender sobre a organização de memória de modo semelhante ao sistema operacional.

## Etapas do desenvolvimento
### Compreensão do ponteiro do tipo void

Comecei a trabalhar na agenda 3 semanas antes da data de entrega (na semana 9), fazendo pequenos códigos para ler dados como inteiros e strings no pBuffer. Sabia que o trabalho era difícil, portanto, não quis deixar para última hora e tentei começar pelo menos a compreendar a ideia logo. Anotei no começo do código o que cada posição do pBuffer guardava para identificar o que eu estava fazendo. 

### Tentativas

Entre as semanas 10 e 12, eu escrevi muitos códigos. Foi um processo, pois a cada nova tentativa, eu descobria algo que estava fazendo errado. 

* Semana 10
Na primeira, eu estava tentando armazenar o tamanho de cada nome e email no pBuffer para evitar gastar memória a mais, o que me deu uma dor de cabeça imensa. Quando descobri que podia ter um número fixo de char para cada string, rcomecei de novo.

* Semana 11
Na segunda, estava usando o pAgenda como um "vetor" de nodos, dando realloc nele cada vez. Depois, me dei conta que o pAgenda deveria ser a cabeça da agenda e não ela inteira e reformulei o código. No novo código, 

Na terceira, utilzei apenas o pBuffer, porém, apliquei as regras da heap somente na hora de adicionar as pessoas. Tinha entendido dessa maneira e quando percebi que estava errado, refiz as minhas funções.

* Semana 12
A quarta tentativa era a que eu teria entregue na quinta. Tentei aplicar as regras da heap, usei uma fila auxiliar, mas na função Buscar, tive problemas e acabei optando por inserir e remover da fila auxiliar pra agenda e vice-versa sempre do início para manter a ordem. Além disso, estava com um erro de memory leak nessa função e também não estava dando free nas pessoas cada vez que as mudava de fila. Em geral, o código funcionava, mas não se adequava totamente ao que foi pedido.

Depois da nossa aula de dúvidas da agenda, eu finalmente entendi o que era pra fazer. O meu maior problema no desenvolvimento foi a falha da interpretçaão, pois cada vez que percebia que estava fazendo algo errado, ia me frustrando e duvidando que eu conseguiria fazer da forma correta. Não desisti e consegui uma agenda funcional, o que pra mim foi uma grande vitória! Usei a fila auxiliar devidamente nas funções, não obtive memory leak no valgrind, parece tudo bem. Só não consegui realocar o meu pBuffer conforme necessidade porque como eu estava usando define, foi difícil me habituar a usar os ponteiros pra pBuffer, e já que teria que modificar o meu código inteiro, achei que dificilmente teria tempo pra isso. Achei melhor pelo menos fazer o vídeo da forma que está, já que o código em si é funcional.

Só para constar, deixei as minhas tentativas na pasta Tentativas desse repositório para mostrar a evolução do código.

## Código final

No meu código, optei por usar define para as posições do pBuffer para deixar o código mais legível. Além disso, usei outros defines (IDADE, EMAIL, ANT e PROX) que se referiam às posições dentro do nodo da pessoa para ficar mais fácil de entender o que estou alterando. 

No meu pBuffer, estão as variáveis que utilizei ao longo do códigos, ponteiros para o início e o fim da agenda e da fila auxiliar e um nodo auxiliar usado como parâmetro na função AdicionarPessoa().

As funções criadas no código foram AdicionarPessoa(), RemoverPessoa(), BuscarPessoa(), ListarPessoas(), LimparAgenda() e LimparAuxiliar(). Enquanto as 4 primeiras foram as explicitamente requisitadas no enunciado, as duas últimas percorrem a fila da agenda e da auxiliar para garantir que os nodos sejam desalocados. Cada função no código tem uma descrição no código.

O código final é a Agenda.c .

## Teste

Testes a serem feitos:

1) Não fazer nada e encerrar a execução;
2) Adicionar várias pessoas, listar as pessoas e encerrar a execução;
3) Adicionar várias pessoas, buscar pessoas em várias posições, listar as pessoas e encerrar a execução;
4) Adicionar várias pessoas, remover pessoas em várias posições, tentar buscar elas, listar as pessoas e encerrar a execução.

Não encontrei nenhum memory leak nos testes que fiz.
