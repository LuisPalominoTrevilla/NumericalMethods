#include <iostream>
#include "Rational.h"
#define WINPAUSE system("pause")

using namespace std;

int main() {
	cout << "Hola mundo" << endl;
	Rational r(3,8);
	Rational r2(1);
	cout << r*r2 << endl;
	WINPAUSE;
	return 0;
}