# Trabalho da Agenda
## Eduarda Pereira Medeiros (M5)

Desenvolver uma agenda sem alocar variáveis, utilizando apenas *pBuffer e uma lista duplamente encadeada para inserir as pessoas em ordem alfabética conforme as regras da fila ordenada (heap).

## Etapas do desenvolvimento
### Compreensão do ponteiro do tipo void

Comecei a trabalhar na agenda 3 semanas antes da data de entrega (na semana 9), fazendo pequenos códigos para ler dados como inteiros e strings no pBuffer. Sabia que o trabalho era difícil, portanto, não quis deixar para última hora e tentei começar pelo menos a compreendar a ideia logo. Anotei no começo do código o que cada posição do pBuffer guardava para identificar o que eu estava fazendo. O meu grande problema na execução do trabalho acabou sendo a interpretação. Fiz diversas tentativas porque cada vez, percebia que não estava seguindo corretamente a proposta por ter entendido mal e tive que refazer meu código muitas vezes.

### Tentativa 1

Na semana 10, tentei realmente colocar em prática a agenda. Usei como exemplo o exercício que fizemos lá na primeira semana e comecei tentando apenas armazenar as pessoas na agenda, sem me preocupar com os conceitos de heap e de lista para não me perder e ir aos poucos. 

No entanto, estava tentando guardar o tamanho de cada nome e email no pBuffer, acreditando que não fazer isso seria fazer mal uso da memória e não poderia simplesmente alocar um valor maior para as strings. Isso acabou dificultando muito e não consegui ir adiante com esse modelo de agenda.

O código iniciado está como tentativa1.c na pasta das Tentativas.

### Tentativa 2

Na semana 11, depois de descobrir que poderia fazer sem me preocupar com o tamanho exato das strings, decidi alocar 20 char para cada string que precisaria ler e a implementação ficou mais simples. 

Implementei as funções e consegui uma agenda funcional exceto por um problema: Após inserir a primeira pessoa, quando eu inseria a segunda pessoa, o nome dela se tornava lixo de memória, o que também influenciava na inserção por ordem alfabética das demais pessoas.

Percebi que esse problema estava se dando por causa do realloc que estava dando a cada nova pessoa no pAgenda, pois o conteúdo do ponteiro que antes apontava para o inicio da agenda se perdia. E então, percebi que eu não devia estar dando realloc no pAgenda e que ele devia ser só um dos nodos da agenda, uma vez que o resto da lista seria encontrado utilizando os ponteiros. Até então, eu não estava entendendo como realmente funcionaria a agenda, porque tinha entendido na aula de apresentação da proposta do trabalho que o pAgenda deveria conter todos os dados da agenda e não entendia a necessidade da lista. Esses conceitos se tornaram mais claros para mim depois de compreender essa parte e fiz uma nova agenda.

O código resultante do mau uso do pAgenda está como tentativa2.c na pasta das Tentativas.

### Tentativa 3

Depois dessa descoberta, reformulei o código para ter apenas o pBuffer declarado. Usei posições do pBuffer para armazenar onde a agenda terminava e começava. Consegui implementar a agenda, no entanto, após conseguir fazer funcionar, tive uma conversa com alguns colegas e me dei conta que eu estava considerando que usar heap era inserir na ordem alfabética, pois no enunciado diz que a inserção deve ser em heap. O resto do código estava manuseando com os ponteiros da lista, ou seja, na hora de buscar e remover pessoas, não estava seguindo a regra da fila de que preciso tirar no início para poder acessar alguém que estava no meio. Novamente, tive que modificar a minha implementação.

O código que implementa a agenda sem seguir corretamente as regras da heap está como tentativa3.c na pasta das Tentativas.

### Tentativa 4

