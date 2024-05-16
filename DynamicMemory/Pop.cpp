#include"Constants.h"
TT T* pop_back(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;return buffer;
}

TT T* pop_front(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;return buffer;
}

TT T* erase(T arr[], int& n, int& index)
{
	
	if(index >= n)return arr;
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)
		buffer[i] = arr[i < index ? i : i + 1];
	delete[] arr;return buffer;
}

TT T** pop_row_back(T** arr, int& rows)
{
	
	T** buffer = new T* [--rows];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];
	delete[] arr[rows]; 
	delete[] arr;return buffer;
}

TT T** pop_row_front(T** arr, int& rows)
{
	T** buffer = new T* [--rows];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i + 1];
	delete[] arr[0];
	delete[] arr;return buffer;
}

TT T** erase_row(T** arr, int& rows, int& index)
{
	if (index >= rows)return arr;
	T** buffer = new T*[--rows];
	for (int i = 0; i < rows; i++)
		buffer[i] = arr[i < index ? i : i + 1];
	delete[] arr; return buffer;
}

TT void pop_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1] {};
		for (int j = 0; j < cols - 1; j++)buffer[j] = arr[i][j];
		delete[] arr[i];arr[i] = buffer;
	}
	cols--;
}

TT void pop_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1] {};
		for (int j = 0; j < cols - 1; j++)buffer[j] = arr[i][j + 1];
		delete[] arr[i];arr[i] = buffer;
	}
	cols--;
}

TT void erase_col(T** arr, const int rows, int& cols, const int index)
{
	
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};

		for (int j = 0; j < cols-1; j++)
		{
			buffer[j] = arr[i][j<index?j:j+1];
		}
		
		delete[] arr[i]; arr[i] = buffer;
	}
	cols--;
}
