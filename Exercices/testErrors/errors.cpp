#include <iostream>
#include <cmath>
#include "errors.h"

using namespace std;

double getAbsoluteError(double realValue, double aproxValue) {
	return abs(realValue - aproxValue);
}

double getRelativeError(double realValue, double aproxValue) {
	double epsilon = 1e-7;
	if (abs(realValue) <= epsilon) return -1;
	return abs((realValue - aproxValue) / realValue);
}

double getNormalizedError(double currentValue, double oldValue) {
	double epsilon = 1e-7;
	if (abs(currentValue) <= epsilon) return -1;
	return abs((currentValue - oldValue) / currentValue);
}

double getPercentageAbsoluteError(double realValue, double aproxValue) {
	return getRelativeError(realValue, aproxValue) * 100;
}

double getPercentageRelativeError(double realValue, double aproxValue) {
	return getRelativeError(realValue, aproxValue) * 100;
}

double getPercentageNormalizedError(double currentValue, double oldValue) {
	return getNormalizedError(currentValue, oldValue) * 100;
}