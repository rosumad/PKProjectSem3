#include "Menu.h"

Menu::Menu() 
{
	this->windowSize = 60;
	this->name = "";
	this->cursorPosition = 0;
	this->choice = -1;
	this->menuPage = 0;
}

Menu::Menu(int windowSize)
{
	this->windowSize = windowSize;
	this->name = "";
	this->cursorPosition = 0;
	this->choice = -1;
	this->menuPage = 0;
}

Menu::Menu(int windowSize, string name)
{
	this->windowSize = windowSize;
	this->name = name;
	this->cursorPosition = 0;
	this->choice = -1;
	this->menuPage = 0;
}

Menu::Menu(int windowSize, string name, vector<string> elements)
{
	this->windowSize = windowSize;
	this->name = name;
	this->elements = elements;
	this->cursorPosition = 0;
	this->choice = -1;
	this->menuPage = 0;
}

Menu::~Menu() 
{
}

void Menu::addElem(string textToDisplay)
{
	this->elements.push_back(textToDisplay);
}

void Menu::removeElem(int elemToDel)
{
	this->elements.erase(elements.begin()+elemToDel);
}

void Menu::show() 
{
	system("cls");
	cout << setw(this->windowSize) << this->name << endl;
	if ((int)this->elements.size() <= elemsPerPage)
	{
		for (int i = 0; i < (int)this->elements.size(); i++)
		{
			if (i == this->cursorPosition)
				cout << CURSOR;
			else
				cout << "\t";

			cout << i << ") " << this->elements[i] << endl;
		}
	}
	else
	{ 
		if ((menuPage * elemsPerPage) < (int)this->elements.size())
		{
			for (int i = 0; i < elemsPerPage; i++) 
			{
				if ((i + menuPage*elemsPerPage) == this->cursorPosition)
					cout << CURSOR;
				else
					cout << "\t";

				cout << i << ") " << this->elements[i+menuPage*elemsPerPage] << endl;  //  tu
			}
			cout << endl << "Uzyj strzalek w lewo oraz w prawo aby przejsc pomiedzy stronami menu." << endl;
		}
	}
	cout << "Nacisnij ESC zeby wyjsc...";
}

int Menu::use() 
{
	int pressedKey;
	this->choice = -1;
	do
	{
		this->show();
		pressedKey = _getch();
		this->handlePressedKey(pressedKey);
	} while ((!this->choiceMade()) && (pressedKey != KEY_ESC));

	return this->choice;
}

void Menu::moveCursor()
{
	int pressedKey = _getch();
	switch(pressedKey)
	{ 
		case KEY_ARROWUP:
			this->moveCursorUp();
			break;

		case KEY_ARROWDOWN:
			this->moveCursorDown();
			break;

		default:
			break;
	}
}

void Menu::moveCursorUp()
{
	if (this->cursorPosition == 0)
		this->cursorPosition = (int)this->elements.size() - 1;
	else
		this->cursorPosition--;
}

void Menu::moveCursorDown()
{
	if (this->cursorPosition == (int)this->elements.size() - 1)
		this->cursorPosition = 0;
	else
		this->cursorPosition++;
}

void Menu::handlePressedKey(int pressedKey)
{
	if (pressedKey == KEY_ARROWSPECIAL)
		this->moveCursor();
	else if (pressedKey == KEY_ENTER)
		this->choice = this->cursorPosition;
	else 
	{
		for (int i = 0; i < (int)this->elements.size(); i++)
		{
			if (pressedKey == KEY_0 + i)
				this->choice = i;
		}
	}
}

bool Menu::choiceMade() 
{
	if (this->choice == -1) 
		return false;
	else 
		return true;
}