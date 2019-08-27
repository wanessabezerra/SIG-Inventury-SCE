#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>


#define quantCadastro 200


void menuPrincipal();
void menuCliente();
void menuProduto();
void menuControleDeEstoque();
void menuRelatorio();
void menuSobre();


void cadastrarCliente();
void pesquisarCliente();
void atualizarCliente();
void deletarCliente();


void cadastrarProduto();
void pesquisarProduto();
void atualizarProduto();
void deletarProduto();


void cadastrarCompra();
void pesquisarCompra();
void atualizarCompra();


void cadastrarVenda();
void pesquisarVenda();
void atualizarVenda();


void relatorioDosClientes();
void relatorioDosProdutos();
void relatorioDasCompra();
void relatorioDasVenda();


void quemSomos();
void contato();


int opcao1;
int opcao2;
int opcao3;
int opcao4;
int opcao5;
int opcao6;
int opcao7; 


struct cliente {
		char nomeCliente[quantCadastro] [50];
		char marca[quantCadastro] [50];
		char rua[quantCadastro] [50];
		char email[quantCadastro] [50];
		int dataDeNascimento[quantCadastro];
		int  cpf[quantCadastro];
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
	system("cls");
	setlocale(LC_ALL, "portuguese");

	do{
		menuPrincipal();
		switch(opcao1){
			case 1: {
        system("cls");
				void menuCliente();

				break;}

			case 2:{
        system("cls");
				void menuProduto();
				
				break;}
	
			case 3: {
        system("cls");
				void menuControleDeEstoque();
				
				break;}
				
			case 4: { 
        system("cls");
				void menuRelatorio();
				
				break;}
			
			case 5: {
        system("cls");
				void menuSobre();
				
				break;}
			
			case 0: {
				system("cls");
				return 0;
				break;}
				
			default: {
				system("cls");
				printf("Opção inválida, digite um número válido\n\n");
				break;}
			}
		} while(opcao1 != 0);
	return 0;
}


void menuPrincipal(){
	system("cls");
	do{
		printf ("\t= = = = = = = = = = = = = = = =\n"
				"\t= M E N U   P R I N C I P A L =\n"
				"\t= = = = = = = = = = = = = = = =\n"
				  "\n\t1 - Cadastrar Cliente\n"
				  "\t2 - Cadastrar Produto\n"
				  "\t3 - Controle de Estoque\n"
				  "\t4 - Relatório\n"
				  "\t5 - Sobre\n"
				  "\t0 - Encerrar\n");
		printf("\n\tEscolha uma opção: ");
		scanf("%d", &opcao2);
		
		}while(opcao2 != 0);
}

void menuCliente(){
	system("cls");
	do{
		printf ("\t= = = = = = = = = = = = = = = = = = = =\n"
				"\t= C A D A S T R O  D O  C L I E N T E =\n"
				"\t= = = = = = = = = = = = = = = = = = = =\n"
				  "\n\t1 - Cadastrar Cliente\n"
				  "\t2 - Atualizar Cliente\n"
				  "\t3 - Pesquisar Cliente\n"
				  "\t4 - Deletar Cliente\n"
				  "\t0 - Retornar\n");
		printf("\n\tEscolha uma opção: ");
		scanf("%d", &opcao3);
		
		} while(opcao3 != 0);
}


void menuProduto(){
	system("cls");
	do{
		printf ("\t= = = = = = = = = = = = = = = = = = = =\n"
				"\t= C A D A S T R O  D O  P R O D U T O =\n"
				"\t= = = = = = = = = = = = = = = = = = = =\n"
				  "\n\t1 - Cadastrar Produto\n"
				  "\t2 - Atualizar Produto\n"
				  "\t3 - Pesquisar Produto\n"
				  "\t4 - Deletar Produto\n"
				  "\t0 - Retornar\n");
		printf("\n\tEscolha uma opção: ");
		scanf("%d", &opcao4);	
		} while(opcao4 != 0);
}

void menuControleDeEstoque(){
	system("cls");
	do{
		printf ("\t= = = = = = = = = = = = = = = = = = = =\n"
				"\t= C O N T R O L E  D E  E S T O Q U E =\n"
				"\t= = = = = = = = = = = = = = = = = = = =\n"
				  "\n\t1 - Efetuar Compra\n"
				  "\t2 - Efetuar Venda\n"
				  "\t3 - Pesquisar Compra\n"
				  "\t4 - Pesquisar Venda\n"
				  "\t5 - Atualizar Compra\n"
				  "\t6 - Atualizar Venda\n"
				  "\t0 - Retornar\n");
		printf("\n\tEscolha uma opção: ");
		scanf("%d", &opcao5);
		} while(opcao5 != 0);
	}

void menuRelatorio(){
	system("cls");
	do{
		printf ("\t= = = = = = = = = = = = = = = = = = = =\n"
				"\t= C O N T R O L E  D E  E S T O Q U E =\n"
				"\t= = = = = = = = = = = = = = = = = = = =\n"
				  "\n\t1 - Relatório de Clientes\n"
				  "\t2 - Relatório de Produtos\n"
				  "\t3 - Relatório de Compras\n"
				  "\t4 - Relatório de Vendas\n"
				  "\t0 - Retornar\n");
		printf("\n\tEscolha uma opção: ");
		scanf("%d", &opcao6);
		} while(opcao6 != 0);
}

void menuSobre(){
	system("cls");
	do{
		printf ("\t= = = = = = = = = = = = = = = = = = = = =\n"
				"\t= M U R A L  D E  I N F O R M A Ç Õ E S =\n"
				"\t= = = = = = = = = = = = = = = = = = = = = \n"
				  "\n\t1 - Quem somos\n"
				  "\t2 - Contato\n"
				  "\t3 - Informações do Programa\n"
				  "\t0 - Retornar\n");
		printf("\n\tEscolha uma opção: ");
		scanf("%d", &opcao7);
		} while(opcao7 != 0);
}
