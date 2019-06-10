/* 
Design and implement a class dayType that implements the day of the week in a program. The class dayType should store the day, such as Sun for Sunday.
The program should be able to perform the following operations on an object of type dayType:
  Set the day
  Print the day
  Return the day
  Return the next day
  Return the previous day
  Calculate and return the day by adding certain days to the currrent day. For example, if the current day is Monday and we add 4 days, 
  the day to be returned is Friday. Similarly, if today is Tuesday and we add 13 days, the day to be returned is Monday.
  Add the appropriate constructors.

*/
#include<iostream>
#include<string>
using namespace std;
#include "dayType.h"

int main()
{
	int inputDay;//variable to save the users input
	int addDays;//variable to save haw many days the user wants to add to the day
	dayType giveMeDay;//an object of the type dayType


	giveMeDay.menu();//calls the function to show the main menu
	cin >> inputDay;

	switch (inputDay)//the day is set depending on the users input number
	{
	case 0:
		giveMeDay.setDay("Sunday");
		break;
	case 1:
		giveMeDay.setDay("Monday");
		break;
	case 2:
		giveMeDay.setDay("Tuesday");
		break;
	case 3:
		giveMeDay.setDay("Wednesday");
		break;
	case 4:
		giveMeDay.setDay("Thursday");
		break;
	case 5:
		giveMeDay.setDay("Friday");
		break;
	case 6:
		giveMeDay.setDay("Saturday");
		break;
	case 77:
		cout << "Have a nice day!" << endl;
		break;

	default:
		cout << "Try again! " << endl;

		break;
	}

	if (inputDay >= 0 && inputDay <= 6) //then, if the user inputs [1,6] call these functions
	{
		giveMeDay.printDay();
		cout << endl;

		giveMeDay.nextDay(inputDay);
		cout << endl;

		giveMeDay.previousDay(inputDay);
		cout << endl;

		cout << "How many days do you want to add: " << endl;
		cin >> addDays;
		giveMeDay.calculateDay(inputDay, addDays);
		cout << endl;

	}

	
	system("pause");
	return 0;
}