#include <stdio.h>

//------funkcja podajaca mniejsza liczbe--------
float mniejsza(float a, float b) {
  if (a<0 && b>0) {
    return b;
  }
  else if (b < 0 && a > 0) {
    return a;
  }
  else if (a > 0 && b > 0 && a > b) {
    return b;
  }
  else {
    return a;
  }
}

//--------------funkcja glowna----------------
int main() {

  float a, d, c, b;
  printf("program podaje najmniejsza liczbe dodatnia (lub 0)\n");
  printf("podaj a: ");
  scanf("%f", &a);
  printf("podaj b: ");
  scanf("%f", &b);
  printf("podaj c: ");
  scanf("%f", &c);
  printf("podaj d: ");
  scanf("%f", &d);

  float aa = mniejsza(a, b);
  float bb = mniejsza(aa, c);
  float dd = mniejsza(bb, d);
  if (dd > 0) {
    printf("najmniejsza: %f\n", dd);
  }
  else {
    printf("0 <--- brak liczby dodatniej\n");
  }

return 0;
}
