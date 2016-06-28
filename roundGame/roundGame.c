#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "dict.h"

Dict d ;

float prob( int n ) {
  switch(n) {
  case 0:
    return 0.5;
  case 1:
    return 0.3;
  case 2:
    return 0.2;
  }
  return 0;
}

float scoreProb( int round, int score ) {
  float result;
  if(round == 1) {
    return prob(score);
  }
  /*
    If a value is found in the hash table at
    "round,score", return that value
   */
  
  result = (scoreProb(round-1, score)*prob(0)
          + scoreProb(round-1, score-1)*prob(1)
          + scoreProb(round-1, score-2)*prob(2));
  
  /*
    Add result to hash table at "round,score"
   */

  return result;
}

int main(int argc, char** argv)
{
    int score, round;
    d = DictCreate();

    /*
    DictInsert(d, "foo", "hello world");
    puts(DictSearch(d, "foo"));
    DictInsert(d, "foo", "hello world2");
    puts(DictSearch(d, "foo"));
    DictDelete(d, "foo");
    puts(DictSearch(d, "foo"));
    DictDelete(d, "foo");
    assert(DictSearch(d, "foo") == 0);
    DictDelete(d, "foo");

    for(i = 0; i < 10000; i++) {
      sprintf(buf, "%d", i);
      DictInsert(d, buf, buf);
    }
    */

    round = atoi(argv[1]);
    score = atoi(argv[2]);

    printf("%f\n", scoreProb(round, score));

    DictDestroy(d);

    return 0;
}

    
