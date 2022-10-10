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
