#include <iostream> 
#include <vector>
#include <string>
#include <ctime>

//1 – displays restaurants, 2 – add a restaurant, C, C has been added to the tournament, 4 – List of restaurants has been shuffled, + - that was an invalid choice, 5 – you don’t have enough restaurants in your list, 6 – exit the program. CLOSE
//3 – remove a restaurant, Outback – Restaurant Outback has been removed from the list, 4 – List of restaurants has been shuffled, 5 – you don’t have enough restaurants in your list, 6 – quit the program. CLOSE
//1 - displays restaurants, 4 - list of restuarnts has been shuffled, 5 - Starting the tournament, 2, 1, 2, 1, 2, 1, 1 - Brasas is the Winner, 5 - You dont have enough restaurant in your list, 6 - Quit the program. CLOSE.

using namespace std;

int findRestaurant(vector<string>& restaurants, string name){
	for (int i = 0; i < restaurants.size(); i++){		//goes thru each element in the vector searching for the name
		if (restaurants[i] == name){
			return i;		//return index if found
		}
	}
	return -1;				//return -1 if not found
}


void addRestaurant(vector<string>& restaurants){
	cin.clear();		//allows cin to capture more than one word
	cin.sync();
	string name;
	cout << "Enter the restaurant's name: ";
	getline(cin, name);		//gets a line of text and puts it in name

	int test = findRestaurant(restaurants, name);		//checks to see if restaurant is already there
	if (test >= 0){
		cout << "This restaurant is already in the list.\n\n";		//doesn't add restaurant since its already there
	}
	else{
		restaurants.push_back(name);		//adds restaurant to list if its not there
		cout << "Restaurant " << name << " has been added to the tournament.\n\n";
	}

}

void removeRestaurant(vector<string>& restaurants){
	cin.clear();		//allows caputre of full line
	cin.sync();
	string name;
	cout << "Enter the restaurant's name you want to remove: ";
	getline(cin, name);

	int test = findRestaurant(restaurants, name);
	if (test >= 0){
		int last = restaurants.size() - 1;		//if restaurant is found it removes it from the list
		restaurants[test] = restaurants[last];
		restaurants.pop_back();
		cout << "Restaurant " << name << " has been removed from the list.\n\n";
	}
	else{
		cout << "Restaurant " << name << " was not found.\n\n";		//if restaurant is not there it says it
	}
}

void display(vector<string> restaurants){		//prints out the vector
	cout << "\n";
	for (int i = 0; i < restaurants.size(); i++){  //goes thru each name in the vector and prints it out
		if (i == restaurants.size() - 1){
			cout << restaurants[i] << "\n\n";
		}
		else{
			cout << restaurants[i] << ", ";
		}
	}
}

void shuffleRestaurants(vector<string>& restaurants){  //shuffles the restaurants
	vector<string> temp;		//creates a temporary restaurant
	int size = restaurants.size();		//gets the size of the restaurant
	int random;		//the random variable
	int last;		//int for last spot in the vector
	for (int i = 0; i < size; i++){		//will repeat for each item in vector
		random = rand() % restaurants.size();		//gets a random variable depending on the size of the vector
		temp.push_back(restaurants[random]);		//moves data to another vector creating new list
		last = restaurants.size() - 1;			//removes the selected data from old vector
		restaurants[random] = restaurants[last];
		restaurants.pop_back();
	}
	restaurants = temp;			//sets restaurant vector to the new shuffled vector
	cout << "List of restaurants has been shuffled.\n\n";		//informs user of success
}

int menu(){		//displays menu options
	int choice;
	cout << "\n 1 - Display all restaurants\n 2 - Add a restaurant\n 3 - Remove a restaurant\n 4 - Shuffle the vector\n 5 - Begin the tournament\n 6 - Quit the program\n\nMake a selection: ";

	cin >> choice;		//makes sure its a valid choice
	if (cin.fail()){
		cin.clear();
		cin.ignore();
	}
	return choice;
}

bool testList(int listSize, int& round){		//checks to see if list has 2^n restaurants
	bool testing = true;
	round = 0;
	while (testing){		//divides by 2 continually until it reaches one or finds a remainder of is
		if (listSize % 2 == 0){
			listSize = listSize / 2;
			round++;
		}
		else if (listSize == 1){		//if there is a remainder of 1 checks to see if listSize is 1
			testing = false;
		}
		else{
			return false;		//returns false if both previous options were not true
		}
	}
	return true;  //returns true if once list check has been completed
}

void runTournament(vector<string>& restaurants){  //runs the tournament
	int round = 1;
	int match = 1;
	int totalRound = 0;
	int totalMatch;
	int choice;
	bool inputTest;
	bool sizeCheck = testList(restaurants.size(), totalRound);  //test to see if list has enough restaurants
	
	if (sizeCheck && restaurants.size() != 1){
		cout << "\nStarting the tournament.\n";
		while (restaurants.size() > 1){  //while there are more than one restaurants in the vector it will run the tournament
			vector<string> temp;
			totalMatch = restaurants.size() / 2;		//keeps track of the total mathes in the round
			for (int i = 0; i < restaurants.size(); i += 2){		//goes thru all restaurants in vector to do a match
				inputTest = true;
				while (inputTest){		//keeps prompting for answer if input is invalid
					cout << "\nRound: " << round << "/" << totalRound << "\tMatch: " << match << "/" << totalMatch << "\n\n 1 - " << restaurants[i] << "\n 2 - " << restaurants[i + 1] << "\n\n What restaurant do you choose: ";		//displays position in round
					cin >> choice;
					if (cin.fail()){
						cin.clear();
						cin.ignore();
						cout << "\nThat was an invalid entry.\n\n";
					}
					else if (choice == 1){		//pushes selected restaurant into new vector and increments match
						temp.push_back(restaurants[i]);
						inputTest = false;		//allows it to stop reprompting when input was valid
						match++;
					}
					else if (choice == 2){
						temp.push_back(restaurants[i + 1]);
						inputTest = false;
						match++;
					}
					else{		//continues reprompting if outside of range
						cout << "\nPlease select option 1 or 2\n\n";
					}
				}
			}
			restaurants = temp;		//sets restaurants to the new vector
			round++;		//increments round
			match = 1;		//resets match number
		}
		cout << "\n" << restaurants[0] << " is the winner.\n";
	}
	else{
		cout << "\nYou don't have enough restaurants in your list.\n";
	}
}

int main(){
	srand(time(0));
	vector<string> restaurants;			//creates vector then populates it
	restaurants.push_back("Carl's Jr");
	restaurants.push_back("Texas Roadhouse");
	restaurants.push_back("Red Lobster");
	restaurants.push_back("Dominoes");
	restaurants.push_back("Brasas");
	restaurants.push_back("Olive Garden");
	restaurants.push_back("In-N-Out");
	restaurants.push_back("Outback");

	
	bool play = true;		//bool to check if main menu shoul continue prompting

	while (play){
		int choice = menu();

		if (choice == 1){		//executes display restaurants
			display(restaurants);
		}
		else if(choice == 2){		//adds a restaurant
			addRestaurant(restaurants);
		}
		else if (choice == 3){		//removes a restaurant
			removeRestaurant(restaurants);
		}
		else if (choice == 4){		//shuffles vector
			shuffleRestaurants(restaurants);
		}
		else if (choice == 5){		//runs the tournament
			runTournament(restaurants);
		}
		else if (choice == 6){ play = false; }		//exits the program
		else {
			cout << "That was an invalid choice.\n";
		}
	}

	return 0;
}