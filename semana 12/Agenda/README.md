# Trabalho da Agenda
## Eduarda Pereira Medeiros (T5)

Desenvolver uma agenda sem alocar variáveis, utilizando apenas *pBuffer e uma lista duplamente encadeada para inserir as pessoas em ordem alfabética conforme as regras da fila ordenada (heap).

# Etapas do desenvolvimento
## Compreensão do ponteiro do tipo void

Comecei a trabalhar na agenda 3 semanas antes da data de entrega (na Semana 9), fazendo pequenos códigos para ler dados como inteiros e strings no pBuffer. Sabia que o trabalho era difícil, portanto, não quis deixar para última hora e tentei começar pelo menos a compreendar a ideia logo. Anotei no começo do código o que cada posição do pBuffer guardava para identificar o que eu estava fazendo. O meu grande problema na execução do trabalho acabou sendo a interpretação. Fiz diversas tentativas porque cada vez, percebia que não estava seguindo corretamente a proposta por ter entendido mal e tive que refazer meu código muitas vezes.

## Tentativa 1

Na semana 10, tentei realmente colocar em prática a agenda. Usei como exemplo o exercício que fizemos lá na primeira semana e comecei tentando apenas armazenar as pessoas na agenda, sem me preocupar com os conceitos de heap e de lista para não me perder e ir aos poucos. 

No entanto, estava tentando guardar o tamanho de cada nome e email no pBuffer, acreditando que não fazer isso seria fazer mal uso da memória e não poderia simplesmente alocar um valor maior para as strings. Isso acabou dificultando muito e não consegui ir adiante com esse modelo de agenda.

O código iniciado está como tentativa1.c na pasta das Tentativas.

## Tentativa 2

Na semana 11, depois de descobrir que poderia fazer sem me preocupar com o tamanho exato das strings, decidi alocar 20 char para cada string que precisaria ler e a implementação ficou mais simples. 

Implementei as funções e consegui uma agenda funcional exceto por um problema: Após inserir a primeira pessoa, quando eu inseria a segunda pessoa, o nome dela se tornava lixo de memória, o que também influenciava na inserção por ordem alfabética das demais pessoas.

Percebi que esse problema estava se dando por causa do realloc que estava dando a cada nova pessoa no pAgenda, pois o conteúdo do ponteiro que antes apontava para o inicio da agenda se perdia. E então, percebi que eu não devia estar dando realloc no pAgenda e que ele devia ser só um dos nodos da agenda, uma vez que o resto da lista seria encontrado utilizando os ponteiros. Até então, eu não estava entendendo como realmente funcionaria a agenda, porque tinha entendido na aula de apresentação da proposta do trabalho que o pAgenda deveria conter todos os dados da agenda e não entendia a necessidade da lista. Esses conceitos se tornaram mais claros para mim depois de compreender essa parte e fiz uma nova agenda.

O código resultante do mau uso do pAgenda está como tentativa2.c na pasta das Tentativas.

## Tentativa 3

Depois dessa descoberta, reformulei o código para ter apenas o pBuffer declarado. Usei posições do pBuffer para armazenar onde a agenda terminava e começava. Consegui implementar a agenda, no entanto, após conseguir fazer funcionar, tive uma conversa com alguns colegas e me dei conta que eu estava considerando que usar heap era inserir na ordem alfabética, pois no enunciado diz que a inserção deve ser em heap. O resto do código estava manuseando com os ponteiros da lista, ou seja, na hora de buscar e remover pessoas, não estava seguindo a regra da fila de que preciso tirar no início para poder acessar alguém que estava no meio. Novamente, tive que modificar a minha implementação.

O código que implementa a agenda sem seguir corretamente as regras da heap está como tentaiva3.c na pasta das Tentativas.

## Tentativa 4

Cheguei em um ponto onde acredito que tenha entendido, finamente, o que era pra fazer. Foi desestimulante, porque gastei muito da minha energia fazendo coisas erradas. Fiz muitos códigos em cada etapa para corrigir erros e no final perceber que tinha feito errado. Mesmo assim, tentei implementar corretamente. O que eu fiz de errado aqui foi que na hora de passar para uma fila auxiliar para buscar e listar, eu usei a lógica semelhante à pilha, retirando e inserindo sempre de uma das pontas, e não de heap, para passar os dados da principal pra auxiliar e da auxiliar pra principal. 

Fiz isso conscientemente porque percebi que se tirasse os elementos do início da fila principal, colocasse no início da auxiliar e tirasse do início dela novamente para colocar no início, manteria a ordem alfabética. Compreendo que o certo seria remover do início da fila original e inserir em ordem alfabética na auxiliar. No entanto, eu precisaria modificar a minha função adicionarPessoa para implementar isso e percebi que meu tempo já estava se esgotando mesmo usando as madrugadas pra tentar entregar um código legal. Optei por implementar algo que funcionasse. Deixo um desenho que fiz da lógica que usei nas funções de busca e lista para ter certeza de que funcionaria.

(Imagem)

Nessa etapa, corrigi um erro que persistia desde o começo do meu trabalho: eu estava alocando 4 bytes para ponteiros do tipo char. O código funcionava no VSCode assim, então não me dei conta, mas quando o Valgrind começou a dar erro, percebi isso e arrumei.

Como esse foi o melhor código que consegui fazer, explicarei melhor como ele funciona:
* No começo do código, está explicado quantos bytes tem pBuffer e cada "nodo" de pessoa da agenda 
* Cada "nodo" da agenda tem 60 bytes compostos da seguinte forma: 20 bytes (Nome) + 4 bytes (Idade) + 20 bytes (Email) + 8 bytes (Ponteiro para a pessoa anterior) + 8 bytes (Ponteiro para a próxima pessoa)
* pBuffer usa 53 bytes para armazenar as "variáveis" que precisei, o início e o fim da fila da agenda e início e o fim da fila auxiliar para poder dar free nela.

No código, são implementadas 6 funções: 
* void AdicionarPessoa(): Aloca 60 bytes, lê os dados da pessoa, percorre a agenda até encontrar a posição correta alfabeticamente para inserir 
* void RemoverPessoa():
* void *BuscarPessoa():
* void ListarPessoas():
* void LimparAgenda():
* void LimparAuxiliar():



# Valgrind

Nesse trabalho, o Valgrind foi um grande desafio. Como eu mudei tantas vezes a minha lógica nesse processo, no final, eu fiquei muito confusa e já mal conseguia arrumar o meu código pra pensar em como corrigir os erros. Identifiquei que havia memory leak na busca, pois eu estava alocando novos nodos para usar a lógica da fila auxiliar e eles não estavam sendo proporiamente desalocados, então a cada pessoa que eu passava, 60 bytes eram perdidos.
