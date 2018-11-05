#pragma once

class DiscreteFunction {
private:
	int n;	// numero de intervalos
	double *x;
	double *y;
public:
	DiscreteFunction(int n, double* x, double *y);
	double riemann(double a, double b, int numIntervals);
	double trapezoide(double a, double b, int numIntervals);
	double simpson1_3(double a, double b, int numIntervals);
	double simpson3_8(double a, double b, int numIntervals);
};