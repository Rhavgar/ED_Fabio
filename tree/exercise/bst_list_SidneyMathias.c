#include<stdio.h>
#include<stdlib.h>

// Estrutura do nó da árvore
struct reg_no
{
  struct reg_no *ptr_esquerda;
  int dado;
  struct reg_no *ptr_direita;
};

// Definindo datatype para o struct
typedef struct reg_no tipo_no;

// Função basica para alocar um novo nó
tipo_no* novo_no(int dado)
{
  tipo_no *novo = NULL;

  novo = (tipo_no*) malloc(sizeof(tipo_no));
  novo->dado = dado;
  novo->ptr_esquerda = NULL;
  novo->ptr_direita = NULL;

  return novo;
}

// Inclusão de dado (recursivo)
void incluir(tipo_no **raiz, int dado) // 164
{
  if (*raiz == NULL)
  {
    *raiz = novo_no(dado);
  }
  else
  {
    if (dado < (*raiz)->dado)
    {
      incluir(&((*raiz)->ptr_esquerda), dado);
    }
    else
    {
      if (dado > (*raiz)->dado)
      {
        incluir(&((*raiz)->ptr_direita), dado);
      }
    }
  }
}

// Inclusão de dado (iterativo)
void incluir_iterativo(tipo_no **raiz, int dado) // 164
{
  tipo_no *atual = *raiz, *anterior = NULL;

  if (*raiz == NULL)
  {
    *raiz = novo_no(dado);
  }

  else
  {
    while (atual != NULL)
    {
      anterior = atual;
      if (dado < atual->dado)
      {
        atual = atual->ptr_esquerda;
      }
      else
      {
        atual = atual->ptr_direita;
      }
    }
    if (dado < anterior->dado)
    {
      anterior->ptr_esquerda = novo_no(dado);
    }
    else
    {
      anterior->ptr_direita = novo_no(dado);
    }
  }
}

// Listagem de dados em ordem de inclusão
void listar_pre_ordem(tipo_no *raiz) // 166
{
  if (raiz != NULL)
  {
    printf("%d ", raiz->dado);
    listar_pre_ordem(raiz->ptr_esquerda);
    listar_pre_ordem(raiz->ptr_direita);
  }
}

// Listagem de dados em ordem crescente
void listar_em_ordem(tipo_no *raiz) // 165
{
  if (raiz != NULL)
  {
    listar_em_ordem(raiz->ptr_esquerda);
    printf("%d ", raiz->dado);
    listar_em_ordem(raiz->ptr_direita);
  }
}

// Listagem de dados em ordem invertiva de inclusão
void listar_pos_ordem(tipo_no *raiz) // 167
{
  if (raiz != NULL)
  {
    listar_pos_ordem(raiz->ptr_esquerda);
    listar_pos_ordem(raiz->ptr_direita);
    printf("%d ", raiz->dado);
  }
}

// Verifica a presença de um valor 'n'
int verificar_n(tipo_no *raiz, int dado) // 168
{
  if (raiz != NULL)
  {
    if (raiz->dado == dado)
    {
      return 1;
    }
    else
    {
      if (dado < raiz->dado)
      {
        verificar_n(raiz->ptr_esquerda, dado);
      }
      else
      {
        verificar_n(raiz->ptr_direita, dado);
      }
    }
  }
  else
  {
    return 0;
  }
}

// Retorna o maior valor da árvore
int maior_valor(tipo_no *raiz) // 169
{
  if (raiz != NULL)
  {
    if (raiz->ptr_direita != NULL)
    {
      maior_valor(raiz->ptr_direita);
    }
    else
    {
      return raiz->dado;
    }
  }
  else
  {
    return 0;
  }
}

// Retorna o menor valor da árvore
int menor_valor(tipo_no *raiz) // 170
{
  if (raiz != NULL)
  {
    if (raiz->ptr_esquerda != NULL)
    {
      menor_valor(raiz->ptr_esquerda);
    }
    else
    {
      return raiz->dado;
    }
  }
  else
  {
    return 0;
  }
}

//Retorna a quantidade de NULLs na árvore
int qtd_null(tipo_no *raiz) // 172
{
  int quantidade = 0;

  if (raiz != NULL)
  {
    quantidade += qtd_null(raiz->ptr_esquerda);
    quantidade += qtd_null(raiz->ptr_direita);

    return quantidade;
  }
  else
  {
    return 1;
  }
}

// Retorna a soma dos valores dos nós
int soma_nos(tipo_no *raiz) // 173
{
  if (raiz != NULL)
  {
    return (raiz->dado + soma_nos(raiz->ptr_esquerda) + soma_nos(raiz->ptr_direita));
  }
  else
  {
    return 0;
  }
}

