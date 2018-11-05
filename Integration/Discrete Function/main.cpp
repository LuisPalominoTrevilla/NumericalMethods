#include <iostream>
#include <string>
#include "DiscreteFunction.h"

#define WINPAUSE system("pause")

using namespace std;

int main() {

	int n = 100; // 5 intervalos (6 puntos)
	double *x = new double[n + 1];
	double *y = new double[n + 1];
	double a = 0.;
	double b = 1.;
	double h = (b - a) / n;
	double xx = a;
	for (int i = 0; i <= n; i++) {
		x[i] = xx;
		y[i] = pow(2.71828182, pow(x[i], 2));
		xx += h;
	}
	DiscreteFunction *df1 = new DiscreteFunction(n+1, x, y);
	cout << "A-Riemann = " << df1->riemann(a, b, n) << endl;
	cout << "A-Trapezoid = " << df1->trapezoide(a, b, n) << endl;
	cout << "A-Simpson 1/3 = " << df1->simpson1_3(a, b, n) << endl;
	cout << "A-Simpson 3/8 = " << df1->simpson3_8(a, b, n) << endl;
	WINPAUSE;
	return 0;
}