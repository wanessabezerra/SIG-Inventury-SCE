int validacaoEmail( const char * email )
{
    char usuario[256], site[256], dominio[256];

    if( sscanf( email, "%[^@ \t\n]@%[^. \t\n].%3[^ \t\n]", usuario, site, dominio ) != 3 )
        return 0;

    return 1;
}
