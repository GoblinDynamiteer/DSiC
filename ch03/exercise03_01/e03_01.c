/*
 *  Exercise from book
 *  Data Structures in C
 *  by Noel Kalicharan
 *
 *	Exercise 01, Chapter 03
 *  Page 77
 *
 *  Write a function that, given a pointer to
 *	a linked list, returns 1 if the list is
 *	sorted in ascending order, 0 otherwise.
 */

#include <stdio.h>
#include "libll.h"

bool isSortedAscending(node * n){
	bool sorted = 1;
	while(!isEmpty(getNext(n))){
		if(n->value > n->next->value){
			sorted = 0;
			break;
		}
		n = getNext(n);
	}
	return sorted;
}

int main(void){
	node *n, *top;

	/*	Creates a sorted linked list: 	*/
	n = createNode(7);
	top = n;
	insLast(top, 12);
	top = insFirst(top, 3);
	top = insFirst(top, 1);
	int i = 1;
	for(node *p = top; !isEmpty(p); p = p->next){
		printf("Node %d: %d\n", i++, p->value);
	}
	/*	Should output 1 	*/
	printf("Array is sorted: %d\n\n", isSortedAscending(top));

	/*	Messes the linked list up, adding non-sorted values: 	*/
	top = insFirst(top, 37);
	insLast(top, 14);
	i = 1;
	for(node *p = top; !isEmpty(p); p = p->next){
		printf("Node %d: %d\n", i++, p->value);
	}
	/*	Should output 0 	*/
	printf("Array is sorted: %d\n\n", isSortedAscending(top));
	return 0;
}
