#include "Movie.h"

Movie::Movie()
{
	count++;
}

Movie::~Movie()
{
	count--;
}

void Movie::display() 
{
	cout << "ROK: " << this->data.year
		<< ", REZYSER: "; this->data.director.display(); cout
		<< ", TYTUL: " << this->data.title
		<< ", AKTORZY: ";
	
	for (int i = 0; i < this->data.actors.size(); i++)
	{
		this->data.actors[i].display();
		cout << ", ";
	}

	cout << endl;
}
