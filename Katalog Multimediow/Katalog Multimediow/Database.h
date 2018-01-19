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
#include <Windows.h>
using namespace std;

//=================================
// defines
#define FILE_READ_ERROR 1
#define UNIDENTIFIED_RECORD_TYPE_ERROR 2

#define ATTRIBUTE_DELIMETER ':'
#define NAME_DELIMETER ','
#define PERSON_DELIMETER '!'
#define ADDON_DELIMETER '!'
#define YEAR_DELIMETER '-'

#define RECORDTYPE_MOVIE "FILM"
#define RECORDTYPE_CLASSICMUSIC "KLASYKA"
#define RECORDTYPE_POPMUSIC "POP"
#define RECORDTYPE_GAME "GRA"

#define ATTRTYPE_PERFORMER 0
#define ATTRTYPE_DIRECTOR 1
#define ATTRTYPE_TITLE 2
#define ATTRTYPE_YEARRANGE 3

//=================================
// class code
enum RecordType
{
	MOVIE, CLASSICMUSIC, POPMUSIC, GAME, ALL, UNIDENTIFIED
};
class Database
{
private:
	vector<Movie> movies;
	vector<ClassicMusic> classicTracks;
	vector<PopMusic> popTracks;
	vector<Game> games;

	vector<string> readFile(string path);
	RecordType getRecordType(string type);
	vector<Person> createPersons(string persons);
	void addMovie(vector<string> attributes);
	void addClassicMusic(vector<string> attributes);
	void addPopMusic(vector<string> attributes);
	void addGame(vector<string> attributes);
	vector<Record*> searchRecords(RecordType type, int attrType, string attrValue);
	vector<Record*> searchMovies(int attrType, string attrValue);
	vector<Record*> searchClassicMusic(int attrType, string attrValue);
	vector<Record*> searchPopMusic(int attrType, string attrValue);
	vector<Record*> searchGames(int attrType, string attrValue);
public:
	int addRecord(string record);
	int importFromFile(string path);
	int displayRecords(RecordType type, int attrType, string attrValue);
	Database();
	~Database();
};

