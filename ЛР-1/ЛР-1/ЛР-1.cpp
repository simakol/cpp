#include <iostream>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <cmath>


using namespace std;

//ф-ция проверки целого числа
bool isInt(float num) {
	if (num == round(num)) return true;
	else return false;
}

int main()
{
	int V = (24 % 5) ? 24 % 5 : 5;
	cout << "Variant #" << V << endl;

	int taskN;

	cout << "Enter a number of task: ";
	cin >> taskN;

	switch (taskN)
	{
	case 1:
	{
		cout << "### TASK #1 ###" << endl;
		int firstNumber, secondNumber;
		float result;
		cout << "Enter a first number: ";
		cin >> firstNumber;
		cout << "Enter a second number: ";
		cin >> secondNumber;
		result = (2 * cos(firstNumber) + sqrt(3) * sin(4 * secondNumber) - 1) / (2 * sin(secondNumber * secondNumber) + cos(42) - exp(pow(3, 1 / 3)));
		cout << "Result: " << result << endl;
		break;
	}
	case 2:
	{
		cout << "### TASK #2 ###" << endl;
		int height, radius;
		float volume, square;
		cout << "Enter a radius: ";
		cin >> radius;
		cout << "Enter a height: ";
		cin >> height;
		volume = M_PI * radius * radius * height;
		square = 2 * M_PI * radius * (radius + height);
		cout << "V =  " << volume << endl;
		cout << "S =  " << square << endl;
		break;
	}
	case 3:
	{
		cout << "### TASK #3 ###" << endl;
		int k, p, t;
		cout << "Enter the integer numbers k, p and t in accordance: ";
		cin >> k >> p >> t;
		int tempP = p;
		p = t;
		t = k;
		k = tempP;
		cout << "k become a " << k << endl;
		cout << "p become a " << p << endl;
		cout << "t become a " << t << endl;
		break;
	}
	case 4:
	{
		cout << "### TASK #4 ###" << endl;
		int num, c1, c2, c3;

		cout << "Enter a three-digit number: ";
		cin >> num;
		c1 = num / 100;        // сотни
		c2 = (num % 100) / 10; //десятки
		c3 = (num % 100) % 10; //единицы
		cout << "Result: " << c2 << c1 << c3 << endl;
		break;
	}
	case 5:
	{
		// решил решать следующим образом: во сколько полных пакетов одного типа влезет груз
		cout << "### TASK #5 ###" << endl;

		int userCargo;

		struct PackageType
		{
			int package;
			int box;
			int container;
		};

		struct PackageCount
		{
			int package;
			int box;
			int container;
		};

		cout << "Enter a cargo: ";
		cin >> userCargo;
		int cargo = userCargo; //чтобы не менять исходное значение веса груза, иммутабельные данные

		PackageType package = { 12.0, 60.0, 300.0 };
		PackageCount packageCount = { 0, 0, 0 };

		float packages = cargo / package.package;
		float boxes = cargo / package.box;
		float containers = cargo / package.container;

		// вариант 1
		packageCount.package = !isInt(packages) ? packages : ceil(packages) + 1;
		packageCount.box = !isInt(boxes) ? boxes : ceil(boxes) + 1;
		packageCount.container = !isInt(containers) ? containers : ceil(containers) + 1;

		cout << "We need " << packageCount.package << " packages or  "
			<< packageCount.box << " boxes or " << packageCount.container << " containers to load " << userCargo << "kg of cargo" << endl;
		//конец первого варианта
		// вариант 2 


		break;
	}
	default: {
		cout << "Task " << taskN << " isn't found" << endl;
		break;
	}
	}

	return 0;
}


