#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int menuRelatorio(){
	int opcao;
	
	do{
		printf("\t= = = = = = = = = = = = = = \n"
				"\t=   R E L A T Ó R I O S   =\n"
				"\t= = = = = = = = = = = = = =\n"
				  "\n\t1 - Relatório de Clientes\n"
				  "\t2 - Relatório de Produtos\n"
				  "\t3 - Relatório de Compras\n"
				  "\t4 - Relatório de Vendas\n"
				  "\t0 - Retornar\n");
		printf("\n\tEscolha uma opção: ");
		scanf("%d", &opcao);
		system("cls || clear");
		
		switch(opcao){
			case 1: 
				relatorioDeClientes();
				break;

			case 2: 
				relatorioDeProdutos();
				break;

			case 3: 
				relatorioDeCompra();
				break;
				
			case 4: 
				relatorioDeVenda();
				break;

			case 0: 
				return 0;
				break;

			default: 
				printf("Opção inválida, digite um número válido\n\n");
				break;

			opcao = menuRelatorio();
		}
	} while(opcao != 0);
	return opcao;
}


///////////////////////////////////////////////////
//// F U N Ç Õ E S  D O S  R E L A T Ó R I O S ////
///////////////////////////////////////////////////


int relatorioDeClientes(){
	printf("Em Construção");
	return 0;
}


int relatorioDeProdutos(){
	printf("Em Construção");
	return 0;
}


int relatorioDeCompra(){
	printf("Em Construção");
	return 0;
}


int relatorioDeVenda(){
	printf("Em Construção");
	return 0;
}
