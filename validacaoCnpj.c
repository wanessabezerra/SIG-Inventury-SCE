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
