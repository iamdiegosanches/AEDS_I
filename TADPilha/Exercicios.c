void InverteComPilha (TPilha *Pilha) {
  TPilha P1, P2;
  FPVazia(&P1);
  FPVazia(&P2);
  TProduto x;
  while (!Vazia(*Pilha)) {
    Desempilha(Pilha, &x);
    Empilha(&P1, x);
  }
  while (!Vazia(P1)) {
    Desempilha(&P1, &x);
    Empilha(&P2, x);
  }
  while (!Vazia(P2)) {
    Desempilha(&P2, &x);
    Empilha(Pilha, x);
  }
  free(P1.topo);
  free(P2.topo);
}


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
