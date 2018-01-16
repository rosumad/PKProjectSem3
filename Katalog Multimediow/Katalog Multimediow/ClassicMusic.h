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
	int id;
	ClassicMusicData data;

public:
	ClassicMusic();
	~ClassicMusic();
};

