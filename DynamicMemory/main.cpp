#include"stdafx.h"
#include"Clear.h"
#include"Clear.cpp"
#include"Print.h"
#include"Print.cpp"
#include"Push.h"
#include"Push.cpp"
#include"Pop.h"
#include"Pop.cpp"
#include"FillRand.h"
int** Allocate(const int rows, const int cols);
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	typedef int DataType;
	DataType* arr = new DataType[n];

	FillRand(arr, n);
	Print(arr, n);

	DataType value;//значение элемента
	int index;//индекс вставляемого значения
	cout << "Введите добавляемое значение в конец массива: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	cout << "Введите добавляемое значение в начало массива: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);
	cout << "Убираем значение в конце массива: " << endl;
	arr = pop_back(arr, n);
	Print(arr, n);
	cout << "Убираем значение в начале массива: " << endl;
	arr = pop_front(arr, n);
	Print(arr, n);
	cout << endl;
	cout << "Введите вставляемое значение в массив: "; cin >> value;
	cout << endl;
	cout << "Введите индекс вставляемого элемента: "; cin >> index;
	arr = insert(arr, n, value, index);
	Print(arr, n);
	cout << endl;
	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);

	delete[] arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	int rows;
	int cols;
	int index;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	
	int** arr = Allocate(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	arr = push_row_front(arr, rows, cols);
	FillRand(arr[0], cols);
	Print(arr, rows, cols);

	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);

	cout << "Введите индекс вставляемой строки: "; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	FillRand(arr[index], cols);
	Print(arr, rows, cols);

	cout << "Введите индекс удаляемой строки: "; cin >> index;
	arr = erase_row(arr, rows, index);
	Print(arr, rows, cols);

	arr = pop_row_back(arr, rows);
	Print(arr, rows, cols);
	
	arr = pop_row_front(arr, rows);
	Print(arr, rows, cols);

	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	
	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите индекс вставляемого столбца: "; cin >> index;
	insert_col(arr, rows, cols, index);
	Print(arr, rows, cols);

	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите индекс удаляемого столбца: "; cin >> index;
	erase_col(arr, rows, cols, index);
	Print(arr, rows, cols);

	Clear(arr, rows);
#endif // DYNAMIC_MEMORY_2
}
//Stack - это модель памяти, из которой последний записанный элемент считывается первым.
//push - вставить //pop - вытащить

int** Allocate(const int rows, const int cols)
{
	//1) Создаём массив указателей :
	int** arr = new int* [rows];

	//2) Выделяем память под строки:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}

