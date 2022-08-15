#include <stdio.h>
#include <stdlib.h>

typedef struct endereco {
    char rua[50];
    int numero;
    char bairro[50];
    char complemento[50];
    char cidade[50];
    char estado[50];
    int CEP;
} TEndereco;

typedef struct livro {
    char ISBN[20];
    char titulo[100];
    int edicao;
    TEndereco endereco;
} TLivro;

void leia_livro(TLivro *pLivro);

void print_livro(TLivro *pLivro);

int main() {
    TLivro *ptr = (TLivro *)calloc(10, sizeof(TLivro));
    int i = 0;

    while(i != 10) {
        leia_livro(ptr+i);
        i++;
    }

    i = 0;
    while(i != 10) {
        print_livro(ptr+i);
        i++;
    }

    free(ptr);
    return 0;
}

void print_livro(TLivro *pLivro) {
    printf("ISBN: %s", pLivro->ISBN);
    printf("Titulo: %s", pLivro->titulo);
    printf("Edicao: %d\n", pLivro->edicao);
    printf("Endereco:\n");
    printf("    -Rua: %s", pLivro->endereco.rua);
    printf("    -Numero: %d\n", pLivro->endereco.numero);
    printf("    -Bairro: %s", pLivro->endereco.bairro);
    printf("    -Complemento: %s", pLivro->endereco.complemento);
    printf("    -Cidade: %s", pLivro->endereco.cidade);
    printf("    -CEP: %d\n\n", pLivro->endereco.CEP);
}

void leia_livro(TLivro *pLivro) {
    printf("Digite o ISBN do livro:\n");
    fflush(stdin);
    fgets(pLivro->ISBN, 20, stdin);

    printf("Digite o Titulo do livro:\n");
    fflush(stdin);
    fgets(pLivro->titulo, 100, stdin);

    printf("Digite o numero de edicao do livro:\n");
    fflush(stdin);
    scanf("%d", &pLivro->edicao);

    printf("Digite o endereco\n");
    printf(" -Digite a rua:\n");
    fflush(stdin);
    fgets(pLivro->endereco.rua, 50, stdin);

    printf(" -Digite o numero:\n");
    fflush(stdin);
    scanf("%d", &pLivro->endereco.numero);

    printf(" -Digite o bairro:\n");
    fflush(stdin);
    fgets(pLivro->endereco.bairro, 50, stdin);

    printf(" -Digite o complemento:\n");
    fflush(stdin);
    fgets(pLivro->endereco.complemento, 50, stdin);

    printf(" -Digite a cidade:\n");
    fflush(stdin);
    fgets(pLivro->endereco.cidade, 50, stdin);

    printf(" -Digite o estado:\n");
    fflush(stdin);
    fgets(pLivro->endereco.estado, 50, stdin);

    printf(" -Digite o CEP:\n");
    fflush(stdin);
    scanf("%d", &pLivro->endereco.CEP);
}
