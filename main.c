#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


#define quantCadastro 200

int menuCliente();
void cadastrarCliente();
void pesquisarCliente();
void atualizarCliente();
void deletarCliente();


char nomeCliente[quantCadastro] [50];
int dataDeNascimento[quantCadastro];
int cpfCliente[quantCadastro];
char enderecoCliente [quantCadastro] [50];
char emailCliente[quantCadastro] [50];
int telefoneCliente[quantCadastro] ;

	
int main (){
	int opcao;
	setlocale(LC_ALL, "portuguese");
	
	do{
		printf ("\t= = = = = = = = = = = = = = = = = =\n"
				"\t=   M E N U   P R I N C I P A L   =\n"
				"\t= = = = = = = = = = = = = = = = = =\n"
				"\n\t1 - Cliente\n"
				"\t2 - Produto\n"
				"\t3 - Controle de Compras\n"
				"\t4 - Controle de Vendas\n"
				"\t5 - Relatório\n"
				"\t6 - Sobre\n"
				"\t0 - Encerrar\n");
		printf("\n\tEscolha uma opção: ");
		scanf("%d", &opcao); 
		system("cls || clear");

		switch(opcao){
			case 1: 
				menuCliente();
				break;

			case 2:
				//menuProduto();
				break;

			case 3: 
				//menuControleDeCompras();
				break;
				
			case 4: 
				//menuControleDeVendas();
				break;

			case 5: 
				//menuRelatorio();
				break;

			case 6: 
				//menuSobre();
				break;

			case 0:
				return 0;
				break;

			default: 
				printf("Opção inválida, digite um número válido\n\n");
				break;
			
		}
	} while(opcao != 0);
	return 0;
}

int menuCliente(){
	
	int opcao;
	
	do{
		printf ("\t= = = = = = = = = = = = = = = = = = = = = =\n"
				"\t=   C A D A S T R O  D O  C L I E N T E   =\n"
				"\t= = = = = = = = = = = = = = = = = = = = = =\n"
				  "\n\t[1] - Cadastrar Cliente\n"
				  "\t[2] - Pesquisar Cliente\n"
				  "\t[3] - Atualizar Cliente\n"
				  "\t[4] - Deletar Cliente\n"
				  "\t[0] - Retornar\n");
		printf("\n\tEscolha uma opção: ");
		scanf("%d", &opcao);
		system("cls || clear");

		switch(opcao){
			case 1: 
				cadastrarCliente();
				break;

			case 2: 
				pesquisarCliente();
				break;

			case 3: 
				atualizarCliente();
				break;

			case 4: 
				deletarCliente();
				break;

			case 0: 
				return opcao;
				break;

			default: 
				printf("Opção inválida, digite um número válido\n\n");
				break;

			}
		} while(opcao != 0);
	return opcao;
}
void cadastrarCliente(){
	int opcao;
	static int linha;
	do{
		printf("\nNome: ");
		scanf("%s",&nomeCliente[linha][50]);
		printf("\nDigite a data de nascimento no formato dd/mm/aaaa: ");
		scanf("%d",&dataDeNascimento[linha]);
		printf("\nCPF: ");
		scanf("%d",&cpfCliente[linha]);
		printf("\nEndereço: ");
		scanf("%s",&enderecoCliente[linha][50]);
		printf("\nE-mail: ");
		scanf("%s",&emailCliente[linha][50]);
		printf("\nTelefone: ");
		scanf("%d",&telefoneCliente[linha]);
		printf("\nDigite 1 para continuar ou outro valor para sair: ");
		scanf("%d",&opcao);
		linha++;
		system("cls || clear");
		
		
	}while(opcao == 1);
	
}
void pesquisarCliente(){
	int cpfPesquisa;
	char emailPesquisa[50];
	int i;
	int opcao;
	do{
		printf (" Pesquisar por uma das opções abaixo\n\n"
				"[1] - CPF\n"
				"[2] - E-mail\n");
		switch(opcao){
			case 1:
				printf("CPF: ");
				scanf("%d",&cpfPesquisa);
				for (i = 0;i < quantCadastro; i++){
					if(cpfCliente[i]==cpfPesquisa){
						printf("\nNome: %s"
								"\nData de Nascimento: %d"
								"\nCPF: %d"
								"\nEndereço: %s"
								"\nE-mail: %s"
								"\nTelefone: %d",nomeCliente[i],dataDeNascimento[i],cpfCliente[i],enderecoCliente[i],emailCliente[i],telefoneCliente[i]);
					}
				}	
				break;
			
			case 2:
				printf("E-mail: ");
				scanf("%s",&emailPesquisa[50]);
				for (i = 0;i < quantCadastro; i++){
					if(strcmp(emailCliente[i], emailPesquisa)==0){
						printf("\nNome: %s"
								"\nData de Nascimento: %d"
								"\nCPF: %d"
								"\nEndereço: %s"
								"\nEmail: %s"
								"\nTelefone: %d",nomeCliente[i],dataDeNascimento[i],cpfCliente[i],enderecoCliente[i],emailCliente[i],telefoneCliente[i]);
					}
				
				}	
				break;
			default: 
				printf("Opção inválida, digite um número válido\n\n");
				break;
			
		}
		system("cls || clear");
		printf("\nDigite 1 para continuar pesquisando ou outro valor para sair: ");
		scanf("%d",&opcao);
		
	}while(opcao == 1);
	
}

void atualizarCliente(){
	int opcao;
	do{
	printf("Em Construção");
	system("cls || clear");
	printf("\nDigite 1 para continuar atualizando ou outro valor para sair: ");
	scanf("%d",&opcao);
	}while(opcao == 1);
	
}


void deletarCliente(){
	int opcao;
	do{
	printf("Em Construção");
	
	printf("\nDigite 1 para deletar novamente ou outro valor para sair: ");
	scanf("%d",&opcao);
	system("cls || clear");
	}while(opcao == 1);
}
