#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "Player.h"

//2 - add player, Hector, Hector has been created. 5 - Fight, Not enough players. 3 - add to line up, Hector. Hector has been added to game. 3 - add to line up, Hector. Hector has been added to game. 5 - fight. Game is auto draw.6 - quit. CLOSE
//2 - add, Hector. 2 - add, Rob. 3 - Hector, 3 - Rob. 4 - Show line up. Hector, Rob. 5 - fight. Hector throws paper, Rob Throws scissors, Rob wins. 1 - Show players. Hector 0,1,0, 0%, Rob - 1,0,0, 100%. 4 - Show line up, There are no players in the line up. 6 - quit. CLOSE
//2 - add, Rob Smith, Rob Smith has been created. 2 - add, Jenny, Jenny has been created. 2 - add, Jenny, Jenny already exists. 6, quit. CLOSE

using namespace std;

int findPlayer(vector<Player*>& playerList, string name){		//searches for a player name in the vector
	for (int i = 0; i < playerList.size(); i++){
		if (playerList[i]->getName() == name){
			return i;		//returns index of pointer if found
		}
	}
	return -1;				//returns -1 otherwise
}

void showPlayers(vector<Player*> playerList){		//uses toString to output player info
	cout << "\n";
	if (playerList.size() == 0){
		cout << "\nNo players have been created.\n\n";
	}
	else{
		for (int i = 0; i < playerList.size(); i++){		//for loop goes thru each pointer
			cout << playerList[i]->toString() << endl;
		}
	}
}

void addNewPlayer(vector<Player*>& playerList){
	cin.clear();									//allos name with spaces
	cin.sync();
	string name;
	cout << "\nEnter players name: ";
	getline(cin, name);

	int found = findPlayer(playerList, name);		//checks to see if player already exists
	if (found >= 0){
		cout << "\nThis player already exists.\n\n";		//doesnt add player cuz it exists
	}
	else{
		Player* newPlayer = new Player(name, 0, 0, 0);		//creates new player is conditions are correct
		playerList.push_back(newPlayer);
		cout << "\nPlayer " << name << " has been created.\n\n";
	}
}

void addToLineUp(vector<Player*>& gameList, vector<Player*> playerList){		//adds existing playre to the line up
	cin.clear();									//makes it able to read name with spaces
	cin.sync();
	string name;
	cout << "\nEnter players name: ";
	getline(cin, name);

	int found = findPlayer(playerList, name);		//checks to see if player already exists
	if (found >= 0){
		Player* newPointer = playerList[found];		//creates new pointer for existing player and adds pointer to other list
		gameList.push_back(newPointer);
		cout << "\nPlayer " << name << " has beed added to the game.\n\n";
	}
	else{
		cout << "\nThis player does not exist.\n\n";
	}

}

void showLineUp(vector<Player*> playerList){			//shows players in the lineup. Just the name
	cout << "\n";
	if (playerList.size() == 0){
		cout << "\nThere are no players in the line up.\n\n";
	}
	else{
		for (int i = 0; i < playerList.size(); i++){
			cout << playerList[i]->getName() << endl;		//gets name
		}
	}
	
}

string result(int throwInt){			//returns rock, paper, or scissors depending on random throw result
	if (throwInt == 0){
		return "Paper";
	}
	else if (throwInt == 1){
		return "Scissors";
	}
	else{
		return "Rock";
	}
}

void fight(vector<Player*>& playerList){		//starts a RPS fight between first two players in line up
	if (playerList.size() < 2){					//checks to see if there is at least two
		cout << "\nNot Enough Players for a fight.\n\n";
	}
	else{
		Player* playerA = playerList[0];		//creates two pointers with data from list to make it easier to understand
		Player* playerB = playerList[1];
		cout << "\nFight initiated between " << playerA->getName() << " and " << playerB->getName() << "!\n\n" << endl;
		if (playerA->getName() == playerB->getName()){		//checks to see if first two players are the same person
			cout << "Game is outmatic draw.\n\n";
			playerA->setDraws();		//updates draw varaible
		}
		else{
			//2 = rock
			//1 = scissors
			//0 = paper
			int throwA = playerA->getRPSThrow();		//gets random throw for each player
			int throwB = playerB->getRPSThrow();

			cout << playerA->getName() << " throws " << result(throwA) << "!\n\n";		//outputs info on throws
			cout << playerB->getName() << " throws " << result(throwB) << "!\n\n";

			if (throwA == throwB){		//checks for a draw
				cout << "Fight is a draw!\n\n";
				playerA->setDraws();
				playerB->setDraws();
			}
			else if(throwA - throwB == 1 || throwA - throwB == -2){		//use math to calculate who would win. 
				cout << playerA->getName() << " is the winner! \n\n";
				playerA->setWins();
				playerB->setLosses();
			}
			else{
				cout << playerB->getName() << " is the winner! \n\n";		//if player A doesnt win then player B does
				playerB->setWins();
				playerA->setLosses();
			}
		}
		playerList.erase(playerList.begin());		//removes first two players from line-up
		playerList.erase(playerList.begin());
	}
}

int menu(){		//displays menu options
	int choice;
	cout << "\n 1 - Show Players\n 2 - Add Player\n 3 - Add to Line-up\n 4 - Show Line-up\n 5 - Fight\n 6 - Quit\n\nMake a selection: ";

	cin >> choice;		//makes sure its a valid choice
	if (cin.fail()){
		cin.clear();
		cin.ignore();
	}
	return choice;
}

int main(){
	srand(time(0));
	vector<Player*> allPlayers;		//pointer vectors
	vector<Player*> activePlayers;

	bool play = true;		//bool to check if main menu should continue prompting

	while (play){
		int choice = menu();

		if (choice == 1){		//Show players
			showPlayers(allPlayers);
		}
		else if (choice == 2){		//add player
			addNewPlayer(allPlayers);
		}
		else if (choice == 3){		//add to line-up
			addToLineUp(activePlayers, allPlayers);
		}
		else if (choice == 4){		//show line-up
			showLineUp(activePlayers);
		}
		else if (choice == 5){		//Fight
			fight(activePlayers);
		}
		else if (choice == 6){ play = false; }		//exits the program
		else {
			cout << "That was an invalid choice.\n";
		}
	}


	return 0;
}