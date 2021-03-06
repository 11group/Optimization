#include "lib.h"
namespace optimization
{
	
	///////////////////////////////////////////////////////
	///////////////////////////////////////////////////////
	//////////////			Дихотомия			///////////
	///////////////////////////////////////////////////////
	///////////////////////////////////////////////////////
	double Dihotomia::func(double x)
	{
		AmountDih++;
		return (pow(x, 4) - x);
		//return pow(x, 2);
	}
	void Dihotomia::Dih()
	{
		setlocale(LC_ALL, "Russian");
		FILE *out = fopen("outputDih.txt", "w");
		int i = 0;
		double delta = eps*0.1;
		double razn = 0;
		double otn;
		fprintf(out, "Номер итерации |   a   |   b   |   b-a   | Отношение\n");
		fprintf(out, "%15d %.15f  %.15f  %.15f  %.15f\n", i, a, b, (b - a), razn);

		while ((b - a) > eps)
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
		fprintf(out, "Минимум = %.15f\nФункция = %.15f\nКоличество вычисления функции: %d", min, a, AmountDih);
		fclose(out);
	}
	
	///////////////////////////////////////////////////////
	///////////////////////////////////////////////////////
	//////////////		Золотое сечение			///////////
	///////////////////////////////////////////////////////
	///////////////////////////////////////////////////////
	double Golden_Section::func(double x)
	{
		AmountGold++;
		return (pow(x, 4) - x);
		//return pow(x, 2);
	}
	void Golden_Section::Gold()
	{
		setlocale(LC_ALL, "Russian");
		FILE *out = fopen("outputGold.txt", "w");
		int i = 0;
		double razn = 0;
		double otn;
		fprintf(out, "Номер итерации |   a   |   b   |   b-a   | Отношение\n");
		fprintf(out, "%15d %.15f  %.15f  %.15f  %.15f\n", i, a, b, (b - a), razn);

		x1 = a + 0.381966011*(b - a);
		x2 = b - 0.381966011*(b - a);

		f1 = func(x1);
		f2 = func(x2);

		while ((b - a) > eps)
		{
			if (f1 <= f2)
			{
				b = x2;
				x2 = x1;
				x1 = a + 0.381966011*(b - a);
				f2 = f1;
				f1 = func(x1);
			}
			else
			{
				a = x1;
				x1 = x2;
				x2 = b - 0.381966011*(b - a);
				f1 = f2;
				f2 = func(x2);
			}
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
		fprintf(out, "Минимум = %.15f\nФункция = %.15f\nКоличество вычисления функции: %d", min, a, AmountGold);
		fclose(out);
	}

	///////////////////////////////////////////////////////
	///////////////////////////////////////////////////////
	//////////////			Фибоначчи			///////////
	///////////////////////////////////////////////////////
	///////////////////////////////////////////////////////
	double Fibonacci::func(double x)
	{
		AmountFib++;
		return x*x;
		//return (pow(x, 4) - x);
	}
	void Fibonacci::Fib()
	{
		setlocale(LC_ALL, "Russian");
		FILE *out = fopen("outputFib.txt", "w");
		int i = 0, n = 2;
		double razn = 0;
		double otn, Fn = 0;
		F.push_back(1);
		F.push_back(1);
		fprintf(out, "Номер итерации |	   a	 |		 b		  |		 b-a	  |	 Отношение\n");
		fprintf(out, "%15d %.15f  %.15f  %.15f  %.15f\n", i, a, b, (b - a), razn);
		
		//Найдем F(n+2), F(n) и F(n+1) 
		for (; ((b - a) / eps) > Fn; n++)
		{
			Fn = F[n-2] + F[n-1];
			F.push_back(Fn);
		} 
		n = n - 3;

		x1 = a + (F[n] / F[n + 2])*(b - a);
		x2 = a + (F[n + 1] / F[n + 2])*(b - a);
		f1 = func(x1);
		f2 = func(x2);
		
		//Ищем минимум 
		for (i = 1; i<n; i++)
		{
			if (f1 <= f2)
			{
				b = x2;
				x2 = x1;
				x1 = a + F[n - i + 1] * (b - a) / F[n - i + 3];
				f2 = f1;
				f1 = func(x1);
			}
			else
			{
				a = x1;
				x1 = x2;
				x2 = a + F[n - i + 2] * (b - a) / F[n - i + 3];
				f1 = f2;
				f2 = func(x2);
			}
			otn = razn / (b - a);
			razn = b - a;
			fprintf(out, "%15d %.15f  %.15f  %.15f  %.15f\n", i, a, b, (b - a), otn);
		}
		double min;
		if (a < b)
			min = a;
		else min = b;
		a = func(min);
		fprintf(out, "Минимум = %.15f\nФункция = %.15f\nКоличество вычисления функции: %d", min, a, AmountFib);
		fclose(out);
	}

	///////////////////////////////////////////////////////
	///////////////////////////////////////////////////////
	//////////////			Алгоритм			///////////
	///////////////////////////////////////////////////////
	///////////////////////////////////////////////////////
	double Algoritm::func(double x)
	{
		return x*x;
		return (pow(x, 4) - x);
		//return -x/exp(x);
	}

	void Algoritm::Alg()
	{
		bool key = true;
		setlocale(LC_ALL, "Russian");
		FILE *out = fopen("outputAlg.txt", "w");
		std::cout << "Введите начальную точку: ";
		std::cin >> x0;
		
		//Находим направление движения
		f1 = func(x0);
		f2 = func(x0 + eps);
		if (f1 > f2)
		{
			x1 = x0 + eps;
			h = eps;
		}
		else
		{
			x1 = x0 - eps;
			h = -eps;
		}

		//Ищем интервал
		while (key == true)
		{
			h += h;
			x2 = x1 + h;
			f1 = func(x1);
			f2 = func(x2);
			if (f1 > f2)
				x1 = x2;
			else
				key = false;
		}
		std::cout << "Интервал с минимумом функции:\n";
		if (h >= 0)
		{
			std::cout << "[ " << x1 - h / 2 << " ; " << x2 << " ]";
			fprintf(out, "[%.15f;%.15f", x1 - h / 2, x2);
		}
		else
		{
			std::cout << "[ " << x2 << " ; " << x1 - h / 2 << " ]";
			fprintf(out, "[ %.15f ; %.15f ]", x2, x1 - h / 2);
		}
		fclose(out);
		_getch();
	}
}
