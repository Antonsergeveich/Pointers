#include<iostream>
using namespace std;

using std::cout;
using std::cin;
using std::endl;

#define tab "\t"

#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_2

int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);

template<typename T> 
void FillRand(T arr[], const int n, T minRand = 0, T maxRand = 100);

template<typename T>
void FillRand(T** arr, const int rows, const int cols);

template<typename T>
void Print(T arr[], const int n);

template<typename T>
void Print(T** arr, const int rows, const int cols);

template<typename T>
T* push_back(T arr[], int &n, T value);

template<typename T>
T* push_front(T arr[], int &n, T value);

template<typename T>
T* pop_back(T arr[], int& n);

template<typename T>
T* pop_front(T arr[], int& n);

template<typename T>
T* insert(T arr[], int &n, T value, int &index);

template<typename T>
T* erase(T arr[], int &n, int &index);

template<typename T>
T** push_row_front(T** arr, int &rows, const int cols);

template<typename T>
T** push_row_back(T** arr, int &rows, const int cols);

template<typename T>
T** pop_row_back(T** arr, int& rows);

template<typename T>
T** pop_row_front(T** arr, int& rows);

template<typename T>
T** erase_row(T** arr, int& rows, int& index);

template<typename T>
T** insert_row(T** arr, int& rows, const int cols, int& index); 

template<typename T>
void push_col_back(T** arr, const int rows, int& cols);

template<typename T>
void push_col_front(T** arr, const int rows, int& cols);

template<typename T>
void insert_col(T** arr, const int rows, int& cols, const int index);

template<typename T>
void pop_col_back(T** arr, const int rows, int& cols);

template<typename T>
void pop_col_front(T** arr, const int rows, int& cols);

template<typename T>
void erase_col(T** arr, const int rows, int& cols, const int index);

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;//значение элемента
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

template<typename T>
void FillRand(T arr[], const int n, T minRand, T maxRand)
{
	     for (int i = 0; i < n; i++)
	     {
		//Обращение к элементам массива через арифметику указателей
		//и оператор разъименования
			 *(arr + i) = rand() % (maxRand - minRand) + minRand;
	     }
}

template<typename T>
void FillRand(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

template<typename T>
void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//обращение к элементам массива через 
		//оператор индексирования - []
		cout << arr[i] << tab;
	}
	cout << endl;
}

template<typename T>
void Print(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
}

template<typename T>
T* push_back(T arr[], int &n, T value)
{
	int* buffer = new int[n + 1]; //1)Создаём буферный массив нужного размера:
	for (int i = 0; i < n; i++) //2)Копируем значения из исходного массива в буферный:
	{
		buffer[i] = arr[i];
	}
	delete[] arr; //3) Удаляем исходный массив:
	//4) Подменяем адрес исходного массива адресом нового массива:
	arr = buffer;
	//5)Только после этого в конце массива появляется свободное место,
	// куда можно добавить значение:
	arr[n] = value; 
	n++;// увеличиваем переменную 'n' на '1' больше, чтобы вывести новый массив 
	return arr;
}

template<typename T>
T* push_front(T arr[], int& n, T value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}

template<typename T>
T* pop_back(T arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

template<typename T>
T* pop_front(T arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i+1];
	delete[] arr;
	return buffer;
}

template<typename T>
T* insert(T arr[], int &n, T value, int &index)
{
	int* buffer = new int[n + 1]; 
	for (int i = n; i >= index; i--)
	{
		buffer[i+1] = arr[i];
	}
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr; 
	arr = buffer;
	arr[index] = value;
	n++; 
	return arr;
}

template<typename T>
T* erase(T arr[], int& n, int &index)
{
	int* buffer = new int[--n];
	for (int i = n; i > index; --i)
	{
	    buffer[i - 1] = arr[i];
	}
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
    delete[] arr;
	arr = buffer;
	return arr;
}

template<typename T>
T** push_row_front(T** arr, int &rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	
	for (int i = 0; i < rows; i++)buffer[i+1] = arr[i];
	
	delete arr;

	buffer[0] = new int[cols] {};

	rows++;
	
	return buffer;
}

template<typename T>
T** push_row_back(T** arr, int &rows, const int cols)
{
	//1)Создаём буферный массив указателей нужного размера:
	int** buffer = new int* [rows + 1];

	//2)Копируем строки из исходного массива в массив указателей:
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];

	//3)Удаляем исходный массив указателей:
	delete[] arr;

	//4)Создаём строку и добавляем её в массив:
	buffer[rows] = new int[cols] {};

	//5)После добавления строки в массив, количество его строк увеличивается:
	rows++;

	return buffer;
}

template<typename T>
T** pop_row_back(T** arr, int& rows)
{
	// переопределяем массив указателей
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];
	delete[] arr[rows]; //удаляем удаляемую строку из памяти
	delete[] arr;
	return buffer;
}

template<typename T>
T** pop_row_front(T** arr, int& rows)
{
	int** buffer = new int* [--rows] ;
	for (int i = 0; i < rows; i++) buffer[i] = arr[i+1];
	delete[] arr[0];
	delete[] arr;
	return buffer;
}

template<typename T>
T** erase_row(T** arr, int& rows, int& index)
{
	rows--;
	int** buffer = new int* [rows];
	for (int i = rows; i > index; --i)
	{
		buffer[i - 1] = arr[i];
	}
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	return buffer;
}

template<typename T>
T** insert_row(T** arr, int& rows, const int cols, int &index)
{
	int** buffer = new int* [rows + 1];
	for (int i = rows; i >= index; i--)
	{
		buffer[i + 1] = arr[i];
	}
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	buffer[index] = new int[cols] {};
	rows++;
	return buffer;
}

template<typename T>
void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//1) Создаём буферную строку
		int* buffer = new int[cols + 1] {};
		//2) Копируем значения из исходной строки в буферную
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		//3) Удаляем исходную строку
		delete[] arr[i];
		//4) Подменяем адрес строки в массиве указателей
		arr[i] = buffer;
	}
		cols++;
}

template<typename T>
void push_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j+1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

template<typename T>
void insert_col(T** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};

		for (int j = 0; j < index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = cols; j >= index; j--)
		{
			buffer[j+1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

template<typename T>
void pop_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1] {};
		for (int j = 0; j < cols - 1; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}

template<typename T>
void pop_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1] {};
		for (int j = 0; j < cols - 1; j++)buffer[j] = arr[i][j+1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}

template<typename T>
void erase_col(T** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1] {};

		for (int j = 0; j < index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = cols; j > index; j--)
		{
			buffer[j - 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}


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

void Clear(int** arr, const int rows)
{
	//3)Сначала удаляем строки:
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//4)Удаляем массив указателей:
	delete[] arr;
}

