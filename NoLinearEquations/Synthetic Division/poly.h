#pragma once
#include <string>

using namespace std;

string polinomialToString(int, double*);

float evaluate(int, double*, double);

bool isRoot(int n, double*, double, double epsilon);
double* solveCuadratic(double a, double b, double c);

// P(x) / (x-a) = Q(x) + R / (x - a)
double* divPolyByMonomial(double*, int n, double a, double &reminder);