#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

void FPVazia (TPilha *Pilha) {
    Pilha->topo = (TCelula *)malloc(sizeof(TCelula));
    Pilha->fundo = Pilha->topo;
    Pilha->topo->prox = NULL;
    Pilha->tamanho = 0;
}

int Vazia (TPilha Pilha) {
    return (Pilha.topo == Pilha.fundo);
}

int Tamanho (TPilha Pilha) {
    return Pilha.tamanho;
}

void Push (TPilha *Pilha, TProduto x) {
    TCelula *Aux;
    Aux = (TCelula *)malloc(sizeof(TCelula));
    Pilha->topo->item = x;
    Aux->prox = Pilha->topo;
    Pilha->topo = Aux;
    Pilha->tamanho++;
}

void Pop (TPilha *Pilha, TProduto *Item) {
    TCelula* q;
    if (Vazia(*Pilha)) {
        printf("Erro lista vazia \n");
        Item->codigo = 0;
        return;
    }
    q = Pilha->topo;
    Pilha->topo = q->prox;
    *Item = q->prox->item;
    free(q);
    Pilha->tamanho--;
}


void Liberar(TPilha *Pilha) {
    TProduto x;
    while(!Vazia(*Pilha)) {
        Pop(Pilha, &x);
    }
    free(Pilha->topo);
}

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
    printf("\n");;
}

void ImprimirProduto(TProduto x) {
    printf("\nCodigo: %d\n", x.codigo);
    printf("Nome: %s", x.nome);
    printf("Quantidade: %d\n", x.quantidade);
    printf("Preco: %d\n\n", x.preco);
}

void Imprimir (TPilha *Pilha1) {
    TPilha Pilha2;
    FPVazia(&Pilha2);
    TProduto x;
    while (!Vazia(*Pilha1)) {
        Pop(Pilha1, &x);
        ImprimirProduto(x);
        Push(&Pilha2, x);
    }

    while (!Vazia(Pilha2)) {
        Pop(&Pilha2, &x);
        Push(Pilha1, x);
    }
    free(Pilha2.topo);
}

TProduto Pesquisar (TProduto Item, TPilha *Pilha1) {
    TPilha Pilha2;
    FPVazia(&Pilha2);
    TProduto x, Aux;
    while (!Vazia(*Pilha1)) {
        Pop(Pilha1, &x);
        if(Item.codigo == x.codigo)
            Aux.codigo = x.codigo;
        //else
            //Aux.codigo = -1;
        Push(&Pilha2, x);
    }

    while (!Vazia(Pilha2)) {
        Pop(&Pilha2, &x);
        Push(Pilha1, x);
    }
    free(Pilha2.topo);
    return Aux;
}
