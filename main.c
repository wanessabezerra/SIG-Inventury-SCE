#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


#define quantCadastro 200

void telaMenuPrincipal();
void telaMenuCliente();
void telaMenuProduto();
void telaMenuControleDeEstoque();
void telaMenuRelatorio();
void telaMenuSobre();


int menuPrincipal();
int menuCliente();
int menuProduto();
int menuControleDeEstoque();
int menuRelatorio();
int menuSobre();


int cadastrarCliente();
int pesquisarCliente();
int atualizarCliente();
int deletarCliente();


int cadastrarProduto();
int pesquisarProduto();
int atualizarProduto();
int deletarProduto();


int cadastrarCompra();
int pesquisarCompra();
int atualizarCompra();


int cadastrarVenda();
int pesquisarVenda();
int atualizarVenda();


int relatorioDosClientes();
int relatorioDosProdutos();
int relatorioDasCompra();
int relatorioDasVenda();


int quemSomos();
int contato();
int inforPrograma();

int validacaoEhNumero(char);
int validacaoEhLetra(char);

struct cliente {
		char nomeCliente[quantCadastro] [50];
		char marca[quantCadastro] [50];
		char rua[quantCadastro] [50];
		char email[quantCadastro] [50];
		int dataDeNascimento[quantCadastro];
		int cpf[quantCadastro];
	};

struct produto {
		char nomeProduto[quantCadastro] [50];
		char codigoProduto[quantCadastro] [6];
		char descricao[quantCadastro] [501];
		char marca[quantCadastro] [50];
		char fornecedor[quantCadastro] [50];
		int dataDeCompra[quantCadastro];
		int dataDeValidade[quantCadastro];
		int quantidade[quantCadastro];
		int precoDeCompra[quantCadastro];
		int precoDeVenda[quantCadastro];
		int precoDeEstMax[quantCadastro];
		int precoDeEstMin[quantCadastro];
		int ativo [quantCadastro];
	};


int main (void){
	int opcao;
	system("clear");
	setlocale(LC_ALL, "portuguese");
	opcao = menuPrincipal();

	while(opcao != 0){
		switch(opcao){
			case 1: {
				system("clear");
				menuCliente();
				break;}

			case 2:{
				system("clear");
				menuProduto();
				break;}

			case 3: {
				system("clear");
				menuControleDeEstoque();
				break;}

			case 4: { 
				system("clear");
				menuRelatorio();
				break;}

			case 5: {
				system("clear");
				menuSobre();
				break;}

			case 0: {
				system("clear");
				return 0;
				break;}

			default: {
				system("clear");
				printf("Opção inválida, digite um número válido\n\n");
				break;}
			opcao = menuPrincipal();
		}
	}
}

void telaMenuCliente(){
	
}

void telaMenuProduto(){
	printf ("\t= = = = = = = = = = = = = = = = = = = = = =\n"
			"\t=   C A D A S T R O  D O  P R O D U T O   =\n"
			"\t= = = = = = = = = = = = = = = = = = = = = =\n"
			  "\n\t1 - Cadastrar Produto\n"
			  "\t2 - Atualizar Produto\n"
			  "\t3 - Pesquisar Produto\n"
			  "\t4 - Deletar Produto\n"
			  "\t0 - Retornar\n");
}

void telaMenuControleDeEstoque(){
	printf("\t= = = = = = = = = = = = = = = = = = = =\n"
			"\t= C O N T R O L E  D E  E S T O Q U E =\n"
			"\t= = = = = = = = = = = = = = = = = = = =\n"
			  "\n\t1 - Efetuar Compra\n"
			  "\t2 - Efetuar Venda\n"
			  "\t3 - Pesquisar Compra\n"
			  "\t4 - Pesquisar Venda\n"
			  "\t5 - Atualizar Compra\n"
			  "\t6 - Atualizar Venda\n"
			  "\t0 - Retornar\n");
}

void telaMenuRelatorio(){
	printf("\t= = = = = = = = = = = = = = \n"
			"\t=   R E L A T Ó R I O S   =\n"
			"\t= = = = = = = = = = = = = =\n"
			  "\n\t1 - Relatório de Clientes\n"
			  "\t2 - Relatório de Produtos\n"
			  "\t3 - Relatório de Compras\n"
			  "\t4 - Relatório de Vendas\n"
			  "\t0 - Retornar\n");
}

void telaMenuSobre(){
  printf ("\t= = = = = = = = = = = = = = = = = = = = = = =\n"
          "\t=   M U R A L  D E  I N F O R M A Ç Õ E S   =\n"
          "\t= = = = = = = = = = = = = = = = = = = = = = = \n"
            "\n\t1 - Quem somos\n"
            "\t2 - Contato\n"
            "\t3 - Informações do Programa\n"
            "\t0 - Retornar\n");
}

int menuPrincipal(void){
	int opcao;
	system("clear");
	printf("\t= = = = = = = = = = = = = = = = = =\n"
			"\t=   M E N U   P R I N C I P A L   =\n"
			"\t= = = = = = = = = = = = = = = = = =\n"
			"\n\t1 - Cliente\n"
			"\t2 - Produto\n"
			"\t3 - Controle de Estoque\n"
			"\t4 - Relatório\n"
			"\t5 - Sobre\n"
			"\t0 - Encerrar\n");
	printf("\n\tEscolha uma opção: ");
	scanf("%d", &opcao); 
	return opcao;
}



