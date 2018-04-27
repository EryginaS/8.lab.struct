// тех прог (структуры).cpp : Defines the entry point for the console application.
//1. Используя записи, необходимо сложить и умножить два комплексных числа.
//2. Задается месяц и год двух дат. Пользователь вводит еще одну дату (месяц и год). Необходимо определить, пренадлежит ли эта дата задонному промежутку.
//3. Пользователь вводит данные о количестве студентов. Для каждого из них вводит: Фамилию и Имя, а так же оценку за лабораторную. Необходимо определить средний балл и вывести список студентов, чей бал выше среднего, подсветив их фамилии.
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <iostream>
#include<string>
#include<istream>
#include <Windows.h>
using namespace std;
struct compl {float x, y;};
struct event{int yaers, mounth;};
struct study { char name[50]; int ball; };
int main()
{
	SetConsoleCP(1251);// позволяет записывать русские символы в строки/массивы 
	SetConsoleOutputCP(1251);

	
	//1.
	setlocale(LC_ALL, "Russian");
	struct compl a, b, sum, proizvedenie;
	cout << "Число А: " << endl;
	cout << "Действительная часть: ";
	cin >> a.x;
	cout << "Мнимая часть:";
	cin >> a.y;
	cout << "Число B: " << endl;
	cout << "Действительная часть: ";
	cin >> b.x;
	cout << "Мнимая часть:";
	cin >> b.y;
	cout << "Число А: " << endl << a.x << "+i" << a.y << endl;
	cout << "Число B: " << endl << b.x << "+i" << b.y << endl;
	sum.x = a.x + b.x;
	sum.y = a.y + b.y;
	proizvedenie.x = a.x*b.x - a.y*b.y;
	proizvedenie.y = a.x*b.y + a.y*b.x;
	cout << endl;
	cout << "Сумма двух комплексных чисел: " << sum.x << "+i" << sum.y << endl;
	cout << "Произведение двух комплексных чисел: " << proizvedenie.x << "+i" << proizvedenie.y << endl;

	cout << endl;
	////2.
	struct event one, two,three;
	
	cout << "Пожалуйста, вводите события в хронологическом порядке!" << endl;
	cout << "Введите первое событие:  " << endl << "месяц: " << endl;
	cin >> one.mounth;
	cout << "Год: ";
	cin >> one.yaers;
	cout << "Введите второе событие:  " << endl << "месяц: " << endl;
	cin >> two.mounth;
	cout << "Год: ";
	cin >> two.yaers;
	cout << "Введите ваше событие для проверки на пренадлежность временного промежутка, заданного ранее:  " << endl << "месяц: " << endl;
	cin >> three.mounth;
	cout << "Год: ";
	cin >> three.yaers;
	if (one.yaers == two.yaers)
	{
		if (three.mounth > one.mounth&&three.mounth < two.mounth)
			cout << "Ваше событие пренадлежит данному временному промежутку" << endl;
		else
			cout << "Ваше событие не пренадлежит данному временному промежутку" << endl;
	}
	else
	{
		if (two.yaers - one.yaers > 1)
		{
			if (three.yaers>one.yaers&&three.yaers<two.yaers)
				cout << "Ваше событие пренадлежит данному временному промежутку" << endl;
			else
				cout << "Ваше событие не пренадлежит данному временному промежутку" << endl;
		}
		else
		{
			if (three.yaers == one.yaers)
			{
				if (three.mounth > one.mounth)
					cout << "Ваше событие пренадлежит данному временному промежутку" << endl;
				else
					cout << "Ваше событие не пренадлежит данному временному промежутку" << endl;
			}
			else
			{
				if (three.yaers==two.yaers)
					if (three.mounth<two.mounth)
						cout << "Ваше событие пренадлежит данному временному промежутку" << endl;
					else
						cout << "Ваше событие не пренадлежит данному временному промежутку" << endl;
				else
					cout << "Ваше событие не пренадлежит данному временному промежутку" << endl;
			}
		}
		
	}
	//3.
	struct study mas[50];
	int n, k=0;
	cout << endl;
	cout << "Введите количество студентов: " << endl;
	cin >> n;
	cout << "ИФ студента: " << endl;
	cout << "Оценка студента за лабораторную работу: " << endl;
	for (int i = 0; i < n;i++)
	{
		cout << i+1<<")" <<endl;
		
		cin.ignore();
		cin.getline(mas[i].name, 50);
		
	
	}
	for (int i = 0; i < n; i++)
	{
		
		cout <<mas[i].name<< ":";
		cin >> mas[i].ball;
		cin.ignore();
	}
	
	int middle = 0;
	for (int i = 0;i < n;i++)
	{
		middle += mas[i].ball;
	}
	cout << endl;
	cout << "Средний балл группы: " << middle/n << endl;
	cout << endl;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0;i < n;i++)
	{
		if (mas[i].ball > middle / n)
		{
			SetConsoleTextAttribute(hConsole, (WORD)((10 << 4) | 0));
			cout << mas[i].name << " " << mas[i].ball << endl;
		}
		else
		{
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) |7));
			cout << mas[i].name << " " << mas[i].ball << endl;
		}
	}
	cout << endl;
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 7));
	system("pause");

    return 0;
}

