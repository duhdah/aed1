Insertionsort (int data[], int n) { 
    int tmp,i,j;
    for (j=1; j<n; j++) { 
        i =j - 1;
        tmp = data[j]; 
        while ( (i>=0) && (tmp < data[i]) ) { 
            data[i+1] = data[i];
            i--; 
        }
        data[i+1] = tmp; 
    }
}