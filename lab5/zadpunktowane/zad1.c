#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

char plansza[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
int x, y;

void wyswietlanie(void);
void czy_dobre_xy(void);
int pelna(char plansza[3][3]);
int ruch_gracza(void);
void ruch_komputera(void);
char sprawdzenie(char plansza[3][3]);
void podaj_wynik(char wynik);

// --------------------------------- funkcja main -------------------------------------
int main() {
  int ruch = 1;
  char wynik = 0;
  srand(time(NULL));
  system("clear");
  printf("*********************************************************\n");
  printf("==================== KOLKO I KRZYZYK ====================\n");
  while (wynik==0) {
    if (ruch == 0){
      ruch_komputera();
      wyswietlanie();
    }
    else if (ruch == 1){
      ruch_gracza();
      wyswietlanie();
    }
    ruch = 1-ruch;
    wynik = sprawdzenie(plansza);
  }

  podaj_wynik(wynik);
  return 0;
}
// -----------------------------------------------------------------------------------

/* Funkcja wyswietla plansze */
void wyswietlanie() {
  printf("\n");
  for (int j = 0; j < 3; j++) {
    printf("   ---   ");
    for (int i = 0; i < 3; i++) {
      printf("[%c]", plansza[j][i]);
    }
    printf("\n");
  }
  printf("\n");
}

/* Funkcja sprawdza czy gracz podal poprawne wsplrzedne (z przedzialu 1-3) */
void czy_dobre_xy() {
  while ((x!=1) && (x!= 2) && (x!=3) || (y!=1) && (y!= 2) && (y!=3)) {
    if ((x!=1) && (x!= 2) && (x!=3)) {
      printf("Nieprawidlowa wsporzedna x!\nPodaj x jeszcze raz: ");
      scanf("%d", &x);
    }
    if ((y!=1) && (y!= 2) && (y!=3)) {
      printf("Nieprawidlowa wsporzedna y!\nPodaj y jeszcze raz: ");
      scanf("%d", &y);
    }
  }
}

/* Funkcja sprawdza czy plansza jest zapelniona */
int pelna(char plansza[3][3]){
  for (int i=0; i<3; i++)
    for (int j=0; j<3; j++)
      if (plansza[i][j] == ' ')
        return 0;  // ---> jesli jest wolne pole zwroc 0
   return 1;  // ---> plansza jest pelna
}

/* Funkcja wykonuje ruch gracza:
    - wczytuje wspolrzedne,
    - sprawdza czy sa poprawne czyli z przedzialu 1-3
    - sprawdza czy pole jest puste,
    - zaznacza kolkiem wybrane pole) */
int ruch_gracza(){
  printf("Podaj wspolrzedne x i y: ");
  scanf("%d %d", &x, &y);
  czy_dobre_xy();
  printf ("Wybrales punkt (%d,%d)", x, y);
  while (plansza[x-1][y-1]!=' ') {
    printf("\nZly ruch!\n Wybierz inne wspolrzedne.");
    printf("Podaj wspolrzedne x i y: ");
    scanf("%d %d", &x, &y);
    czy_dobre_xy();
    printf ("Wybrales punkt (%d,%d)", x, y);
  }
  plansza[x-1][y-1]='o';
}

/* Funkcja wykonuje ruch komputera:
   - losuje wspolrzedne dopoki znajdzie takie pole, ktore jest puste
   - zaznacza pole krzyzykiem) */
void ruch_komputera(){
  int i, j;
  do{
    i=1+rand()%3;
    j=1+rand()%3;
  } while (plansza[i-1][j-1]!=' ');
  plansza[i-1][j-1]='x';
  printf ("Przeciwnik wybral punkt (%d,%d)", i, j);
}

/* Funkcja sprawdza czy ktos wygral/czy jest remis */
char sprawdzenie(char plansza[3][3]){
  for (int i=0; i<3; i++){
    if ((plansza[i][0]!=' ') && (plansza[i][0]==plansza[i][1]) && (plansza[i][0]==plansza[i][2]))
      return plansza[i][0];
    if ((plansza[0][i]!=' ') && (plansza[0][i]==plansza[1][i]) && (plansza[0][i]==plansza[2][i]))
      return plansza [0][i];
  }
  if ((plansza[0][0]!=' ') && (plansza[0][0]==plansza[1][1]) && (plansza[0][0]==plansza[2][2]))
    return plansza[0][0];
  if ((plansza[2][0]!=' ') && (plansza[2][0]==plansza[1][1]) && (plansza[2][0]==plansza[0][2]))
    return plansza[2][0];

  if (pelna(plansza)==1) return 1;  // ---> remis
  return 0;
}

/* Funkcja wypisuje w terminalu wynik gry */
void podaj_wynik(char wynik) {
  if (wynik==1){
    printf("Remis\n");
    printf("Nacisnij ENTER aby kontynowac\n");
    getchar();
    getchar();
  }
  else if (wynik=='o'){
    printf("Wygrales!!! :-) \n");
    printf("Nacisnij ENTER aby kontynowac\n");
    getchar();
    getchar();
  }
  else if (wynik=='x'){
    printf("Przegrales :( \n");
    printf("Nacisnij ENTER aby kontynowac\n");
    getchar();
    getchar();
  }
}
