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

protected:
	int id;

public:
	Record();
	Record(const Record&) { count++; };
	~Record();

	static int getCount() { return count; };
};