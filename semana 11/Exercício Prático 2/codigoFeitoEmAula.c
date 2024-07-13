
// CÓDIGO PRINCIPAL:
// Passou 45/76 casos de teste

char *removeSubstring(char *s, int indice);
int encontraSubstring(char *s);

int maximumGain(char* s, int x, int y) {
    int pontos = 0;

    // ideia do codigo: tirar primeiro 'ab' se eles valerem mais e depois os 'ba's, vice versa
    // fica em um while para ver se encontra novas substrings formadas depois de passar pelos fors
    // problema: se forma 'ab' em um dos fors de 'ba' quando 'ab' deveria ser prioridade, nao obtem o maximo

    if(x>y){
        while(encontraSubstring(s)){
            for(int i = 0; i < strlen(s); i++){
                if(s[i] == 'a'){
                    if(s[i+1] == 'b'){
                        char *nova = removeSubstring(s, i);
                        strcpy(s,nova);
                        i=0;
                        pontos+=x;
                    }
                }
            }
            for(int i = 0; i < strlen(s); i++){
                if(s[i] == 'a'){
                    if(s[i+1] == 'b'){
                        char *nova = removeSubstring(s, i);
                        strcpy(s,nova);
                        i=0;
                        pontos+=x;
                    }
                }
                if(s[i] == 'b'){
                    if(s[i+1] == 'a'){
                        char *nova = removeSubstring(s, i);
                        strcpy(s,nova);
                        i=0;
                        pontos+=y;
                    }
                }
            }
        }
    }else{
        while(encontraSubstring(s)){
            for(int i = 0; i < strlen(s); i++){
                if(s[i] == 'b'){
                    if(s[i+1] == 'a'){
                        char *nova = removeSubstring(s, i);
                        strcpy(s,nova);
                        i=0;
                        pontos+=y;
                    }
                }
            }
            for(int i = 0; i < strlen(s); i++){
                if(s[i] == 'b'){
                    if(s[i+1] == 'a'){
                        char *nova = removeSubstring(s, i);
                        strcpy(s,nova);
                        i=0;
                        pontos+=y;
                    }
                }if(s[i] == 'a'){
                    if(s[i+1] == 'b'){
                        char *nova = removeSubstring(s, i);
                        strcpy(s,nova);
                        i=0;
                        pontos+=x;
                    }
                }
            }
        }
    }
    return pontos;
}

// remove uma substring dado o indice
char *removeSubstring(char *s, int indice){
    int tam = 0;
    char *nova = (char *)malloc(sizeof(char)*(strlen(s)+1));
    for(int i = 0; i < strlen(s); i++){
        if((i != indice) && (i != indice+1)){
            nova[tam] = s[i];
            tam++;
        }
    }
    nova[tam] = '\0';
    return nova;
}

int encontraSubstring(char *s){
    for(int i = 0; s[i+1]; i++){
        if(s[i]=='b'){
            if(s[i+1] =='a'){
               return 1;
            }
        }
        if(s[i]=='a'){
            if(s[i+1] =='b'){
               return i;
            }
        }
    }
    return 0;
}


// OUTRAS TENTATIVAS FEITAS EM AULA:
// A melhor foi a primeira. As outras podem estar incompletas.

// Tentativa 1: "Remover" os caracteres tornando os 'z' (nem a, nem b)

int encontraSubstring(char *s);

