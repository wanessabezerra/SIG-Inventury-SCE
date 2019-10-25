#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
//#include "funcoesDeValidacao"


typedef struct client Cliente;

struct client {
  char nomeCliente[20];
  char nascCliente[11];
  int cpfCliente;
  char emailCliente[20];
  char telefoneCliente[12];
  char statusCliente;
};

typedef struct produto Prod;

struct produto {
  int cod;
  char nome[15];
  char marca[15];
  int quant;
  char status;
};

int menuPrincipal(void);
int menuPrincipalCliente(void);
int menuCliente(void);
void cadastraCliente(void);
void buscaCliente(void);
void editaCliente(void);
void excluiCliente(void);
void exibeCliente(Cliente*);
void gravaCliente(Cliente*);

int menuPrincipalProduto(void);
int menuProduto(void);
void cadastraProduto(void);
void buscaProduto(void);
void editaProduto(void);
void excluiProduto(void);
void listaProduto(void);
void exibeProduto(Prod*);
void gravaProduto(Prod*);

int menuPrincipalRelatorio(void);
void listaClientes(void);

int ehLetra(char);


int main(void) {
    setlocale(LC_ALL, "portuguese");
    int opcao;
    opcao = menuPrincipal();
    while (opcao != 0) {
        switch (opcao) {
            case 1 :  menuPrincipalCliente();
                    break;
            case 2 :  menuPrincipalProduto();
                    break;
            case 5 :  menuPrincipalRelatorio();
                    break;
            case 0 : return 0;
                    break;
            default : printf("Opção inválida, digite um número válido\n\n");
                    break;
            
            //case 3 :  edita();
                    break;
            //case 4 :  excluiP(;
                    break;
          
            //case 6 :  sobre();
                    break;
    }
    opcao = menuPrincipal();
  }
  printf("\nFim do programa!\n\n");
  return 0;
}

int menuPrincipal(void) {
    int opcao;
    printf("\n\n");
    printf ("\t= = = = = = = = = = = = = = = = = =\n"
            "\t=   M E N U   P R I N C I P A L   =\n"
            "\t= = = = = = = = = = = = = = = = = =\n"
            "\n[1] - Cliente\n"
            "[2] - Produto\n"
            "[3] - Controle de Compras\n"
            "[4] - Controle de Vendas\n"
            "[5] - Relatórios\n"
            "[6] - Sobre o programa\n"
            "[0] - Encerrar programa\n");
    printf("\nEscolha sua opção: ");
    scanf("%d", &opcao);
    system("cls || clear");
    return opcao;
}

/////////////// cliente ///////////////
int menuPrincipalCliente(void){
    int opcao;
    opcao = menuCliente();
    while (opcao != 0) {
        switch (opcao) {
            case 1 :  cadastraCliente();
                    break;
            case 2 :  buscaCliente();
                    break;
            case 3 :  editaCliente();
                    break;
            case 4 :  excluiCliente();
                    break;
            case 0 : return 0;
                    break;
            default : printf("Opção inválida, digite um número válido\n\n");
                    break;

        }
    opcao = menuCliente();
    }
    return 0;
}



int menuCliente(void) {
    int opcao;
    printf("\n\n");
    printf ("= = = = = = = = = = = = \n"
            "=    C L I E N T E    =\n"
            "= = = = = = = = = = = = \n"
            "\n[1] - Cadastrar Cliente\n"
            "[2] - Pesquisar Cliente\n"
            "[3] - Atualizar Cliente\n"
            "[4] - Deletar Cliente\n"
            "[0] - Retornar\n");
    printf("\nEscolha sua opção: ");
    scanf("%d", &opcao);
    system("cls || clear");
    return opcao;
}


