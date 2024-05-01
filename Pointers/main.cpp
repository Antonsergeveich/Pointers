﻿#include<iostream>
using namespace std;

//#define POINTERS_BASICS

void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTERS_BASICS
	int a = 2;
	int* pa = &a;
	cout << a << endl; // вывод значения переменной 'a' на экран
	cout << &a << endl; // взятия адреса переменной 'a' прямо при выводе
	cout << pa << endl; // вывод адреса переменной 'a' хранящегося в указателе 'pa'
	cout << *pa << endl;// разыменование указателя 'pa' и вывод значению по адресу
	                    // (значение переменной 'a')
	/* & - Оператор взятия адреса (Address-of operator)
       * - Оператор разъименования (Dereference operator)*/
	int* pb;
	int b = 3;
	pb = &b;
	// int - int
	// int* - указатель на int
#endif // POINTERS_BASICS

	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;
}