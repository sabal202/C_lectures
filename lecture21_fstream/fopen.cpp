#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream fout("file"); // создание файла для вывода

	if (!fout) {
		cout << "Файл открыть невозможно\n";
		return 1;
	}

	fout << "Write!!!\n";
	fout << 100 << ' ' << hex << 100 << endl;

	fout.close();

	ifstream fin("file"); // открытие файла для ввода

	if (!fin) {
		cout << "Файл открыть невозможно\n";
		return 1;
	}

	char str[80];
	int i, j;

	fin >> str >> i >> j;
	cout << str << ' ' << i << ' ' << j << endl;

	fin.close();

	return 0;
}
