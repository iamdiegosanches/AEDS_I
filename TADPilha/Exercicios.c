// Pilha 1.a)
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

// Pilha 1.b)
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

// 1 - c --> fazer isso sem passar pilha como argumento
void Inverte (TPilha *Pilha1, TPilha *Pilha2) {
    int n = Tamanho(*Pilha1);
    TProduto Aux;
    TProduto x;
    if(n == 0) { // Caso base
        while(!Vazia(*Pilha2)){
            Pop(Pilha2, &x);
            Push(Pilha1, x);
        }
    } else { // Passo indutivo
        for(int i = 0; i < n-1; i++) {
            Pop(Pilha1, &x);
            Push(Pilha2, x);
        }
        Pop(Pilha1, &Aux);
        for(int i = 0; i < n-1; i++) {
            Pop(Pilha2, &x);
            Push(Pilha1, x);
        }
        Push(Pilha2, Aux);
        Inverte(Pilha1, Pilha2);
    }
}

// 2
void Transfere (TPilha *Pilha1, TPilha *Pilha2) {
    int n = Tamanho(*Pilha1);
    TProduto Aux;
    TProduto x;
    if(n == 0) { // Caso base
        return;
    } else { // Passo indutivo
        for(int i = 0; i < n-1; i++) {
            Pop(Pilha1, &x);
            Push(Pilha2, x);
        }
        Pop(Pilha1, &Aux);
        for(int i = 0; i < n-1; i++) {
            Pop(Pilha2, &x);
            Push(Pilha1, x);
        }
        Push(Pilha2, Aux);
        Transfere(Pilha1, Pilha2);
    }
}

// 3 - CONFERIR
int ExpValid (char *str) {
    TPilha pilha;
    FPVazia(&pilha);
    TCharacter x;
    int i = 0;
    while(*(str + i) != '\0'){
        if(*(str + i) == '{' || *(str + i) == '[' || *(str + i) == '(')
            Empilha(&pilha, *(str + i));
        
        if(*(str + i) == '}') {
            if(pilha.topo == '{')
                Desempilha(x, &pilha);
        }
        
        if(*(str + i) == ']') {
            if(pilha.topo == '[')
                Desempilha(x, &pilha);
        }
        
        if(*(str + i) == ')') {
            if(pilha.topo == '(')
                Desempilha(x, &pilha);
        }
        i++;
    }
    if(Vazia(pilha))
        return 1;
    else
        return 0;
}

// 4
void soma(TPilha *Pilha1, TPilha *Pilha2, TPilha *Pilha3) {
    int resultado = 0;
    int soma, D1, D2;
    while(!Vazia(*Pilha1) || !Vazia(*Pilha2)) {
        Pop(Pilha1, &D1);
        Pop(Pilha2, &D2);
        soma = resultado + D1 + D2;
        if (soma.codigo > 9) {
            resultado = 1;
            soma = soma - 10;
        } else {
            resultado = 0;
        }
        Push(Pilha3, soma);
    }
}
