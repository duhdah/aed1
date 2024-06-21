/*
344. Reverse String

Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.

Link: https://leetcode.com/problems/reverse-string/description/
*/

// Funcionou (51 ms)
// Essa foi bem simples, mas o runtime ficou bem maior que o dos outros
// Vale a pena estudar os casos mais otimizados depois!

void reverseString(char* s, int sSize) {
    int inicio = 0, fim = sSize - 1;
    for(int i = 0; i < fim; i++){
        char temp = s[i];
        s[i] = s[fim];
        s[fim] = temp;
        fim--;
    }
}
