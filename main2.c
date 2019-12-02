#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>
#include <time.h>


typedef struct clt Cliente;

struct clt {
  char nome[20];
  int nasc[3];
  char cpf[12]; 
  char email[40];
  char telefone[12];
  char status;
};

typedef struct noClt NoCliente;

struct noClt {
  char nome[20];
  int nasc[3];
  char cpf[12]; 
  char email[40];
  char telefone[12];
  char status;
  NoCliente* prox;
}; 

typedef struct produt Prod;

struct produt {
  char cod[6];
  char nome[15];
  char marca[15];
  char status;
  char qntd[4];
  char preco[5];
};

typedef struct noProdut NoProd;

struct noProdut {
  char cod[6];
  char nome[15];
  char marca[15];
  char status;
  char qntd[4];
  char preco[6];
  NoProd* prox;
};


typedef struct compr Compra;

struct compr {
  char cod[6];
  char cod2[5];
  char qntd[4];
  char status;
  
};


typedef struct noCompr NoCompra;

struct noCompr {
  char cod[6];
  char cod2[5];
  char qntd[4];
  char status;
  NoCompra* prox;
};


typedef struct vend Venda;

struct vend {
  char cod[6];
  char cpf[12];
  char qntd[4];
  char status;
  time_t dataVenda;
};


typedef struct noVend NoVenda;

struct noVend {
  char cod[6];
  char cpf[12];
  char qntd[4];
  char status;
  time_t dataVenda;
  NoVenda* prox;
};

int menuPrincipal(void);
int menuPrincipalCliente(void);
int menuCliente(void);
void cadastraCliente(void);
Cliente* buscaCliente(char*);
void editaCliente(void);
void excluiCliente(void);
void gravaCliente(Cliente*);


int menuPrincipalProduto(void);
int menuProduto(void);
void cadastraProduto(void);
Prod* buscaProduto(char*);
void editaProduto(void);
void excluiProduto(void);
void gravaProduto(Prod*);


int menuPrincipalCompra(void);
int menuCompra(void);
void cadastraCompra(void);
Compra* buscaCompra(char*);
void editaCompra(void);
void excluiCompra(void);
void listaCompra(void);
void gravaCompra(Compra*);
void dataEhora1(Compra*);


int menuPrincipalVenda(void);
int menuVenda(void);
void cadastraVenda(void);
Venda* buscaVenda(char*);
void editaVenda(void);
void excluiVenda(void);
void gravaVenda(Venda*);
void dataEhora2(Venda*);


int menuPrincipalRelatorio(void);
int menuRelatorio(void);
NoCliente* listaOrdenadaCliente(void);
NoCliente* listaDiretaCliente(void);
NoProd* listaOrdenadaProduto(void);
NoCompra* listaInvertidaCompra(void);
NoVenda* listaInvertidaVenda(void);
void exibeCliente(Cliente*);
void exibeProduto(Prod*);
void exibeCompra(Compra*);
void exibeVenda(Venda*);
void exibeListaCliente();
void exibeListaProduto();
void exibeListaCompra();
void exibeListaVenda();

//void listaClientes(void);
//void listaProdutos(void);
//void listaCompra(void);
//void listaVendas(void);


int menuPrincipalSobre(void);
int menuSobre(void);
void sobreOprograma(void);


int ehLetra(char);
int validacaoEhNumero(char);
int validacaoEhNumero1(char*);
int validacaoEhNumero2(char*);
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
    Cliente* busca;
    opcao = menuCliente();
    while (opcao != 0) {
        switch (opcao) {
            case 1 :  cadastraCliente();
                    break;
            case 2 :  editaCliente();
                    break;
            case 3 :  excluiCliente();
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
            "[2] - Atualizar Cliente\n"
            "[3] - Deletar Cliente\n"
            "[0] - Retornar\n");
    printf("\nEscolha sua opção: ");
    scanf("%d", &opcao);
    system("cls || clear");
    return opcao;
}


