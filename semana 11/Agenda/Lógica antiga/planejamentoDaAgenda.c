/*

O que vai ter no pBuffer? (int = a cada 4 bytes)

pBuffer[0] = getchar (char = 1 byte!)
pBuffer[1] = variavel para for (int = 4 bytes)
pBuffer[2] = número de pessoas armazenadas na agenda. (int = 4 bytes)
pBuffer[3] = quantos bytes ja foram ocupados (int = 4 bytes)


// OBS: As 3 proximas posicoes sao referentes a implementacao de lista duplamente ligada sem usar struct (nao sei se funciona :^) )
pBuffer[4] = posicao anterior do ponteiro (int = 4 bytes)
pBuffer[5] = posicao atual do ponteiro (int = 4 bytes)
pBuffer[6] = posicao seguinte do ponteiro (int = 4 bytes)

pBuffer[7...] = tamanho dos nomes e dos emails? (2 a 2) (int = 4 bytes)

*/

/*
pBuffer[0] = getchar (char = 1 byte!)  -> pBuffer
pBuffer[1] = tamanho de uma palavra lida (int = 4 bytes)   -> pBuffer+1
pBuffer[2] = variavel para for/entrada do menu (int = 4 bytes)   -> pBuffer+5
pBuffer[3] = número de pessoas armazenadas na agenda. (int = 4 bytes) -> pBuffer+9
pBuffer[4] = total de bytes ocupados (int = 4 bytes) -> pBuffer+13
pBuffer[5] = variavel para for (int = 4 bytes) -> pBuffer+17
pBuffer[6] = posicao anterior do ponteiro (int = 4 bytes) -> pBuffer+21
pBuffer[7] = posicao seguinte do ponteiro (int = 4 bytes) -> pBuffer+25
pBuffer[8...] = tamanho dos nomes + emails (int = 4 bytes) -> a partir de pBuffer+29
    ideia: ler nome, colocar um & depois de ler o nome, ler email, colocar & depois de ler email, ler o numero.
*/
