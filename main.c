#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

typedef struct noClt NoCliente;

struct noClt {
  char nome[40];
  int nasc[3];
  char cpf[12]; 
  char email[40];
  char telefone[12];
  char status;
  NoCliente* prox;
}; 

typedef struct noProdut NoProd;

struct noProdut {
  char cod[6];
  char nome[40];
  char marca[40];
  char qntd[6];
  char preco[7];
  char status;
  NoProd* prox;
};


typedef struct noCompr NoCompra;

struct noCompr {
  char cod[6];
  char qntd[6];
  char status;
  NoCompra* prox;
};


typedef struct noVend NoVenda;

struct noVend {
  char cod[6];
  char cpf[12];
  char qntd[6];
  char status;
  NoVenda* prox;
};

int menuPrincipal(void);
int menuPrincipalCliente(void);
int menuCliente(void);
void cadastraCliente(void);
void buscaCliente(void);
void editaCliente(void);
void excluiCliente(void);
void gravaCliente(NoCliente*);


int menuPrincipalProduto(void);
int menuProduto(void);
void cadastraProduto(void);
void buscaProduto(void);
void editaProduto(void);
void excluiProduto(void);
void gravaProduto(NoProd*);


int menuPrincipalCompra(void);
int menuCompra(void);
void cadastraCompra(void);
void buscaCompra(void);
void editaCompra(void);
void excluiCompra(void);
void listaCompra(void);
void gravaCompra(NoCompra*);
void dataEhora1(NoCompra*);


int menuPrincipalVenda(void);
int menuVenda(void);
void cadastraVenda(void);
void buscaVenda(void);
void editaVenda(void);
void excluiVenda(void);
void gravaVenda(NoVenda*);
void dataEhora2(NoVenda*);


int menuPrincipalRelatorio(void);
int menuRelatorio(void);
NoCliente* listaOrdenadaCliente(void);
NoCliente* listaDiretaCliente(void);
NoProd* listaOrdenadaProduto(void);
NoCompra* listaInvertidaCompra(void);
NoVenda* listaInvertidaVenda(void);
void exibeCliente(NoCliente*);
void exibeProduto(NoProd*);
void exibeCompra(NoCompra*);
void exibeVenda(NoVenda*);
void exibeListaCliente();
void exibeListaProduto();
void exibeListaCompra();
void exibeListaVenda();


int menuPrincipalSobre(void);
int menuSobre(void);
void sobreOprograma(void);


int ehLetra(char);
int validacaoEhNumero(char);
int validacaoPalavra(char[]);
int validacaoCpf(char *);
int validacaoEmail( const char *);
int validacaoTelefone(char *);
int validacaoCod(char *);
int validacaoCod2(char *);
int validacaoPalavra1(char[]);
int validacaoEhLetra(char);
int bissexto(int);
int dataValida(int,int,int);
int validacaoCpf(char *);


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
            case 3 :  menuPrincipalCompra();
                    break;
            case 4 :  menuPrincipalVenda();
                    break;
            case 5 :  menuPrincipalRelatorio();
                    break;
            case 6 :  menuPrincipalSobre();
                    break;
            case 0 : return 0;
                    break;
            default : printf("Opção inválida, digite um número válido\n\n");
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
    printf ("= = = = = = = = = = = = = = = = = =\n"
            "=   M E N U   P R I N C I P A L   =\n"
            "= = = = = = = = = = = = = = = = = =\n"
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
  NoCliente* cliente;
  int dia, mes, ano;
  char resp;
  do{
    printf("\n\n");
    printf("= = = = = = = = = = = = =\n");
    printf("=   Cadastrar Cliente   =\n");
    printf("= = = = = = = = = = = = =\n");
    cliente = (NoCliente*) malloc(sizeof(NoCliente));

    printf("\nNome: ");
    scanf(" %39s", cliente->nome);
    while((validacaoPalavra(cliente->nome)!= 1)) {
      printf("\nNome inválido, tente novamente.\n");
      printf("Nome: ");
      scanf(" %39s", cliente->nome);
    }

    printf("Data de nascimento no formato(dd/mm/aaaa): ");
    scanf(" %d/%d/%d", &cliente->nasc[0], &cliente->nasc[1],&cliente->nasc[2]);
    getchar();
    while((dataValida(cliente->nasc[0], cliente->nasc[1],cliente->nasc[2]))!= 1){
              printf("Data inválida: %d/%d/%d, tente novamente. ", cliente->nasc[0], cliente->nasc[1],cliente->nasc[2]);
              printf("\nData: ");
              scanf("%d/%d/%d", &cliente->nasc[0], &cliente->nasc[1],&cliente->nasc[2]);
              getchar();
            }

    printf("CPF: ");
    scanf("%11s", cliente->cpf);
    while((validacaoCpf(cliente->cpf)!=1)) {
      printf("\nNúmero inválido, tente novamente.\n");
      printf("CPF: ");
      scanf("%11s", cliente->cpf);
    }

    printf("E-mail: ");
    scanf("%39s", cliente->email);
    while(!(validacaoEmail(cliente->email))) {
      printf("\nE-mail inválido, tente novamente.\n");
      printf("E-mail: ");
      scanf(" %39s", cliente->email);
    }
    
    printf("Telefone: ");
    scanf("%9s", cliente->telefone);
    getchar();
    while((validacaoTelefone(cliente->telefone)!=1)) {
      printf("\nTelefone inválido, tente novamente.\n");
      printf("Telefone: ");
      scanf("%9s", cliente->telefone);
    }

    cliente->status = '1';
    gravaCliente(cliente);
    printf("\nDeseja cadastrar outro cliente (s/n)? ");
    scanf("%c", &resp);
    system("cls || clear");

  }while(resp == 's' || resp == 'S');
  getchar();
}