void cadastraCliente(void) {
    Cliente* cliente;
    printf("\n\n");
    printf("= = = = = = = = = = = = =\n");
    printf("= = Cadastrar Cliente = =\n");
    printf("= = = = = = = = = = = = =\n");
    cliente = (Cliente*) malloc(sizeof(Cliente));
    printf("Nome: ");
    scanf(" %19[^\n]", cliente->nomeCliente);
    printf("Data de nascimento (dd/mm/aaaa): ");
    scanf(" %10[^\n]", cliente->nascCliente);
    getchar();
    printf("CPF: ");
    scanf(" %d", &cliente->cpfCliente);
    printf("E-mail: ");
    scanf(" %19[^\n]", cliente->emailCliente);
    printf("Telefone: ");
    scanf(" %11[^\n]", cliente->telefoneCliente);
    cliente->statusCliente = '1';
    printf("###############################\n");
    exibeCliente(cliente);
    printf("###############################\n");
    gravaCliente(cliente);
}

void buscaCliente(void){
    FILE* fp;
    Cliente* cliente;
    int achou;
    char procurado[15];
    fp = fopen("cliente.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    printf("= = = = = = = = = = = = = \n");
    printf("= = Pesquisar Cliente = = \n");
    printf("= = = = = = = = = = = = =\n");
    printf("Informe o nome do cliente a ser buscado: ");
    scanf(" %14[^\n]", procurado);
    cliente = (Cliente*) malloc(sizeof(Cliente));
    achou = 0;
    while((!achou) && (fread(cliente, sizeof(Cliente), 1, fp))) {
        if ((strcmp(cliente->nomeCliente, procurado) == 0) && (cliente->statusCliente == '1')) {
            achou = 1;
        }
    }
    fclose(fp);
    if (achou) {
        exibeCliente(cliente);
    } else {
        printf("O cliente %s não foi encontrado...\n", procurado);
    }
    free(cliente);
}

void editaCliente(void) {
    FILE* fp;
    Cliente* cliente;
    int achou;
    char resp;
    char procurado[15];
    fp = fopen("cliente.dat", "r+b");
    if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
    }
    printf("\n\n");
    printf("= = = = = = = = = = = =\n");
    printf("= = Editar Cliente = =\n");
    printf("= = = = = = = = = = = =\n");
    printf("Informe o nome do cliente a ser alterado: ");
    scanf(" %14[^\n]", procurado);
    cliente = (Cliente*) malloc(sizeof(Cliente));
    achou = 0;
    while((!achou) && (fread(cliente, sizeof(Cliente), 1, fp))) {
        if ((strcmp(cliente->nomeCliente, procurado) == 0) && (cliente->statusCliente == '1')) {
            achou = 1;
        }
    }
    if (achou) {
        exibeCliente(cliente);
        getchar();
        printf("Deseja realmente editar este cliente (s/n)? ");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S') {
            printf("Nome: ");
            scanf(" %19[^\n]", cliente->nomeCliente);
            printf("Data de nascimento (dd/mm/aaaa): ");
            scanf(" %10[^\n]", cliente->nascCliente);
            getchar();
            printf("CPF: ");
            scanf(" %d", &cliente->cpfCliente);
            printf("E-mail: ");
            scanf(" %19[^\n]", cliente->emailCliente);
            printf("Telefone: ");
            scanf(" %11[^\n]", cliente->telefoneCliente);
            cliente->statusCliente = '1';
            fseek(fp, (-1)*sizeof(Cliente), SEEK_CUR);
            fwrite(cliente, sizeof(Cliente), 1, fp);
            printf("\ncliente editado com sucesso!!!\n");
        } else {
            printf("\nOk, os dados não foram alterados\n");
        }
    } else {
        printf("O cliente %s não foi encontrado...\n", procurado);
  }
  free(cliente);
  fclose(fp);
}

