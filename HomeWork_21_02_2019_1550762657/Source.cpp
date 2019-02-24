#include<iostream>
#include<locale.h>
#include<time.h>
#include<Windows.h>
#include<cmath>

#define Pi 3.14159265;

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


double sgrt(double a)
{
	return sgrt(a);
}

double cub(double a)
{
	return pow(a, 3);
}

double sinus(double a)
{
	return sin (a * 3.14159265 / 180);
}


double func1(double x)
{
	return x * 2;
}

double func2(double x)
{
	return x * 2 + 4;
}

double acumArray(double *funcPtr, double a, double b)
{
	for(a)
}



void Task1()
{
	/*1.	**Реализовать 3 функции каждая из которых принимает вещественное число и возвращает вещественное число. 
	Первая функция вычисляет квадратный корень числа, вторая – куб числа, третья – синус числа. 
	В главной функции создайте массив из 3-х указателей на эти функции. Добавьте меню, в котором пользователь может 
	выбрать желаемую операцию. Напишите программу без использования операторов if и switch.*/


	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask1\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	setlocale(LC_ALL, "");
	srand(time(NULL));

	double(*ukaz[3])(double) = { sqrt, cub, sinus };
	double a;

	
	cout << "Введите число" << "\n\n-> ";
	cin >> a;
	cout << endl;
	
		
	cout << "Выберите номер операции над числом : \n" << endl;
	cout << "(1) - квадратный корень числа" << endl;
	cout << "(2) - куб числа" << endl;
	cout << "(3) - синус числа" << endl;
	
	int choice = -1;

		while (choice < 1 || choice > 3)
		{
			cout << "\n-> ";
			cin >> choice;
			cout << endl;

			if (choice < 1 || choice > 3) 
				cout<<"Выбранной операции нет, повторите выбор...\n";
		}
		
		cout << endl << "Результат : " << ukaz[choice-1](a) << endl;
}

void Task2()
{
	/* 2.	***Напишите 2 функции, каждая из которых принимает вещественный параметр и возвращает вещественное значение. 
	Пусть первая функция вычисляет y = x2 , а вторая – y = x*2+4, где x – входной параметр y – возвращаемое значение. 
	Затем напишите функцию, которая принимает указатель на одну из этих функций, а также диапазон значений (от a до b)
	и выводит на экран 10 точек (координаты x и y) для этого диапазона. Напишите меню, которое иллюстрирует работу этих функций*/



	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask2\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	double x, a, b;

	double(*funcPtr[2])(double) = { func1, func2};

	cout << "Введите диапозон значений от ( a ) до ( b )" << "\n\n-> ";
	cin >> a >> b;
	cout << endl;


	cout << "Выберите функцию для расчета координат точек x и y : \n" << endl;
	cout << "(1) - функция y = x*2" << endl;
	cout << "(2) - функция y = x*2+4" << endl;
	
	int choice = -1;

	while (choice < 1 || choice > 2)
	{
		cout << "\n-> ";
		cin >> choice;
		cout << endl;

		if (choice < 1 || choice > 2)
			cout << "Выбранной операции нет, повторите выбор...\n";
	}

	cout << endl << "Результат : " << funcPtr[choice - 1](a) << endl;


}


int main()
{
	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n Orlov Vladimir HomeWork_19_02_2019_1550591366 \n\n";
	SetConsoleTextAttribute(hConsole, 7);


	setlocale(LC_ALL, "");
	srand(time(NULL));

	int number;
	char flag;

	do
	{
		cout << endl << "Enter number of Task (1) to (2) => ";
		cin >> number;

		switch (number)
		{
		case 1: {Task1(); } break;
		case 2: {Task2(); } break;


		default: cout << "\nEntered number of Task does not exist...\n\n";

		}

		SetConsoleTextAttribute(hConsole, 10);
		cout << "\n--------------------------------------------------------------------------\n\n";
		SetConsoleTextAttribute(hConsole, 7);

		cout << "Do you want to continue? \n\nIf YES press (y) if NO any keys => ";
		cin >> flag;

	} while (flag == 'y');
}
