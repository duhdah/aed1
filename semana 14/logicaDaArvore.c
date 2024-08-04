

// fiz anotações para compreender e lembrar das funções de uma árvore (desconsiderando o balanceamento)



// Struct: Deve ter o conteudo do nodo, o left e o right.

// Main: Deve inicializar a arvore como nodo *arvore = NULL;

// Pesquisa: tipo nodo*
    // verifica se o nodo é NULL, se for, não encontrou o valor
    // verifica se o valor buscado é menor que o do nodo atual, se for, vai pra esquerda
    // depois verifica se o valor buscado é maior que o do nodo atual, se for, vai pra direita
    // se não for maior nem menor, é igual, retorna o nodo atual.
    // recursão: Pesquisa(x, p->left);

// Insere: tipo void
    // verifica se o nodo é NULL, se for, dá malloc e insere
    // verifica se o valor do nodo a ser inserido é menor que o do nodo atual, se for, chama insere pra esquerda
    // verifica se o valor do nodo a ser inserido é menor que o do nodo atual, se for, chama insere pra direita
    // recursão: Insere(x,&(*p)->right);

// Remove: tipo void
    // verifica se o nodo é NULL, se for, não encontrou o valor
    // verifica se o valor do nodo a ser inserido é menor que o do nodo atual, se for, chama remove pra esquerda 
    // verifica se o valor do nodo a ser inserido é maior que o do nodo atual, se for, chama remove pra direita 
    // verifica se o right é NULL, e se for, aux = p, p = p->left e free(aux)
    // verifica se o left é diferente de NULL, e se for, chama Antecessor (remove maior nodo da subarvore esquerda)
    // se não entrar em nenhum if, no final aux = p, p = p->right e free(aux)

// Antecessor: tipo void
    // recebe como parâmetro um nodo em que vai salvar o nodo removido e um nodo da subarvore esquerda
    // busca o maior valor da subarvore esquerda e remove ele
    // aux = p, p = p->left, free(p)

// Imprime: tipo void
    // é o mesmo codigo para as tres ordens, o que muda é onde fica o printf
    // Na pre-ordem, fica aqui
    // Imprime(p->left);
    // Na ordem central, fica aqui
    // Imprime(p->right);
    // Na pos-ordem, fica aqui