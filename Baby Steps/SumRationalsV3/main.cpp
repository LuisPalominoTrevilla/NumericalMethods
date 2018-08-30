#include <iostream>

using namespace std;

#define WINPAUSE system("pause")

void sumRationals(int a, int b, int c, int d, int *e, int *f);
void printSumRational(int a, int b, int c, int d, int e, int f);

int main() {
	int a, b, c, d, e, f;

	a = 1;
	b = 2;
	c = 3;
	d = 4;
	e = 0;
	f = 0;

	// Pasar la dirección de e y dirección de f
	sumRationals(a, b, c, d, &e, &f);
	printSumRational(a, b, c, d, e, f);
	WINPAUSE;
	return 0;
}

// Función hecha con pointers, e es un apuntador a entero y f es un apuntador a entero
void sumRationals(int a, int b, int c, int d, int *e, int *f) {
	// Modificar valor apuntado por e
	*e = a * d + b * c;
	// Modificar valor apuntado por f
	*f = b * d;
}

void printSumRational(int a, int b, int c, int d, int e, int f) {
	cout << a << "/" << b << " + " << c << "/" << d << " = " << e << "/" << f << endl;
}