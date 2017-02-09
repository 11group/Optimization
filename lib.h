#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <conio.h>

namespace dih
{
	class Dihotomia
	{
		double x1, x2, f1, f2;
		double a = 0., b = 1.;
		double eps = 1E-3;
	public:
		Dihotomia() {};
		~Dihotomia() {};
		double func(double x);
		void Dih();
	};
}

namespace gold
{
	class Golden_Section
	{
		double x1, x2, f1, f2;
		double a = 0., b = 1.;
		double eps = 1E-3;
	public:
		Golden_Section() {};
		~Golden_Section() {};
		double func(double x);
		void Gold();
	};
}

namespace fib
{
	class Fibonacci
	{
		double x1, x2, f1, f2;
		double a = 0., b = 1.;
		double eps = 1E-3;
	public:
		Fibonacci(){};
		~Fibonacci(){};
		double func(double x);
		void Fib();
	};
}
