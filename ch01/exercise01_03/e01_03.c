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
#include <stdbool.h>

/*	Date structure 	*/
typedef struct{
	int day;
	int month;
	int year;
}date;

enum {YEAR_DAYS = 365, LEAP_YEAR_DAYS};

int daysBetween(date d1, date d2);
bool isLeapYear(int year);

int main(void){
	date d1 = {12, 11, 1984};
	date d2 = {13, 9, 2005};
	return 0;
}

/*	Calculates amount of days from full years 	*/
int getDaysFromYears(int year){
	int days = 0;
	while(--year){ //Skip current year
		printf("Calcing year %d\n", year);
		if(isLeapYear(year)){
			days += LEAP_YEAR_DAYS;
		}
		else{
			days += YEAR_DAYS;
		}
	}
	return days;
}

int getDaysFromYearStart(date date){
	int days = 0;
	return days;
}

int daysBetween(date d1, date d2){
	return 123;
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
