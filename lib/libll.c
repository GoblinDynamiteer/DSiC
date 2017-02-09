/*   Integer linked list functions  */

#include "libll.h"

/*  Inserts value last in list   */
void insLast(node * n, int val){
  while(!isEmpty(getNext(n))){
    n = getNext(n);
  }
  n->next = createNode(val);
}

/*  Inserts value first in list,
    returns pointer to first node   */
node * insFirst(node * n, int val){
  if(isEmpty(n)){
    n = createNode(val);
  }
  else{
    node * temp = n;
    n = createNode(val);
    n->next = temp;
  }
  return n;
}

/*  Check if node is empty  */
bool isEmpty(node * n){
  return (n == NULL);
}

/*  Creates a new node, returns pointer   */
node * createNode(int val){
  node * newNode = (node *)malloc(sizeof(node));
  /*  Security check   */
  if(isEmpty(newNode)){
    printf("Malloc of new node failed!\n");
    return NULL;
  }
  newNode->value = val;
  newNode->next = NULL;
  return newNode;
}

/*  Returns the next node in the list   */
node * getNext(node * n){
  return n->next;
}
