template<typename T>
T** Allocate(const int rows, const int cols)
{
	//1) Создаём массив указателей :
	T** arr = new int* [rows];

	//2) Выделяем память под строки:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}