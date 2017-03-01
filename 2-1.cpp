//Линейный конгруэнтный генератор псевдослучайных чисел
#include <iostream>
using namespace std;

double congruent(int &); 

int main()
{
	setlocale(0, "");
	int number;
	cin >> number;
	int x0 = 2; 
	cout << "\n случайные числа:   ";
	for (int i = 0; i <= number; i++)
	{
		cout << congruent(x0) << " ";
	}
	cout << "\n";
	system("pause");
	return 0;
}

double congruent(int &x) 
{
	int zx = rand() % 100;
	//int a=4096, c=150899,m=714025;//
    int m = 100, a = 8, c = 65; 
	x = ((a * zx) + c) % m; 
	x = zx;
	return (x / double(m));
}