/*
 *  Exercise from book
 *  Data Structures in C
 *  by Noel Kalicharan
 *
 *	Exercise 07, Chapter 03
 *  Page 78
 *
 *  Write a function that, given an integer n
 *  converts n to binary, and stores each digit
 *  in a linked list. The least significant bit
 *  shall be placed in the head of the list.
 *	Return a pointer to the head of the list.
 */

#include <stdio.h>
#include "libll.h"

node * toBase(int decimal, int base);
node * toBinary(int decimal);
void printBinaryList(node * list);

int main(void){
	int decimal = 56982;
	node * binaryString = toBinary(decimal);
	printf("%d is ", decimal);
	printBinaryList(binaryString);
	printf(" in binary!");
	return 0;
}

/*	Convert decimal to base 	*/
node * toBase(int decimal, int base){
	int i = 0, num;
	node * binary = NULL;
	for(decimal; decimal != 0; decimal /= base){
		num = decimal % base;
		binary = insFirst(binary, num);
		i++;
	}
	return binary;
}

node * toBinary(int decimal){
	return toBase(decimal, 2);
}

/*	Print list values	*/
void printBinaryList(node * list){
	int count = countItems(list);
	for(int i = 0; i < count; i++){
		printf("%d", list->value);
		list = getNext(list);
	}
}
