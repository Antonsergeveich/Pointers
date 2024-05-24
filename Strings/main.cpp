#include<iostream>
#include "main.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	const int N = 192;
	const int n = 224;
	int upper[32]{N};
	for (int i = 0; i < 32; i++)
	{
		 upper[i] = N+i;
		 cout << (char)upper[i]<< endl;
	}
	int lower[32]{ n };
	for (int i = 0; i < 32; i++)
	{
		lower[i] = n + i;
		cout << (char)lower[i] << endl;
	}
	
}