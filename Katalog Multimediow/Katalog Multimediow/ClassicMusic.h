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
#include <iostream>
using namespace std;

//=================================
// class code
struct ClassicMusicData
{
	int year;
	Person composer;
	Person performer;
	string title;
	int catalogNumber;
	vector<Person> soloists;
};

class ClassicMusic :
	public Record
{
private:
	static int count;

public:
	ClassicMusicData data;
	ClassicMusic();
	ClassicMusic(const ClassicMusic& music) { count++; this->data = music.data; }
	~ClassicMusic();

	static int getCount() { return count; };
	int getId() { return this->id; }
	void display();
};

