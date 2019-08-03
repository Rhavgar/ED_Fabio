#include<stdio.h>
#include"arvore_busca.h"

int main()
{
    int opcao, dado;
    tipo_arvore arvore = NULL;

    arvore = criar_arvore();

    do
    {
        printf("\n\n0 - Sair\n");
        printf("1 - Incluir elemento\n");
        printf("2 - Listar pré-ordem\n");
        printf("3 - Listar em ordem\n");
        printf("4 - Listar pós-ordem\n");
        printf("5 - Excluir elemento\n");
        printf("6 - Excluir maior elemento\n");
        printf("Entre com a opção:");
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1: printf("Entre com o dado a ser incluido:");
                    scanf("%d", &dado);
                    incluir(arvore, dado);
                    break;
            case 2: listar_pre_ordem(arvore);
                    break;
            case 3: listar_em_ordem(arvore);
                    break;
            case 4: listar_pos_ordem(arvore);
                    break;
            case 5: printf("Entre com o dado a ser excluido:");
                    scanf("%d", &dado);
                    excluir(arvore, dado);
                    break;
            case 6: printf("Valor excluido: %d\n", excluir_maior(arvore));
                    break;
        }
    }
    while (opcao != 0);
    return 0;
}
