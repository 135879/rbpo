// При необходимости подключить заголовочные файлы, используйте фрагмент глобального модуля (Global Module Fragment).
module;						// Используем технологию "Global Module Fragment" для подключения заголовочных файлов
#include <cmath>			// Подключаем заголовочный файл для вычисления тригонометрических функций
export module Task1;		// Делаем возможным подключение модуля

// Определения функций f1, f2, a, f3, f4 поместить в одну единицу трансляции, описывающую интерфейс модуля (Module Interface Unit – файл с расширением* .ixx).
namespace RBPO
{
	namespace Lab3
	{
		//Экспортировать функции f1, f2, f3, f4. Само пространство имен НЕ экспортировать.
		namespace Task1
		{
			/*
				++	При реализации функции f2 использовать условное выражение (не инструкцию выбора if).d
				++	Функции f3 и f4 реализовать с помощью цикла for.
				++	Определения функций f1, f2, a, f3, f4 поместить в одну единицу трансляции, описывающую интерфейс модуля
						(Module Interface Unit – файл с расширением *.ixx).
				++	Экспортировать функции f1, f2, f3, f4. Само пространство имен НЕ экспортировать.
				++	При необходимости подключить заголовочные файлы, используйте фрагмент глобального модуля (Global Module Fragment).
			*/

			export double f1(int x) { return cos(x) + cos(2 * x) + cos(6 * x) + cos(7 * x); }

			//При реализации функции f2 использовать условное выражение(не инструкцию выбора if).
			export double f2(int x) { return x > 3 ? (sin(x) / (x ^ 2 - 9)) : (x ^ 2 + 3 * x + 9); }


			double a(int i)
			{
				return pow(-1, i) * (1 - pow(i + 1, 2) / pow(i + 2, 2));
			}

			// Функции f3 и f4 реализовать с помощью цикла for.
			export double f3(int x, int n)
			{
				double result = 0.0;
				for (int i = 0; i < n; i++)
					result += a(i);
				return result;
			}

			// Функции f3 и f4 реализовать с помощью цикла for.
			export double f4(int x, double e)
			{
				double total_result = 0.0;
				double previous_result = 0.0;

				//Условие проверки должно быть указано в теле цикла
				for (int i = 0; ; i++)
				{
					double current_result = a(i);
					if (fabs(current_result - previous_result) > e)
					{
						total_result += current_result;
						previous_result = current_result;
						continue;
					}
					else
						break;
				}
				return total_result;
			}
		}
	}
}