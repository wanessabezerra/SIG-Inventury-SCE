#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int menuSobre(){
	int opcao;
	
	do{
		printf ("\t= = = = = = = = = = = = = = = = = = = = = = =\n"
				  "\t=   M U R A L  D E  I N F O R M A Ç Õ E S   =\n"
				  "\t= = = = = = = = = = = = = = = = = = = = = = = \n"
					"\n\t1 - Quem somos\n"
					"\t2 - Contato\n"
					"\t3 - Informações do Programa\n"
					"\t0 - Retornar\n");
		printf("\n\tEscolha uma opção: ");
		scanf("%d", &opcao);
		system("cls || clear");
		
		switch(opcao){
			case 1: 
				quemSomos();
				break;

			case 2: 
				contato();
				break;

			case 3: 
				inforPrograma();
				break;

			case 0: 
				return 0;
				break;

			default: 
				printf("Opção inválida, digite um número válido\n\n");
				break;

			opcao = menuSobre();
		}
	} while(opcao != 0);
	return opcao;
}


///////////////////////////////////////
//// F U N Ç Õ E S  D O  S O B R E ////
///////////////////////////////////////


int quemSomos(){
	printf("Em Construção");
	return 0;
}


int contato(){
	printf("Em Construção");
	return 0;
}


int inforPrograma(){
	printf("Em Construção");
	return 0;
}
