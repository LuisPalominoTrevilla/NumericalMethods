#pragma once
#include <string>

using namespace std;

int sum(int a, int b);

string polinomialToString(int, int*);

float evaluate(int n, int* polynomial, float val);

bool isRoot(int n, int* polynomial, float possibleRoot, double epsilon);
double* solveCuadratic(int a, int b, int c);