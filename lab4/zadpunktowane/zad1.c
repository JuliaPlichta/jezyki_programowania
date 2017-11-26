#include <stdio.h>

/*
int funkcja(int a){
    if (a < 2) return 1;
    else return funkcja(a - 1)+a;
}
*/

int main() {
  double kwota;
  printf("Program 'wyda' kwote jaka poda uzytkownik\n\n");
  printf("Podaj kwote jaka chcesz wyplacic: ");
  scanf("%lf", &kwota);

  printf("Kwota: %.2f\n", kwota);

  double tab[] = {500,200,100,50,20,10,5,2,1,0.5,0.2,0.1,0.05,0.02,0.01};
//  for(int i=0; i<15; i++){
//    printf("%.2f\n", tab[i]);
//  }


//for (int i = 0; i < 15; i++) {
//  printf("%.1f x %.2f\n", kwota/tab[i], tab[i]);
//}


  for (int i = 0; i < 15; i++) {
    int a = 0;
    while (kwota >= tab[i]) {
      kwota = kwota - tab[i];
      a += 1;
      printf("  %.2f x %d\n", tab[i], a);
      printf("  kwota do wydania: %.2f\n", kwota);

      if (kwota == 0) {
        printf("Udało się!\n");
      }

    }

  }
/*  while (kwota > tab[2]) {
    kwota = kwota - tab[2];
    a += 1;
    printf("  kwota do wydania: %.2f\n", kwota);
    printf("  %.2f x %d\n", tab[2], a);
  }
*/
/*  if (kwota > tab[2]) {
    kwota = kwota - tab[2];
    a += 1;
    printf("  kwota do wydania: %.2f\n", kwota);
    printf("  %.2f x %d\n", tab[2], a);
  }
*/

//  printf("suma liczb od 1 do %d = %d\n", x, funkcja(x));
  printf("\n");
}
