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

  printf("suma: %f\n", a + b + c + d);
  printf("srednia: %f\n", (a + b + c + d) / 4.0);
  printf("najmniejsza liczba do kwadratu: ");

    if ((a <= b) && (a <= c) && (a <= d)) {
      printf("%f\n", a*a );
    }
    else if ((b <= a) && (b <= c) && (b <= d)) {
      printf("%f\n", b*b );
    }
    else if ((c <= a) && (c <= b) && (c <= d)) {
      printf("%f\n", c*c );
    }
    else if ((d <= a) && (d <= b) && (d <= c)) {
      printf("%f\n", d*d );
    }

  return 0;
}
