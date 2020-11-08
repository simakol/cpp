#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int V = (8 % 5) ? 8 % 5 : 5;
	cout << "Variant #" << V << endl;

	int taskN;

	cout << "Enter a number of task: ";
	cin >> taskN;

	switch (taskN) {
	case 1: {//TODO: ДОДЕЛАТЬ!!
		int K, N, quotient, remainder;
		cout << "Enter N and K(N/K): " << endl;
		cin >> N >> K;
		quotient = N;
		do {
			quotient -= K; // %
		} while (quotient >= K);
		cout << "N % K = " << quotient << endl;
		break;
	}
	case 2: {
		int N, k = 1;
		cout << "Enter N (N > 1): " << endl;
		cin >> N;
		if (N <= 1) {
			cout << "Incorrect data!" << endl;
			return 0;
		}
		while (pow(3, k) <= N) {
			k++;
		}
		cout << "3^" << k << "(" << pow(3, k) << ") > " << N << endl;

		break;
	}
	case 3: {
		double A, k = 1.0, sum = 0; // k - divisor

		cout << "Enter A (A > 1): " << endl;
		cin >> A;

		if (A <= 1) {
			cout << "Incorrect data!" << endl;
			return 0;
		}

		while (A > sum) {
			if (sum + (1 / k) >= A) break;
			k++;
			sum += (1 / k);
			cout << sum << " | " << k << endl;
		}
		cout << "Max divisor(k) = " << k << endl;
		cout << "Sum = " << sum << endl;
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

