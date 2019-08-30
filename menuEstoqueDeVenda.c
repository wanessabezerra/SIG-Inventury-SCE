#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int menuControleDeVendas(){
	int opcao;
	
	do{
		printf("\t= = = = = = = = = = = = = = = = = = = = =\n"
				"\t=   C O N T R O L E  D E  V E N D A S   =\n"
				"\t= = = = = = = = = = = = = = = = = = = = =\n"
				  "\n\t1 - Efetuar Venda\n"
				  "\t2 - Pesquisar Venda\n"
				  "\t3 - Atualizar Venda\n"
				  "\t0 - Retornar\n");
		printf("\n\tEscolha uma opção: ");
		scanf("%d", &opcao);
		system("cls || clear");
		
		switch(opcao){
			case 1: 
				cadastrarVenda();
				break;

			case 2: 
				pesquisarVenda();
				break;

			case 3: 
				atualizarVenda();
				break;

			case 0: 
				return 0;
				break;

			default: 
				printf("Opção inválida, digite um número válido\n\n");
				break;

			opcao = menuControleDeVendas();
		}
	} while(opcao != 0);
	return opcao;
}


/////////////////////////////////////////////////////////////
//// F U N Ç Õ E S  D O  C O N T R O L E  D E  V E N D A ////
/////////////////////////////////////////////////////////////


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

