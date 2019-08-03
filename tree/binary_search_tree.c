#include<stdio.h>
#include<stdlib.h>

struct reg_no
{
    struct reg_no *ptr_esquerda;
    int dado;
    struct reg_no *ptr_direita;
};

typedef struct reg_no tipo_no;

void incluir(tipo_no **sub_raiz, int dado)
{
    if (*sub_raiz == NULL)
    {
        *sub_raiz = (tipo_no*) malloc(sizeof(tipo_no));
        (*sub_raiz)->dado = dado;
        (*sub_raiz)->ptr_esquerda = NULL;
        (*sub_raiz)->ptr_direita = NULL;
    }
    else
    {
        if (dado < (*sub_raiz)->dado)
        {
            incluir(&((*sub_raiz)->ptr_esquerda), dado);
        }
        else
        {
            if (dado > (*sub_raiz)->dado)
            {
                incluir(&((*sub_raiz)->ptr_direita), dado);
            }
        }
    }
}

void listar_pre_ordem(tipo_no *sub_raiz)
{
    if (sub_raiz != NULL)
    {
        printf("%d ", sub_raiz->dado);
        listar_pre_ordem(sub_raiz->ptr_esquerda);
        listar_pre_ordem(sub_raiz->ptr_direita);
    }
}

void listar_em_ordem(tipo_no *sub_raiz)
{
    if (sub_raiz != NULL)
    {
        listar_em_ordem(sub_raiz->ptr_esquerda);
        printf("%d ", sub_raiz->dado);
        listar_em_ordem(sub_raiz->ptr_direita);
    }
}

void listar_pos_ordem(tipo_no *sub_raiz)
{
    if (sub_raiz != NULL)
    {
        listar_pos_ordem(sub_raiz->ptr_esquerda);
        listar_pos_ordem(sub_raiz->ptr_direita);
        printf("%d ", sub_raiz->dado);
    }
}

int excluir_maior(tipo_no **sub_raiz)
{
    tipo_no *auxiliar;
    int dado;

    if (*sub_raiz != NULL)
    {
        if ((*sub_raiz)->ptr_direita != NULL)
        {
            return excluir_maior(&((*sub_raiz)->ptr_direita));
        }
        else
        {
            auxiliar = *sub_raiz;
            dado = (*sub_raiz)->dado;
            *sub_raiz = (*sub_raiz)->ptr_esquerda;
            free(auxiliar);
            return dado;
        }
    }
    return -1;
}


void excluir(tipo_no **sub_raiz, int dado)
{
    tipo_no *auxiliar;
    if (*sub_raiz != NULL)
    {
        if (dado < (*sub_raiz)->dado)
        {
            excluir(&((*sub_raiz)->ptr_esquerda), dado);
        }
        else
        {
            if (dado > (*sub_raiz)->dado)
            {
                excluir(&((*sub_raiz)->ptr_direita), dado);
            }
            else
            {
                if ((*sub_raiz)->ptr_esquerda == NULL)
                {
                    auxiliar = *sub_raiz;
                    *sub_raiz = (*sub_raiz)->ptr_direita;
                    free(auxiliar);
                }
                else
                {
                    if ((*sub_raiz)->ptr_direita == NULL)
                    {
                        auxiliar = *sub_raiz;
                        *sub_raiz = (*sub_raiz)->ptr_esquerda;
                        free(auxiliar);
                    }
                    else
                    {
                        (*sub_raiz)->dado = excluir_maior(&((*sub_raiz)->ptr_esquerda));
                    }
                }
            }
        }
    }
}

int main()
{
    int opcao, dado;
    tipo_no *raiz = NULL;

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
                    incluir(&raiz, dado);
                    break;
            case 2: listar_pre_ordem(raiz);
                    break;
            case 3: listar_em_ordem(raiz);
                    break;
            case 4: listar_pos_ordem(raiz);
                    break;
            case 5: printf("Entre com o dado a ser excluido:");
                    scanf("%d", &dado);
                    excluir(&raiz, dado);
                    break;
            case 6: printf("Valor excluido: %d\n", excluir_maior(&raiz));
                    break;
        }
    }
    while (opcao != 0);
    return 0;
}
