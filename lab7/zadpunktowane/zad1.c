#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  int **tablica;
  int rozmiar;
//  printf("Podaj N (wielkosc tablicy):");
//  scanf("%d", rozmiar);
  rozmiar = 5;
  tablica = malloc(rozmiar * sizeof(int*));
  for (int i = 0; i < rozmiar; i++) {
    tablica[i] = malloc(rozmiar * sizeof(int));
  }

  for (int i = 0; i < rozmiar; i++) {
    for (int j = 0; j < rozmiar; j++) {
      tablica[i][j] = 0;
    }
  }

for (int i = 0; i < rozmiar; i++) {
  tablica[i][i] = i;
}
for (int i = 0; i < rozmiar; i++) {
  for (int j = rozmiar; j > i; j--) {
    tablica[i][j] = 9;
  }
}


// wyswietlanie
  for (int i = 0; i < rozmiar; i++) {
    for (int j = 0; j < rozmiar; j++) {
      printf("%d", tablica[i][j]);
    }
    printf("\n");
  }





  for (int i = 0; i < rozmiar; i++) {
    free(tablica[i]);
  }
  free(tablica);
  return 0;
}