void buscaCliente(void){
    FILE* fp;
    NoCliente* cliente;
    int achou;
    char procurado[12];
    fp = fopen("cliente.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    printf("= = = = = = = = = = = = = \n");
    printf("=   Pesquisar Cliente   = \n");
    printf("= = = = = = = = = = = = =\n");
    printf("\nCPF: ");
    scanf("%11s", procurado);
    while((validacaoCpf(procurado)!=1)) {
      printf("\nNúmero inválido, tente novamente.\n");
      printf("CPF: ");
      scanf("%11s", procurado);
    }
    
    cliente = (NoCliente*) malloc(sizeof(NoCliente));
    achou = 0;
    while((!achou) && (fread(cliente, sizeof(NoCliente), 1, fp))) {
        if ((strcmp(cliente->cpf, procurado) == 0) && (cliente->status == '1')) {
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
    NoCliente* cliente;
    int achou;
    char resp;
    char procurado[12];
    do{
      fp = fopen("cliente.dat", "r+b");
      if (fp == NULL) {
      printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
      printf("Não é possível continuar o programa...\n");
      exit(1);
      }
      printf("\n\n");
      printf("= = = = = = = = = = = =\n");
      printf("=   Editar Cliente    =\n");
      printf("= = = = = = = = = = = =\n");
      printf("\nCPF do cliente: ");
      scanf("%11s", procurado);
      while((validacaoCpf(procurado)!=1)) {
        printf("\nNúmero inválido, tente novamente.\n");
        printf("CPF: ");
        scanf("%11s", procurado);
      }
      cliente = (NoCliente*) malloc(sizeof(NoCliente));
      achou = 0;
      while((!achou) && (fread(cliente, sizeof(NoCliente), 1, fp))) {
          if ((strcmp(cliente->nome, procurado) == 0) && (cliente->status == '1')) {
              achou = 1;
          }
      }
      if (achou) {
          exibeCliente(cliente);
          getchar();
          printf("\nDeseja realmente editar este cliente (s/n)? ");
          scanf("%c", &resp);
          if (resp == 's' || resp == 'S') {
              printf("\nNome: ");
              scanf(" %39s", cliente->nome);
              while((validacaoPalavra(cliente->nome)!= 1)) {
                printf("\nNome inválido, tente novamente.\n");
                printf("Nome: ");
                scanf(" %39s", cliente->nome);
              }

              printf("Data de nascimento no formato(dd/mm/aaaa): ");
              scanf("%d/%d/%d", &cliente->nasc[0], &cliente->nasc[1],&cliente->nasc[2]);
              getchar();
              
              while((dataValida(cliente->nasc[0], cliente->nasc[1],cliente->nasc[2]))!= 0){
                printf("Data inválida: %d/%d/%d, tente novamente. ", cliente->nasc[0], cliente->nasc[1],cliente->nasc[2]);
                printf("\nData: ");
                scanf("%d/%d/%d", &cliente->nasc[0], &cliente->nasc[1],&cliente->nasc[2]);
                getchar();
              }

              printf("CPF: ");
              scanf("%11s", cliente->cpf);
              while((validacaoCpf(cliente->cpf)!=1)) {
                printf("\nNúmero inválido, tente novamente.\n");
                printf("CPF: ");
                scanf("%11s", cliente->cpf);
              }

              printf("E-mail: ");
              scanf(" %39s", cliente->email);
              while(!(validacaoEmail(cliente->email))) {
                printf("\nE-mail inválido, tente novamente.\n");
                printf("E-mail: ");
                scanf(" %39s", cliente->email);
              }
              
              printf("Telefone: ");
              scanf("%9s", cliente->telefone);
              getchar();
              while((validacaoTelefone(cliente->telefone)!=1)) {
                printf("\nTelefone inválido, tente novamente.\n");
                printf("Telefone: ");
                scanf("%9s", cliente->telefone);
              }

              cliente->status = '1';
              fseek(fp, (-1)*sizeof(NoCliente), SEEK_CUR);
              fwrite(cliente, sizeof(NoCliente), 1, fp);
              printf("\ncliente editado com sucesso!!!\n");
          } else {
              printf("\nOk, os dados não foram alterados\n");
          }
      } else {
          printf("O cliente %s não foi encontrado...\n", procurado);
    }
    free(cliente);
    fclose(fp);
    printf("\nDeseja editar o cadastro de outro cliente (s/n)? ");
    scanf("%c", &resp);


  }while(resp == 's' || resp == 'S');
  getchar();
}

void excluiCliente(void) {
  FILE* fp;
  NoCliente* cliente;
  int achou;
  char resp;
  char procurado[15];
  do{
    fp = fopen("cliente.dat", "r+b");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    printf("= = = = = = = = = = = =\n");
    printf("=   Excluir Cliente   = \n");
    printf("= = = = = = = = = = = =\n");
    printf("\nCPF: ");
      scanf("%11s", procurado);
      while((validacaoCpf(procurado)!=1)) {
        printf("\nNúmero inválido, tente novamente.\n");
        printf("CPF: ");
        scanf("%11s", procurado);
      }
    cliente = (NoCliente*) malloc(sizeof(NoCliente));
    achou = 0;
    while((!achou) && (fread(cliente, sizeof(NoCliente), 1, fp))) {
        if ((strcmp(cliente->cpf, procurado) == 0) && (cliente->status == '1')) {
            achou = 1;
        }
    }
    if (achou) {
        exibeCliente(cliente);
        getchar();
        printf("\nDeseja realmente apagar este cliente (s/n)? ");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S') {
            cliente->status = '0';
            fseek(fp, -1*sizeof(NoCliente), SEEK_CUR);
            fwrite(cliente, sizeof(NoCliente), 1, fp);
            printf("\nCliente excluído com sucesso!!!\n");
        } else {
            printf("\nOk, os dados não foram alterados\n");
        }
    } else {
        printf("O cliente %s não foi encontrado...\n", procurado);
    }
    free(cliente);
    fclose(fp);
    printf("\nDeseja apagar o cadastrar de outro cliente (s/n)? ");
    scanf("%c", &resp);
    system("cls || clear");

  }while(resp == 's' || resp == 'S');
  getchar();
}


void gravaCliente(NoCliente* cliente) {
    FILE* fp;
    fp = fopen("cliente.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    fwrite(cliente, sizeof(NoCliente), 1, fp);
    fclose(fp);
}

void exibeCliente(NoCliente* cliente) {
    printf("Nome: %s\n", cliente->nome);
    printf("Nascimento: %d/%d/%d\n",cliente->nasc[0], cliente->nasc[1],cliente->nasc[2]);
    printf("CPF: %s\n", cliente->cpf);
    printf("E-mail: %s\n", cliente->email);
    printf("Telefone: %s\n", cliente->telefone);
    printf("Status: %c\n", cliente->status);
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
      case 0 : return 0;
                break;
      default : printf("Opção inválida, digite um número válido\n\n");
                break;
}
    opcao = menuProduto();
  }
  return 0;
}

int menuProduto(void) {
  int op;
  printf("\n\n");
  printf("= = = = = = = = = = = \n");
  printf("=   P R O D U T O   = \n");
  printf("= = = = = = = = = = = \n");
  printf("\n[1] - Cadastrar produto\n");
  printf("[2] - Pesquisar produto\n");
  printf("[3] - Atualizar produto\n");
  printf("[4] - Deletar produto\n");
  printf("[0] - Retornar\n");
  printf("\nEscolha sua opção: ");
  scanf("%d", &op);
  system("cls || clear");
  return op;
}


void cadastraProduto(void) {
  NoProd* produto;
  char resp;
  do{
    printf("\n\n");
    printf("= = = = = = = = = = = = \n");
    printf("=  Cadastrar Produto  = \n");
    printf("= = = = = = = = = = = =\n");
    
    produto = (NoProd*) malloc(sizeof(NoProd));

    printf("\nCódigo do produto: ");
    scanf("%5s", produto->cod);
    while((validacaoCod(produto->cod)!=1)) {
      printf("\nCódigo inválido, tente novamente com cinco dígitos ou o código já está cadastrado.\n");
      printf("Código do produto: ");
      scanf("%5s", produto->cod);
    }

    printf("Nome do produto: ");
    scanf(" %39s", produto->nome);
    while((validacaoPalavra(produto->nome)!= 1)) {
      printf("\nNome inválido, tente novamente.\n");
      printf("Nome do produto: ");
      scanf("%39s", produto->nome);
    }

    printf("Marca do produto: ");
    scanf(" %29s", produto->marca);
    while((validacaoPalavra1(produto->marca)!= 1)) {
      printf("\nMarca inválida, tente novamente.\n");
      printf("Marca do produto: ");
      scanf(" %29s", produto->marca);
    }

    printf("Preço do produto: ");
    scanf("%6s", produto->preco);
    getchar();
    while((validacaoEhNumero(*produto->preco)!=1)) {
      printf("\nPreço inválido, tente novamente.\n");
      printf("Preço do produto: ");
      scanf("%6s", produto->preco);
      getchar();
    }

    printf("Quantidade do produto: ");
    scanf("%5s", produto->qntd);
    getchar();
    while((validacaoEhNumero(*produto->qntd)!=1)) {
      printf("\nQuantidade inválida, tente novamente.\n");
      printf("Quantidade do produto: ");
      scanf("%5s", produto->qntd);
      getchar();
    }

    produto->status = '1';
    gravaProduto(produto);
    printf("\nDeseja cadastrar outro produto (s/n)? ");
    scanf("%c", &resp);
    system("cls || clear");

  }while(resp == 's' || resp == 'S');
  getchar();
}

void buscaProduto(void) {
  FILE* fp;
  NoProd* produto;
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
  printf("=    Buscar Produto   = \n");
  printf("= = = = = = = = = = = = \n");
  printf("\nInforme o código do produto a ser buscado:\n");
    scanf("%5s", procurado);
    while((validacaoCod(procurado)!=1)) {
      printf("\nCódigo inválido, tente novamente com 5 dígitos ou o código já foi cadastrado.\n");
      printf("Código do produto: ");
      scanf("%5s", procurado);
    }
  produto = (NoProd*) malloc(sizeof(NoProd));
  achou = 0;
  while((!achou) && (fread(produto, sizeof(NoProd), 1, fp))) {
   if ((strcmp(produto->cod, procurado) == 0) && (produto->status == '1')) {
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
  printf("Aperte a tecla ENTER para continuar. ");
  getchar();
  
}


void editaProduto(void) {
  FILE* fp;
  NoProd* produto;
  int achou;
  char resp;
  char procurado[6];
  do{
    fp = fopen("produto.dat", "r+b");
    if (fp == NULL) {
      printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
      printf("Não é possível continuar o programa...\n");
      exit(1);
    }
    printf("\n\n");
    printf("= = = = = = = = = = = \n");
    printf("=  Editar produto   = \n");
    printf("= = = = = = = = = = = \n");
    printf("\nInforme o código do produto a ser editado:\n");
      scanf("%5s", procurado);
      while((validacaoCod(procurado)!=1)) {
        printf("\nCódigo inválido, tente novamente com 5 dígitos ou o código já está cadastrado.\n");
        printf("Código do produto: ");
        scanf("%5s", procurado);
      }
    produto = (NoProd*) malloc(sizeof(NoProd));
    achou = 0;
    while((!achou) && (fread(produto, sizeof(NoProd), 1, fp))) {
    if ((strcmp(produto->cod, procurado) == 0) && (produto->status == '1')) {
      achou = 1;
    }
    }
    if (achou) {
      exibeProduto(produto);
      getchar();
      printf("\nDeseja realmente editar este produto (s/n)? ");
      scanf("%c", &resp);
      if (resp == 's' || resp == 'S') {
        printf("\nCódigo do produto: ");
        scanf("%5s", produto->cod);
        while((validacaoCod(produto->cod)!=1)) {
          printf("\nCódigo inválido, tente novamente com cinco dígitos ou o código já está cadastrado.\n");
          printf("Código do produto: ");
          scanf("%5s", produto->cod);
        }

        printf("Nome do produto: ");
        scanf(" %39s", produto->nome);
        while((validacaoPalavra(produto->nome)!= 1)) {
          printf("\nNome inválido, tente novamente.\n");
          printf("Nome do produto: ");
          scanf("%39s", produto->nome);
        }

        printf("Marca do produto: ");
        scanf(" %29s", produto->marca);
        while((validacaoPalavra1(produto->marca)!= 1)) {
          printf("\nMarca inválida, tente novamente.\n");
          printf("Marca do produto: ");
          scanf(" %29s", produto->marca);
        }

        printf("Preço do produto: ");
        scanf("%6s", produto->preco);
        getchar();
        while((validacaoEhNumero(*produto->preco)!=1)) {
          printf("\nPreço inválido, tente novamente.\n");
          printf("Preço do produto: ");
          scanf("%6s", produto->preco);
          getchar();
        }

        printf("Quantidade do produto: ");
        scanf("%5s", produto->qntd);
        getchar();
        while((validacaoEhNumero(*produto->qntd)!=1)) {
          printf("\nQuantidade inválida, tente novamente.\n");
          printf("Quantidade do produto: ");
          scanf("%5s", produto->qntd);
          getchar();
        }
        produto->status = '1';
        fseek(fp, (-1)*sizeof(NoProd), SEEK_CUR);
        fwrite(produto, sizeof(NoProd), 1, fp);
        printf("\nProduto editado com sucesso!!!\n");
      } else {
        printf("\nOk, os dados não foram alterados\n");
      }
    } else {
      printf("O produto %s não foi encontrado...\n", procurado);
    }
    free(produto);
    fclose(fp);
    printf("\nDeseja editar o cadastro de outro produto (s/n)? ");
    scanf("%c", &resp);
    system("cls || clear");

  }while(resp == 's' || resp == 'S');
  getchar();
}


void excluiProduto(void) {
  FILE* fp;
  NoProd* produto;
  int achou;
  char resp;
  char procurado[6];
  do{
    fp = fopen("produto.dat", "r+b");
    if (fp == NULL) {
      printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
      printf("Não é possível continuar o programa...\n");
      exit(1);
    }
    printf("\n\n");
    printf("= = = = = = = = = = = \n");
    printf("=   Apagar Produto  = \n");
    printf("= = = = = = = = = = = \n");
    printf("\nInforme o código do produto a ser apagado: ");
    scanf("%5s", procurado);
    while((validacaoCod(procurado)!=1)) {
      printf("\nCódigo inválido, tente novamente com cinco dígitos ou o código já está cadastrado.\n");
      printf("Código do produto: ");
      scanf("%5s", procurado);
    }
    produto = (NoProd*) malloc(sizeof(NoProd));
    achou = 0;
    while((!achou) && (fread(produto, sizeof(NoProd), 1, fp))) {
    if ((strcmp(produto->cod, procurado) == 0) && (produto->status == '1')) {
      achou = 1;
    }
    }
    if (achou) {
      exibeProduto(produto);
      getchar();
      printf("\nDeseja realmente apagar este produto (s/n)? ");
      scanf("%c", &resp);
      if (resp == 's' || resp == 'S') {
        produto->status = '0';
        fseek(fp, -1*sizeof(NoProd), SEEK_CUR);
        fwrite(produto, sizeof(NoProd), 1, fp);
        printf("\nProduto excluído com sucesso!!!\n");
      } else {
        printf("\nOk, os dados não foram alterados\n");
      }
    } else {
      printf("O produto %s não foi encontrado...\n", procurado);
    }
    free(produto);
    fclose(fp);
    printf("\nDeseja excluir outro produto (s/n)? ");
    scanf("%c", &resp);
    system("cls || clear");

  }while(resp == 's' || resp == 'S');
  getchar();
}


void gravaProduto(NoProd* produto) {
  FILE* fp;
  fp = fopen("produto.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  fwrite(produto, sizeof(NoProd), 1, fp);
  fclose(fp);
}


void exibeProduto(NoProd* produto) {
  printf("\nCódigo: %s\n", produto->cod);
  printf("Nome: %s\n", produto->nome);
  printf("Marca: %s\n", produto->marca);
  printf("Preço: R$%s\n ", produto->preco);
  printf("Quantidade: %s\n", produto->qntd);
  printf("\n");
}

/////////////// menu compra /////////////////////

int menuPrincipalCompra(void){
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
        case 0 : return 0;
                  break;
        default : printf("Opção inválida, digite um número válido\n\n");
                  break;
      }
      opcao = menuCompra();
    }
    return 0;
}

int menuCompra(void) {
  int op;
  printf("\n\n");
  printf("= = = = = = = = = = = = = = = = = = = = = =\n");
  printf("=   C O N T R O L E  D E  C O M P R A S   =\n");
  printf("= = = = = = = = = = = = = = = = = = = = = =\n");
  printf("\n[1] - Cadastrar Compras\n");
  printf("[2] - Pesquisar Compras\n");
  printf("[3] - Atualizar Compras\n");
  printf("[4] - Deletar Compras\n");
  printf("[0] - Retornar\n");
  printf("\nEscolha sua opção: ");
  scanf("%d", &op);
  system("cls || clear");
  return op;
}

void cadastraCompra(void) {
  NoCompra* compra;
    printf("\n\n");
    printf(" = = = = = = = = = = = =\n");
    printf(" =   Cadastrar Compra  =\n");
    printf(" = = = = = = = = = = = =\n");

    compra = (NoCompra*) malloc(sizeof(NoCompra));

    printf("\nCódigo do produto: ");
    scanf("%5s", compra->cod);
    while((validacaoCod(compra->cod)!=1)) {
      printf("\nCódigo inválido, somente 5 dígitos, tente novamente.\n");
      printf("Código do produto: ");
      scanf("%5s", compra->cod);
    }

    printf("Quantidade do produto: ");
    scanf("%5s", compra->qntd);
    getchar();
    while((validacaoEhNumero(*compra->qntd)!=1)) {
      printf("\nQuantidade inválida, tente novamente.\n");
      printf("Quantidade do produto: ");
      scanf("%5s", compra->qntd);
      getchar();
    }

    (dataEhora1(compra));
    compra->status = '1';
    gravaCompra(compra);
    printf("Aperte a tecla ENTER para continuar. ");
    getchar();
    system("cls || clear");
}


void buscaCompra(void) {
  FILE* fp;
  NoCompra* compra;
  int achou;
  char procurado[6];
  fp = fopen("compra.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  printf("= = = = = = = = = = = \n");
  printf("=   Buscar Compras  = \n");
  printf("= = = = = = = = = = = \n");
  printf("\nInforme o código do produto a ser buscado: ");
  scanf("%5s", procurado);
  while((validacaoCod(procurado)!=1)) {
    printf("\nCódigo inválido, somente 5 dígitos, tente novamente.\n");
    printf("Código do produto: ");
    scanf("%5s", procurado);
  }
  compra = (NoCompra*) malloc(sizeof(NoCompra));
  achou = 0;
  while((!achou) && (fread(compra, sizeof(NoCompra), 1, fp))) {
   if ((strcmp(compra->cod, procurado) == 0) && (compra->status == '1')) {
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
  printf("Aperte a tecla ENTER para continuar. ");
  getchar();
  system("cls || clear");
}

void editaCompra(void) {
  FILE* fp;
  NoCompra* compra;
  int achou;
  char resp;
  char procurado[6];
  do{
    fp = fopen("compra.dat", "r+b");
    if (fp == NULL) {
      printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
      printf("Não é possível continuar o programa...\n");
      exit(1);
    }
    printf("\n\n");
    printf("= = = = = = = = = = = \n");
    printf("=   Editar compras  = \n");
    printf("= = = = = = = = = = = \n");
    printf("\nInforme o código do produto a ser alterado: ");
    scanf("%5s", procurado);
    while((validacaoCod(procurado)!=1)) {
      printf("\nCódigo inválido, somente 5 dígitos, tente novamente.\n");
      printf("Código do produto: ");
      scanf("%5s", procurado);
    }
    compra = (NoCompra*) malloc(sizeof(NoCompra));
    achou = 0;
    while((!achou) && (fread(compra, sizeof(NoCompra), 1, fp))) {
    if ((strcmp(compra->cod, procurado) == 0) && (compra->status == '1')) {
      achou = 1;
    }
    }
    if (achou) {
      exibeCompra(compra);
      getchar();
      printf("\nDeseja realmente editar este produto (s/n)? ");
      scanf("%c", &resp);
      if (resp == 's' || resp == 'S') {

        printf("\nCódigo do produto: ");
        scanf("%5s", compra->cod);
        while((validacaoCod(compra->cod)!=1)) {
          printf("\nCódigo inválido, somente 5 dígitos, tente novamente.\n");
          printf("Código do produto: ");
          scanf("%5s", compra->cod);
        }

        printf("Quantidade do produto: ");
        scanf("%5s", compra->qntd);
        getchar();
        while((validacaoEhNumero(*compra->qntd)!=1)) {
          printf("\nQuantidade inválida, tente novamente.\n");
          printf("\nQuantidade do produto: ");
          scanf("%5s", compra->qntd);
          getchar();
        }
        (dataEhora1(compra));
        compra->status = '1';
        printf("Aperte a tecla ENTER para continuar. ");
        getchar();
        fseek(fp, (-1)*sizeof(NoCompra), SEEK_CUR);
        fwrite(compra, sizeof(NoCompra), 1, fp);
        printf("\nProduto editado com sucesso!!!\n");

      } else {
        printf("\nOk, os dados não foram alterados\n");
      }
    } else {
      printf("O produto %s não foi encontrado...\n", procurado);
    }
    free(compra);
    fclose(fp);
    printf("\nDeseja editar outra compra (s/n)? ");
    scanf("%c", &resp);
    system("cls || clear");

  }while(resp == 's' || resp == 'S');
  getchar();
}


void excluiCompra(void) {
  FILE* fp;
  NoCompra* compra;
  int achou;
  char resp;
  char procurado[6];
  do{
    fp = fopen("compra.dat", "r+b");
    if (fp == NULL) {
      printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
      printf("Não é possível continuar o programa...\n");
      exit(1);
    }
    printf("\n\n");
    printf("= = = = = = = = = = = \n");
    printf("=   Apagar Compra   = \n");
    printf("= = = = = = = = = = = \n");
    printf("\nInforme o código do produto a ser apagado: ");
    scanf("%5s", procurado);
    while((validacaoCod(procurado)!=1)) {
      printf("\nCódigo inválido, somente 5 dígitos, tente novamente.\n");
      printf("Código do produto: ");
      scanf("%5s", procurado);
    }
    compra = (NoCompra*) malloc(sizeof(NoCompra));
    achou = 0;
    while((!achou) && (fread(compra, sizeof(NoCompra), 1, fp))) {
    if ((strcmp(compra->cod, procurado) == 0) && (compra->status == '1')) {
      achou = 1;
    }
    }
    if (achou) {
      exibeCompra(compra);
      getchar();
      printf("\nDeseja realmente apagar este produto (s/n)? ");
      scanf("%c", &resp);
      if (resp == 's' || resp == 'S') {
        compra->status = '0';
        fseek(fp, -1*sizeof(NoCompra), SEEK_CUR);
        fwrite(compra, sizeof(NoCompra), 1, fp);
        printf("\nProduto excluído com sucesso!!!\n");
      } else {
        printf("\nOk, os dados não foram alterados\n");
      }
    } else {
      printf("O produto %s não foi encontrado...\n", procurado);
    }
    fclose(fp);
    free(compra);
    printf("\nDeseja apagar outra compra (s/n)? ");
    scanf("%c", &resp);
    system("cls || clear");

  }while(resp == 's' || resp == 'S');
  getchar();
}

void gravaCompra(NoCompra* compra) {
  FILE* fp;
  fp = fopen("compra.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  fwrite(compra, sizeof(NoCompra), 1, fp);
  fclose(fp);
}


void exibeCompra(NoCompra* compra) {
  printf("Código do Produto: %s\n", compra->cod);
  printf("Quantidade: %s\n", compra->qntd);
  (dataEhora1(compra));
  printf("\n");
}



/////////////// menu venda /////////////////////

int menuPrincipalVenda(void){
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
        case 0 : return 0;
                  break;
        default : printf("Opção inválida, digite um número válido\n\n");
                  break;
      }
      opcao = menuVenda();
    }
    return 0;
}

int menuVenda(void) {
  int opcao;
  printf("\n\n");
  printf("= = = = = = = = = = = = = = = = = = = = =  \n");
  printf("=   C O N T R O L E  D E  V E N D A S   = \n");
  printf("= = = = = = = = = = = = = = = = = = = = =  \n");
  printf("\n[1] - Cadastrar Venda\n");
  printf("[2] - Pesquisar Venda\n");
  printf("[3] - Alterar Venda\n");
  printf("[4] - Excluir Venda\n");
  printf("[0] - Retornar\n");
  printf("\nEscolha sua opção: ");
  scanf("%d", &opcao);
  system("cls || clear");
  return opcao;
}


void cadastraVenda(void) {
  NoVenda* venda;
  printf("\n\n");
  printf(" = = = = = = = = = =\n");
  printf(" =  Efetuar Venda  =\n");
  printf(" = = = = = = = = = =  \n");
  venda = (NoVenda*) malloc(sizeof(NoVenda));

  printf("\nCódigo do produto: ");
  scanf("%5s", venda->cod);
  while((validacaoCod(venda->cod)!=1)) {
    printf("\nCódigo inválido, tente novamente com 5 dígitos ou o código já está cadastrado.\n");
    printf("Código do produto: ");
    scanf("%5s", venda->cod);
  }

  printf("Quantidade do produto: ");
  scanf("%5s", venda->qntd);
  getchar();
  while((validacaoEhNumero(*venda->qntd)!=1)) {
    printf("\nQuantidade inválida, tente novamente.\n");
    printf("\nQuantidade do produto: ");
    scanf("%5s", venda->qntd);
    getchar();
  }

  (dataEhora2(venda));
  venda->status = '1';
  gravaVenda(venda);
  printf("Aperte a tecla ENTER para continuar. ");
  getchar();
  system("cls || clear");
}

void buscaVenda(void){
    FILE* fp;
    NoVenda* venda;
    int achou;
    char procurado[6];
    fp = fopen("venda.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    printf("= = = = = = = = = = = =  \n");
    printf("=   Pesquisar Venda   = \n");
    printf("= = = = = = = = = = = = \n");

    printf("\nInforme o código do produto a ser buscado: ");
    scanf("%5s", venda->cod);
    while((validacaoCod(venda->cod)!=1)) {
      printf("\nCódigo inválido, tente novamente com cinco dígitos.\n");
      printf("Código do produto: ");
      scanf("%5s", venda->cod);
    }

    venda = (NoVenda*) malloc(sizeof(NoVenda));
    achou = 0;
    while((!achou) && (fread(venda, sizeof(NoVenda), 1, fp))) {
        if ((strcmp(venda->cod, procurado) == 0) && (venda->status == '1')) {
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
    printf("Aperte a tecla ENTER para continuar. ");
    getchar();
    system("cls || clear");
}

void editaVenda(void) {
  FILE* fp;
  NoVenda* venda;
  int achou;
  char resp;
  char procurado[6];
  do{
    fp = fopen("venda.dat", "r+b");
    if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
    }
    printf("\n\n");
    printf("= = = = = = = = = = = \n");
    printf("=   Editar Venda    =\n");
    printf("= = = = = = = = = = =\n");
    printf("\nInforme o código do produto vendido a ser alterado: ");
    scanf("%5s", procurado);
    while((validacaoCod(procurado)!=1)) {
      printf("\nCódigo inválido, tente novamente com 5 dígitos.\n");
      printf("Código do produto: ");
      scanf("%5s", procurado);
    }
    venda = (NoVenda*) malloc(sizeof(NoVenda));
    achou = 0;
    while((!achou) && (fread(venda, sizeof(NoVenda), 1, fp))) {
        if ((strcmp(venda->cod, procurado) == 0) && (venda->status == '1')) {
            achou = 1;
        }
    }
    if (achou) {
        exibeVenda(venda);
        getchar();
        printf("\nDeseja realmente editar este venda (s/n)? ");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S') {
            printf("\nCódigo do produto: ");
            scanf("%5s", venda->cod);
            while((validacaoCod(venda->cod)!=1)) {
              printf("\nCódigo inválido, tente novamente.\n");
              printf("Código do produto: ");
              scanf("%5s", venda->cod);
            }

            printf("Quantidade do produto: ");
            scanf("%3s", venda->qntd);
            getchar();
            while((validacaoEhNumero(*venda->qntd)!=1)) {
              printf("\nQuantidade inválida, tente novamente.\n");
              printf("\nQuantidade do produto: ");
              scanf("%3s", venda->qntd);
              getchar();
            }
            
            (dataEhora2(venda));
            venda->status = '1';
            fseek(fp, (-1)*sizeof(NoVenda), SEEK_CUR);
            fwrite(venda, sizeof(NoVenda), 1, fp);
            printf("\nvenda editado com sucesso!!!\n");
        } else {
            printf("\nOk, os dados não foram alterados\n");
        }
    } else {
        printf("O venda %s não foi encontrado...\n", procurado);
    }
    free(venda);
    fclose(fp);
    printf("\nDeseja editar outra venda (s/n)? ");
    scanf("%c", &resp);
    system("cls || clear");

  }while(resp == 's' || resp == 'S');
  getchar();
}

void excluiVenda(void) {
  FILE* fp;
  NoVenda* venda;
  int achou;
  char resp;
  char procurado[6];
  do{
    fp = fopen("venda.dat", "r+b");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n\n");
    printf("= = = = = = = = = = = \n");
    printf("=   Excluir Venda   = \n");
    printf("= = = = = = = = = = = \n");
  
    printf("\nInforme o código do produto vendido a ser apagado: ");
    scanf("%5s", procurado);
    while((validacaoCod(procurado)!=1)) {
      printf("\nCódigo inválido, tente novamente com 5 dígitos ou o código já está cadastrado.\n");
      printf("Código do produto: ");
      scanf("%5s", procurado);
    }
    venda = (NoVenda*) malloc(sizeof(NoVenda));
    achou = 0;
    while((!achou) && (fread(venda, sizeof(NoVenda), 1, fp))) {
        if ((strcmp(venda->cod, procurado) == 0) && (venda->status == '1')) {
            achou = 1;
        }
    }
    if (achou) {
        exibeVenda(venda);
        getchar();
        printf("\nDeseja realmente apagar esta venda (s/n)? ");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S') {
            venda->status = '0';
            fseek(fp, -1*sizeof(NoVenda), SEEK_CUR);
            fwrite(venda, sizeof(NoVenda), 1, fp);
            printf("\nVenda excluído com sucesso!!!\n");
        } else {
            printf("\nOk, os dados não foram alterados\n");
        }
    } else {
        printf("O produto %s não foi encontrado...\n", procurado);
    }
    free(venda);
    fclose(fp);
    printf("\nDeseja apagar o cadastro de outra venda (s/n)? ");
    scanf("%c", &resp);
    system("cls || clear");

  }while(resp == 's' || resp == 'S');
  getchar();
}



void gravaVenda(NoVenda* venda) {
    FILE* fp;
    fp = fopen("venda.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    fwrite(venda, sizeof(NoVenda), 1, fp);
    fclose(fp);
}

void exibeVenda(NoVenda* venda) {
    printf("Código do produto: %s\n", venda->cod);
    printf("Quantidade: %s\n", venda->qntd);
    printf("Status: %c\n", venda->status);
    (dataEhora2(venda));
    printf("\n");
}

/////////////// menu relatório /////////////////////

int menuPrincipalRelatorio(void){
    int opcao;
    NoCliente* lista;
    NoProd* lista1;
    NoCompra* lista2;
    NoVenda* lista3;
    opcao = menuRelatorio();
    while (opcao != 0) {
        switch (opcao) {
            case 1 :  lista = listaOrdenadaCliente();
                      exibeListaCliente(lista);
                      break;
            case 2 :  lista = listaDiretaCliente();
                      exibeListaCliente(lista);
                      break;
            case 3 :  lista1 = listaOrdenadaProduto();
                      exibeListaProduto(lista1);
                      break;
            case 4 :  lista2 = listaInvertidaCompra();
                      exibeListaCompra(lista2);
                      break;
            case 5 :  lista3 = listaInvertidaVenda();
                      exibeListaVenda(lista3);
                      break;
            case 0 :  return 0;
                      break;
            default : printf("Opção inválida, digite um número válido\n\n");
                      break;
        }
    opcao = menuRelatorio();
    }
    return 0;
}

int menuRelatorio(void) {
    int opcao;
    printf("\n\n");
    printf ("= = = = = = = = = = = = =\n"
            "=  R E L A T Ó R I O S  =\n"
            "= = = = = = = = = = = = =\n"
            "\n[1] - Lista Ordenada de Clientes\n"
            "[2] - Lista Direta de Clientes\n"
            "[3] - Lista de Produtos\n"
            "[4] - Lista de Compras\n"
            "[5] - Lista de Vendas\n"
            "[0] - Retornar\n");
    printf("\nEscolha sua opção: ");
    scanf("%d", &opcao);
    system("cls || clear");
    return opcao;
}

NoCliente* listaOrdenadaCliente(void) {
  FILE* fp;
  NoCliente* cliente;
  NoCliente* noClt;
  NoCliente* lista;

  lista = NULL;
  fp = fopen("cliente.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }

  cliente = (NoCliente*) malloc(sizeof(NoCliente));
  while(fread(cliente, sizeof(NoCliente), 1, fp)) {
    if (cliente->status == '1') {
      noClt = (NoCliente*) malloc(sizeof(NoCliente));
      strcpy(noClt->nome, cliente->nome);
      noClt->nasc[0] = cliente->nasc[0];
      noClt->nasc[1] = cliente->nasc[1];
      noClt->nasc[2] = cliente->nasc[2];
      strcpy(noClt->cpf, cliente->cpf);
      strcpy(noClt->email, cliente->email);
      strcpy(noClt->telefone, cliente->telefone);
      noClt->status = cliente->status;

      if (lista == NULL) {
        lista = noClt;
        noClt->prox = NULL;
      } else if (strcmp(noClt->nome,lista->nome) < 0) {
        noClt->prox = lista;
        lista = noClt;
      } else {
        NoCliente* anter = lista;
        NoCliente* atual = lista->prox;
        while ((atual != NULL) && strcmp(atual->nome,noClt->nome) < 0) {
          anter = atual;
          atual = atual->prox;
        }
        anter->prox = noClt;
        noClt->prox = atual;
      }
    }
  }
  fclose(fp);
  free(cliente);
  return lista;
}

NoCliente* listaDiretaCliente(void) {
  FILE* fp;
  NoCliente* cliente;
  NoCliente* noClt;
  NoCliente* lista;
  NoCliente* ultimo;

  lista = NULL;
  fp = fopen("cliente.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }

  cliente = (NoCliente*) malloc(sizeof(NoCliente));
  while(fread(cliente, sizeof(NoCliente), 1, fp)) {
    if (cliente->status == '1') {
      noClt = (NoCliente*) malloc(sizeof(NoCliente));
      strcpy(noClt->nome, cliente->nome);
      noClt->nasc[0] = cliente->nasc[0];
      noClt->nasc[1] = cliente->nasc[1];
      noClt->nasc[2] = cliente->nasc[2];
      strcpy(noClt->cpf, cliente->cpf);
      strcpy(noClt->email, cliente->email);
      strcpy(noClt->telefone, cliente->telefone);
      noClt->status = cliente->status;
      noClt->prox = NULL;
      if (lista == NULL) {
        lista = noClt;
      } else {
        ultimo->prox = noClt;
      }
      ultimo = noClt;
    }
  }
  fclose(fp);
  free(cliente);
  return lista;
}

void exibeListaCliente(NoCliente* lista) {
  printf("\n\n");
  printf("= = = = = = = = = = = = = = = = = = \n");
  printf("=   Listagem de Clientes: A - Z   = \n");
  printf("= = = = = = = = = = = = = = = = = = \n");
  while (lista != NULL) {
    printf("Nome: %s\n", lista->nome);
    printf("Nascimento: %d/%d/%d\n",lista->nasc[0], lista->nasc[1],lista->nasc[2]);
    printf("CPF: %s\n", lista->cpf);
    printf("E-mail: %s\n", lista->email);
    printf("Telefone: %s\n", lista->telefone);
    printf("Status: %c\n", lista->status);
    printf("\n");
    lista = lista->prox;
  }
}

void limpar(){
    NoCliente* lista;
    NoCliente* primeiro;
    NoCliente *cliente = primeiro, *aux;
    while (lista != NULL)
    {
        aux = lista;
        lista = lista->prox;
        free (aux);
    }
    primeiro = NULL;
}

NoProd* listaOrdenadaProduto(void) {
  FILE* fp;
  NoProd* produto;
  NoProd* noProdut;
  NoProd* lista1;

  lista1 = NULL;
  fp = fopen("produto.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }

  produto = (NoProd*) malloc(sizeof(NoProd));
  while(fread(produto, sizeof(NoProd), 1, fp)) {
    if (produto->status == '1') {
      noProdut = (NoProd*) malloc(sizeof(NoProd));
      strcpy(noProdut->cod, produto->cod);
      strcpy(noProdut->nome, produto->nome);
      strcpy(noProdut->marca, produto->marca);
      strcpy(noProdut->preco, produto->preco);
      strcpy(noProdut->qntd, produto->qntd);
      noProdut->status = produto->status;

      if (lista1 == NULL) {
        lista1 = noProdut;
        noProdut->prox = NULL;
      } else if (strcmp(noProdut->nome,lista1->nome) < 0) {
        noProdut->prox = lista1;
        lista1 = noProdut;
      } else {
        NoProd* anter = lista1;
        NoProd* atual = lista1->prox;
        while ((atual != NULL) && strcmp(atual->nome,noProdut->nome) < 0) {
          anter = atual;
          atual = atual->prox;
        }
        anter->prox = noProdut;
        noProdut->prox = atual;
      }
    }
  }
  fclose(fp);
  free(produto);
  return lista1;
}

void exibeListaProduto(NoProd* lista1) {
  printf("\n\n");
  printf("= = = = = = = = = = = = = = \n");
  printf("=   Listagem de Produtos  = \n");
  printf("= = = = = = = = = = = = = = \n");
  while (lista1 != NULL) {
    printf("\nCódigo: %s\n", lista1->cod);
    printf("Nome: %s\n",lista1->nome);
    printf("Marca: %s\n", lista1->marca);
    printf("Preço: R$%s\n", lista1->preco);
    printf("Quantidade: %s\n", lista1->qntd);
    printf("\n");
    printf("===========================");
    lista1 = lista1->prox;
  }
}

NoCompra* listaInvertidaCompra(void) {
  FILE* fp;
  NoCompra* compra;
  NoCompra* noCompr;
  NoCompra* lista2;

  lista2 = NULL;
  fp = fopen("compra.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }

  compra = (NoCompra*) malloc(sizeof(NoCompra));
  while(fread(compra, sizeof(NoCompra), 1, fp)) {
    if (compra->status == '1') {
      noCompr = (NoCompra*) malloc(sizeof(NoCompra));
      strcpy(noCompr->cod, compra->cod);
      strcpy(noCompr->qntd, compra->qntd);
      noCompr->status = compra->status;
      noCompr->prox = lista2;
      lista2 = noCompr;
    }
  }
  fclose(fp);
  free(compra);
  return lista2;
}

void exibeListaCompra(NoCompra* lista2) {
  printf("\n\n");
  printf("= = = = = = = = = = = = = = \n");
  printf("=   Relatório de Compras  = \n");
  printf("= = = = = = = = = = = = = = \n");
  while (lista2 != NULL) {
    printf("\nCódigo do Produto: %s\n", lista2->cod);
    printf("Quantidade: %s\n", lista2->qntd);
    printf("\n");
    printf("============================");
    lista2 = lista2->prox;
  }
}

NoVenda* listaInvertidaVenda(void) {
  FILE* fp;
  NoVenda* venda;
  NoVenda* noVend;
  NoVenda* lista3;

  lista3 = NULL;
  fp = fopen("venda.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }

  venda = (NoVenda*) malloc(sizeof(NoVenda));
  while(fread(venda, sizeof(NoVenda), 1, fp)) {
    if (venda->status == '1') {
      noVend = (NoVenda*) malloc(sizeof(NoVenda));
      strcpy(noVend->cod, venda->cod);
      strcpy(noVend->qntd, venda->qntd);
      noVend->status = venda->status;
      noVend->prox = lista3;
      lista3 = noVend;
    }
  }
  fclose(fp);
  free(venda);
  return lista3;
}

void exibeListaVenda(NoVenda* lista3) {
  printf("\n\n");
  printf("= = = = = = = = = = = = = = \n");
  printf("=   Relatório de Vendas   = \n");
  printf("= = = = = = = = = = = = = = \n");
  while (lista3 != NULL) {
    printf("\nCódigo do Produto: %s\n", lista3->cod);
    printf("Quantidade: %s\n", lista3->qntd);
    printf("\n");
    printf("============================");
    lista3 = lista3->prox;
  }
}

/////////////// Sobre /////////////////

int menuPrincipalSobre(void) {
  int opcao;
  opcao = menuSobre();
  while (opcao != 0) {
    switch (opcao) {
      case 1 :  sobreOprograma();
                break;
      case 0 : return 0;
                break;
      default : printf("Opção inválida, digite um número válido\n\n");
                break;
    }
    opcao = menuSobre();
  }
  return 0;
}

int menuSobre(void) {
  int op;
  printf("\n\n");
  printf("= = = = = = = =  \n");
  printf("=  S O B R E  = \n");
  printf("= = = = = = = = \n");
  printf("\n[1] - Sobre\n");
  printf("[0] - Retornar\n");
  printf("\nEscolha sua opção: ");
  scanf("%d", &op);
  system("cls || clear");
  return op;
}

void sobreOprograma(void){
  printf("\n\n");
  printf("    *============================= SOBRE O PROGRAMA ============================*\n");
  printf("    |                                                                           |\n");
  printf("    |PROGRAMA DE CONTROLE DE ESTOQUES CRIADO UTILIZANDO ALOCAÇÃO DINÁMICA,      |\n");
  printf("    |STRUCTS E PONTEIROS, COMO FORMA DE AVALIAÇÃO NA DISCIPLINA DE PROGRAMAÇÃO, |\n");
  printf("    |DO PROFESSOR: FLAVIUS GORGÔNIO. APRESENTADO EM SALA DE AULA,               |\n");
  printf("    |COM A FINALIDADE DE OBTER NOTAS DE AVALIAÇÃO DA DISCIPLINA.                |\n");
  printf("    |                                                                           |\n");
  printf("    |                                                                           |\n");
  printf("    |                              IDENTIFICAÇÃO                                |\n");
  printf("    |                                                                           |\n");
  printf("    |           ALUNAS DE SISTEMAS DE INFORMAÇÃO - UFRN CERES CAICÓ             |\n");
  printf("    |                                                                           |\n");
  printf("    |RENATA ARAÚJO.                             WANESSA SILVA.                  |\n");
  printf("    |TEL:(84) 9 9912-3995                       TEL:(84) 9 9849-0496            |\n");
  printf("    |renatakarla02@gmail.com                    wanessaparelhas68@gmail.com     |\n");
  printf("    |github.com/renatak12                       github.com/wanessabezerra       |\n");
  printf("    *===========================================================================*\n");
}

/////////////// validaçoes ////////////////


int validacaoEhNumero(char c) {
  if (c>='0'&& c<='9') {
    return 1;
  }
  else {
    return 0;
  }
}


int validacaoPalavra(char s[]) {
  int tam = strlen(s);
  for(int i = 0; i < tam; i++){
    char c = s[i];
    if (c>='0'&& c<='9') {
      return 0;
    }
  }
  return 1;
}


int validacaoCpf(char *cpf){
    int i, j, digito1 = 0, digito2 = 0;
    if(strlen(cpf) != 11)
        return 0;
    
    else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
            (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
            (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
            (strcmp(cpf,"99999999999") == 0)){
        return 0;

    }else {
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--)
            digito1 += (cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((cpf[9]-48) != digito1)
            return 0;
        else
        
        {
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--)
                    digito2 += (cpf[i]-48) * j;
        digito2 %= 11;
        if(digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if((cpf[10]-48) != digito2)
            return 0;
        }
    }
    return 1;
}

int validacaoEmail( const char * email ) {
    char usuario[256], site[256], dominio[256];

    if( sscanf( email, "%[^@ \t\n]@%[^. \t\n].%3[^ \t\n]", usuario, site, dominio ) != 3 )
        return 0;

    return 1;
}

int validacaoTelefone(char *telefone){
  if(strlen(telefone) != 9) {
      return 0;
      }
  else if((strcmp(telefone,"000000000") == 0) || (strcmp(telefone,"111111111") == 0) || (strcmp(telefone,"222222222") == 0) ||
          (strcmp(telefone,"333333333") == 0) || (strcmp(telefone,"444444444") == 0) || (strcmp(telefone,"555555555") == 0) ||
          (strcmp(telefone,"666666666") == 0) || (strcmp(telefone,"777777777") == 0) || (strcmp(telefone,"888888888") == 0) ||
          (strcmp(telefone,"999999999") == 0)){
      return 0;}

  else if(strlen(telefone) == 6){
    int tam = strlen(telefone);
    for(int i = 0; i < tam; i++){
      char c = telefone[i];
      if (c < '0' || c > '9'){
        return 0;}
      }
    }
  return 1;
}

    
int bissexto(int aa){
    if ((aa % 4 == 0) && (aa % 100 != 0)) {
        return 1;
    } else if (aa % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int dataValida(int dd, int mm, int aa) {
    int maiorDia;
    if (aa < 0 || mm < 1 || mm > 12) {
        return 0;
    } if (mm == 2) {
        if(bissexto(aa)) {
            maiorDia = 29;
        } else {
            maiorDia = 28;
        }
    } else if (mm == 4 || mm == 6 || mm == 9 || mm == 11 ){
        maiorDia = 30;
    } else {
        maiorDia = 31;
    } if (dd < 1 || dd > maiorDia){
        return 0;
    }
    return 1;
}


int validacaoCod(char *codi){
  if(strlen(codi) != 5){
      return 0;
      }

  else if((strcmp(codi,"00000") == 0) || (strcmp(codi,"11111") == 0) || (strcmp(codi,"22222") == 0) ||
          (strcmp(codi,"33333") == 0) || (strcmp(codi,"44444") == 0) || (strcmp(codi,"55555") == 0) ||
          (strcmp(codi,"66666") == 0) || (strcmp(codi,"77777") == 0) || (strcmp(codi,"88888") == 0) ||
          (strcmp(codi,"99999") == 0)){
      return 0;
  }else if(strlen(codi) == 5){
    int tam = strlen(codi);
    for(int i = 0; i < tam; i++){
      char c = codi[i];
      if (c>='A' && c<='Z') {
        return 0;
      }
      else if (c>='a' && c<='z') {
        return 0;
      }
    }
  }
  return 1;
}

int validacaoPalavra1(char s[]) {
  int tam;
  tam = strlen(s);
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
void dataEhora1(NoCompra* compra) {
  FILE* fp;
  fp = fopen("venda.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  struct tm *data_hora_atual;     
  
  time_t segundos;  
  time(&segundos);     
  data_hora_atual = localtime(&segundos);
  
  printf("Hora de saída: %d:",data_hora_atual->tm_hour-3);printf("%d:",data_hora_atual->tm_min);
  printf("%d\n",data_hora_atual->tm_sec);
  printf("Data de saída: %d/", data_hora_atual->tm_mday);
  printf("%d/",data_hora_atual->tm_mon+1);
  printf("%d\n\n",data_hora_atual->tm_year+1900);
  fclose(fp);
}

void dataEhora2(NoVenda* venda) {
  FILE* fp;
  fp = fopen("venda.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  struct tm *data_hora_atual;     
  
  time_t segundos;  
  time(&segundos);     
  data_hora_atual = localtime(&segundos);
  
  printf("Hora de saída: %d:",data_hora_atual->tm_hour-3);printf("%d:",data_hora_atual->tm_min);
  printf("%d\n",data_hora_atual->tm_sec);
  printf("Data de saída: %d/", data_hora_atual->tm_mday);
  printf("%d/",data_hora_atual->tm_mon+1);
  printf("%d\n\n",data_hora_atual->tm_year+1900);
  fclose(fp);
}
