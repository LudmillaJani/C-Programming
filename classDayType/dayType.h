//class definition
class dayType
{
public:
	void setDay(string);//function that sets the day
	int getDay(int day);//function that gets the day
	void printDay();//function that prints the day
	int nextDay(int);//prints the next day
	int previousDay(int);//prints the previous day
	int calculateDay(int day, int nrdays);//calculate the day after some given days
	void menu();//this function shows the main menu to the user
	dayType()//constructor
	{
	 weekDay[0] = "Sunday";
	 weekDay[1] = "Monday";
	 weekDay[2] = "Tuesday";
	 weekDay[3] = "Wednesday";
	 weekDay[4] = "Thursday";
	 weekDay[5] = "Friday";
	 weekDay[6] = "Saturday";
	 
	 givenDay = weekDay[0];
	 nrDays = 0;
	 
		givenDay = "def";
		nrDays = 0;
	}
	
private://members
	string weekDay[7];//variable with seven components to save weekdays
	string givenDay;//to save given day by the user
	int nrDays;//used to add to the current day, i.e calculation function
};