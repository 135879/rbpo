//		Module Implementation Unit

/*
++	Функции f3 и f4 реализовать с помощью цикла do … while.Реализации функций должны возвращать те же результаты, что и в предыдущих заданиях.
++	Каждое определение функций f1, f2, a, f3, f4 поместить в отдельную единицу трансляции, описывающую реализацию модуля(Module Implementation Unit).
*/
module;
#include <cmath>
module Task3;

// Каждое определение функций f1, f2, a, f3, f4 поместить в отдельную единицу трансляции, описывающую реализацию модуля(Module Implementation Unit).
double RBPO::Lab3::Task3::f4(int x, double e)
{
	double total_result = 0.0;
	double previous_result = 0.0;
	double current_result = 0.0;
	int i = 0;
	do {
		current_result = a(i);
		total_result += current_result;
		if (fabs(current_result - previous_result) > e)
		{
			previous_result = current_result;
			i++;
			continue;
		}
		else
			break;
	} while (true);
	return total_result;
}