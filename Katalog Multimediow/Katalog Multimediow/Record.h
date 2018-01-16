//=================================
// include guard
#pragma once

//=================================
// forward declared dependencies

//=================================
// included dependencies

//=================================
// class code
class Record
{
private:
	static int count;

public:
	Record();
	~Record();

	static int getCount();
};