#include "Game.h"

Game::Game()
{
	count++;
}

Game::~Game()
{
	count--;
}

void Game::display()
{
	cout << "ROK: " << this->data.year
		<< ", PRODUCENT: " << this->data.director
		<< ", TYTUL: " << this->data.title
		<< ", DODATKI: ";

	for (int i = 0; i < (int)this->data.addons.size(); i++)
		cout << this->data.addons[i] << ", ";

	cout << endl;
}