////////////////////////////////////////////
////////////////////////////////////////////
////	Три метода поиска минимума	////////
////	функции на отрезке			////////
////	и метод поиска интервала	////////
////	содержащего минимум функции ////////
////////////////////////////////////////////


#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <conio.h>
#include <vector>
#include <iostream>

namespace optimization
{
	class Dihotomia
	{
		double x1, x2, f1, f2;
		double a = 0., b = 1.;
		double eps = 1E-14;
	public:
		Dihotomia() {};
		~Dihotomia() {};
		double func(double x);
		void Dih();
	};

	class Golden_Section
	{
		double x1, x2, f1, f2;
		double a = 0., b = 1.;
		double eps = 1E-14;
	public:
		Golden_Section() {};
		~Golden_Section() {};
		double func(double x);
		void Gold();
	};

	class Fibonacci
	{
		double x1, x2, f1, f2;
		double a = 0., b = 3.;
		std::vector <double> F;
		double eps = 1E-14;
	public:
		Fibonacci(){};
		~Fibonacci(){};
		double func(double x);
		void Fib();
	};

	class Algoritm
	{
		double x0, x1, x2, f1, f2;
		double h;
		double eps = 1E-14;
	public:
		Algoritm() {};
		~Algoritm() {};
		double func(double x);
		void Alg();
	};
}
