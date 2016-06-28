/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 * Takes a matrix and returns the sub matrix with the greatest
 * sum
 *
 *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWCOUNT 3
#define COLCOUNT 3

int rand_range( int lower, int higher ) {
  return lower + rand() / (RAND_MAX / (higher - lower + 1) + 1) ;
}

int maxSubMatrix(int matrix[ROWCOUNT][COLCOUNT]) {
  int partialSum[COLCOUNT];
  int maxSum = 0, tempMaxSum;
  int rowStart, rowEnd, i, j;
  
  for( rowStart = 0; rowStart < ROWCOUNT; rowStart++ ) {
    for(j=0;j<COLCOUNT;j++)
      partialSum[j] = 0;
    
    for(rowEnd = rowStart; rowEnd < ROWCOUNT; rowEnd++) {
      for(i=0;i<COLCOUNT;i++)
        partialSum[i] += matrix[rowEnd][i];
      
      tempMaxSum = maxSubArray(partialSum, COLCOUNT);
      
      if(tempMaxSum > maxSum)
        maxSum = tempMaxSum;
    }
  }
  return maxSum;
  
}

int maxSubArray(int array[], int N) {
  int maxSum = 0;
  int runningSum = 0;
  int i;
  
  for(i=0;i<N;i++) {
    runningSum += array[i];
    if(runningSum > maxSum)
      maxSum = runningSum;
    
    if (runningSum < 0)
      runningSum = 0;
  }
  return maxSum;
}

int main(int argc, char *argv[]) {

  
  int m[ROWCOUNT][COLCOUNT];
  int i, j;

  srand(time(NULL));

  for( i=0; i<ROWCOUNT; i++) {
    for( j=0; j<COLCOUNT; j++) {
      m[i][j] = rand_range(-9,9);
      printf("%d ", m[i][j]);
    }
    printf("\n");
  }

  printf("\nThe sum of the greatest sub matrix is %d\n", maxSubMatrix(m));

  return 0;
}
