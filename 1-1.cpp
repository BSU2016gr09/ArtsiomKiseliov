//Расположить в порядке возрастания элементы массива А(N), начиная с k-го элемента.
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
	cout << "Ââåäèòå ðàçìåð: ";
	cin >> n;
	Arr = new double[n];
	insert(Arr, n);//Ну что это за имя для функции????
	sort(Arr, Arr+n);//ОППА, разберить ка самостоятельно что за тип выражения  Arr+n!!!!!!
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
	cout << "Ââåäèòå k:";
	cin >> k;
	for (; k<n; k++)
	{
		for (int j = k; j<n; j++)
		{
			if (Arr[k] > Arr[j])
			{
				swap(Arr[k], Arr[j]); //какая колхозная сортировка
		
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
