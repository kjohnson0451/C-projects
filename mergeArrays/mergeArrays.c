/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 * Merges two sorted arrays, A and B, into A. A has a buffer
 * large enough to store B.
 *
 *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include <stdio.h>

void merge(unsigned short a[], unsigned short b[], short lastA, short lastB) {
  short indexA = lastA - 1;
  short indexB = lastB - 1;
  short indexMerged = lastB + lastA - 1;

  while( indexB >= 0) {
    if (indexA >= 0 && a[indexA] > b[indexB]) {
      a[indexMerged] = a[indexA];
      indexA--;
    } else {
      a[indexMerged] = b[indexB];
      indexB--;
    }
    indexMerged--;
  }

}

int main(int argc, char *argv[]) {

  unsigned short A[15] = {1, 4, 7, 14, 16, 19, 22, 25, 29, 40};  
  unsigned short B[5] = {2, 5, 13, 17, 21};
  unsigned short i;

  printf("Array A:\n");
  for(i=0;i<11;i++)
    printf("%d ",A[i]);
  printf("\n");

  printf("Array B:\n");
  for(i=0;i<5;i++)
    printf("%d ",B[i]);
  printf("\n");
  

  merge(A, B, 10, 5);
  
  printf("Merged array:\n");
  for(i=0;i<15;i++)
    printf("%d ",A[i]);
  printf("\n");
  
  return 0;
}
