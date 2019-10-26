#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vend Venda;

struct vend {
  int cod;
  char nome[20];
  char marca[20];
  char data[11];
  char status;
  int qntd;
};

int menuVenda(void);
void cadastraVenda(void);
void buscaVenda(void);
void editaVenda(void);
void excluiVenda(void);
void exibeVenda(Venda*);
void gravaVenda(Venda*);

int validacaoEhNumero(char);

int main(void) {
  int opcao;
  opcao = menuVenda();
  while (opcao != 0) {
    switch (opcao) {
      case 1 :  cadastraVenda();
                break;
      case 2 :  buscaVenda();
                break;
      case 3 :  editaVenda();
                break;
      case 4 :  excluiVenda();
                break;
    }
    opcao = menuVenda();
  }
  printf("\nFim do programa!\n\n");
  return 0;
}

int menuVenda(void) {
  int opcao;
  printf("\n\n");
  printf("= = = = = = = = = = = = = = = = = =  \n");
  printf("= = = =  Venda de Produtos  = = = = \n");
  printf("= = = = = = = = = = = = = = = = = =  \n");
  printf("\n1 - Cadastrar Venda\n");
  printf("2 - Pesquisar Venda\n");
  printf("3 - Alterar Venda\n");
  printf("4 - Excluir Venda\n");
  printf("0 - Retornar\n");
  printf("\nEscolha sua opção: ");
  scanf("%d", &opcao);
  system("cls || clear");
  return opcao;
}


void cadastraVenda(void) {
  Venda* venda;
  printf("\n\n");
  printf(" = = = = = = = = = =\n");
  printf(" =  Efetuar Venda  =\n");
  printf(" = = = = = = = = = =  \n");
  venda = (Venda*) malloc(sizeof(Venda));
  printf("\nCódigo do produto: ");
  scanf("%d", &venda->cod);
  printf("Nome do produto: ");
  scanf(" %19[^\n]", venda->nome);
  printf("Marca do produto: ");
  scanf(" %19[^\n]", venda->marca);
  printf("Quantidade de produtos: ");
  scanf("%d", &venda->qntd);
  printf("Data de saída do produto (dd/mm/aaaa): ");
  scanf(" %10[^\n]", venda->data);
  getchar();
  venda->status = '1';
  gravaVenda(venda);
}

void buscaVenda(void){
    FILE* fp;
    Venda* venda;
    int achou;
    char procurado[15];
    fp = fopen("venda.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    printf("= = = = = = = = = = = = = \n");
    printf("= = Pesquisar Venda = = \n");
    printf("= = = = = = = = = = = = =\n");
    printf("Informe o nome do produto vendido a ser buscado: ");
    scanf(" %14[^\n]", procurado);
    venda = (Venda*) malloc(sizeof(Venda));
    achou = 0;
    while((!achou) && (fread(venda, sizeof(Venda), 1, fp))) {
        if ((strcmp(venda->nome, procurado) == 0) && (venda->status == '1')) {
            achou = 1;
        }
    }
    fclose(fp);
    if (achou) {
        exibeVenda(venda);
    } else {
        printf("O venda %s não foi encontrado...\n", procurado);
    }
    free(venda);
}

void editaVenda(void) {
    FILE* fp;
    Venda* venda;
    int achou;
    char resp;
    char procurado[15];
    fp = fopen("venda.dat", "r+b");
    if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
    }
    printf("\n\n");
    printf("= = = = = = = = = = = =\n");
    printf("= = Editar Venda = =\n");
    printf("= = = = = = = = = = = =\n");
    printf("Informe o nome do produto vendido a ser alterado: ");
    scanf(" %14[^\n]", procurado);
    venda = (Venda*) malloc(sizeof(Venda));
    achou = 0;
    while((!achou) && (fread(venda, sizeof(Venda), 1, fp))) {
        if ((strcmp(venda->nome, procurado) == 0) && (venda->status == '1')) {
            achou = 1;
        }
    }
    if (achou) {
        exibeVenda(venda);
        getchar();
        printf("Deseja realmente editar este venda (s/n)? ");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S') {
            printf("\nInforme o código do produto que será vendido: ");
            scanf("%d", &venda->cod);
            printf("Informe o nome do produto: ");
            scanf(" %19[^\n]", venda->nome);
            printf("Informe a marca do produto: ");
            scanf(" %19[^\n]", venda->marca);
            printf("Informe a quantidade de produtos: ");
            scanf("%d", &venda->qntd);
            printf("Informe a data de saída do produto (dd/mm/aaaa): ");
            scanf(" %10[^\n]", venda->data);
            getchar();
            venda->status = '1';
            fseek(fp, (-1)*sizeof(Venda), SEEK_CUR);
            fwrite(venda, sizeof(Venda), 1, fp);
            printf("\nvenda editado com sucesso!!!\n");
        } else {
            printf("\nOk, os dados não foram alterados\n");
        }
    } else {
        printf("O venda %s não foi encontrado...\n", procurado);
  }
  free(venda);
  fclose(fp);
}

void excluiVenda(void) {
    FILE* fp;
    Venda* venda;
    int achou;
    char resp;
    char procurado[15];
    fp = fopen("venda.dat", "r+b");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    printf("= = = = = = = = = = = =\n");
    printf("= = Excluir Venda = = \n");
    printf("= = = = = = = = = = = =\n");
    printf("Informe o nome do produto vendido a ser apagado: ");
    scanf(" %14[^\n]", procurado);
    venda = (Venda*) malloc(sizeof(Venda));
    achou = 0;
    while((!achou) && (fread(venda, sizeof(Venda), 1, fp))) {
        if ((strcmp(venda->nome, procurado) == 0) && (venda->status == '1')) {
            achou = 1;
        }
    }
    if (achou) {
        exibeVenda(venda);
        getchar();
        printf("Deseja realmente apagar esta venda (s/n)? ");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S') {
            venda->status = '0';
            fseek(fp, -1*sizeof(Venda), SEEK_CUR);
            fwrite(venda, sizeof(Venda), 1, fp);
            printf("\nVenda excluído com sucesso!!!\n");
        } else {
            printf("\nOk, os dados não foram alterados\n");
        }
    } else {
        printf("O produto %s não foi encontrado...\n", procurado);
    }
    free(venda);
    fclose(fp);
}


void gravaVenda(Venda* venda) {
    FILE* fp;
    fp = fopen("venda.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    fwrite(venda, sizeof(Venda), 1, fp);
    fclose(fp);
}

void exibeVenda(Venda* venda) {
    printf("Código do produto: %d\n", venda->cod);
    printf("Nome do produto: %s\n", venda->nome);
    printf("Marca do produto: %s\n", venda->marca);
    printf("Quantidade: %d\n", venda->qntd);
    printf("Data de saída do produto: %s\n", venda->data
);
    printf("Status: %c\n", venda->status);
    printf("\n");
}
