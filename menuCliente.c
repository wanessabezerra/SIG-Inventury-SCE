#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "menuCliente.h"

int menuCliente(){
	int opcao;
	
	do{
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
				
			opcao = menuCliente();
		}
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

