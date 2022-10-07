// 1
void Liberar (TFila *Fila)
{
    TProduto x;
    while (!Vazia(*Fila))
    {
        Desenfileirar(Fila, &x);
    }
    free(Fila->frente);
}

// 2
int VerificaIgual (TFila *Fila1, TFila *Fila2) {
    if (Fila1->tamanho != Fila2->tamanho) {
        return 0;
    } else {
        TFila FilaAux;
        FFVazia(&FilaAux);
        int n = Tamanho(*Fila1);
        TProduto x, y;
        // Fazendo uma copia de Fila1;
        while(n != 0) {
            Desenfileirar(Fila1, &x);
            Enfileirar(x, &FilaAux);
            Enfileirar(x, Fila1);
            n--;
        }
        n = Tamanho(*Fila2);
        int n2;
        while(n != 0) {
            Desenfileirar(Fila2, &x);
            if(Pesquisar(&FilaAux, x).codigo == x.codigo) { //Encontrou o item
                // Remover o item encontrado
                n2 = Tamanho(FilaAux);
                while(n2 != 0) {
                    Desenfileirar(&FilaAux, &y);
                    if(y.codigo != x.codigo)
                        Enfileirar(y, &FilaAux);
                    else
                        break;
                    n2--;
                }
            }
            Enfileirar(x, Fila2);
            n--;
        }
        if(Tamanho(FilaAux) == 0) {
            free(FilaAux.frente);
            return 1;
        } else {
            Liberar(&FilaAux);
            return 0;
        }

    }
}

// 3
void ExcluirIndice (TFila *Fila1, int indice) {
    if (indice > 0 && indice <= Tamanho(*Fila1)) {
        int n = 1;
        TProduto x;
        TFila Fila2;
        FFVazia(&Fila2);
        while(!Vazia(*Fila1)) {
            Desenfileirar(Fila1, &x);
            if(n != indice)
                Enfileirar(x, &Fila2);
            n++;
        }
        while(!Vazia(Fila2)) {
            Desenfileirar(&Fila2, &x);
            Enfileirar(x, Fila1);
        }
        free(Fila2.frente);
    }
}

// 4
void Intersecao (TFila *Fila1, TFila *Fila2, TFila *Fila3) {
    int n = Tamanho(*Fila2);
    TProduto x;
    while(n != 0) {
        Desenfileirar(Fila2, &x);
        if(Pesquisar(Fila1, x).codigo != -1 && Pesquisar(Fila3, x).codigo != x.codigo)
            Enfileirar(x, Fila3);
        Enfileirar(x, Fila2);
        n--;
    }
}

// 5
void Diferenca (TFila *Fila1, TFila *Fila2, TFila *Fila3) {
    int n = Tamanho(*Fila2);
    TProduto x;
    while(n != 0) {
        Desenfileirar(Fila2, &x);
        if(Pesquisar(Fila1, x).codigo == -1 && Pesquisar(Fila3, x).codigo != x.codigo)
            Enfileirar(x, Fila3);
        Enfileirar(x, Fila2);
        n--;
    }
    n = Tamanho(*Fila1);
    while(n != 0) {
        Desenfileirar(Fila1, &x);
        if(Pesquisar(Fila2, x).codigo == -1 && Pesquisar(Fila3, x).codigo != x.codigo)
            Enfileirar(x, Fila3);
        Enfileirar(x, Fila1);
        n--;
    }
}

// Operação de união
void Uniao (TFila *F1, TFila *F2, TFila *F3) {
    int n = Tamanho(*F1);
    TProduto x;
    while (n != 0) {
        Desenfileirar(F1, &x);
        Enfileirar(x, F2);
        if(Pesquisar2(F3, x).codigo == -1)
                Enfileirar(x, F3);
        n--;
    }
    n = Tamanho(*F2);
    while(n != 0) {
        Desenfileirar(F2, &x);
        Enfileirar(x, F2);
            if(Pesquisar2(F3, x).codigo == -1)
                Enfileirar(x, F3);
        n--;
    }
}

// Organizar fila usando pilha
void sortFila(TFila *fila) {
    TPilha pilha;
    FPVazia(&pilha);
    TProduto x, y;
    while(!Vazia(*fila)) {
        Desenfileirar(fila, &x);
        while(!Vazia2(pilha) && pilha.topo->prox->item.codigo < x.codigo) {
            Pop(&pilha, &y);
            Enfileirar(y, fila);
        }
        Push(&pilha, x);
    }
    while(!Vazia2(pilha)) {
        Pop(&pilha, &y);
        Enfileirar(y, fila);
    }
    free(pilha.topo);
}
