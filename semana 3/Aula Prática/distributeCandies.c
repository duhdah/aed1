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