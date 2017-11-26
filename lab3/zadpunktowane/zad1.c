#include "stdio.h"

int sprawdzenie(int liczba) {
  int reszta, a=0;
  for (int i = 1; i < liczba; i++) {
    reszta = liczba%i;
    if (reszta == 0)
      a+=i;
  }

  if (a == liczba)
    printf("Ta liczba jest doskonala\n");
  else
    printf("Ta liczba nie jest doskonala\n");
}

int main() {
  int number;

  printf("Program sprawdza czy podana liczba jest liczba doskonala\n\n");
  printf("Podaj liczbe: ");
  scanf("%d", &number);
  sprawdzenie(number);

}
