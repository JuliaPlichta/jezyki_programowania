#include "stdio.h"

int nwd(int num1, int num2) {
  int reszta, wynik;
  for (int j = 2; j <= num1; j++) {
    if ((num1%j == 0) && (num2%j == 0)) {
      wynik = j;
    }
  }
  printf("NWD(%d,%d) = %d\n",num1, num2, wynik);
}

int main() {
  int liczba1, liczba2;

  printf("Program liczy NWD dwoch podanych liczb\n\n");
  printf("Podaj pierwsza liczbe: ");
  scanf("%d", &liczba1);
  printf("Podaj druga liczbe: ");
  scanf("%d", &liczba2);

  nwd(liczba1, liczba2);

}
