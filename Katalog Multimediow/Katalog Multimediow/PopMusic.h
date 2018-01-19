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

struct PopMusicData
{
	int year;
	Person performer;
	string title;
};

class PopMusic :
	public Record
{
private:
	static int count;	

public:
	PopMusicData data;
	PopMusic();
	PopMusic(const PopMusic&) { count++; }
	~PopMusic();

	static int getCount() { return count; };
	int getId() { return this->id; }
};

