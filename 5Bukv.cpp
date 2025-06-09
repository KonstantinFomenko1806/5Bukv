#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <Windows.h>
#include <math.h>

using namespace std;
                                               // счетчик
const int len = 8;
const int strings = 9620;
const char ch = '\n';

char arr[strings][len];

int N = 0;
int A;                                                   // Аналог переменной bool, да/нет
char X;    // Запоминаем букву
int Y;     // Порядковое число буквы

void XX2()
{
	for (int i = 0; i < strings; i++)                    // Перебираем слова
	{
		

		for (int i2 = 0; i2 < 5; i2++)                   // Ищем букву в слове
		{
			
			if (arr[i][i2] != X )                     //Этой буквы в слове нет
			{
				N++;
				if (N == 5 && arr[i][0] != 0)
				{
					for (int i4 = 0; i4 < 5; i4++)           // Выводим слово если совпало
					{
						cout << arr[i][i4];
					}
					cout << '\n';
				}
				else 
				{}

			}
			else
			{
				for (int i3 = 0; i3 < 5; i3++)           // Чистим строчку массива если в слове нет нужной буквы
				{
					arr[i][i3] = 0;
				}
				break;
			}
		}
		N = 0;
	}
}
void XX1()       // следующий этап цикла 1.3
{
	for (int i = 0; i < strings; i++)
	{
		for (int i2 = 0; i2 < 5; i2++)
		{
			if (arr[i - 1][Y-1] == X)
			{
				for (int i4 = 0; i4 < 5; i4++)           // Выводим слово если совпало
				{
					cout << arr[i - 1][i4];
				}
				cout << '\n';
				break;
			}
			else
			{
				if (i2 == 4)
				{
					for (int i3 = 0; i3 < 5; i3++)
					{
						arr[i - 1][i3] = 0;
					}
				}
			}
		}
	}
}
void XX()
{
	for (int i = 0; i < strings; i++)                    // Перебираем слова
	{
		for (int i2 = 0; i2 < 5; i2++)                   // Ищем букву в слове
		{
			if (arr[i - 1][i2] == X && arr[i-1][Y-1] != X)                     // Совпала/не совпала буква
			{
				for (int i4 = 0; i4 < 5; i4++)           // Выводим слово если совпало
				{
						cout << arr[i - 1][i4];
				}
				cout << '\n';
				break;
			}
			else
			{
				if (i2 == 4)
				{
					for (int i3 = 0; i3 < 5; i3++)           // Чистим строчку массива если в слове нет нужной буквы
					{
						arr[i - 1][i3] = 0;
					}
				}
			}
		}
	}
}
void W2()
{
	cout << "Есть ли лишние буквы? 1-да, 0-нет:  ";
	cin >> A;
	if (A == 1)
	{
		cout << "Введите эту букву:  ";                            
		cin >> X;
		XX2();
		cout << "Желаете продолжить? 1 - да, 0 - нет:  ";
		cin >> A;
		if (A == 1)
		{
			W2();
		}
		else
		{}
	}
}
void W1()
{
	cout << "Есть ли буква на своем месте? 1 - да, 0 - нет:  ";    //Переход к следующему этапу цикла 1.2 <-----------------------------------
	cin >> A;
	if (A == 1)
	{
		cout << "Введите эту букву:  ";                            //Переход к следующему этапу цикла 1.3
		cin >> X;
		cout << "Порядковый номер буквы:  ";
		cin >> Y;
		XX1();
		cout << "Желаете продолжить? 1 - да, 0 - нет:  ";
		cin >> A;
		if (A == 1)
		{
			W1();
		}
		else
		{
			W2();
		}
	}
	else
	{
		W2();
	}
}
void W()     //Переход к следующему этапу цикла 1.0
{
	cout << "Есть ли открытая буква, но точное место не известно? 1-да, 0-нет:  ";
	cin >> A;
	if (A == 1)
	{
		cout << "Введите эту букву: ";
		cin >> X;
		cout << "На каком месте сей час буква?:  ";
		cin >> Y;
		XX();    //Переход к следующему этапу цикла 1.1
		cout << "Желаете продолжить? 1 - да, 0 - нет:  ";
		cin >> A;
		if (A == 1)
		{
			W();
		}
		else
		{
			W1();
		}
	}
	else
	{
		W1();    //Переход к следующему этапу цикла 1.4
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 0; // строчка массива
	int a = 0; // буква по счету
	char in = 0; // какая именно буква
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ifstream fs("E:/My Code/slovo/slovo/text333.txt", ios::in | ios::binary);        //Укажите путь к списку слов <----------
	if (!fs) return 1;
	for (int r = 0; r < strings; r++)
	{
		fs.getline(arr[r], len - 1, ch);        // записываем в массив
		//cout << arr[0] << '\n';
	}
	fs.close();
	
	for (int i = 1; i > 0; i++)
	{
		W();
	}
	
	return 0;
}
