#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* zapisywanie danych do pliku */

int main (int argc, char *argv[]) {
  FILE *fout;  /* uchwyt do pliku wyjściowego */
  srand(time(NULL));

  if (argc != 2) {
    printf("Użycie: %s SOURCE DEST\n", argv[0]);
    return 2;
  }
  if ((fout = fopen(argv[1], "w")) == NULL) {
    printf("Nie mogę otworzyć pliku do zapisu '%s'\n", argv[1]);
    return 1;
  }

  printf("Zapisywanie danych do pliku: %s\n", argv[1]);

  float srednia;
  int tab[1000], los, suma = 0;

  for (int c = 1; c <= 1000; c++) {
    los = rand();
    tab[c] = los;
    suma += tab[c];
    srednia = suma/(double)c;

    fprintf(fout, "%.3f\n", srednia);
  }

  fclose(fout);

  return 0;
}
