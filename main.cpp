#include "lib.h"
using namespace optimization;
using namespace std;

void main()
{
	int key;
	setlocale(LC_ALL, "Russian");
	cout << "1 - ����� ������� �������\n2 - ����� ��������, ���������� ������� �������\n";
	cin >> key;
	if (key == 1)
	{
		Dihotomia A;
		A.Dih();
		Golden_Section B;
		B.Gold();
		Fibonacci C;
		C.Fib();
		printf("���� ��������� ���������");
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
			cout << "������������� ��������� � �������� 1 ��� 2";
			_getch();
		}
	}
}