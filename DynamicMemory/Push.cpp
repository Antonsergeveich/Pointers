template<typename T>
T* push_back(T arr[], int& n, T value)
{
	int* buffer = new int[n + 1]; //1)Создаём буферный массив нужного размера:
	for (int i = 0; i < n; i++) //2)Копируем значения из исходного массива в буферный:
	{
		buffer[i] = arr[i];
	}
	delete[] arr; //3) Удаляем исходный массив:
	//4) Подменяем адрес исходного массива адресом нового массива:
	arr = buffer;
	//5)Только после этого в конце массива появляется свободное место,
	// куда можно добавить значение:
	arr[n] = value;
	n++;// увеличиваем переменную 'n' на '1' больше, чтобы вывести новый массив 
	return arr;
}

template<typename T>
T* push_front(T arr[], int& n, T value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}

template<typename T>
T* insert(T arr[], int& n, T value, int& index)
{
	int* buffer = new int[n + 1];
	for (int i = n; i >= index; i--)
	{
		buffer[i + 1] = arr[i];
	}
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}

template<typename T>
T** push_row_front(T** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];

	for (int i = 0; i < rows; i++)buffer[i + 1] = arr[i];

	delete arr;

	buffer[0] = new int[cols] {};

	rows++;

	return buffer;
}

template<typename T>
T** push_row_back(T** arr, int& rows, const int cols)
{
	//1)Создаём буферный массив указателей нужного размера:
	int** buffer = new int* [rows + 1];

	//2)Копируем строки из исходного массива в массив указателей:
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];

	//3)Удаляем исходный массив указателей:
	delete[] arr;

	//4)Создаём строку и добавляем её в массив:
	buffer[rows] = new int[cols] {};

	//5)После добавления строки в массив, количество его строк увеличивается:
	rows++;

	return buffer;
}

template<typename T>
T** insert_row(T** arr, int& rows, const int cols, int& index)
{
	int** buffer = new int* [rows + 1];
	for (int i = rows; i >= index; i--)
	{
		buffer[i + 1] = arr[i];
	}
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	buffer[index] = new int[cols] {};
	rows++;
	return buffer;
}

template<typename T>
void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//1) Создаём буферную строку
		int* buffer = new int[cols + 1] {};
		//2) Копируем значения из исходной строки в буферную
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		//3) Удаляем исходную строку
		delete[] arr[i];
		//4) Подменяем адрес строки в массиве указателей
		arr[i] = buffer;
	}
	cols++;
}

template<typename T>
void push_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

template<typename T>
void insert_col(T** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};

		for (int j = 0; j < index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = cols; j >= index; j--)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}