int maximumGain(char* s, int x, int y) {
    // usa pilha para remover a partir do final
    char* pilha = (char *)malloc(sizeof(char)*strlen(s));
    int topo = -1, pontos = 0;
    for(int i = 0; i < strlen(s); i++){
        topo++;
        pilha[topo] = s[i];
    }

    while(encontraSubstring(s)){
        for(int i = topo; i >= 0; i--){
            if(pilha[i] == 'a'){
                if(pilha[i-1] == 'b'){ // ba
                    if(y>x){ // ba vale mais que ab
                        pilha[i] ='z';
                        pilha[i-1] = 'z';
                        pontos+=y;
                    }else if(pilha[i-2] == 'a'){
                        pilha[i-1] = 'z';
                        pilha[i-2] = 'z';
                        pontos+=x;
                    }

                }
            }else if(pilha[i] == 'b'){
                if(pilha[i-1] == 'a'){ // encontrou ab
                    if(x>y){ // ab vale mais que ba
                        pilha[i] ='z';
                        pilha[i-1] = 'z';
                        pontos+=x;
                    }else if(pilha[i-2] == 'b'){
                        pilha[i-1] = 'z';
                        pilha[i-2] = 'z';
                        pontos+=y;
                    }
                }
            }
        }
    }
    return pontos;
}

int encontraSubstring(char *s){
    for(int i = 0; s[i+1]; i++){
        if(s[i]=='b'){
            if(s[i+1] =='a'){
               return 1;
            }
        }
        if(s[i]=='a'){
            if(s[i+1] =='b'){
               return i;
            }
        }
    }
    return 0;
}


// Tentativa 2: Com pilha


struct Pilha{
    int topo;
    struct Nodo *head;
};

struct Nodo{
    char c;
    struct Nodo *next;
};


int encontraSubstring(char *s);

int maximumGain(char* s, int x, int y) {

    struct Pilha *pilha;
    pilha->head = (struct Nodo *)sizeof(struct Nodo);
    pilha->topo = -1;
    int pontos = 0;

    for(int i = 0; i < strlen(s); i++){
        struct Nodo *novoNodo = (struct Nodo *)sizeof(struct Nodo);
        novoNodo->c = s[i];
        novoNodo->next = NULL;
        pilha->head->next = novoNodo;
        pilha->topo++;
    }

    while(encontraSubstring(s)){
        struct Nodo *p = head->next;
        if(!p) return pontos;
        if(p->c == 'a'){
            if(p->next->c == 'b'){
                if()
            }
        }
    }
    return pontos;
}

int encontraSubstring(char *s){
    for(int i = 0; s[i+1]; i++){
        if(s[i]=='b'){
            if(s[i+1] =='a'){
               return 1;
            }
        }
        if(s[i]=='a'){
            if(s[i+1] =='b'){
               return i;
            }
        }
    }
    return 0;
}



void novaString(char **s, int indice){
    int tam = 0;
    char *nova = (char *)malloc(sizeof(char)*strlen(s));
    for(int i = 0; i < strlen(s); i++){
        if((i != indice) && (i != indice+1)){
            nova[tam] = s[i];
            tam++;
        }
    }
    nova[tam] = '\0';
    s = nova;
}


// Tentativa 3: Sem pilha (Time Limit Exceeded)

int encontraSubstring(char *s);
int EncontraBa(char *s);
int EncontraAb(char *s);

int maximumGain(char* s, int x, int y) {
    int pontos = 0, indice = -1;

    // se ba der mais pontos, tira primeiro 'ba' depois 'ab'
    if(y>x){
        indice = EncontraBa(s);
        while(indice != -1){
            pontos+=y;
            novaString(&s,indice);
            indice = EncontraBa(s);
        }
        indice = EncontraAb(s);
        while(indice != -1){
            pontos+=x;
            novaString(&s,indice);
            indice = EncontraAb(s);
        }
    }else{
        // se ab der mais pontos ou mesma quantidade, tira primeiro 'ab' depois 'ba'
        indice = EncontraAb(s);
        while(indice != -1){
            pontos+=x;
            novaString(&s,indice);
            indice = EncontraAb(s);
        }
        indice = EncontraBa(s);
        while(indice != -1){
            pontos+=y;
            novaString(&s,indice);
            indice = EncontraBa(s);
        }
    }
    return pontos;
}

// verifica se tem 'ba' na palavra e retorna a posição
int EncontraBa(char *s){
    for(int i = 0; s[i]; i++){
        if(s[i]=='b'){
            if(s[i+1] =='a'){
               return i;
            }
        }
    }
    return -1;
}

