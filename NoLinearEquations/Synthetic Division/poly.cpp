#include "poly.h"
#include <string>

using namespace std;

string polinomialToString(int n, double* polynomial) {
	string msg = "";
	for (int i = 0; i <= n; i++) {
		if (polynomial[i] == 0) {
			continue;
		}
		msg += ((polynomial[i] > 0 && i != 0) ? " + " : " ") + ((polynomial[i] == 1 && i > 0) ? "" : to_string(polynomial[i])) + ((i == 0) ? "" : (i == 1) ? "x" : ("x^" + to_string(i)));
	}
	return msg;
}

float evaluate(int n, double* polynomial, double val) {
	double result = 0.0;
	for (int i = 0; i <= n; i++) {
		result += polynomial[i] * pow(val, i);
	}
	return result;
}

bool isRoot(int n, double* polynomial, double possibleRoot, double epsilon) {
	return abs(evaluate(n, polynomial, possibleRoot)) <= epsilon;
}

double* solveCuadratic(double a, double b, double c) {
	double det = pow(b, 2) - 4 * a * c;
	if (abs(det) < 1.e-7) {
		return NULL;
	}
	double* roots = new double[2];
	det = sqrt(det);
	roots[0] = (-1 * b + det) / (2 * a);
	roots[1] = (-1 * b - det) / (2 * a);
	return roots;
}

double* divPolyByMonomial(double* p, int n, double a, double &reminder) {
	double* q = new double[n];
	q[0] = p[n];
	for (int i = 1; i < n; i++) {
		q[i] = q[i - 1] * a + p[n-i];
	}
	reminder = q[n - 1] * a + p[0];
	double* tmp = new double[n];
	for (int i = 0; i < n; i++) {
		tmp[i] = q[n - i-1];
	}
	delete[] q;
	return tmp;
}