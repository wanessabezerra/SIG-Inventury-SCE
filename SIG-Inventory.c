#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <unistd.h>

#define quantCadastro 200

char produto[quantCadastro] [50];
int codigoProduto [quantCadastro];


int main (void){
	system("cls");
	setlocale(LC_ALL, "portuguese");
int opcao1;
	do{
		printf ("\t= = = = = = = = = = = = = = = =\n"
				"\t= M E N U   P R I N C I P A L =\n"
				"\t= = = = = = = = = = = = = = = =\n"
				  "\n\t1 - Cadastrar Cliente\n"
				  "\t2 - Cadastrar Estoque\n"
				  "\t3 - Relatório\n"
				  "\t4 - Contato\n"
				  "\t0 - Encerrar\n");
		printf("\n\tEscolha uma opção: ");
		scanf("%d", &opcao1);
		
		switch(opcao1){
			case 1: 
				system("cls");
				
				
				break;
			case 2: 
				system("cls");
				
				
				break;
				
			case 3: 
				system("cls");
				
				
				break;
			
			case 4: 
				system("cls");
			
				
				
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

void cadastroDeProdutos(){
	static int linha;
	do {
		printf("\nDigite o nome do produto: ");
		scanf("%s"),&produto[linha];
		printf("\nDigite o codígo do produto: ");
		scanf("%d", &codigoProduto[linha];
		
	} while(); 
	
	
	
}


void clearScreen(void)
{
	const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J"; 
	write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}
