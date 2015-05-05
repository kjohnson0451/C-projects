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
  std::cout << "'One' added to queue. Front of the queue is: " << *(q.front()) << "\n";

  q.push(&three);
  std::cout << "'Three' added to queue. Front of the queue is: " << *(q.front()) << "\n";

  q.pop();
  std::cout << "Queue popped. Front of the queue is: " << *(q.front()) << "\n";

  q.push(&two);
  std::cout << "'Two' added to queue. Front of the queue is: " << *(q.front()) << "\n";

  q.push(&four);
  std::cout << "'Four' added to queue. Front of the queue is: " << *(q.front()) << "\n";

  q.pop();
  std::cout << "Queue popped. Front of the queue is: " << *(q.front()) << "\n";

  return 0;
}
