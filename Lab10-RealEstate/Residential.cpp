#include "Residential.h"
#include <sstream>

using namespace std;

Residential::Residential(int id_in, string address_in, int rental_in, int value_in, int occupied_in) : Property(id_in, address_in, rental_in, value_in)
{
	id = id_in;
	address = address_in;
	rental = rental_in;
	value = value_in;
	occupied = occupied_in;
}
Residential::~Residential(){}

string Residential::toString()
{
	stringstream ss;
	ss << Property::toString();
	if (occupied){ ss << "occupied"; }
	else{ ss << "NOT occupied"; }
	ss << endl;
	return ss.str();
}

double Residential::getTaxes()
{
	const double OCCUPIED_RATE = .006;
	const double AVAILABLE_RATE = .009;
	
	if (occupied){
		taxes = value * OCCUPIED_RATE;
	}
	else{
		taxes = value * AVAILABLE_RATE;
	}
	return taxes;
}