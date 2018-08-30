#include "poly.h"
#include <string>

using namespace std;

string polinomialToString(int n, int* polynomial) {
	string a = "";
	for (int i = 0; i <= n; i++) {
		if (polynomial[i] == 0) {
			continue;
		}
		a += ((polynomial[i] > 0 && i != 0) ? "+" : "") + ((polynomial[i] == 1 && i > 0) ? "" : to_string(polynomial[i])) + ((i == 0) ? "" : (i == 1) ? "x" : ("x^" + to_string(i)));
	}
	return a;
}

float evaluate(int n, int* polynomial, float val) {
	float result = 0.0;
	for (int i = 0; i <= n; i++) {
		result += polynomial[i] * pow(val, i);
	}
	return result;
}

bool isRoot(int n, int* polynomial, float possibleRoot, double epsilon) {
	return abs(evaluate(n, polynomial, possibleRoot)) <= epsilon;
}

double* solveCuadratic(int a, int b, int c) {
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