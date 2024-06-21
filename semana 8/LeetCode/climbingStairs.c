/*
    70. Climbing Stairs
    You are climbing a staircase. It takes n steps to reach the top.
    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
    Link: https://leetcode.com/problems/climbing-stairs/description/?envType=daily-question&envId=2024-05-01
*/

// Funcionou (0 ms, 5.6 MB)
int climbStairs(int n) {
    if(n<=1) return 1;
    int formas[n+1];
    formas[0] = 1;
    formas[1] = 1;
    for(int i = 2; i <= n; i++){
        formas[i] = formas[i - 1] + formas[i - 2];
    }
    return formas[n];
}

// Funcionou (2ms, 5.29 MB) (Ignora a possibilidade n = 0)
int climbStairs(int n) {
    if(n == 1) return 1;
    int formas[n+1];
    formas[1] = 1;
    formas[2] = 2;
    for(int i = 3; i <= n; i++){
        formas[i] = formas[i - 1] + formas[i - 2];
    }
    return formas[n];
}