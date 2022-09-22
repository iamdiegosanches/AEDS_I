#include <stdio.h>
#include <stdlib.h>

#include "interface.h"

void MSG_MENU( )
{
    system("clear");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. INSERIR");
    printf("  \n\t2. PESQUISAR");
    printf("  \n\t3. EXCLUIR");
    printf("  \n\t4. IMPRIMIR");
    printf("  \n\t5. SAIR");
}

void MENU(TLista *lista1)
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
        case 1: // INSERUR
            printf("\n\t >>>>>> MSG: INSIRA O PRODUTO! <<<<<<\n\n");
            LerProduto(&produto);
            Inserir(produto, lista1);

            break;
        case 2: // PESQUISAR
            printf("\nInforme o codigo do produto que deseja pesquisar: ");
            fflush(stdin);
            scanf("%d", &produto.codigo);

            if(Pesquisar(*lista1, produto) != NULL)
                printf("\nO produto esta na lista!\n\n");
            else
                printf("\nO produto NAO esta na lista!\n\n");

            break;
        case 3: // EXCLUIR
            printf("\nInforme o codigo do produto que deseja excluir: ");
            scanf("%d", &produto.codigo);

            Excluir(lista1, &produto);

            if(produto.codigo != -1)
                printf("\nItem excluido com sucesso!\n");
            else
                printf("\n >>>>>Nao foi possivel excluir o produto! Poduto NAO pertence a lista!!<<<< \n");

            break;
        case 4: // IMPRIMIR
            printf("\n\n\t >>>>>> IMPRIMINDO A LISTA!! <<<<<<");
            Imprimir(*lista1);

            break;
        case 5:
            Liberar(lista1);
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
