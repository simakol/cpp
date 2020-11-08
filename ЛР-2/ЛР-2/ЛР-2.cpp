#include <iostream>
#include <cmath>

using namespace std;

//function for 4th task
int tringleParams(float length)
{
	cout << "a = " << length << "; b = " << length << "; c = " << length * sqrt(2) << "; h = " << length / sqrt(2) << "; S = " << (length * length) / 2 << endl;
	return 0;
}

int main()
{
	setlocale(LC_ALL, "ukrainian");
	int V = (21 % 5) ? 21 % 5 : 5;
	cout << "Варiант №" << V << endl;

	int taskN;

	cout << "Введiть номер завдвння: ";
	cin >> taskN;

	switch (taskN)
	{
	case 1:
	{
		cout << "### Завдання #1 ###" << endl;
		int firstNumber, secondNumber;
		float result;
		cout << "Введiть перше число: ";
		cin >> firstNumber;
		cout << "Введiть друге число: ";
		cin >> secondNumber;
		if (firstNumber <= 0 && secondNumber > 0)
		{
			result = exp(firstNumber * secondNumber * secondNumber);
		}
		else if (firstNumber > 0 && secondNumber > 0 && firstNumber != 1)
		{ // одз логирифма

			result = log(secondNumber) / log(firstNumber); // first number - основа логарифма
		}
		else
		{
			cout << "Неможливо визначити, перевiрте правильнiсть вводу!" << endl;
			break; // конечный ответ, завершение кейса
		}
		cout << "Результат: " << result << endl;

		break;
	}
	case 2:
	{
		cout << "### Завдання #2 ###" << endl;
		int x, y;
		cout << "Введiть x: ";
		cin >> x;
		cout << "Введiть y: ";
		cin >> y;
		if (x * x + y * y >= 4 && x * x + y * y <= 25)
		{
			cout << "Точка з коорданатами " << x << " та " << y << " iснує на графiку" << endl;
		}
		else
		{
			cout << "Точка з коорданатами " << x << " та " << y << " не iснує на графiку" << endl;
		}
		break;
	}
		// Переделать, начиная с этого задания! Сделал не свой вариант!
	case 3:
	{
		cout << "### Завдання #3 ###" << endl;
		int A, B, C, temp;
		cout << "Введiть A: ";
		cin >> A;
		cout << "Введiть B: ";
		cin >> B;
		cout << "Введiть C: ";
		cin >> C;

		if (A > B && A > C)
		{
			//A the biggest
			if (C > B)
			{
				C = B;
			}
			cout << "A = " << A << "; C = " << C << endl;
		}
		else if (B > A && B > C)
		{
			//B the biggest
			if (C > A)
			{
				C = A;
			}
			A = B;
			cout << "A = " << A << "; C = " << C << endl;
		}
		else
		{
			//C the biggest
			temp = C;
			if (A > B)
			{
				C = B;
			}
			else
				C = A;
			A = temp;
			cout << "A = " << A << "; C = " << C << endl;
		}

		break;
	}
	case 4:
	{
		cout << "### Завдання #4 ###" << endl;
		int param;
		float length;
		cout << "Введiть значення: ";
		cin >> length;
		cout << "Введiть значення(1 – катет a, 2 – гiпотенуза с, 3 - висота h, опущена на гiпотенузу, 4 - площа S): ";
		cin >> param;

		switch (param)
		{
		case 1:
		{
			tringleParams(length);
			break;
		}
		case 2:
		{
			length /= sqrt(2);
			tringleParams(length);
			break;
		}
		case 3:
		{
			length *= sqrt(2);
			tringleParams(length);
			break;
		}
		case 4:
		{
			length = sqrt(2 * length);
			tringleParams(length);
			break;
		}
		default:
		{
			cout << "Такого значення не знайдено" << endl;
			break;
		}
		}

		break;
	}
	case 5:
	{
		cout << "### Завдання #5 ###" << endl;
		int mark;
		cout << "Введiть оцiнку: ";
		cin >> mark;
		switch (mark)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		{
			cout << "Незадовiльно" << endl;
			break;
		}
		case 6:
		case 7:
		case 8:
		{
			cout << "Задовiльно" << endl;
			break;
		}
		case 9:
		case 10:
		{
			cout << "Добре" << endl;
			break;
		}
		case 11:
		case 12:
		{
			cout << "Вiдмiнно" << endl;
			break;
		}
		default:
		{
			cout << "Невiрне значення оцiнки!" << endl;
			break;
		}
		}

		break;
	}

	default:
	{
		cout << "Завдання " << taskN << " не знайдено" << endl;
		break;
	}
	}
	return 0;
}
