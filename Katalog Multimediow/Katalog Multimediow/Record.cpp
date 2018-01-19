#include "Record.h"

Record::Record()
{
	this->id = count;
	count++;
}

Record::~Record()
{
	count--;
}