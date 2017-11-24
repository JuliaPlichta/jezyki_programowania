#include <stdio.h>

int main() {
  int a, b;
  
  printf("Program wypisuje liczby z podanego przedialu\n\n");
  printf("Podaj dolna granice przedzialu: ");
  scanf("%d", &a);
  printf("Podaj gorna granice przedzialu: ");
  scanf("%d", &b);

//---------do while----------
  int j = a;
  do {
    printf("%d\n", j);
    j++;
  } while(j <= b);

  printf("Podaj dolna granice przedzialu: ");
  scanf("%d", &a);
  printf("Podaj gorna granice przedzialu: ");
  scanf("%d", &b);
//----------while------------
  j = a;
  while (j <= b) {
    printf("%d\n", j);
    j++;
  }

  printf("Podaj dolna granice przedzialu: ");
  scanf("%d", &a);
  printf("Podaj gorna granice przedzialu: ");
  scanf("%d", &b);
//-----------for-------------
  for (j = a; j <= b; j++) {
    printf("%d\n", j);
  }

  return 0;
}
