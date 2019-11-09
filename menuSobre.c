#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menuSobre(void);
void sobreOprograma(void);

int main(void) {
  int opcao;
  opcao = menuSobre();
  while (opcao != 0) {
    switch (opcao) {
      case 1 :  sobreOprograma();
                break;
    }
    opcao = menuSobre();
  }
  printf("\nFim do programa!\n\n");
  return 0;
}

int menuSobre(void) {
  int op;
  printf("\n\n");
  printf("= = = = = = = = = = = = = = = = = = = \n");
  printf("= = = = = = = = Sobre = = = = = = = = \n");
  printf("= = = = = = = = = = = = = = = = = = = \n");
  printf("1 - Sobre\n");
  printf("0 - Retornar\n");
  printf("Escolha sua opção: ");
  scanf("%d", &op);
  system("cls || clear");
  return op;
}

void sobreOprograma(void){
  printf("\n\n");
  printf("    *============================= SOBRE O PROGRAMA ============================*\n");
  printf("    |                                                                           |\n");
  printf("    |PROGRAMA DE CONTROLE DE ESTOQUES CRIADO UTILIZANDO ALOCACAO DINAMICA,      |\n");
  printf("    |STRUCTS E PONTEIROS, COMO FORMA DE AVALIACAO DA DISCIPLINA DE PROGRAMAÇÃO, |\n");
  printf("    |DO PROFESSOR: FLAVIUS GORGONIO. APRESENTADO EM SALA DE AULA,               |\n");
  printf("    |COM A FINALIDADE DE OBTER NOTAS DE AVALIAÇÃO DA DISCIPLINA.                |\n");
  printf("    |                                                                           |\n");
  printf("    |                                                                           |\n");
  printf("    |                              IDENTIFICACAO                                |\n");
  printf("    |                                                                           |\n");
  printf("    |           ALUNAS DE SISTEMAS DE INFORMAÇÃO - UFRN CERES CAICÓ             |\n");
  printf("    |                                                                           |\n");
  printf("    |RENATA ARAÚJO.                             WANESSA SILVA.                  |\n");
  printf("    |TEL:(84) 9 9912-3995                       TEL:(84) 9 9849-0496            |\n");
  printf("    |renatakarla02@gmail.com                    wanessaparelhas68@gmail.com     |\n");
  printf("    |github.com/renatak12                       github.com/wanessabezerra       |\n");
  printf("    *===========================================================================*\n");
}
