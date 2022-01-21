#include "Math.h"
#include <cmath>
//Реализуем нахождение НОД
using namespace Math;
//----Реализуем функция нахождение НОД двух чисел
int Math::FindGreatestCommonDivisor(int a, int b)
{
	a = abs(a);
	b = abs(b);
	//std::cout << a << b << std::endl;
	while (a!=0 && b!=0)
	{
		if (a > b)
		{
			a %= b;
		}
		else
			b %= a;

	}
	return a + b;

}
//-------Реализация нахождение НОК двух чисел-----
int Math::FindLeastCommmonMultuple(int a, int b)
{
	int mul = a * b;
	mul *= (mul < 0) ? -1 : 1;//Модул
	return (mul) / FindGreatestCommonDivisor(a, b);
}

//Сложение комплексных чисел
Math::Complex Math::operator+(const Complex& a, const Complex& b)
{
      //Сложение двух ком-чисел
	Complex ans(a.Re() + b.Re(), a.Im() + b.Im());
	return ans;
}
//Вычитание
Math::Complex Math::operator-(const Complex& a, const Complex& b)
{
	Complex ans(a.Re() - b.Re(), a.Im() - b.Im());
	return ans;
}
//И так далее операция над Комплексным
Math::Complex Math::operator*(const Complex& a, const Complex& b)
{
	return Complex((a.Re() * b.Re() - a.Im() * b.Im()), a.Re() * b.Im() + b.Re() * a.Im());
}

Math::Complex Math::operator/(const Complex& a, const Complex& b)
{
	return Complex(((a.Re() * b.Re() +a.Im() * b.Im()))/(b.Re()*b.Re()+b.Im()*b.Im()), (a.Re() * b.Im() + b.Re() * a.Im())/ (b.Re() * b.Re() + b.Im() * b.Im()));
}


Math::Complex::Complex() :m_re(0), m_im(0)
{
 	
}

Math::Complex::Complex(double r, double m)
{
	this->m_im = m;
	this->m_re = r;
}

Math::Complex::Complex(const Complex& cm)
{
	this->m_im = cm.Im();
	this->m_re = cm.Re();
}

Math::Complex::Complex(double d)
{
	this->m_re = d;
	this->m_im = 0.0;
}

Math::Complex Math::Complex::FromAlgebraikForm(double re, double me)
{
	return Complex(re,me);
}

double Math::Complex::Re() const
{
	return this->m_re;
}

double Math::Complex::Im() const
{
	return this->m_im;
}

Math::Complex::operator double()
{

	return this->Re();
}

Math::Complex Math::Complex::operator-()
{
	return Complex(this->m_re*-1,this->m_im*-1);
}

Math::Complex& Math::Complex::operator++()
{
	this->m_re += 1.0;
	return (*this);
}

Math::Complex Math::Complex::operator++(const int)
{
	Complex ans(this->m_re, this->m_im);
	this->m_re += 1.0;
	return ans;
}

Math::Complex& Math::Complex::operator--()
{
	this->m_re -= 1.0;
	return (*this);
}

Math::Complex Math::Complex::operator--(const int)
{
	Complex ans(this->m_re, this->m_im);
	this->m_re -= 1.0;
	return ans;
}

Math::Complex& Math::Complex::operator+=(const Complex& cm)
{
	this->m_re += cm.Re();
	this->m_im += cm.Im();
	return (*this);
}

Math::Complex& Math::Complex::operator-=(const Complex& cm)
{
	this->m_re -= cm.Re();
	this->m_im -= cm.Im();
	return (*this);
}

Math::Complex& Math::Complex::operator*=(const Complex& cm)
{
	double curRe = this->m_re * cm.Re() - this->m_im * cm.Im();
	double curIm = this->m_re * cm.Im() + cm.Re() * this->m_im;
	this->m_re = curRe;
	this->m_im = curIm;
	return (*this);
}

Math::Complex& Math::Complex::operator/=(const Complex& cm)
{
	double curRe = this->m_re * cm.Re() + this->m_im * cm.Im();
	curRe /= (cm.Re() * cm.Re() + cm.Im() * cm.Im());
	double curIm = this->m_re * cm.Im() + cm.Re() * this->m_im;
	curIm /=(cm.Re() * cm.Re() + cm.Im() * cm.Im());
	this->m_re = curRe;
	this->m_im = curIm;
	return (*this);
}
std::ostream& Math::operator<<(std::ostream& out, Complex& cm)
{
	char zn = '+';
	if (cm.Im() < 0)
		zn = '-';
	out << cm.Re() << zn << cm.Im() << "i";
	return out;
}
Math::Complex& Math::Complex::operator=(const Complex& cm)
{
	this->m_re = cm.Re();
	this->m_im = cm.Im();
	return (*this);
}

Math::Rational::Rational()
{
	this->nominator = 0;
	this->denominator = 1;
}

Math::Rational::Rational(int _chs, int _zn)
{
	//Сокрашение 
	this->nominator = _chs;
	this->denominator = _zn;
	int nod=FindGreatestCommonDivisor(_chs, _zn);
	this->denominator /= nod;
	this->nominator /= nod;
	//Нормализация
	if (this->denominator * this->nominator >0)
	{
		this->nominator *= (this->nominator > 0) ? 1 : -1;
		this->denominator *= (this->denominator > 0) ? 1 : -1;
	}
	else if (this->denominator * this->nominator < 0)
	{
		if (denominator < 0)
		{
			this->nominator *= -1;
			denominator *= -1;
		}
	}
}

