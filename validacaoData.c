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
