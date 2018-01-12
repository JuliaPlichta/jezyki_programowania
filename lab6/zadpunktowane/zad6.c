#include <stdio.h>
#include <stdlib.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main(int argc, char const *argv[]) {
  int i, j, wys = 20;
  printf(ANSI_COLOR_YELLOW "%*c #\n", wys, ' ');
  printf(ANSI_COLOR_GREEN);
  for(i = 1; i < wys; i++) {
    printf("%*c", wys - i, ' ');
    for (j = 0; j <= i; j++)
      printf(ANSI_COLOR_GREEN " *" ANSI_COLOR_RESET);
    putchar('\n');
  }
  for (int a = 0; a < 3; a++) {
    printf(ANSI_COLOR_RED "%*c* *\n", wys, ' ');
  }

  printf(ANSI_COLOR_MAGENTA "%*c* *   * *\n", 5, ' ');
  printf(ANSI_COLOR_MAGENTA "%*c* * *\n", 7, ' ');
  printf(ANSI_COLOR_CYAN "%*c* * * " ANSI_COLOR_MAGENTA "* * " ANSI_COLOR_CYAN "* * *\n", 2, ' ');
  printf(ANSI_COLOR_CYAN "%*c* * * " ANSI_COLOR_MAGENTA "* * " ANSI_COLOR_CYAN "* * *\n", 2, ' ');
  printf(ANSI_COLOR_CYAN "%*c* * * " ANSI_COLOR_MAGENTA "* * " ANSI_COLOR_CYAN "* * *\n", 2, ' ');
  printf(ANSI_COLOR_MAGENTA "%*c* * * * * * * *\n", 2, ' ');
  printf(ANSI_COLOR_MAGENTA "%*c* * * * * * * *\n", 2, ' ');
  printf(ANSI_COLOR_CYAN "%*c* * * " ANSI_COLOR_MAGENTA "* * " ANSI_COLOR_CYAN "* * *\n", 2, ' ');
  printf(ANSI_COLOR_CYAN "%*c* * * " ANSI_COLOR_MAGENTA "* * " ANSI_COLOR_CYAN "* * *\n", 2, ' ');
  printf(ANSI_COLOR_CYAN "%*c* * * " ANSI_COLOR_MAGENTA "* * " ANSI_COLOR_CYAN "* * *\n", 2, ' ');

  return 0;
}
