#include <iostream>
#include<clocale>
using namespace std;
void isNatural(float n)
{
	if (n > 0 && floor(n) == n);
	else exit;
}
int summa(int m)
{
int sum = 0;
		while (m > 0)
		{
			sum += m % 10;
			m /= 10;
		}
		return sum;
}
int main()
{
	setlocale(0, "");
	float k;
	cout << "Введите число: ";
	cin >> k;
	isNatural(k);
	cout << "Сумма цифр числа равна " << summa(k) << endl;
	system("pause");
	return 0;
}