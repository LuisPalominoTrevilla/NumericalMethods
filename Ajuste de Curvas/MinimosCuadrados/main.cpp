#include <iostream>
#include <math.h>
#include "Matrix.h"

#define WINPAUSE system("pause")

using namespace std;

void preparation(double *x, double *y, double *Xi, double* Xi2Yi, int order, int points);
double* minimosCuadrados(double* x, double* y, int points, int order);

int main() {
	int const points = 4;
	double x[points] = {0, -.5, 1.3, -2.3};
	double y[points] = {1, .75, 3.99, 3.99};

	int order = 2;

	// Should return 1 + x + x^2
	double* coeficients = minimosCuadrados(x, y, points, order);
	for (int i = 0; i < order + 1; i++) {
		cout << coeficients[i] << " ";
	}
	cout << endl;
	WINPAUSE;
}

void preparation(double *x, double *y, double *Xi, double* Xi2Yi, int order, int points) {
	// Initialize Xi array
	for (int i = 0; i < (order + 1) * 2; i++) {
		Xi[i] = 0;
	}
	// Initialize Xi2Yi array
	for (int i = 0; i < order + 1; i++) {
		Xi2Yi[i] = 0;
	}
	for (int i = 0; i < points; i++) {
		for (int j = 0; j < order * 2 + 1; j++) {
			Xi[j] += powf(x[i], j);
		}
		for (int j = 0; j < order + 1; j++) {
			Xi2Yi[j] += y[i] * powf(x[i], j);
		}
	}
}

double* minimosCuadrados(double* x, double* y, int points, int order) {
	double* Xi = new double[order * 2 + 1];
	double* Xi2Yi = new double[order + 1];

	preparation(x, y, Xi, Xi2Yi, order, points);
	
	int rows = (order + 1);
	int cols = (order + 2);
	int counter = 0;

	// Create the array representing a row-major matrix
	double* equations = new double[rows * cols];
	for (int i = 0; i < rows; i++) {
		for (int j = i; j < rows + i; j++) {
			equations[counter++] = Xi[j];
		}
		equations[counter++] = Xi2Yi[i];
	}
	// Create the matrix
	Matrix* m = new Matrix(rows, cols, equations);
	// Get the result
	Matrix* result = m->getRREF();
	double *poly = new double[rows];
	for (int i = 0; i < rows; i++) {
		poly[i] = result->getElement(i, cols-1);
	}
	delete[] equations;
	return poly;
}