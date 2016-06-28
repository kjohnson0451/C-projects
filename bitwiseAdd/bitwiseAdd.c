/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 * Adds two integers using only bitwise operations.
 * Requires two arguments.
 *
 *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {
  if (b == 0) return a;
  int sum = a ^ b;
  int carry = (a & b) << 1;
  return add(sum, carry);
}

int main(int argc, char *argv[]) {

  int a, b;

  a = atoi(argv[1]); b = atoi(argv[2]);

  printf("%d\n", add(a, b));

  return 0;
}
