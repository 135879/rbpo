#ifndef __MATH_H__


#pragma once
#include <iostream>
namespace Math
{
	int FindGreatestCommonDivisor(int a, int b);//НОД двух чисел
	int FindLeastCommmonMultuple(int a, int b);//НОК двух чисел
	//Реализуем класс Комплексных чисел
	class Complex
	{
	private:
		double m_re;//Реальный часть
		double m_im;//Мнимой часть
	public:
		Complex();//Конструктор по умолчание
		Complex(double r, double m);//Конструктор инициализация
		Complex(const Complex& cm);
		explicit Complex(double d);//Конструктор инициализация переобразование
		static Complex FromAlgebraikForm(double re, double me);//Статическая функция возврашает Комплексное число
		double Re()const;//Возврашет реалиьную часть комплексного числа
		double Im()const;//Возврашает мнимую часть комплексного числа
		explicit  operator double();
		Complex operator-();
		Complex& operator++();//Префиксная форма инкремент
		Complex operator++(const int);//Постфиксная инкремент
		Complex& operator--();//Префиксная декремент
		Complex operator--(const int);//Постфиксная декремент
		Complex& operator+=(const Complex& cm);
		Complex& operator-=(const Complex& cm);
		Complex& operator*=(const Complex& cm);
		Complex& operator/=(const Complex& cm);
		Complex& operator=(const Complex& cm);//Оператор присваивания 
		//Дполнительно 
		bool operator==(const Complex& cm)
		{
			return  (this->m_re == cm.Re() && this->m_im == cm.Im());
		}
		friend Complex operator+(const Complex& a, const Complex& b);
		friend Complex operator-(const Complex& a, const Complex& b);
		friend Complex operator*(const Complex& a, const Complex& b);
		friend Complex operator/(const Complex& a, const Complex& b);
		//Не понятно как перегрузит ""i
		//Реализация оператора потокогово вывода сразу а то не компилируется 
		friend std::ostream& operator<<(std::ostream& out, Complex& cm);
		
	};
	std::ostream& operator<<(std::ostream& out, Complex& cm);
	Complex operator+(const Complex& a, const Complex& b);
	Complex operator-(const Complex& a, const Complex& b);
	Complex operator*(const Complex& a, const Complex& b);
	Complex operator/(const Complex& a, const Complex& b);

	//Начинаем реализовать следуюшый класс Для Рациональних чисел
	class Rational
	{
	private:
		int nominator;//Числитель
		int denominator;//Знаминатель
		//Допольнительное функция для нормализация
		void NormalGCD()
		{
			int nod = FindGreatestCommonDivisor(nominator, denominator);
			nominator /= nod;
			denominator /= nod;
		}
	public:
		Rational();//Конструктор по умолчание
		Rational(int _chs, int _zn);//инициализация
		Rational(int _chs);//Конструктор переобразование
		//Реализуем переобразование в дробную чисел
		Rational(double d);
		int Nominator()const;//Возврашает числитель
		int Denominator()const;//Возврашает знаминатель

		explicit operator double();//Переобразование в double
		Rational operator-();
		Rational& operator++();//Префикс 
		Rational operator++(const int);//Постфикс
		Rational& operator--();//
		Rational operator--(const int);//
		Rational& operator+=(const Rational& r);//
		Rational& operator-=(const Rational& r);//
		Rational& operator*=(const Rational& r);//
		Rational& operator/=(const Rational& r);//
		friend Rational operator+(const Rational& a, const Rational& b);//сложение
		friend Rational operator-(const Rational& a, const Rational& b);//вычитание
		friend Rational operator*(const Rational& a, const Rational& b);//Умножение
		friend Rational operator/(const Rational& a, const Rational& b);//Деление
		friend bool operator==(const Rational& a, const Rational& b);//Сравнение 
		friend bool operator<(const Rational& a, const Rational& b);//Сравнение 
		friend bool operator>(const Rational& a, const Rational& b);//Сравнение 
		friend bool operator<=(const Rational& a, const Rational& b);//Сравнение 
		friend bool operator>=(const Rational& a, const Rational& b);//Сравнение 
		friend std::ostream& operator<<(std::ostream& out, const Rational& r);
	};
	 Rational operator+(const Rational& a, const Rational& b);
	 Rational operator-(const Rational& a, const Rational& b);
	 Rational operator*(const Rational& a, const Rational& b);
	 Rational operator/(const Rational& a, const Rational& b);
	 bool operator==(const Rational& a, const Rational& b);//Сравнение 
	 bool operator<(const Rational& a, const Rational& b);//Сравнение 
	 bool operator>(const Rational& a, const Rational& b);//Сравнение 
	 bool operator<=(const Rational& a, const Rational& b);//Сравнение 
	 bool operator>=(const Rational& a, const Rational& b);//Сравнение 
	 std::ostream& operator<<(std::ostream& out, const Rational& r);
}
#endif // !__MATH_H__