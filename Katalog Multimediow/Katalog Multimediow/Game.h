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
struct GameData
{
	int year;
	Person director;
	string title;
	vector<string> addons;
};

class Game :
	public Record
{
private:
	static int count;
	int id;
	GameData data;

public:
	Game();
	~Game();
};

