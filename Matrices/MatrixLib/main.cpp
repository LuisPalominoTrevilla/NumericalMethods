#include <iostream>
#include "Rational.h"
#include "Complex.h"

#define WINPAUSE system("pause")

using namespace std;

int main() {
	Rational *a = new Rational(3, 2);
	Rational *b = new Rational(1);
	Complex cm(a, b);
	Complex cm2(4, 5);
	cout << cm << endl;
	cout << cm2 << endl;
	cout << *(cm/cm2) << endl;
	WINPAUSE;
	return 0;
}