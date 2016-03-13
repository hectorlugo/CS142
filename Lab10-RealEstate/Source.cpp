#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Property.h"
#include "Residential.h"
#include "Commercial.h"

using namespace std;

bool openFile(vector<Property*>& properties, string fileName){
	ifstream input;			//open stream for input from file
	input.open(fileName);

	if (!input){			//checks to see if file exists
		cout << "ERROR. That file does not exist.";
		return false;
	}
	else{
		string type;		//create variables for input
		int id = 0;
		int rental;
		int value;
		string address;
		int occupied;
		int discounted;
		double discountRate;
		string badLine;

		while (input.good() && !input.eof()){		//keeps going as long as the input is good and its not the end of the file
			input >> type;
			
			if (type == "Residential"){				//residential input tester
				input >> rental;
				if (input.fail() || (rental != 1 && rental != 0)){
					input.clear();
					getline(input, badLine);
					cout << "Ignoring bad RESIDENTIAL in input file: " << type << " " << rental << " " << badLine << "" << "\n\n";
				}
				else{
					input >> value;
					if (input.fail() || value <= 0){
						input.clear();
						getline(input, badLine);
						cout << "Ignoring bad RESIDENTIAL in input file: " << type << " " << rental << " " << value << " " << badLine << "\n\n";
					}
					else{
						input >> occupied;
						if (input.fail() || (occupied != 1 && occupied != 0)){
							input.clear();
							getline(input, badLine);
							cout << "Ignoring bad RESIDENTIAL in input file: " << type << " " << rental << " " << value << " " << occupied << " " << badLine << "\n\n";
						}
						else{
							getline(input, address);
							Property* newProperty = new Residential(id, address, rental, value, occupied);
							properties.push_back(newProperty);		//pushes new property
							id++;
						}
					}
				}
			}
			else if (type == "Commercial"){		//inputs checked for commercial
				input >> rental;
				if (input.fail() || (rental != 1 && rental != 0)){
					input.clear();
					getline(input, badLine);
					cout << "Ignoring bad COMMERCIAL in input file: " << type << " " << rental << " " << badLine << "" << "\n\n";
				}
				else{
					input >> value;
					if (input.fail() || value <= 0){
						input.clear();
						getline(input, badLine);
						cout << "Ignoring bad COMMERCIAL in input file: " << type << " " << rental << " " << value << " " << badLine << "\n\n";
					}
					else{
						input >> discounted;
						if (input.fail() || (discounted != 0 && discounted != 1)){
							input.clear();
							getline(input, badLine);
							cout << "Ignoring bad COMMERCIAL in input file: " << type << " " << rental << " " << value << " " << discounted << " " << badLine << "\n\n";
						}
						else{
							input >> discountRate;
							if (input.fail() || discountRate >= 1){
								input.clear();
								getline(input, badLine);
								cout << "Ignoring bad COMMERCIAL in input file: " << type << " " << rental << " " << value << " " << discounted << " " << discountRate << " " << badLine << "\n\n";
							}
							else{
								getline(input, address);
								Property* newProperty = new Commercial(id, address, rental, value, discounted, discountRate);
								properties.push_back(newProperty);
								id++;
							}
						}
					}
				}
			}
			else{			//in case there is neither commercial or residential
				getline(input, badLine);
				cout << "Ignoring unknown types of properties appearing in the input file: " << type << " " << badLine << "\n\n";
			}
			
		}
		
	}
	input.close();		//closes stream
	return true;
	
}

void printTaxReport(vector<Property*> properties){		//prints tax report
	cout << "NOW PRINTING TAX REPORT:\n\n";
	for (int i = 0; i < properties.size(); i++){
		cout << "** Taxes due for the property at: " << properties[i]->getAddress() << "\n";
		cout << "Property ID: " << properties[i]->getID() << "\n";
		cout << "This property has an estimated value of: " << properties[i]->getValue() << "\n";
		cout << "Taxes due on this property are: " << properties[i]->getTaxes() << "\n\n";
	}
}

void printProperties(vector<Property*> properties){		//prints valid propeties
	cout << "All valid properties:" << endl;
	for (int i = 0; i < properties.size(); i++){
		cout << properties[i]->toString() << endl;
	}
}

int main(){
	vector<Property*> properties;		//creates property pointer vector
	string fileName;

	cout << "Enter the location of the file: ";
	getline(cin, fileName);		//captures file name

	if (openFile(properties, fileName)){		//checks to see if file existed, if yes prints properties and tax report
		
		printProperties(properties);
		printTaxReport(properties);
	}
	else{		//fails
		cout << "Failed.";
	}

	system("pause");		//allows you to read the output

	return 0;
}