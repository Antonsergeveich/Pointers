#include<iostream>
using namespace std;
#define tab "\t"
void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		//Обращение к элементам массива через арифметику указателей
		//и оператор разъименоания
		*(arr + i) = rand() % 100;
	}
	for (int i = 0; i < n; i++)
	{
		//обращение к элементам массива через 
		//оператор индексирования - []
		cout << arr[i] << tab;
	}
	cout << endl;
}