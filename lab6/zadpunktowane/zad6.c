#include <stdio.h>

#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m"

int main(int argc, char const *argv[]) {
  printf(ANSI_COLOR_BLUE "kolor niebieski" ANSI_COLOR_RESET "\n");
  return 0;
}
