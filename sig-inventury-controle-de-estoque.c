#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>

#define quantCadastro 200

void menuPrincipal();
void menuCadastrarProduto();
void menuEstoque();
void menuRelatorio();
void menuSobre();

int opcao1;
int opcao2;
//int opcao3;

struct produto {
		char nomeProduto[quantCadastro] [50];
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



int opcao1;
	do{
		menuPrincipal();
		switch(opcao1){
			case 1: 
				void menuCadastrarProduto();
				
				break;
			case 2: 
				system("cls");
				void menuEstoque();
				
				break;
				
			case 3: 
				system("cls");
				void menuRelatorio();
				
				break;
			
			case 4: 
				system("cls");
			  void menuSobre();
				
				
				break;
			
			case 0: 
				system("cls");
				return 0;
				break;
				
			default:
				system("cls");
				printf("Opção inválida, digite um número válido\n\n");
				break;
	
	}
	} while(opcao1 != 0);
	return 0;
}

void menuPrincipal(){
	system("cls");
	int opcao1;
	do{
		printf ("\t= = = = = = = = = = = = = = = =\n"
				"\t= M E N U   P R I N C I P A L =\n"
				"\t= = = = = = = = = = = = = = = =\n"
				  "\n\t1 - Cadastrar Produto\n"
				  "\t2 - Estoque\n"
				  "\t3 - Relatório\n"
				  "\t4 - Contato\n"
				  "\t0 - Encerrar\n");
		printf("\n\tEscolha uma opção: ");
		scanf("%d", &opcao1);
		
	}while(opcao1 != 0);
}

void menuCadastrarProduto(){
	system("cls");
	int opcao2;
	do{
		printf ("\t= = = = = = = = = = = = = = = = = = = =\n"
				"\t= C A D A S T R O  D O  P R O D U T O =\n"
				"\t= = = = = = = = = = = = = = = = = = = =\n"
				  "\n\t1 - Cadastrar Produto\n"
				  "\t2 - Estoque\n"
				  "\t3 - Relatório\n"
				  "\t4 - Contato\n"
				  "\t0 - Retornar\n");
		printf("\n\tEscolha uma opção: ");
		scanf("%d", &opcao2);
		
		
	} while(opca2 != 0);
}

void menuRelatorio(){
	do{
	} while(opcao3 != 0);
}

void menuSobre(opcao4 != 0){
	do{
	} while();
}


void cadastroDeProdutos(){
	static int linha;
	do {
		printf("\nDigite o nome do produto: ");
		scanf("%s"),&produto[linha];
		printf("\nDigite o codígo do produto: ");
		scanf("%d", &codigoProduto[linha];
		
	} while(); 
	}
}


void clearScreen(void)
{
	const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J"; 
	write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}