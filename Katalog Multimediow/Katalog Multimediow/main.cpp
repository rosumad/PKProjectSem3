#include "Menu.h"
#include "Record.h"
#include "Movie.h"
#include "Person.h"
#include "ClassicMusic.h"
#include "PopMusic.h"
#include "Game.h"
#include "Database.h"
#include <iostream>
using namespace std;

int Record::count = 0;
int Movie::count = 0;
int ClassicMusic::count = 0;
int PopMusic::count = 0;
int Game::count = 0;

int main() {
	Database database;

	database.importFromFile("import.txt");

	int x; cin >> x;
	return 1;
}