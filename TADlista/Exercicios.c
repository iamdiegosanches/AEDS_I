// Copiar uma lista em outra
void copiaLista (TLista lista1, TLista *lista2) {
    if(Vazia(*lista2)) {
        TCelula *Aux;
        Aux = lista1.primeiro->prox;
        while(Aux != NULL) {
            Inserir(Aux->item, lista2);
            Aux = Aux->prox;
        }
        free(Aux);
    }
}

// Inverte lista
void inverteLista (TLista *Lista) {
    TCelula *Aux1;
    TCelula *Aux2;
    TCelula Aux3;
    int n = Tamanho(*Lista);
    int i;
    while(n != 0) {
        Aux1 = Lista->primeiro->prox;
        Aux2 = Lista->primeiro->prox->prox;
        for(i = 0; i < n-1; i++) {
            Aux3.item = Aux1->item;
            Aux1->item = Aux2->item;
            Aux2->item = Aux3.item;
            Aux1 = Aux1->prox;
            Aux2 = Aux2->prox;
        }
        n--;
    }
}

void sortLista (TLista *Lista) {
    TCelula *Aux1;
    TCelula *Aux2;
    TCelula Aux3;
    int n = Tamanho(*Lista);
    int i;
    while(n != 0) {
        Aux1 = Lista->primeiro->prox;
        Aux2 = Lista->primeiro->prox->prox;
        for(i = 0; i < n-1; i++) {
            if(Aux1->item.codigo > Aux2->item.codigo) {
                Aux3.item = Aux1->item;
                Aux1->item = Aux2->item;
                Aux2->item = Aux3.item;
                Aux1 = Aux1->prox;
                Aux2 = Aux2->prox;
            } else {
                Aux1 = Aux1->prox;
                Aux2 = Aux2->prox;
            }
        }
        n--;
    }
}
