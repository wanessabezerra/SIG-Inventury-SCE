#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int validacaoEhNumero(char);
int validacaoEhLetra(char);
int validacaoPalavra(char[]);

typedef struct compra Compra;

struct compra {
  int cod;
  char nome[81];
  char marca[25];
  char status;
  int qntd;
  
};

int menuCompra(void);
void cadastraCompra(void);
void buscaCompra(void);
void editaCompra(void);
void excluiCompra(void);
void listaCompra(void);
void exibeCompra(Compra*);
void gravaCompra(Compra*);
void dataEhora(Compra*);


int main(void) {
  int opcao;
  opcao = menuCompra();
  while (opcao != 0) {
    switch (opcao) {
      case 1 :  cadastraCompra();
                break;
      case 2 :  buscaCompra();
                break;
      case 3 :  editaCompra();
                break;
      case 4 :  excluiCompra();
                break;
      case 5 :  listaCompra();
                break;
    }
    opcao = menuCompra();
  }
  printf("\nFim do programa!\n\n");
  return 0;
}

int menuCompra(void) {
  int op;
  printf("\n\n");
  printf("= = = = = = = = = = = = = = = = = = = \n");
  printf("= = = =  Compras de Produto  = = = = \n");
  printf("= = = = = = = = = = = = = = = = = = = \n");
  printf("1 - Cadastrar Compras\n");
  printf("2 - Pesquisar Compras\n");
  printf("3 - Atualizar Compras\n");
  printf("4 - Deletar Compras\n");
  printf("5 - Listar todos as Compras\n");
  printf("0 - Retornar\n");
  printf("Escolha sua opção: ");
  scanf("%d", &op);
  system("cls || clear");
  return op;
}


void cadastraCompra(void) {
  Compra* compra;
  printf("\n\n");
  printf(" = = = = = = = = = = = = = = = = =\n");
  printf(" =  Cadastrar Compra de Produtos =\n");
  printf(" = = = = = = = = = = = = = = = = =\n");
  compra = (Compra*) malloc(sizeof(Compra));
  printf("\nInforme o código da empresa: ");
  scanf("%d", &compra->cod);
  while((validacaoEhNumero(compra->cod)!=1)) {
    printf("inválido");
    printf("\nInforme o código da empresa: ");
    scanf("%d", &compra->cod);
  }
  printf("Informe o nome do produto: ");
  scanf(" %80[^\n]", compra->nome);
  while((validacaoPalavra(compra->nome)!= 1)) {
    printf("inválido");
    printf("\nInforme o nome do produto: ");
    scanf(" %80[^\n]", compra->nome);
  }
  printf("Informe a marca do produto: ");
  scanf(" %24[^\n]", compra->marca);
  printf("Informe a quantidade do produto: ");
  scanf("%d", &compra->qntd);
  while((validacaoEhNumero(compra->qntd)!=1)) {
    printf("inválido");
    printf("\nInforme a quantidade do produto: ");
    scanf("%d", &compra->qntd);
  }
  (dataEhora(compra));
  getchar();
  compra->status = '1';
  printf("###############################\n");
  exibeCompra(compra);
  printf("###############################\n");
  gravaCompra(compra);
}


