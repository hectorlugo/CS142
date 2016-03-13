#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Player
{

private:
	string name;
	double wins;
	int losses;
	int draws;
	double total;

public:
	Player(string name_in, double wins_in, int losses_in, int draws_in);
	virtual ~Player();

	string getName();
	void setWins();
	void setLosses();
	void setDraws();

	int getRPSThrow();

	double getWinRecord();

	string toString();
};