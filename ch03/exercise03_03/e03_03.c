/*
 *  Exercise from book
 *  Data Structures in C
 *  by Noel Kalicharan
 *
 *	Exercise 03, Chapter 03
 *  Page 77
 *
 *  Write a function to sort a linked list of
 *	integers as follows:
 *		a, 	Find the largest value in the list.
 *		b, 	Delete the node and insert value at head
 *		c, 	Repeat a + b at subsequent nodes after head
 *				until list is sorted.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "libll.h"

void printList(node * top);
node * sortList(node * top);

int main(void){
	srand(time(NULL));
	/*	Create list with random values 	*/
	node * top = createNode(rand() % 1001);
	for(int i = 0; i < 12; i++){
		insLast(top, rand() % 1001);
	}
	printList(top);
	top = sortList(top);
	printf("\nSorted List:\n");
	printList(top);
	return 0;
}

/*	Printout values in list 	*/
void printList(node * top){
	int i = 1;
	while(1){
		printf("Node %03d %3d\n",i++, top->value);
		if(isEmpty(getNext(top))){
			break;
		}
		top = getNext(top);
	}
}

/*	Returns node with highest value in list 	*/
node * findMaxValue(node * n){
	node * maxValNode = NULL;
	int val = -1;
	if(!isEmpty(n)){
		val = n->value;
		maxValNode = n;
	}
	while(!isEmpty(n)){
		if(n->value > val){
			val = n->value;
			maxValNode = n;
		}
		n = getNext(n);
	}
	return maxValNode;
}

/*	Sort the list, highest value first 	*/
node * sortList(node * top){
	node * max = findMaxValue(top);
	node * newTop = max;
	top = removeNode(top, max);
	node * in = newTop;
	while(countItems(top)){
		max = findMaxValue(top);
		top = removeNode(top, max);
		in->next = max;
		in = getNext(in);
	}
	in->next = NULL;
	return newTop;
}
