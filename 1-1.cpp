#include <iostream>
#include <algorithm>
using namespace std;
void sort(double*, int);
void swap(double*, double*);

int main()
{
	setlocale(0,"");
	double* Arr;
	int n;
	cout << "¬ведите размер: ";
	cin >> n;
	Arr = new double[n];
	insert(Arr, n);
	sort(Arr, Arr+n);
	print(Arr, n);
	delete[] Arr;
	Arr = nullptr;
	system ("pause");
}

void insert(double* Arr, int n)
{
	for (int i = 0; i<n; ++i)
		cin >> Arr[i];
}
void print(double* Arr, int n)
{
	for (int i = 0; i<n; ++i)
		cout << Arr[i] << ' ';
}
void sort(double* Arr, int n)
{
	int k;
	cout << "¬ведите k:";
	cin >> k;
	for (; k<n; k++)
	{
		for (int j = k; j<n; j++)
		{
			if (Arr[k] > Arr[j])
			{
				swap(Arr[k], Arr[j]);
		
			}
		}
	}
}

void swap(double* first, double* second)
{
	double tmp = *first;
	*first = *second;
	*second = tmp;
}