#include <stdio.h>

int bankomat(double reszta, int i){
  double liczbaNominalow[15];
  double nominaly[] = {500, 200, 100, 50, 20, 10, 5, 2, 1, 0.50, 0.20, 0.10, 0.05, 0.02, 0.01};
  if (reszta > 0.001){
    liczbaNominalow[i] = (int)(reszta / nominaly[i]);
    reszta = (reszta - nominaly[i] * liczbaNominalow[i]);
    if (liczbaNominalow[i] != 0) {
      printf("Wyplacono: %.0lf x %.2lf PLN\n", liczbaNominalow[i], nominaly[i]);
    }
    i++;
    bankomat(reszta, i);
  }
  else return 0;
}

int main() {
  double kwota;
  printf("Program 'wyda' kwote jaka poda uzytkownik\n\n");
  printf("Podaj kwote do wyplacenia: ");
  scanf("%lf", &kwota);
  kwota +=0.001;
  bankomat(kwota, 0);

  return 0;
}
