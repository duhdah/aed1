/*
Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the 
first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.
*/

// Minha solucao:

char* reversePrefix(char* word, char ch) {
    for(int i = 0; word[i]; i++){
        if(word[i]==ch){
            int j = 0;
            int k = i;
            while(j<k){
                char temp = word[j];
                word[j] = word[k];
                word[k] = temp;
                j++;
                k--;
            }
            break;
        }
    }
    return word;
}

// Solucao otimizada:

void reverse(char* s, int n) {
    int i = 0;
    int j = n - 1;
    while (i < j) {
        int t = s[i];
        s[i++] = s[j];
        s[j--] = t;
    }
}

char* reversePrefix(char* word, char ch) {
    int m = 0;
    while (word[m] != ch && word[m] != 0) {
        m++;
    }
    if (word[m] != 0) {
        reverse(word, m + 1);
    }
    return word;
}