#include <iostream>
#include "poly.h"

using namespace std;

#define WINPAUSE system("pause")

int main() {
	int n;
	double* p;	// P(x)
	double* q;	// Q(x)
	double r;	// R
	double a;	// x-a

	n = 4;
	p = new double[n+1];
	p[0] = 24.;
	p[1] = -10.;
	p[2] = -15.;
	p[3] = 0.;
	p[4] = 1.;
	a = -4;
	
	cout << "P(x) = " << polinomialToString(n, p) << " = 0 " << endl;
	q = divPolyByMonomial(p, n, a, r);

	cout << "Q(x) = " << polinomialToString(n-1, q) << " = 0 " << endl;
	cout << "R = " << r << endl;
	//cout << isRoot(2, a, 1, 1.e-7) << endl;
	//double* root = solveCuadratic(1, 0, -1);
	//cout << root[0] << endl;
	//cout << root[1] << endl;
	delete[] p;
	delete[] q;
	WINPAUSE;
	return 0;
}