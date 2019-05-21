#include <iostream>
#include <vector>
#include<string>
using namespace std;


int main() {
	setlocale(LC_ALL, "RUS");
	// Создание пустого вектора
	vector<int> v;
	cout << "Пустой вектор: " << v.size();
	// Создание вектора заданного размера с инициализацией "по умолчанию"
	vector<int> v1(10);
	cout << endl <<
	     "Вектор с инициализацией \"по умолчанию\": ";

	for (int i = 0; i < 10; i++)
		cout << v1[i] << " ";

	// Создание вектора заданного размера с инициализацией :
	vector<int> v2(10, 7);
	vector<string> sArr(3, "Hello World!!!");
	cout << endl << "Вектор с инициализацией: ";

	for (int i = 0; i < 10; i++)
		cout << v2[i] << " ";

	cout << endl << "Вектор с инициализацией: ";

	for (int i = 0; i < 3; i++)
		cout << sArr[i] << " ";

	// Создание вектора и инициализация его массивом :
	int iArr[7] = { 1, 2, 3, 4, 5, 6, 7 };
	vector <int> v3(iArr, iArr + 7);
	cout << endl <<
	     "Вектор с инициализацией массивом: ";

	for (int i = 0; i < 7; i++)
		cout << v3[i] << " ";

	//	Создание вектора и инициализация его другим вектором :
	vector<int> v4(10, 5);
	vector<int> v5(v4);
	cout << endl <<
	     "Вектор с инициализацией другим вектором: ";

	for (int i = 0; i < 10; i++)
		cout << v5[i] << " ";

	cout << endl;

	return 0;
}

