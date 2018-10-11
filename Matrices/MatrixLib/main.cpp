#include <iostream>
#include "Rational.h"
#include "Complex.h"
#include <string>
#include "Matrix.h"
#include "Matrix.cpp"

#define WINPAUSE system("pause")

using namespace std;

int main() {
	cout << "Autor: Luis Palomino Trevilla\nFecha: 10 de octubre de 2018\n" << endl;
	cout << "Usando la siguiente matriz double A = \n";
	double a[4] = { 2,4,3,5 };
	Matrix<double> *m = new Matrix<double>(2, 2, a);
	m->toString();
	cout << "Su determinante: "<<m->getDeterminant() << endl;
	cout << "Su inversa: ";
	m->getInverse()->toString();
	cout << "Su transpuesta: \n";
	m->transposed()->toString();
	cout << "-------------------------------------------------------------\n" << endl;
	cout << "Usando la siguiente matriz Rational B = \n";
	Rational b1(1);
	Rational b2(1);
	Rational b3(3);
	Rational b4(3);
	Rational b5(3);
	Rational b6(1);
	Rational b7(0);
	Rational b8(2);
	Rational b9(4);
	Rational b[9] = { b1,b2,b3,b4,b5,b6,b7,b8,b9 };
	Matrix<Rational> *m2 = new Matrix<Rational>(3, 3, b);
	m2->toString();
	cout << "Su determinante: " << m2->getDeterminant() << endl;
	cout << "Su inversa: ";
	m2->getInverse()->toString();
	cout << "Su transpuesta: \n";
	m2->transposed()->toString();
	cout << "-------------------------------------------------------------\n" << endl;
	cout << "Usando la siguiente matriz Compleja C = \n";
	Complex c1(1, 2);
	Complex c2(4, 1);
	Complex c3(3, 5);
	Complex c4(2, 2);
	Complex c[4] = { c1,c2,c3,c4 };
	Matrix<Complex> *m3 = new Matrix<Complex>(2, 2, c);
	m3->toString();
	cout << "Su determinante: " << m3->getDeterminant() << endl;
	cout << "Su inversa: ";
	m3->getInverse()->toString();
	cout << "Su transpuesta: \n";
	m3->transposed()->toString();
	WINPAUSE;
	return 0;
}