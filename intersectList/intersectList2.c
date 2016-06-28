#include <stdlib.h>
#include <stdio.h>
#include <time.h>
 
// C99 Program (not ANSI C!)
//
// gcc -std=c99 -Wall -Wextra -O3
 
const int nb_numbers1=16; // any large number
const int nb_numbers2=4;

int rand_range( uint lower, uint higher ) {
  return lower + rand() / (RAND_MAX / (higher - lower + 1) + 1) ;
}

 
////////////////////////////////////////
//
// a list node
//
struct list_node { 
  int data;
  struct list_node * next;
};
 
////////////////////////////////////////
//
// structure that holds
// the head and tail of 
// a list
//
struct list {
  struct list_node * head;
  struct list_node * tail;
};
 
////////////////////////////////////////
//
// quite minimalistic append
//
void append( struct list * this_list, int number )
{
  struct list_node * new_node = malloc( sizeof (struct list_node) );
 
  new_node->data=number;
  new_node->next=NULL;
 
  if (this_list->tail)
    {
      this_list->tail->next = new_node;
      this_list->tail = new_node; 
    }
  else
    this_list->head=this_list->tail=new_node;
}
 
////////////////////////////////////////
//
// appends a node to a list
// and unlinks it
void append_and_unlink_node( struct list * this_list, 
                             struct list_node * this_node )
{
  if (this_list->tail)
    {
      this_list->tail->next=this_node;
      this_list->tail=this_node;
    }
  else
    this_list->head=this_list->tail=this_node;
 
  this_node->next=NULL; // unlinks
}
 
 
////////////////////////////////////////
//
// shows the content of a list
//
void show_list(struct list * this_list )
{
  struct list_node * current = this_list->head;
  int sorted=1;
  int last=0;
  while (current)
    {
      printf(" %d",current->data);
      if (last > current->data) sorted=0;
      last=current->data;
      current=current->next;
    }
  printf("\n");
  if (sorted)
    printf("sorted.\n");
}
 
 
////////////////////////////////////////
//
// the radix sort on simply-linked
// list
//
//
void radix_sort_list(struct list * this_list, 
               int base // in bits
               )
{
  int i,s;
  const int nb_buckets=1<<base;
  const unsigned mask=nb_buckets-1;
  const int iterations=(sizeof(int)*8+base-1)/base; // with rounding!
  struct list buckets[nb_buckets];
 
  // exits if the list is empty
  //
  if (this_list->head==NULL) 
    return;
 
  // do the iterations
  //
  for (i=0,s=0;i<iterations; i++,s+=base)
    {
      int b,c;
      struct list_node * current = this_list->head;
 
      // clears the buckets
      for (b=0;b<nb_buckets;b++)
        buckets[b].head=buckets[b].tail=NULL;
 
 
      // scans the original list's items
      // one by one and transfer them to 
      // buckets
      //
      while (current)
        {
          struct list_node * next = current->next;
 
          int num = current->data;
          int bucket = (num >> s) & mask;
 
          append_and_unlink_node(&buckets[bucket],current);
 
          // necessary because here
          // the node is unlinked from
          // the main list
          //
          current=next;
        }
 
      // sews the buckets back together
      // while checking for empty buckets
      //
      for (c=0,b=0;b<nb_buckets;b++)
        if (buckets[b].head)
          {
            if (c)
              // this is not the first (non empty)
              // bucket
              {
                this_list->tail->next=buckets[b].head;
                this_list->tail=buckets[b].tail;
              }
            else
              // first non-empty bucket
              //
              {
                this_list->head=buckets[b].head;
                this_list->tail=buckets[b].tail;
                c=1;
              }
          }
 
      
    }
 
  // buckets pointers can be just
  // dropped (no deallocation needed)
  // 
}

void intersectList(struct list* list1, struct list* list2, struct list* intersect_list) {

  struct list_node* current1 = list1->head;
  struct list_node* current2 = list2->head;

  int i = 0, j = 0;

  radix_sort_list(list1,4);
  radix_sort_list(list2,4);

  while(current1 && current2) {
    if(current1->data < current2->data)
      current1 = current1->next;
    else if(current1->data > current2->data)
      current2 = current2->next;
    else {
      append(intersect_list, current1->data);
      current1 = current1->next;
      current2 = current2->next;
    }
  }

}

int main()
{
  int i;
  struct list list1={NULL,NULL};
  struct list list2={NULL,NULL};
  struct list intersect_list = {NULL,NULL};

  // fills the list with
  // random numbers
  //
  srand(time(NULL));
  for (i=0;i<nb_numbers1;i++)
    append( &list1, rand_range(1,16));
  for (i=0;i<nb_numbers2;i++)
    append( &list2, rand_range(1,16));
  
  show_list(&list1);
  show_list(&list2);

  //show_list(&list1);
  //show_list(&list2);

  intersectList(&list1, &list2, &intersect_list);

  show_list(&intersect_list);

  return 0;
}
