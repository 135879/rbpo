module Task4;

import :Part5;

double RBPO::Lab3::Task4::f3(int x, int n)
{
	double result = 0.0;
	int i = 0;
	do
	{
		result += a(i);
		i++;
	} while (i < n);
	return result;
}