# Trabalho Prático 3 - Árvores
## Eduarda Pereira Medeiros (M5)


## Enunciado
### 865. Smallest Subtree with all the Deepest Nodes

Given the root of a binary tree, the depth of each node is the shortest distance to the root.
Return the smallest subtree such that it contains all the deepest nodes in the original tree.
A node is called the deepest if it has the largest depth possible among any node in the entire tree.
The subtree of a node is a tree consisting of that node, plus the set of all descendants of that node.

## Código feito em aula 

Em aula, me dediquei ao máximo para fazer um código que atendesse ao que o problema pedia, mas tive bastante dificuldade em entender qual a lógica que devia usar para atingir isso. Fui escrevendo meu código aos poucos e tentando atender a casos específicos primeiro, já que não consegui elaborar uma função mais genérica para abranger todas as possibilidades.

Consegui encontrar os nodos mais profundos e inseri eles em um vetor. Consegui, ainda, retornar as subárvores corretas quando a árvore não tinha nodos, quando tinha só um nodo ou quando a menor subárvore era formada por um nodo e seus dois filhos. Não deu tempo de tentar refinar o código para identificar as subárvores nos casos em que, por exemplo, há dois nodos com maior profundidade e estes não são diretamente filhos do mesmo nodo.

No final, o meu código foi aceito em 50 dos 58 casos testados pelo LeetCode.

![image](https://github.com/user-attachments/assets/bd5a2329-a491-4438-a7b9-61139f2f362f)

O código feito em aula pode ser encontrado no repositório como CodigoFeitoEmAula.c.

## Código feito em casa

Em casa, resolvi analisar melhor o problema desenhando as árvores pra pensar em uma estratégia melhor. Optei por começar de novo e deixar o que já tinha feito de lado porque não seria eficiente continuar naquele código, uma vez que não faria sentido manter pedaços de códigos para casos específicos se eu deveria encontrar algo mais geral.

Então, decidi tentar buscar a profundidade de todos os nodos ao invés de só encontrar os nodos mais profundos. Procurei uma forma de comparar a profudidade dos nodos da árvore. Travei um pouco na hora de implementar a lógica correta para criar a função que estava idealizando, então dei uma olhada no editorial, entendi a estratégia que eles usavam e apliquei no meu código. Dessa vez, funcionou e o código ficou bem mais simplificado e conseguiu abranger todos os casos.

O runtime no LeetCode variou entre 0 e 6 ms nas minhas submissões, mas foi aceito!

![image](https://github.com/user-attachments/assets/f1fb0157-a5d6-47b8-b2c9-c29cf3cd1b46)

O código feito em casa pode ser encontrado no repositório como CodigoFeitoEmCasa.c.

## Casos de teste (Valgrind)

* Teste 1:
* 
Input: root = [3,5,1,6,2,0,8,null,null,7,4]

Output: [2,7,4]

Na pasta Teste: teste1.c

* Teste 2:

Input: root = [1]

Output: [1]

Na pasta Teste: teste2.c

* Teste 3:

Input: root = [0,1,3,null,2]

Output: [2]

Na pasta Teste: teste3.c

* Teste 4:

Input = root = []

Output: []

Na pasta Teste: teste4.c


* Teste 5:

Input: [0,3,1,4,null,2,null,null,6,null,5]

Output [0,3,1,4,null,2,null,null,6,null,5]

Na pasta Teste: teste5.c


Nenhum memory leak foi detectado nos testes.
