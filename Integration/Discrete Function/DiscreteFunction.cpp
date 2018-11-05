#include "DiscreteFunction.h"
#include <cmath>

DiscreteFunction::DiscreteFunction(int n, double* x, double *y) {
	this->n = n;
	this->x = x;
	this->y = y;
}

double DiscreteFunction::riemann(double a, double b, int numIntervals) {
	double h = (b - a) / numIntervals;
	double area = 0;
	for (int i = 0; i < this->n-1; i++) {
		area += this->y[i];
	}
	area *= h;
	return area;
}

double DiscreteFunction::trapezoide(double a, double b, int numIntervals) {
	double h = (b - a) / numIntervals;
	double area = 0;
	for (int i = 1; i < this->n - 1; i++) {
		area += this->y[i];
	}
	area = (this->y[0] + this->y[this->n - 1] + 2. *area) * h / 2.;
	return area;
}

double DiscreteFunction::simpson1_3(double a, double b, int numIntervals) {
	double h = (b - a) / numIntervals;
	double areaPar = 0;
	double area = 0;
	for (int i = 1; i < this->n - 1; i++) {
		if (i % 2 == 0) {
			areaPar += this->y[i];
		}
		else {
			area += this->y[i];
		}
	}
	area = (this->y[0] + this->y[this->n - 1] + 2. * areaPar + 4* area) * h / 3.;
	return area;
}

double DiscreteFunction::simpson3_8(double a, double b, int numIntervals) {
	double h = (b - a) / numIntervals;
	double areaMult3 = 0;
	double area = 0;
	for (int i = 1; i < this->n - 1; i++) {
		if (i % 3 == 0) {
			areaMult3 += this->y[i];
		}
		else {
			area += this->y[i];
		}
	}
	area = (this->y[0] + this->y[this->n - 1] + 2. * areaMult3 + 3 * area) * 3. * h / 8.;
	return area;
}