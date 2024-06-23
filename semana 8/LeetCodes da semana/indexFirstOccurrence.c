/*

28. Find the Index of the First Occurrence in a String

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack.

Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
*/

// Funcionou (3 ms)
int strStr(char* haystack, char* needle) {
    for(int i = 0; i < strlen(haystack); i++){
        int encontrou = 1;
        for(int j = 0; j < strlen(needle); j++){
            if(haystack[i+j]!=needle[j]){
                encontrou = 0;
                break;
            }
        }
        if(encontrou) return i;
    }
    return -1;
}
