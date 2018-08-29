#include <iostream>
#include "sum.h"

using namespace std;

#define WINPAUSE system("pause")

int main() {
	int* a = new int[3];
	a[0] = -1;
	a[1] = 0;
	a[2] = 1;
	cout << polinomialToString(2, a) << endl;
	//cout << isRoot(2, a, 1, 1.e-7) << endl;
	double* root = solveCuadratic(1, 0, -1);
	cout << root[0] << endl;
	cout << root[1] << endl;
	WINPAUSE;
	return 0;
}