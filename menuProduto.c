#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto Prod;

struct produto {
  int cod;
  char nome[15];
  char tipo[15];
  char data[11];
  char status;
};

int menuProduto(void);
void cadastraProduto(void);
void buscaProduto(void);
void editaProduto(void);
void excluiProduto(void);
void listaProduto(void);
void exibeProduto(Prod*);
void gravaProduto(Prod*);

int main(void) {
  int opcao;
  opcao = menuProduto();
  while (opcao != 0) {
    switch (opcao) {
      case 1 :  cadastraProduto();
                break;
      case 2 :  buscaProduto();
                break;
      case 3 :  editaProduto();
                break;
      case 4 :  excluiProduto();
                break;
      case 5 :  listaProduto();
                break;
    }
    opcao = menuProduto();
  }
  printf("\nFim do programa!\n\n");
  return 0;
}

int menuProduto(void) {
  int op;
  printf("\n\n");
  printf("= = = = = = = = = = = = = = = = = = = \n");
  printf("= = = =  Cadastro do Produto  = = = = \n");
  printf("= = = = = = = = = = = = = = = = = = = \n");
  printf("1 - Cadastrar produto\n");
  printf("2 - Pesquisar produto\n");
  printf("3 - Alterar produto\n");
  printf("4 - Excluir produto\n");
  printf("5 - Listar todos os produtos\n");
  //printf("6 - Sobre o produto\n");
  printf("0 - Encerrar\n");
  printf("Escolha sua opção: ");
  scanf("%d", &op);
  return op;
}


void cadastraProduto(void) {
  Prod* produto;
  printf("\n\n");
  printf("= = = = = = = = = = = \n");
  printf("= Cadastrar Produto = \n");
  printf("= = = = = = = = = = = \n");
  produto = (Prod*) malloc(sizeof(Prod));
  printf("\nInforme o código do produto: ");
  scanf("%d", &produto->cod);
  printf("Informe o nome do produto: ");
  scanf(" %14[^\n]", produto->nome);
  printf("Informe a tipo do produto: ");
  scanf(" %14[^\n]", produto->tipo);
  printf("Informe a data de cadastro do produto (dd/mm/aaaa): ");
  scanf(" %10[^\n]", produto->data);
  getchar();
  produto->status = '1';
  printf("###############################\n");
  exibeProduto(produto);
  printf("###############################\n");
  gravaProduto(produto);
}


void buscaProduto(void) {
  FILE* fp;
  Prod* produto;
  int achou;
  char procurado[15];
  fp = fopen("produto.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  printf("= = = = = = = = = = = = \n");
  printf("= =  Buscar Produto = = \n");
  printf("= = = = = = = = = = = = \n");
  printf("Informe o nome do produto a ser buscado: ");
  scanf(" %14[^\n]", procurado);
  produto = (Prod*) malloc(sizeof(Prod));
  achou = 0;
  while((!achou) && (fread(produto, sizeof(Prod), 1, fp))) {
   if ((strcmp(produto->nome, procurado) == 0) && (produto->status == '1')) {
     achou = 1;
   }
  }
  fclose(fp);
  if (achou) {
    exibeProduto(produto);
  } else {
    printf("O produto %s não foi encontrado...\n", procurado);
  }
  free(produto);
}


void editaProduto(void) {
  printf("Menu edita \n");
}


void excluiProduto(void) {
  FILE* fp;
  Prod* produto;
  int achou;
  char resp;
  char procurado[15];
  fp = fopen("produto.dat", "r+b");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  printf("= = = = = = = =  = = = \n");
  printf("= = Apagar Produto = = \n");
  printf("= = = = = = = = =  = = \n");
  printf("Informe o nome do produto a ser apagado: ");
  scanf(" %14[^\n]", procurado);
  produto = (Prod*) malloc(sizeof(Prod));
  achou = 0;
  while((!achou) && (fread(produto, sizeof(Prod), 1, fp))) {
   if ((strcmp(produto->nome, procurado) == 0) && (produto->status == '1')) {
     achou = 1;
   }
  }
  fclose(fp);
  if (achou) {
    exibeProduto(produto);
    getchar();
    printf("Deseja realmente apagar este produto (s/n)? ");
    scanf("%c", &resp);
    if (resp == 's' || resp == 'S') {
      produto->status = '0';
      fseek(fp, -1*sizeof(Prod), SEEK_CUR);
      fwrite(produto, sizeof(Prod), 1, fp);
      printf("\nProduto excluído com sucesso!!!\n");
     } else {
       printf("\nOk, os dados não foram alterados\n");
     }
  } else {
    printf("O produto %s não foi encontrado...\n", procurado);
  }
  free(produto);
}


void listaProduto(void) {
  FILE* fp;
  Prod* produto;
  fp = fopen("produto.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  printf("= = = = = = = = = = = \n");
  printf("= = Exibe Produto = = \n");
  printf("= = = = = = = = = = = \n");
  produto = (Prod*) malloc(sizeof(Prod));
  while(fread(produto, sizeof(Prod), 1, fp)) {
    if (produto->status == '1') {
      exibeProduto(produto);
    }
  }
  fclose(fp);
  free(produto);
}


void gravaProduto(Prod* produto) {
  FILE* fp;
  fp = fopen("produto.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  fwrite(produto, sizeof(Prod), 1, fp);
  fclose(fp);
}


void exibeProduto(Prod* produto) {
  printf("Código: %d\n", produto->cod);
  printf("Nome: %s\n", produto->nome);
  printf("Tipo: %s\n", produto->tipo);
  printf("Data de cadastro: %s\n", produto->data);
  printf("Status: %c\n", produto->status);
  printf("\n");
}