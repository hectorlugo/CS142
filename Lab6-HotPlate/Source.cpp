#include <iostream>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

void initializeHotPlate(double(&plate)[20][20], int dimension, int min, int max){
	for (int i = 0; i < dimension; i++){		//goes to each spot in array to fill up with 0 and 100
		for (int j = 0; j < dimension; j++){
			if (i == 0 || i == 19){
				if (j == 0 || j == 19){
					plate[i][j] = min;
				}
				else{
					plate[i][j] = max;
				}
			}
			else{
				plate[i][j] = 0;
			}
		}
	}
}

void averageHotPlate(double(&oldPlate)[20][20], double(&plate)[20][20], bool& update, int dimension, double testValue, int divideBy){
	
	update = false;		//keeps track if there is  change larger than .1
	for (int i = 1; i < dimension - 1; i++){
		for (int j = 1; j < dimension - 1; j++){
			
			plate[i][j] = (oldPlate[i + 1][j] + oldPlate[i - 1][j] + oldPlate[i][j + 1] + oldPlate[i][j - 1]) / divideBy;		//gets variables from north, south, east, and west and divides by 4
			if (abs(plate[i][j] - oldPlate[i][j]) > testValue){		//testing to see if there is a change larger than .1
				update = true;
			}
		}
	}
	for (int i = 1; i < dimension - 1; i++){		//copy new array into old array to prepare for next iteration
		for (int j = 1; j < dimension - 1; j++){
			oldPlate[i][j] = plate[i][j];
		}
	}
}

void printHotPlate(double(&plate)[20][20], int dimension){
	for (int i = 0; i < dimension; i++){		//prints each variable in array
		for (int j = 0; j < dimension; j++){

			if (j == dimension - 1 && i != dimension - 1){
				cout << fixed << setprecision(1) << plate[i][j] << "\n";
			}
			else{
				cout << fixed << setprecision(1) << plate[i][j] << " ";
			}
		}
	}
}

void exportHotPlate(double(&plate)[20][20], int dimension){
	ofstream out_file;		//create export variable
	out_file.open("lab6output.csv");		//opens export file for editing

	for (int i = 0; i < dimension; i++){		//prints each value to file
		for (int j = 0; j < dimension; j++){

			if (j == dimension - 1){
				out_file << fixed << setprecision(1) << plate[i][j] << ",\n";
			}
			else{
				out_file << fixed << setprecision(1) << plate[i][j] << ",";
			}
		}
	}
}


int main()
{
	const int max = 100;
	const int min = 0;
	const int dimension = 20;
	bool update = true;
	const double testValue = .1;
	const int divideBy = 4;
	
	double oldPlate[dimension][dimension];		//create aray
	double plate[dimension][dimension];		

	initializeHotPlate(oldPlate, dimension, min, max);		//initialize array
	initializeHotPlate(plate, dimension, min, max);
	printHotPlate(oldPlate, dimension);
	cout << "\n\n";
	averageHotPlate(oldPlate, plate, update, dimension, testValue, divideBy);
	printHotPlate(plate, dimension);
	cout << "\n\n";
	while (update){		//iterates until no change grater than .1
		averageHotPlate(oldPlate, plate, update, dimension, testValue, divideBy);
	}
	printHotPlate(plate, dimension);		//prints out array
	cout << "\n\n";
	exportHotPlate(plate, dimension);		//exports the array

	return 0;
}