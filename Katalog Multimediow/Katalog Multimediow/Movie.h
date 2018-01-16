//=================================
// include guard
#pragma once

//=================================
// forward declared dependencies

//=================================
// included dependencies
#include "Record.h"
#include "Person.h"
#include <string>
#include <vector>
using namespace std;

//=================================
// class code
struct MovieData
{
	int year;
	Person director;
	string title;
	vector<Person> actors;
};

class Movie :
	public Record
{
private:
	static int count;
	int id;
	MovieData data;

public:
	Movie();
	~Movie();
};

