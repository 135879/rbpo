//	Module Interface Unit

//���������� ������� f1, f2, f3, f4 ��������� � ������� ����������, ����������� ��������� ������ (Module Interface Unit).
//���������� ������� a �������� �� �����.
//��� ������������� ���������� ������������ �����, ����������� ����������� �������� ����������� ������(Global Module Fragment).
module;
#include <cmath>
export module Task2;

namespace RBPO
{
	namespace Lab3
	{
		//�������������� ������������ ���� RBPO::Lab3::Task2 �������.
		export namespace Task2
		{
			/*
			++	���������� ������� f1, f2, f3, f4 ��������� � ������� ����������, ����������� ��������� ������ (Module Interface Unit). ���������� ������� a �������� �� �����.
			++	�������������� ������������ ���� RBPO::Lab3::Task2 �������.
			++	��� ������������� ���������� ������������ �����, ����������� ����������� �������� ����������� ������ (Global Module Fragment).
			*/
			double f1(int x);
			double f2(int x);
			double f3(int x, int n);
			double f4(int x, double e);
		}
	}
}