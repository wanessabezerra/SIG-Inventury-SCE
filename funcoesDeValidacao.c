#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


///////////////////////////////////////////////
//// F U N Ç Õ E S  D E  V A L I D A Ç A O ////
///////////////////////////////////////////////


int validacaoEhNumero(char c) {
  if (c>='0'&& c<='9') {
    return 1;
  }
  else 
    return 0;
  
}

char minusculas(char c) {
  if (c>='A' && c<='Z') {
    return c - 'A' + 'a';
  }
  else {
    return c;
  }
}

char maiusculas(char c) {
  if (c>='a' && c<='z') {
    return c - 'a' + 'A';
  }
  else {
    return c;
  }
}

int validacaoEhLetra(char c) {
  if (c>='A' && c<='Z') {
    return 1;
  }
  else if (c>='a' && c<='z') {
    return 1;
  }
  else {
    return 0;
  }
}

int validacaoEmail( const char * email )
{
    char usuario[256], site[256], dominio[256];

    if( sscanf( email, "%[^@ \t\n]@%[^. \t\n].%3[^ \t\n]", usuario, site, dominio ) != 3 )
        return 0;

    return 1;
}

int validacaoCpf(char *cpf){
    int i, j, digito1 = 0, digito2 = 0;
    if(strlen(cpf) != 11)
        return 0;
    else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
            (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
            (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
            (strcmp(cpf,"99999999999") == 0))
        return 0;
    else
    {
        
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--)
            digito1 += (cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((cpf[9]-48) != digito1)
            return 0;
        else
        
        {
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--)
                    digito2 += (cpf[i]-48) * j;
        digito2 %= 11;
        if(digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if((cpf[10]-48) != digito2)
            return 0;
        }
    }
    return 1;
}


int validacaoCnpj(char *cnpj){
    int i, j, digito1 = 0, digito2 = 0;
    if(strlen(cnpj) != 14)
        return 0;
    else if((strcmp(cnpj,"00000000000000") == 0) || (strcmp(cnpj,"11111111111111") == 0) || (strcmp(cnpj,"22222222222222") == 0) ||
            (strcmp(cnpj,"33333333333333") == 0) || (strcmp(cnpj,"44444444444444") == 0) || (strcmp(cnpj,"55555555555555") == 0) ||
            (strcmp(cnpj,"66666666666666") == 0) || (strcmp(cnpj,"77777777777777") == 0) || (strcmp(cnpj,"88888888888888") == 0) ||
            (strcmp(cnpj,"99999999999999") == 0))
        return 0;
    else
    {
        
        for(i = 0, j = 13; i < strlen(cnpj)-2; i++, j--)
            digito1 += (cnpj[i]-48) * j;
        digito1 %= 14;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 14 - digito1;
        if((cnpj[9]-48) != digito1)
            return 0;
        else
        
        {
            for(i = 0, j = 14; i < strlen(cnpj)-1; i++, j--)
                    digito2 += (cnpj[i]-48) * j;
        digito2 %= 14;
        if(digito2 < 2)
            digito2 = 0;
        else
            digito2 = 14 - digito2;
        if((cnpj[13]-48) != digito2)
            return 0;
        }
    }
    return 1;
}

int validacaoData(int dd, int mm, int aa) {
  int maiorDia;
  if (aa < 0) {
    return 0;
  } else if (mm < 1 || mm > 12) {
    return 0;
  } else {
    if (mm == 1 || mm == 3 || mm == 5 ||
        mm == 7 || mm == 8 || mm == 10 ||
        mm == 12) {
          maiorDia = 31;
    } else if (mm == 4 || mm == 6 || 
               mm == 9 || mm == 11) {
                 maiorDia = 30;
    } else {
      if (bissexto(aa)) {
        maiorDia = 29;
      } else {
        maiorDia = 28;
      }
    }
    if (dd < 1 || dd > maiorDia) {
      return 0;
    } else {
      return 1;
    }
  }
}

int bissexto(int aa) {
  if ((aa % 4 == 0) && (aa % 100 != 0)) {
    return 1;
  } else if (aa % 400 == 0) {
    return 1;
  } else {
    return 0;
  }
}


