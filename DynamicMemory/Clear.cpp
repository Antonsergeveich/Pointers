void Clear(int** arr, const int rows)
{
	//3)Сначала удаляем строки:
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//4)Удаляем массив указателей:
	delete[] arr;
}