#include "PopMusic.h"

PopMusic::PopMusic()
{
	count++;
}


PopMusic::~PopMusic()
{
	count--;
}

void PopMusic::display()
{
	cout << "ROK: " << this->data.year
		<< ", WYKONAWCA: "; this->data.performer.display(); cout
		<< ", TYTUL: " << this->data.title;

	cout << endl;
}