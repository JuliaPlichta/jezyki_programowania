#include <stdio.h>

int main() {
  float a, b;
  int x;

  printf("program podaje wynik wybranej operacji (+, -, *, /)\n");
  printf("podaj a: \n");
  scanf("%f", &a);
  printf("podaj b: \n");
  scanf("%f", &b);
  printf("podaj operacje jaka chcesz wykonac:\n(1-dodawanie, 2-odejmowanie, 3-mnozenie, 4-dzielenie)\n");
  scanf("%d", &x);

  do {
    printf("wybrales nieprawidlowa liczbe!\n\n");
    printf("podaj operacje jaka chcesz wykonac:\n(1-dodawanie, 2-odejmowanie, 3-mnozenie, 4-dzielenie)\n");
    scanf("%d", &x);
  }
  while((x != 1) && (x != 2) && (x != 3) && (x != 4));

  if (x == 1) {
    printf("%f\n", a + b);
  }
  if (x == 2) {
    printf("%f\n", a - b);
  }
  if (x == 3) {
    printf("%f\n", a * b);
  }
  if (x == 4) {
    printf("%f\n", a / b);
  }

  return 0;
}
