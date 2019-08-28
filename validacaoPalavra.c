int validacaoPalavra(char s[]) {
  int tam;
  tam = strlen(s) - 1;
  for (int i = 0; i < tam; i++) {
    if (!validacaoEhLetra(s[i])) {
      return 0;
    }
  }
  return 1;
}
