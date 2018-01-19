//=================================
// include guard
#pragma once

//=================================
// forward declared dependencies

//=================================
// included dependencies
#include "Record.h"
#include "Person.h"
#include <iostream>
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

public:
	MovieData data;
	Movie();
	Movie(const Movie& movie) { count++; this->data = movie.data; }
	~Movie();

	static int getCount() { return count; };
	int getId() { return this->id; }
	void display();
};

