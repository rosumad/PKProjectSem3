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
	int id;
	PopMusicData data;

public:
	PopMusic();
	~PopMusic();
};