int menuCliente(){
	int opcao;
	system("clear");
	printf ("\t= = = = = = = = = = = = = = = = = = = = = =\n"
			"\t=   C A D A S T R O  D O  C L I E N T E   =\n"
			"\t= = = = = = = = = = = = = = = = = = = = = =\n"
			  "\n\t1 - Cadastrar Cliente\n"
			  "\t2 - Atualizar Cliente\n"
			  "\t3 - Pesquisar Cliente\n"
			  "\t4 - Deletar Cliente\n"
			  "\t0 - Retornar\n");
	printf("\n\tEscolha uma opção: ");
	scanf("%d", &opcao);


	while(opcao != 0){
    	switch(opcao){
      		case 1: {
				system("clear");
				cadastrarCliente();
				break;}

      		case 2: {
				system("clear");
				pesquisarCliente();
				break;}
      
      		case 3: {
				system("clear");
				atualizarCliente();
				break;}
      
      		case 4: {
				system("clear");
				deletarCliente();
				break;}
			case 0: {
				system ("clear");
				break;
			}

			default: {
				system("clear");
				break;}
      
      	return opcao;
		}
	opcao = menuCliente();
  }
}


int menuProduto(){
	int opcao;
	system("clear");
	telaMenuProduto();
	printf("\n\tEscolha uma opção: ");
	scanf("%d", &opcao);	
	opcao = menuProduto();
	while(opcao != 0){
    switch(opcao){
      case 1: {
				system("clear");
				cadastrarProduto();
				break;}

      case 2: {
				system("clear");
				pesquisarProduto();
				break;}
      
      case 3: {
				system("clear");
				atualizarProduto();
				break;}
      
      case 4: {
				system("clear");
				deletarProduto();
				break;}

      case 0: {
				system("clear");
				return 0;
				break;}

			default: {
				system("clear");
				printf("Opção inválida, digite um número válido\n\n");
				break;}
      
			opcao = menuCliente();
      return opcao;
		}
  }
}

int menuControleDeEstoque(){
	int opcao;
	system("clear");
	telaMenuControleDeEstoque();
	printf("\n\tEscolha uma opção: ");
	scanf("%d", &opcao);
	do{

		} while(opcao != 0);
	return opcao;
}

int menuRelatorio(){
	int opcao;
	system("clear");
	telaMenuRelatorio();
	printf("\n\tEscolha uma opção: ");
	scanf("%d", &opcao);
	do{

		} while(opcao != 0);
	return opcao;
}

int menuSobre(){
	int opcao;
	system("clear");
	telaMenuSobre();
	printf("\n\tEscolha uma opção: ");
	scanf("%d", &opcao);
	do{

		} while(opcao != 0);
	return opcao;
}


///////////////////////////////////////////
//// F U N Ç Õ E S  D O  C L I E N T E ////
///////////////////////////////////////////


int cadastrarCliente(){
	printf("Em Construção");
	return 0;
}


int pesquisarCliente(){
	printf("Em Construção");
	return 0;
}


int atualizarCliente(){
	printf("Em Construção");
	return 0;
}


int deletarCliente(){
	printf("Em Construção");
	return 0;
}

int retornarCliente(){
	printf("retornando");
	return 0;
}

///////////////////////////////////////////
//// F U N Ç Õ E S  D O  P R O D U T O ////
///////////////////////////////////////////

int cadastrarProduto(){
	printf("Em Construção");
	return 0;
}


int pesquisarProduto(){
	printf("Em Construção");
	return 0;
}


int atualizarProduto(){
	printf("Em Construção");
	return 0;
}


int deletarProduto(){
	printf("Em Construção");
	return 0;
}


/////////////////////////////////////////////////////////////////
//// F U N Ç Õ E S  D O  C O N T R O L E  D E  E S T O Q U E ////
/////////////////////////////////////////////////////////////////


int cadastrarCompra(){
	printf("Em Construção");
	return 0;
	
}


int pesquisarCompra(){
	printf("Em Construção");
	return 0;
}


int atualizarCompra(){
	printf("Em Construção");
	return 0;
}


int cadastrarVenda(){
	printf("Em Construção");
	return 0;
}


int pesquisarVenda(){
	printf("Em Construção");
	return 0;
}


int atualizarVenda(){
	printf("Em Construção");
	return 0;
}


///////////////////////////////////////////////////
//// F U N Ç Õ E S  D O S  R E L A T Ó R I O S ////
///////////////////////////////////////////////////


int relatorioDosClientes(){
	printf("Em Construção");
	return 0;
}


int relatorioDosProdutos(){
	printf("Em Construção");
	return 0;
}


int relatorioDasCompra(){
	printf("Em Construção");
	return 0;
}


int relatorioDasVenda(){
	printf("Em Construção");
	return 0;
}



///////////////////////////////////////
//// F U N Ç Õ E S  D O  S O B R E ////
///////////////////////////////////////


int quemSomos(){
	printf("Em Construção");
	return 0;
}


int contato(){
	printf("Em Construção");
	return 0;
}


int inforPrograma(){
	printf("Em Construção");
	return 0;
}

///////////////////////////////////////////////
//// F U N Ç Õ E S  D E  V A L I D A Ç A O ////
///////////////////////////////////////////////

int validacaoEhNumero(char c) {
  if (c>='0'&& c<='9') {
    return 1;
  }
  else 
    return 0;
  
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
