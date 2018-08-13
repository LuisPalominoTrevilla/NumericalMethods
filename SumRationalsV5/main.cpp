#include <iostream>

using namespace std;

#define WINPAUSE system("pause")

void sumRationals(int const * const a, const int &b, const int &c, const int &d, int *const e, int * const f);
void printSumRational(int const * const a, const int &b, const int &c, const int &d, int &e, int &f);

// Código seguro en C++

int main() {
	int * a;
	int b, c, d, e, f;

	// Crear primitivo dinámico a
	a = new int;
	*a = 1;

	b = 2;
	c = 3;
	d = 4;
	e = 0;
	f = 0;

	// Pasar la dirección de e y dirección de f
	// Pasar la dirección de memoria de a a ambas
	sumRationals(a, b, c, d, &e, &f);
	printSumRational(a, b, c, d, e, f);
	delete a;
	WINPAUSE;
	return 0;
}

// Función hecha con pointers, e es un apuntador a entero y f es un apuntador a entero
// Pasar por referencia para ahorrar memoria
// referencia a un entero constante para denegar modificar el valor
// apuntador constante a un entero para poder modificar valor pero no reasignar apuntador
// Pasar a como apuntador restringiendo el reasignado del apuntador y modificar su valor
void sumRationals(int const * const a, int const &b, int const &c, int const &d, int *const e, int * const f) {
	// Modificar valor apuntado por e
	*e = d * *a + b * c;
	// Modificar valor apuntado por f
	*f = b * d;
}

// Pasar a como apuntador registriendo el reasignado del apuntador y modificar su valor
void printSumRational(int const * const a, int const &b, int const &c, int const &d, int &e, int &f) {
	cout << *a << "/" << b << " + " << c << "/" << d << " = " << e << "/" << f << endl;
}