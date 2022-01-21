//	Module Implementation Unit

//����������� ������� f1, f2, a, f3, f4 ��������� � ���� ������� ����������, ����������� ���������� ������ (Module Implementation Unit).
module;
#include <cmath>
module Task2;

/*
++	��� ���������� ������� f2 ������������ ���������� ������ if.
++	������� f3 � f4 ����������� � ������� ����� while.
++	����������� ������� f1, f2, a, f3, f4 ��������� � ���� ������� ����������, ����������� ���������� ������ (Module Implementation Unit).
*/

double RBPO::Lab3::Task2::f1(int x) { return cos(x) + cos(2 * x) + cos(6 * x) + cos(7 * x); }

//	��� ���������� ������� f2 ������������ ���������� ������ if.
double RBPO::Lab3::Task2::f2(int x)
{
	double result = 0.0;
	if (x > 3)
		result = (sin(x) / (x ^ 2 - 9));
	else
		result = (x ^ 2 + 3 * x + 9);
	return result;
}


static double a(int i)
{
	return pow(-1, i) * (1 - pow(i + 1, 2) / pow(i + 2, 2));
}

// ������� f3 � f4 ����������� � ������� ����� while.
double RBPO::Lab3::Task2::f3(int x, int n)
{
	double result = 0.0;
	int i = 0;
	while (i < n)
	{
		result += a(i);
		i++;
	}
	return result;
}

// ������� f3 � f4 ����������� � ������� ����� while.
double RBPO::Lab3::Task2::f4(int x, double e)
{
	double total_result = 0.0;
	double previous_result = 0.0;
	int i = 0;
	while (true)
	{
		double current_result = a(i);
		total_result += current_result;
		if (fabs(current_result - previous_result) > e)
		{
			previous_result = current_result;
			i++;
			continue;
		}
		else 
			break;	
	}
	return total_result;
}