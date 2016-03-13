#include "Player.h"
using namespace std;

Player::Player(string name_in, double wins_in, int losses_in, int draws_in) 
{
	name = name_in;
	wins = wins_in;
	losses = losses_in;
	draws = draws_in;
}
Player::~Player(){}

string Player::getName()
{
	return name;
}
void Player::setWins()
{
	wins++;
}
void Player::setLosses()
{
	losses++;
}
void Player::setDraws()
{
	draws++;
}
int Player::getRPSThrow()
{
	int random = (rand() % 3);
	return random;
}
double Player::getWinRecord()
{
	double record = wins / (wins + losses + draws);
	return record;
}
string Player::toString()
{
	stringstream ss;
	ss << "Name: " << name << endl;
	ss << "Wins: " << wins << endl;
	ss << "Losses: " << losses << endl;
	ss << "Draws: " << draws << endl;
	if ((wins + losses + draws) == 0){
		ss << "Win Percentage: No Games Played" << endl;
	}
	else{
		ss << "Win Percentage: " << fixed << setprecision(0) << (getWinRecord() * 100) << "%" << endl;
	}
	
	return ss.str();
}