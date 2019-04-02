#include <iostream>
#include <algorithm> 

using namespace std;

// Алгоритм find()

int arr[10] = { 5, 4, 7 , 8, 11, 3, 2, 1, 15, 7 };
int main()
{
	setlocale(LC_ALL, "Russian");
	int* ptr;
	ptr = find(arr, arr + 10, 7);
	cout << "Число 7 стоит на " << (ptr - arr);
	cout << " месте массива." << endl;

	// Алгоритм count()

	int n = count(arr, arr + 10, 7);
	cout << "Число 7 встречается " << n;
	cout << " раз(а)." << endl;

	// Алгоритм sort()

	sort(arr, arr + 10);
	for (int i = 0; i < 10; i++)
		cout << arr[i] << ' ';
	cout << endl;

	return 0;
}
