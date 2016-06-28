
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 * Given a stream of integers, this program gives the rank 
 * of a given integers within that stream.
 *
 * UNFINISHED
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include <iostream>

class RankNode {
public:
  int left_size;
  RankNode* left;
  RankNode* right;
  int data;

  RankNode(int d) {
    data = d;
    left_size = 0;
    left = NULL;
    right = NULL;
  }

  void insert(int d) {
    if( d <= data) {
      if (left != NULL) left->insert(d);
      else left = new RankNode(d);
      left_size++;
    } else {
      if (right != NULL) right->insert(d);
      else right = new RankNode(d);
    }
  }

  int getRank(int d) {
    if (d == data) {
      return left_size;
    } else if (d < data) {
      if (left == NULL) return -1;
      else return left->getRank(d);
    } else {
      int right_rank = (right == NULL ? -1 : right->getRank(d));
      if (right_rank == -1) return -1;
      else return left_size + 1 + right_rank;
    }
  }
};


class Question {
private:
  RankNode* root;
public:
  Question() {
    root = NULL;
  }
  
  void track(int number) {
    if (root == NULL) {
      root = new RankNode(number);
    } else {
      root->insert(number);
    }
  }

  int getRankOfNumber(int number) {
    return root->getRank(number);
  }
};

int main(int argc, char *argv[]) {

  Question* myQ = new Question;

  myQ->track(5);
  myQ->track(7);
  myQ->track(47);
  myQ->track(15);
  myQ->track(192);
  myQ->track(245);
  myQ->track(13);
  myQ->track(2);
  myQ->track(91);
  myQ->track(623);
  myQ->track(542);
  myQ->track(929);
  myQ->track(935);
  myQ->track(651);

  std::cout << "2 is of rank " << myQ->getRankOfNumber(2) << "\n";
  std::cout << "5 is of rank " << myQ->getRankOfNumber(5) << "\n";
  std::cout << "7 is of rank " << myQ->getRankOfNumber(7) << "\n";
  std::cout << "13 is of rank " << myQ->getRankOfNumber(13) << "\n";

  return 0;
}
