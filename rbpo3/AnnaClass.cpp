#include <iostream>
#include "Math.h"
#include <cmath>
using namespace std;
using namespace Math;

//-----------Реализуем пользовательских функции--------------
Complex f(const Complex& z)
{
	//Находим пятый  степени
	Complex a(1, 0);
	Complex u5 = z;
	for (int i = 0; i < 4; i++)
		u5 *= z;
	Complex cm(2.0);
	Complex tnh(tanh((double)(z / cm)));
	Complex ans = a - u5;
	ans -= tnh;
	return ans;
}
Rational f(const Rational& r)
{
	Rational a(1, 1);
	Rational u5 = r;
	for (int i = 0; i < 4; i++)
		u5 *= r;
	Rational two(2,1);
	Rational th(tanh((double)(r / (two))));
	Rational ans = a - u5;
	ans =ans-th;
	return ans;
}
double f(double x)
{
	double a = 1.0;
	double x5 = x;
	for (int i = 0; i < 4; i++)
		x5 *= x;
	a -= x5;
	a -= (tanh(x / 2.0));
	return a;
}
int main()
{
    Complex num(2.0,0);
	Complex dur = f(num);
	Rational rat(4, 2);
	Rational ru=f(rat);
	double x = 2.0;
	x = f(x);
	cout << dur << endl;
	cout << ru << endl;
	cout << x << endl;
	return 0;
}
