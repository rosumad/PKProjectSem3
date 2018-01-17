#include "Database.h"

Database::Database()
{

}

Database::~Database()
{

}

void Database::addRecord(string record)
{
	
}

vector<string> Database::readFile(string path)
{
	ifstream fileToImport;
	vector<string> lines;
	fileToImport.open(path);
	if (fileToImport.is_open())
	{
		string buffer;
		while (getline(fileToImport, buffer))
			lines.push_back(buffer);

		fileToImport.close();
		return lines;
	}
	else
		return lines;  // vector must be empty in this situation.

}

int Database::importFromFile(string path) 
{
	vector<string> lines = readFile(path);
	if (lines.size() == 0)
		return FILE_READ_ERROR;


}