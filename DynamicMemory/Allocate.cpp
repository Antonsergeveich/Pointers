int** Allocate(const int rows, const int cols)
{
	//1) ������ ������ ���������� :
	int** arr = new int* [rows];

	//2) �������� ������ ��� ������:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}