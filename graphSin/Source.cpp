#include <iostream> 
#include <iomanip> 
#define M_PI 3.14
using namespace std;
int main()
{
	float x = -360, y;
	while (x <= 360)
	{
		y = ((sin(x * M_PI / 90) * 80)/x * 20);
		cout << setw(40 + (y)) << setfill(' ') << '*' << "\n";
		x = x + 5;
	}
	system("pause");
	return 0;
}