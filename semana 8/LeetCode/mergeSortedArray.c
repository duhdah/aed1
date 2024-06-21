#include <stdio.h>

/*

88. Merge Sorted Array

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, 
representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. 
To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, 
and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Link: https://leetcode.com/problems/merge-sorted-array/description/

*/

// Funcionou (0 ms)



// Raciocinio passo a passo:

// Os vetores já foram dados em ordem decrescente.
// O vetor nums1 tem espaço para todos os elementos.
// Precisamos considerar as posições nos vetores dos elementos maiores e compara-los para ir adicionando em nums1.

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {

    int p1 = m - 1; // valor da posicao referente ao index do maior elemento do vetor nums1 que falta ser ajustado no vetor
    int p2 = n - 1; // valor da posicao referente ao index do maior elemento do vetor nums2 que resta colocar em nums1
    int pt = m + n - 1; // valor da posicao referente a maior posicao de p1 disponivel (t de total)

    // Comeca comparando os maiores elementos dos vetores e coloca os valores correspondentes no final do vetor nums1.
    // Conforme um numero é colocado no vetor, as posicoes dos numeros que ja foram contabilizados sao descontadas das variaveis p1, p2 e pt.

    while(p1>=0 && p2>=0){
        if(nums1[p1] > nums2[p2]){
            nums1[pt] = nums1[p1];
            p1--;
        }else{
            nums1[pt] = nums2[p2];
            p2--;
        }
        pt--;
    }

    // Se o primeiro elemento de nums2 for maior ou igual ao primeiro elemento de nums1, o vetor nums1 estara pronto.
    // Mas se p1 < 0 antes de p2, falta colocar os elementos de p2 que faltaram no começo de nums1.

    while(p2>=0){
        nums1[pt] = nums2[p2];
        p2--;
        pt--;
    }
}
