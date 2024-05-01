
/*

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

 */

#include <stdio.h>
int romanToInt(char* s);

int main(){
    char roman[10];
    printf("Digite o numero em romanos: ");
    scanf("%s",roman);
    int number;
    number = romanToInt(roman);
    printf("Numero decimal: %d",number);
}

int romanToInt(char* s) {
    int num = 0;
    for(int i = 0; s[i]; i++){
        //printf("\ni: %d\nnum: %d\n\n",i,num);
        if(s[i] == 'M'){
            num += 1000;
        }else if(s[i] == 'D'){
            num += 500;
        }else if(s[i] == 'C'){
            if((s[i+1]) == 'D'){
                i++;
                num += 400;
            }else if((s[i+1]) == 'M'){
                i++;
                num += 900;
            }else{
                num += 100;
            }
        }else if(s[i] == 'L'){
            num += 50;
        }else if(s[i] == 'X'){
            if((s[i+1]) == 'L'){
                i++;
                num += 40;
            }else if((s[i+1]) == 'C'){
                i++;
                num += 90;
            }else{
                num += 10;
            }
        }else if(s[i] == 'V'){
            num += 5;
        }else if(s[i] == 'I'){
            if((s[i+1]) == 'V'){
                i++;
                num += 4;
            }else if((s[i+1]) == 'X'){
                i++;
                num += 9;
            }else{
                num += 1;
            }
        }
    }
    return num;
}