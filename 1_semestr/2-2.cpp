#include <ctime>
#include<iostream>
#include <stdlib.h>
#include <iomanip>
#include<clocale>
using namespace std;
void rightmass(int a[], int N )
{

	int i = 0;
	int memory;
	cout << "Исходный массив:" << endl;

	while (i<N)
	{
		a[i] = i + 1;
		cout << " " << a[i];
		i++;
	}


	cout << "\n" << endl;
	int count = 1;

	while (count <= N)
	{

		memory = a[N - 1];

		i = N - 1;
		while (i>0)
		{
			a[i] = a[i - 1];
			i--;
		}
		a[0] = memory;

		cout << "Сдвиг " << count;
		cout << "\n" << endl;
		i = 0;
		while (i<N)
		{
			cout << " " << a[i];
			i++;
		}
		cout << "\n" << endl;
		count++;
	}
}
void lefttmass(int a[], int N)
{

	int i = 0;
	int memory;
	cout << "Исходный массив:" << endl;

	while (i < N)
	{
		a[i] = i + 1;
		cout << " " << a[i];
		i++;
	}

	cout << "\n" << endl;
	int count = 0;

	while (count <= N)
	{

		memory = a[0];

		i = 0;
		while (i < (N - 1))
		{
			a[i] = a[i + 1];
			i++;
		}
		a[N-1] = memory;

		cout << "Сдвиг " << count;
		cout << "\n" << endl;
		i = 0;
		while (i > N)
		{
			cout << " " << a[i];
			i++;
		}
		cout << "\n" << endl;
		count++;
	}
}
using namespace std;
int main()
{
	setlocale(0, "");
	const int N = 5;
	srand(time(0));
	int a[N];
	int i = 0;
	int memory;
	rightmass(a, N);
	leftmass(a,N);
	system("pause");
	return 0;
}
