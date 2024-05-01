#include<iostream>
using namespace std;

//#define POINTERS_BASICS

void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTERS_BASICS
	int a = 2;
	int* pa = &a;
	cout << a << endl; // вывод значени€ переменной 'a' на экран
	cout << &a << endl; // вз€ти€ адреса переменной 'a' пр€мо при выводе
	cout << pa << endl; // вывод адреса переменной 'a' хран€щегос€ в указателе 'pa'
	cout << *pa << endl;// разыменование указател€ 'pa' и вывод значению по адресу
	                    // (значение переменной 'a')
	/* & - ќператор вз€ти€ адреса (Address-of operator)
       * - ќператор разъименовани€ (Dereference operator)*/
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