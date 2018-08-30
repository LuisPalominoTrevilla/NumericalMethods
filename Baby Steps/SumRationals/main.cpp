#include <iostream>

using namespace std;

#define WINPAUSE system("pause")

void sumRationals(int a, int b, int c, int d, int e, int f);
void printSumRational(int a, int b, int c, int d, int e, int f);

int main() {
	int a, b, c, d, e, f;

	a = 1;
	b = 2;
	c = 3;
	d = 4;
	e = 0;
	f = 0;

	sumRationals(a, b, c, d, e, f);
	printSumRational(a, b, c, d, e, f);
	WINPAUSE;
	return 0;
}

void sumRationals(int a, int b, int c, int d, int e, int f) {
	e = a * d + b * c;
	f = b * d;
}

void printSumRational(int a, int b, int c, int d, int e, int f) {
	cout << a << "/" << b << " + " << c << "/" << d << " = " << e << "/" << f << endl;
}