#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
using namespace std;

class person {
public:
	string name, id;
	person(string name, string id) : name(name), id(id) {}
};

ostream & operator<< (ostream &os, const person &p) {
	os << "person " << p.id << ": " << p.name << endl;
	return os;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector<person> db;
	int command = 0;

	while (1) {
		cout << "Choose:\n1. Add person\n2. Find by id\n3. Find by name\n4. Exit\n";
		cin >> command;

		switch (command) {
			case 1:
			{
				cout << "Enter name and id: " << endl;
				string name, id;
				cin >> name >> id;
				person p(name, id);
				db.push_back(p);
				break;
			}
			case 2:
			{
				cout << "Enter id: " << endl;
				string id;
				cin >> id;

				for (int i = 0; i < db.size(); i++) {
					if (id.compare(db[i].id) == 0) {
						cout << db[i];
						break;
					}
				}
				break;
			}
			case 3:
			{
				cout << "Enter name: " << endl;
				string name;
				cin >> name;

				for (int i = 0; i < db.size(); i++) {
					if (name.compare(db[i].name) == 0) {
						cout << db[i];
						break;
					}
				}
				break;
			}
			case 4:
				exit(1);
		}
	}

	return 0;
}