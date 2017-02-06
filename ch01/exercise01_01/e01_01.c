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
 *  Textfile from
 *  https://github.com/weirdvector/kalicharan/blob/master/ch1/phonenumbers.txt
 */

#include <stdio.h>
#include <stdbool.h> //bool type
#include <stdlib.h> //exit()
#include <ctype.h> //isspace()

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

int main(void){
	FILE * numberFile = fopen(
		"ch01/exercise01_01/phonenumbers.txt", "r");
 	if(!numberFile){
		printf("Error opening file!");
		exit(1);
	}
	person persons[MAXPERSONS];
	getData(numberFile, persons);

	return 0;
}

int getData(FILE * file, person p[]){
	int i = 0;
	char tempStr[CHARBUFFER*2];
	char c;
	while(getString(file, tempStr)){
		getName(tempStr, &p[i]);
		getNumber(tempStr, &p[i++]);
		printf("Name: %s Number: %s\n",p[i-1].name, p[i-1].number);
	}
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

/*	Extracts name part from textfile 	*/
void getName(char string[], person * p){
	int i = 0, j = 0;
	while(!isdigit(string[i])){
		p->name[j++] = string[i++];
	}
	p->name[j-1] = '\0';
}

/*	Extracts phone number part from textfile 	*/
void getNumber(char string[], person * p){
	int i = 0, j = 0;
	while(!isdigit(string[i])){
		i++;
	}
	/*	Copy chars from textfile to string	*/
	while(string[i] != '\0'){
		p->number[j++] = string[i++];
	}

	p->number[j] = '\0';
}
