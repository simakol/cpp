#include <iostream>
#include <cmath>

using namespace std;

int sunRange(int A, int B) {
	if (A > B) {
		cout << "Incorrect interval" << endl;
		return 0;
	}

	int sum = 0;

	for (int i = A; i <= B; i++) {
		sum += i;
	}

	return sum;
}


bool isSquare(int K) {
	if (K <= 0) {
		cout << "Incorrect data" << endl;
		return 0;
	}
	bool isSquare = false;
	float root = sqrt(K);

	if ((float)((int)root) == root) { //проверка на целое число
		isSquare = true;
		cout << K << " is square" << endl;
	}
	else cout << K << " isn't square" << endl;

	return isSquare;
}

//int main()
//{
//	float num;
//	cout << "Enter number please" << endl;
//	cin >> num;
//	isSquare(num);
//
//	return 0;
//}

int main()
{
	int V = (29 % 5) ? 29 % 5 : 5;
	cout << "Variant #" << V << endl;

	int taskN;

	cout << "Enter a number of task: ";
	cin >> taskN;

	switch (taskN) {
	case 1: {
		cout << "Enter X, Y and Z(Z > Y > X)" << endl;
		int X, Y, Z;
		cin >> X >> Y >> Z;

		cout << "From X yo Y: " << sunRange(X, Y) << endl;
		cout << "From Y yo Z: " << sunRange(Y, Z) << endl;
		break;
	}
	case 2: {
		float num;
		cout << "Enter number please" << endl;
		cin >> num;
		isSquare(num);

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