#include <iostream>
#include <bitset>

int main(int argc, char *argv[]) {

  std::bitset<16> foo;
  std::bitset<16> bar (0xfa2);
  std::bitset<16> baz (std::string("0101111001"));

  std::cout << "foo: " << foo << '\n';
  std::cout << "bar: " << bar << '\n';
  std::cout << "baz: " << baz << '\n';

  std::cout << "The fifth bit of bar is " << bar[5] << "\n";

  return 0;
}
