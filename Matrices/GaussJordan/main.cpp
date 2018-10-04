#include <iostream>
#include "Matrix.h"

#define WINPAUSE system("pause")

using namespace std;


int main() {
	double a[6] = {1,2,3,4,5,6};
	Matrix *A = new Matrix(2, 3, a);
	cout << A->toString() << endl;
	cout << "After gauss elimination: " << endl;
	cout << A->getRREF()->toString() << endl;
	delete A;

	WINPAUSE;
}