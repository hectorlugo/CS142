#include <iostream>  

#include <math.h>
using namespace std;
//Test Cases
//19 Guests 2 Large, 1 Medium, 2 Small, 1055.575 total sq in pizza. 55.556 sq in per person, $66 total cost at 20% tip
//25 Guests 3 Large, 1 Medium, 1 Small, 1256.64 total sq in of pizza, 50.2655 sq in per person, $70 total cost at 12% tip
//39 Guests, 5 large, 1 Medium, 1 Small, 1844.95 total sq in of pizza, 48.33 sq in per person, $123 total cost at 33% tip
int main()
{
	//How many pizzas we need and how many guests are coming
	cout << "Enter the number of guests attending: " << endl;
	int guests;
	cin >> guests; //get guest number from user
	const int lsize = 7;
	const int msize = 3;
	//calculating pizzas needed
	int large = guests / lsize;
	int second = guests % lsize;
	int medium = second / msize;
	int small = second % msize;
	cout << "We Need " << large << " large, " << medium << " medium, and " << small << " small pizzas." << endl;
	system("pause");

	//how many square inches we need and how many sq in each guest can eat
	//constants for pizza radius and PI
	const double PI = 3.14159;
	const int lradius = 10;
	const int mradius = 8;
	const int sradius = 6;
	//square inches of pizza needed
	double buy = (large * PI * lradius * lradius) + (medium * PI * mradius * mradius) + (small * PI * sradius * sradius);
	cout << "We need to buy " << buy << " square inches of pizza." << endl;
	system("pause");
	//square inches of pizza each guest can eat.
	double eat = buy / guests;
	cout << "Each guest can eat " << eat << " square inches of pizza." << endl;
	system("pause");

	//Cost
	cout << "Enter the tip percentage to be paid: " << endl;
	double tip;
	cin >> tip;
	tip = tip / 100;	//turn tip into percentage
	cout << "You will pay " << tip << " percent tip." << endl;
	system("pause");
	//constants for pizza prices
	const double lCost = 14.68;
	const double mCost = 11.48;
	const double sCost = 7.28;
	//get total before tip
	double subtotal = (large * lCost) + (medium * mCost) + (small * sCost);
	//total with tip
	double total = subtotal + (subtotal * tip);
	int rounded = round(total);	//rouning up total to nearest dollar
	cout << "The total cost is $" << rounded << endl;
	system("pause");
	return 0;
}