#include <stdio.h>

int main(int argc, char *argv[]) {

  if( argc != 2 ) {
    fprintf(stderr, "ERROR: Requires ONE argument.\n");
    return 1;
  }
  int i = atoi(argv[1]);

  switch(i) {
  case 1:
    printf("one\n");
    break;
  case 2:
  case 3:
  case 4:
    printf("four\n");
    break;
  case 5:
    printf("five\n");
    break;
  case 6:
    printf("six\n");
    break;
  default :
    fprintf(stderr, "Invalid. Must be an integer between 1 and 5.\n");
    return 2;
  }

  return 0;
}
