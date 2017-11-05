#include <stdio.h>

int main() {
  int a, b;
  
  printf("podaj a: ");
  scanf("%d", &a);
  printf("podaj b: ");
  scanf("%d", &b);

//---------do while----------
  int j = a;
  do {
    printf("%d\n", j);
    j++;
  } while(j <= b);

  printf("podaj a: ");
  scanf("%d", &a);
  printf("podaj b: ");
  scanf("%d", &b);
//----------while------------
  j = a;
  while (j <= b) {
    printf("%d\n", j);
    j++;
  }

  printf("podaj a: ");
  scanf("%d", &a);
  printf("podaj b: ");
  scanf("%d", &b);
//-----------for-------------
  for (j = a; j <= b; j++) {
    printf("%d\n", j);
  }

  return 0;
}
