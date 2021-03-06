/*
 *  Exercise from book
 *  Data Structures in C
 *  by Noel Kalicharan
 *
 *	Exercise 05, Chapter 01
 *  Page 23
 *
 *  Use a structure to hold lengths in
 *	meter/centimeter. Write functions
 *	that compares, adds and subtracts
 *	two lengths.
 */

#include <stdio.h>

typedef struct{
	int m, cm;
}length;

int compareLen(length l1, length l2);
length addLen(length l1, length l2);
length subLen(length l1, length l2);

int main(void){
	length l1, l2, res;
	l1.m = 3;
	l1.cm = 75;
	l2.m = 2;
	l2.cm = 12;
	res = addLen(l1, l2);
	printf("%dm %dcm + %dm %dcm = %dm %dcm\n",
		l1.m, l1.cm, l2.m, l2.cm,
		res.m, res.cm
	);
	res = subLen(l1, l2);
	printf("%dm %dcm - %dm %dcm = %dm %dcm\n",
		l1.m, l1.cm, l2.m, l2.cm,
		res.m, res.cm
	);
	return 0;
}

/*  Converts length to centimeters	*/
int convertToCm(length l){
	return l.m * 100 + l.cm;
}

/*	Conerts centimeters to struct length 	*/
length convertCmToStruct(int cm){
	length res;
	res.m = (int)(cm / 100);
	res.cm = (int)(cm % 100);
	return res;
}

/*	Compare two lengths, unsure what is wanted here,
		returns difference	*/
int compareLen(length l1, length l2){
	return convertToCm(l1) - convertToCm(l2);
}

/*	Addition, returns result as length struct 	*/
length addLen(length l1, length l2){
	return convertCmToStruct(
		convertToCm(l1) + convertToCm(l2)
	);
}

/*	Subtraction, returns result as length struct 	*/
length subLen(length l1, length l2){
	return convertCmToStruct(
		convertToCm(l1) - convertToCm(l2)
	);
}
