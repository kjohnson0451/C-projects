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

int rand_range( int lower, int higher ) {
  return lower + rand() / (RAND_MAX / (higher - lower + 1) + 1) ;
}

int* pickM(int orig[], int sizeOfOrig, int m) {
  int i;
  int* subset = malloc((int)sizeof(int) * m);
  
  for( i = 0; i < m; i++ )
    subset[i] = orig[i];

  for( i = m; i < sizeOfOrig; i++) {
    int k = rand_range(0, i);
    if( k<m ) subset[k] = orig[i];
  }

  return subset;
}

int main(int argc, char *argv[]) {

  int i;
  int a[20];
  int* b;

  srand(time(NULL));

  for(i=0;i<20;i++)
    a[i] = i+1;

  b = pickM(a, 20, 5);

  for(i=0;i<5;i++)
    printf("%d\n", b[i]);

  return 0;
}
