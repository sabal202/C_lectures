#include <iostream>
#include <algorithm>                  
#include <windows.h>           
using namespace std;


bool isDon(char const * name)		// возвращает true, если
// name=="Иванов"
{
	return name == "Иванов";
}


char const * names[] = { "Петров", "Сидоров", "Елисеев", "Иванов", "Степанов", "Владимиров", "Иванов", "Кузнецов", "Иванов", "Петров", "Степанов", "Иванов", "Машин", "Андреев" };

int main() {
	setlocale(LC_ALL, "Russian");
	int n = count_if(names, names + 14, isDon);

	cout << "Всего в списке Ивановых " << n << endl;

	return 0;
}

