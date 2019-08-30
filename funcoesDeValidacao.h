#ifndef FUNCOESDEVALIDACAO_H_INCLUDED
#define FUNCOESDEVALIDACAO_H_INCLUDED

int validacaoEhNumero(char);
char minusculas(char);
char maiusculas(char);
int validacaoEhLetra(char);
int validacaoEmail(const char *);
int validacaoCpf(char *);
int validacaoCnpj(char *);
int validacaoData(int, int, int);
int bissexto(int);

#endif // FUNCOESDEVALIDACAO_H_INCLUDED