void excluiCliente(void) {
    FILE* fp;
    Cliente* cliente;
    int achou;
    char resp;
    char procurado[15];
    fp = fopen("cliente.dat", "r+b");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    printf("= = = = = = = = = = = =\n");
    printf("= = Excluir Cliente = = \n");
    printf("= = = = = = = = = = = =\n");
    printf("Informe o nome do cliente a ser apagado: ");
    scanf(" %14[^\n]", procurado);
    cliente = (Cliente*) malloc(sizeof(Cliente));
    achou = 0;
    while((!achou) && (fread(cliente, sizeof(Cliente), 1, fp))) {
        if ((strcmp(cliente->nomeCliente, procurado) == 0) && (cliente->statusCliente == '1')) {
            achou = 1;
        }
    }
    if (achou) {
        exibeCliente(cliente);
        getchar();
        printf("Deseja realmente apagar este cliente (s/n)? ");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S') {
            cliente->statusCliente = '0';
            fseek(fp, -1*sizeof(Cliente), SEEK_CUR);
            fwrite(cliente, sizeof(Cliente), 1, fp);
            printf("\nCliente excluído com sucesso!!!\n");
        } else {
            printf("\nOk, os dados não foram alterados\n");
        }
    } else {
        printf("O cliente %s não foi encontrado...\n", procurado);
    }
    free(cliente);
    fclose(fp);
}


void gravaCliente(Cliente* cliente) {
    FILE* fp;
    fp = fopen("cliente.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    fwrite(cliente, sizeof(Cliente), 1, fp);
    fclose(fp);
}

void exibeCliente(Cliente* cliente) {
    printf("Nome: %s\n", cliente->nomeCliente);
    printf("Nascimento: %s\n", cliente->nascCliente);
    printf("CPF: %d\n", cliente->cpfCliente);
    printf("E-mail: %s\n", cliente->emailCliente);
    printf("Telefone: %s\n", cliente->telefoneCliente);
    printf("Status: %c\n", cliente->statusCliente);
    printf("\n");
}
/////////////// menu produto ///////////////
int menuPrincipalProduto(void) {
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
  printf("3 - Atualizar produto\n");
  printf("4 - Deletar produto\n");
  printf("5 - Listar todos os produtos\n");
  printf("0 - Retornar\n");
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
  printf("Informe o nome do produto: ");
  scanf(" %14[^\n]", produto->nome);
  printf("Informe a marca do produto: ");
  scanf(" %14[^\n]", produto->marca);
  printf("Informe a quantidade do produto: ");
  scanf("%d", &produto->quant);
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
      printf("Informe o nome do produto: ");
      scanf(" %14[^\n]", produto->nome);
      printf("Informe a tipo do produto: ");
      scanf(" %14[^\n]", produto->marca);
      printf("Informe a quantidade disponivel do produto (dd/mm/aaaa): ");
      scanf("%d", &produto->quant);
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

/////////////// menu relatório /////////////////////
int menuPrincipalRelatorio(void){
    int opcao;
    opcao = menuCliente();
    while (opcao != 0) {
        switch (opcao) {
            case 1 :  listaClientes();
                    break;
            //case 2 :  buscaCliente();
                    break;
            //case 3 :  editaCliente();
                    break;
            //case 4 :  excluiCliente();
                    break;
            //case 0 : return 0;
                    break;
            default : printf("Opção inválida, digite um número válido\n\n");
                    break;

        }
    opcao = menuCliente();
    }
    return 0;
}

int menuRelatorio(void) {
    int opcao;
    printf("\n\n");
    printf ("\t= = = = = = = = = = = = =\n"
            "\t=  R E L A T Ó R I O S  =\n"
            "\t= = = = = = = = = = = = = = = = = =\n"
            "\n[1] - Listagem dos Cliente\n"
            "[2] - Produto\n"
            "[3] - Controle de Compras\n"
            "[4] - Controle de Vendas\n"
            "[5] - Relatórios\n"
            "[0] - Encerrar programa\n");
    printf("Escolha sua opção: ");
    scanf("%d", &opcao);
    system("cls || clear");
    return opcao;
}

void listaClientes(void) {
  FILE* fp;
  Cliente* cliente;
  fp = fopen("cliente.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  printf("= = = = = = = = = = = = = = =\n");
  printf("= = Listagem de Clientes = = \n");
  printf("= = = = = = = = = = = = = = =\n");
  cliente = (Cliente*) malloc(sizeof(Cliente));
  while(fread(cliente, sizeof(Cliente), 1, fp)) {
    if (cliente->statusCliente == '1') {
      exibeCliente(cliente);
    }
  }
  fclose(fp);
  free(cliente);
}
