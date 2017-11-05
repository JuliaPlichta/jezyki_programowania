#include <stdio.h>

int main() {
  int a, b, j, wynik;
//-------------- do while --------------
  printf("podaj a: ");
  scanf("%d", &a);

  if (a == 0) {
    printf("wynik = 1\n");
  }
  else if (a < 0) {
    printf("Nieprawidlowa liczba!\n");
  }
  else {
    j = a;
    wynik = 1;
    do {
      wynik *= j;
      j--;
    } while(j > 1);
    printf("wynik = %d\n", wynik);
  }
//-------------- while ----------------
  printf("podaj a: ");
  scanf("%d", &a);

  if (a == 0) {
    printf("wynik = 1\n");
  }
  else if (a < 0) {
    printf("Nieprawidlowa liczba!\n");
  }
  else {
    j = a;
    wynik = 1;
    while (j > 1) {
      wynik *= j;
      j--;
    }
    printf("wynik = %d\n", wynik);
  }
//-------------- for -----------------
  printf("podaj a: ");
  scanf("%d", &a);
  if (a == 0) {
    printf("wynik = 1\n");
  }
  else if (a < 0) {
    printf("Nieprawidlowa liczba!\n");
  }
  else {
    wynik = 1;
    for (int j = a; j > 0; j--) {
      wynik *= j;
    }
    printf("wynik = %d\n", wynik);
  }

  return 0;
}
