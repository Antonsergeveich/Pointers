#include<iostream>
using namespace std;

/*
1. By value;
2. By Pointer;
3. By reference;
*/

void Exchange(int& a, int& b);// �� ������
void Exchange_1(int* a, int* b);// �� ���������

void main()
{
	setlocale(LC_ALL, "");
	int a = 2, b = 3;
	cout << a << "\t" << b << endl;
	//Exchange(a, b);//�� ������
	Exchange_1(&a, &b);// �� ���������
	cout << a << "\t" << b << endl;
}

void Exchange(int& a, int& b)
{
	int buffer = a;
	a = b;
	b = buffer;
}

void Exchange_1(int* a, int* b)
{
	
	int buffer = *a;
	*a = *b;
	*b = buffer;
}
