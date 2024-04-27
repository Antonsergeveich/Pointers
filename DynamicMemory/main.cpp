#include<iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	int* arr_2 = new int[n+1]; //выделяем память под новый массив на один элемент больше
	for (int i = 0; i < n; i++) //перезаписываем элементы с одного массива в другой
	{
		arr_2[i] = arr[i];
	}
	arr_2[n] = value; // последнему элементу нового массива присваиваем значение введённое с клавиатуры
	delete[] arr; // удаляем исходный массив
	n++;// увеличиваем переменную 'n' на '1' больше, чтобы вывести новый массив 
	Print(arr_2, n);
	delete[] arr_2;
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
