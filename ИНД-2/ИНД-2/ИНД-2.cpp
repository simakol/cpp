#include <iostream>
#include <cmath>

using namespace std;

double iterationF(double x) {
	if (x <= 0) {
		cout << "Incorrect data!" << endl;
		return 0;
	}

	double res = 0.0;

	for (int i = 1; i <= x * 2; i += 2) {
		res += pow((x - 1), i) / (i * pow((x + 1), i));
	}
	res *= 2;
	return res;
}

typedef double (*func)(double x);

void tabFunc(float a, float b, float n, func f) {

	for (float i = a; i <= b; i += n) {
		cout << i << " | " << f(i) << endl;
	}
}

int main()
{
	double num;
	cout << "Enter number please: " << endl;
	cin >> num;
	cout << "Value of iteration func: " << iterationF(num) << endl;
	cout << "Value of library func: " << log(num) << endl;

	float a, b, n;
	cout << "Enter a, b and n(a < b): " << endl;
	cin >> a >> b >> n;

	cout << "==================" << endl << "Iteration func: " << endl;
	tabFunc(a, b, n, &iterationF);

	cout << "==================" << endl << "Library func: " << endl;
	tabFunc(a, b, n, &log);

	return 0;
}

