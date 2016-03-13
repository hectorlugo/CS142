#include <iostream>
#include <math.h>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <string>

//Choose option 1, Choose slot 10, Result: Invalid slot, Returned to main. Choose 1, choose 3, Path[3.0 3.5 3.0 205 3.0 3.5 4.0 3.5 3.0 3.5 4.0 3.5 3.0]: $0.00 winnings. Choose 3. GOODBYE!
//Choose option 2, Choose -10 chips, Result: INVALID NUMBER OF CHIPS, returned to main menu. Choose 2, choose 250, choose 4, Won $126,000.00, 504 per chip. Choose 3. GOODBYE!
//Choose option 3, choose 20, Won 19700 in 0, 16600 in 1, 37300 in 2, 77000 in 3, 34600 in 4, 54000 in 5, 28500 in 6, 21300 in 7, 20400 in 8. Choose 3, Entered t, Invalid Entry. Choose 4. GOODBYE!

using namespace std;

void calcPath(double& slot, int levels, int x){
	
	for (int i = 0; i < levels; i++)		//repeats for each level
	{
		if (slot == 0)
		{
			slot += .5;
		}
		else if (slot == 8)
		{
			slot -= .5;
		}
		else
		{
			int r = rand() % 2 + 1;
			if (r == 1)
			{
				slot -= .5;
			}
			else
			{
				slot += .5;
			}
		}

		if (x == 1){ cout << setprecision(1) << fixed << " " << slot; }		//prints out path 

	}
}

double getPriceMoney(double& winnings, double& slot, int hundred, int fiveHun, int thousand, int zero, int win){

	if (slot == 0 || slot == 8)				//adding system for the winnings
	{
		winnings += hundred;
	}
	else if (slot == 1 || slot == 7)
	{
		winnings += fiveHun;
	}
	else if (slot == 2 || slot == 6)
	{
		winnings += thousand;
	}
	else if (slot == 3 || slot == 5)
	{
		winnings += zero;
	}
	else if (slot == 4)
	{
		winnings += win;
	}

	return winnings;
}

void simMultiChip(int chips, int& x, double slot, int levels, double winnings, int hundred, int fiveHun, int thousand, int zero, int win, int reset){
	cout << "\n\n*** DROP MULTIPLE CHIPS ***\n" <<
		"How many chips do you want to drop [>0]? ";
	cin >> chips;
	if (cin.fail()){
		cin.clear();
		cin.ignore();
		cout << "INVALID ENTRY. Please enter an integer greater than zero.\n\n\n";
		x = reset;
	}
	else if (chips < 1)		//return to menu for invalid chip amount
	{
		cout << "INVALID NUMBER OF CHIPS. Please enter an integer greater than zero.\n\n\n";
		x = reset;
	}
	else{			//ask for slot

		if (x == 2){
			cout << "Which slot do you want to drop the chip in [0-8]? ";
			cin >> slot;

			if (cin.fail()){
				cin.clear();
				cin.ignore();
				cout << "INVALID ENTRY. Please enter an integer between 0 and 8\n\n\n";
				x = reset;
			}
			else if (slot < 0 || slot > 8)		//return to menu for invalid slot
			{
				cout << "INVALID SLOT. Please enter an integer between 0 and 8\n\n\n";
				x = reset;
			}
			else
			{


				double start = slot;
				for (int c = 0; c < chips; c++)		//repeat for each chip
				{
					start = slot;
					calcPath(start, levels, x);		//calculate path
					getPriceMoney(winnings, start, hundred, fiveHun, thousand, zero, win);	//calculates winnings

				}
				cout << "Total Winnings on " << chips << " chips: $" << setprecision(2) << fixed << winnings <<
					"\nAverage winnings per chip: $" << setprecision(2) << fixed << (winnings / chips) << "\n\n\n";		//calculate total winnings and winnings per chip
				winnings = reset;
				x = reset;
			}
		}
		else{
			double start;
			for (int s = 0; s < 9; s++){
				
				for (int c = 0; c < chips; c++){
					start = s;
					calcPath(start, levels, x);
					getPriceMoney(winnings, start, hundred, fiveHun, thousand, zero, win);	//calculates winnings
				}
				cout << "Total Winnings on " << chips << " chips " << " in slot "<< s << " : $" << setprecision(2) << fixed << winnings <<
					"\nAverage winnings per chip: $" << setprecision(2) << fixed << (winnings / chips) << "\n\n\n";		//calculate total winnings and winnings per chip
				winnings = reset;
				

			}
			x = reset;
		}
	}
}

void simSingleChip(double& slot, int levels, int& x, double& winnings, int hundred, int fiveHun, int thousand, int zero, int win, int reset){
	cout << "\n\n*** DROP SINGLE CHIP ***\n" <<
		"Which slot do you want to drop the chip in [0-8]? ";
	cin >> slot;
	if (cin.fail()){
		cin.clear();
		cin.ignore();
		cout << "INVALID ENTRY. Please enter an integer between 0 and 8\n\n\n";
		x = reset;
	}
	else if (slot < 0 || slot > 8)	//return to menu if invalid slot chosen.
	{
		cout << "INVALID SLOT. Please enter an integer between 0 and 8\n\n\n";
		x = reset;
	}
	else						//result for correct slot selection
	{
		cout << "\n\n*** DROPPING CHIP INTO SLOT " << slot << " ***\n";
		
		cout << "PATH: [" << setprecision(1) << fixed << slot;
		calcPath(slot, levels, x);
		cout << "]\n";

		getPriceMoney(winnings, slot, hundred, fiveHun, thousand, zero, win);	//calculates winnings

		cout << "WINNINGS: $" << setprecision(2) << fixed << winnings << "\n\n\n";
		winnings = reset;
		x = reset;
	}
}

int main()
{
	int x = 0;
	double slot = 9;
	int chips = 0;
	double winnings = 0;
	const int hundred = 100;
	const int fiveHun = 500;
	const int thousand = 1000;
	const int zero = 0;
	const int win = 10000;
	const int levels = 12;
	const int reset = 0;
	srand(time(0));

	while (x < 1 || x > 4)		 //makes sure menu selection is 1,2,3, or 4
	{
		cout << "MENU: Please select one of the following options:\n" <<
			"  1 - Drop a single chip into one slot\n" <<
			"  2 - Drop multiple chips into one slot\n" <<
			"  3 - Drop multiple chips in every slot\n" <<
			"  4 - Quit the program\n" <<
			"Enter your selection now: ";

		cin >> x;
		string failed;
		while (cin.fail()){
			cin.clear();
			cin >> failed;
			//cin.ignore();
		}

		if (x < 1 || x > 4)		//response for bad entry
		{
			cout << "INVALID SELECTION.   Please enter 1, 2, 3, or 4\n\n\n";
		}
		else if (x == 1)		//option 1 result
		{
			simSingleChip(slot, levels, x, winnings, hundred, fiveHun, thousand, zero, win, reset);
		}
		else if (x == 2)		//result for option 2
		{
			simMultiChip(chips, x, slot, levels, winnings, hundred, fiveHun, thousand, zero, win, reset);
		}
		else if (x == 3){		//result for option 3
			simMultiChip(chips, x, slot, levels, winnings, hundred, fiveHun, thousand, zero, win, reset);
		}
		else if (x == 4)		//exit program option
		{
			cout << "GOODBYE!";
			return 0;
		}

	}


	return 0;
}