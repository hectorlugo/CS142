#include "Property.h"
#include <iostream>
#include <sstream>
int Property::counter = 0;
Property::Property(int id_in, string address_in, int rental_in, int value_in)
{
	id = counter;
	counter++;
	address = address_in;
	rental = rental_in;
	value = value_in;
}
Property::~Property(){}
int Property::getID()
{
	return id;
}
int Property::getValue()
{
	return value;
}
string Property::getAddress()
{
	return address;
}
string Property::toString()
{
	stringstream ss;
	ss << "Property ID: " << id << "  Address:  " << address << "  ";
	if (rental){ ss << "Rental  "; }
	else{ ss << "NOT Rental  "; }
	ss << "Estimated value: " << value << "  ";
	return ss.str();
}