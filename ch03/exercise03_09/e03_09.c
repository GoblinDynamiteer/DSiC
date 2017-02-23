/*
 *  Exercise from book
 *  Data Structures in C
 *  by Noel Kalicharan
 *
 *	Exercise 09, Chapter 03
 *  Page 78
 *
 *  You are given two pointers b1, b2.
 *  Each points to a binary number stored
 	as in exercise 7. Write a function
	that does binary addition and returns
	a pointer to a new binary number.
	Use:
		1	Functions as in ex 7 and 8
		2	bit-by-bit addition

 */

#include <stdio.h>
#include <math.h>
#include "libll.h"

node * toBase(int decimal, int base);
node * toBinary(int decimal);
node * addBinary(node * b1, node * b2);
int toDec(node * n);
void printBinaryList(node * list);

int main(void){
	node * b1 = toBinary(123);
	node * b2 = toBinary(5315);
	printBinaryList(b1);
	printf(" + ");
	printBinaryList(b2);
	printf(" = ");
	node * addResult = addBinary(b1,b2);
	printBinaryList(addResult);
	printf("\n%d + %d = %d",
		toDec(b1),
		toDec(b2),
		toDec(addResult)
	);
	return 0;
}

/*	 Binary additon by using functions from exercises 7 & 8	*/
node * addBinary(node * b1, node * b2){
	return toBinary(toDec(b1) + toDec(b2));
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
