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
#include <vector>
#include <string>
using namespace std;

//=================================
// defines


//=================================
// class code
class Database
{
private:
	vector<Movie> movies;
	vector<ClassicMusic> classicTracks;
	vector<PopMusic> popTracks;
	vector<Game> games;

public:
	void addMovie();
	void importFromFile(string path);
	Database();
	~Database();
};

