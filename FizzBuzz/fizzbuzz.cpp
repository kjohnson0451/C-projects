/*******************************************************************************************************************************
 *
 *
 * 
 *******************************************************************************************************************************/

#include <iostream>
#include <stdlib.h>

void fizzbuzz(int);

int main(int argc, char *argv[]) {

  int n;
  std::cin >> n;

  fizzbuzz(n);

  return 0;
}

void fizzbuzz(int n) {
  int i;
  bool isFizzBuzz = false;

  for( i=1; i<=n; i++) {
    if(i % 3 == 0) {
      std::cout << "Fizz";
      isFizzBuzz = true;
    }
    if(i % 5 == 0) {
      std::cout << "Buzz";
      isFizzBuzz = true;
    }
    if(!isFizzBuzz) {
      std::cout << i;
    }
    isFizzBuzz = false;
    std::cout << "\n";
  }
}
