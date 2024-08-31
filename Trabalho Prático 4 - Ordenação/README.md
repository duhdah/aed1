# Trabalho Prático 4 - Ordenação
## Eduarda Pereira Medeiros

**826: Most Profit Assigning Work**

You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:

* difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
* worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).
* Every worker can be assigned at most one job, but one job can be completed multiple times.

For example, if three workers attempt the same job that pays $1, then the total profit will be $3. If a worker cannot complete any job, their profit is $0.
Return the maximum profit we can achieve after assigning the workers to the jobs.

# Código feito em aula
## O código funcionou! 🎉🎉🎉

Inicialmente, pensei em usar Merge Sort para ordenar o vetor das dificuldades, o que deixaria mais simples a busca pelos trabalhos que o trabalhador poderia fazer, e usar busca binária para encontrar qual o trabalho de maior dificuldade que o trabalhador conseguiria. Mas quando percebi que nem sempre o trabalho mais difícil era o mais rentável, mudei de estratégia. Não consegui adaptar o Merge Sort para alterar simultaneamente o vetor dos lucros conforme mudava o das dificuldades, já que deveria fazer isso para manter os dois com o mesmo índice. Além disso, como poderia haver diferentes valores com dificuldade menor ou igual à habilidade do trabalhador, também deixei de usar a busca binária.

Optei por implementar o Insertion Sort, que apesar de ter uma complexidade maior do que o Merge Sort ou o Quick Sort, por exemplo, pode ser implementado em uma única função e não tem recursão, o que facilitava para mim já que havia tido dificuldade para mexer simulataneamente em dois vetores com os outros algortimos. Ao mudar elementos do vetor das dificuldades de lugar, eu também mudava os elementos correspondentes no vetor de lucros para que a informação continuasse válida. Depois de ordenar as dificuldades, chamei uma função maiorLucro que percorre o vetor das dificuldades do começo até o momento que a dificuldade se torna maior do que a habilidade do trabalhador atual. Assim, o lucro vai sendo comparado e a função retorna o maior lucro possível que o trabalhador consegue obter. A função principal (maxProfitAssignment) retorna a soma dos lucros obtidos pelos trabalhadores.

**O código foi aceito pelo LeetCode.** O runtime ficou bem alto devido a escolha do algoritmo de ordenação. A complexidade do Insertion Sort é O(n) no melhor caso, quando o vetor está quase ordenado, mas O(n²) na maioria dos casos. Isso acabou afetando o desempenho do código.

![image](https://github.com/user-attachments/assets/7951b62c-a684-4dc4-b5c1-7b71ee2bef32)

# Código melhorado em casa

Como meu código já funcionou em aula, não precisei elaborar um novo código. Ainda assim, analisei as soluções dos editoriais para ver o que poderia ter feito de diferente e também olhei as soluções dos usuários do LeetCode. 

Algo que testei modificando o meu código foi implementar o Merge Sort ao invés do Insertion Sort para ver que impacto teria no runtime. Incrivelmente, não teve nenhum, só ocupou mais memória. Achava que o Merge Sort teria um desempenho bem melhor, então achei interessante esse resultado. Enfim, provavelmente usar a busca binária teria sido bem mais eficaz.

Percebi que as soluções do editorial usavam lógicas semelhantes a que eu usei, apesar de sempre fazerem uma coisinha ou outra diferente. O que se repetia muito nas soluções era a busca binária, então testei implementar a busca binária na minha solução para encontrar o índice correspondente à habilidade do trabalhador para limitar melhor a busca do melhor lucro para cada trabalhador. O runtime do código melhorou consideravelmente.

![image](https://github.com/user-attachments/assets/dab21492-7807-4394-bddf-d6a9651f3166)

# Testes
## Caso 1:
**Input:**
difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]

**Output:** 100

## Caso 2:
**Input:**
difficulty = [85,47,57], profit = [24,66,99], worker = [40,25,25]

**Output:** 0

## Caso 3:
**Input:**
difficulty = [1,3,4,7,3,4,8], profit = [4,6,5,7,5,3,8], worker = [1,2,8,5]

**Output:** 22

## **Nenhum memory leak foi detectado no Valgrind.**
