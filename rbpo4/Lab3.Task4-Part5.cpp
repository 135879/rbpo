module;
#include <cmath>
module Task4;

double RBPO::Lab3::Task4::a(int i)
{
	return pow(-1, i) * (1 - pow(i + 1, 2) / pow(i + 2, 2));
}