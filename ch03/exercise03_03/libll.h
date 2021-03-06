/*   Integer linked list functions  */

#ifndef _LIBLL_H
#define _LIBLL_H

#include <stdlib.h>
#include <stdio.h>

typedef int bool;

typedef struct _S_LLINT{
  int value;
  struct _S_LLINT * next;
}node;

void insLast(node * n, int val);
node * insFirst(node * n, int val);
bool isEmpty(node * n);
node * createNode(int val);
node * getNext(node * n);
node * getNode(node * n, int num);
node * removeNode(node * list, node * n);
int countItems(node * n);

#endif
