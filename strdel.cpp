#include <iostream>
#include <clocale>
using namespace std;
//19(*).В строке удалить слова, заключённые в круглые скобки
char* delstr(char* s, char k, char j) 
{
	int   q;
	char* p, *i, *z = s;

	while (*s && (*s != k))
		++s;

	for (p = s; *s; *s = *p) 
	{
		if (*p == k) 
		{
			q = 0;
			for (i = p; *i; ++i) 
			{
				if (*i == k)
					++q;
				else if (*i == j) 
				{
					if (--q == 0)
						break;
				}
			}

			if (q == 0) 
			{
				p = (*i) ? i + 1 : i;
				continue;
			}
		}
		++s;
		++p;
	}
	return z;
}

int main()
{
	setlocale(0, "");
	char s[100];
	cout << "Введите строку: \n";
	cin.getline(s, 100);
	delstr(s, '(', ')');
	cout << "Изменённая строка: \n" << s << endl;
	system("pause");
	return 0;
}
