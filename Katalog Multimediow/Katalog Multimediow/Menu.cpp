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
	if (this->fitOnOnePage())
		this->showOnePage();
	else
		this->showMultiplePages();

	cout << endl << "Nacisnij ESC zeby wyjsc...";
}

bool Menu::fitOnOnePage()
{
	if ((int)this->elements.size() <= elemsPerPage)
		return true;
	else
		return false;
}

void Menu::showOnePage()
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

void Menu::showMultiplePages()
{
	if (this->pageIsFull())
	{
		for (int i = 0; i < elemsPerPage; i++)
		{
			if ((i + menuPage * elemsPerPage) == this->cursorPosition)
				cout << CURSOR;
			else
				cout << "\t";

			cout << i + menuPage * elemsPerPage << ") " << this->elements[i + menuPage * elemsPerPage] << endl;
		}
		cout << endl << "Uzyj strzalek w lewo oraz w prawo aby przejsc pomiedzy stronami menu." << endl;
	}
	else
	{
		int elemsOnLastPage = (int)this->elements.size() - menuPage * elemsPerPage;
		for (int i = 0; i < elemsOnLastPage; i++)
		{
			if ((i + menuPage * elemsPerPage) == this->cursorPosition)
				cout << CURSOR;
			else
				cout << "\t";

			cout << i + menuPage * elemsPerPage << ") " << this->elements[i + menuPage * elemsPerPage] << endl;
		}
		cout << endl << "Uzyj strzalek w lewo oraz w prawo aby przejsc pomiedzy stronami menu." << endl;
	}
}

bool Menu::pageIsFull() 
{
	if (((int)this->elements.size() - menuPage * elemsPerPage) >= elemsPerPage)
		return true;
	else
		return false;
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

		case KEY_ARROWLEFT:
			this->movePageLeft();
			break;

		case KEY_ARROWRIGHT:
			this->movePageRight();
			break;

		default:
			break;
	}
}

void Menu::movePageLeft() 
{
	if (this->menuPage == 0)
		this->menuPage = (int)((int)this->elements.size() / elemsPerPage);
	else
		this->menuPage--;

	this->cursorPosition = this->menuPage * elemsPerPage;
}

void Menu::movePageRight()
{
	if (this->menuPage == ((int)((int)this->elements.size() / elemsPerPage)))
		this->menuPage = 0;
	else
		this->menuPage++;

	this->cursorPosition = this->menuPage * elemsPerPage;
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
			if (pressedKey == KEY_0 + (i%elemsPerPage))
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