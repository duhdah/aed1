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
