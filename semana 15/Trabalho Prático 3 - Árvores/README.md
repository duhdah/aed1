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

## Código feito em casa

## Casos de teste (Valgrind)

* Teste 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]

* Teste 2:
Input: root = [1]
Output: [1]

* Teste 3:
Input: root = [0,1,3,null,2]
Output: [2]

Nenhum memory leak foi detectado nos testes.
