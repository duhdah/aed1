/*

Cada pessoa armazenda em agenda ocupara exatamente 44 bytes (20 bytes de nome, 4 bytes de idade, 20 bytes de email)
No pAgenda, cada pessoa precisa ter um *prev e um *next.
O pBuffer guarda o ponteiro do inicio e do fim da agenda e as demais variaveis.

pBuffer[0] = getchar (char = 1 byte)  -> pBuffer
pBuffer[1] = entrada do menu (int = 4 bytes)   -> pBuffer+1
pBuffer[2] = variavel para for (int = 4 bytes)   -> pBuffer+5


O que falta (14/07):
-> Implementar o RemovePesssoa()
-> Corrigir o erro no nome da 1a pessoa depois de adicionar a segunda
-> Verificar memory leaks
-> Testar mais casos

*/