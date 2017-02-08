/*
 *  Exercise from book
 *  Data Structures in C
 *  by Noel Kalicharan
 *
 *	Exercise 03, Chapter 01
 *  Page 23
 *
 *  Write a function that returns the number
 *	of days between two dates defined in structs.
 *  Return a negative value if date 2 is before date 1.
 */

#include <stdio.h>
#include <stdbool.h> //bool variable
#include <stdlib.h> //rand() srand()
#include <time.h> //time()

/*	Date structure 	*/
typedef struct{
	int day;
	int month;
	int year;
}date;

enum {YEAR_DAYS = 365, LEAP_YEAR_DAYS};
enum {
	JAN = 1,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC};
int daysPerMonth[13] = {
	0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int daysBetween(date d1, date d2);
bool isLeapYear(int year);

int main(void){
	srand(time(NULL));
	date d1,d2;
	/* Check random dates	*/
	for(int i = 0; i < 20; i++){
		d1.year = 1600 + (rand() % 600);
		d2.year = 1600 + (rand() % 600);
		d1.month = 1 + (rand() % 12);
		d2.month = 1 + (rand() % 12);
		d1.day = 1 + (rand() % daysPerMonth[d1.month]);
		d2.day = 1 + (rand() % daysPerMonth[d2.month]);
		printf("There are %d days between "
			"%04d-%02d-%02d and %04d-%02d-%02d\n",
			daysBetween(d1, d2),
			d1.year, d1.month, d1.day,
			d2.year, d2.month, d2.day
		);
	}
	return 0;
}

/*	Calculates amount of days from full years 	*/
int getDaysFromYears(int year){
	int days = 0;
	while(--year){ //Skip current year
		if(isLeapYear(year)){
			days += LEAP_YEAR_DAYS;
		}
		else{
			days += YEAR_DAYS;
		}
	}
	return days;
}

/*	Calculates days from year start. 	*/
int getDaysFromYearStart(date date){
	int days = date.day;
	int month = date.month;
	while(--month){
		if(month == FEB && isLeapYear(date.year)){
			days += daysPerMonth[month] + 1;
		}
		else{
			days += daysPerMonth[month];
		}
	}
	return days;
}

/*	Gets days between two dates 	*/
int daysBetween(date d1, date d2){
	return (getDaysFromYearStart(d2) + getDaysFromYears(d2.year))
		- (getDaysFromYearStart(d1) + getDaysFromYears(d1.year));
}

/*	Determines if year is a leap year 	*/
bool isLeapYear(int year){
	/*	a year is a leap year if it is divisible by four,
	UNLESS it is also divisible by 100.
	A year is NOT a leap year if it is divisible by 100
	UNLESS it is also divisible by 400. 	*/
	return (((year % 4 == 0) && !(year % 100 == 0)) ||
			((year % 400 == 0) && (year % 100 == 0)));
}
