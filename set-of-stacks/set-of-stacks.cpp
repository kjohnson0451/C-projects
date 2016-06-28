#include <iostream>
#include <stack>
#include <vector>

class setOfStacks {
  std::stack<int> stacks[8];

};

int main(int argc, char *argv[]) {

  std::stack <int> st;
  st.push(15);
  st.push(17);
  st.pop();

  std::cout << st.top() << " is on the top\n";

  return 0;
}
