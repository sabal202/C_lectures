#include <iostream>
#include <algorithm>
#include <cstring>
#include <functional>

using namespace std;


int dat[8] = { 5, 8, -3, 4, 0, -1, 7, 4 };

char const * names[] = { "Sergey", "Tatiana", "Helen", "Dima", "Mikhail", "Vladimir" };

bool s_comp(char const*, char const*);

int main() {
	// Обратная сортировка чисел  (функциональный объект greater<>())

	sort(dat, dat + 8, greater<int>());

	for (int i = 0; i < 8; i++)
		cout << dat[i] << ' ';

	cout << endl;

	// Сортировка строк (пользовательская функция)

	sort(names, names + 6, s_comp);
	//	sort(names, names + 6); 	// сортировка строк

	for (int j = 0; j < 6; j++)
		cout << names[j] << endl;

	return 0;
}

bool s_comp(char const* s1, char const * s2) { //если s1<s2
	return (strcmp(s1, s2) < 0) ? true : false;
}
