module;
#include <cmath>
module Task4;

import :Part5;

double RBPO::Lab3::Task4::f4(int x, double e)
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