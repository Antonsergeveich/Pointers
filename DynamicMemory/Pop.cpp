template<typename T>T* pop_back(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

template<typename T>T* pop_front(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}

template<typename T>T* erase(T arr[], int& n, int& index)
{
	if(index >= n)return arr;
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)
		buffer[i] = arr[i < index ? i : i + 1];
	delete[] arr;
	return buffer;
}

template<typename T>T** pop_row_back(T** arr, int& rows)
{
	delete[] arr[rows - 1];
	return pop_back(arr,rows);
}

template<typename T>T** pop_row_front(T** arr, int& rows)
{
	delete[] arr[0];
	return pop_front(arr,rows);
}

template<typename T>T** erase_row(T** arr, int& rows, int& index)
{
	delete[] arr[index];
	return erase(arr,rows,index);
}

template<typename T>void pop_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = pop_back(arr[i], cols);
		cols++;
	}
	cols--;
	/*for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1] {};
		for (int j = 0; j < cols - 1; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;*/
}

template<typename T>void pop_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = pop_front(arr[i], cols);
		cols++;
	}
	cols--;
	/*for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1] {};
		for (int j = 0; j < cols - 1; j++)buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
		cols--;
	}*/
}

template<typename T>void erase_col(T** arr, const int rows, int& cols, const int index)
{
	/*for (int i = 0; i < rows; i++)
	{
		delete[] arr[index];
		return arr[i] = erase(arr[i], cols, index);
		cols++;
	}
	cols--;*/
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1] {};

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