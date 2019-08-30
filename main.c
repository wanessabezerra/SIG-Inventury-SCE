#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "menuCliente.h"
#include "menuProduto.h"
#include "menuEstoqueDeCompra.h"
#include "menuEstoqueDeVenda.h"
#include "menuRelatorio.h"
#include "menuSobre.h"
#include "funcoesDeValidacao.h" 

int main (){
	int opcao;
	setlocale(LC_ALL, "portuguese");
	
	do{
		printf ("\t= = = = = = = = = = = = = = = = = =\n"
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
		system("cls || clear");

		switch(opcao){
			case 1: 
				menuCliente();
				break;

			case 2:
				//menuProduto();
				break;

			case 3: 
				//menuControleDeEstoque();
				break;

			case 4: 
				//menuRelatorio();
				break;

			case 5: 
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
}
