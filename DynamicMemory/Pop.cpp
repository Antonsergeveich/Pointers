template<typename T>
T* pop_back(T arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

template<typename T>
T* pop_front(T arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}

template<typename T>
T* erase(T arr[], int& n, int& index)
{
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

template<typename T>
T** pop_row_back(T** arr, int& rows)
{
	// переопределяем массив указателей
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];
	delete[] arr[rows]; //удаляем удаляемую строку из памяти
	delete[] arr;
	return buffer;
}

template<typename T>
T** pop_row_front(T** arr, int& rows)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i + 1];
	delete[] arr[0];
	delete[] arr;
	return buffer;
}

template<typename T>
T** erase_row(T** arr, int& rows, int& index)
{
	rows--;
	int** buffer = new int* [rows];
	for (int i = rows; i > index; --i)
	{
		buffer[i - 1] = arr[i];
	}
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	return buffer;
}

template<typename T>
void pop_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1] {};
		for (int j = 0; j < cols - 1; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}

template<typename T>
void pop_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1] {};
		for (int j = 0; j < cols - 1; j++)buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}

template<typename T>
void erase_col(T** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1] {};

		for (int j = 0; j < index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = cols; j > index; j--)
		{
			buffer[j - 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}