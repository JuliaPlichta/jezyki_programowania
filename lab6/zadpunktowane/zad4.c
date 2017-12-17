#include <stdio.h>

int main (int argc, char *argv[]) {
  FILE *fin;   /* uchwyt do pliku wejściowego */
  FILE *fout;  /* uchwyt do pliku wyjściowego */
  int c;

  if (argc != 2) {
    printf("Użycie: %s SOURCE DEST\n", argv[0]);
    return 3;
  }
  if ((fin = fopen(argv[1], "r")) == NULL) {
    printf("Nie mogę otworzyć pliku do czytania '%s'\n", argv[1]);
    return 1;
  }

  printf("Zliczanie znakow z pliku: %s\n", argv[1]);

  int tab[255];

  //while ((c = fgetc(fin)) != EOF) {

    for (int i = 0; i < 255; i++) {
      printf("%d\n", tab[i]);
    }

  //}

  fclose(fin);

  return 0;
}
