#include "Record.h"

Record::Record()
{
	count++;
}


Record::~Record()
{
	count--;
}int Record::getCount(){	return count;}