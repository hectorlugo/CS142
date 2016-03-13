#pragma once
#include <string>

using namespace std;

class Property
{
private:
	int id;
	string address;
	int rental;
	int value;
	static int counter;
	

public:
	Property(int id, string address, int rental, int value);
	~Property();
	
	virtual int getID();
	virtual int getValue();
	virtual string getAddress();
	virtual string toString();
	virtual double getTaxes() = 0;
};