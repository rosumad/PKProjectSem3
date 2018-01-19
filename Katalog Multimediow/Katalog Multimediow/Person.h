//=================================
// include guard
#pragma once

//=================================
// forward declared dependencies

//=================================
// included dependencies
#include <string>
#include <iostream>
using namespace std;

//=================================
// class code
class Person
{
public:
	string firstName;
	string lastName;
	Person();
	~Person();

	bool operator==(const Person& p);
	void display();
};