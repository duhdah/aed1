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