// ��� ������������� ���������� ������������ �����, ����������� �������� ����������� ������ (Global Module Fragment).
module;						// ���������� ���������� "Global Module Fragment" ��� ����������� ������������ ������
#include <cmath>			// ���������� ������������ ���� ��� ���������� ������������������ �������
export module Task1;		// ������ ��������� ����������� ������

// ����������� ������� f1, f2, a, f3, f4 ��������� � ���� ������� ����������, ����������� ��������� ������ (Module Interface Unit � ���� � �����������* .ixx).
namespace RBPO
{
	namespace Lab3
	{
		//�������������� ������� f1, f2, f3, f4. ���� ������������ ���� �� ��������������.
		namespace Task1
		{
			/*
				++	��� ���������� ������� f2 ������������ �������� ��������� (�� ���������� ������ if).d
				++	������� f3 � f4 ����������� � ������� ����� for.
				++	����������� ������� f1, f2, a, f3, f4 ��������� � ���� ������� ����������, ����������� ��������� ������
						(Module Interface Unit � ���� � ����������� *.ixx).
				++	�������������� ������� f1, f2, f3, f4. ���� ������������ ���� �� ��������������.
				++	��� ������������� ���������� ������������ �����, ����������� �������� ����������� ������ (Global Module Fragment).
			*/

			export double f1(int x) { return cos(x) + cos(2 * x) + cos(6 * x) + cos(7 * x); }

			//��� ���������� ������� f2 ������������ �������� ���������(�� ���������� ������ if).
			export double f2(int x) { return x > 3 ? (sin(x) / (x ^ 2 - 9)) : (x ^ 2 + 3 * x + 9); }


			double a(int i)
			{
				return pow(-1, i) * (1 - pow(i + 1, 2) / pow(i + 2, 2));
			}

			// ������� f3 � f4 ����������� � ������� ����� for.
			export double f3(int x, int n)
			{
				double result = 0.0;
				for (int i = 0; i < n; i++)
					result += a(i);
				return result;
			}

			// ������� f3 � f4 ����������� � ������� ����� for.
			export double f4(int x, double e)
			{
				double total_result = 0.0;
				double previous_result = 0.0;

				//������� �������� ������ ���� ������� � ���� �����
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