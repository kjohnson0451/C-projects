/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *
 *
 *
 *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include <stdio.h>

void quickSort(int arr[], int left, int right) {
  
  int i = left, j = right;
  int tmp;
  int pivot = arr[(left + right) / 2];

  /* partition */
  while (i <= j) {
    while (arr[i] < pivot)
      i++;
    while (arr[j] > pivot)
      j--;
    if (i <= j) {
      /* swap */
      tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;
      i++;
      j--;
    }
  };

  /* recursion */
  if (left < j)
    quickSort(arr, left, j);
  if (i < right)
    quickSort(arr, i, right);
}
 
int main () {
  int a[] = {7, 6, 9, 8, 5, 2, 1, 4, 3};
  int n = sizeof a / sizeof a[0];
  int i;
  for (i = 0; i < n; i++)
    printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
  quickSort(a, 0, n);
  for (i = 0; i < n; i++)
    printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
  return 0;
}
