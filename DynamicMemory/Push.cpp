template<typename T>
T* push_back(T arr[], int& n, T value)
{
	int* buffer = new int[n + 1]; //1)������ �������� ������ ������� �������:
	for (int i = 0; i < n; i++) //2)�������� �������� �� ��������� ������� � ��������:
	{
		buffer[i] = arr[i];
	}
	delete[] arr; //3) ������� �������� ������:
	//4) ��������� ����� ��������� ������� ������� ������ �������:
	arr = buffer;
	//5)������ ����� ����� � ����� ������� ���������� ��������� �����,
	// ���� ����� �������� ��������:
	arr[n] = value;
	n++;// ����������� ���������� 'n' �� '1' ������, ����� ������� ����� ������ 
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
	//1)������ �������� ������ ���������� ������� �������:
	int** buffer = new int* [rows + 1];

	//2)�������� ������ �� ��������� ������� � ������ ����������:
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];

	//3)������� �������� ������ ����������:
	delete[] arr;

	//4)������ ������ � ��������� � � ������:
	buffer[rows] = new int[cols] {};

	//5)����� ���������� ������ � ������, ���������� ��� ����� �������������:
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
		//1) ������ �������� ������
		int* buffer = new int[cols + 1] {};
		//2) �������� �������� �� �������� ������ � ��������
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		//3) ������� �������� ������
		delete[] arr[i];
		//4) ��������� ����� ������ � ������� ����������
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