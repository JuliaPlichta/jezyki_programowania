#include <stdio.h>

int main() {
  float a, b, c, d;
  printf("program podaje sume, srednia, najmniejsza liczbe do kwadratu z podanych liczb\n");
  printf("podaj a: \n");
  scanf("%f", &a);
  printf("podaj b: \n");
  scanf("%f", &b);
  printf("podaj c: \n");
  scanf("%f", &c);
  printf("podaj d: \n");
  scanf("%f", &d);
  printf("podales: %f, %f, %f, %f\n", a, b, c, d);  // <----sprawdzenie

  printf("suma: %f\n", a + b + c + d);
  printf("srednia: %f\n", (a + b + c + d) / 4.0);
  return 0;
}