void cadastraCliente(void) {
  Cliente* cliente;
  int dia, mes, ano;
  char resp;
  do{
    printf("\n\n");
    printf("= = = = = = = = = = = = =\n");
    printf("= = Cadastrar Cliente = =\n");
    printf("= = = = = = = = = = = = =\n");
    cliente = (Cliente*) malloc(sizeof(Cliente));

    printf("\nNome: ");
    scanf(" %19[^\n]", cliente->nome);
    while((validacaoPalavra(cliente->nome)!= 1)) {
      printf("\nNome inválido, tente novamente.\n");
      printf("Nome: ");
      scanf(" %19[^\n]", cliente->nome);
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
    scanf(" %39[^\n]", cliente->email);
    while(!(validacaoEmail(cliente->email))) {
      printf("\nE-mail inválido, tente novamente.\n");
      printf("E-mail: ");
      scanf(" %39[^\n]", cliente->email);
    }
    
    printf("Telefone: ");
    scanf("%11s", cliente->telefone);
    getchar();
    while((validacaoTelefone(cliente->telefone)!=1)) {
      printf("\nTelefone inválido, tente novamente.\n");
      printf("Telefone: ");
      scanf("%11s", cliente->telefone);
    }

    cliente->status = '1';
    gravaCliente(cliente);
    printf("Deseja comprar outro produto (s/n)? ");
    scanf("%c", &resp);
    getchar();
    system("cls || clear");

  }while(resp == 's' || resp == 'S');

}
/*
Cliente* buscaCliente(char *cpf){ // Cliente* no lugar do void e *cpf
    Cliente* cliente;
    FILE* fp;
    char listacliente;
    int achou;
    char procurado[15];
    fp = fopen("cliente.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    achou = 0;
    while((!achou) && (fread(cliente, sizeof(Cliente), 1, fp))) {
        if ((strcmp(cliente->cpf, procurado) == 0) && (cliente->status == '1')) {
            achou = 1;
        }
    }
    fclose(fp);
    if (achou) {//exibeCliente
        return (cliente);
    } else {
        printf("O cliente %s não foi encontrado...\n", procurado);
    }
    free(cliente);
}*/

void editaCliente() {
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
    printf("CPF: ");
    scanf("%11s", cliente->cpf);
    while((validacaoCpf(cliente->cpf)!=1)) {
      printf("\nNúmero inválido, tente novamente.\n");
      printf("CPF: ");
      scanf("%11s", cliente->cpf);
    }

    cliente = (Cliente*) malloc(sizeof(Cliente));
    achou = 0;
    while((!achou) && (fread(cliente, sizeof(Cliente), 1, fp))) {
        if ((strcmp(cliente->cpf, procurado) == 0) && (cliente->status == '1')) {
            achou = 1;
        }
    }
    if (achou) {
        exibeCliente(cliente);
        getchar();
        printf("Deseja realmente editar este cliente (s/n)? ");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S') {
            printf("\nNome: ");
            scanf(" %19[^\n]", cliente->nome);
            while((validacaoPalavra(cliente->nome)!= 1)) {
              printf("\nNome inválido, tente novamente.\n");
              printf("Nome: ");
              scanf(" %19[^\n]", cliente->nome);
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
            scanf(" %39[^\n]", cliente->email);
            while(!(validacaoEmail(cliente->email))) {
              printf("\nE-mail inválido, tente novamente.\n");
              printf("E-mail: ");
              scanf(" %39[^\n]", cliente->email);
            }
            
            printf("\nTelefone: ");
            scanf("%11s", cliente->telefone);
            getchar();
            while((validacaoTelefone(cliente->telefone)!=1)) {
              printf("\nTelefone inválido, tente novamente.\n");
              printf("Telefone: ");
              scanf("%11s", cliente->telefone);
            }

            cliente->status = '1';
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

    printf("\nInforme o CPF do cliente a ser apagado: ");
    scanf("%11s", cliente->cpf);
    while((validacaoCpf(cliente->cpf)!=1)) {
      printf("\nNúmero inválido, tente novamente.\n");
      printf("CPF: ");
      scanf("%11s", cliente->cpf);
    }
    cliente = (Cliente*) malloc(sizeof(Cliente));
    achou = 0;
    while((!achou) && (fread(cliente, sizeof(Cliente), 1, fp))) {
        if ((strcmp(cliente->cpf, procurado) == 0) && (cliente->status == '1')) {
            achou = 1;
        }
    }
    if (achou) {
        exibeCliente(cliente);
        getchar();
        printf("Deseja realmente apagar este cliente (s/n)? ");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S') {
            cliente->status = '0';
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
    printf("Deseja excluir outro cadastro(s/n)? ");
    scanf("%c", &resp);
    getchar();
    system("cls || clear");

  }while(resp == 's' || resp == 'S');
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
    printf("Nome: %s\n", cliente->nome);
    printf("Nascimento: %d/%d/%d\n",cliente->nasc[0], cliente->nasc[1],cliente->nasc[2]);
    printf("CPF: %s\n", cliente->cpf);
    printf("E-mail: %s\n", cliente->email);
    printf("Telefone: %s\n", cliente->telefone
);
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
     // case 2 :  buscaProduto();
             //   break;
      case 2 :  editaProduto();
                break;
      case 3 :  excluiProduto();
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
  printf("= = = = = = = = = = = = \n");
  printf("=    P R O D U T O    = \n");
  printf("= = = = = = = = = = = = \n");
  printf("\n[1] - Cadastrar produto\n");
  printf("[2] - Atualizar produto\n");
  printf("[3] - Deletar produto\n");
  printf("[0] - Retornar\n");
  printf("\nEscolha sua opção: ");
  scanf("%d", &op);
  system("cls || clear");
  return op;
}


void cadastraProduto(void) {
  Prod* produto;
  char resp;
  do{
    printf("\n\n");
    printf("= = = = = = = = = = = = = \n");
    printf("=   Cadastrar Produto   = \n");
    printf("= = = = = = = = = = = = =\n");
    produto = (Prod*) malloc(sizeof(Prod));
    printf("\nCódigo do produto: ");
    scanf("%5s", produto->cod);
    while((validacaoCod(produto->cod)!=1)) {
      printf("\nCódigo inválido, tente novamente.\n");
      printf("Código do produto: ");
      scanf("%5s", produto->cod);
    }

    printf("Nome do produto: ");
    scanf(" %14[^\n]", produto->nome);
    while((validacaoPalavra(produto->nome)!= 1)) {
      printf("\nNome inválido, tente novamente.\n");
      printf("Nome do produto: ");
      scanf(" %14[^\n]", produto->nome);
    }

    printf("Marca do produto: ");
    scanf(" %14[^\n]", produto->marca);
    while((validacaoPalavra1(produto->marca)!= 1)) {
      printf("\nMarca inválida, tente novamente.\n");
      printf("Marca do produto: ");
      scanf(" %14[^\n]", produto->marca);
    }

    printf("Preço unitário do produto: ");
    scanf("%6s ,", produto->preco);
    getchar();
    while((validacaoEhNumero1(produto->preco)!=1)) {
      printf("\nPreço inválido, tente novamente.\n");
      printf("\nPreço unitário do produto: ");
      scanf("%6s", produto->preco);
      getchar();
    }

    printf("Quantidade do produto: ");
    scanf("%3s", produto->qntd);
    getchar();
    while((validacaoEhNumero2(produto->qntd)!=1)) {
      printf("\nQuantidade inválida, tente novamente.\n");
      printf("\nQuantidade do produto: ");
      scanf("%3s", produto->qntd);
      getchar();
    }

    produto->status = '1';
    gravaProduto(produto);

    printf("Deseja cadastrar outro produto (s/n)? ");
    scanf("%c", &resp);
    system("cls || clear");

  }while(resp == 's' || resp == 'S');
}

/*
Prod* buscaProduto(char *cod) {
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
  printf("\nCódigo do produto: ");
  scanf("%5s", produto->cod);
  while((validacaoCod(produto->cod)!=1)) {
    printf("\nCódigo inválido, tente novamente.\n");
    printf("Código do produto: ");
    scanf("%5s", produto->cod);
  }
  produto = (Prod*) malloc(sizeof(Prod));
  achou = 0;
  while((!achou) && (fread(produto, sizeof(Prod), 1, fp))) {
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
  system("cls || clear");
}*/


void editaProduto(void) {
  FILE* fp;
  Prod* produto;
  int achou;
  char resp;
  char procurado[15];
  do{
    fp = fopen("produto.dat", "r+b");
    if (fp == NULL) {
      printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
      printf("Não é possível continuar o programa...\n");
      exit(1);
    }
    printf("\n\n");
    printf("= = = = = = = = = = = = \n");
    printf("=    Editar produto   = \n");
    printf("= = = = = = = = = = = =\n");
    printf("\nInforme o código do produto a ser alterado: ");
    scanf("%5s", produto->cod);
    while((validacaoCod(produto->cod)!=1)) {
      printf("\nCódigo inválido, tente novamente.\n");
      printf("Código do produto: ");
      scanf("%5s", produto->cod);
    }
    produto = (Prod*) malloc(sizeof(Prod));
    achou = 0;
    while((!achou) && (fread(produto, sizeof(Prod), 1, fp))) {
    if ((strcmp(produto->cod, procurado) == 0) && (produto->status == '1')) {
      achou = 1;
    }
    }
    if (achou) {
      exibeProduto(produto);
      getchar();
      printf("Deseja realmente editar este produto (s/n)? ");
      scanf("%c", &resp);
      if (resp == 's' || resp == 'S') {
        printf("\nCódigo do produto: ");
        scanf("%5s", produto->cod);
        while((validacaoCod(produto->cod)!=1)) {
          printf("\nCódigo inválido, tente novamente.\n");
          printf("Código do produto: ");
          scanf("%5s", produto->cod);
        }

        printf("Nome do produto: ");
        scanf(" %14[^\n]", produto->nome);
        while((validacaoPalavra(produto->nome)!= 1)) {
          printf("\nNome inválido, tente novamente.\n");
          printf("Nome do produto: ");
          scanf(" %14[^\n]", produto->nome);
        }

        printf("Marca do produto: ");
        scanf(" %14[^\n]", produto->marca);
        while((validacaoPalavra1(produto->marca)!= 1)) {
          printf("\nMarca inválida, tente novamente.\n");
          printf("Marca do produto: ");
          scanf(" %14[^\n]", produto->marca);
        }

        printf("Preço unitário do produto: ");
        scanf("%6s ,", produto->preco);
        getchar();
        while((validacaoEhNumero1(produto->preco)!=1)) {
          printf("\nPreço inválido, tente novamente.\n");
          printf("\nPreço unitário do produto: ");
          scanf("%6s", produto->preco);
          getchar();
        }

        printf("Quantidade do produto: ");
        scanf("%3s", produto->qntd);
        getchar();
        while((validacaoEhNumero(*produto->qntd)!=1)) {
          printf("\nQuantidade inválida, tente novamente.\n");
          printf("\nQuantidade do produto: ");
          scanf("%3s", produto->qntd);
          getchar();
        }

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
    printf("Deseja editar outro produto (s/n)? ");
    scanf("%c", &resp);
    system("cls || clear");
  }while(resp == 's' || resp == 'S');
  getchar();
}


void excluiProduto(void) {
  FILE* fp;
  Prod* produto;
  int achou;
  char resp;
  char procurado[15];
  do{
    fp = fopen("produto.dat", "r+b");
    if (fp == NULL) {
      printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
      printf("Não é possível continuar o programa...\n");
      exit(1);
    }
    printf("\n\n");
    printf("= = = = = = = =  = = = \n");
    printf("=   Apagar Produto   = \n");
    printf("= = = = = = = = =  = = \n");
    printf("\nInforme o código do produto a ser apagado: ");
    scanf("%5s", produto->cod);
    while((validacaoCod(produto->cod)!=1)) {
      printf("\nCódigo inválido, tente novamente.\n");
      printf("Código do produto: ");
      scanf("%5s", produto->cod);
    }

    produto = (Prod*) malloc(sizeof(Prod));
    achou = 0;
    while((!achou) && (fread(produto, sizeof(Prod), 1, fp))) {
    if ((strcmp(produto->cod, procurado) == 0) && (produto->status == '1')) {
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

    printf("Deseja apagar outro produto (s/n)? ");
    scanf("%c", &resp);
    system("cls || clear");

  }while(resp == 's' || resp == 'S');
  getchar();
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
  printf("Código: %s\n", produto->cod);
  printf("Nome: %s\n", produto->nome);
  printf("Marca: %s\n", produto->marca);
  printf("Preço: %d\n", *produto->preco);
  printf("Quantidade: %d\n", *produto->qntd);
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
        case 2 :  editaCompra();
                  break;
        case 3 :  excluiCompra();
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
  printf("= = = = = = = = = = \n");
  printf("=   C O M P R A   = \n");
  printf("= = = = = = = = = = \n");
  printf("\n[1] - Cadastrar Compra\n");
  printf("[2] - Atualizar Compra\n");
  printf("[3] - Deletar Compra\n");
  printf("[0] - Retornar\n");
  printf("\nEscolha sua opção: ");
  scanf("%d", &op);
  system("cls || clear");
  return op;
}

void cadastraCompra(void) {
  Compra* compra;
  Prod* produto;
  char resp;
  do{
    printf("\n\n");
    printf(" = = = = = = = = = = = = = = = = = =\n");
    printf(" =   Cadastrar Compra de Produtos  =\n");
    printf(" = = = = = = = = = = = = = = = = = = \n");

    compra = (Compra*) malloc(sizeof(Compra));

    printf("\nCódigo da empresa: ");
    scanf("%6s", compra->cod);
    while((validacaoCod2(compra->cod)!=1)) {
      printf("\nCódigo inválido, somente 6 dígitos, tente novamente.\n");
      printf("Código da empresa: ");
      scanf("%6s", compra->cod);
    }

    printf("Código do produto: ");
    scanf("%5s", compra->cod2);
    while((validacaoCod(compra->cod2)!=1)) {
      printf("\nCódigo inválido, somente 5 dígitos, tente novamente.\n");
      printf("Código do produto: ");
      scanf("%5s", compra->cod2);
    }

    printf("Quantidade do produto: ");
    scanf("%s", compra->qntd);
    getchar();
    while((validacaoEhNumero(*compra->qntd)!=1)) {
      printf("\nQuantidade inválida, tente novamente.\n");
      printf("Quantidade do produto: ");
      scanf("%s", compra->qntd);
      getchar();
    }

    (dataEhora1(compra));
    compra->status = '1';
    gravaCompra(compra);

    printf("Deseja comprar outro produto (s/n)? ");
    scanf("%c", &resp);
    system("cls || clear");

  }while(resp == 's' || resp == 'S');


}

/*
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
  printf("\nCódigo do produto: ");
  scanf("%5s", compra->cod2);
  while((validacaoCod(compra->cod2)!=1)) {
    printf("\nCódigo inválido, somente 5 dígitos, tente novamente.\n");
    printf("Código do produto: ");
    scanf("%5s", compra->cod2);
  }
  compra = (Compra*) malloc(sizeof(Compra));
  achou = 0;
  while((!achou) && (fread(compra, sizeof(Compra), 1, fp))) {
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
*/
void editaCompra(void) {
  FILE* fp;
  Compra* compra;
  int achou;
  char resp;
  char procurado[15];
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
    printf("Informe o código do produto a ser alterado: ");
    scanf("%5s", compra->cod2);
    while((validacaoCod(compra->cod2)!=1)) {
      printf("\nCódigo inválido, somente 5 dígitos, tente novamente.\n");
      printf("Código do produto: ");
      scanf("%5s", compra->cod2);
    }
    compra = (Compra*) malloc(sizeof(Compra));
    achou = 0;
    while((!achou) && (fread(compra, sizeof(Compra), 1, fp))) {
    if ((strcmp(compra->cod, procurado) == 0) && (compra->status == '1')) {
      achou = 1;
    }
    }
    if (achou) {
      exibeCompra(compra);
      getchar();
      printf("Deseja realmente editar este produto (s/n)? ");
      scanf("%c", &resp);
      if (resp == 's' || resp == 'S') {
        printf("\nCódigo da empresa: ");
        scanf("%6s", compra->cod);
        while((validacaoCod2(compra->cod)!=1)) {
          printf("\nCódigo inválido, somente 6 dígitos, tente novamente.\n");
          printf("Código da empresa: ");
          scanf("%6s", compra->cod);
        }

        printf("\nCódigo do produto: ");
        scanf("%5s", compra->cod2);
        while((validacaoCod(compra->cod2)!=1)) {
          printf("\nCódigo inválido, somente 5 dígitos, tente novamente.\n");
          printf("Código do produto: ");
          scanf("%5s", compra->cod2);
        }

        /*printf("Nome do produto: ");
        scanf(" %14[^\n]", compra->nome);
        while((validacaoPalavra(compra->nome)!= 1)) {
          printf("\nNome inválido, tente novamente.\n");
          printf("Nome do produto: ");
          scanf(" %14[^\n]", compra->nome);
        }

        printf("Marca do produto: ");
        scanf(" %14[^\n]", compra->marca);
        while((validacaoPalavra1(compra->marca)!= 1)) {
          printf("\nMarca inválida, tente novamente.\n");
          printf("Marca do produto: ");
          scanf(" %14[^\n]", compra->marca);
        }*/

        printf("Quantidade do produto: ");
        scanf("%3s", compra->qntd);
        getchar();
        while((validacaoEhNumero(*compra->qntd)!=1)) {
          printf("\nQuantidade inválida, tente novamente.\n");
          printf("\nQuantidade do produto: ");
          scanf("%3s", compra->qntd);
          getchar();
        }
        (dataEhora1(compra));
        compra->status = '1';
        printf("Aperte a tecla ENTER para continuar. ");
        getchar();
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
      printf("Deseja comprar outro produto (s/n)? ");
      scanf("%c", &resp);
      system("cls || clear");

  }while(resp == 's' || resp == 'S');
}


void excluiCompra(void) {
  FILE* fp;
  Compra* compra;
  int achou;
  char resp;
  char procurado[15];
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
    scanf("%5s", compra->cod2);
    while((validacaoCod(compra->cod2)!=1)) {
      printf("\nCódigo inválido, somente 5 dígitos, tente novamente.\n");
      printf("Código do produto: ");
      scanf("%5s", compra->cod2);
    }

    compra = (Compra*) malloc(sizeof(Compra));
    achou = 0;
    while((!achou) && (fread(compra, sizeof(Compra), 1, fp))) {
    if ((strcmp(compra->cod, procurado) == 0) && (compra->status == '1')) {
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
    printf("Deseja apagar a compra de outro produto (s/n)? ");
    scanf("%c", &resp);
    system("cls || clear");

  }while(resp == 's' || resp == 'S');
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
  printf("Código da Empresa: %s\n", compra->cod2);
  printf("Código do Produto: %s\n", compra->cod);
  //printf("Nome: %s\n",produto->nome);
  //printf("Marca: %s\n", produto->marca);
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
        case 2 :  editaVenda();
                  break;
        case 3 :  excluiVenda();
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
  printf("= = = = = = = = = = = = = = = = = = = = =\n");
  printf("=   V E N D A   D E   P R O D U T O S   =\n");
  printf("= = = = = = = = = = = = = = = = = = = = =\n");
  printf("\n[1] - Cadastrar Venda\n");
  printf("[2] - Alterar Venda\n");
  printf("[3] - Excluir Venda\n");
  printf("[0] - Retornar\n");
  printf("\nEscolha sua opção: ");
  scanf("%d", &opcao);
  system("cls || clear");
  return opcao;
}


void cadastraVenda(void) {
  Venda* venda;
  Cliente* cliente;
  Prod* produto;
  float valor;
  char resp;
  do{
    printf("\n\n");
    printf(" = = = = = = = = = = =\n");
    printf(" =   Efetuar Venda   =\n");
    printf(" = = = = = = = = = = =\n");
    venda = (Venda*) malloc(sizeof(Venda));

    printf("\nCódigo do produto: ");
    scanf("%5s", venda->cod);
    while((validacaoCod(venda->cod)!=1)) {
      printf("\nCódigo inválido, tente novamente.\n");
      printf("Código do produto: ");
      scanf("%5s", venda->cod);
    }

    //busca = buscarCliente(cliente ->cpf);

    /*printf("Nome do produto: ");
    scanf(" %14[^\n]", venda->nome);
    while((validacaoPalavra(venda->nome)!= 1)) {
      printf("\nNome inválido, tente novamente.\n");
      printf("Nome do produto: ");
      scanf(" %14[^\n]", venda->nome);
    }

    printf("Marca do produto: ");
    scanf(" %14[^\n]", venda->marca);
    while((validacaoPalavra1(venda->marca)!= 1)) {
      printf("\nMarca inválida, tente novamente.\n");
      printf("Marca do produto: ");
      scanf(" %14[^\n]", venda->marca);
    }*/

    printf("Quantidade do produto: ");
    scanf("%3s", venda->qntd);
    getchar();
    while((validacaoEhNumero(*venda->qntd)!=1)) {
      printf("\nQuantidade inválida, tente novamente.\n");
      printf("\nQuantidade do produto: ");
      scanf("%3s", venda->qntd);
      getchar();
    }               

    //valor = (produto->preco) * (venda->qntd);
    (dataEhora2(venda));
    venda->status = '1';
    gravaVenda(venda);
    printf("Deseja vender outro produto (s/n)? ");
    scanf("%c", &resp);
    system("cls || clear");

  }while(resp == 's' || resp == 'S');
}

/*Venda* buscaVenda(){
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

    printf("\nCódigo do produto: ");
    scanf("%5s", venda->cod);
    while((validacaoCod(venda->cod)!=1)) {
      printf("\nCódigo inválido, tente novamente.\n");
      printf("Código do produto: ");
      scanf("%5s", venda->cod);
    }

    venda = (Venda*) malloc(sizeof(Venda));
    achou = 0;
    while((!achou) && (fread(venda, sizeof(Venda), 1, fp))) {
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
}*/

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
    printf("Nome do produto vendido a ser alterado: ");
    scanf(" %14[^\n]", procurado);
    while((validacaoPalavra(procurado)!= 1)) {
      printf("\nNome inválido, tente novamente.\n");
      printf("Nome do produto vendido a ser alterado: ");
      scanf(" %14[^\n]", procurado);
    }
    venda = (Venda*) malloc(sizeof(Venda));
    achou = 0;
    while((!achou) && (fread(venda, sizeof(Venda), 1, fp))) {
        if ((strcmp(venda->cod, procurado) == 0) && (venda->status == '1')) {
            achou = 1;
        }
    }
    if (achou) {
        exibeVenda(venda);
        getchar();
        printf("Deseja realmente editar este venda (s/n)? ");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S') {
            printf("\nCódigo do produto: ");
            scanf("%5s", venda->cod);
            while((validacaoCod(venda->cod)!=1)) {
              printf("\nCódigo inválido, tente novamente.\n");
              printf("Código do produto: ");
              scanf("%5s", venda->cod);
            }

            /*printf("Nome do produto: ");
            scanf(" %14[^\n]", venda->nome);
            while((validacaoPalavra(venda->nome)!= 1)) {
              printf("\nNome inválido, tente novamente.\n");
              printf("Nome do produto: ");
              scanf(" %14[^\n]", venda->nome);
            }

            printf("Marca do produto: ");
            scanf(" %14[^\n]", venda->marca);
            while((validacaoPalavra1(venda->marca)!= 1)) {
              printf("\nMarca inválida, tente novamente.\n");
              printf("Marca do produto: ");
              scanf(" %14[^\n]", venda->marca);
            }
            */
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
  printf("Aperte a tecla ENTER para continuar. ");
  getchar();
  system("cls || clear");

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
  
    printf("\nCódigo do produto vendido a ser apagado: ");
    scanf("%5s", venda->cod);
    while((validacaoCod(venda->cod)!=1)) {
      printf("\nCódigo inválido, tente novamente.\n");
      printf("Código do produto: ");
      scanf("%5s", venda->cod);
    }
    venda = (Venda*) malloc(sizeof(Venda));
    achou = 0;
    while((!achou) && (fread(venda, sizeof(Venda), 1, fp))) {
        if ((strcmp(venda->cod, procurado) == 0) && (venda->status == '1')) {
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
    printf("Aperte a tecla ENTER para continuar. ");
    getchar();
    system("cls || clear");
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
    printf("Código do produto: %s\n", venda->cod);
    //printf("Nome do produto: %s\n", venda->nome);
    //printf("Marca do produto: %s\n", venda->marca);
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
    printf("Escolha sua opção: ");
    scanf("%d", &opcao);
    system("cls || clear");
    return opcao;
}

NoCliente* listaOrdenadaCliente(void) {
  FILE* fp;
  Cliente* cliente;
  NoCliente* noClt;
  NoCliente* lista;

  lista = NULL;
  fp = fopen("cliente.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }

  cliente = (Cliente*) malloc(sizeof(Cliente));
  while(fread(cliente, sizeof(Cliente), 1, fp)) {
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
  Cliente* cliente;
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

  cliente = (Cliente*) malloc(sizeof(Cliente));
  while(fread(cliente, sizeof(Cliente), 1, fp)) {
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
  printf("= = Listagem de Clientes: A - Z = = \n");
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

NoProd* listaOrdenadaProduto(void) {
  FILE* fp;
  Prod* produto;
  NoProd* noProdut;
  NoProd* lista1;

  lista1 = NULL;
  fp = fopen("produto.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }

  produto = (Prod*) malloc(sizeof(Prod));
  while(fread(produto, sizeof(Prod), 1, fp)) {
    if (produto->status == '1') {
      noProdut = (NoProd*) malloc(sizeof(NoProd));
      strcpy(noProdut->cod, produto->cod);
      strcpy(noProdut->nome, produto->nome);
      strcpy(noProdut->marca, produto->marca);
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
  printf("= = = = = = = = = = = = = = =\n");
  printf("= = Listagem de Produtos = = \n");
  printf("= = = = = = = = = = = = = = =\n");
  while (lista1 != NULL) {
    printf("Código: %s\n", lista1->cod);
    printf("Nome: %s\n",lista1->nome);
    printf("Marca: %s\n", lista1->marca);
    printf("Quantidade: %s\n", lista1->qntd);
    printf("\n");
    lista1 = lista1->prox;
  }
}

NoCompra* listaInvertidaCompra(void) {
  FILE* fp;
  Compra* compra;
  NoCompra* noCompr;
  NoCompra* lista2;

  lista2 = NULL;
  fp = fopen("compra.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }

  compra = (Compra*) malloc(sizeof(Compra));
  while(fread(compra, sizeof(Compra), 1, fp)) {
    if (compra->status == '1') {
      noCompr = (NoCompra*) malloc(sizeof(NoCompra));
      strcpy(noCompr->cod, compra->cod);
      strcpy(noCompr->cod2, compra->cod2);
      //strcpy(noCompr->nome, compra->nome);
      //strcpy(noCompr->marca, compra->marca);
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
  printf("= = = = = = = = = = = = = = =\n");
  printf("= = Relatório de Compras = = \n");
  printf("= = = = = = = = = = = = = = =\n");
  while (lista2 != NULL) {
    printf("Código da Empresa: %s\n", lista2->cod);
    printf("\nCódigo do Produto: %s\n", lista2->cod2);
    //printf("Nome: %s\n",lista2->nome);
    //printf("Marca: %s\n", lista2->marca);
    printf("Quantidade: %s\n", lista2->qntd);
    printf("\n");
    lista2 = lista2->prox;
  }
}

NoVenda* listaInvertidaVenda(void) {
  FILE* fp;
  Venda* venda;
  NoVenda* noVend;
  NoVenda* lista3;

  lista3 = NULL;
  fp = fopen("venda.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }

  venda = (Venda*) malloc(sizeof(Venda));
  while(fread(venda, sizeof(Venda), 1, fp)) {
    if (venda->status == '1') {
      noVend = (NoVenda*) malloc(sizeof(NoVenda));
      strcpy(noVend->cod, venda->cod);
      //strcpy(noVend->nome, venda->nome);
      //strcpy(noVend->marca, venda->marca);
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
  printf("= = = = = = = = = = = = = = =\n");
  printf("= = Relatório de Vendas = = \n");
  printf("= = = = = = = = = = = = = = =\n");
  while (lista3 != NULL) {
    printf("\nCódigo do Produto: %s\n", lista3->cod);
    //printf("Nome: %s\n",lista3->nome);
    //printf("Marca: %s\n", lista3->marca);
    printf("Quantidade: %s\n", lista3->qntd);
    printf("\n");
    lista3 = lista3->prox;
  }
}


/*void listaClientes(void) {
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
    if (cliente->status == '1') {
      exibeCliente(cliente);
    }
  }
  fclose(fp);
  free(cliente);
  printf("Aperte a tecla ENTER para continuar. ");
  getchar();
  system("cls || clear");
}

void listaProdutos(void) {
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
  printf("= = Listagem de Produtos = = \n");
  printf("= = = = = = = = = = = \n");
  produto = (Prod*) malloc(sizeof(Prod));
  while(fread(produto, sizeof(Prod), 1, fp)) {
    if (produto->status == '1') {
      exibeProduto(produto);
    }
  }
  fclose(fp);
  free(produto);
  printf("Aperte a tecla ENTER para continuar. ");
  getchar();
  system("cls || clear");
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
  printf("= = = = = = = = = = = = = =\n");
  printf("= = Listagem de Compras = = \n");
  printf("= = = = = = = = = = = = = =\n");
  compra = (Compra*) malloc(sizeof(Compra));
  while(fread(compra, sizeof(Compra), 1, fp)) {
    if (compra->status == '1') {
      exibeCompra(compra);
    }
  }
  fclose(fp);
  free(compra);
  printf("Aperte a tecla ENTER para continuar. ");
  getchar();
  system("cls || clear");
}

void listaVendas(void) {
  FILE* fp;
  Venda* venda;
  fp = fopen("venda.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar o programa...\n");
    exit(1);
  }
  printf("\n\n");
  printf("= = = = = = = = = = = \n");
  printf("= = Listagem de Vendas = = \n");
  printf("= = = = = = = = = = = \n");
  venda = (Venda*) malloc(sizeof(Venda));
  while(fread(venda, sizeof(Venda), 1, fp)) {
    if (venda->status == '1') {
      exibeVenda(venda);
    }
  }
  fclose(fp);
  free(venda);
  printf("Aperte a tecla ENTER para continuar. ");
  getchar();
  system("cls || clear");
}*/

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
  printf("= = = = = = = = = = = = = = = = = = = \n");
  printf("= S O B R E = = = = = = = = \n");
  printf("= = = = = = = = = = = = = = = = = = = \n");
  printf("1 - Sobre\n");
  printf("0 - Retornar\n");
  printf("Escolha sua opção: ");
  scanf("%d", &op);
  system("cls || clear");
  return op;
}

void sobreOprograma(void){
    printf("\n\n");
    printf("    *============================= SOBRE O PROGRAMA ============================*\n");
    printf("    |                                                                           |\n");
    printf("    |PROGRAMA DE CONTROLE DE ESTOQUES CRIADO UTILIZANDO ALOCACAO DINAMICA,      |\n");
    printf("    |STRUCTS E PONTEIROS, COMO FORMA DE AVALIACAO DA DISCIPLINA DE PROGRAMAÇÃO, |\n");
    printf("    |DO PROFESSOR: FLAVIUS GORGONIO. APRESENTADO EM SALA DE AULA,               |\n");
    printf("    |COM A FINALIDADE DE OBTER NOTAS DE AVALIAÇÃO DA DISCIPLINA.                |\n");
    printf("    |                                                                           |\n");
    printf("    |                                                                           |\n");
    printf("    |                              IDENTIFICACAO                                |\n");
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

void dataEhora1(Compra* compra) {
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

int validacaoEhNumero(char c){
  if (c>='A' && c<='Z') {
      return 0;
    }
  else if (c>='a' && c<='z') {
      return 0;
    }
  else {
      return 1;
    }

}

int validacaoEhNumero1(char *preco) {
  if (strlen(preco) == 4){
    int tam = strlen(preco);
    for(int i = 0; i < tam; i++){
      char c = preco[i];
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


int validacaoEhNumero2(char *qntd) {
  if (strlen(qntd) == 4){
    int tam = strlen(qntd);
    for(int i = 0; i < tam; i++){
      char c = qntd[i];
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
            (strcmp(cpf,"99999999999") == 0))
        return 0;
    else
    {
        
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

  else if(strlen(telefone) == 9){
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
      return 0;}

  else if(strlen(codi) == 5){
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

int validacaoCod2(char *codi){
  if(strlen(codi) != 4){
      return 0;
      }

  else if((strcmp(codi,"0000") == 0) || (strcmp(codi,"1111") == 0) || (strcmp(codi,"2222") == 0) ||
          (strcmp(codi,"3333") == 0) || (strcmp(codi,"4444") == 0) || (strcmp(codi,"5555") == 0) ||
          (strcmp(codi,"6666") == 0) || (strcmp(codi,"7777") == 0) || (strcmp(codi,"8888") == 0) ||
          (strcmp(codi,"9999") == 0)){
      return 0;}

  else if(strlen(codi) == 4){
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


void dataEhora2(Venda* venda) {
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