// Retorna o número de nós múltiplos de três
int num_nos_x3(tipo_no *raiz) // 174
{
  int quantidade = 0;

  if (raiz != NULL)
  {
    if (((raiz->dado) % 3) == 0)
    {
      return (++quantidade + num_nos_x3(raiz->ptr_esquerda) + num_nos_x3(raiz->ptr_direita));
    }
    else
    {
      return (quantidade + num_nos_x3(raiz->ptr_esquerda) + num_nos_x3(raiz->ptr_direita));
    }
  }
  else
  {
    return 0;
  }
}

// Retorna o número de nós da árvore
int num_nos(tipo_no *raiz) // 175
{
  int quantidade = 0;

  if (raiz != NULL)
  {
    return (++quantidade + num_nos(raiz->ptr_esquerda) + num_nos(raiz->ptr_direita));
  }
  else
  {
    return 0;
  }
}

// Retorna a média dos valores da árvore
int media_arvore(tipo_no *raiz) // 171
{
  if (raiz != NULL)
  {
    return ((soma_nos(raiz)) / (num_nos(raiz)));
  }
  else
  {
    return 0;
  }
}

// Retorna o número de folhas da árvore
int num_folhas(tipo_no *raiz) // 176
{
  int quantidade = 0;

  if (raiz != NULL)
  {
    if ((raiz->ptr_esquerda == NULL) && (raiz->ptr_direita == NULL))
    {
      return ++quantidade;
    }
    else
    {
      return (num_folhas(raiz->ptr_esquerda) + num_folhas(raiz->ptr_direita));
    }
  }
  else
  {
    return 0;
  }
}

// Retorna a altura da árvore
int altura_arvore(tipo_no *raiz) // 177
{
  int alt_esquerda = 0, alt_direita = 0;

  if (raiz != NULL)
  {
    alt_esquerda = altura_arvore(raiz->ptr_esquerda);
    alt_direita = altura_arvore(raiz->ptr_direita);

    if (alt_esquerda > alt_direita)
    {
      return ++alt_esquerda;
    }
    else
    {
      return ++alt_direita;
    }
  }
  else
  {
    return 0;
  }
}

// Verifica se a árvore é estritamente binária
int verificar_binaria(tipo_no *raiz) // 178
{
  int condicao = 0;

  if (raiz != NULL)
  {
    if (((raiz->ptr_esquerda) == NULL) && ((raiz->ptr_direita) == NULL))
    {
      return condicao;
    }
    else if (((raiz->ptr_esquerda) != NULL) && ((raiz->ptr_direita) != NULL))
    {
      return (condicao + verificar_binaria(raiz->ptr_esquerda) + verificar_binaria(raiz->ptr_direita));
    }
    else
    {
      return (++condicao + verificar_binaria(raiz->ptr_esquerda) + verificar_binaria(raiz->ptr_direita));
    }
  }
  else
  {
    return 0;
  }
}

// Copia uma árvore
tipo_no* copiar_arvore(tipo_no *raiz) // 179
{
  tipo_no *novo = NULL;

  if (raiz != NULL)
  {
    novo = novo_no(raiz->dado);
    novo->ptr_esquerda = copiar_arvore(raiz->ptr_esquerda);
    novo->ptr_direita = copiar_arvore (raiz->ptr_direita);

    return novo;
  }
  else
  {
    return 0;
  }
}

// Exclusão do maior nó
int excluir_maior(tipo_no **raiz) // 181
{
  tipo_no *auxiliar = NULL;
  int dado;

  if (*raiz != NULL)
  {
    if ((*raiz)->ptr_direita != NULL)
    {
      return excluir_maior(&((*raiz)->ptr_direita));
    }
    else
    {
      auxiliar = *raiz;
      dado = (*raiz)->dado;
      *raiz = (*raiz)->ptr_esquerda;
      free(auxiliar);
      return dado;
    }
  }
  else
  {
    return 0;
  }
}

// Exclusão de um nó especifico
void excluir_no(tipo_no **raiz, int dado) // 181
{
  tipo_no *auxiliar;

  if (*raiz != NULL)
  {
    if (dado < (*raiz)->dado)
    {
      excluir_no(&((*raiz)->ptr_esquerda), dado);
    }
    else
    {
      if (dado > (*raiz)->dado)
      {
        excluir_no(&((*raiz)->ptr_direita), dado);
      }
      else
      {
        if ((*raiz)->ptr_esquerda == NULL)
        {
          auxiliar = *raiz;
          *raiz = (*raiz)->ptr_direita;
          free(auxiliar);
        }
        else
        {
          if ((*raiz)->ptr_direita == NULL)
          {
            auxiliar = *raiz;
            *raiz = (*raiz)->ptr_esquerda;
            free(auxiliar);
          }
          else
          {
            (*raiz)->dado = excluir_maior(&((*raiz)->ptr_esquerda));
          }
        }
      }
    }
  }
}

