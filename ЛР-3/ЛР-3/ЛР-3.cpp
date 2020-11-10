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
	case 1: {
		int K, N, quotient = 0, remainder, dividend;
		cout << "Enter N and K(N/K): " << endl;
		cin >> N >> K;
		if (N < 0 || K <= 0) {
			cout << "Incorrect data!" << endl;
			return 0;
		}
		remainder = N;
		do {
			remainder -= K;
		} while (remainder >= K);

		dividend = N - remainder;
		while (dividend != 0) {
			dividend -= K;
			quotient++;
		}

		cout << "N % K = " << remainder << endl;
		cout << "quotient = " << quotient << endl;

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
		int A;
		double  k = 1.0, sum = 0; // k - divisor

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
	case 4: {
		// поменять - парный-непарный разряд 213 -> 231
		int N, acc = 0;//acc - accumulator, накопитель для нового числа

		cout << "Enter N (N > 1): " << endl;
		cin >> N;

		int nCopy = N, rank = 0; //копия числа и счетчик кол-ва его разрядов начиная с последнего

		if (N <= 0) {
			cout << "Incorrect data!" << endl;
			return 0;
		}

		// накапливаем количество разрядов числа
		while (nCopy >= 1) {
			nCopy /= 10;
			rank++;
		}

		if (rank == 2) { // проверка базового случая, если число из двух цифр - менять нечего, соответственно, нужно вернуть само число
			acc = N;
		}
		else {
			int nexRankN = 0, reverseRankCounter = 0; //nexRankN - значение следующей цифры | reverseRankCounter - счетчик кол-ва разрядов с начала
			nCopy = 0; // обнуляем копию числа, потому что будем считать его по новому
			acc = (N / pow(10, rank - 1)); // устанавливаем начальное значение накопителю(то есть цифру, к которой будут добавляться остальные) - первую цифру оригиального числа, оно не парное и от него ничего не зависит

			while (rank >= 1) {
				reverseRankCounter++; //увеличиваем количество обратных разрядов(rank начинает с последнего, reverseRankCounter - с первого)
				nCopy = (N / pow(10, rank - 1)); // текущий разряд
				nexRankN = (N / pow(10, rank - 2)); // следующий разряд
				nCopy = nCopy % 100 % 10; // N % 100 % 10 - получить последнюю цифру числа текущеко разряда 
				nexRankN = nexRankN % 100 % 10; // последняя цифра числа следующего разряда

				if (!(reverseRankCounter % 2)) { // если разряд парный
					if (nexRankN == 0) acc = acc; // если следующего разряда не существует, ничего не меняем
					else acc = acc * 10 + nexRankN; // накапливаем новое число
					acc = acc * 10 + nCopy;
				}
				rank--; // уменьшаем кол-во разрядов числа, чтобы выйти из цикла, когда они закончатся
			}
		}
		cout << "result = " << acc << endl;
		break;
	}
	case 5: {
		int N, prev = 0, next = 1;
		cout << "Enter N (N > 1): " << endl;
		cin >> N;

		if (N <= 1) {
			cout << "Incorrect data!" << endl;
			return 0;
		}

		int currentF; // для своей последовательности фибоначчи
		do {
			currentF = prev + next;
			prev = next;
			next = currentF;
			if (currentF == N) {
				next += prev;
			}
		} while (currentF != N);

		cout << "prev = " << prev << endl << "next = " << next << endl;
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

