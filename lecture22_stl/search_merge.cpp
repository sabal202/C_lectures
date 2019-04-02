#include <iostream>
#include <algorithm>

using namespace std;


int source[] = { 1, 4, 3, 1, 2, 3, 1, 2, 4, 5, 1, 2, 3, 4, 5 };
int pattern[] = { 2, 3 };

int arr1[] = { 1, 3, 5, 7, 8, 9, 12 };
int arr2[] = { 2, 3, 6, 7, 8, 10 };
int arr3[13];

int main() {
	// Алгоритм search()

	int* ptr;
	ptr = search(source, source + 15, pattern, pattern + 2);

	if (ptr == source + 15)
		cout << "Not found" << endl;
	else
		cout << "Found " << (ptr - source) << endl;

	// Алгоритм merge()

	merge(arr1, arr1 + 7, arr2, arr2 + 6, arr3);

	for (int i = 0; i < 13; i++)     // вывести arr3
		cout << arr3[i] << ' ';

	cout << endl;


	return 0;
}
