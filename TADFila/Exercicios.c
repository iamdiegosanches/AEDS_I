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
        int res = 1;
        int n = Tamanho(*Fila2);
        TProduto x;
        while(n != 0) {
            Desenfileirar(Fila2, &x);
            if(Pesquisar(Fila1, x).codigo == -1)
                res = 0;
            Enfileirar(x, Fila2);
            n--;
        }
        return res;
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
        if(Pesquisar(Fila1, x).codigo != -1)
            Enfileirar(x, Fila3);
        Enfileirar(x, Fila2);
        n--;
    }
}
