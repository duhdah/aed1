#include  <stdio.h>

/*
ARVORES:
-> Estrutura hierárquica
-> Os elementos são chamados de nós
-> O "pai" de todos é a raiz.
-> O conteúdo de um nó pode ser de qualquer tipo.
-> Um caminho é a sequência de nós para chegar de um até outro nó.
-> Os nós sem antecedentes sao raízes e os nós sem descendentes, são folhas.
-> A altura de um nó na árvore é o caminho de maior comprimento desse nó até uma folha.
-> A profundidade de um nó é o comprimento da sua raiz até o nó.

Maneiras de imprimir uma árvore:
-> Pré-ordem (Pré-fixa)
       Inicio
              Lista(n);
              Para cada filho f de n, da esquerda para direita,  faça
              PREORDEM (f);
       Fim
       // Por tras, a informação dos nodos é guardada em uma pilha
       // Como é recursivo, ele declara variavel a cada chamada (Consumo de memória)

-> Central
       Início
          Se Folha(n) então    /* Folha retorna se n é uma folha da árvore ou não)
             Lista(n);
          Senão
              CENTRAL (FilhoMaisEsquerda(n));
               Lista (n);
               Para cada filho f de n, exceto o mais à esquerda, da esquerda para a direita faça
       	 CENTRAL (f);
       Fim;

-> Pos-ordem (Pos-fixa)
       Início 
          Para cada filho f de n, da esquerda para direita faça
       	POSORDEM(f);
          Lista(n);
       Fim;

Classificação de árvores:
-> Árvores Estritamente Bináriass
       Cada nó tem, no máximo, dois filhos.
       Uma árvore é completa quando todos as folhas tem a mesma altura (nível n ou n-1).
       Uma árvore é quase completa quando todas folhas estão no nível n ou n-1.

-> Árvores Binárias de Pesquisa
       Muito eficiente para armazenar informações.
       Acesso direto e sequencial, faciidade de inserçãao e retirada, boa taxa de uso de memória.
       
-> Árvores Binárias de Pesquisa sem Balanceamento
       Todos os registros com chave menores estão na subárvore à esquerda. (Em números, são os menores. Em letras, pode ser a posição no alfabeto).
       Todos os registros com chave maiores estão na subárvore à direita.
       O primeiro valor inserido vira a raiz.
       O segundo será comparado com a raiz. Se for menor, vai pra esquerda, se for maior, direita... E assim, sucessitivamente.
       Questão fácil que pode cair na prova: Pegar uma árvore dessas e colocar um elemento.

-> Aplicação de árvores:
       Expressões: Usa a forma central de percorrer a árvore para calcular a expressão.

-> Estrutura de dados
       É como uma lista duplamente encadeada, mas ao invés de anterior e posterior, é esquerda e direita.
       
*/

typedef long TipoChave;                               
                    
typedef struct Registro {                
  TipoChave Chave;
  /* outros componentes */
} Registro;                                        

typedef struct No{
       Registro Reg;
       Apontador pEsq, pDir;
}No;
No *Apontador;              

void Pesquisa(Registro *x, Apontador p)‏
{ 
  if (p == NULL){
    printf("Erro : Registro nao esta presente na arvore\n");
    return;
  }
  if (x->Chave < p->Reg.Chave) { 
    Pesquisa(x, p->pEsq);
    return;
  }
  if (x->Chave > p->Reg.Chave)    
     Pesquisa(x, p->pDir);
  else *x = p->Reg;
}


/*
Inserir na árvore:
       Primeiro, buscar pra ver se ele já está na árvore.
       Se já não estiver na árvore, inserir. Criar uma nova célula com o valor desejado e colocar ela na posição condizente.
*/

void Insere(Registro x, Apontador *p)‏
{ 
  if (*p == NULL)  
  { 
    *p = (Apontador)malloc(sizeof(No));
    (*p)->Reg = x;  
    (*p)->pEsq = NULL; (*p)->pDir = NULL;
    return;
  }
  if (x.Chave < (*p)->Reg.Chave) 
  { 
    Insere(x, &(*p)->pEsq); 
    return; 
  }
  if (x.Chave > (*p)->Reg.Chave) 
    Insere(x, &(*p)->pDir);
  else 
    printf("Erro : Registro ja existe na arvore\n");
} 

// Inicializar a arvore:

void Inicializa(Apontador *Dicionario)
{ 
	*Dicionario = NULL;
}

/*
Remover da árvore:
       Se for folha é simples.
       Se não, deve ser substituído pelo registro mais à direita na subárvore esquerda.
       No raíz, pode  escolher substituir pelo mais à direita da subàrvore esquerda ou pelo mais à esquerda na subárvore direita.
       NO ENTANTO, tem que escolher um dos dois pra implementar no algoritmo. Tanto faz qual. O importante é manter a decisão.

*/

void Retira(Registro x, 
            Apontador *p)‏
{   
  Apontador Aux;
  if (*p == NULL) { 
    printf("Erro : Registro nao 
            esta na arvore\n"); 
    return;
  }
  if (x.Chave < (*p)->Reg.Chave) { 
     Retira(x, &(*p)->pEsq);        
     return; 
  }
  if (x.Chave > (*p)->Reg.Chave){ 
     Retira(x, &(*p)->pDir); 
     return; 
  }

if ((*p)->pDir == NULL)  {
     Aux = *p;           
     *p = (*p)->pEsq;
     free(Aux);
     return;
  }
  if ((*p)->pEsq != NULL) { 
     Antecessor(*p, &(*p)->pEsq);
     return;
  }
  /* ((*p)->pEsq == NULL) */ 
  Aux = *p; 
  *p = (*p)->pDir;
  free(Aux);
}  

void Antecessor(Apontador q, Apontador *r)‏
{ 
  Apontador aux;
	if ( (*r)->pDir != NULL) 
  { 
		Antecessor(q, &(*r)->pDir);
     return;
  }
  q->Reg = (*r)->Reg;
  aux = *r;
  *r = (*r)->pEsq;
  free(aux);
} 

/*
       A complexidade da busca binária com árvores é O(h).
       No pior caso, a altura de uma árvore é n, e no melhor caso, log2n + 1.  (O +1 é do nodo que estamos buscando).
       A inserção e a remoção também tem complexidade O(h), portanto, no pior caso, é O(n²) e no melhor caso, O(n log n).

       OBS: Se a árvore não for completa, o desempenho fica ruim, pois quando ela chega na folha, ela tem que voltar.
       Se a árvore ficar semelhante a uma linha, o desempenho fica muito ruim.

       ANTES DE CODAR, usar esse site:
       https://www.cs.usfca.edu/~galles/visualization/BST.html
       para fixar o conceito de árvores binárias.
*/
