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

int VerificaIgual (TFila Fila1, TFila fila2) { // TERMINAR AINDA
    if (Fila1.tamanho != Fila2.tamanho) {
        return 0;
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
