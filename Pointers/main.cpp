#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t" 

void ShowArray(int arr[], int size);
int GetAmound(int* ptr, int size);
int GetAmound_1(int* ptr, int size);
void Swap(int* a, int* b);

//#define POINTERS_BASICS
//#define BASIC
//#define BASIC_1
//#define POINTERS_AND_ARRAYS
//#define POINTERS_AND_ARRAYS_1
//#define POINTERS_AND_ARRAYS_2
//#define POINTERS_AND_ARRAYS_3
//#define POINTERS_AND_ARRAYS_4
//#define POINTERS_AND_FUNCTIONS
//#define POINTERS_AND_FUNCTIONS_1
//#define INITIALIZATION

void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTERS_BASICS
	int a = 2;
	int* pa = &a;
	cout << a << endl; // вывод значения переменной 'a' на экран
	cout << &a << endl; // взятия адреса переменной 'a' прямо при выводе
	cout << pa << endl; // вывод адреса переменной 'a' хранящегося в указателе 'pa'
	cout << *pa << endl;// разыменование указателя 'pa' и вывод значению по адресу
	                    // (значение переменной 'a')
	/* & - Оператор взятия адреса (Address-of operator)
       * - Оператор разъименования (Dereference operator)*/
	int* pb;
	int b = 3;
	pb = &b;
	// int - int
	// int* - указатель на int
#endif // POINTERS_BASICS

	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;
#ifdef BASIC
	int x = 3, y = 5;
	double d;
	int* px = &x;//указатель 'px' берёт адрес переменной 'x';
	int* py = &y;//указатель 'py' берёт фдрес переменной 'y';
	cout << "*px = &x = " << *px << endl;
	cout << "*py = &y = " << *py << endl;
	y = *px + 1;//присваивает 'y' значение на 1 больше значения 'x';
	//'*' разъименовывает указатель 'px' и выводит значение переменной 'x';
	cout << "y = *px + 1 = " << y << endl;
	cout << "*px = " << *px << endl; //выводит текущее значение 'x';
	d = sqrt((double)*px);//получает в 'd' квадратный корень из 'x';
	//причём до передачи функции 'sqrt' значение 'x' преобразуется типу double
	cout << "d = sqrt((double)*px) = " << d << endl;
	*px += 1;// = *px + 1;
	cout << "*px = *px + 1 = " << *px << endl;
	py = px; cout << "py = px = " << *py << endl;
#endif // BASIC

#ifdef BASIC_1
	int x = 10;
	int y = 5;
	int* px = nullptr;
	int* py = nullptr;
	px = &x;//Записываем адрес переменной x в px;
	cout << px << " " << &x << endl; //отображаем адрес x через указатель и операцию взятия адреса;
	cout << *px << " " << x << endl; //отображаем значения x через переменную и операцию разыменования;
	*px = 99;//изменяем значение переменной x используя операцию разъименования;
	cout << *px << " " << x << endl;//отображаем новое значение x через пременную и операцию разъименования;
	py = &y; // записываем адрес переменной y в py;
	cout << py << " " << &y << endl;//отображаем адрес y через указатель и операцию взятия адреса;
	cout << *py << " " << y << endl;//отображаем значение y через переменную и операцию разъименования;
	py = px; //записываем значение адреса из px в py//теперь оба указателя указывают на x;
	cout << *px << " " << *py << " " << x << endl;//отображаем значение x через переменную и два указателя;
#endif // BASIC_1

#ifdef POINTERS_AND_ARRAYS
	const int N = 10;
	int a[N] = { 0,1,1,2,3,5,8,13,21,34 };
	int* pa;
	pa = &a[0];// одно и то же что и "pa = a", так как имя массива это указатель на его нулевой элемент;
	pa = a;//&a[i] == a+i одно и тоже;
	cout << "*pa = " << *pa << endl;
	int x = *pa;//копируем содержимое a[0] в x;
	cout << "x = *pa = " << x << " " << sizeof(x) << endl;
	x = *(pa + 1);
	cout << "x = *(pa + 1) = " << x << " " << &x << " " << sizeof(x) << endl;//выводим значение следующего элемента массива т.е. a[1];
	x = *(a + 8);//ссылку на любой элемент массива a[i] можно записать как *(a+i), где 'a' имя массива;
	cout << "x = *(a + 8) = a[8] = " << x << endl;//выводим значение выбранного элемента массива т.е. a[8];
	//указатель "pa" является переменной, имя массива является константой;
