#include "Person.h"

Person::Person()
{

}

Person::~Person()
{

}

bool Person::operator==(const Person& p) 
{
	if ((this->firstName == p.firstName) && (this->lastName == p.lastName))
		return true;
	else
		return false;
}

void Person::display() 
{
	cout << this->firstName << " " << this->lastName;
}