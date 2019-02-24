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
	/*1.	**����������� 3 ������� ������ �� ������� ��������� ������������ ����� � ���������� ������������ �����. 
	������ ������� ��������� ���������� ������ �����, ������ � ��� �����, ������ � ����� �����. 
	� ������� ������� �������� ������ �� 3-� ���������� �� ��� �������. �������� ����, � ������� ������������ ����� 
	������� �������� ��������. �������� ��������� ��� ������������� ���������� if � switch.*/


	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask1\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	setlocale(LC_ALL, "");
	srand(time(NULL));

	double(*ukaz[3])(double) = { sqrt, cub, sinus };
	double a;

	
	cout << "������� �����" << "\n\n-> ";
	cin >> a;
	cout << endl;
	
		
	cout << "�������� ����� �������� ��� ������ : \n" << endl;
	cout << "(1) - ���������� ������ �����" << endl;
	cout << "(2) - ��� �����" << endl;
	cout << "(3) - ����� �����" << endl;
	
	int choice = -1;

		while (choice < 1 || choice > 3)
		{
			cout << "\n-> ";
			cin >> choice;
			cout << endl;

			if (choice < 1 || choice > 3) 
				cout<<"��������� �������� ���, ��������� �����...\n";
		}
		
		cout << endl << "��������� : " << ukaz[choice-1](a) << endl;
}

void Task2()
{
	/* 2.	***�������� 2 �������, ������ �� ������� ��������� ������������ �������� � ���������� ������������ ��������. 
	����� ������ ������� ��������� y = x2 , � ������ � y = x*2+4, ��� x � ������� �������� y � ������������ ��������. 
	����� �������� �������, ������� ��������� ��������� �� ���� �� ���� �������, � ����� �������� �������� (�� a �� b)
	� ������� �� ����� 10 ����� (���������� x � y) ��� ����� ���������. �������� ����, ������� ������������ ������ ���� �������*/



	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n--------------------------------------------------------------------------\n\nTask2\n\n";
	SetConsoleTextAttribute(hConsole, 7);

	double x, a, b;

	double(*funcPtr[2])(double) = { func1, func2};

	cout << "������� �������� �������� �� ( a ) �� ( b )" << "\n\n-> ";
	cin >> a >> b;
	cout << endl;


	cout << "�������� ������� ��� ������� ��������� ����� x � y : \n" << endl;
	cout << "(1) - ������� y = x*2" << endl;
	cout << "(2) - ������� y = x*2+4" << endl;
	
	int choice = -1;

	while (choice < 1 || choice > 2)
	{
		cout << "\n-> ";
		cin >> choice;
		cout << endl;

		if (choice < 1 || choice > 2)
			cout << "��������� �������� ���, ��������� �����...\n";
	}

	cout << endl << "��������� : " << funcPtr[choice - 1](a) << endl;


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
