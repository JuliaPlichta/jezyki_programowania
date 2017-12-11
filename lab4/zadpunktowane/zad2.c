#include <stdio.h>

void dzies_na_bin(int num){
  if(num > 0){
    dzies_na_bin(num / 2);
    printf("%d", num % 2);
  }
}

int main(){
  int liczba;
  printf("Podaj liczbę: ");
  scanf("%d", &liczba);
  printf("\nPostać binarna: ");
  dzies_na_bin(liczba);
  printf("\n");

  return 0;
}
