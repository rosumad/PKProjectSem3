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
#include <sstream>
using namespace std;

//=================================
// defines
#define FILE_READ_ERROR 1
#define UNIDENTIFIED_RECORD_TYPE_ERROR 2
#define ATTRIBUTE_DELIMETER ':'
#define NAME_DELIMETER ','
#define PERSON_DELIMETER '!'
#define ADDON_DELIMETER '!'
#define RECORDTYPE_MOVIE "FILM"
#define RECORDTYPE_CLASSICMUSIC "KLASYKA"
#define RECORDTYPE_POPMUSIC "POP"
#define RECORDTYPE_GAME "GRA"

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
	enum RecordType
	{
		MOVIE, CLASSICMUSIC, POPMUSIC, GAME, UNIDENTIFIED
	};
	RecordType getRecordType(string type);
	vector<Person> createPersons(string persons);
	void addMovie(vector<string> attributes);
	void addClassicMusic(vector<string> attributes);
	void addPopMusic(vector<string> attributes);
	void addGame(vector<string> attributes);
public:
	int addRecord(string record);
	int importFromFile(string path);
	Database();
	~Database();
};

