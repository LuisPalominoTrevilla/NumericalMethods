#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define WINPAUSE system("pause")

void roundNumber(double &, int);
double getAbsoluteError(double, double);
double getRelativeError(double, double);
double getNormalizedError(double, double);
double getPI(int);
double getPI(double);

int main() {
	cout << setprecision(20) << getPI(.00000000000001) << endl;

	WINPAUSE;
	return 0;
}

void roundNumber(double &num, int decimal) {
	if (decimal <= 0) return;
	int places = pow(10, decimal);
	num = roundl(num*places) / places;
}

double getAbsoluteError(double realValue, double aproxValue) {
	return abs(realValue - aproxValue);
}

double getRelativeError(double realValue, double aproxValue) {
	if (aproxValue == 0) return 0;
	return abs((realValue - aproxValue) / realValue);
}

double getNormalizedError(double currentValue, double oldValue) {
	if (oldValue == 0) return -1;
	return abs((currentValue - oldValue) / currentValue);
}

double getPI(int n) {
	double pi = 0.0;
	for (int i = 1; i <= n; i++) {
		pi += 1.0 / pow(i, 2);
	}
	return sqrtl(pi * 6);
}

double getPI(double error) {
	double sum = 0, normalizedError = 0, currentVal = 0, oldVal = 0;
	int n = 1;
	do {
		sum += 1.0 / pow(n++, 2);
		currentVal = sqrtl(sum * 6);
		normalizedError = getNormalizedError(currentVal, oldVal);
		if (normalizedError == -1) {
			normalizedError = 1;
		}
		oldVal = currentVal;
	} while (normalizedError > error / 100);
	return currentVal;
}