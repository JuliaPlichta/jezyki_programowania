#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {
  FILE *fin;   /* uchwyt do pliku wejściowego */
  FILE *fout;  /* uchwyt do pliku wyjściowego */
  int ilosc = 0;
  int licznik_wyst[256];
  char znak;

  if (argc != 3) {
    printf("Użycie: %s 'nazwa pliku do wczytania' 'nazwa pliku do zapisu'\n", argv[0]);
    return 3;
  }
  if ((fin = fopen(argv[1], "r")) == NULL) {
    printf("Nie mogę otworzyć pliku do czytania '%s'\n", argv[1]);
    return 1;
  }
  if ((fout = fopen(argv[2], "w")) == NULL) {
    printf("Nie mogę otworzyć pliku do zapisu '%s'\n", argv[2]);
    return 2;
  }

  printf("Zliczanie znakow z pliku: %s\n", argv[1]);

  memset(licznik_wyst, 0, sizeof(licznik_wyst)); // zerowanie tablicy
  while((znak = fgetc(fin)) != EOF) {
    licznik_wyst[znak]++;
  }  // przegladanie pliku

  for(int a = 0; a < 256; a++) {
    if(licznik_wyst[a] > 0){
      fprintf(fout, "%d %d\n", a, licznik_wyst[a]);
      ilosc++;
    }
  }

  fclose(fin);
  fclose(fout);
  return 0;
}
