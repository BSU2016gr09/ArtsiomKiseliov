#include <ctime>
#include<iostream>
#include <stdlib.h>
#include <iomanip>
#include<clocale>
using namespace std;
// Массив целых чисел размера N проинициализировать случайными числами из промежутка от 1 до N. "Перевернуть" массив (последний элемент станет первым, 1-й станет последним, 2-й поменяется с предпоследним и т.д.) 
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
