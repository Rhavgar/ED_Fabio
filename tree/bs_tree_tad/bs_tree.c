#include<stdio.h>
#include<stdlib.h>

struct reg_no
{
    struct reg_no *ptr_esquerda;
    int dado;
    struct reg_no *ptr_direita;
};

typedef struct reg_no tipo_no;
typedef tipo_no **tipo_arvore;

tipo_no** criar_arvore()
{
    return (tipo_no**) malloc(sizeof(tipo_no*));
}

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

void listar_pre_ordem(tipo_no **sub_raiz)
{
    if (*sub_raiz != NULL)
    {
        printf("%d ", (*sub_raiz)->dado);
        listar_pre_ordem(&((*sub_raiz)->ptr_esquerda));
        listar_pre_ordem(&((*sub_raiz)->ptr_direita));
    }
}

void listar_em_ordem(tipo_no **sub_raiz)
{
    if (*sub_raiz != NULL)
    {
        listar_em_ordem(&((*sub_raiz)->ptr_esquerda));
        printf("%d ", (*sub_raiz)->dado);
        listar_em_ordem(&((*sub_raiz)->ptr_direita));
    }
}

void listar_pos_ordem(tipo_no **sub_raiz)
{
    if (*sub_raiz != NULL)
    {
        listar_pos_ordem(&((*sub_raiz)->ptr_esquerda));
        listar_pos_ordem(&((*sub_raiz)->ptr_direita));
        printf("%d ", (*sub_raiz)->dado);
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
