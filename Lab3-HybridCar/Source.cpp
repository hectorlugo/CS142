#include <iostream>  
#include <math.h>
#include <string>
//Extra Credit
//Milage needed on the Hybrid is 166.67 to get the same total cost as the non-Hybrid
//Test Cases
//At 10,000 miles per year, at $1.60 a gallon, Hybrid cost 27,435, MPG = 47, resell is 20,576, non-hybrid cost 18,290, MPG = 34, resell is 13,718. 
//Minimizing Gas consumption, Hybrid is best car with 1,063.83 gallons consumed in 5 years & total cost in 5 years is 8,561
//non-hybrid consumes 1,470.59 gallons in 5 years, with a total cost of 6,924 in 5 years.

//At 10,000 miles per year, at $2.48 a gallon, Hybrid cost 24,200, MPG = 48, resell is 18,150, non-hybrid cost 20,765, MPG = 25, resell is 15,574.
//Minimizing Total cost, Hybrid is best car with 1,041.67 gallons consumed in 5 years & total cost is 8,633 in 5 years.
//non-Hybrid consumes 2,000 gallons in 5 years, with a total cost of 10,151 in 5 years.

//At 10,000 miles per year, at $3.00 a gallon, Hybrid cost 31,670, MPG = 48, resell is 24,503. Non-Hybrid cost is 24,895, MPG = 33, resell is 18,671.
//Minimizing Total cost, Hybrid is best car with 1,041.67 gallons consumed in 5 years & total cost is 10,292 in 5 years.
//non-Hybrid cosumes 1,515.15 gallons in 5 years. Total cost is 10,769 in 5 years.
using namespace std;

int main()
{
	//Prompting the user for info
	cout << "About how many miles do you drive per year? ";
	int mpy;
	cin >> mpy;		//miles per year
	if (mpy <= 0)
	{
		cout << "Value must be positive, Reenter miles driven per year: ";
		cin >> mpy;
	}
	cout << "\n";
	cout << "What is the price of a gallon of gas in the 5 years of ownership? ";
	double gallon;	//price of a gallon of gas
	cin >> gallon;
	if (gallon <= 0)
	{
		cout << "Value must be positive, Reenter price of gallon of gas: ";
		cin >> gallon;
	}
	cout << "\n";
	cout << "What is the price of the Hybrid car? ";
	int hybrid;		//price of a hybrid car
	cin >> hybrid;
	if (hybrid <= 0)
	{
		cout << "Value must be positive, Reenter price of a Hybrid car: ";
		cin >> hybrid;
	}
	cout << "\n";
	cout << "How many miles per gallon does the Hybrid car give? ";
	double milesHybrid;	//mpg of a hybrid car
	cin >> milesHybrid;
	if (milesHybrid <= 0)
	{
		cout << "Value must be positive, Reenter amount of miles per gallon: ";
		cin >> milesHybrid;
	}
	cout << "\n";
	cout << "For how much can you sell the Hybrid after 5 years? ";
	int oldHybrid;		//resell value of a hybrid car after 5 years
	cin >> oldHybrid;
	if (oldHybrid <= 0)
	{
		cout << "Value must be positive, Reenter price of Hybrid after 5 years: ";
		cin >> oldHybrid;
	}
	cout << "\n";
	cout << "How much does a non-Hybrid car cost? ";
	int car;			//cost of a non-hybrid car
	cin >> car;
	if (car <= 0)
	{
		cout << "Value must be positive, Reenter cost of a non-Hybrid car: ";
		cin >> car;
	}
	cout << "\n";
	cout << "How many miles per gallon does the non-Hybrid car give? ";
	double milesCar;	//mpg of non-hybrid car
	cin >> milesCar;
	if (milesCar <= 0)
	{
		cout << "Value must be positive, Reenter miles per gallon of non-Hybrid car: ";
		cin >> milesCar;
	}
	cout << "\n";
	cout << "For how much can you sell the non-Hybrid car after 5 years? ";
	int oldCar;			//resell value of non-hybrid car after 5 years
	cin >> oldCar;
	if (oldCar <= 0)
	{
		cout << "Value must be positive, Reenter price of non-Hybrid car after 5 years: ";
		cin >> oldCar;
	}
	cout << "\n";
	cout << "Do you want to minimize Gas consumption or minimize Total cost?\n" << "Enter either Gas or Total: ";
	string choice;		//user minimizing preference
	cin >> choice;
	system("pause");
	cout << "\n";
	//calculations for total cost and cost of gas in 5 years
	const int years = 5;
	double gallonsHybrid = (mpy / milesHybrid) * years;
	double gallonsCar = (mpy / milesCar) * years;
	double gasCostHybrid = gallonsHybrid * gallon;
	double gasCostCar = gallonsCar * gallon;

	int totalHybrid = gasCostHybrid + (hybrid - oldHybrid);
	int totalCar = gasCostCar + (car - oldCar);

	if (choice == "Gas")
	{
		if (gallonsHybrid < gallonsCar)
		{
			cout << "Vehicle with best fuel consumption is the Hybrid.\n";
			cout << "Total gallons of fuel consumed in 5 years is " << gallonsHybrid << "\n";
			cout << "Total cost of owning the car for 5 years is " << totalHybrid << "\n";

			cout << "Vehicle with worst fuel consumption is the non-Hybrid.\n";
			cout << "Total gallons of fuel consumed in 5 years is " << gallonsCar << "\n";
			cout << "Total cost of owning the car for 5 years is " << totalCar << "\n";
		}
		else{
			cout << "Vehicle with best fuel consumption is the non-Hybrid.\n";
			cout << "Total gallons of fuel consumed in 5 years is " << gallonsCar << "\n";
			cout << "Total cost of owning the car for 5 years is " << totalCar << "\n";

			cout << "Vehicle with worst fuel consumption is the Hybrid.\n";
			cout << "Total gallons of fuel consumed in 5 years is " << gallonsHybrid << "\n";
			cout << "Total cost of owning the car for 5 years is " << totalHybrid << "\n";
		}
	}
	else{
		if (totalHybrid < totalCar)
		{
			cout << "Vehicle with best total cost is the Hybrid.\n";
			cout << "Total gallons of fuel consumed in 5 years is " << gallonsHybrid << "\n";
			cout << "Total cost of owning the car for 5 years is " << totalHybrid << "\n";

			cout << "Vehicle with worst total cost is the non-Hybrid.\n";
			cout << "Total gallons of fuel consumed in 5 years is " << gallonsCar << "\n";
			cout << "Total cost of owning the car for 5 years is " << totalCar << "\n";
		}
		else{
			cout << "Vehicle with best total cost is the non-Hybrid.\n";
			cout << "Total gallons of fuel consumed in 5 years is " << gallonsCar << "\n";
			cout << "Total cost of owning the car for 5 years is " << totalCar << "\n";

			cout << "Vehicle with worst total cost is the Hybrid.\n";
			cout << "Total gallons of fuel consumed in 5 years is " << gallonsHybrid << "\n";
			cout << "Total cost of owning the car for 5 years is " << totalHybrid << "\n";
		}
		
	}	
	system("pause");
	return 0;
}