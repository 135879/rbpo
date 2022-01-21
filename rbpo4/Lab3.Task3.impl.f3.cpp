//		Module Implementation Unit

/*
++	Функции f3 и f4 реализовать с помощью цикла do … while.Реализации функций должны возвращать те же результаты, что и в предыдущих заданиях.
++	Каждое определение функций f1, f2, a, f3, f4 поместить в отдельную единицу трансляции, описывающую реализацию модуля(Module Implementation Unit).
*/

module Task3;

// Каждое определение функций f1, f2, a, f3, f4 поместить в отдельную единицу трансляции, описывающую реализацию модуля(Module Implementation Unit).
double RBPO::Lab3::Task3::f3(int x, int n)
{
	double result = 0.0;
	int i = 0;
	do
	{
		result += a(i);
		i++;
	} 
	while (i < n);
	return result;
}