// Verifica se a árvore binária é de busca
int verificar_busca(tipo_no *raiz) // 182
{
  if (raiz != NULL)
  {
    if (raiz->ptr_esquerda != NULL)
    {
      if ((raiz->ptr_esquerda->dado) < (raiz->dado))
      {
        return verificar_busca(raiz->ptr_esquerda);
      }
      else
      {
        return 1;
      }
    }
    if (raiz->ptr_direita != NULL)
    {
      if((raiz->ptr_direita->dado) > (raiz->dado))
      {
        return verificar_busca(raiz->ptr_direita);
      }
      else
      {
        return 1;
      }
    }
  }
  else
  {
    return 0;
  }
}

int main()
{
  int opcao, dado;
  tipo_no *raiz = NULL, *clone = NULL;;

  do
  {
    printf("\n0 - Sair\n");
    printf("1 - Incluir Elemento\n");
    printf("2 - Listar Pré-Ordem\n");
    printf("3 - Listar em Ordem\n");
    printf("4 - Listar Pós-Ordem\n");
    printf("5 - Verificar Elemento N\n");
    printf("6 - Maior Valor\n");
    printf("7 - Menor Valor\n");
    printf("8 - Média dos Valores\n");
    printf("9 - Quantidade de NULLs\n");
    printf("10 - Soma dos Valores\n");
    printf("11 - Quantidade de Múltiplos de 3\n");
    printf("12 - Quantidade de Nós\n");
    printf("13 - Quantidade de Folhas\n");
    printf("14 - Altura da Árvore\n");
    printf("15 - Estritamente Binária\n");
    printf("16 - Copiar Árvore\n");
    printf("17 - Excluir Maior\n");
    printf("18 - Excluir Número\n");
    printf("19 - Verificar BST\n");
    printf("\nEntre com a opção: ");
    scanf("%d", &opcao);
    switch(opcao)
    {
      case 1: printf("\nEntre com o dado a ser incluido: ");
              scanf("%d", &dado);
              incluir_iterativo(&raiz, dado);
              break;
      case 2: printf("\n");
              listar_pre_ordem(raiz);
              printf("\n");
              break;
      case 3: printf("\n");
              listar_em_ordem(raiz);
              printf("\n");
              break;
      case 4: printf("\n");
              listar_pos_ordem(raiz);
              printf("\n");
              break;
      case 5: printf("\nEntre com o dado a verificar: ");
              scanf("%d", &dado);
              if (verificar_n(raiz, dado) == 1)
              {
                printf("\nDado existe na árvore!\n");
              }
              else
              {
                printf("\nDado não existe na árvore!\n");
              }
              break;
      case 6: printf("\nMaior valor: %d\n", maior_valor(raiz));
              break;
      case 7: printf("\nMenor valor: %d\n", menor_valor(raiz));
              break;
      case 8: printf("Média dos valores: %d\n", media_arvore(raiz));
              break;
      case 9: printf("\nQuantidade de NULLs: %d\n", qtd_null(raiz));
              break;
      case 10:printf("\nSoma dos valores: %d\n", soma_nos(raiz));
              break;
      case 11:printf("\nQuantidade de múltiplos de 3: %d\n", num_nos_x3(raiz));
              break;
      case 12:printf("\nQuantidade de nós: %d\n", num_nos(raiz));
              break;
      case 13:printf("\nQuantidade de folhas: %d\n", num_folhas(raiz));
              break;
      case 14:printf("\nAltura da árvore: %d\n", altura_arvore(raiz));
              break;
      case 15:if (verificar_binaria(raiz) == 0)
              {
                printf("\nA árvore é estritamente binária!\n");
              }
              else
              {
                printf("\nA árvore não é estritamente binária!\n");
              }
              break;
      case 16:clone = copiar_arvore(raiz);
              printf("\nÁrvore Clone:\n");
              printf("\n");
              listar_pre_ordem(clone);
              printf("\n");
              break;
      case 17:excluir_maior(&raiz);
              break;
      case 18:printf("\nEntre com o dado a ser excluido: ");
              scanf("%d", &dado);
              excluir_no(&raiz, dado);
              break;
      case 19:if (verificar_busca(raiz) == 0)
              {
                printf("\nA árvore é de busca!\n");
              }
              else
              {
                printf("\nA árvore não é de busca!\n");
              }
              break;
    }
  }
  while (opcao != 0);

  return 0;
}
