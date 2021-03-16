
#include <iostream>
#include <Windows.h>

using namespace std;


int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //for hightlight text
	cout << "Variant #" << (21 + 5) % 6 << endl;
	int task;
	cout << "Enter number of taks: ";
	cin >> task;
	switch (task)
	{
	case 1: {
		//1. Сформувати цілочисельну матрицю розміру MхN, у якій всі елементи J-го стовпця мають значення Т · J (J = 0, N-1),
		//де Т задає користувач.
		const int ROWS = 5, COLS = 5;
		int T, arr[ROWS][COLS];
		cout << "Enter T: ";
		cin >> T;

		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				arr[i][j] = T * j;
				cout.width(3);
				cout << arr[i][j] << " | ";

			}
			cout << endl;
		}

		break;
	}
	case 2: {
		//2. Для матриці С розміром NxM обчислити та вивести на екран кількість парних від’ємних елементів.
		const int ROWS = 6, COLS = 6;
		int arr[ROWS][COLS], negativeEvenCounter = 0;
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				arr[i][j] = rand() * fraction * (999 + 999 + 1) - 999;
				if (arr[i][j] < 0 && (arr[i][j] % 2 == 0)) {
					SetConsoleTextAttribute(hConsole, (WORD)((10 << 4) | 15));
					negativeEvenCounter++;
				}
				cout.width(4);
				cout << arr[i][j];
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
				cout << " | ";

			}
			cout << endl;
		}
		cout << "Amount of even neative elements: " << negativeEvenCounter << endl;

		break;
	}
	case 3: {
		//3. Для матриці Н розміром KxT визначити та вивести на екран: 1) суму елементів для кожного рядка;
		//2) добуток елементів для кожного стовпця.
		const int ROWS = 3, COLS = 3;
		int arr[ROWS][COLS] = {
				{5, 10, 15},
				{20, 25, 30},
				{35, 40, 45}
		}, sumOfRows = 0, multiplicationOfCols = 1;

		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				cout.width(3);
				cout << arr[i][j] << " | ";
				sumOfRows += arr[i][j];
				multiplicationOfCols *= arr[j][i];
			}
			SetConsoleTextAttribute(hConsole, (WORD)((5 << 4) | 15));
			cout << "sum of row #" << i << " is: " << sumOfRows;
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
			sumOfRows = 0;
			cout << " | ";

			SetConsoleTextAttribute(hConsole, (WORD)((5 << 4) | 15));
			cout << "multiplication of cols #" << i << " is: " << multiplicationOfCols;
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
			multiplicationOfCols = 1;
			cout << endl;
		}

		break;
	}
	case 4: {
		//4.Дана цілочисельна матриця розміру MхN. 
		//Для кожного рядка матриці знайти кількість елементів, менших ніж середнє арифметичне елементів цього рядка.
		const int ROWS = 5, COLS = 5;
		int arr[ROWS][COLS] = {
				{2,98,25,-9,3},
				{8,74,36,8,-2},
				{20,1,-4,-35,2},
				{85,-14,250,74,32},
				{12,-302,84,33,154},
		};

		for (int i = 0; i < ROWS; i++)
		{
			int sumOfRow = 0;

			for (int j = 0; j < COLS; j++)
			{
				/*cout.width(3);
				cout << arr[i][j] << " | ";*/
				sumOfRow += arr[i][j];
			}
			int average = sumOfRow / COLS;
			int counter = 0;

			for (int j = 0; j < COLS; j++)
			{
				cout.width(4);

				if (arr[i][j] < average) {
					counter++;
					SetConsoleTextAttribute(hConsole, (WORD)((5 << 4) | 15));
					cout << arr[i][j];
					SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
					cout << " | ";
				}
				else {
					cout << arr[i][j] << " | ";
				}
			}

			cout << "Average of row = " << average << " | " << "Counter = " << counter << endl;
			counter = 0;
		}

		break;
	}
	case 5: {
		//5. Дана цілочисельна матриця розміру MхN. Знайти кількість її стовпців, всi елементи яких різні.
		/*const int ROWS = 5, COLS = 5;
		int arr[ROWS][COLS] = {
				{2,5, 25, 3,3},
				{2,55, 35,3,-2},
				{2,5, -4, 3,2},
				{2,5, 25,3,32},
				{2,5, 84, 3,154},
		}, allColsCounter = 0;

		for (int i = 0; i < ROWS; i++)
		{
			int counterColItem = 0;

			for (int j = 0; j < COLS; j++)
			{
				int startElem = arr[i][i];
				cout.width(4);
				cout << arr[i][j] << " | ";

				if (startElem == arr[j][i]) {
					counterColItem++;
				}

			}
			if (counterColItem > 1) {
				allColsCounter++;
			}
			cout << endl;
		}
		cout << "Diff cols counter = " << allColsCounter << endl;
		break;*/
		const int ROWS = 5, COLS = 5;
		int arr[ROWS][COLS] = {
				{2, 5,  25, 5, 3},
				{2, 52, 35, 3, -2},
				{2, 5,  -4, 3, 2},
				{2, 5,  25, 3, 32},
				{2, 5,  84, 3, 154},
		}, allColsCounter = ROWS;

		for (int i = 0; i < ROWS; i++)
		{

			for (int j = 0; j < COLS; j++)
			{
				//int startElem = arr[j][j];
				//cout.width(4);
				//cout << arr[i][j] << " | ";

				if (arr[j][j] == arr[j + 1][i]) {
					allColsCounter--;
					break;
				}

			}
			//cout << endl;
		}
		cout << "Diff cols counter = " << allColsCounter << endl;
		break;
	}
	default: {
		cout << "Task isn't exist!" << endl;
	}
	}
	return 0;
}
