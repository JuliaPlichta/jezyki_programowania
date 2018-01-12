#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* zapisywanie danych do pliku */

int main (int argc, char *argv[]) {
  FILE *fout;  /* uchwyt do pliku wyjściowego */
  float c = 0, los;
  srand(time(NULL));

  if ((fout = fopen("dane.dat", "w")) == NULL) {
    printf("Nie mogę otworzyć pliku do zapisu '%s'\n", argv[1]);
    return 1;
  }

  printf("Zapisywanie danych do pliku: %s\n", "dane.dat");

  while (c <= 100) {
    los = rand()%100;
    los /= 100;
    fprintf(fout, "%.1f ", c/100);
    fprintf(fout, " %.2f ", (c*c)/10000);
    fprintf(fout, " %.2f\n", los);
    c += 10;
  }

  fclose(fout);

  return 0;
}
