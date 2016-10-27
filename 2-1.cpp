#include <ctime>
#include<iostream>
#include <stdlib.h>
#include <iomanip>
#include<clocale>
using namespace std;
const int N = 100;
void normalmas(int a[], int N)
{
int i = 0;
srand(time(0));
cout << "Исходный массив:" << endl;
while (i<N)
{
	a[i] = rand() % 20;
	cout << " " << a[i];
	i++;
}
}
void invertmas(int a[], int N)
{
	int i = 0;
	while (i<N)
	{
		a[i] = rand() % 20;
		cout << " " << a[i];
		i++;
	}
cout << "\nПеревернутый массив:" << endl;
i = N - 1;
     while (i >= 0)
{
	cout << " " << a[i];
	i--;
}
}
int main()
{
	setlocale(0, "");
	const int N = 100;
	int a[N];
	normalmas(a, N);
	invertmas(a, N);
	cout << "\n" << endl;
	system("pause");
	return 0;
}