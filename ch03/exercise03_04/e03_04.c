/*
 *  Exercise from book
 *  Data Structures in C
 *  by Noel Kalicharan
 *
 *	Exercise 04, Chapter 03
 *  Page 77
 *
 *  Write a function to free all the nodes
 *	of a given linked list.
 */

#include <stdio.h>
#include "libll.h"

#define LISTSIZE 100

int main(void){
	node * list = NULL;
	for(int i = 0; i < LISTSIZE; i++){
		list = insLast(list, (int)1+i*1.75);
	}
	int count = countItems(list);
	printf("Count: %d\n", count);
	node * nodes = list;
	for(int i = 0; i< LISTSIZE; i++){
		printf("Node %03d - %03d\n", i+1, nodes->value);
		nodes = getNext(nodes);
	}
	list = freeNodes(list);
	if(isEmpty(list)){
		printf("List is empty");
	}
	return 0;
}