// verifica se tem 'ab' na palavra e retorna a posição
int EncontraAb(char *s){
    for(int i = 0; s[i]; i++){
        if(s[i]=='a'){
            if(s[i+1] =='b'){
               return i;
            }
        }
    }
    return -1;
}

// remove uma substring dado o indice
void novaString(char *s, int indice){
    int tam = 0;
    char *nova = (char *)malloc(sizeof(char)*strlen(s)+1);
    for(int i = 0; i < strlen(s); i++){
        if((i != indice) && (i != indice+1)){
            nova[tam] = s[i];
            tam++;
        }
    }
    nova[tam] = '\0';
    s = nova;
}

// ideia de usar a pilha: começar a tirar do fim
// precisa considerar o que vale mais pontos, x ou y, na hora de tirar a substring se tiver 'aba'
// tambem tem que considerar que depois de tirar 'ab' ou 'ba' podem se formar novas substrings (ex: baba -> tirar 'ab' fica 'ba', se nao, da pra tirar 2 'ba' )
// como fazer funcionar tendo certeza de que tiramos todas as substrings e, aind


// Tentativa 4: Funciona em 36/76 testes

char *removeSubstring(char *s, int indice);

int maximumGain(char* s, int x, int y) {
    int pontos = 0, indice = -1;

    // se ba der mais pontos, tira primeiro 'ba' depois 'ab'
    if(x>y){
        for(int i = 0; i < strlen(s); i++){
            if(s[i] == 'a'){
                if(s[i+1] == 'b'){
                    char *nova = removeSubstring(s, i);
                    strcpy(s,nova);
                    i=0;
                    pontos+=x;
                }
            }
        }
        for(int i = 0; i < strlen(s); i++){
            if(s[i] == 'b'){
                if(s[i+1] == 'a'){
                    char *nova = removeSubstring(s, i);
                    strcpy(s,nova);
                    i=0;
                    pontos+=y;
                }
            }
            int teste = -1;
            teste = EncontraAb(s);
            while(teste != -1){
                char *nova = removeSubstring(s, i);
                strcpy(s,nova);
                pontos+=x;
                teste = EncontraAb(s);
            }
        }
    }else{
        for(int i = 0; i < strlen(s); i++){
            if(s[i] == 'b'){
                if(s[i+1] == 'a'){
                    char *nova = removeSubstring(s, i);
                    strcpy(s,nova);
                    i=0;
                    pontos+=y;
                }
            }
        }
        for(int i = 0; i < strlen(s); i++){
            if(s[i] == 'a'){
                if(s[i+1] == 'b'){
                    char *nova = removeSubstring(s, i);
                    strcpy(s,nova);
                    i=0;
                    pontos+=x;
                }
            }
            int teste = -1;
            teste = EncontraBa(s);
            while(teste != -1){
                char *nova = removeSubstring(s, i);
                strcpy(s,nova);
                pontos+=y;
                teste = EncontraBa(s);
            }
        }
    }
    return pontos;
}

// remove uma substring dado o indice
char *removeSubstring(char *s, int indice){
    int tam = 0;
    char *nova = (char *)malloc(sizeof(char)*(strlen(s)+1));
    for(int i = 0; i < strlen(s); i++){
        if((i != indice) && (i != indice+1)){
            nova[tam] = s[i];
            tam++;
        }
    }
    nova[tam] = '\0';
    return nova;
}

// verifica se tem 'ba' na palavra e retorna a posição
int EncontraBa(char *s){
    for(int i = 0; s[i]; i++){
        if(s[i]=='b'){
            if(s[i+1] =='a'){
               return i;
            }
        }
    }
    return -1;
}

// verifica se tem 'ab' na palavra e retorna a posição
int EncontraAb(char *s){
    for(int i = 0; s[i]; i++){
        if(s[i]=='a'){
            if(s[i+1] =='b'){
               return i;
            }
        }
    }
    return -1;
}
