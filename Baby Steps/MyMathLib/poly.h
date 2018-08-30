#pragma once
#include <string>

using namespace std;

string polinomialToString(int, int*);

float evaluate(int n, int* polynomial, float val);

bool isRoot(int n, int* polynomial, float possibleRoot, double epsilon);
double* solveCuadratic(int a, int b, int c);