Cheguei em um ponto onde acredito que tenha entendido, finamente, o que era pra fazer. Foi desanimador, porque gastei muito da minha energia fazendo coisas erradas. Fiz muitos códigos em cada etapa para corrigir erros e no final perceber que tinha feito errado. Mesmo assim, tentei implementar corretamente. O que eu fiz de errado aqui foi que na hora de passar para uma fila auxiliar na função BuscarPessoa, eu usei a lógica semelhante à pilha, retirando e inserindo sempre de uma das pontas, e não de heap, para passar os dados da principal pra auxiliar e da auxiliar pra principal. 

Fiz isso conscientemente porque percebi que se tirasse os elementos do início da fila principal, colocasse no início da auxiliar e tirasse do início dela novamente para colocar no início, manteria a ordem alfabética. Compreendo que o certo seria remover do início da fila original e inserir em ordem alfabética na auxiliar. No entanto, eu precisaria modificar a minha função adicionarPessoa para implementar isso e percebi que meu tempo já estava se esgotando mesmo usando as madrugadas pra tentar entregar um código legal. Optei por implementar algo que funcionasse. Deixo um desenho que fiz da lógica que usei nas funções de busca e lista para ter certeza de que funcionaria.

<img src="https://github.com/user-attachments/assets/e5ed6a53-0ce8-4023-8eb6-77893f4016de)" width="300"/>

![pilha](https://github.com/user-attachments/assets/e5ed6a53-0ce8-4023-8eb6-77893f4016de)

Como esse foi o melhor código que consegui fazer, explicarei melhor como ele funciona:
* No começo do código, está explicado quantos bytes tem pBuffer e cada "nodo" de pessoa da agenda:
* Cada "nodo" da agenda tem 60 bytes compostos da seguinte forma: 20 bytes (Nome) + 4 bytes (Idade) + 20 bytes (Email) + 8 bytes (Ponteiro para a pessoa anterior) + 8 bytes (Ponteiro para a próxima pessoa)
* pBuffer usa 53 bytes para armazenar as "variáveis" que precisei, o início e o fim da fila da agenda e início e o fim da fila auxiliar para poder dar free nela.

No código, são implementadas 6 funções: 
* void AdicionarPessoa():
* void RemoverPessoa():
* void *BuscarPessoa():
* void ListarPessoas():
* void LimparAgenda():
* void LimparAuxiliar():
Cada uma delas tem um header no código que explica melhor o que faz.

O meu maior problema acabou sendo a BuscarAgenda, como descrito no tópico a seguir sobre o Valgrind.

## Valgrind

Nesse trabalho, o Valgrind foi um grande desafio. Como eu mudei tantas vezes a minha lógica nesse processo, no final, eu fiquei muito confusa e já mal conseguia arrumar o meu código pra pensar em como corrigir os erros. Identifiquei que havia memory leak na busca, pois eu estava alocando novos nodos para usar a lógica da fila auxiliar e eles não estavam sendo proporiamente desalocados, então a cada pessoa que eu passava, 60 bytes eram perdidos.

Eu tentei solucionar isso fazendo uma função BuscarPessoa que não alocasse um novo nodo e usasse apenas os ponteiros e consegui, porém, a função RemoverPessoas parou de funcionar. Também tentei guardar um espaço no pBuffer para um nodo, mas isso acabou gerando mais problemas no código. Nenhuma dessas coisas funcionou, o que é uma pena, já que o erro está bem óbvio. O problema é que dar free depois de usar o nodo altera o conteúdo da lista, o que é prejudicial para o meu código. No final, acabei desistindo e deixando assim, tanto por falta de tempo quanto por cansaço.

## Teste

Usei a seguinte entrada para testar as funções de listar, buscar pessoas, remover nas extremidades da fila e no meio e adicionar mais pessoas:

1
Gabriel
25
gabriel@gmail.com
1
Amanda
31
amanda@gmail.com
1
Bruna
43
bruna@gmail.com
1
Zeca
74
zeca@gmail.com
1
Carlos
65
carlos@gmail.com
1
Rogerio
34
rogerio@gmail.com
1
Fabio
17
fabio@gmail.com
1
Renata
40
renata@gmail.com
1
Iara
23
iara@gmail.com

