/*
20. Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Link: https://leetcode.com/problems/valid-parentheses/description/
*/


// Funcionou (0 ms)
typedef struct{
    char bracket[10000];
    int topo;
}Stack;

bool isValid(char* s) {
    if(!s) return true;
    Stack stack;
    stack.topo=0;
    int tam = strlen(s);
    for(int i = 0; i < tam; i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            stack.bracket[stack.topo] = s[i];
            stack.topo++;
        }
        else{
            if(stack.topo == 0) return false;
            stack.topo--;
            if (s[i] == ')' && stack.bracket[stack.topo] != '(' || 
                s[i] == '}' && stack.bracket[stack.topo] != '{' || 
                s[i] == ']' && stack.bracket[stack.topo] != '[' ){
                return false;
                
            }
        }
    }
    return stack.topo == 0;
}