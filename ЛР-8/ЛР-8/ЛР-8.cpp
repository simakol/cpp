#include <iostream>
#include <cmath>
#include <fstream> 
#include <string> 


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
		// 1. Задане число N і набір з N додатних дійсних чисел. Вивести на екран для
		// кожного числа з набору значення, якого йому не вистачає до найближчого
		//	більшого до нього цілого, а також число, яке є найближчим до свого більшого

		ifstream file;
		file.open("d:\\Users\\Alex\\Desktop\\`\\Универ\\АИП\\cpp\\ЛР-8\\ЛР-8\\files\\task1.txt");
		int N;
		file >> N;
		double* pArr = new double[N], * pFractionalPartArr = new double[N];

		for (int i = 0; i < N; i++) {
			double el;
			file >> el;
			cout << el << " ";
			pArr[i] = el;
		}
		cout << endl;



		for (int i = 0; i < N; i++) {
			double numDiff = ceil(pArr[i]) - pArr[i];
			cout << pArr[i] << " -> " << ceil(pArr[i]) << " | We need to add " << numDiff << " to get closest bigger integer" << endl;
			pFractionalPartArr[i] = 1 - numDiff;
		}

		int maxIndex = 0;
		for (int i = 0; i < N; i++) {
			if (pFractionalPartArr[i] > pFractionalPartArr[maxIndex]) maxIndex = i;
		}

		cout << pArr[maxIndex] << " is closest to bigger integer " << ceil(pArr[maxIndex]) << endl;
		file.close();
		break;
	}
	case 2: {
		// 2. Заданий набір ненульових цілих чисел. Вивести суму всіх додатних парних
		// чисел з даного набору. Якщо необхідні числа в наборі відсутні, то вивести 0.
		ifstream file;
		file.open("d:\\Users\\Alex\\Desktop\\`\\Универ\\АИП\\cpp\\ЛР-8\\ЛР-8\\files\\task2.txt");
		int sum = 0;
		while (!file.eof()) { //пока файл не закончился
			int el;
			file >> el;
			cout << el << " ";
			if (el > 0 && !(el % 2)) sum += el;
		}
		cout << endl << sum << endl;
		file.close();
		break;
	}
	case 3: {
		// 3. Задані цілі числа K, N, а також K наборів по N цілих чисел в кожному наборі.
		// Для кожного набору виконати таку дію : якщо в наборі міститься число 2, то
		// вивести суму його елементів; якщо в наборі немає двійок, то вивести 0.

		ifstream file;
		file.open("d:\\Users\\Alex\\Desktop\\`\\Универ\\АИП\\cpp\\ЛР-8\\ЛР-8\\files\\task3.txt");
		int K, N;
		file >> K >> N;
		int** pMatrix = new int* [K];

		// заполнение и вывод матрицы
		for (int i = 0; i < K; i++) {
			pMatrix[i] = new int[N];
			for (int k = 0; k < N; k++) {
				int el;
				file >> el;
				cout.width(4);
				cout << el << " | ";
				pMatrix[i][k] = el;

			}
			cout << endl;
		}

		for (int i = 0; i < K; i++) {
			int sum = 0;
			for (int k = 0; k < N; k++) {
				if (pMatrix[i][k] == 2) {
					for (int j = 0; j < N; j++) {
						sum += pMatrix[i][j];
					}
					break;
				}
				else sum = 0;
			}
			cout << i << ": " << sum << endl;
		}
		file.close();
		break;
	}
	case 4: {
		// 4. Задані ціле число K, а також K наборів ненульових цілих чисел. Кожен набір
		// містить не менше двох елементів, ознакою його завершення є число 0. Знайти
		// кількість наборів, елементи яких зростають.
		ifstream file;
		file.open("d:\\Users\\Alex\\Desktop\\`\\Универ\\АИП\\cpp\\ЛР-8\\ЛР-8\\files\\task4.txt");
		int sequenceAmount;
		file >> sequenceAmount;
		int growSequenceCounter = sequenceAmount;
		int el, prevEl;

		for (int i = 0; i < sequenceAmount; ++i) {
			file >> el;

			while (el != 0) {
				prevEl = el;
				file >> el;
				if ((el != 0) && (el <= prevEl)) {
					growSequenceCounter--;
					break;
				}
			}
		}
		cout << endl;
		cout << "Quantity of sequences that grows: " << growSequenceCounter << endl;

		file.close();
		break;
	}
	}
}
