
#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int> > & iArr, int, int);

int main()
{
	setlocale(LC_ALL, "RUS");
	// Создание двумерного массива
	int n, m;
	// Ввод размерности двумерного массива (n,m)
	cout << "Введите количество строк и столбцов матрицы: ";
	cin >> n >> m;

	// Создание прямоугольной матрицы
	vector<vector<int> > iArr(n, vector<int>(m));

	// Заполнение и вывод двумерного массива
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			iArr[i][j] = 2 * (i + j);

	print(iArr, n, m);

	system("pause");
	return 0;
}

void print(vector<vector<int> > & iArr, int n, int m)
{
	// Печать двумерного массива
	cout << endl << "Вывод двумерного массива iArr" << endl;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << iArr[i][j] << " ";

		cout << endl;
	}

}
