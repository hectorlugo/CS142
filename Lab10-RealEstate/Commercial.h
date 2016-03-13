#pragma once
#include "Property.h"

using namespace std;

class Commercial : public Property
{
private:
	int id;
	string address;
	int rental;
	int value;
	int discounted;
	double rate;
	double taxes;

public:
	Commercial(int id_in, string address_in, int rental_in, int value_in, int discounted_in, double rate_in);
	~Commercial();

	string toString();
	double getTaxes();
};