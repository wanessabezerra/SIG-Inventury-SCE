#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int menuControleDeCompras(){
	int opcao;
	
	do{
		printf("\t= = = = = = = = = = = = = = = = = = = = = =\n"
				"\t=   C O N T R O L E  D E  C O M P R A S   =\n"
				"\t= = = = = = = = = = = = = = = = = = = = = =\n"
				  "\n\t1 - Efetuar Compra\n"
				  "\t2 - Pesquisar Compra\n"
				  "\t3 - Atualizar Compra\n"
				  "\t0 - Retornar\n");
		printf("\n\tEscolha uma opção: ");
		scanf("%d", &opcao);
		system("cls || clear");
		
		switch(opcao){
			case 1: 
				cadastrarCompra();
				break;

			case 2: 
				pesquisarCompra();
				break;

			case 3: 
				atualizarCompra();
				break;

			case 0: 
				return 0;
				break;

			default: 
				printf("Opção inválida, digite um número válido\n\n");
				break;

			opcao = menuControleDeCompras();
		}
	} while(opcao != 0);
	return opcao;
}


///////////////////////////////////////////////////////////////
//// F U N Ç Õ E S  D O  C O N T R O L E  D E  C O M P R A ////
///////////////////////////////////////////////////////////////


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
