/*
 *  Exercise from book
 *  Data Structures in C
 *  by Noel Kalicharan
 *
 *	Exercise 06, Chapter 03
 *  Page 78
 *
 *  Store strings as chars in a linked list,
 *	one char per node.
 *	Write functions:
 *		replaceChar(list, c1, c2) -> replaces char 1 with char 2
 *		deleteChar(list, c) -> deletes all occurances of c
 *		toUpperChar(list) -> convert string to uppercase
 *		getChars(list) -> return a new list of characters
 *					used in the original list, sorted, lowercased.
 *		isSubString(list1, list2) -> determine if list1 is
 *					a substring of list 2.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h> //toupper() islower()
#include "libll.h" //can use integer linked list for holding chars


void printListAsChars(node * list);
node * replaceChar(node * string, char c1, char c2);
node * deleteChar(node * string, char c1);
void * toUpperChar(node * string);
node * getChars(node * string);
bool isSubString(node * s1, node * s2);

int main(void){
	node * string1 = NULL;
	node * string2 = NULL;
	node * string3 = NULL;
	node * string4 = NULL;
	char * text1 = "Text is super cool, wow!\0";
	char * text2 = "Rainbow Delta Hexagon Supper\0";
	char * text3 = "Hexagon Supper\0";
	char * text4 = "Roinbaw Delta\0";

	/*	Set chars to linked lists 	*/
	int len = strlen(text1);
	for(int i = 0; i < len; i++){
		string1 = insLast(string1, text1[i]);
	}
	len = strlen(text2);
	for(int i = 0; i < len; i++){
		string2 = insLast(string2, text2[i]);
	}
	len = strlen(text3);
	for(int i = 0; i < len; i++){
		string3 = insLast(string3, text3[i]);
	}
	len = strlen(text4);
	for(int i = 0; i < len; i++){
		string4 = insLast(string4, text4[i]);
	}

	/*	Print original string 	*/
	printListAsChars(string1);

	/*	Replace o with a and print new string	*/
	string1 = replaceChar(string1, 'o', 'a');
	printf("\n");
	printListAsChars(string1);

	/*	Remove all a from string and print new string	*/
	string1 = deleteChar(string1, 'a');
	printf("\n");
	printListAsChars(string1);

	/*	Converts string to uppercase 	*/
	toUpperChar(string1);
	printf("\n");
	printListAsChars(string1);

	/*	Gets a linked list of lowercased,
			sorted chars from string1 	*/
	node * sorted = getChars(string1);
	printf("\n");
	printListAsChars(sorted);
	printf("\n");
	if(isSubString(string3, string2)){
		printListAsChars(string3);
		printf(" is a substring of ");
		printListAsChars(string2);
	}
	if(!isSubString(string4, string2)){
		printListAsChars(string4);
		printf(" is NOT a substring of ");
		printListAsChars(string2);
	}
	return 0;
}

/*	Print list values	*/
void printListAsChars(node * list){
	int count = countItems(list);
	for(int i = 0; i < count; i++){
		printf("%c", list->value);
		list = getNext(list);
	}
}

/*	Replace c1 with c2 in string 	*/
node * replaceChar(node * string, char c1, char c2){
	node * top = string;
	while(!isEmpty(string)){
		if(string->value == c1){
			string->value = c2;
		}
		string = getNext(string);
	}
	return top;
}

/*	Deletes occurences of c1 	*/
node * deleteChar(node * string, char c1){
	node * top = string;
	while(!isEmpty(string)){
		if(string->value == c1){
			top = removeNode(top, string);
		}
		string = getNext(string);
	}
	return top;
}

/*	Converts lowercase letters in
		linked list to uppercase 	*/
void * toUpperChar(node * string){
	while(!isEmpty(string)){
		if(islower(string->value)){
			string->value = toupper(string->value);
		}
		string = getNext(string);
	}
}

/*	Gets all letters in list, sorts them as lowercase,
	returns new list	*/
node * getChars(node * string){
	node * sortedList = NULL;
	int letter;
	while(!isEmpty(string)){
		letter = tolower(string->value);
		node * count = sortedList;
		int i = 0;
		/*	Find element position to insert letter 	*/
		while(!isEmpty(count)){
			if(letter < count->value){
				break; //position found
			}
			i++;
			count = getNext(count);
		}
		/*	Insert letter at element i in list 	*/
		sortedList = insertAt(sortedList, i, letter);
		string = getNext(string);
	}
	return sortedList;
}

/*	Checks if string 1 is a substring of string 2 	*/
bool isSubString(node * s1, node * s2){
	while(!isEmpty(s2)){
		node * s1start = s1;
		while(s2->value == s1start->value){
			s2 = getNext(s2);
			s1start = getNext(s1start);
			if(isEmpty(s1start)){
				return 1;
			}
		}
		s2 = getNext(s2);
	}
	return 0;
}
