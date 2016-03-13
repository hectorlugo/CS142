#pragma once
#include "Property.h"

using namespace std;

class Residential : public Property
{
private:
	int id;
	string address;
	int rental;
	int value;
	int occupied;
	double taxes;

public:
	Residential(int id_in, string address_in, int rental_in, int value_in, int occupied_in);
	~Residential();

	double getTaxes();
	string toString();

};