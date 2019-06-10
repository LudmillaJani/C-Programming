/* Money Class
Define a Template class named MOney that stores a monetary amount. The class should have two private integer variables, one to store the number 
of dollars and another to store the number of cents.
Add accessors and mutators functions to read and set both member variables. Add another function that returns the monetary amount as a double.
Add another member functions that converts the Money currency to another type of currency shuch as EURO's. Also create additional methods to support 
the converted currency. Arite a program that tests all of your functions with at least ywo different Money objects.
*/
#include<iostream>

using namespace std;


template <class moneyType>//template
class Money
{
	friend istream& operator>> (istream& isObject, Money<moneyType>& money);//operator overloading
public:
	const double euro = 0.88;// 1 euro = 0.88 dollars //I will this conversion
	void setDollars(int d);//to set dollars
	void setCents(int c);//to set cents
	int getDollars();//to get dollars
	int getCents();//to get cents
	double amount();//calculates the total amount of dollars and cents
	double convertDollarsToEuros(double d);//converts dollars to euros
	double convertEurosToDollars(double d);//converts euros to dollars
	Money();//constructors
	Money(int d, int c);


private:
	int dollars;//to save the amount of dollars
	int cents;//to save the amount of cents

};


template <class moneyType>// definitions
void Money<moneyType>::setDollars(int d)
{
	dollars = d;
}
template <class moneyType>
void Money<moneyType>::setCents(int c)
{
	if (c > 0)
	{
		c = c % 100;
		dollars = dollars + (c / 100);
	}
	cents = c;
}
template <class moneyType>
int Money<moneyType>::getDollars()
{
	return dollars;
}
template <class moneyType>
int Money<moneyType>::getCents()
{
	return cents;
}

template<class moneyType>
double Money<moneyType>::amount()
{
	return dollars + static_cast<double>(cents) / 100;
}
template<class moneyType>
double Money<moneyType>::convertDollarsToEuros(double d)
{
	
	return static_cast<double> (euro * d);
}

template<class moneyType>
double Money<moneyType>::convertEurosToDollars(double d)
{
	return static_cast<double> ( d / euro);
}

//constructors
template<class moneyType>
Money<moneyType>::Money()
{
	dollars = 0;
	cents = 0;
}

template<class moneyType>
Money<moneyType>::Money(int d, int c)
{
	dollars = d;
	cents = c;

}
//overload 
template<class moneyType>
istream& operator>> (istream& isObject, Money<moneyType>& money)
{
	isObject >> money.dollars >> money.cents;

	return isObject;
}
//*******************************************************
//Main Function
int main()
{
	Money<int> dollars(100,45);
	cout<< "100 dollars and 45 cents: " << dollars.amount() << endl;
	Money<double> convertDollars;
	cout << "How much dollars do you want to convert: ";
	double d;
	cin >> d;
	cout << endl;
	cout << "$"<< d << " converted in euros: " << convertDollars.convertDollarsToEuros(d) << endl;

	Money<double> convertEuros;
	cout << "How much Euros do you want to convert: ";
	double e;
	cin >> e;
	cout << endl;
	cout <<  e << " euros converted in $: " << convertEuros.convertEurosToDollars(e) << endl;



	system("pause");
	return 0;
}