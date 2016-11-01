#include<iostream>
#include<clocale>
#include<cmath>
#include<time.h>
using namespace std;
void drawCost1(int a)
{
	switch (a)
	{
	case 1: cout << "+-----+\n" << "|     |\n" << "|  O  |\n" << "|     |\n" <<"+-----+\n"<< endl; break;
	case 2: cout << "+-----+\n" << "|  O  |\n" << "|     |\n" << "|  O  |\n" << "+-----+\n" << endl; break;
	case 3: cout << "+-----+\n" << "|O    |\n" << "|  O  |\n" << "|    O|\n" << "+-----+\n" << endl; break;
	case 4: cout << "+-----+\n" << "|O   O|\n" << "|     |\n" << "|O   O|\n" << "+-----+\n" << endl; break;
	case 5: cout << "+-----+\n" << "|O   O|\n" << "|  O  |\n" << "|O   O|\n" << "+-----+\n" << endl; break;
	case 6: cout << "+-----+\n" << "|O   O|\n" << "|O   O|\n" << "|O   O|\n" << "+-----+\n" << endl; break;
	}
}
void drawCost2(int b)
{
	switch (b)
	{
	case 1: cout << "+-----+\n" << "|     |\n" << "|  O  |\n" << "|     |\n" << "+-----+\n" << endl; break;
	case 2: cout << "+-----+\n" << "|  O  |\n" << "|     |\n" << "|  O  |\n" << "+-----+\n" << endl; break;
	case 3: cout << "+-----+\n" << "|O    |\n" << "|  O  |\n" << "|    O|\n" << "+-----+\n" << endl; break;
	case 4: cout << "+-----+\n" << "|O   O|\n" << "|     |\n" << "|O   O|\n" << "+-----+\n" << endl; break;
	case 5: cout << "+-----+\n" << "|O   O|\n" << "|  O  |\n" << "|O   O|\n" << "+-----+\n" << endl; break;
	case 6: cout << "+-----+\n" << "|O   O|\n" << "|O   O|\n" << "|O   O|\n" << "+-----+\n" << endl; break;
	}
}
void cube1(int &a)
{
	a = rand() % 6 + 1;
	drawCost1(a);
}
void cube2(int &b) 
{
	b = rand() % 6 + 1;
	drawCost2(b);
}
void qGame(int s, int f)
{
	int a = 0,b = 0, i;
	while (s <= 50 && f <= 50)
	{
		if (i=0,i < 2)
		{
			cube1(a);
			cube2(b);
			s += (a + b);
			i++;
			cout << "игрок: " << s << endl;
		}
		if (i = 0, i < 2)
		{
			cube1(a);
			cube2(b);
			f += (a + b);
			i++;
			cout << "компьютер: " << f << endl;
		}
	}
}
void result(int &s, int &f)
{
	if (s > f)
	{
		cout << "вы выиграли" << endl;
	}
	if (s == f)
	{
		cout << "ничья" << endl;
	}
	if (s < f)
	{
		cout << "вы проиграли" << endl;
	}
}
int main()
{
	int s1 = 0, f1 = 0;
	setlocale(0, "");
	qGame(s1,f1);
	result(s1, f1);
	system("pause");
	return 0;
}