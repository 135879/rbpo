//	Module Interface Unit

//ќбъ€влени€ функций f1, f2, f3, f4 поместить в единицу трансл€ции, описывающую интерфейс модул€ (Module Interface Unit).
//ќбъ€вление функции a помещать не нужно.
//ѕри необходимости подключить заголовочные файлы, используйте используйте фрагмент глобального модул€(Global Module Fragment).
module;
#include <cmath>
export module Task2;

namespace RBPO
{
	namespace Lab3
	{
		//Ёкспортировать пространство имен RBPO::Lab3::Task2 целиком.
		export namespace Task2
		{
			/*
			++	ќбъ€влени€ функций f1, f2, f3, f4 поместить в единицу трансл€ции, описывающую интерфейс модул€ (Module Interface Unit). ќбъ€вление функции a помещать не нужно.
			++	Ёкспортировать пространство имен RBPO::Lab3::Task2 целиком.
			++	ѕри необходимости подключить заголовочные файлы, используйте используйте фрагмент глобального модул€ (Global Module Fragment).
			*/
			double f1(int x);
			double f2(int x);
			double f3(int x, int n);
			double f4(int x, double e);
		}
	}
}