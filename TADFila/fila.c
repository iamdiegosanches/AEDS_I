#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

void FFVazia (TFila *Fila)
{
    Fila->frente = (TCelula *)malloc(sizeof(TCelula));
    Fila->tras = Fila->frente;
    Fila->frente->prox = NULL;
    Fila->tamanho = 0;
}

int Vazia(TFila Fila)
{
    return (Fila.tras == Fila.frente);
}

int Tamanho(TFila Fila)
{
    return Fila.tamanho;
}

void Enfileirar (TProduto x, TFila *Fila)
{
    Fila->tras->prox = (TCelula*)malloc(sizeof(TCelula));
    Fila->tras = Fila->tras->prox;
    Fila->tras->item = x;
    Fila->tras->prox = NULL;
    Fila->tamanho++;
}

void Desenfileirar (TFila *Fila, TProduto *Item)
{
    if(!Vazia(*Fila))
    {
        TCelula *Aux;
        Aux = Fila->frente->prox;
        Fila->frente->prox = Aux->prox;
        *Item = Aux->item;
        free(Aux);
        if (Fila->frente->prox == NULL)
        {
            Fila->tras = Fila->frente; // Tratamento de excessao
        }
        Fila->tamanho++;
    }
}

void LerProduto(TProduto *x)
{
    printf("Digite codigo do produto: ");
    //__fpurge(stdin);
    fflush(stdin);
    scanf("%d", &x->codigo);
}

void ImprimirProduto(TProduto x)
{
    printf("\nCodigo: %d\n", x.codigo);
}

void Liberar (TFila *Fila)
{
    TProduto x;
    while (!Vazia(*Fila))
    {
        Desenfileirar(Fila, &x);
    }
    free(Fila->frente);
}

void Imprimir1 (TFila *Fila1)
{
    TProduto x;
    TFila Fila2;
    FFVazia(&Fila2);
    while (!Vazia(*Fila1))
    {
        Desenfileirar(Fila1, &x);
        Enfileirar(x, &Fila2);
    }
    while (!Vazia(Fila2))
    {
        Desenfileirar(&Fila2, &x);
        ImprimirProduto(x);
        Enfileirar(x, Fila1);
    }
    Liberar(&Fila2);
}

void Imprimir2 (TFila *Fila)
{
    int n = Tamanho(*Fila);
    TProduto x;
    while (n != 0)
    {
        Desenfileirar (Fila, &x);
        ImprimirProduto(x);
        Enfileirar (x, Fila);
        n--;
    }
}

//TProduto Pesquisar (TFila *Fila1, TProduto Item) {
//    return NULL;
//}
