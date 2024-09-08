#include<iostream>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

void to_lower(char s[]);      //переводит строку в нижний регистр
void to_upper(char s[]);      //переводит строку в верхний регистр
void shrink(char s[]);        //удаляет из строки лишние пробелы; Хорошо живёт на свете Винни Пух;
bool is_palindrome(char s[]); //Определяет, является строка палиндромом
bool is_int_number(char s[]); //Определяет, является ли строка целым числом
bool to_int_number(char s[]); //Если строка является целым числом, то возврвщает его значение
bool is_bin_number(char s[]); //Определяет,является ли строка двоичным числом
int  bin_to_dec(char s[]);    //Если строка является двоичным числом, возвращает его десятичное  значение
bool is_hex_number(char s[]); //Определяет является ли строка шестнадцатиричным числом
int  hex_to_dec(char s[]);    //Если строка является шестнацатеричным числом, возвращает его десятиричное значение


void main()
{
	setlocale(LC_ALL, "");
	char a[] = "HELLO STRING Ё";
	char b[] = "Хорошо     живёт на   свете         Винни             Пух";
	to_lower(a);
	printf(a);
	cout << endl;
	to_upper(a);
	printf(a);
	cout << endl;
	shrink(b);
	printf(b);
}

void to_lower(char s[])
{
	for (int i = 0; s[i]; i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'А' && s[i] <= 'Я')
			s[i] = s[i] + 32;
		else if (s[i] == 'Ё')s[i] = s[i] + 16;
	}
}

void to_upper(char s[])
{
	for (int i = 0; s[i]; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'а' && s[i] <= 'я')
			s[i] -= 32;
		else if (s[i] == 'ё')s[i] -= 16;
	}
}

void shrink(char s[])
{
	for (int i = 0; s[i]; i++)
	{
		while (s[i] == ' ' && s[i + 1] == ' ')
		{
			for (int j = i; s[j]; j++)s[j] = s[j + 1]; // сдвигаем влево строку если за пробелом пробел
		}
	}
}

bool is_palindrome(char s[])
{
	return false;
}
