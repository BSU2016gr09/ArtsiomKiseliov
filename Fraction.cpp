#include <iostream>
#include <clocale>
using namespace std;
// Сделать сумму дробей, произведение дробей.
struct Fraction {//не нравится мне, что не указано в явном виде секция public!!!
       int a;
	   int b;
	   Fraction(int a, int b) {//сделай еще обязательно конструктор без параметров. А то тебе пришлось 10 раз писать Fraction temp(0, 0);
		(*this).a = a;
		(*this).b = b;
	   };
	   void NOD() {//слабо понимаю идею доступности этой функции извне класса. Это вспомогательная ф-ция...
		int a_1 = a;
		int b_1 = b;
		int buf;
		while (b_1 != 0) {
			buf = b_1;
			b_1 = a_1 % b_1;
			a_1 = buf;
		}
		a /= a_1;
		b /= a_1;
	   };
	   void show(){
		int buf = a % b;
		if (!buf) cout << a / b << endl;
		else cout << a << "/" << b << endl;
	   };
};

struct addMultFraction {
	struct Fraction drob1; //в С++ писать тут struct не обязательно
	struct Fraction drob2; 
	addMultFraction(int a, int b, int a1, int b1) : drob1(a, b), drob2(a1, b1) {} //ты разобрался с инициализацией? Или просто скопировал откуда-то????
	friend Fraction operator+(Fraction drob1, Fraction drob2);//не нравится мне, что ты передаешь не по ссылке!!!
	friend Fraction operator*(Fraction drob1, Fraction drob2);//не нравится мне, что ты передаешь не по ссылке!!!
	void show() {
		cout << "Первая дробь: " << drob1.a << "/" << drob1.b << endl;
		cout << "Вторая дробь: " << drob2.a << "/" << drob2.b << endl;
		cout << endl;
	};
};

Fraction operator+(Fraction drob1, Fraction drob2) {
	Fraction temp(0, 0);
	temp.b = drob1.b * drob2.b;
	temp.a = (temp.b / drob1.b) * drob1.a + (temp.b / drob2.b) * drob2.a;
	return temp;
}

Fraction operator*(Fraction drob1, Fraction drob2) {
	Fraction temp(0, 0);
	temp.a = drob1.a * drob2.a;
	temp.b = drob1.b * drob2.b;
	return temp;
}

int main() 
{
	setlocale(0, "");
	Fraction drob0(0, 0);
	addMultFraction drob(10, 4, 5, 9);

	drob.show();

	cout << "Сумма: ";

	drob0 = drob.drob1 + drob.drob2;
	drob0.NOD();
	drob0.show();

	cout << "Произведение: ";

	drob0 = drob.drob1 * drob.drob2;
	drob0.NOD();
	drob0.show();

	system("pause");
	return 0;
}
