void Liberar(TPilha *Pilha) {
    TProduto x;
    while(!Vazia(*Pilha)) {
        Pop(Pilha, &x);
    }
    free(Pilha->topo);
}

void Imprimir (TPilha *Pilha1) {
    TPilha Pilha2;
    TProduto x;
    while (!Vazia(Pilha1)) {
        Pop(Pilha1, &x);
        ImprimirProduto(x);
        Push(&Pilha2, x);
    }
    
    while (!Vazia(&Pilha2)) {
        Pop(%Pilha2, %x);
        Push(Pilha1, x);
    }
}

TProduto Pesquisar (TProduto Item, TPilha *Pilha) {
    TPilha Pilha2;
    TProduto x, Aux;
    while (!Vazia(Pilha1)) {
        Pop(Pilha1, &x);
        if(Item.codigo == x.codigo)
            Aux.codigo = x.codigo;
        Push(&Pilha2, x);
    }
    
    while (!Vazia(&Pilha2)) {
        Pop(%Pilha2, %x);
        Push(Pilha1, x);
    }
    return Aux;
}