void buscaCompra(void) {
  FILE* fp;
  Compra* compra;
  int achou;
  char procurado[15];
  fp = fopen("compra.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  printf("= = = = = = = = = = = = \n");
  printf("= =  Buscar Compras = = \n");
  printf("= = = = = = = = = = = = \n");
  printf("Informe o nome do produto a ser buscado: ");
  scanf(" %14[^\n]", procurado);
  while((validacaoPalavra(compra->nome)!= 1)) {
    printf("inválido");
    printf("\nInforme o nome do produto: ");
    scanf(" %80[^\n]", compra->nome);
  }
  compra = (Compra*) malloc(sizeof(Compra));
  achou = 0;
  while((!achou) && (fread(compra, sizeof(Compra), 1, fp))) {
   if ((strcmp(compra->nome, procurado) == 0) && (compra->status == '1')) {
     achou = 1;
   }
  }
  fclose(fp);
  if (achou) {
    exibeCompra(compra);
  } else {
    printf("O produto %s não foi encontrado...\n", procurado);
  }
  free(compra);
}

void editaCompra(void) {
  FILE* fp;
  Compra* compra;
  int achou;
  char resp;
  char procurado[15];
  fp = fopen("compra.dat", "r+b");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  printf("= = = = = = = = = = = \n");
  printf("= = Editar compras = = \n");
  printf("= = = = = = = = = = = \n");
  printf("Informe o nome do produto a ser alterado: ");
  scanf(" %14[^\n]", procurado);
  while((validacaoPalavra(compra->nome)!= 1)) {
    printf("inválido");
    printf("\nInforme o nome do produto: ");
    scanf(" %80[^\n]", compra->nome);
  }
  compra = (Compra*) malloc(sizeof(Compra));
  achou = 0;
  while((!achou) && (fread(compra, sizeof(Compra), 1, fp))) {
   if ((strcmp(compra->nome, procurado) == 0) && (compra->status == '1')) {
     achou = 1;
   }
  }
  if (achou) {
    exibeCompra(compra);
    getchar();
    printf("Deseja realmente editar este produto (s/n)? ");
    scanf("%c", &resp);
    if (resp == 's' || resp == 'S') {
      printf("\nInforme o código do produto: ");
      scanf("%d", &compra->cod);
      while((validacaoEhNumero(compra->cod)!=1)) {
        printf("inválido");
        printf("\nInforme o código da empresa: ");
        scanf("%d", &compra->cod);
      }
      printf("Informe o nome do produto: ");
      scanf(" %14[^\n]", compra->nome);
      printf("Informe a marca do produto: ");
      scanf(" %14[^\n]", compra->marca);
      printf("Informe a quantidade disponivel do produto: ");
      scanf("%d", &compra->qntd);
      while((validacaoEhNumero(compra->qntd)!=1)) {
        printf("inválido");
        printf("\nInforme a quantidade do produto: ");
        scanf("%d", &compra->qntd);
      }
      getchar();
      compra->status = '1';
      fseek(fp, (-1)*sizeof(Compra), SEEK_CUR);
      fwrite(compra, sizeof(Compra), 1, fp);
      printf("\nProduto editado com sucesso!!!\n");
    } else {
      printf("\nOk, os dados não foram alterados\n");
    }
  } else {
    printf("O produto %s não foi encontrado...\n", procurado);
  }
  free(compra);
  fclose(fp);
}


void excluiCompra(void) {
  FILE* fp;
  Compra* compra;
  int achou;
  char resp;
  char procurado[15];
  fp = fopen("compra.dat", "r+b");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  printf("= = = = = = = =  = = = \n");
  printf("= = Apagar Compra = = \n");
  printf("= = = = = = = = =  = = \n");
  printf("Informe o nome do produto a ser apagado: ");
  scanf(" %14[^\n]", procurado);
  while((validacaoPalavra(compra->nome)!= 1)) {
    printf("inválido");
    printf("\nInforme o nome do produto: ");
    scanf(" %80[^\n]", compra->nome);
  }
  compra = (Compra*) malloc(sizeof(Compra));
  achou = 0;
  while((!achou) && (fread(compra, sizeof(Compra), 1, fp))) {
   if ((strcmp(compra->nome, procurado) == 0) && (compra->status == '1')) {
     achou = 1;
   }
  }
  if (achou) {
    exibeCompra(compra);
    getchar();
    printf("Deseja realmente apagar este produto (s/n)? ");
    scanf("%c", &resp);
    if (resp == 's' || resp == 'S') {
      compra->status = '0';
      fseek(fp, -1*sizeof(Compra), SEEK_CUR);
      fwrite(compra, sizeof(Compra), 1, fp);
      printf("\nProduto excluído com sucesso!!!\n");
     } else {
       printf("\nOk, os dados não foram alterados\n");
     }
  } else {
    printf("O produto %s não foi encontrado...\n", procurado);
  }
  fclose(fp);
  free(compra);
}


void listaCompra(void) {
  FILE* fp;
  Compra* compra;
  fp = fopen("compra.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  printf("= = = = = = = = = = = \n");
  printf("= = Exibe Compras = = \n");
  printf("= = = = = = = = = = = \n");
  compra = (Compra*) malloc(sizeof(Compra));
  while(fread(compra, sizeof(Compra), 1, fp)) {
    if (compra->status == '1') {
      exibeCompra(compra);
    }
  }
  fclose(fp);
  free(compra);
}


void gravaCompra(Compra* compra) {
  FILE* fp;
  fp = fopen("compra.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  fwrite(compra, sizeof(Compra), 1, fp);
  fclose(fp);
}


void exibeCompra(Compra* compra) {
  printf("Código: %d\n", compra->cod);
  printf("Nome: %s\n", compra->nome);
  printf("Marca: %s\n", compra->marca);
  printf("Quantidade: %d\n", compra->qntd);
  (dataEhora(compra));
  printf("\n");
}

void dataEhora(Compra* compra) {
  FILE* fp;
  fp = fopen("compra.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  struct tm *data_hora_atual;     
  
  time_t segundos;  
  time(&segundos);     
  data_hora_atual = localtime(&segundos);
  
  printf("\nHora de entrada: %d:",data_hora_atual->tm_hour-3);printf("%d:",data_hora_atual->tm_min);
  printf("%d\n",data_hora_atual->tm_sec);
  printf("\nData de entrada: %d/", data_hora_atual->tm_mday);
  printf("%d/",data_hora_atual->tm_mon+1);
  printf("%d\n\n",data_hora_atual->tm_year+1900);
  fclose(fp);
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
