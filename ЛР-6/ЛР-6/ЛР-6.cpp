#include <iostream>
using namespace std;


int main()
{
	cout << "Variant #" << (21 + 5) % 5 << endl;
	int task;
	cout << "Enter number of taks: ";
	cin >> task;
	switch (task)
	{
	case 1: {
		//1. Дано цілу константу N (> 0). Сформувати і вивести цілочисельний масив
		// розміру N, що містить N перших додатних непарних чисел : 1, 3, 5, ...
		const int N = 50;
		int arr[N];


		for (int i = 0; i < N; i++) {
			int el;
			for (int k = 1; k <= (i + 1) * 2; k += 2) {
				el = k;
			}
			arr[i] = el;
			cout << i << ": " << arr[i] << endl;
		}
		cout << endl;

		break;
	}
	case 2: {
		//2. Для введення задано цілочисельний масив розміру N.Вивести всі непарні числа,
		//що містяться в даному масиві, в порядку зростання їх індексів, а також їх кількість К.
		const int N = 10;
		int arr[N] = { 1, 5, 9, -6, 8, 2, 77, 56, 85, 20 }, counter = 0;


		for (int i = 0; i < N; i++) {
			if (arr[i] % 2 != 0) {
				cout << arr[i] << " " << endl;
				counter++;
			}
		}
		cout << endl << "Counter = " << counter << endl;
		break;
	}
	case 3: {
		//3. Для введення заданий цілочисельний масив розміру N та ціле число К(0 ≤ К < N).
		//Вивести на екран в порядку спадання індексів елементи масиву, індекси яких кратні до К.Оператор умови не використовувати.

		const int N = 10;
		int arr[N] = { 1, 5, 9, -6, 8, 2, 77, 56, 85, 20 }, K;

		cout << "Enter K(K < length of arr): " << endl;
		cin >> K;

		for (int i = N - 1 - (N - 1) % K; i > 0; i -= K)
		{
			cout << i << ": " << arr[i] << endl;
		}


		break;
	}
	case 4: {
		const int N = 10;
		int arr[N] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 }, d = arr[2] - arr[1];
		//int arr[N] = { 1,3,6,9,12,15,18,21,24,27 }, d = arr[2] - arr[1];



		for (int i = 0; i < N; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;

		for (int i = 0; i < N; i++) {
			int el = arr[1] + d * (i - 1);
			if (i != 0 && arr[i] != el) {
				cout << "It isn's a arithmetic sequence" << endl;
				cout << 0 << endl;
				return 0;
			}
		}

		cout << "d = " << d << endl;
		break;
	}

	case 5: {
		//5. Дано масив розміру N. Знайти номери тих елементів масиву, які більше свого
		//правого сусіда, і кількість таких елементів.Знайдені номера виводити в
		//порядку їх зростання.

		const int N = 10;
		int arr[N] = { 5, 8, 1, 5, 9, 2, 7, 12, 4, 88 }; //1, 4, 7


		for (int i = 0; i < N; i++) {
			cout << arr[i] << " ";
		}

		cout << endl;

		for (int i = 0; i < N; i++) {
			if (i + 1 < N && arr[i] > arr[i + 1])	cout << i << ": " << arr[i] << endl;
		}



		break;
	}

	default: {
		cout << "Task isn't exist!" << endl;
	}
	}
	return 0;
}

