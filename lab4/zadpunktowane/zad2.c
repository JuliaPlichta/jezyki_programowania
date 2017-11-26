#include <stdio.h>

/*int funkcja(int a, int tab[2] int tab[2][5]){
    if (b < 1) return 1;
    else return funkcja(a, b - 1)*a;
}
*/

int main() {
  int dzies;
//  int tab[5] = {1,2,3,4,5};
//  int tab2[2][5] = {{1,2,3,4,5},{6,7,8,9,10}};
//  for (int i=0; i<5; i++){
//    printf("1: %d\n", tab2[0][i]);
//    printf("2: %d\n", tab2[1][i]);
//  }

  printf("podaj liczbe: ");
  scanf("%d", &dzies);

while (dzies < 0) {

  if (dzies%2 == 0) {
    printf("%d, 0\n", dzies/2);
  }
  else printf("1\n");
}

//  if (dzies%2 == 0) {
//    printf("%d\n", dzies/2);
//  }



  return 0;
}
