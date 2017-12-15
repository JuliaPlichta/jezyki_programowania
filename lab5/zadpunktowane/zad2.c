#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int size;
int x, y;

void czy_dobry_size() {
  printf("Podaj rozmiar planszy na jakiej chcesz grac (od 3 do 10): ");
  scanf("%d", &size);
  while (size>10 || size<3) {
    if (size>10 || size<3) {
      printf("Nieprawidlowa wielkosc planszy!\nPodaj wielkosc jeszcze raz: ");
      scanf("%d", &size);
    }
  }
  printf("Rozmiar planszy to %d x %d\n", size, size);
}

/* Funkcja wyswietla plansze */
void wyswietlanie(char plansza[size][size]) {
  printf("\n");
  for (int j = 0; j < size; j++) {
    printf("   ---   ");
    for (int i = 0; i < size; i++) {
      printf("[%c]", plansza[j][i]);
    }
    printf("\n");
  }
  printf("\n");
}

/* Funkcja sprawdza czy gracz podal wsplrzedne z przedzialu 1-3 */
void czy_dobre_xy() {
  while (x>size && x<0 || y>size && y<0) {
    if (x>size && x<0 ) {
      printf("Nieprawidlowa wsporzedna x!\nPodaj x jeszcze raz: ");
      scanf("%d", &x);
    }
    if (y>size && y<0) {
      printf("Nieprawidlowa wsporzedna y!\nPodaj y jeszcze raz: ");
      scanf("%d", &y);
    }
  }
}

/* Funkcja sprawdza czy plansza jest zapelniona */
int pelna(char plansza[size][size]){
  for (int i=0; i<size; i++)
    for (int j=0; j<size; j++)
      if (plansza[i][j] == ' ') return 0;  // ---> jesli jest wolne pole zwroc 0
   return 1;
}

/* Funkcja wykonuje ruch gracza:
    - wczytuje wspolrzedne,
    - sprawdza czy sa poprawne czyli z przedzialu 1-3
    - sprawdza czy pole jest puste,
    - zaznacza kolkiem wybrane pole) */
int ruch_gracza(char plansza[size][size]){
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
void ruch_komputera(char plansza[size][size]){
  int i, j;
  do{
    i=1+rand()%size;
    j=1+rand()%size;
  } while (plansza[i-1][j-1]!=' ');
  plansza[i-1][j-1]='x';
  printf ("Przeciwnik wybral punkt (%d,%d)", i, j);
}

/* Funkcja sprawdza czy ktos wygral/czy jest remis */
char sprawdzenie(char plansza[size][size]){
  int k = 0, l = 0;
  char schowek_x = 'x', schowek_o = 'o';
  for (int i = 0; i < size; i++){    // poziome
      for (int j = 0; j < size; j++) {
        if (schowek_x == plansza[i][j]) k++;
        if (k == size) return schowek_x;
        if (schowek_o == plansza[i][j]) l++;
        if (l == size) return schowek_o;
      }
      k = 0, l = 0;
  }
  for (int j = 0; j < size; j++){    // pionowe
      for (int i = 0; i < size; i++) {
        if (schowek_x == plansza[i][j]) k++;
        if (k == size) return schowek_x;
        if (schowek_o == plansza[i][j]) l++;
        if (l == size) return schowek_o;
      }
      k = 0, l = 0;
  }
  for (int i = 0; i < size; i++) {   // ukosne z gory
    if (schowek_x == plansza[i][i]) k++;
    if (k == size) return schowek_x;
    if (schowek_o == plansza[i][i]) l++;
    if (l == size) return schowek_o;
  }
  k = 0, l = 0;
  for (int i = 0; i < size; i++) {   // ukosne z dolu
    if (schowek_x == plansza[i][size-1-i]) k++;
    if (k == size) return schowek_x;
    if (schowek_o == plansza[i][size-1-i]) l++;
    if (l == size) return schowek_o;
  }
  k = 0, l = 0;

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


// ----------------------------------------------------------------
int main() {
  int ruch = 1;
  char wynik = 0;
  srand(time(NULL));
  system("clear");
  printf("*********************************************************\n");
  printf("==================== KOLKO I KRZYZYK ====================\n");
  //printf("Podaj rozmiar planszy na jakiej chcesz grac (od 3 do 10): ");
  //scanf("%d", &size);
  czy_dobry_size();
  char plansza[size][size];
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      plansza[i][j] = ' ';
    }
  }
  while (wynik==0) {
    if (ruch == 0){
      ruch_komputera(plansza);
      wyswietlanie(plansza);
    }
    else if (ruch == 1){
      ruch_gracza(plansza);
      wyswietlanie(plansza);
    }
    ruch = 1-ruch;
    wynik = sprawdzenie(plansza);
  }
  podaj_wynik(wynik);
  return 0;
}
