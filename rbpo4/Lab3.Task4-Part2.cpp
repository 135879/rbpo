module;
#include <cmath>
module Task4;

double RBPO::Lab3::Task4::f2(int x) 
{
	return x > 3 ? (sin(x) / (x ^ 2 - 9)) : (x ^ 2 + 3 * x + 9); 
}