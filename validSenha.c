int validSenha(char senha[7]) {
  int i;
  for (i=0;i<7;i++) {
    senha[i] = '\0';
    putchar('*');
  }
  if (strcmp(senha,"123456") {
    return 0;
  }
  else {
    return 1;
  }
}
