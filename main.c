#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
//#include "funcoesDeValidacao"


typedef struct clt Cliente;

struct clt {
  char nome[20];
  char nasc[11];
  char cpf[12];
  char email[20];
  char telefone[12];
  char status;
};

typedef struct produt Prod;

struct produt {
  char cod[6];
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
void exibeProduto(Prod*);
void gravaProduto(Prod*);

int menuPrincipalRelatorio(void);
int menuRelatorio(void);
void listaClientes(void);
void listaProdutos(void);
void listaVendas(void);

int ehLetra(char);

int validacaoCpf(char *);
int validacaoEmail( const char *);
int validacaoTelefone(char *);


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
    Cliente* cliente;
    printf("\n\n");
    printf("= = = = = = = = = = = = =\n");
    printf("= = Cadastrar Cliente = =\n");
    printf("= = = = = = = = = = = = =\n");
    cliente = (Cliente*) malloc(sizeof(Cliente));
    printf("\nNome: ");
    scanf(" %19[^\n]", cliente->nome);
    printf("Data de nascimento (dd/mm/aaaa): ");
    scanf(" %10[^\n]", cliente->nasc);
    getchar();

    printf("CPF: ");
    scanf("%11s", cliente->cpf);
    while((validacaoCpf(cliente->cpf)!=1)) {
      printf("\nNúmero inválido, tente novamente.\n");
      printf("CPF: ");
      scanf("%11s", cliente->cpf);
    }

    printf("E-mail: ");
    scanf(" %19[^\n]", cliente->email);
    while(!(validacaoEmail(cliente->email))) {
      printf("\nE-mail inválido, tente novamente.\n");
      printf("E-mail: ");
      scanf(" %19[^\n]", cliente->email);
    }
    
    printf("\nTelefone: ");
    scanf("%9s", cliente->telefone);
    getchar();
    while((validacaoTelefone(cliente->telefone)!=1)) {
      printf("\nTelefone inválido, tente novamente.\n");
      printf("\nTelefone: ");
      scanf("%9s", cliente->telefone);
    }

    cliente->status = '1';
    gravaCliente(cliente);
    system("cls || clear");
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
        if ((strcmp(cliente->nome, procurado) == 0) && (cliente->status == '1')) {
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
        if ((strcmp(cliente->nome, procurado) == 0) && (cliente->status == '1')) {
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
            scanf(" %19[^\n]", cliente->nome);
            printf("Data de nascimento (dd/mm/aaaa): ");
            scanf(" %10[^\n]", cliente->nasc);
            getchar();
            printf("CPF: ");
            scanf("%15s", cliente->cpf);
            while((validacaoCpf(cliente->cpf)!=1)) {
              printf("\nCPF: ");
              scanf("%15s", cliente->cpf);
            }
            printf("E-mail: ");
            scanf(" %19[^\n]", cliente->email);
            printf("Telefone: ");
            scanf(" %11[^\n]", cliente->telefone
        );
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
        if ((strcmp(cliente->nome, procurado) == 0) && (cliente->status == '1')) {
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
    printf("Nascimento: %s\n", cliente->nasc);
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
  scanf("%5s ", produto->cod);
  printf("Informe o nome do produto: ");
  scanf(" %14[^\n]", produto->nome);
  printf("Informe a marca do produto: ");
  scanf(" %14[^\n]", produto->marca);
  printf("Informe a quantidade do produto: ");
  scanf("%d", &produto->quant);
  getchar();
  produto->status = '1';
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
  printf("= = = = = = = = = = = \n");
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
      scanf("%5s", produto->cod);
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
  printf("Quantidade: %d\n", produto->quant);
  printf("\n");
}


/////////////// menu relatório /////////////////////
int menuPrincipalRelatorio(void){
    int opcao;
    opcao = menuRelatorio();
    while (opcao != 0) {
        switch (opcao) {
            case 1 :  listaClientes();
                    break;
            case 2 :  listaProdutos();
                    break;
            //case 3 :  listaCompras();
                    break;
            //case 4 :  listaVendas();
                    break;
            case 0 : return 0;
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
            "\n[1] - Lista de Clientes\n"
            "[2] - Lista de Produtos\n"
            "[3] - Listar todos as Compras\n"
            "[4] - Listar todos as Vendas\n"
            "[5] - Relatórios\n"
            "[0] - Retornar\n");
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
    if (cliente->status == '1') {
      exibeCliente(cliente);
    }
  }
  fclose(fp);
  free(cliente);
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
}
/*
void listaCompras(void) {
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
  printf("= = Listagem de Compras = = \n");
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
  venda = (Prod*) malloc(sizeof(Prod));
  while(fread(venda, sizeof(Prod), 1, fp)) {
    if (venda->status == '1') {
      exibeVenda(venda);
    }
  }
  fclose(fp);
  free(venda);
}
*/ 
int validacaoEhNumero(char c) {
  if (c>='0'&& c<='9') {
    return 1;
  }
  else {
    return 0;
  }
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