Math::Rational::Rational(int _chs)
{
	this->nominator = _chs;
	this->denominator = 1;
}

Math::Rational::Rational(double d)
{
   //12.25
	int den = 1;
	int mxCnt = 2;
	while ((d - (int)d != 0)&&(mxCnt!=0))
	{
		mxCnt--;
		den *= 10;
		d *= den;
	}
	d /= 10;
	this->nominator = (int)d;
	this->denominator = den;
	NormalGCD();
}

int Math::Rational::Nominator() const
{
	return this->nominator;
}

int Math::Rational::Denominator() const
{
	return this->denominator;
}

Math::Rational::operator double()
{
	return (this->nominator * 1.0) / (this->denominator * 1.0);
}

Rational Math::Rational::operator-()
{
	return Rational(this->nominator*-1,this->denominator);
}

Rational& Math::Rational::operator++()
{
	this->nominator += (this->denominator);
	NormalGCD();
	return (*this);
}

Rational Math::Rational::operator++(const int)
{
	Rational ans(Nominator(), Denominator());
	this->nominator += (this->denominator);
	NormalGCD();
	return ans;
}

Rational& Math::Rational::operator--()
{
	this->nominator -= (this->denominator);
	NormalGCD();
	return (*this);
}

Rational Math::Rational::operator--(const int)
{
	Rational ans(Nominator(), Denominator());
	this->nominator -= (this->denominator);
	NormalGCD();
	return ans;
}

Rational& Math::Rational::operator+=(const Rational& r)
{
	//НОК
	int nok = FindLeastCommmonMultuple(this->denominator, r.Denominator());
	this->nominator *=(nok)/(this->denominator);
	this->nominator += ((nok/r.Denominator()) * r.Nominator());
	this->denominator = nok;
	NormalGCD();
	return (*this);
}

Rational& Math::Rational::operator-=(const Rational& r)
{
	//НОК
	int nok = FindLeastCommmonMultuple(this->denominator, r.Denominator());
	this->nominator *= (nok) / (this->denominator);
	this->nominator -= ((nok / r.Denominator()) * r.Nominator());
	this->nominator = nok;
	NormalGCD();

	return (*this);
}

Rational& Math::Rational::operator*=(const Rational& r)
{
	this->nominator *= r.Nominator();
	this->denominator *= r.Denominator();
	NormalGCD();
	return (*this);
}

Rational& Math::Rational::operator/=(const Rational& r)
{
	this->nominator *= r.Denominator();
	this->denominator *= r.Nominator();
	NormalGCD();
	return (*this);
}

Rational Math::operator+(const Rational& a, const Rational& b)
{
   //НОК
	int nok = FindLeastCommmonMultuple(a.Denominator(), b.Denominator());
	int nka = nok / a.Denominator();
	int nkb = nok / b.Denominator();
	return Rational(a.Nominator() * nka + b.Nominator() * nkb, nok);
}

Rational Math::operator-(const Rational& a, const Rational& b)
{
	//НОК
	int nok = FindLeastCommmonMultuple(a.Denominator(), b.Denominator());
	int nka = nok / a.Denominator();
	int nkb = nok / b.Denominator();
	return Rational(a.Nominator() * nka - b.Nominator() * nkb, nok);
}

Rational Math::operator*(const Rational& a, const Rational& b)
{
	return Rational(a.Nominator()*b.Nominator(),a.Denominator()*b.Denominator());
}

Rational Math::operator/(const Rational& a, const Rational& b)
{
	return Rational(a.Nominator() * b.Denominator(), a.Denominator() * b.Nominator());
}
//Проверка на равенство
bool Math::operator==(const Rational& a, const Rational& b)
{
	return (a.Nominator() == b.Nominator() && a.Denominator() == b.Denominator());
}

bool Math::operator<(const Rational& a, const Rational& b)
{
	//Преведем к обшему знаминателю
	int nok = FindLeastCommmonMultuple(a.Denominator(), b.Denominator());
	int ka = a.Nominator() * (nok / a.Denominator());
	int kb = b.Nominator() * (nok / b.Denominator());
	return ka < kb;
}

bool Math::operator>(const Rational& a, const Rational& b)
{
	int nok = FindLeastCommmonMultuple(a.Denominator(), b.Denominator());
	int ka = a.Nominator() * (nok / a.Denominator());
	int kb = b.Nominator() * (nok / b.Denominator());
	return ka > kb;
}

bool Math::operator<=(const Rational& a, const Rational& b)
{
	int nok = FindLeastCommmonMultuple(a.Denominator(), b.Denominator());
	int ka = a.Nominator() * (nok / a.Denominator());
	int kb = b.Nominator() * (nok / b.Denominator());
	return ka <= kb;
}

bool Math::operator>=(const Rational& a, const Rational& b)
{
	int nok = FindLeastCommmonMultuple(a.Denominator(), b.Denominator());
	int ka = a.Nominator() * (nok / a.Denominator());
	int kb = b.Nominator() * (nok / b.Denominator());
	return ka >= kb;
}

std::ostream& Math::operator<<(std::ostream& out, const Rational& r)
{
	out << r.Nominator() << "/" << r.Denominator();
	return out;
}
