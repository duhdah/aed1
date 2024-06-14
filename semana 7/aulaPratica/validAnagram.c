
/*

242. Valid Anagram
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Link: https://leetcode.com/problems/valid-anagram/description/

*/

// Funcionou (2 ms) 

bool isAnagram(char* s, char* t) {
    int sLetters[26] = {0};
    int tLetters[26] = {0};
    if(strlen(s)!=strlen(t)) return false;
    for(int i = 0; i < strlen(s); i++){
        sLetters[s[i]-'a']++;
    }
    for(int i = 0; i < strlen(t); i++){
        tLetters[t[i]-'a']++;
    }
    for(int i = 0; i < 26; i++){
        if(sLetters[i]!=tLetters[i]) return false;
    }
    return true;
}