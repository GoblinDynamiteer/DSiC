/*
 *  Exercise from book
 *  Data Structures in C
 *  by Noel Kalicharan
 *
 *	Exercise 06, Chapter 01
 *  Page 23
 *
 *  Read a file that contains distances
 *	jumped by athletes in a long jump
 *	competition.
 *	Read names and lenghts into a struct
 *	and print out the names in order of
 *	merit. Best jumper first.
 *	Lenght should be a struct defined as in
 *	exercise 5.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NAMELEN 30
#define LINELEN 50
#define NUMJUMPERS 25

typedef struct{
	int m, cm;
}lenght;

typedef struct{
	char name[NAMELEN];
	lenght lenght;
}jumpers;

int loadJumpsFromFile(jumpers j[]);
void sortByJump(jumpers ju[], int entries);

int main(void){
	jumpers jumpers[NUMJUMPERS];
	int entries = loadJumpsFromFile(jumpers);
	sortByJump(jumpers, entries);
	/*	Print results 	*/
	printf("Results:\n");
	for(int i = 0; i< entries; i++){
		/*  %-30s pads string with spaces right	*/
		printf("%-30s\t %dm %02dcm\n", jumpers[i].name,
			jumpers[i].lenght.m, jumpers[i].lenght.cm
		);
	}
	return 0;
}

/*	Loads name and jump lenghts into struct array, returns
 		number of loaded entires */
int loadJumpsFromFile(jumpers j[]){
	FILE * f = fopen("ch01/exercise01_06/jumps.txt", "r");
	char str[LINELEN];
	int k = 0; //jumper athlete index
	while(fgets(str, LINELEN, f) != NULL){
		/*  Get name lenght before jump data	*/
		int n = 0;
		while(!isdigit(str[n])){
			n++;
		}
		/*	Fill char array with null terminators and set name 	*/
		memset(j[k].name, '\0', sizeof(j[k].name));
		strncpy(j[k].name, str, n-1);
		/*	Scan jump lenghts to int variables 	*/
		sscanf(str+n, "%d %d", &j[k].lenght.m, &j[k].lenght.cm);
		k++;
	}
	return k;
}

/*  Converts lenght to centimeters	*/
int convertToCm(lenght l){
	return l.m * 100 + l.cm;
}

/* Sorts array in descending order, longest jump first 	*/
void sortByJump(jumpers ju[], int entries){
	jumpers temp;
	/*	Iterate through array 	*/
	for(int i = 0; i < entries; i++){
		int k = i;
		/*	Iterate through array, compare jump lenghts in cm 	*/
		for(int j = i + 1; j < entries; j++){
			if(convertToCm(ju[j].lenght) > convertToCm(ju[k].lenght)){
				k = j;
			}
		}
		/*	Swap entries 	*/
		temp = ju[i];
		ju[i] = ju[k];
		ju[k] = temp;
	}
}
