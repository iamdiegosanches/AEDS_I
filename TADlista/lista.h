#ifndef HEADER_LISTA
#define HEADER_LISTA

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int codigo;
    char nome[100];
    int quantidade;
    int preco;
} TProduto;

typedef struct celula
{
    TProduto item;
    struct celula *prox;
} TCelula;

typedef struct
{
    TCelula* primeiro;
    TCelula* ultimo;
    int tamanho;
} TLista;

void FLVazia(TLista *Lista);
int Vazia(TLista Lista);
int Tamanho (TLista Lista);
void LerProduto(TProduto *x);
void ImprimirProduto(TProduto x);
void Imprimir(TLista lista);
int Pesquisar2 (TLista Lista, TProduto Item);
TCelula* Pesquisar (TLista Lista, TProduto Item);
void Excluir (TLista *Lista, TProduto *Item);


#endif // HEADER_LISTA
