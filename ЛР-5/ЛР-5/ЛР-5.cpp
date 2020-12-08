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

void addLeftDigit(int D, int* K) { //змінні покажчики
	int temp = 10;
	while (*K > temp) temp *= 10;
	*K += D * temp;
}

void shiftLeft3(float& a, float& b, float& c) {
	float temp = a;
	a = c;
	c = b;
	b = temp;
}



//int main()
//{
//	for (int i = 1; i <= 2; i++)
//	{
//		float a, b, c;
//		cout << "Enter A, B and C: " << endl;
//		cin >> a >> b >> c;
//		shiftLeft3(a, b, c);
//		cout << a << endl << b << endl << c << endl;
//	}
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
	case 3: {
		int k;
		cout << "Enter k: " << endl;
		cin >> k;

		for (int i = 1; i <= 2; i++) {
			int d;
			cout << "Enter d: " << endl;
			cin >> d;

			addLeftDigit(d, &k);
			cout << k << endl;

		}
		break;
	}
	case 4: {
		for (int i = 1; i <= 2; i++)
		{
			float a, b, c;
			cout << "Enter A, B and C: " << endl;
			cin >> a >> b >> c;
			shiftLeft3(a, b, c);
			cout << a << endl << b << endl << c << endl;
		}
		break;
	}
	case 5: {
		
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