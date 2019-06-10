//Ludmilla Jani
/* Jason opened a coffee shop at the beach and sells coffee in three sizes: small (9oz), medium (12oz), and large (15oz). The cost of one small cup is $1.75, one medium cup is $1.90, and one large cup is $2.00. Write a menu-driven
program that will make the coffee shop operational. Your program should allow the user to do the following:
  Buy coffee in any size and any number of cups.
  At any time show the total number of cups of each size sold.
  At any time show the total amount of coffee sold.
  At any time show the total money made.
Your program should consists of at least of at least the following functions: a function to show the user how to use the program, a function to
sell coffee, a function to show the number of cups of each size sold, a function to show the total amount of coffee sold, and a function to show
the total money made. Your program should not use any global variables and special values such as coffee cup sizes and cost of a coffee cup must 
be declared as named constants.

*/

#include<iostream>
#include<iomanip>
using namespace std;

int mainMenu(); //function prototypes
void sellCofee(int& ,int& ,int&);
int coffeeSize();
int getNrCups();
double totalMoneyBySize(int, int, int);
void totalCupsBySize(int, int, int);
void totalMoney(double small, double medium, double large);
void totalCups(int small, int medium, int large);


const double small$ = 1.75;
const double  medium$ = 1.9;
const double large$ = 2.00;

const int ouncesSmallCoffee = 9;
const int ouncesMediumCoffee = 12;
const int ouncesLargeCoffee = 15;

int main()
{
	bool flag = true;
	int mainChoice = 0;
	int SaleSmallCups = 0;
	int SaleMediumCups = 0;
	int SaleLargeCups = 0;
			
	do
	{
		mainChoice = mainMenu();//calls the function mainMenu
		switch (mainChoice)
		{
		case 1: 	sellCofee(SaleSmallCups, SaleMediumCups, SaleLargeCups);//first case when chosen 1 from  mainmenu(), then call function sellCoffee
			break;
		case 2:		totalCupsBySize(SaleSmallCups, SaleMediumCups, SaleLargeCups);//second case when chosen 2 from  mainmenu(), then call function totalCupBySize
			break;
		case 3:     totalCups(SaleSmallCups, SaleMediumCups, SaleLargeCups);//third case when chosen 3 from mainmenu(), then call function totalCups
			break;
		case 4:		totalMoney(SaleSmallCups, SaleMediumCups, SaleLargeCups);//when chosen 4 from mainMenu(), then call function totanMoney
			break;
		default:	cout << "This is default";
			break;
		}

	} while (flag != false);


	

	system("pause");
	return 0;
}


///////////////////Function Definitions///////////////////

//FUNCTION 1....................Gives the menu of the store
int mainMenu()
{
	int select;
	cout << "******************************************" << endl;
	cout << "Welcome at Jason's coffee shop " << endl;
	cout << "Please select one of the options " << endl;
	cout << "1: Sell Coffe" << endl;
	cout << "2: Total Number of cups of each size sold " << endl;
	cout << "3: Total amount of coffee sold " << endl;
	cout << "4:Total money made " << endl;
	cout << "5:Quit" << endl;
	cin >> select;

	while (!(1 <= select && select <= 5))     //Outputs the message if the input is not a number betwwen 1-5
	{
		cout << "Invalid Selection. Please eneter a number 1-5: ";
		cin >> select;
	}
	return select;
}


