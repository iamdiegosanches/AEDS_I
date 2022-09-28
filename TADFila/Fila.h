#ifndef HEADER_FILA
#define HEADER_FILA

#include <stdlib.h>
#include <stdio.h>

typedef struct item {
    int codigo;
} TProduto;

typedef struct celula {
    TProduto item;
    struct celula *prox;
} TCelula;

typedef struct {
    TCelula *frente;
    TCelula *tras;
    int tamanho;
} TFila;

void FFVazia (TFila *Fila);
int Vazia(TFila Fila);
int Tamanho(TFila Fila);
void Enfileirar (TProduto x, TFila *Fila);
void Desenfileirar (TFila *Fila, TProduto *Item);
void ImprimirProduto(TProduto x);
void Imprimir1 (TFila *Fila1);
void Imprimir2 (TFila *Fila);
TProduto Pesquisar (TFila *Fila1, TProduto Item);

#endif // HEADER_FILA
