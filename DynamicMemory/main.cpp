#include<iostream>
using namespace std;

using std::cout;
using std::cin;
using std::endl;

#define tab "\t"

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

int** Allocate(int rows, int cols);
void Clear(int* arr[], int rows);
void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);
int* push_back(int arr[], int &n, int value);//добавить значение в конец массива
int* push_front(int arr[], int &n, int value);//добавить значение в начало массива
int* pop_back(int arr[], int& n);//убрать значение в конце массива
int* pop_front(int arr[], int& n);//убрать значение в конце массива
int* insert(int arr[], int &n, int value, int &index);//добавить значение по указанному индексу
int* erase(int arr[], int &n, int &index);//удалить значение по указанному индексу
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
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	////1) Создаём массив указателей:
	//int** arr = new int*[rows];
	////2) Выделяем память под строки:
	//for (int i = 0; i < rows; i++)
	//{
	//	arr[i] = new int[cols] {};
	//}
	
	int** arr = Allocate(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	Clear(arr, rows);
	////3)Сначала удаляем строки:
	//for (int i = 0; i < rows; i++)
	//{
	//	delete[] arr[i];
	//}
	////4)Удаляем массив указателей:
	//delete[] arr;
#endif // DYNAMIC_MEMORY_2
}

void FillRand(int arr[], const int n)
{
	     for (int i = 0; i < n; i++)
	     {
		//Обращение к элементам массива через арифметику указателей
		//и оператор разъименования
		   *(arr + i) = rand() % 100;
	     }
}

void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//обращение к элементам массива через 
		//оператор индексирования - []
		cout << arr[i] << tab;
	}
	cout << endl;
}

void Print(int** arr, const int rows, const int cols)
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

int* push_back(int arr[], int &n, int value)
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

int* push_front(int arr[], int& n, int value)
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

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i+1];
	delete[] arr;
	return buffer;
}

int* insert(int arr[], int &n, int value, int &index)
{
	while (index >= n)
	{
		cout << "WARNING!!! Index: " << index << " Error " << endl;
		cout << "Введите новый индекс вставляемого значения: "; cin >> index;
	} 
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

int* erase(int arr[], int& n, int &index)
{
	while (index >= n)
	{
		cout << "WARNING!!! Index: " << index << " Error " << endl;
		cout << "Введите новый индекс вставляемого значения: "; cin >> index;
	}
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

int** Allocate(int rows, int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}

void Clear(int* arr[], int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