//Function 5: sells coffee
void sellCofee(int& sumSmallCupsThis, int& sumMediumCupsThis, int& sumLargeCupsThis)
{
	int cups = 0;

	int smallCups = 0; //variables to store the total number of small cupSize sold
	int mediumCups = 0; //variables to store the total number of medium cupSize sold
	int largeCups = 0; //variables to store the total number of large cupSize sold
	double total = 0.0; //varible that stores the total money made of selling coffee for each particular transaction

	int coffeeSelect = 0;
	cout << "******************************************" << endl;

	do   //go through this steps until the choice for coffeesize is diffenet then 4
	{
		coffeeSelect = coffeeSize(); //call the function coffesize and stores the return value to coffeeSelect variable 
									 //stores whatever size the user selects, small, medium, or large
		switch (coffeeSelect)
		{
		case 1:	cups = getNrCups();//When selected 1. Small. call the function getNrCups to get the input of how many cups the buyer wants
			sumSmallCupsThis += cups;   
			break;
		case 2: cups = getNrCups(); //when selected 4.Medium                              //stores the number of all cups sold from the daily sales by cupsize
			sumMediumCupsThis += cups;
			break;
		case 3: cups = getNrCups(); //when selected 3. Large
			sumLargeCupsThis += cups;
			break;
		case 4: total = totalMoneyBySize(sumSmallCupsThis, sumMediumCupsThis, sumLargeCupsThis);//calls the function totalSale and calculates the total money made of salling coffee
			
			cout << "******************************************" << endl;//when selected exit        
			cout << "Total money is $" << total << endl;                                
			//increment daily totals with the current sale
			sumSmallCupsThis = sumSmallCupsThis + smallCups;
			sumMediumCupsThis = sumMediumCupsThis + mediumCups;
			sumLargeCupsThis = sumLargeCupsThis + largeCups;
			break;
		}

	} while (coffeeSelect != 4);

}


//Function 2...................

int coffeeSize()// function that gives the coffee menu: three sizes that can be chosen
{
	int select = 0;
	cout << "******************************************" << endl;
	cout << "Coffee Menu" << endl;
	cout << "What size would you like: " << endl;
	cout << "1. Small" << endl;
	cout << "2. Medium" << endl;
	cout << "3. Large" << endl;
	cout << "4. Exit" << endl;
	
	cin >> select;
	while (!(select >= 1 && select <= 4))  //Outputs the message if the input is not correct i.e a number betwwen 1-4
	{
		cout << "******************************************" << endl;
		cout << "Invalid Selection - Please re-enter: ";
		cin >> select;
	}
	return select;

}

//Function 3: Inputs the number of cups the  buyer wants
int getNrCups()
{
	int nrCups = 0;
	cout << "******************************************" << endl;
	cout << "How many cups would you like to buy? " << endl;
	cin >> nrCups;
	cout << endl;
	return nrCups;
}


//======>>>>>>>>MONEY

//Function 4:  calculates the total money made for each coffe size sold also the total amount 

double totalMoneyBySize(int small, int medium, int large)
{
	double totalMoneyFromSmallCup= small * small$;
	double totalMoneyFromMediumCup = medium * medium$;
	double totalMoneyFromLargeCup = large * large$;
	cout << "******************************************" << endl;
	
		cout << "Total money from selling Small Cups: " << small << " small cup(s) at $" << small$ << " each: $" << totalMoneyFromSmallCup << endl;
	
		cout << "Total money from selling Medium Cups: " << medium << " medium cup(s) at $ " << medium$ << " each: $" << totalMoneyFromMediumCup << endl;
	
		cout << "Total money from selling Large Cups: " << large << " large cup(s) at $" << large$ << " each: $" << totalMoneyFromLargeCup << endl;

	double totalMoney = totalMoneyFromSmallCup + totalMoneyFromMediumCup + totalMoneyFromLargeCup;
	return totalMoney;
}

//Function 6***************************************************************************
void totalMoney(double small, double medium, double large)//Total money from selling coffee during the day
{
	cout << "******************************************" << endl;
	cout << "Total money from selling coffee today is: $" << (small*small$) + (medium*medium$) + (large*large$) << endl;
}


//===========>>>>CUPS

//Function 7***************************************************************************

void totalCupsBySize(int small, int medium, int large)//total coffee by size
{
	cout << "******************************************" << endl;
	cout << "Small cups Coffee sold today is: " << small << endl;
	cout << "Medium cups Coffee sold today is: " << medium << endl;
	cout << "Large cups Coffee sold today is: " << large << endl;
}

//Function 8***************************************************************************
void totalCups(int small, int medium, int large)//Total coffe(number of cups alltogether) from selling coffee during the day
{
	int total_coffe;
	cout << "******************************************" << endl;
	cout << "Total cofee sold is: " << small+medium+large << "cups" << endl;
}


