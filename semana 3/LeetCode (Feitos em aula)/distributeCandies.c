
/*

Alice has n candies, where the ith candy is of type candyType[i]. Alice noticed that she started to gain weight, so she visited a doctor.

The doctor advised Alice to only eat n / 2 of the candies she has (n is always even). 
Alice likes her candies very much, and she wants to eat the maximum number of different types of candies while still following the doctor's advice.

Given the integer array candyType of length n, return the maximum number of different types of candies she can eat if she only eats n / 2 of them.

Link: https://leetcode.com/problems/distribute-candies/description/
*/

// Funcionou, mas deu time limit exceeded 
int distributeCandies(int* candyType, int candyTypeSize) {
    int tipos = 0;
    int max = candyTypeSize/2;
    for(int i = 0; i < candyTypeSize; i++){
        int unico = 1;
        for(int j = i +1; j<candyTypeSize; j++){
            if(candyType[i] == candyType[j]) unico = 0;
        }
        if(unico) tipos++;
        if(tipos>max) break;
    }
    if(max < tipos){
        return max;
    }else{
        return tipos;
    }
}