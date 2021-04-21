#include "pch.h"
#include "piCalc.h"
#include <vector>


double piCalc(int precision)
{
	//In Visual Studio compiler max precision is in double (long double same precision) and equal 15 digits
	if (precision > 15)
		precision = 15;

	double piResult;

	std::vector<double> a(precision+1);
	std::vector<double> t(precision+1);
	std::vector<double> p(precision+1);
	std::vector<double> b(precision+1);

	// initial values
	a[0] = 1.0;
	b[0] = 1.0 / sqrt(2.0);
	t[0] = 1.0 / 4.0;
	p[0] = 1.0;


	for (int i = 1; i <= precision; i++) {
		a[i] = (a[i - 1] + b[i - 1]) / 2.0;
		b[i] = sqrt(a[i - 1] * b[i - 1]);
		t[i] = t[i - 1] - p[i - 1] * pow((a[i - 1] - a[i]), 2);
		p[i] = 2.0 * p[i - 1];

		piResult = pow((a[i] + b[i]), 2) / (4.0 * t[i]);
	}

	return piResult;
}
