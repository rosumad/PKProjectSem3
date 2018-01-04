#include "Menu.h"

Menu::Menu() 
{
	this->windowSize = 60;
	this->name = "";
	this->cursorPosition = 0;
	this->choice = 0;
}

Menu::Menu(int windowSize)
{
	this->windowSize = windowSize;
	this->name = "";
	this->cursorPosition = 0;
	this->choice = 0;
}

Menu::Menu(int windowSize, string name)
{
	this->windowSize = windowSize;
	this->name = name;
	this->cursorPosition = 0;
	this->choice = 0;
}

Menu::Menu(int windowSize, string name, vector<string> elements)
{
	this->windowSize = windowSize;
	this->name = name;
	this->elements = elements;
	this->cursorPosition = 0;
	this->choice = 0;
}

Menu::~Menu() 
{
}

int Menu::addElem(string textToDisplay)
{
	this->elements.push_back(textToDisplay);
	return 0;
}

int Menu::removeElem(int elemToDel)
{
	this->elements.erase(elements.begin()+elemToDel);
	return 0;
}

int Menu::show() 
{
	cout << setw(this->windowSize) << this->name << endl;
	for (int i = 0; i < elements.size(); i++) {
		if (i == cursorPosition)
			cout << "    ->  ";
		else
			cout << "\t";

		cout << i << ") " << elements[i] << endl;
	}

	return 0;
}