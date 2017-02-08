/*
 *  Exercise from book
 *  Data Structures in C
 *  by Noel Kalicharan
 *
 *	Exercise 04, Chapter 01
 *  Page 23
 *
 *  Write a function that returns the number
 *	of minutes between two times t1 & t2 (24h clock).
 *	Time is represented in a struct HH & MM.
 *	If t2 is before t1, it should be interpeted as
 *	the day after.
 */

#include <stdio.h>
#include <stdlib.h> //rand() srand()
#include <time.h> //time()

typedef struct{
	int h, m;
}Time;

int minsBetween(Time t1, Time t2);

int main(void){
	Time t1, t2;
	/*	Randomize times 	*/
	srand(time(NULL));
	for(int i = 0; i < 10; i++){
		t1.h = rand() % 24;
		t1.m = rand() % 60;
		t2.h = rand() % 24;
		t2.m = rand() % 60;
		printf("There are %d mins between "
			"%02d:%02d & %02d:%02d\n",
				minsBetween(t1,t2),
				t1.h, t1.m, t2.h, t2.m
		);
	}
	return 0;
}

/*	Gets elapsed minutes from midnight 	*/
int minsFromMidnight(Time t){
	return t.h * 60 + t.m;
}

/*	Gets minutes left until midnight 	*/
int minsToMidnight(Time t){
	return 24 * 60 - (t.h * 60 + t.m);
}

/*	Returns minutes between two times 	*/
int minsBetween(Time t1, Time t2){
	int mins;
	/*	If t2 is "before" t1 -> interpet as next day */
	if((t2.h < t1.h) ||
		(t2.h == t1.h && t2.m < t1.m)){
			mins = minsToMidnight(t1) + minsFromMidnight(t2);
		}
	else{
		mins = minsFromMidnight(t2) - minsFromMidnight(t1);
	}
	return mins;
}
