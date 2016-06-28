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

typedef unsigned uint;

struct linked_list {
  uint data;
  struct linked_list *next;
};

typedef struct linked_list node;

void printList(node* list) {
  node* n = list;
  
  while( n != NULL) {
    printf("%d ", n->data);
    n = n->next;
  }
  printf("\n");
}

uint rand_range( uint lower, uint higher ) {
  return lower + rand() / (RAND_MAX / (higher - lower + 1) + 1) ;
}

void radix_sort(int *a, int n) {
  int i, b[MAX], m = 0, exp = 1;
  for (i = 0; i < n; i++) {
    if (a[i] > m)
      m = a[i];
  }
  while (m / exp > 0) {
    int box[10] = {
      0
    }
    ;
    for (i = 0; i < n; i++)
      box[a[i] / exp % 10]++;
    for (i = 1; i < 10; i++)
      box[i] += box[i - 1];
    for (i = n - 1; i >= 0; i--)
      b[--box[a[i] / exp % 10]] = a[i];
    for (i = 0; i < n; i++)
      a[i] = b[i];
    exp *= 10;
    #ifdef SHOWPASS
    printf("\n\nPASS   : ");
    print(a, n);
    #endif
  }
}

int main(int argc, char *argv[]) {

  uint i;

  node* list = (node *)calloc(1, sizeof(node));
  node* currentNode = list;

  srand(time(NULL));
  
  for( i = 0; i < 10; i++) {

    currentNode->data = rand_range(1, 1000);
    currentNode->next = (node *)calloc(1, sizeof(node));    
    currentNode = currentNode->next;
  }

  currentNode->data = rand_range(1, 100);

  printList(list);

  return 0;
}
