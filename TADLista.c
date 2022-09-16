#include <stdio.h>
#include <stdlib.h>

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

void Imprimir(TLista Lista)
{
    TCelula* Aux;
    Aux = Lista.primeiro->prox;
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

void LimparLista (TLista *Lista) {
    if (Lista != NULL) {
        TCelula *Aux;
        Aux = Lista->primeiro->prox;
        while (Aux != NULL) {
            Excluir(Lista, &Aux->item);
            Aux = Aux->prox;
        }
    }
}

TLista* CopiaLista (TLista *ListaOrigem, TLista *ListaDestino) {
    if (ListaDestino != NULL) {
        TCelula *Aux;
        Aux = ListaOrigem->primeiro->prox;

        if (Vazia(*ListaDestino) == 0) {
            LimparLista(ListaDestino);
        }

        while (Aux != NULL) {
            Inserir(Aux->item, ListaDestino);
            Aux = Aux->prox;
        }
    } else {
        return NULL;
    }
}

TLista* CombinarLista (TLista *ListaOrigem, TLista *ListaDestino) {
    if (ListaDestino != NULL) {
        TCelula *Aux;
        Aux = ListaOrigem->primeiro->prox;
        while (Aux != NULL) {

            Aux = Aux->prox;
        }
    } else {
        return NULL;
    }
}

int main()
{
    TLista lista1;
    TLista lista2;

    FLVazia(&lista1);
    FLVazia(&lista2);

    TProduto x;

    int i;
    for (i = 0; i < 2; ++i)
    {
        LerProduto(&x);
        Inserir(x, &lista1);
    }

    Imprimir(lista1);

    /*
        if(Pesquisar2(lista, x) == 1) {
            printf("O item esta na lista!\n");
        } else {
            printf("O item nao esta na lista!\n");
        }
    */

    if(Pesquisar(lista1, x) != NULL)
        printf("O produto esta na lista!\n");
    else
        printf("O produto NAO esta na lista!\n");

    printf("\nInforme o codigo do produto que deseja excluir: ");
    scanf("%d", &x.codigo);

    Excluir(&lista1, &x);

    if(x.codigo != -1)
        printf("\nItem excluido com sucesso!\n");
    else
        printf("\nNao foi possivel excluir o produto!\n");

    printf("\nIMPRIMINDO lista1");

    Imprimir(lista1);

    CopiaLista(&lista1, &lista2);

    printf("\nIMPRIMINDO lista2");
    Imprimir(lista2);

    printf("\nIMPRIMINDO lista2");
    CopiaLista(&lista1, &lista2);
    Imprimir(lista2);

    return 0;
}
