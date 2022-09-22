#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

void FLVazia(TLista *Lista)
{
    Lista->primeiro = (TCelula *)malloc(sizeof(TCelula));
    Lista->ultimo = Lista->primeiro;
    Lista->primeiro->prox = NULL;
    Lista->tamanho = 0;
}

int Vazia(TLista Lista)
{
    return (Lista.primeiro == Lista.ultimo);
}

int Tamanho (TLista Lista)
{
    return Lista.tamanho;
}

void Inserir (TProduto x, TLista *Lista)
{
    Lista->ultimo->prox = (TCelula *)malloc(sizeof(TCelula));
    Lista->ultimo = Lista->ultimo->prox;
    Lista->ultimo->item = x;
    Lista->ultimo->prox = NULL;
    Lista->tamanho++;
}

// LerProduto e ImprimirProduto são funções auxiliares
void LerProduto(TProduto *x)
{
    printf("Digite codigo do produto: ");
    //__fpurge(stdin);
    fflush(stdin);
    scanf("%d", &x->codigo);

    printf("Digite o nome do produto: ");
    //__fpurge(stdin);
    fflush(stdin);
    fgets(x->nome,100,stdin);

    printf("Digite oq quantidade: ");
    //__fpurge(stdin);
    fflush(stdin);
    scanf("%d", &x->quantidade);

    printf("Digite o preco: ");
    //__fpurge(stdin);
    fflush(stdin);
    scanf("%d", &x->preco);
    printf("\n");
}

void ImprimirProduto(TProduto x)
{
    printf("\nCodigo: %d\n", x.codigo);
    printf("Nome: %s", x.nome);
    printf("Quantidade: %d\n", x.quantidade);
    printf("Preco: %d\n\n", x.preco);
}

void Imprimir(TLista lista)
{
    TCelula* Aux;
    Aux = lista.primeiro->prox;
    while(Aux != NULL)
    {
        ImprimirProduto(Aux->item);
        Aux = Aux->prox;
    }
}

int Pesquisar2 (TLista Lista, TProduto Item)
{
    TCelula* Aux;
    Aux = Lista.primeiro;
    while (Aux->prox != NULL)
    {
        if(Aux->prox->item.codigo == Item.codigo)
            return 1;
        Aux = Aux->prox;
    }
    return 0;
}


TCelula* Pesquisar (TLista Lista, TProduto Item)
{
    TCelula* Aux;
    Aux = Lista.primeiro;
    while (Aux->prox != NULL)
    {
        if(Aux->prox->item.codigo == Item.codigo)
            return Aux; // Retorna o ponteiro para a célula anterior
        Aux = Aux->prox;
    }
    return NULL;
}

void Excluir (TLista *Lista, TProduto *Item)
{
    TCelula *Aux1, *Aux2;
    Aux1 = Pesquisar(*Lista, *Item);
    if(Aux1 != NULL)
    {
        Aux2 = Aux1->prox;
        Aux1->prox = Aux2->prox;
        *Item = Aux2->item;
        if(Aux1->prox == NULL)
            Lista->ultimo = Aux1;
        free(Aux2);
        Lista->tamanho--;
    }
    else
        Item->codigo = -1;
}

void Liberar (TLista *Lista) {
    while (!Vazia(*Lista)) {
        Excluir(Lista, &Lista->primeiro->prox->item);
    }
    free(Lista->primeiro);

    /*if (Vazia(*Lista) != 1) {
        TCelula *Aux;
        Aux = Lista->primeiro->prox;
        while (Aux != NULL) {
            Excluir(Lista, &Aux->item);
            Aux = Lista->primeiro->prox;
        }
    }
    free(Lista->primeiro);*/
}
