void Liberar (TFila *Fila)
{
    TProduto x;
    while (!Vazia(*Fila))
    {
        Desenfileirar(Fila, &x);
    }
    free(Fila->frente);
}

int VerificaIgual (TFila Fila1, TFila fila2) {
    if (Fila1.tamanho != Fila2.tamanho) {
        return 0;
    }
}
