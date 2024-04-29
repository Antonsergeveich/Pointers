#include<iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* push_back(int arr[], int &n, int value);
int* push_front(int arr[], int &n, int value);
int* pop_back(int arr[], int& n);
void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	
	FillRand(arr, n);
	Print(arr, n);

	int value;
	/*cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);*/
	
	arr = pop_back(arr, n);
	Print(arr, n);
	delete[] arr;
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

int* push_back(int arr[], int &n, int value)
{
	int* buffer = new int[n + 1]; //выделяем память под новый массив на один элемент больше
	for (int i = 0; i < n; i++) //перезаписываем элементы с одного массива в другой
	{
		buffer[i] = arr[i];
	}
	delete[] arr; // удаляем исходный массив
	// Подменяем адрес исходного массива адресом нового массива
	arr = buffer;
	//только после этого в конце массива появляется свободное место,
	arr[n] = value; // последнему элементу нового массива присваиваем значение введённое с клавиатуры
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
