#include<iostream>
#include<string>
using namespace std;
#include "dayType.h"


//implementation functions
void dayType::setDay(string newDay)
{
	givenDay = newDay;
}
int dayType::getDay(int day)
{
	return day;
}
void dayType::printDay()
{
	cout << "Day chosen is: " << givenDay << endl;

}

int dayType::nextDay(int day)
{
	day = day++;//increment the day by one
	if (day > 6)
		day = day % 7;
	switch (day)
	{
	case 0: cout << "Next Day: Sunday";
		break;
	case 1: cout << "Next Day: Monday";
		break;
	case 2: cout << "Next Day: Tuesday";
		break;
	case 3: cout << "Next Day: Wednesday";
		break;
	case 4: cout << "Next Day: Thursday";
		break;
	case 5: cout << "Next Day: Friday";
		break;
	case 6: cout << "Next Day: Saturday";
		break;
	}
	cout << endl;
	return day;


}
int dayType::previousDay(int day)
{

	day = day--;//decrement the day by one
	switch (day)
	{
	case 0: cout << "Previous day: Sunday";
		break;
	case 1: cout << "Previous day: Monday";
		break;
	case 2: cout << "Previous day: Tuesday";
		break;
	case 3: cout << "Previous day: Wednesday";
		break;
	case 4: cout << "Previous day: Thursday";
		break;
	case 5: cout << "Previous day: Friday";
		break;
	case 6: cout << "Previous day: Saturday";
		break;
	default: cout << "Hemmm, I am not sure";
	}
	cout << endl;
	return day;

}
int dayType::calculateDay(int addDays, int nrDays)//adds to the users first input another number of days
{                                                 //and then finds what will be the day
	addDays = addDays + nrDays;
	if (addDays > 6)
		addDays = addDays % 7;
	switch (addDays)
	{
	case 0: cout << nrDays<< " days after is Sunday";
		break;
	case 1: cout << nrDays << " days after is Monday.";
		break;
	case 2: cout << nrDays << " days after is Tuesday.";
		break;
	case 3: cout << nrDays << " days after is Wednesday.";
		break;
	case 4: cout << nrDays << " days after is Thursday.";
		break;
	case 5: cout << nrDays << " days after is Friday.";
		break;
	case 6: cout << nrDays << " days after is Saturday.";
		break;
	default: cout << nrDays << "Not a valid choice.";
	}
	cout << endl;
	return addDays;
}


void dayType::menu()//this gives the main menu, i.e what the user will see and then select one of them
{
	cout << "****MAIN MENU: PLEASE SELECT ONE****"<<endl;
	cout << "0 : Sunday" << endl;
	cout << "1 : Monday" << endl;
	cout << "2 : Tuesday" << endl;
	cout << "3 : Wednesday" << endl;
	cout << "4 : Thursday" << endl;
	cout << "5 : Friday" << endl;
	cout << "6 : Saturday" << endl;
	cout << "77 : Exit" << endl;
	
}


