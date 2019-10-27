#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validacaoEhNumero(char);
int validacaoEhLetra(char);
int validacaoPalavra(char[]);

typedef struct produto Prod;

struct produto {
  int cod;
  char nome[15];
  char marca[15];
  int quant;
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
  printf("0 - Encerrar\n");
  printf("Escolha sua opção: ");
  scanf("%d", &op);
  system("cls || clear");
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
  while((validacaoEhNumero(produto->cod)!=1)) {
    printf("inválido");
    printf("\nInforme o código da empresa: ");
    scanf("%d", &produto->cod);
  }
  printf("Informe o nome do produto: ");
  scanf(" %14[^\n]", produto->nome);
  while((validacaoPalavra(produto->nome)!= 1)) {
    printf("inválido");
    printf("\nInforme o nome do produto: ");
    scanf(" %14[^\n]", produto->nome);
  }
  printf("Informe a marca do produto: ");
  scanf(" %14[^\n]", produto->marca);
  while((validacaoPalavra(produto->marca)!= 1)) {
    printf("inválido");
    printf("\nInforme a marca do produto: ");
    scanf(" %14[^\n]", produto->marca);
  }
  printf("Informe a quantidade do produto: ");
  scanf("%d", &produto->quant);
  while((validacaoEhNumero(produto->quant)!=1)) {
    printf("inválido");
    printf("\nInforme a quantidade do produto: ");
    scanf("%d", &produto->quant);
  }
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
  printf("= = = S G P e t = = = \n");
  printf("= = Editar produto = = \n");
  printf("= = = = = = = = = = = \n");
  printf("Informe o nome do produto a ser alterado: ");
  scanf(" %14[^\n]", procurado);
  produto = (Prod*) malloc(sizeof(Prod));
  achou = 0;
  while((!achou) && (fread(produto, sizeof(Prod), 1, fp))) {
   if ((strcmp(produto->nome, procurado) == 0) && (produto->status == '1')) {
     achou = 1;
   }
  }
  if (achou) {
    exibeProduto(produto);
    getchar();
    printf("Deseja realmente editar este produto (s/n)? ");
    scanf("%c", &resp);
    if (resp == 's' || resp == 'S') {
      printf("\nInforme o código do produto: ");
      scanf("%d", &produto->cod);
      while((validacaoEhNumero(produto->cod)!=1)) {
        printf("inválido");
        printf("\nInforme o código da empresa: ");
        scanf("%d", &produto->cod);
      }
      printf("Informe o nome do produto: ");
      scanf(" %14[^\n]", produto->nome);
      while((validacaoPalavra(produto->nome)!= 1)) {
        printf("inválido");
        printf("\nInforme o nome do produto: ");
        scanf(" %14[^\n]", produto->nome);
      }
      printf("Informe a tipo do produto: ");
      scanf(" %14[^\n]", produto->marca);
      while((validacaoPalavra(produto->nome)!= 1)) {
        printf("inválido");
        printf("\nInforme a marca do produto: ");
        scanf(" %14[^\n]", produto->marca);
      }
      printf("Informe a quantidade disponivel do produto: ");
      scanf("%d", &produto->quant);
      while((validacaoEhNumero(produto->quant)!=1)) {
        printf("inválido");
        printf("\nInforme a quantidade disponivel do produto: ");
        scanf("%d", &produto->quant);
      }
      getchar();
      produto->status = '1';
      fseek(fp, (-1)*sizeof(Prod), SEEK_CUR);
      fwrite(produto, sizeof(Prod), 1, fp);
      printf("\nProduto editado com sucesso!!!\n");
    } else {
      printf("\nOk, os dados não foram alterados\n");
    }
  } else {
    printf("O produto %s não foi encontrado...\n", procurado);
  }
  free(produto);
  fclose(fp);
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
  fclose(fp);
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
  printf("Marca: %s\n", produto->marca);
  printf("Quantidade: %d\n", produto->quant);
  printf("\n");
}

int validacaoEhNumero(char c) {
  if (c>='0'&& c<='9') {
    return 0;
  }
  else {
    return 1;
  }
}

int validacaoPalavra(char s[]) {
  int tam;
  tam = strlen(s) - 1;
  for (int i = 0; i < tam; i++) {
    if (!validacaoEhLetra(s[i])) {
      return 0;
    }
  }
  return 1;
}

int validacaoEhLetra(char c) {
  if (c>='A' && c<='Z') {
    return 1;
  }
  else if (c>='a' && c<='z') {
    return 1;
  }
  else {
    return 0;
  }
}
