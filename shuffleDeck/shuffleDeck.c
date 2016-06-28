/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *
 *
 *
 *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUMCARDS 52

struct space_s {
  int cardVal;
  int instances;
};

typedef struct space_s space;

int rand_range( int lower, int higher ) {
  return lower + rand() / (RAND_MAX / (higher - lower + 1) + 1) ;
}

void shuffleArray( int cards[], int numcards) {
  int i;
  for(i = 0; i < numcards; i++) {
    int k = rand_range(0, i);
    int temp = cards[k];
    cards[k] = cards[i];
    cards[i] = temp;
  }
}

int addCardToTable( space* table, int cardVal, int place ) {
  if( table[place].instances == 0 ) {
    table[place].cardVal = cardVal;
    table[place].instances++;
    return 0;
  }
  if( table[place].instances > 0 && table[place].cardVal == cardVal ) {
    table[place].instances++;
    return 0;
  } else 
    return -1;
}

int main(int argc, char *argv[]) {

  srand(time(NULL));
  
  const unsigned short numcards = NUMCARDS;
  unsigned short i, j;
  int deck[numcards];
  space table[10];
  int optimalPlace;
  int numDiscard = 0;
  int result;
  
  //Initialize Deck
  for(i=0;i<numcards;i++)
    deck[i] = (i % 13)+1;

  //Shuffle Deck
  shuffleArray(deck, numcards);
  
  //Initialize table
  for(i=0;i<10;i++) {
    table[i].cardVal = 0;
    table[i].instances = 0;
  }
  
  //Print deck
  for(i=0;i<numcards;i++)
    printf("%d ",deck[i]);

  printf("\n\n");

  for(i=0; i<NUMCARDS; i++) {
    optimalPlace = deck[i]*10/13;
    if(!optimalPlace) optimalPlace = 1;
    if(addCardToTable(table, deck[i], optimalPlace-1))
      numDiscard++;

    for(j=0;j<10;j++) {
      printf("%d:%d ", table[j].cardVal, table[j].instances);
    }
    printf("\n%d\n", numDiscard);   

    for(j=0;j<10;j++) {
      if(table[j].instances == 0)
        break;
      if(j == 9 && table[j].instances > 0) {
        printf("You win.\n");
        return 0;
      } 
    }

    if(numDiscard > 5) {
      printf("Discard pile reached 6. You lost.\n");
      return 1;
    }
  }
  printf("\n\n");

  return 0;
}
