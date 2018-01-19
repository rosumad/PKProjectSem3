//=================================
// include guard
#pragma once

//=================================
// included dependencies
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstdlib>
#include <conio.h>
using namespace std;

//=================================
// defines
#define	KEY_ESC	27
#define KEY_ARROWSPECIAL 224
#define KEY_ARROWUP 72
#define KEY_ARROWDOWN 80
#define KEY_ARROWLEFT 75
#define KEY_ARROWRIGHT 77
#define KEY_ENTER 13
#define KEY_0 48
#define elemsPerPage 10
#define CURSOR "    ->  "
#define CHOICE_ESCAPE -1

//=================================
// class code
class Menu
{
private:
	int windowSize;
	string name;
	vector<string> elements;
	int cursorPosition;
	int choice;
	int menuPage;

	void show();
	void showOnePage();
	void showMultiplePages();
	bool fitOnOnePage();
	bool pageIsFull();
	void moveCursor();
	void moveCursorUp();
	void moveCursorDown();
	void movePageLeft();
	void movePageRight();
	void handlePressedKey(int pressedKey);
	bool choiceMade();
public:
	Menu();
	Menu(int windowSize);
	Menu(int windowSize, string name);
	Menu(int windowSize, string name, vector<string> elements);
	~Menu();

	void addElem(string textToDisplay);
	void removeElem(int elemToDel);
	
	int use();
};