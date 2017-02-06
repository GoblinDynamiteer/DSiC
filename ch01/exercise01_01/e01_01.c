/*
 *  Exercise from book
 *  Data Structures in C
 *  by Noel Kalicharan
 *
 *	Exercise 01, Chapter 01
 *  Page 23
 *
 *  Read names and phone numbers into a struct array, sort by name.
 *  Request name and print number, use binary search.
 *
 *  Textfile from:
 *  https://github.com/weirdvector/kalicharan/blob/master/ch1/phonenumbers.txt
 * 	Some entries added by me.
 */

#include <stdio.h>
#include <stdbool.h> //bool type
#include <stdlib.h> //exit()
#include <ctype.h> //isspace()
#include <string.h> //isspace()

#define MAXPERSONS 20
#define CHARBUFFER 30

typedef struct{
	char number[CHARBUFFER];
	char name[CHARBUFFER];
}person;

int getData(FILE * file, person p[]);
bool getString(FILE * file, char string[]);
void getName(char string[], person * p);
void getNumber(char string[], person * p);
void sortByName(person p[], int entries);
int searchByName(person p[], char name[], int low, int high);

int main(void){
	FILE * numberFile = fopen(
		"ch01/exercise01_01/phonenumbers.txt", "r");
 	if(!numberFile){
		printf("Error opening file!");
		exit(1);
	}
	/*	Declare struct array 	*/
	person persons[MAXPERSONS];
	int entries = getData(numberFile, persons);
	sortByName(persons, entries);
	printf("Enter name: ");
	char search[CHARBUFFER];
	fgets(search, CHARBUFFER, stdin);
	search[strlen(search)-1] = '\0';
	int i = searchByName(persons, search, 0, entries);
	if(i >= 0){
		printf("Name: %s - Phone: %s",
			persons[i].name,
			persons[i].number
		);
	}
	else{
		printf("Name not found!");
	}

	return 0;
}

/*	Extract data from textfile to struct 	*/
int getData(FILE * file, person p[]){
	int i = 0;
	char tempStr[CHARBUFFER*2];
	char c;
	while(getString(file, tempStr)){
		getName(tempStr, &p[i]);
		getNumber(tempStr, &p[i++]);
		if(i > MAXPERSONS){
			printf("Array size limit reached!");
			break;
		}
	}
	return i;
}

/*	Copies line from textfile to string 	*/
bool getString(FILE * file, char string[]){
	char ch;
	int i = 0;
	/*	Skip white characters 	*/
	while(isspace(ch = getc(file))){
		;
	}
	if(ch == EOF){
		return 0;
	}
	/*	Copy chars from textfile to string	*/
	do{
		string[i++] = ch;
	}while((ch = getc(file)) != '\n' &&
		(ch != EOF));

	string[i] = '\0';
	return 1;
}

/*	Extracts name part from string 	*/
void getName(char string[], person * p){
	int i = 0, j = 0;
	/*	Runs until first digit is reached in string 	*/
	while(!isdigit(string[i])){
		p->name[j++] = string[i++];
	}
	p->name[j-1] = '\0';
}

/*	Extracts phone number part from string 	*/
void getNumber(char string[], person * p){
	int i = 0, j = 0;
	while(!isdigit(string[i])){
		i++;
	}
	/*	Copy chars from string to phone number	*/
	while(string[i] != '\0'){
		p->number[j++] = string[i++];
	}
	p->number[j] = '\0';
}

/*	Sort array by first name 	*/
void sortByName(person p[], int entries){
	person temp;
	/*	Iterate through array 	*/
	for(int i = 0; i < entries; i++){
		/*	k is array index entry to check 	*/
		int k = i;
		/*	Iterate through array, compare names 	*/
		for(int j = i + 1; j < entries; j++){
			if(strcmp(p[j].name, p[k].name) < 0){
				k = j;
			}
		}
		/*	Swap entries 	*/
		temp = p[i];
		p[i] = p[k];
		p[k] = temp;
	}
	return;
}

/*	Find phone number by binary search 	*/
int searchByName(person p[], char name[], int low, int high){
	int middle;
	while(low <= high){
		middle = low + (high - low) / 2;
		if(strcmp(name, p[middle].name) < 0){
			high = middle - 1;
		}
		else if(strcmp(name, p[middle].name) > 0){
			low = middle + 1;
		}
		else{
			if(strcmp(name, p[middle].name) == 0){
				return middle; //Found at index middle
			}
		}
	}
	/*	Name not found 	*/
	return -1;
}
