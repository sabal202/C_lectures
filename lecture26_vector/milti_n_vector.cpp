#include <iostream>
#include <vector>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	// Создание двумерного массива
	int n, m;
	// Ввод размерности двумерного массива (n,m)
	cout << "Введите количество строк и столбцов матрицы: ";
	cin >> n >> m;
	// Создание нулевого двумерного массива целых чисел
	vector<vector<int> > iArr;
	// Создание массива (вектор)
	iArr.resize(n);

	// Создание массива (двумерный)
	for (int i = 0; i < n; i++)
		iArr[i].resize(m);

	// Заполнение и вывод двумерного массива
	cout << "Вывод двумерного массива iArr" << endl;

	for (int i = 0; i < n; ++i)	{
		for (int j = 0; j < m; ++j)
		{
			iArr[i][j] = i + j;
			cout << iArr[i][j] << " ";
		}

		cout << endl;
	}

	// Создание прямоугольной матрицы
	vector<vector<int> > iArr1(n, vector<int>(m));
	// Заполнение и вывод двумерного массива
	cout << endl << "Вывод двумерного массива iArr1" << endl;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
		{
			iArr1[i][j] = 2 * (i + j);
			cout << iArr1[i][j] << " ";
		}

		cout << endl;
	}

	// Создание двумерного непрямоугольного массива
	vector<vector<int> > iArr2;
	iArr2.resize(n);

	for (int i = 0; i < n; ++i)
		iArr2[i].resize(i + 1);

	// Заполнение и вывод двумерного массива
	cout << endl << "Вывод двумерного массива iArr2" << endl;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i + 1; ++j)
		{
			iArr2[i][j] = 2 * (i + j);
			cout << iArr2[i][j] << " ";
		}

		cout << endl;
	}

	cout << endl << "Размерность массива iArr2= " << iArr2.size()
	     << endl;
	int k;
	cout << "Введите 3-ю размерность: ";
	cin >> k;
	// Создание трехмерного массива
	vector<vector<vector<int> > > iArr3(n, vector<vector<int> >(m, vector<int>(k)));
	cout << endl << "Размерность массива iArr3= " << iArr2.size()
	     << endl;
	return 0;
}

