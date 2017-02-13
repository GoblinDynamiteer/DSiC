/*
 *  Exercise from book
 *  Data Structures in C
 *  by Noel Kalicharan
 *
 *	Exercise 05, Chapter 03
 *  Page 78
 *
 *  Write a function that takes three arguments:
 *	- A pointer to a linked list of integers.
 *	- 2 integers, n and i
 *
 *	Insert n after the i-th element.
 *	if i is 0: insert at head.
 *	if i > elements in list: insert last.
 */

#include <stdio.h>
#include "libll.h"

/*	Inserts value at position i in list 	*/
node * insertAt(node * list, int i, int n){
	if(i <= 0){
		return insFirst(list, n);
	}
	else if(i >= countItems(list)){
		return insLast(list, n);
	}
	else{
		node * top = list;
		while(--i){
			list = getNext(list);
		}
		node * temp = getNext(list);;
		list->next = createNode(n);
		list->next->next = temp;
		return top;
	}
}

int main(void){
	/*	Create list with values 	*/
	node * list = NULL;
	for(int i = 0; i < 10; i++){
		list = insLast(list, i+33);
	}
	/*	Print list before added values 	*/
	printList(list);
	printf("\n");
	/*	Test function 	*/
	list = insertAt(list, 0, 666);
	list = insertAt(list, 1000, 667);
	list = insertAt(list, 5, 668);
	list = insertAt(list, 12, 951);
	/*	Print list after added values 	*/
	printList(list);
	return 0;
}
