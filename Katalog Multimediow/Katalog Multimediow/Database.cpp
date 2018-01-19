#include "Database.h"

Database::Database()
{

}

Database::~Database()
{

}

vector<string> split(string strToSplit, char delimeter)
{
	vector<string> attributes;
	string attribute;
	istringstream attributeStream(strToSplit);
	while (getline(attributeStream, attribute, delimeter))
		attributes.push_back(attribute);

	return attributes;
}

RecordType Database::getRecordType(string type)
{
	RecordType typeEnum;
	if (type == RECORDTYPE_MOVIE)
		typeEnum = MOVIE;
	else if (type == RECORDTYPE_CLASSICMUSIC)
		typeEnum = CLASSICMUSIC;
	else if (type == RECORDTYPE_POPMUSIC)
		typeEnum = POPMUSIC;
	else if (type == RECORDTYPE_GAME)
		typeEnum = GAME;
	else
		typeEnum = UNIDENTIFIED;

	return typeEnum;
}

int Database::addRecord(string record)
{
	vector<string> attributes = split(record, ATTRIBUTE_DELIMETER);
	RecordType recordType = getRecordType(attributes[0]);
	switch (recordType) 
	{
	case MOVIE:
		this->addMovie(attributes);
		break;
	case CLASSICMUSIC:
		this->addClassicMusic(attributes);
		break;
	case POPMUSIC:
		this->addPopMusic(attributes);
		break;
	case GAME:
		this->addGame(attributes);
		break;
	case UNIDENTIFIED:
		return UNIDENTIFIED_RECORD_TYPE_ERROR;
		break;
	default:
		return UNIDENTIFIED_RECORD_TYPE_ERROR;
		break;
	}
}

vector<Person> Database::createPersons(string stringToExtractPersons) 
{
	vector<string> personsNames = split(stringToExtractPersons, PERSON_DELIMETER);
	vector<string> firstAndLastName;
	vector<Person> persons;
	for (int i = 0; i < (int)personsNames.size(); i++) 
	{
		Person person;
		firstAndLastName = split(personsNames[i], NAME_DELIMETER);
		person.firstName = firstAndLastName[0];
		person.lastName = firstAndLastName[1];
		persons.push_back(person);
	}
	return persons;
}

void Database::addMovie(vector<string> attributes)
{
	MovieData data;
	data.year = stoi(attributes[1]);
	vector<Person> director = createPersons(attributes[2]);
	data.director = director[0];
	data.title = attributes[3];
	data.actors = createPersons(attributes[4]);

	Movie movie;
	movie.data = data;
	movies.push_back(movie);
}

void Database::addClassicMusic(vector<string> attributes)
{
	ClassicMusicData data;

	data.year = stoi(attributes[1]);
	vector<Person> composer = createPersons(attributes[2]);
	data.composer = composer[0];
	vector<Person> performer = createPersons(attributes[3]);
	data.performer = performer[0];
	data.title = attributes[4];
	if (attributes.size() > 5)
		data.catalogNumber = stoi(attributes[5]);

	if (attributes.size() > 6) 
	{
		vector<Person> soloists = createPersons(attributes[6]);
		data.soloists = soloists;
	}

	ClassicMusic classicMusic;
	classicMusic.data = data;
	classicTracks.push_back(classicMusic);
}

void Database::addPopMusic(vector<string> attributes)
{
	PopMusicData data;

	data.year = stoi(attributes[1]);
	vector<Person> performer = createPersons(attributes[2]);
	data.performer = performer[0];
	data.title = attributes[3];

	PopMusic popMusic;
	popMusic.data = data;
	popTracks.push_back(popMusic);
}

void Database::addGame(vector<string> attributes)
{
	GameData data;

	data.year = stoi(attributes[1]);
	data.director = attributes[2];
	data.title = attributes[3];

	if (attributes.size() > 4)
		data.addons = split(attributes[4], ADDON_DELIMETER);

	Game game;
	game.data = data;
	games.push_back(game);
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
	int linesCount = lines.size(); // to avoid calculating vector size  in each iteration
	if (linesCount == 0)
		return FILE_READ_ERROR;

	int recordCount = Record::getCount();
	int movieCount = Movie::getCount();
	int classicCount = ClassicMusic::getCount();
	int popCount = PopMusic::getCount();
	int gameCount = Game::getCount();

	for (int i = 0; i < linesCount; i++)
		this->addRecord(lines[i]);

	cout << "Plik " << path << " zostal pomyslnie wczytany." << endl;
	cout << "Ogolem dodano " << Record::getCount() - recordCount << " rekordow:" << endl;
	cout << "\tDodano " << Movie::getCount() - movieCount << " rekordow typu film." << endl;
	cout << "\tDodano " << ClassicMusic::getCount() - classicCount << " rekordow typu muzyka klasyczna." << endl;
	cout << "\tDodano " << PopMusic::getCount() - popCount << " rekordow typu muzyka popularna." << endl;
	cout << "\tDodano " << Game::getCount() - gameCount << " rekordow typu gra." << endl;
	cout << endl << "Ogolem rekordow w bazie: " << Record::getCount() << "." << endl;
	cout << "\tW bazie jest " << Movie::getCount() << " rekordow typu film." << endl;
	cout << "\tW bazie jest " << ClassicMusic::getCount() << " rekordow typu muzyka klasyczna." << endl;
	cout << "\tW bazie jest " << PopMusic::getCount() << " rekordow typu muzyka popularna." << endl;
	cout << "\tW bazie jest " << Game::getCount() << " rekordow typu gra." << endl;
	Sleep(3000);
	return 0;
}

