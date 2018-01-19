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

Menu prepareMainMenu() 
{
	Menu menu(60, "Katalog multimediow");
	menu.addElem("Import z pliku");
	menu.addElem("Wyszukiwanie...");
	return menu;
}
Menu prepareSearchMenu() 
{
	Menu searchMenu(60, "Wyszukiwanie po kryterium");
	searchMenu.addElem("Wykonawca");
	searchMenu.addElem("Rezyser");
	searchMenu.addElem("Tytul");
	searchMenu.addElem("Lata");

	return searchMenu;
}
Menu prepareTypeMenu() 
{
	Menu typeMenu(60, "Jakiego typu wyszukiwac...");
	typeMenu.addElem("Film");
	typeMenu.addElem("Muzyka klasyczna");
	typeMenu.addElem("Muzyka popularna");
	typeMenu.addElem("Gra");
	typeMenu.addElem("Wszystkie");

	return typeMenu;
	
}
string askUserForPath() 
{
	string path;

	system("cls");
	cout << " Przykladowa sciezka: import.txt" << endl;
	cout << "Podaj sciezke pliku do zaimportowania: ";
	cin >> path;

	return path;
}
RecordType typeMenu();
string askUserForAttribValue(int attribType) 
{
	system("cls");
	string attribValue;
	switch (attribType) 
	{
	case 0:
		cout << " Format: Imie,Nazwisko  Przyklad: Michael,Jackson" << endl;
		cout << "Podaj wykonawce: ";
		break;
	case 1:
		cout << " Format: Imie,Nazwisko  Przyklad: James,Cameron" << endl;
		cout << "Podaj rezysera: ";
		break;
	case 2:
		cout << " Format: Tytul  Przyklad: Titanic" << endl;
		cout << "Podaj tytul: ";
		break;
	case 3:
		cout << " Format: YYYY-YYYY  Przyklad: 1980-1999" << endl;
		cout << "Podaj zakres lat: ";
		break;
	}
	cin.sync();
	getline(cin, attribValue);
	return attribValue;
}
int searchMenu(Database &database) 
{
	Menu searchMenu = prepareSearchMenu();
	RecordType recordTypeToSearch = ALL;
	int attribType;

	int searchMenuChoice = searchMenu.use();
	if (searchMenuChoice == CHOICE_ESCAPE)
		return -1;

	attribType = searchMenuChoice;
	recordTypeToSearch = typeMenu();
	string attribValue = askUserForAttribValue(attribType);
	database.displayRecords(recordTypeToSearch, attribType, attribValue);
}

RecordType typeMenu()
{
	Menu typeMenu = prepareTypeMenu();
	int typeMenuChoice = typeMenu.use();
	switch (typeMenuChoice)
	{
	case CHOICE_ESCAPE:
		return UNIDENTIFIED;
	case 0:
		return MOVIE;
	case 1:
		return CLASSICMUSIC;
	case 2:
		return POPMUSIC;
	case 3:
		return GAME;
	case 4:
		return ALL;
	}
	return UNIDENTIFIED;
}

int main() 
{
	Database database;
	Menu mainMenu = prepareMainMenu();
	int mainMenuChoice = 0;

	while (mainMenuChoice != CHOICE_ESCAPE)
	{
		mainMenuChoice = mainMenu.use();
		switch (mainMenuChoice)
		{
		case CHOICE_ESCAPE:
			break;
		case 0:
			database.importFromFile(askUserForPath());
			break;
		case 1:
			searchMenu(database);
			break;
		}
	}

	return 0;
}