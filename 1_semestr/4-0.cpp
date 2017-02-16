#include <iostream> 
#include <iomanip> 
void drawSin()
{
	float x, y;
	for (x = -6; x <= 6; y++)
	{
		y = ((sin(2 * (x * 3.14 / 1.5)) * 8) / x * 2);//что это за магические числа 3.14 , 1.5, 8 и 2 функция, то y=sin(2x)/x 
		std::cout << std::setw(40 + (y)) << std::setfill(' ') << '*' << "\n";
		x = x + 0.1;
		if (x == 0)
		{
			x = x + 5;
		}
	}
}
int main()
{
	drawSin();
	system("pause");
}
