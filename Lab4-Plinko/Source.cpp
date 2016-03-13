#include <iostream>
#include <math.h>
#include <iomanip>
#include <ctime>
#include <cstdlib>

//Choose option 1, Choose slot 10, Result: Invalid slot, Returned to main. Choose 1, choose 3, Path[3.0 3.5 3.0 205 3.0 3.5 4.0 3.5 3.0 3.5 4.0 3.5 3.0]: $0.00 winnings. Choose 3. GOODBYE!
//Choose option 2, Choose -10 chips, Result: INVALID NUMBER OF CHIPS, returned to main menu. Choose 2, choose 250, choose 4, Won $126,000.00, 504 per chip. Choose 3. GOODBYE!
//Choose option 1, choose 6, Won 10,000.00, choose 2. choose 120, choose 8, total winnings 224500.00, 1870.83 per chip. choose 3. GOODBYE!

using namespace std;

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
	
	while (x < 1 || x > 3)		 //makes sure menu selection is 1,2, or 3
	{
		cout << "MENU: Please select one of the following options:\n" << 
			"  1 - Drop a single chip into one slot\n" << 
			"  2 - Drop multiple chips into one slot\n" <<
			"  3 - Quit the program\n" <<
			"Enter your selection now: ";

		cin >> x;

		if (x < 1 || x > 3)		//response for bad entry
		{
			cout << "INVALID SELECTION.   Please enter 1, 2 or 3\n\n\n";
		}
		else if (x == 1)		//option 1 result
		{
			cout << "\n\n*** DROP SINGLE CHIP ***\n" <<
				"Which slot do you want to drop the chip in [0-8]? ";
			cin >> slot;
			if (slot < 0 || slot > 8)	//return to menu if invalid slot chosen.
			{
				cout << "INVALID SLOT. Please enter an integer between 0 and 8\n\n\n";
				x = 0;
			}
			else						//result for correct slot selection
			{
				cout << "\n\n*** DROPPING CHIP INTO SLOT " << slot << " ***\n";
				cout << "PATH: [" << setprecision(1) << fixed << slot;
				x = 0;
				

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
					
					cout << setprecision(1) << fixed << " " << slot;		//prints out path 
					
				}
				
				cout << "]\n";

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
				cout << "WINNINGS: $" << setprecision(2) << fixed << winnings << "\n\n\n";
				winnings = reset;
			}
			
		}
		else if (x == 2)		//result for option 2
		{
			cout << "\n\n*** DROP MULTIPLE CHIPS ***\n" <<
				"How many chips do you want to drop [>0]? ";
			cin >> chips;
			if (chips < 1)		//return to menu for invalid chip amount
			{
				cout << "INVALID NUMBER OF CHIPS. Please enter an integer greater than zero.\n\n\n";
				x = 0;
			}
			else{			//ask for slot
				cout << "Which slot do you want to drop the chip in [0-8]? ";
				cin >> slot;
				if (slot < 0 || slot > 8)		//return to menu for invalid slot
				{
					cout << "INVALID SLOT. Please enter an integer between 0 and 8\n\n\n";
					x = 0;
				}
				else
				{
					x = 0;
				
					double start = slot;
					for (int c = 0; c < chips; c++)		//repeat for each chip
					{
						start = slot;
						for (int i = 0; i < 12; i++)	//calculate each chip winnings
						{
							if (start == 0)
							{
								start += .5;
							}
							else if (start == 8)
							{
								start -= .5;
							}
							else
							{
								int r = rand() % 2;
								if (r == 1)
								{
									start -= .5;
								}
								else
								{
									start += .5;
								}
							}

						}



						if (start == 0 || start == 8)		//add winnings
						{
							winnings += hundred;
						}
						else if (start == 1 || start == 7)
						{
							winnings += fiveHun;
						}
						else if (start == 2 || start == 6)
						{
							winnings += thousand;
						}
						else if (start == 3 || start == 5)
						{
							winnings += zero;
						}
						else if (start == 4)
						{
							winnings += win;
						}
						
					}
					cout << "Total Winnings on " << chips << " chips: $" << setprecision(2) << fixed << winnings <<
						"\nAverage winnings per chip: $" << setprecision(2) << fixed << (winnings / chips) << "\n\n\n";		//calculate total winnings and winnings per chip
					winnings = reset;
				}

			}
		}
		else if (x == 3)		//exit program option
		{
			cout << "GOODBYE!";
			return 0;
		}
		
	}
	

	return 0;
}