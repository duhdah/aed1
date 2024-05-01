/*

The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.

*/

// Minha primeira tentativa:
// Funcionou, mas deu time limit exceeded

int tribonacci(int n){
    if(n == 0){
        return 0;
    }else if(n == 1){
        return 1;
    }else if(n == 2){
        return 1;
    }else if(n > 0){
        return tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    }else{
        return -1;
    }
}

// Segunda tentativa:

int tribonacci(int n){
    int T[38];
    T[0]=0;
    T[1]=1;
    T[2]=1;
    if(n < 3 && n>=0){
        return T[n];
    }else{
        for(int i = 3; i < 38; i++){
            T[i] = T[i-1] + T[i-2] + T[i-3];
            if(n == i){
                return T[i];
            }
         }
     }
    return -1;
}

// Solucao otimizada: 

int tribonacci(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    if(n==2)
        return 1;
    int* arr = (int*)calloc((n+2),sizeof(int));
    arr[1] = 1;
    arr[2] = 1;
    int sum = arr[0] + arr[1] + arr[2];
    for(int i=3;i<n+1;i++)
    {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
        sum+=arr[i];
        sum-=arr[i-3];
    }
    return arr[n];
}