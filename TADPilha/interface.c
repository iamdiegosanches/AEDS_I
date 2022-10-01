#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

void MSG_MENU( )
{
    system("clear");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. ENFILEIRAR");
    printf("  \n\t2. PESQUISAR");
    printf("  \n\t3. DESENFILEIRAR");
    printf("  \n\t4. IMPRIMIR");
    printf("  \n\t5. SAIR");
}

void MENU(TPilha *pilha1)
{
    TProduto produto;
    int opcao=0;
    //int i;
    do
    {
        MSG_MENU();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1: // EPILHAR
            printf("\n\t >>>>>> MSG: INSIRA O PRODUTO! <<<<<<\n\n");
            LerProduto(&produto);
            Push(pilha1, produto);

            break;
        case 2: // PESQUISAR
            printf("\nInforme o codigo do produto que deseja pesquisar: ");
            fflush(stdin);
            scanf("%d", &produto.codigo);

            TProduto Aux = Pesquisar(produto, pilha1);
            if(Aux.codigo == produto.codigo)
                printf("\nO produto esta na lista!\n\n");
            else
                printf("\nO produto NAO esta na lista!\n\n");

            break;
        case 3: // DESEMPILHAR
            Pop(pilha1, &produto);

            if(produto.codigo != -1)
                printf("\nItem excluido com sucesso!\n");
            else
                printf("\n >>>>>Nao foi possivel excluir o produto! Poduto NAO pertence a lista!!<<<< \n");

            break;
        case 4: // IMPRIMIR
            printf("\n\n\t >>>>>> IMPRIMINDO A LISTA!! <<<<<<");
            Imprimir(pilha1);

            break;
        case 5:
            Liberar(pilha1);
            //system("clear");
            system("cls");
            printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<\n");
            system("PAUSE");
            break;
        default:
            //system("clear");
            system("cls");
            printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<\n");
            system("PAUSE");
        } // fim do bloco switch
    }
    while(opcao != 5);
}

