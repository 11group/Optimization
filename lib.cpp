#include "lib.h"
namespace dih
{
	double Dihotomia::func(double x) //�������, ��� ���
	{
		//return (pow(x, 4) - x);
		return pow(x, 2);
	}
	void Dihotomia::Dih()
	{
		setlocale(LC_ALL, "Russian");
		FILE *out = fopen("output.txt", "w");
		int i = 0;
		double delta = eps*0.1;
		double razn = 0;
		double otn;
		fprintf(out, "����� �������� |   a   |   b   |   b-a   | ���������\n ");
		fprintf(out, "%15d %.15f  %.15f  %.15f  %.15f\n", i, a, b, (b - a), razn);


		while (b - a > eps)
		{
			x1 = (b + a - delta) / 2;
			x2 = (b + a + delta) / 2;
			f1 = func(x1);
			f2 = func(x2);
			if (f1 <= f2)
				b = x2;
			else a = x1;
			i++;
			otn = razn / (b - a);
			razn = b - a;
			fprintf(out, "%15d %.15f  %.15f  %.15f  %.15f\n", i, a, b, (b - a), otn);
		}
		double min;
		if (a < b)
			min = a;
		else min = b;
		a = func(min);
		fprintf(out, "������� = %.15f\n������� = %.15f", min, a);
	}
}