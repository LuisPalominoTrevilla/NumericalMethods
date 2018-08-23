#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define WINPAUSE system("pause")

double getAbsoluteError(double, double);
double getRelativeError(double, double);
double getNormalizedError(double, double);
double getPINormal(int);
double getPIPrecision(double);
double getEulerNormal(int);
double getEulerPrecision(double);

int main() {
	/* Probar primeras 3 funciones
		considerando que el valor verdadero de pi es 3.146*/
	cout << "Probar primeras 3 funciones considerando que el valor verdadero de pi es 3.1416\n" << endl;
	double piVerd = 3.1416;
	// Probar error absoluto con 5 términos de la serie:
	cout << "Error Absoluto con n = 5 es: " << getAbsoluteError(piVerd, getPINormal(5)) << endl;
	// Probar error relativo con 5 términos de la serie:
	cout << "Error Relativo con n = 5 es: " << getRelativeError(piVerd, getPINormal(5)) << endl;
	// Probar error normalizado con 5 términos de la serie:
	cout << "Error Relativo Normalizado con n = 5 es: " << getNormalizedError(getPINormal(5), getPINormal(4)) << endl;
	cout << "\n" << endl;
	/* Probar últimas 2 funciones
		Para calcular el número Euler*/
	cout << "Probar las ultimas 2 funciones para calcular el numero Euler\n" << endl;
	// Probar calcular aproximación de número euler en términos de n. Se asume que n > 0
	cout << "Probar aproximacion de Euler en terminos de un numero n" << endl;
	cout << "Probar cuando\t\tn = 10: " << setprecision(10) << getEulerNormal(10) << endl;
	cout << "\t \t \tn = 100: " << setprecision(10) << getEulerNormal(100) << endl;
	cout << "\t \t \tn = 1,000: " << setprecision(10) << getEulerNormal(1000) << endl;
	cout << "\t \t \tn = 10,000: " << setprecision(10) << getEulerNormal(10000) << endl;
	cout << "\t \t \tn = 100,000: " << setprecision(10) << getEulerNormal(100000) << endl;
	cout << "\t \t \tn = 1,000,000: " << setprecision(10) << getEulerNormal(1000000) << endl;
	cout << "\t \t \tn = 10,000,000: " << setprecision(10) << getEulerNormal(10000000) << endl;
	cout << "\t \t \tn = 100,000,000: " << setprecision(10) << getEulerNormal(100000000) << endl;
	cout << endl;
	// Probar calcular aproximación de número euler dada una tolerancia de error normalizado dado en %
	cout << "Probar aproximacion de Euler dada una tolerancia de error normalizado en %" << endl;
	cout << "Probar cuando \t\ttolerancia = 5%: " << getEulerPrecision(5) << endl;
	cout << "\t\t\ttolerancia = 1%: " << getEulerPrecision(1) << endl;
	cout << "\t\t\ttolerancia = .1%: " << getEulerPrecision(.1) << endl;
	cout << "\t\t\ttolerancia = .001%: " << getEulerPrecision(.001) << endl;
	cout << "\t\t\ttolerancia = .0001%: " << getEulerPrecision(.0001) << endl;
	cout << "\t\t\ttolerancia = .000001%: " << getEulerPrecision(.000001) << endl;
	cout << "\t\t\ttolerancia = .00000001%: " << getEulerPrecision(.00000001) << endl;
	cout << "\t\t\ttolerancia = .00000000000001%: " << getEulerPrecision(.00000000000001) << endl;
	WINPAUSE;
	return 0;
}

/**
	Methods to calculate errors
*/

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

/**
	Get Pi methods
*/

double getPINormal(int n) {
	double pi = 0.0;
	for (int i = 1; i <= n; i++) {
		pi += 1.0 / pow(i, 2);
	}
	return sqrtl(pi * 6);
}

double getPIPrecision(double tolerance) {
	double sum = 0, normalizedError = 0, currentVal = 0, oldVal = 0;
	int n = 1;
	do {
		sum += 1.0 / pow(n++, 2);
		currentVal = sqrtl(sum * 6);
		normalizedError = getNormalizedError(currentVal, oldVal);
		cout << normalizedError << endl;
		oldVal = currentVal;
	} while (normalizedError > tolerance / 100.0);
	return currentVal;
}


/**
	Get Euler methods
*/
double getEulerNormal(int n) {
	return (n == 0)? 0.0: pow(1 + 1.0 / n, n);
}

double getEulerPrecision(double tolerance) {
	int n = 0;
	double prevEuler = getEulerNormal(n++), error = 0.0, currEuler = 0.0;
	do {
		currEuler = getEulerNormal(n++);
		error = getNormalizedError(currEuler, prevEuler);
		prevEuler = currEuler;
	} while (error > tolerance / 100.0);
	return currEuler;
}