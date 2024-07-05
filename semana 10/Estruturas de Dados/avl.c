#include <stdio.h>

/*
Uma árvore com as mesmas informações pode ser balanceada ou não.
Algoritmos de balanceamento:
- AVL;
- Rubro-negra;
- Outros (mas vamos ver esses dois).

ÁRVORE AVL:
Uma árvore balanceada é tal que, para cada  nó, a diferença de altura de seus filhos de v é no máximo 1 (nem sempre tem como toda diferença ser 0).
Fator de balanceamento (FB) = Altura da subárvore esquerda - Altura da subárvore direita.
Na árvore balanceada, FB é -1, 0 ou 1.
Se for maior que 1, a árvore da esquerda tem maior altura.
Se for menor que -1, a árvore da direita tem maior altura.
*/
        
typedef long TipoChave;                               
                    
typedef struct Registro {                
  TipoChave Chave;
  /* outros componentes */
} Registro;                                        

typedef struct No * Apontador;
typedef Apontador TipoDicionario;

typedef struct No {
  Registro Reg;
  Apontador pEsq, pDir;
} No;

int FB (TNo* pRaiz)
{
  if (pRaiz == NULL)
    return 0;
 
  return Altura(pRaiz->pEsq) 
       - Altura(pRaiz->pDir);
}

int FB (TNo* pRaiz)
{
  if (pRaiz == NULL)
    return 0;
 
  return Altura(pRaiz->pEsq) 
       - Altura(pRaiz->pDir);
}

/*
Primeiro caso: rotação simples para a direita
  FB > 1
  A subárvore da  esque rda é maior que a da direita. 
  Acha o primeiro ancestral que tem F > 1
  Aplica a rotação simples à direita sem quebrar o conceito de árvore, de balanceada e de busca.

Segundo caso: rotação simples para a esquerda
  FB < -1
  A subárvore da  direita é maior que a da esquerdaa. 
  Acha o primeiro ancestral que tem F < -1
  Aplica a rotação simples à esquerda sem quebrar o conceito de árvore, de balanceada e de busca.

Terceiro caso: rotação dupla para a esquerda

Quarto caso: rotação dupla para a direita          
*/


void RSE(TNo** ppRaiz)
{
  TNo *pAux;

  pAux = (*ppRaiz)->pDir;
  (*ppRaiz)->pDir = pAux->pEsq;
  pAux->pEsq = (*ppRaiz);
  (*ppRaiz) = pAux;
}


void RSD(TNo** ppRaiz)
{
  TNo *pAux;

  pAux = (*ppRaiz)->pEsq;
  (*ppRaiz)->pEsq = pAux->pDir;
  pAux->pDir = (*ppRaiz);
  (*ppRaiz) = pAux;
}

// OBS: A arvore está sempre balanceada
// Pode estragar no momento de adicionar um novo nó, por isso, conferir no momento de adicionar o nó!


int BalancaEsquerda(TNo** ppRaiz)
{
  int fbe = FB ( (*ppRaiz)->pEsq );
  if ( fbe > 0 )
  {
    RSD(ppRaiz);
    return 1;
  }
  else if (fbe < 0 )
  { /* Rotação Dupla Direita */
    RSE( &((*ppRaiz)->pEsq) );
    RSD( ppRaiz ); /* &(*ppRaiz) */
    return 1;
  }
  return 0;
}


int BalancaDireita(TNo** ppRaiz)
{
  int fbd = FB( (*ppRaiz)->pDir);
  if ( fbd < 0 )
  {
    RSE (ppRaiz);
    return 1;
  }
  else if (fbd > 0 )
  { /* Rotação Dupla Esquerda */
    RSD( &((*ppRaiz)->pDir) );
    RSE( ppRaiz ); /* &(*ppRaiz) */
    return 1;
  }
  return 0;
}
  
  int Balanceamento(TNo** ppRaiz)
{
	int fb = FB(*ppRaiz);
	if ( fb > 1)
		return BalancaEsquerda(ppRaiz);
	else if (fb < -1 )
		return BalancaDireita(ppRaiz);
	else
		return 0;
}


int Insere(TNo** ppRaiz,Registro* x)
{
  if (*ppRaiz == NULL)
  {
    *ppRaiz = (TNo*)malloc(sizeof(TNo));
    (*ppRaiz)->Reg = *x;
    (*ppRaiz)->pEsq = NULL;
    (*ppRaiz)->pDir = NULL;
    return 1;
  }
  else if ( (*ppRaiz)->Reg.chave 
            > x->chave )
  {
    if ( Insere(&(*ppRaiz)->pEsq,x) )
    {
      if (Balanceamento(ppRaiz))
        return 0;
      else
        return 1;
    }
  }    
  else if ( (*ppRaiz)->Reg.chave 
            < x->chave )
  {
    if ( Insere(&(*ppRaiz)->pDir,x) )
    {
      if (Balanceamento(ppRaiz))
        return 0;
      else
        return 1;
    }
    else
      return 0;
  }
  else
    return 0; /* valor jah presente */
}
  

// Busca em árvore balanceada é sempre O(log n).
// Não se aplica busca em árvore não balanceada.
// Insere, balanceia, insere, balanceia...
// Calcular o fator de balanceamento é caro. E se guardar o FB no sentinela?
// Pergunta teórica na  prova: O que significa dizer que uma árvore é AVL?

/*
Tempo de execução nas árvores AVL:
  Uma única reestruturação: O(1).
  Pesquisa: O(log n).
      Altura da árvore é O(log n), não precisa de reestruturação.
  Inserção: O(log n).
      Busca inicial é O(log n).
      Reestruturação para manter balanceamento é O(log n).
  Remoção: O(log n).
    Busca inicial é O(log n).
      Reestruturação para manter balanceamento é O(log n).
*/

/*
Remoção:
    Mesma coisa que inserção:
    Encontra na árvore o nó que quer remover, remove, calcula o FB, aplica alguma das 4 rotações.

*/

Verifica se árvore é AVL

int EhArvoreArvl(TNo* pRaiz)
{
  int fb;

  if (pRaiz == NULL)
    return 1;

  if (!EhArvoreArvl(pRaiz->pEsq))
    return 0;
  if (!EhArvoreArvl(pRaiz->pDir))
    return 0;

  fb = FB (pRaiz);
  if ( ( fb > 1 ) || ( fb < -1) )
    return 0;
  else
    return 1;

}


/*
Site para aprender sobre AVL:
https://www.cs.usfca.edu/~galles/visualization/AVLtree.html
*/
