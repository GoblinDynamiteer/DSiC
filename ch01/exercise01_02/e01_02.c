/*
 *  Exercise from book
 *  Data Structures in C
 *  by Noel Kalicharan
 *
 *	Exercise 02, Chapter 01
 *  Page 23
 *
 *  Write a function that gets two date
 *	structures, d1 & d2. Return 0 if same date,
 *	-1 if d1 is first, else 1.
 */

#include <stdio.h>
#include <stdlib.h> //rand()
#include <time.h> //time()
#include <string.h> //strcmp

typedef struct{
	int day;
	int month;
	int year;
}date;

int compareDates(date d1, date d2);

int main(void){
	date d1, d2;
	srand(time(NULL));
	/* Check random dates	*/
	for(int i = 0; i < 10; i++){
		d1.year = 1900 + (rand() % 150);
		d2.year = 1900 + (rand() % 150);
		d1.month = 1 + (rand() % 12);
		d2.month = 1 + (rand() % 12);
		/* Cheating with number of days..	*/
		d1.day = 1 + (rand() % 30);
		d2.day = 1 + (rand() % 30);
		if(compareDates(d1, d2) > 0){
			printf("%04d-%02d-%02d comes before %04d-%02d-%02d\n",
				d2.year, d2.month, d2.day,
				d1.year, d1.month, d1.day
			);
		}
		else if(compareDates(d1, d2) < 0){
				printf("%04d-%02d-%02d comes before %04d-%02d-%02d\n",
					d1.year, d1.month, d1.day,
					d2.year, d2.month, d2.day
				);
		}
		else{
			printf("%04d-%02d-%02d is same as %04d-%02d-%02d\n",
				d1.year, d1.month, d1.day,
				d2.year, d2.month, d2.day
			);
		}
	}
	/*	Check same date 	*/
	d1 = d2;
	if(!compareDates(d1, d2)){
		printf("%04d-%02d-%02d is same as %04d-%02d-%02d\n",
			d1.year, d1.month, d1.day,
			d2.year, d2.month, d2.day
		);
	}
	return 0;
}

/*	Checks wichs date comes first. 	*/
int compareDates(date d1, date d2){
	int returnVal = 0;
	char d1str[10], d2str[10];
	/*	Get dates into strings 	*/
	sprintf(d1str, "%04d%02d%02d", d1.year, d1.month, d1.day);
	sprintf(d2str, "%04d%02d%02d", d2.year, d2.month, d2.day);
	/*	Compare strings 	*/
	if(strcmp(d1str, d2str) < 0){
		returnVal = -1;
	}
	else if(strcmp(d1str, d2str) > 0){
		returnVal = 1;
	}
	return returnVal;
}
