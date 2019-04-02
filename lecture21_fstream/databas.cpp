#include <iostream>
#include <windows.h>
using namespace std;

char bufRus[256];
char* Rus(const char *text)
{
	CharToOem(text, bufRus);
	return bufRus;
}

char bufEng[256];
char* Eng(const char *text)
{
	OemToChar(text, bufEng);
	return bufEng;
}

class student {
	char fio[40];
	char group[5];
	char n_st[10];
public:
	student() {};
	student(char const *n, char const *g, char const *b)
	{
		strcpy_s(fio, n); strcpy_s(group, g); strcpy_s(n_st, b);
	}
	friend ostream& operator << (ostream &stream, student &ob);
	friend istream&  operator >> (istream  &stream, student &ob);
};

ostream &operator << (ostream &stream, student &ob)
{
	stream << Rus(ob.fio) << " " << ob.group << " " << ob.n_st << endl;
	return stream;
}

istream &operator >> (istream &stream, student &ob)
{
	cout << Rus("\nВведите фамилию, имя, студента: ");
	stream.getline(ob.fio, 40);
	strcpy_s(ob.fio, Eng(ob.fio));
	cout << Rus("\nВведите номер группы студента: ");
	stream >> ob.group;
	cout << Rus("\nВведите номер идентификатора студента: ");
	stream >> ob.n_st;
	cout << endl;

	return stream;
}

int main()
{
	// setlocale(LC_ALL, "Russian");
// SetConsoleCP(1251); 
	// SetConsoleOutputCP(1251);
	student ob1("Иванов Иван Иванович", "115", "050100");
	student ob2("Петров Петр Петрович", "116", "050115");
	student ob3("Сидоров Сидор Сидорович", "118", "050125");
	student ob4;

	cout << ob1 << ob2 << ob3;

	cin >> ob4;
	cout << ob4;

	return 0;
}
