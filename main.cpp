#include "lib.h"
using namespace optimization;
using namespace std;

void main()
{
	int key;
	setlocale(LC_ALL, "Russian");
	cout << "1 - Найти минимум функции\n2 - найти интервал, содержащий минимум функции\n";
	cin >> key;
	if (key == 1)
	{
		Dihotomia A;
		A.Dih();
		Golden_Section B;
		B.Gold();
		Fibonacci C;
		C.Fib();
		printf("Ваше повеление исполнено");
		_getch();
	}
	else
	{
		if (key == 2)
		{
			Algoritm D;
			D.Alg();
		}
		else
		{
			cout << "Перезапустите программу и выберете 1 или 2";
			_getch();
		}
	}
}