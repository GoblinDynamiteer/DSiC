/*
 *  Exercise from book
 *  Data Structures in C
 *  by Noel Kalicharan
 *
 *	Exercise 02, Chapter 03
 *  Page 77
 *
 *  Write code to reverse the nodes of a linked list.
 *	Use manipulation of pointer fields only. No new
 *	nodes must be created!
 */

#include <stdio.h>
#include "libll.h"

node * reverseList(node * n);
void printList(node * top);

int main(void){
	/*	Add values to list 	*/
	node *top = createNode(12);
	for(int i = 1; i < 10; i++){
		insLast(top, (int)i * 13.75);
	}
	/*	Print lists before and after reverse 	*/
	printf("\nOriginal: \n");
	printList(top);
	top = reverseList(top);
	printf("\nReversed: \n");
	printList(top);
	return 0;
}

/*	Reverse values in list, returns pointer to new top node 	*/
node * reverseList(node * n){
	/*	Counts items in list, i will be the last node 	*/
	int i = countItems(n);
	/*	getNode returns node at place i 	*/
	node * newTopNode = getNode(n, i);
	/*	Pointer used to iterate through list 	*/
	node * it = newTopNode;
	while(i){
		it->next = getNode(n, i);
		it = getNext(it);
		i--;
	}
	it->next = NULL;
	return newTopNode;
}

/*	Printout values in list 	*/
void printList(node * top){
	int i = 1;
	while(1){
		printf("Node %02d %3d\n",i++, top->value);
		if(isEmpty(getNext(top))){
			break;
		}
		top = getNext(top);
	}
}
