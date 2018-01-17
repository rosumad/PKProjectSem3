//=================================
// include guard
#pragma once

//=================================
// forward declared dependencies

//=================================
// included dependencies
#include "Movie.h"
#include "ClassicMusic.h"
#include "PopMusic.h"
#include "Game.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//=================================
// defines
#define FILE_READ_ERROR 1

//=================================
// class code
class Database
{
private:
	vector<Movie> movies;
	vector<ClassicMusic> classicTracks;
	vector<PopMusic> popTracks;
	vector<Game> games;

	vector<string> readFile(string path);
public:
	void addRecord(string record);
	int importFromFile(string path);
	Database();
	~Database();
};

