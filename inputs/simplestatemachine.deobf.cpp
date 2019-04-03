#include <stdio.h>
#include <stdlib.h>
void error() {
  printf("invalid_input\n");
  exit(0);
}

int state=0;

char output(char in) {
  switch (state) {
    case 0:
      switch (in) {
        case 'A':
          state = 1;
          return 'X';
        case 'B':
          state = 2;
          return 'Y';
        case 'C':
          return 'Z';
        default:
          error();
        }
    case 1:
      switch (in) {
        case 'A':
          state = 3;
          return 'Z';
        case 'B':
          return 'Y';
        case 'C':
          return 'Z';
        default:
          error();
      }
    case 2:
      switch (in) {
        case 'A':
          return 'Z';
        case 'B':
          return 'Y';
        case 'C':
          state = 0;
          return 'Z';
        default:
          error();
      }
    case 3:
      switch (in) {
        case 'A':
          return 'Z';
        case 'B':
          return 'Y';
        case 'C':
          state = 0;
          return 'Z';
        case 'Q':
          return 'A';
        default:
          error();
      }
  }
    return 0;
}

int main() {
  while (1) {
    char input=0;
    int result=scanf("%c",&input);
    if (result == EOF)
      exit(0);
    else if (input >= 'A') {
      char out = output(input);
      printf("%c\n",out);
      fflush(stdout);
    }
  }
}
