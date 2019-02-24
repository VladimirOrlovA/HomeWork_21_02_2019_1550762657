#include<iostream>
#include<locale.h>
#include<time.h>
#include<Windows.h>
#include<cmath>

#define Pi 3.14159265

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
	return sin (a * Pi / 180);
}


double func1(double x)
{
	return (x) * 2;
}

double func2(double x)
{
	return x * 2 + 4;
}

void printFuncDiap(double(*funcPtr)(double) , double a, double b, double x)
{
	double step = (b - a) / 9;					// определяем (шаг) дискретизацию (или цену деления) для расчета 10 точек в диапозоне от "a" до "b"
	
	a += x;										// определение значения "x" на первой границе диапозона заданной значением "а"
	
	cout << "\n Значения по оси x - > ";

	for (int i = 0; i != 10; i++)				// выводим значения 10 точек "x"
	{
		cout << (a + step * i) << "\t";
	}


	cout << "\n Значения по оси y - > ";

	for (int i = 0; i != 10; i++)				// выводим значения 10 точек "y" через цикл и вызов в нем выбранной функции расчета значения "y"
	{
		cout << funcPtr(a+step*i)<<"\t";		
	}
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

	double(*funcPtr[2])(double) = { func1, func2 };							// указатель с массивом содержащим значения адресов функций для расчета y
	
	cout << "Введите значение ( x )" << "\n\n-> ";
	cin >> x;
	cout << endl;

	cout << "Введите диапозон значений от ( a ) до ( b )" << "\n\n-> ";
	cin >> a;
	cout<< "\n\n-> ";
	cin	>> b;
	cout << endl;


	cout << "Выберите функцию для расчета координат точек x и y : \n" << endl;
	cout << "(1) - функция y = x*2" << endl;
	cout << "(2) - функция y = x*2+4" << endl;
	
	int choice = -1;

	while (choice < 1 || choice > 2)										// меню для выбора адреса функции, в массиве указателе для расчета координаты y
	{
		cout << "\n-> ";
		cin >> choice;
		cout << endl;

		if (choice < 1 || choice > 2)
			cout << "Выбранной функции под эти номером нет, повторите выбор...\n";
	}

	*funcPtr = funcPtr[choice - 1];											// присваиваем адрес выбранной функции через указатель 

	printFuncDiap((*funcPtr), a, b, x);										// вызываем функцию вывода на экран координат "x" и "y"
	
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

	return 0;
}
