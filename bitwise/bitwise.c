#include <stdio.h>

int main(int argc, char *argv[]) {
  
  unsigned short x, y, z;

  
  x = 1; y = 32768; z = 65535;

  printf("X is %hu\n", x);
  printf("X bitshifted to the right is %hu\n", x>>1);
  printf("X bitshifted to the left is %hu\n", x<<1);

  printf("Y is %hu\n", y);
  printf("Y bitshifted to the right is %hu\n", y>>1);
  printf("Y bitshifted to the left is %hu\n", y<<1);

  printf("Z is %hu\n", z);
  printf("Z bitshifted to the right is %hu\n", z>>1);
  printf("Z bitshifted to the left is %hu\n", z<<1);

  return 0;
}
