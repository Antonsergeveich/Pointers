#include<iostream>
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