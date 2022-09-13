#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    char nome[100];
    int quantidade;
    int preco;
} TProduto;
typedef struct celula {
    TProduto item;
    struct celula *prox;
} TCelula;
typedef struct {
    TCelula* primeiro;
    TCelula* ultimo;
    int tamanho;
}TLista;

void FLVazia(TLista *Lista) {
    Lista->primeiro = (TCelula *)malloc(sizeof(TCelula));
    Lista->ultimo = Lista->primeiro;
    Lista->primeiro->prox = NULL;
    Lista->tamanho = 0;
}

int Vazia(TLista Lista) {
    return (Lista.primeiro == Lista.ultimo);
}

int Tamanho (TLista Lista) {
    return Lista.tamanho;
}

void Inserir (TProduto x, TLista *Lista) {
    Lista->ultimo->prox = (TCelula *)malloc(sizeof(TCelula));
    Lista->ultimo = Lista->ultimo->prox;
    Lista->ultimo->prox = NULL;
    Lista->tamanho++;
}

void Ler(TProduto *x) {
    printf("Digite codigo do produto: ");
    fflush(stdin);
    scanf("%d", &x->codigo);

    printf("Digite o nome do produto: ");
    fflush(stdin);
    fgets(x->nome,100,stdin);

    printf("Digite oq quantidade: ");
    fflush(stdin);
    scanf("%d", &x->quantidade);

    printf("Digite o preco: ");
    fflush(stdin);
    scanf("%d", &x->preco);

}

void Imprimir(TProduto *x) {
    printf("Codigo: %d", x->codigo);
    printf("Nome: %s", x->nome);
    printf("Quantidade: %d", x->quantidade);
    printf("Preco: %d", x->preco);
}

int main() {
    TLista lista;
    FLVazia(&lista);
    TProduto x;
    Inserir(x,&lista);

    for (int i = 0; i < 10; ++i) {
        Ler(&x);
        Inserir(x, &lista);
        Imprimir(&x);
    }
    return 0;
}
