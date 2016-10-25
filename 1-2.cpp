#include<iostream>
#include<clocale>
using namespace std;
void isNatural(float n)
{
	int i = 0;
	if (n > 0 && n/floor(n) == 1);
		else exit;
}
void max(int m)
{
	while (true)
	{
		int a[10] = { 0 }, q;
		cin >> m;
		while (m > 0)
		{
			a[m % 10]++;
			m /= 10;
		}
		for (q = 0; q < 5; q++)
			if (a[q])
				m++;
		if (m < 2)
			break;
		for (q = 9; q >= 0; q--)
			while (a[q])
			{
				cout << q;
				a[q]--;
			}
		cout << endl;
	}
}
int main()
{
	setlocale(0, "");
	float a;
	cout << "Ââåäèòå ÷èñëî";
	cin >> a;
	isNatural(a);
	max(a);
	system("pause");
}
