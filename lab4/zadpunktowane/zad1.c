#include <stdio.h>

void bankomat(int kwota, int i){
  i++;
  int ile[15];
  int nominaly[] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
  // nominaly sa pomnozone razy 100, aby uniknac bledow w programie
  if (kwota == 0) return;
  else if (kwota > 0){
    ile[i] = (int)(kwota / nominaly[i]);
    kwota = kwota - (ile[i] * nominaly[i]);
    if (ile[i] != 0) {
      printf("Wyplacono: %d x %.2lf PLN\n", ile[i], (double)nominaly[i]/100);
    }
    return bankomat(kwota, i);
  }
}

int main() {
  int i=-1;
  double kasa;
  printf("Program 'wyda' kwote jaka poda uzytkownik\n\n");
  printf("Podaj kwote do wyplacenia: ");
  scanf("%lf", &kasa);
  int kasa2 = 100 * kasa;
  bankomat(kasa2, i);

  return 0;
}
