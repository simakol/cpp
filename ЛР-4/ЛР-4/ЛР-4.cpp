#include <iostream>
#include <cmath>

using namespace std;

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

	default:
	{
		cout << "Task " << taskN << " isn't exist" << endl;
		break;
	}
	}
	return 0;
}

