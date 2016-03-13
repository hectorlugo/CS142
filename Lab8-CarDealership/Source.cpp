#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <iomanip>
#include <fstream>
#include "Car.h"

//1 - There are no cars in inventory, 3 - Enter name = golf, color = green, price = 5000, car golf has been purchased, 1 - outputs correct info, 3 - golf, A car by that name already exists
//3 - Audi, Black, 30000, you do not have enough money to buy this car
//3 - Bug, Blue, 1500, Car Bug has been purchased, 3 - bug, car already exists, 5 - bug, red, bug has been painted red, 8 - quit program.

using namespace std;

int findCar(vector<Car>& cars, string carName){		//searches for a car name in the vector
	for (int i = 0; i < cars.size(); i++){
		if (cars[i].getName() == carName){
			return i;		//returns index of the car if found
		}
	}
	return -1;				//returns -1 otherwise
}

void displayInventory(vector<Car> cars){		//goes through each object in the vector and displays the information
	if (cars.size() == 0){		//returns this if inventory is empty
		cout << "There are no cars in the inventory.\n";
	}

	for (int i = 0; i < cars.size(); i++){		//uses toString function to print out info
		cout << cars[i].toString() << endl;
	}
}

void buyCar(vector<Car>& cars, double& balance){		//gets info to buy a car
	string carName, carColor;
	double carPrice;
	
	cout << "\nBuying a car. \n\nEnter name of car: ";
	cin >> carName;
	int found = findCar(cars, carName);		//runs find function for the car
	if (found >= 0){		//if found does not let you buy
		cout << "A car by that name already exists.\n";
	}
	else{					//gets rest of info if there is no such car
		cout << "Enter car color: ";
		cin >> carColor;
		cout << "Enter car price: ";
		cin >> carPrice;
		if (carPrice > balance){		//checks to make sure you have enough money
			cout << "You don't have enough money to buy this car.\n";
		}
		else{				//you can buy the car if you have enough
			Car newCar = Car(carName, carColor, carPrice);		//creates new car object
			cars.push_back(newCar);		//adds it to vector
			balance -= carPrice;		//subtracts cast of car
			cout << "Car " << carName << " has been purchased.\n";
		}
	}
}

void sellCar(vector<Car>& cars, double& balance){		//sell car function
	string carName;
	double carPrice;
	cout << "Enter name of car to sell: ";
	cin >> carName;
	int found = findCar(cars, carName);		//checks to see if car is in vector
	if (found >= 0){		//if car is found gets the info, erases it from vector, and adjusts the balance
		carPrice = cars[found].getPrice();
		cars.erase(cars.begin() + found);
		balance += carPrice;
		cout << carName << " has been sold.\n";
	}
	else{
		cout << carName + " was not found.\n";		//informs if the car is not found
	}
}

void paintCar(vector<Car>& cars){		//paint car function
	string carName;
	string carColor;
	cout << "Enter the name of the car you want to paint: ";
	cin >> carName;
	int found = findCar(cars, carName);		//searches for the car to paint
	if (found >= 0){		//if found gets the rest of the info and changes the color
		cout << "Enter the new color: ";
		cin >> carColor;
		cars[found].paint(carColor);
		cout << carName << " has been painted " << carColor << "\n";
	}
	else{
		cout << "That car does not exsist.\n";		//informs if car does not exist
	}
}

void loadFile(vector<Car>& cars, double& balance){		//loads cars into vector from file
	ifstream input;		//uses fstream
	string fileName;
	
	cout << "Enter file name: ";
	cin >> fileName;
	input.open(fileName);		//opens the file

	double fileBalance;		//gets the balance and adds it to already existing balance
	input >> fileBalance;
	
	balance += fileBalance;

	string name_in, color_in;
	double price_in;

	while (input.good() && !input.eof()){		//while the input is correct and its not the end of file, keeps adding in input

		input >> name_in >> color_in >> price_in;
		Car newCar = Car(name_in, color_in, price_in);		//creates new car and adds car to vector
		cars.push_back(newCar);
	}
	input.close();		//close the file stream		
	cout << fileName << " has been loaded.\n";
}

void saveFile(vector<Car>& cars, double balance){		//save file function
	string fileName;
	cout << "Enter the name of the file to save: ";
	cin >> fileName;

	ofstream output;		//create and output stream
	output.open(fileName);
	output << balance << "\n";
	for (int i = 0; i < cars.size(); i++){		//adds vector info to output file
		output << cars[i].getName() << " " << cars[i].getColor() << " " << cars[i].getPrice();
		if (i < cars.size() - 1){
			output << "\n";
		}
	}

	output.close();		//closes output stream
	cout << fileName << " has been saved.\n";
}

int menu(){		//displays menu options
	int choice;
	cout << "\n 1 - Show Current Inventory\n 2 - Show Current Balance\n 3 - Buy a Car\n 4 - Sell a Car\n 5 - Paint a Car\n 6 - Load File\n 7 - Save File\n 8 - Quit Program\n\nMake a selection: ";

	cin >> choice;		//makes sure its a valid choice
	if (cin.fail()){
		cin.clear();
		cin.ignore();
	}
	return choice;
}

int main(){
	bool run = true;		//bool to check if main menu shoul continue prompting
	double balance = 10000;		//starting balance
	vector<Car> cars;		//creates Car vector
	
	while (run){
		int choice = menu();

		if (choice == 1){		//display inventory
			displayInventory(cars);
		}
		else if (choice == 2){		//shows current ballance		
			cout << fixed << setprecision(2) << "Current Balance is $" << balance << "\n\n";
		}
		else if (choice == 3){		//runs buyCar
			buyCar(cars, balance);
		}
		else if (choice == 4){		//runs sellCar
			sellCar(cars, balance);
		}
		else if (choice == 5){		//runs paintCar
			paintCar(cars);
		}
		else if (choice == 6){		//runs loadFile
			loadFile(cars, balance);
		}
		else if (choice == 7){		//runs saveFile
			saveFile(cars, balance);
		}
		else if (choice == 8){ run = false; }		
		else {
			cout << "That was an invalid choice.\n";
		}
	}

	return 0;
}