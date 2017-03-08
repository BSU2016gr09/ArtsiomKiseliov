#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <clocale>
// Игра в пятнадцать.
using namespace std;
const int SIZE = 4;
int board[SIZE][SIZE];

void cleanBoard();
bool check();
bool checkBoard();
void showBoard();
void changeBoard();
void fillBoard();
void mainMenu();
void Game();

int main()
{
	mainMenu();
	return 0;
}

void mainMenu()
{
	setlocale(0, "");
	system("cls");
	cout << "\t Игра в пятнадцать"<< endl;

	cout << "\tНажмите 1 чтобы начать игру\n"
		<< "\tНажмите 2 чтобы выйти\n";
	bool y = 0;
	int choice;
	while (!y)
	{
		cout << ">";
		cin >> choice;

		if (choice < 1 || choice > 2)
			cout << "Неверное значение. Повторите попытку." << endl;
		else
			y = 1;
	}

	switch (choice)
	{
	case 1:
		Game();
		break;
	case 2:
		exit(0);
	}
}

void Game()
{
	do
	{
		cleanBoard();
		fillBoard();
	} while (!check());

	int turns = 0;
	while (!checkBoard())
	{
		showBoard();
		changeBoard();
		turns++;
	}
	cout << "Вы выиграли "<< turns << " вернуться." << endl;
	system("pause");
}

void cleanBoard()
{
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			board[i][j] = 0;
}

bool check()
{
	int solution[SIZE*SIZE] = { 0 };
	int index = 0;
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++, index++)
			solution[index] = board[i][j];
	int inv = 0;
	for (int i = 0; i < SIZE*SIZE; i++)
		if (solution[i])
			for (int j = 0; j < i; j++)
				if (solution[j] > solution[i])
					++inv;
	for (int i = 0; i < SIZE*SIZE; i++)
		if (solution[i] == 0)
			inv += 1 + i / 4;
	return (inv & 1) ? 0 : 1;
}

bool checkBoard()
{
	int count = 1;
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++, count++)
		{
			if (i == SIZE - 1 && j == SIZE - 1 && board[i][j] == 0) break;
			if (board[i][j] != count)
				return 0;
		}
	return 1;
}

void showBoard()
{
	system("cls");
	cout << "Игра Пятнадцать" << endl;

	for (int i = 0; i < SIZE; i++)
	{
		cout << "-------------" << endl;
	    cout << "|";
		for (int j = 0; j < SIZE; j++)
		{
			cout << left << setw(4) << board[i][j] << "|";
		}
		cout << endl;
	}
	cout << "-------------" << endl;
}

void changeBoard()
{
	bool y = 0;
	while (!y)
	{
		int turn = 0;
		do
		{
			cout << ">";
			cin >> turn;
		} while (turn < 0 || turn > 15);

		if (turn == 0)
		{
			mainMenu();
			return;
		}
		int ox = 0;
		int oy = 0;
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				if (board[i][j] == turn)
				{
					ox = i;
					oy = j;
				}
		int dx[] = { 0, 0, 1, -1 };
		int dy[] = { 1, -1, 0, 0 };
		for (int i = 0; i < 4; i++)
		{
			int newx = ox + dx[i];
			int newy = oy + dy[i];
			if (newx < 0 || newx > SIZE - 1 ||
				newy < 0 || newy > SIZE - 1)
				continue;
			if (board[newx][newy] == 0)
			{
				board[newx][newy] = turn;
				board[ox][oy] = 0;
				y = 1;
				break;
			}
		}
		if (!y)
			cout << "Неверное значение. Повторите попытку." << endl;
	}
}

void fillBoard()
{
	bool already[15] = { 0 };
	int count = 1;
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++, count++)
		{
			if (i == SIZE - 1 && j == SIZE - 1)
				break;
			while (true)
			{
				int randNum = rand() % 15;
				if (!already[randNum])
				{
					already[randNum] = 1;
					board[i][j] = randNum + 1;
					break;
				}
			}
		}
}