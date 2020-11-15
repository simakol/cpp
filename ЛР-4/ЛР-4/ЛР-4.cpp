#include <iostream>
#include <cmath>

using namespace std;

float myPow(float a, float b) { // полифилл функции pow
	float pow = 1;

	for (int i = 1; i <= b; i++) {
		pow *= a;
	}

	return pow;
}

int main()
{
	int V = (20 % 5) ? 20 % 5 : 5;
	cout << "Variant #" << V << endl;

	int taskN;

	cout << "Enter a number of task: ";
	cin >> taskN;

	switch (taskN) {
	case 1: {
		int A, B;
		double sum = 0.0;

		cout << "Enter a border(A, B | A < B)" << endl;
		cin >> A >> B;

		if (A > B) {
			cout << "Incorrect data!" << endl;
			return 0;
		}

		for (int i = A; i <= B; i++) {
			sum += sqrt(i);
		}

		cout << "Sum = " << sum << endl;

		break;
	}
	case 2: {
		int N, square = 0;

		cout << "Enter a number: " << endl;
		cin >> N;

		if (N <= 0) {
			cout << "Incorrect data!" << endl;
			return 0;
		}

		for (int i = 1; i <= 2 * N - 1; i += 2) {
			square += i;
			cout << square << endl; // вывожу квадраты чисел(по условию задания)
		}

		cout << N << "^2 = " << square << endl;

		break;
	}
	case 3: {
		int N, k = -1;
		float A, res = 1.0;

		cout << "Enter A and N (A^N | N > 0): " << endl;
		cin >> A >> N;

		if (N <= 0) {
			cout << "Incorrect data!" << endl;
			return 0;
		}

		for (int i = 2; i <= N; i += 2) {
			res += (myPow(A, i) * k);
			k *= -1;//смена коэфициента(меняем знак)
		}

		cout << res << endl;

		break;
	}
	case 4: {
		int N, k = -1;
		float x;

		cout << "Enter X and N (X^N | N > 0 | |X| < 1): " << endl;
		cin >> x >> N;

		if (N <= 0 || abs(x) >= 1) {
			cout << "Incorrect data!" << endl;
			return 0;
		}

		float res = x;

		for (int i = 3; i <= N; i += 2) {
			res += (myPow(x, i) / i) * k;
			k *= -1;//смена коэфициента(меняем знак)
		}

		cout << res << endl;

		break;
	}
	case 5: {
		int N;
		cout << "Enter N (N > 2): " << endl;
		cin >> N;

		if (N <= 2) {
			cout << "Incorrect data!" << endl;
			return 0;
		}

		int prePrev = 1, prev = 2, current = 3, next;
		cout << "=============" << endl << prePrev << endl << prev << endl << current << endl;//вывожу первые 3 члена;

		for (int i = 1; i <= N - 2; i++) {
			next = (prev + current) - 2 * prePrev;
			prePrev = prev;
			prev = current;
			current = next;

			cout << current << endl;
		}

		break;
	}
	default:
	{
		cout << "Task " << taskN << " isn't exist" << endl;
		break;
	}
	}
	return 0;
}

