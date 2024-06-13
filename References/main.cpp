#include<iostream>
using namespace std;

//Reference - это переменная, которая содержит адрес другой переменной
//#define REFERENCE
#define THE_DIFFERENCE_BETWEEN_A_POINTER_AND_A_REFERENCE
void main()
{
	setlocale(LC_ALL, "");
#ifdef REFERENCE
	int a = 2;
	int& ra = a;
	ra += 3;
	cout << a << endl;
	cout << &a << endl;
	cout << &ra << endl;
#endif // REFERENCE

#ifdef THE_DIFFERENCE_BETWEEN_A_POINTER_AND_A_REFERENCE
	//1.The reference must be initialized when it is created. Ссылка должна быть инициализирована при создании, указатель не обязательно.
	int a;
	int b;
	int& r_a = a;// the r_a reference contains the address of the variable a;
	r_a = b;//заставить ссылку изменить адресс на который она ссылается НЕЛЬЗЯ;
	//можно только поменять значение по этому адресу, т.е. значение переменной 'a' будет такое же как и переменной 'b';
	int* p_a; //The pointer does not have to be initialized when it is created.
	p_a = &a;
	p_a = &b; //Указатель может изменить адресс на который он указывает;

	//2.The pointer may not point to anything, but the reference cannot.
	int* p = nullptr;//Указатель может не на что не указывать;
	int& r = nullptr;//Ссылка должна на что то ссылаться.

	//3.The reference does not need to be named. 
	r_a = 20; //чтобы получить значение на которое ссылается ссылка нам нужно использовать имя этой ссылки. 
	//Ссылку разъименовывать не нужно;
	*p_a = 30;//Чтобы получить значение на которое указывает указатель его нужно разъименовать.

	//4.В указателе есть адрес, у ссылки нет адреса (он есть, но мы его не узнаем). 
	int a = 10;
	int* p_a = &a;
	int& r_a = a;
	cout << &a << endl;
	cout << &r_a << endl;//адрес ссылки такой же как адрес переменной на которую она ссылается;
	//Компилятор не явно сначала разъименовывает ссылку, а потом берёт адрес переменной на которую ссылается ссылка
	//Таким образом у ссылки и переменной одинаковые адреса при выводе в консоль, хотя у ссылки есть свой адрес, но мы его узнать не можем.
	cout << &p_a << endl;

	//5.Создать массив ссылок НЕЛЬЗЯ! Массив указателей мы создать можем.

	//6.Арифметики ссылок НЕТ! Есть арифметика указателей.

#endif // THE_DIFFERENCE_BETWEEN_A_POINTER_AND_A_REFERENCE
}