#endif // POINTERS_AND_ARRAYS

#ifdef POINTERS_AND_ARRAYS_1
	const int size = 5;
	int arr[size] = { 33,44,7,8,9 };
	int* ptr = &arr[0];//записываем адрес нулевого элемента массива в указатель;
	cout << *ptr << endl;//показываем значение нулевого массива через разъименовывание указателя;
	//cout << *(ptr + 1) << endl;//выполняем смещение на один элемент целого типа вперёд и записываем новый адрес в указатель ptr;
	//ptr = ptr + 1 * sizeof(int);
	ptr++;
	//ptr = ptr + 1;
	cout << *ptr << endl;
#endif // POINTERS_AND_ARRAYS_1

#ifdef POINTERS_AND_ARRAYS_2//использование указателя для отображения элементов массива;
	const int size = 5;
	int arr[size] = { 33,44,7,8,9 };
	int* ptr = arr;//записываем адрес нулевого элемента массива в указатель;
	for (int i = 0; i < size; i++)//выводим массив на экран;
	{
		cout << *(ptr + i) << tab;
	}
	*(ptr + 1) = 55;//изменяем значение первого элемента;
	*(ptr + 2) = 12;//изменяем значения второго элемента;
	cout << endl;
	for (int i = 0; i < size; i++)//выводим массив;
	{
		cout << *(ptr + i) << tab;
	}
#endif // POINTERS_AND_ARRAYS_2

#ifdef POINTERS_AND_ARRAYS_3//обращение к имени массива с помощью синтаксиса указателей;
	const int size = 5;
	int arr[size] = { 33,44,7,8,9 };
	for (int i = 0; i < size; i++)//выводим массив на экран;
	{
		cout << *(arr + i) << tab;
	}
	*(arr + 1) = 55;//изменяем значение первого элемента;
	*(arr + 2) = 12;//изменяем значения второго элемента;
	cout << endl;
	for (int i = 0; i < size; i++)//выводим массив;
	{
		cout << *(arr + i) << tab;
	}
#endif // POINTERS_AND_ARRAYS_3

#ifdef POINTERS_AND_ARRAYS_4//использование синтаксиса мвссивов к указателю;
	const int size = 5;
	int arr[size] = { 33,44,7,8,9 };
	int* ptr = arr;
	for (int i = 0; i < size; i++)
	{
		cout << ptr[i] << tab;
	}
	ptr[1] = 55;
	ptr[2] = 12;
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << ptr[i] << tab;
	}
#endif //  POINTERS_AND_ARRAYS_4

#ifdef POINTERS_AND_FUNCTIONS
	const int size = 5;
	int arr[size] = { 33,44,7,8,9 };
	ShowArray(arr, size);
	cout << endl;
	cout << "Amound of array elements: " << GetAmound_1(arr, size) << endl;
	ShowArray(&arr[0], size);
#endif // POINTERS_AND_FUNCTIONS

#ifdef POINTERS_AND_FUNCTIONS_1//изменение параметров по указателю
	int av = 5, bv = 9;
	Swap(&av, &bv);
	cout << av << " " << bv << endl;
#endif // POINTERS_AND_FUNCTIONS_1

#ifdef INITIALIZATION
	int* ptr;//указатель не инициализирован, в нём мусор;
	ptr = 0;//сейчас ptr нулевой, так делать нельзя;
	cout << ptr << endl;
	ptr = NULL;//наследие языка 'C' так делать не рекомендуется;
	cout << ptr << endl;
	ptr = nullptr;//современный способ C++ создания нулевого указателя;
	cout << ptr << endl;
#endif // INITIALIZATION
}

void ShowArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << tab;
	}
}
int GetAmound(int* ptr, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += *(ptr + i);
	}
	return sum;
}
int GetAmound_1(int* ptr, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++, ptr++)
	{
		sum += *ptr;
	}
	return sum;
}
void Swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}