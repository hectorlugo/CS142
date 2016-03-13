#include "Commercial.h"
#include <sstream>
#include <iostream>

Commercial::Commercial(int id_in, string address_in, int rental_in, int value_in, int discounted_in, double rate_in) : Property(id_in, address_in, rental_in, value_in)
{
	id = id_in;
	address = address_in;
	rental = rental_in;
	value = value_in;
	discounted = discounted_in;
	rate = rate_in;
}
Commercial::~Commercial(){}

string Commercial::toString()
{
	stringstream ss;
	ss << Property::toString();
	if (discounted){ ss << "Discounted  Discount: " << rate; }
	else{ ss << "NOT Discounted"; }
	ss << endl;
	return ss.str();
}

double Commercial::getTaxes()
{
	const double RENTAL_RATE = .012;
	const double NON_RENTAL_RATE = .01;
	double taxRate;
	if (rental){
		taxRate = RENTAL_RATE * (1 - rate);
		taxes = value * taxRate;
	}
	else{
		taxRate = NON_RENTAL_RATE * (1 - rate);
		taxes = value * taxRate;
	}
	return taxes;
}