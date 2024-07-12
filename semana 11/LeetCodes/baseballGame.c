/*
682. Baseball Game

You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.

You are given a list of strings operations, where operations[i] is the ith operation you must apply to the record and is one of the following:

An integer x.
Record a new score of x.
'+'.
Record a new score that is the sum of the previous two scores.
'D'.
Record a new score that is the double of the previous score.
'C'.
Invalidate the previous score, removing it from the record.
Return the sum of all the scores on the record after applying all the operations.

The test cases are generated such that the answer and all intermediate calculations fit in a 32-bit integer and that all operations are valid.

Link: https://leetcode.com/problems/baseball-game/description/
*/

// Funcionou (5 ms)

int calPoints(char** operations, int operationsSize) {
    int *pilha = (int *)malloc(sizeof(int)*1000);
    int topo = -1;
    for(int i = 0; i < operationsSize; i++){
        if(strcmp(operations[i], "+") == 0 && topo>0){
            topo++;
            pilha[topo] = pilha[topo-1] + pilha[topo-2];
        }else if(strcmp(operations[i], "D") == 0 && topo>-1){
            topo++;
            pilha[topo] = 2*pilha[topo-1];
        }else if(strcmp(operations[i], "C") == 0 && topo>-1){
            pilha[topo] = 0;
            topo--;
        }else{
            topo++;
            pilha[topo] = atoi(operations[i]);
        }
    }
    int soma = 0;
    for(int i = 0; i <= topo; i++){
        soma+=pilha[i];
    }
    return soma;
}