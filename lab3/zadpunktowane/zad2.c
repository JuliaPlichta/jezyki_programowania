#include "stdio.h"

/*nwd() {

}
*/

int main() {
  int num1, num2, reszta, a = 1;

  printf("Program liczy NWD dwoch podanych liczb\n\n");
  printf("Podaj pierwsza liczbe: ");
  scanf("%d", &num1);
  printf("Podaj druga liczbe: ");
  scanf("%d", &num2);

for (int j = 2; j < num1; j++) {
  if ((num1%j == 0) && (num2%j == 0)) {
    printf("%d, ", j);
  }
}


}
