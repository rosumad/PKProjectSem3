#include "Record.h"
#include "Menu.h"

int Record::recordCount = 0;

int main() {
	vector<string> elements;
	string a;
	for (int i = 0; i < 15; i++) {
		a = "test " + to_string(i);
		elements.push_back(a);
	}
	Menu menu(60, "Katalog Multimediow", elements);
	int choice = menu.use();
	int x; cin >> x;
	return 1;
}