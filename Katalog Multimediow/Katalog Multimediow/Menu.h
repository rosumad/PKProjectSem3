#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

#pragma once
class Menu
{
private:
	int windowSize;
	string name;
	vector<string> elements;
	int cursorPosition;
	int choice;

public:
	Menu();
	Menu(int windowSize);
	Menu(int windowSize, string name);
	Menu(int windowSize, string name, vector<string> elements);
	~Menu();

	int addElem(string textToDisplay);
	int removeElem(int elemToDel);
	int show();

};