bool isInYearRange(int yearToCheck, string yearRange) 
{
	vector<string> range = split(yearRange, YEAR_DELIMETER);
	int rangeMin = stoi(range[0]);
	int rangeMax = stoi(range[1]);

	if ((yearToCheck <= rangeMax) && (yearToCheck >= rangeMin))
		return true;
	else
		return false;
}

vector<Record*> Database::searchMovies(int attrType, string attrValue)
{
	vector<Record*> result;
	switch (attrType) 
	{
	case ATTRTYPE_PERFORMER:
		return result;
		break;
	case ATTRTYPE_DIRECTOR:
	{
		vector<Person> director = createPersons(attrValue);
		for (int i = 0; i < (int)movies.size(); i++)
		{
			if (movies[i].data.director == director[0])
				result.push_back(&movies[i]);
		}
		return result;
		break;
	}
	case ATTRTYPE_TITLE:
	{
		string title;
		title = attrValue;
		for (int i = 0; i < (int)movies.size(); i++)
		{
			if (movies[i].data.title == title)
				result.push_back(&movies[i]);
		}
		return result;
		break;
	}
	case ATTRTYPE_YEARRANGE:
		for (int i = 0; i < (int)movies.size(); i++)
		{
			if (isInYearRange(movies[i].data.year, attrValue))
				result.push_back(&movies[i]);
		}
		return result;
		break;
	default:
		return result;
	}
}

vector<Record*> Database::searchClassicMusic(int attrType, string attrValue)
{
	vector<Record*> result;
	switch (attrType)
	{
	case ATTRTYPE_PERFORMER:
	{
		vector<Person> performer = createPersons(attrValue);
		for (int i = 0; i < (int)classicTracks.size(); i++)
		{
			if (classicTracks[i].data.performer == performer[0])
				result.push_back(&classicTracks[i]);
		}
		return result;
		break;
	}
	case ATTRTYPE_DIRECTOR:
		return result;
		break;
	case ATTRTYPE_TITLE:
	{
		string title = attrValue;
		for (int i = 0; i < (int)classicTracks.size(); i++)
		{
			if (classicTracks[i].data.title == title)
				result.push_back(&classicTracks[i]);
		}
		return result;
		break;
	}
	case ATTRTYPE_YEARRANGE:
		for (int i = 0; i < (int)classicTracks.size(); i++)
		{
			if (isInYearRange(classicTracks[i].data.year, attrValue))
				result.push_back(&classicTracks[i]);
		}
		return result;
		break;
	default:
		return result;
	}
}

vector<Record*> Database::searchPopMusic(int attrType, string attrValue)
{
	vector<Record*> result;
	switch (attrType)
	{
	case ATTRTYPE_PERFORMER:
	{
		vector<Person> performer = createPersons(attrValue);
		for (int i = 0; i < (int)popTracks.size(); i++)
		{
			if (popTracks[i].data.performer == performer[0])
				result.push_back(&popTracks[i]);
		}
		return result;
		break;
	}
	case ATTRTYPE_DIRECTOR:
		return result;
		break;
	case ATTRTYPE_TITLE:
	{
		string title = attrValue;
		for (int i = 0; i < (int)popTracks.size(); i++)
		{
			if (popTracks[i].data.title == title)
				result.push_back(&popTracks[i]);
		}
		return result;
		break;
	}
	case ATTRTYPE_YEARRANGE:
		for (int i = 0; i < (int)popTracks.size(); i++)
		{
			if (isInYearRange(popTracks[i].data.year, attrValue))
				result.push_back(&popTracks[i]);
		}
		return result;
		break;
	default:
		return result;
	}
}

vector<Record*> Database::searchGames(int attrType, string attrValue)
{
	vector<Record*> result;
	switch (attrType)
	{
	case ATTRTYPE_PERFORMER:
		return result;
		break;
	case ATTRTYPE_DIRECTOR:
	{
		string director = attrValue;
		for (int i = 0; i < (int)games.size(); i++)
		{
			if (games[i].data.director == director)
				result.push_back(&games[i]);
		}
		return result;
		break;
	}
	case ATTRTYPE_TITLE:
	{
		string title = attrValue;
		for (int i = 0; i < (int)games.size(); i++)
		{
			if (games[i].data.title == title)
				result.push_back(&games[i]);
		}
		return result;
		break;
	}
	case ATTRTYPE_YEARRANGE:
		for (int i = 0; i < (int)games.size(); i++)
		{
			if (isInYearRange(games[i].data.year, attrValue))
				result.push_back(&games[i]);
		}
		return result;
		break;
	default:
		return result;
	}
}

vector<Record*> Database::searchRecords(RecordType type, int attrType, string attrValue) 
{
	vector<Record*> result;
	switch (type)
	{
	case MOVIE:
		result = searchMovies(attrType, attrValue);
		break;
	case CLASSICMUSIC:
		result = searchClassicMusic(attrType, attrValue);
		break;
	case POPMUSIC:
		result = searchPopMusic(attrType, attrValue);
		break;
	case GAME:
		result = searchGames(attrType, attrValue);
		break;
	case ALL:
	{
		vector<Record*> tempResult;
		result = searchMovies(attrType, attrValue);
		tempResult = searchClassicMusic(attrType, attrValue);
		result.insert(result.end(), tempResult.begin(), tempResult.end());

		tempResult = searchPopMusic(attrType, attrValue);
		result.insert(result.end(), tempResult.begin(), tempResult.end());

		tempResult = searchGames(attrType, attrValue);
		result.insert(result.end(), tempResult.begin(), tempResult.end());
		break;
	}
	}
	return result;
}

int Database::displayRecords(RecordType type, int typeOfAttr, string attrValue) 
{
	vector<Record*> records = searchRecords(type, typeOfAttr, attrValue);

	system("cls");
	for (int i = 0; i < records.size(); i++)
		records[i]->display();

	Sleep(2000);
	return 0;
}