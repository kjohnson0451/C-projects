/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *
 *
 *
 *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include <iostream>
#include <queue>

int main(int argc, char *argv[]) {

  std::queue<short *> q;
  
  short one = 1;
  short two = 2;
  short three = 3;
  short four = 4;

  q.push(&one);
  std::cout << "'One' added to queue.\nFront of the queue is: " << *(q.front()) << "\n"
            << "Back of the queue is: " << *(q.back()) << "\n\n";
  

  q.push(&three);
  std::cout << "'Three' added to queue.\nFront of the queue is: " << *(q.front()) << "\n"
            << "Back of the queue is: " << *(q.back()) << "\n\n";

  q.pop();
  std::cout << "Queue popped.\nFront of the queue is: " << *(q.front()) << "\n"
            << "Back of the queue is: " << *(q.back()) << "\n\n";

  q.push(&two);
  std::cout << "'Two' added to queue.\nFront of the queue is: " << *(q.front()) << "\n"
            << "Back of the queue is: " << *(q.back()) << "\n\n";

  q.push(&four);
  std::cout << "'Four' added to queue.\nFront of the queue is: " << *(q.front()) << "\n"
            << "Back of the queue is: " << *(q.back()) << "\n\n";

  q.pop();
  std::cout << "Queue popped.\nFront of the queue is: " << *(q.front()) << "\n"
            << "Back of the queue is: " << *(q.back()) << "\n\n";

  return 0;
}
