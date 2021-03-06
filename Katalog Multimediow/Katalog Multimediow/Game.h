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
struct GameData
{
	int year;
	string director;
	string title;
	vector<string> addons;
};

class Game :
	public Record
{
private:
	static int count;
	
public:
	GameData data;
	Game();
	Game(const Game& game) { count++; this->data = game.data; }
	~Game();

	static int getCount() { return count; };
	int getId() { return this->id; }
	void display();
};