/*
 *  Exercise from book
 *  Data Structures in C
 *  by Noel Kalicharan
 *
 *	Exercise 08, Chapter 03
 *  Page 78
 *
 *  Write a function that takes a binary
 *	number stored in a linked list, as in
 *	exercise 07. Traverse the list and return
 *  the decimal equivalence.
 */

#include <stdio.h>
#include <math.h>
#include "libll.h"

node * toBase(int decimal, int base);
node * toBinary(int decimal);
int toDec(node * n);
void printBinaryList(node * list);

int main(void){
	int dec = 827829;
	node * binary = toBinary(dec);
	int decConverted = toDec(binary);
	if(dec == decConverted){
		printf("Conversion success!\n");
		printBinaryList(binary);
		printf(" is %d in decimal.\n", decConverted);
	}
	else{
		printf("Conversion failed!\n");
	}
	return 0;
}

/*	Convert decimal to base
		-- taken from exercise 07 	*/
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

/*	Convert binary stored in list to decimal 	*/
int toDec(node * n){
	int dec = 0;
	for(int i = countItems(n) -1; i >= 0; i--){
		dec += n->value * (int)pow(2,i);
		n = getNext(n);
	}
	return dec;
}

/*	Print list values	*/
void printBinaryList(node * list){
	int count = countItems(list);
	for(int i = 0; i < count; i++){
		printf("%d", list->value);
		list = getNext(list);
	}
}
