// Bubble Sort

for (int i = 0; i < tamanho - 1; i++) {
    for (int j = 0; j < tamanho - i - 1; j++) {
        if (numeros[j] > numeros[j+1]) {
            int temp = numeros[j];
            numeros[j] = numeros[j+1];
            numeros[j+1] = temp;
        }
    }
}

// OBS: Na primeira passada, faz n comparações, na segunda, n-1, na terceira, n-2...
// Ex: 14 33 27 35 10
/*
i = 0
    Compara 14 com 33: Mantém
    Compara 33 com 27: Troca, pois 33 > 27
        Vetor resultante: 33 14 27 35 10
    Compara 27 com 35: Mantém
    Compara 35 com 10: Troca, pois 35 > 10
        Vetor resultante: 33 14 27 10 35

i = 1
    Compara 33 com 14: Troca, pois 33 > 14
        Vetor resultante: 14 33 27 10 35
    Compara 33 com 27: Troca, pois 33 > 27
        Vetor resultante: 14 27 33 10 35
    Compara 33 com 10: Troca, pois 33 > 10
        Vetor resultante: 14 27 10 33 35

i = 2
    Compara 14 com 27: Mantém
    Compara 27 com 10: Troca, pois 27 > 10
        Vetor resultante: 14 10 27 33 35

i = 3
    Compara 14 com 10: Troca, pois 14 > 10
        Vetor resultante: 10 14 27 33 35
*/

// i não chega a ter o valor da última posição pois não faria sentido.

// Complexidade: O(n²) 
// Muito lento! Ruim para bases de dados grandes
// O desempenho dele não é tão diferente dos outros para pequenas quantidades de dados
// O tempo de execução também é menor quando o vetor já está ordenado ou quase ordenado