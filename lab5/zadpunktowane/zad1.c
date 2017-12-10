#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

char plansza[3][3] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}};

void czy_dobre_xy(int *x, int *y);
void wyswietlanie();

int zaznaczanie(int x, int y){
  for (int i = 1; i < 4; i++) {
    for (int j = 1; j < 4; j++) {
      if ((x==i) && (y==j)) {
        if ((plansza[i-1][j-1] == 'o') || (plansza[i-1][j-1] == 'x')){
          printf("\n Zly ruch!\n Wybierz inne wspolrzedne.");

        }
        else
          plansza[i-1][j-1] = 'o';
      }
    }
  }
}

void ruch_przeciwnika() {
  int x, y;
  srand(time(NULL));
  x = 1+rand()%3;
  y = 1+rand()%3;
  printf ("  Przeciwnik wybral punkt (%d,%d)", x, y);

  for (int i = 1; i < 4; i++) {
    for (int j = 1; j < 4; j++) {
      if ((x==i) && (y==j)) {
        if ((plansza[i-1][j-1] == 'o') || (plansza[i-1][j-1] == 'x')){
          printf("\n Zly ruch!\n ");
          sleep(1);
          ruch_przeciwnika();
        }
        else
          plansza[i-1][j-1] = 'x';
      }
    }
  }
}

int warunek_wygranej() {
  for (int i = 0; i < 3; i++) {
    if ((plansza[0][i] == 'o') && (plansza[1][i] == 'o') && (plansza[2][i] == 'o')){
      printf("wygrana\n" );
      return 0;
    }
    else if ((plansza[i][0] == 'x') && (plansza[i][1] == 'x') && (plansza[i][2] == 'x')){
      printf("przegrana\n" );
      return 0;
    }
    else return 11;
  }
}

//---------------- funkcja main -------------------
int main() {
  int x, y;
  printf("Gra kolko i krzyzyk.\n");
  while (warunek_wygranej() != 0) {
    printf("  Podaj wspolrzedne x i y: ");
    scanf("%d %d", &x, &y);
    printf("  Wybrales punkt (%d,%d)", x, y);
    czy_dobre_xy(&x,&y);
    zaznaczanie(x,y);
    wyswietlanie();
    ruch_przeciwnika();
    wyswietlanie();
  }
  return 0;
}
//-------------------------------------------------

void wyswietlanie() {
  printf("\n");
  for (int j = 0; j < 3; j++) {
    printf("   ---   ");
    for (int i = 0; i < 3; i++) {
      printf(" %c | ", plansza[j][i]);
    }
    printf("\n");
  }
  printf("\n");
}

void czy_dobre_xy(int *x, int *y) {
  while ((*x!=1) && (*x!= 2) && (*x!=3) || (*y!=1) && (*y!= 2) && (*y!=3)) {
    if ((*x!=1) && (*x!= 2) && (*x!=3)) {
      printf("Nieprawidlowa wsporzedna x!\n Podaj x jeszcze raz: ");
      scanf("%d", x);
    }
    if ((*y!=1) && (*y!= 2) && (*y!=3)) {
      printf("Nieprawidlowa wsporzedna y!\n Podaj y jeszcze raz: ");
      scanf("%d", y);
    }
  }
}
