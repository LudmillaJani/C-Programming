//Ludmilla Jani
//CSC 2111-Lab 5
//Program that prints the day number of the year, given the date in the form month-day-year
/* Write a program that prints the day number of the year, given the date in the form month-day-year. The program should check for a leap year.
A year is a leap year if it is divisible by 4, but not divisible by 100. A year that is divisible by 100 is a leap year if it is also divisible by 400*/

#include<iostream>
using namespace std;

int leapYear(int& monthS, int& dayS, int& yearL);// function prototype

int main()
{
	int day, month, year;
	
	
	cout << "Please enter the date in the form month date year: " << endl;
	cin >> month >> day >> year;

	day = day + leapYear(month, day, year);
	cout << "The day number of the year is: " << day << endl;

	system("pause");
}

int leapYear(int& monthS, int& dayS,int& yearL) //function definition
{                                               //function that checks if a year is a leap year
	                                            //if yes, then February has 29 days
	                                            //if not, February has 28 days
	int sumDays = 0;

	if ((yearL % 4 == 0 && yearL % 100 != 0) || (yearL % 100 == 0 && yearL % 400 == 0))  //If the year is a leap year, February has 29 days
	{                                                                                   
		cout << "The year you entered is a leap year: " << endl;
		int daysPerMonth[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; 

		for (int i = 1; i < monthS; i++)             //loop to find the sum of the days up to the typed date by the user
		{
			sumDays = sumDays + daysPerMonth[i - 1];
		}
		
	}
	else                                                                            //If the year is not a leap year, February has 28 days
	{
		cout << "The year you entered is not a lip year! " << endl;
		int daysPerMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		for (int i = 1; i < monthS; i++)             //loop to find the sum of the days up to the typed date by the user
		{
			sumDays = sumDays + daysPerMonth[i - 1];
		}
		
	}
	return sumDays;
}

