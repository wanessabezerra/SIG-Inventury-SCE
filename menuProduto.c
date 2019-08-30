#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int menuProduto(){
	int opcao;
	
	do {
		printf ("\t= = = = = = = = = = = = = = = = = = = = = =\n"
				"\t=   C A D A S T R O  D O  P R O D U T O   =\n"
				"\t= = = = = = = = = = = = = = = = = = = = = =\n"
				  "\n\t1 - Cadastrar Produto\n"
				  "\t2 - Atualizar Produto\n"
				  "\t3 - Pesquisar Produto\n"
				  "\t4 - Deletar Produto\n"
				  "\t0 - Retornar\n");
		printf("\n\tEscolha uma opção: ");
		scanf("%d", &opcao);	
		system("cls || clear");
		
		switch(opcao){
			case 1: 
				cadastrarProduto();
				break;

			case 2: 
				pesquisarProduto();
				break;

			case 3: 
				atualizarProduto();
				break;

			case 4: 
				deletarProduto();
				break;

			case 0: 
				return 0;
				break;

			default: 
				printf("Opção inválida, digite um número válido\n\n");
				break;

			opcao = menuProduto();
		}
	} while(opcao != 0);
	return opcao;
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
