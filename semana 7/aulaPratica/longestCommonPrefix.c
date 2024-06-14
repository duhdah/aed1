
/*

14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Link: https://leetcode.com/problems/longest-common-prefix/

*/

// TERMINAR

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strs == NULL) return 0;
    int tamPrefix = strlen(strs[0]), indexMenor = 0;
    for(int i = 1; i < strsSize; i++){
        if(strlen(strs[i]) < tamPrefix){
            tamPrefix = strlen(strs[i]);
            indexMenor = i;
        }
    }
    for(int i = 0; i < strsSize; i++){
        if(i == indexMenor) continue;
        while(strs[i][tamPrefix]!=strs[indexMenor][tamPrefix] && tamPrefix > 0)         tamPrefix--;
        if(!tamPrefix) return "";
    }
    char prefix[tamPrefix];
    for(int i = 0; i < tamPrefix; i++){
        prefix[i] = strs[indexMenor][i];
    }
    return prefix;
}