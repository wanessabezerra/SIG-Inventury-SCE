#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


typedef struct client Cliente;

struct client {
  char nomeCliente[20];
  char nascCliente[11];
  int cpfCliente[12];
  char emailCliente[20];
  int telefoneCliente[12];
  char statusCliente;
};

int menuPrincipal(void);
int menuPrincipalCliente(void);
int menuCliente(void);
void cadastraCliente(void);
void buscaCliente(void);
//void editaCliente(void);
void excluiCliente(void);
void exibeCliente(Cliente*);
void gravaCliente(Cliente*);

//void listaCliente(void);

int ehLetra(char);


int main(void) {
    setlocale(LC_ALL, "portuguese");
    int opcao;
    opcao = menuPrincipal();
    while (opcao != 0) {
        switch (opcao) {
            case 1 :  menuPrincipalCliente();
                    break;
            //case 2 :  menuPrincipalProduto();
                    break;
            case 0 : return 0;
                    break;
            default : printf("Opção inválida, digite um número válido\n\n");
                    break;
            
            //case 3 :  edita();
                    break;
            //case 4 :  excluiP(;
                    break;
            //case 5 :  lista();
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
    printf("Escolha sua opção: ");
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
            //case 3 :  editaCliente();
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
    printf("Escolha sua opção: ");
    scanf("%d", &opcao);
    system("cls || clear");
    return opcao;
}


void cadastraCliente(void) {
    Cliente* cliente;
    printf("\n\n");
    printf("= = = = = = = = = = = \n");
    printf("= Cadastrar Cliente  = \n");
    printf("= = = = = = = = = = = \n");
    cliente = (Cliente*) malloc(sizeof(Cliente));
    printf("Nome: ");
    scanf(" %19[^\n]", cliente->nomeCliente);

    //while(ehLetra()!= cliente ){
       // printf("Nome: ");
        //scanf(" %19[^\n]", cliente->nomeCliente);}

    printf("Data de nascimento (dd/mm/aaaa): ");
    scanf(" %10[^\n]", cliente->nascCliente);
    getchar();
    printf("CPF: ");
    scanf(" %11[^\n]", &cliente->cpfCliente);
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
    printf("= = = = = = = = = = = \n");
    printf("= = Excluir cliente = = \n");
    printf("= = = = = = = = = = = \n");
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
    printf("Telefone: %d\n", cliente->telefoneCliente);
    printf("liente: %c\n", cliente->statusCliente);
    printf("\n");
}

int ehLetra(char c) {
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
