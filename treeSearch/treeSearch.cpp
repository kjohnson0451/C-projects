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
#include <queue>

struct tree_el {
  int val;
  struct tree_el * right, * left;
};

typedef struct tree_el node;

void insert(node ** tree, node * item) {
  if(!(*tree)) {
    *tree = item;
    return;
  }
  unsigned short chance = rand();
  if(chance)
    insert(&(*tree)->left, item);
  else
    insert(&(*tree)->right, item);
}

void printout(node * tree) {
  if(tree->left) printout(tree->left);
  printf("%d\n",tree->val);
  if(tree->right) printout(tree->right);
}

void treeBreadthFirst(node* tree) {
  std::queue<node *> treeQueue;
  node* traverse;

  if (tree == NULL)
    return;  /* Nothing to traverse. */

  treeQueue.push(tree);

  while(!treeQueue.empty()) {
    traverse = treeQueue.front();
    treeQueue.pop();

    printf("%d\n",traverse->val);

    if( traverse->left != NULL )
      treeQueue.push(traverse->left);
    if( traverse->right != NULL)
      treeQueue.push(traverse->right);
  }
  return;

}

int main() {
  node * curr, * root;
  int i;

  root = NULL;
  
  srand(time(NULL));

  for(i=1;i<=10;i++) {
    curr = (node *)malloc(sizeof(node));
    curr->left = curr->right = NULL;

    curr->val = rand() % 50;
    insert(&root, curr);
  }

  printf("Default traversal:\n");
  printout(root);
  printf("\n\n");

  printf("Breadth first traversal:\n");
  treeBreadthFirst(root);
  printf("\n\n");

  return 0;
}
