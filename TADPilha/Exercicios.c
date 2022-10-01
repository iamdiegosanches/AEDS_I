void InverteComFila (TPilha *Pilha) {
  TFila Fila;
  FFVazia(&Fila);
  TProduto x;
  while (!Vazia(*Pilha)) {
    Desempilha(Pilha, &x);
    Enfileira(&Fila, x);
  }
  while (!Vazia(Fila)) {
    Desenfileira(&Fila, &x);
    Empilha(Pilha, x);
  }
  free(Fila.frente);
}
