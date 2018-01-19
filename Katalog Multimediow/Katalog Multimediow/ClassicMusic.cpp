#include "ClassicMusic.h"

ClassicMusic::ClassicMusic()
{
	count++;
}

ClassicMusic::~ClassicMusic()
{
	count--;
}


void ClassicMusic::display()
{
	cout << "ROK: " << this->data.year
		<< ", KOMPOZYTOR: "; this->data.composer.display(); cout
		<< ", WYKONAWCA: "; this->data.performer.display(); cout
		<< ", TYTUL: " << this->data.title
		<< ", NUMER KATALOGOWY: " << this->data.catalogNumber
		<< ", SOLISCI: ";

	for (int i = 0; i < this->data.soloists.size(); i++)
	{
		this->data.soloists[i].display();
		cout << ", ";
	}
	cout << endl;
}
