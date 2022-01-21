//		Module Implementation Unit

/*
++	������� f3 � f4 ����������� � ������� ����� do � while.���������� ������� ������ ���������� �� �� ����������, ��� � � ���������� ��������.
++	������ ����������� ������� f1, f2, a, f3, f4 ��������� � ��������� ������� ����������, ����������� ���������� ������(Module Implementation Unit).
*/
module;
#include <cmath>
module Task3;

// ������ ����������� ������� f1, f2, a, f3, f4 ��������� � ��������� ������� ����������, ����������� ���������� ������(Module Implementation Unit).
double RBPO::Lab3::Task3::a(int i)
{
	return pow(-1, i) * (1 - pow(i + 1, 2) / pow(i + 2, 2));
}