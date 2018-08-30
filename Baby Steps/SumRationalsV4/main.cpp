#include <iostream>

using namespace std;

#define WINPAUSE system("pause")

void sumRationals(const int &a, const int &b, const int &c, const int &d, int *const e, int * const f);
void printSumRational(const int &a, const int &b, const int &c, const int &d, int &e, int &f);

// Código seguro en C++

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
// Pasar por referencia para ahorrar memoria
// referencia a un entero constante para denegar modificar el valor
// apuntador constante a un entero para poder modificar valor pero no reasignar apuntador
void sumRationals(int const &a, int const &b, int const &c, int const &d, int *const e, int * const f) {
	// Modificar valor apuntado por e
	*e = a * d + b * c;
	// Modificar valor apuntado por f
	*f = b * d;
}

void printSumRational(int const &a, int const &b, int const &c, int const &d, int &e, int &f) {
	cout << a << "/" << b << " + " << c << "/" << d << " = " << e << "/" << f << endl;
}