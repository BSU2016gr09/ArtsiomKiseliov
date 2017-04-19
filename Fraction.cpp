#include <iostream>
#include <clocale>
using namespace std;
//Сделать сумму и произведение дробей.
struct Fraction {
public:
	int a;//я же говорил: Плохо, что это public
	int b;//я же говорил: Плохо, что это public
	Fraction(): a (0), b(0) {};//Плохо совсем, что знаменатель у вас равен НУЛЮ!!!! Вы не учились в 3-м классе????
	Fraction(int a, int b) {//тут тоже стоит использовать список инициализации!!!
		(*this).a = a;//тут надо проверки на знак 
		(*this).b = b;//тут надо проверки на знак и на равенство нулю
		cout << "Работает конструктор\n";
	};
	void NOD() {
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
	void show() {
		int buf = a % b;
		if (!buf) cout << a / b << endl;
		else cout << a << "/" << b << endl;
	};
	~Fraction() {
		cout << "Работает деструктор\n";
	};
};

struct addMultFraction {//тут вообще не понимаю что это и зачем. На паре мне расскажете свою идею
	Fraction drob1;
	Fraction drob2;
	addMultFraction(int a, int b, int a1, int b1) : drob1(a, b), drob2(a1, b1) {}
	friend Fraction& operator+(Fraction &drob1, Fraction &drob2);
	friend Fraction& operator*(Fraction &drob1, Fraction &drob2);
	void show() {
		cout << "Первая дробь: " << drob1.a << "/" << drob1.b << endl;
		cout << "Вторая дробь: " << drob2.a << "/" << drob2.b << endl;
		cout << endl;
	};
};

Fraction& operator+(Fraction &drob1, Fraction &drob2) {
	Fraction * temp = new Fraction;
	(*temp).b = drob1.b * drob2.b;
	(*temp).a = (((*temp).b) / drob1.b) * drob1.a + (((*temp).b) / drob2.b) * drob2.a;
	return *temp;
}

Fraction& operator*(Fraction &drob1, Fraction &drob2) {
	Fraction * temp = new Fraction;
	(*temp).a = drob1.a * drob2.a;
	(*temp).b = drob1.b * drob2.b;
	return *temp;
}

int main()
{
	setlocale(0, "");
	Fraction drob0;
	addMultFraction drob(14, 4, 5, 9);

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
