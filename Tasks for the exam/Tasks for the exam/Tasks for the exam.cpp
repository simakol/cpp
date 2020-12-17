#include <iostream>
#include <cmath>

using namespace std;

float f1(float x, int n) { //функция для первой задачи
	int  k = -1, den = 3; //k- коефициент для смены знака, den - знаменатель
	float res = 1.0;
	for (int i = 1; i <= n; i++) {
		res += (pow(x, i) / den) * k;
		k *= -1;
		den += 2;
	}
	return res;
}

int reverseNum(int x) { //функция обратного числа
	int y = 0;
	while (x)
	{
		y = y * 10 + x % 10;
		x /= 10;
	}
	return y;
}

int f2(int k) { //функция для второй задачи
	int samePairingCounter = 0;

	for (int i = 0; i < k; i++) {
		int n, reverseN;
		cout << "Enter number: " << endl;
		cin >> n;
		reverseN = reverseNum(n);

		cout << n << "\t" << reverseN << endl;

		if ((!(n % 2) && !(reverseN % 2)) || ((n % 2) && (reverseN % 2))) {
			samePairingCounter++;
		}
		else {
			continue; // переходим на следующую итерацию цикла
		}
	}

	cout << "Same pairing with enter has " << samePairingCounter << " numbers" << endl;

	return samePairingCounter;
}

float f3(float e) { //функция для второй задачи
	float res = 1.0, prevValue;
	int i = 2, k = -1;

	cout << "e = " << e << endl;
	do {
		prevValue = res;
		res += (1 / float(i)) * k;
		i *= 2;
		k *= -1;
	} while (abs(res - prevValue) > e); // если модуль разницы меньше заданной точности e, то считаем, что значение функции вычислено с точностью e и на этом суммирование прекращаем.

	cout << "y = " << res << endl;
	cout << "===================" << endl;
	return res;
}

int evenNumeralCounter(int n) {
	int evenCounter = 0;

	while (n) {
		int numeral = n % 10;
		n /= 10;
		if (!(numeral % 2)) evenCounter++;
	}
	return evenCounter;
}

float myPow(float a, float b) { // полифилл функции pow
	float pow = 1;

	for (int i = 1; i <= b; i++) {
		pow *= a;
	}

	return pow;
}

int myFactorial(int n) {
	int res = 1;
	for (int i = n; i > 0; i--) {
		res *= i;
	}
	return res;

}

float func(float x, int n) {
	float res = 1;
	for (int i = 1; i <= n; i++) {
		res += myPow(x, i) / (myFactorial(i));
	}

	return res;
}

int main()
{
	int taskN;
	cout << "Enter number of task please: " << endl;
	cin >> taskN;

	switch (taskN)
	{
	case 1: {
		cout << "Task 1" << endl;
		float x, res;
		int n;
		cout << "Enter x: " << endl;
		cin >> x;
		while (x) {
			cout << "Enter n: " << endl;
			cin >> n;

			res = f1(x, n);
			cout << res << endl;

			cout << "Enter x: " << endl;
			cin >> x;
		}
		break;
	}case 2: {
		cout << "Task 2" << endl;
		int k;
		cout << "Enter K: " << endl;
		cin >> k;
		f2(k);
		break;
	}case 3: {
		cout << "Task 3" << endl;
		float e = 1e-1;
		for (int i = 0; i < 10; i++) {
			f3(e);
			e *= 1e-1;
		}
		break;
	}
	case 4: {
		cout << "Task 4" << endl;
		int k, generalCounter = 0;
		cout << "Enter k: " << endl;
		cin >> k;
		for (int i = 0; i < k; i++) {
			int n;
			cout << "Enter n: " << endl;
			cin >> n;

			int evenCounter = evenNumeralCounter(n);
			cout << evenCounter << endl;
			generalCounter += evenCounter;
		}
		cout << "General count: " << generalCounter << endl;
		break;
	}
	case 5: {
		cout << "Task 5" << endl;
		float e = 1e-1;
		for (int i = 0; i < 10; i++) {
			f3(e);
			e *= 1e-1;
		}
		break;
	}
	case 6: {
		cout << "Exam task" << endl;
		float x, res;
		int n;
		cout << "Enter x: " << endl;
		cin >> x;
		while (x) {
			cout << "Enter n: " << endl;
			cin >> n;

			res = func(x, n);
			cout << res << endl;

			cout << "Enter x: " << endl;
			cin >> x;
		}
		break;
	}
	default: {
		cout << "Task #" << taskN << " isn't exist" << endl;
		break;
	}
	}


	return 0;
}

