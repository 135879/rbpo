//		Module Implementation Unit

/*
++	������� f3 � f4 ����������� � ������� ����� do � while.���������� ������� ������ ���������� �� �� ����������, ��� � � ���������� ��������.
++	������ ����������� ������� f1, f2, a, f3, f4 ��������� � ��������� ������� ����������, ����������� ���������� ������(Module Implementation Unit).
*/

module Task3;

// ������ ����������� ������� f1, f2, a, f3, f4 ��������� � ��������� ������� ����������, ����������� ���������� ������(Module Implementation Unit).
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