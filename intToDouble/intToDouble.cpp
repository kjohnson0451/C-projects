#include <iostream>

int main(int argc, char *argv[]) {
  double example1 = 1.04512;
  std::cout << "Example double: " << example1 << "\n";

  int example2 = 3;
  double example3 = (double)example2;

  std::cout << "Int converted to double: " << example3 << "\n";
  
  return 0;
}
