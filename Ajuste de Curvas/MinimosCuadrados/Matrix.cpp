#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Matrix.h"

using namespace std;

/* CONSTRUCTORS */

// Default matrix constructor
Matrix::Matrix(int row, int col, bool isRandom) {
	this->m = row;
	this->n = col;
	this->matrix = new double[m*n];
	if (!isRandom) {
		for (int i = 0; i < m*n; i++) {
			this->matrix[i] = 0;
		}
	}
	else {
		srand(time(NULL));

		for (int i = 0; i < m*n; i++) {
			this->matrix[i] = rand() % 11;
		}
	}
}

// Creates identity matrix
Matrix::Matrix(int n) {
	this->m = n;
	this->n = n;
	int k = 0;
	this->matrix = new double[n*n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			k = i * n + j;
			if (i == j) {
				matrix[k] = 1;
				continue;
			}
			matrix[k] = 0;
		}
	}
}

// Create matrix using a bidimensional array
Matrix::Matrix(int rows, int cols, double **matrix) {
	this->m = rows;
	this->n = cols;
	int k = 0;
	this->matrix = new double[this->m*this->n];
	for (int i = 0; i < this->m; i++) {
		for (int j = 0; j < this->n; j++) {
			k = i * n + j;
			cout << matrix[i][j] << " ";
			this->matrix[k] = matrix[i][j];
		}
		cout << endl;
	}
}

// Creates matrix using row-major-order array
Matrix::Matrix(int rows, int cols, double* matrix) {
	this->m = rows;
	this->n = cols;
	this->matrix = new double[this->m*this->n];
	for (int i = 0; i < this->m * this->n; i++) {
		this->matrix[i] = matrix[i];
	}
}

/* MODIFIERS */

void Matrix::deleteRow(int row) {
	if (row >= this->m || row < 0) {
		// can't delete unexistent rows
		return;
	}
	this->m--;
	double *newMatrix = new double[this->m*this->n];
	int i, j, index;
	index = 0;
	for (int k = 0; k < (this->m + 1)*this->n; k++) {
		i = k / this->n;
		if (i == row) {
			// If current row is equal to the row I want to delete then I skip it
			continue;
		}
		newMatrix[index++] = this->matrix[k];
	}
	delete[] this->matrix;
	this->matrix = newMatrix;
}

// Appends a row full of 0 at the end of the matrix
void Matrix::appendRow() {
	this->m++;
	int i;
	double *newMatrix = new double[this->m*this->n];
	for (int k = 0; k < this->m*this->n; k++) {
		i = k / this->n;
		if (i == this->m - 1) {
			newMatrix[k] = 0;
			continue;
		}
		newMatrix[k] = this->matrix[k];
	}
	delete[] this->matrix;
	this->matrix = newMatrix;
}

void Matrix::exchangeRows(int r1, int r2) {
	for (int j = 0; j < this->n; j++) {
		double tmp = this->getElement(r1, j);
		this->setElement(r1, j, this->getElement(r2, j));
		this->setElement(r2, j, tmp);
	}
}

/* ANALIZERS */

int Matrix::getRows() {
	return this->m;
}

int Matrix::getColumns() {
	return this->n;
}

double Matrix::getElement(int i, int j) {
	int k = i * this->n + j;
	return this->matrix[k];
}

void Matrix::setElement(int i, int j, double val) {
	int k = i * this->n + j;
	this->matrix[k] = val;
}

Matrix* Matrix::getRREF() {
	Matrix *RREF = new Matrix(this->m, this->n, this->matrix);
	double pivote;
	double factor;
	double tol = 1.e-7;
	for (int i = 0; i < RREF->m; i++) {
		pivote = RREF->getElement(i, i);
		if (abs(pivote) <= tol) {
			int k;
			// Try to interchange a row
			for (k = i + 1; k < RREF->m; k++) {
				if (abs(this->getElement(k, i)) > tol) {
					// Intercambio de renglones
					this->exchangeRows(i, k);
					pivote = RREF->getElement(i, i);
					break;
				}
			}
			if (k == this->m) {
				return NULL;
			}
		}
		for (int j = 0; j < RREF->n; j++) {
			RREF->setElement(i, j, RREF->getElement(i, j) / pivote);
		}
		for (int k = 0; k < RREF->m; k++) {
			if (k != i) {
				factor = -RREF->getElement(k, i);
				for (int j = 0; j < RREF->n; j++) {
					RREF->setElement(k, j, RREF->getElement(i, j)*factor + RREF->getElement(k, j));
				}
			}
		}
	}
	return RREF;
}

// Returns the determinant of the square matrix
double Matrix::getDeterminant() {
	// Check if it's not a square matrix
	if (this->m != this->n) {
		return -1.0;
	}
	return this->getElement(0, 0)*this->getElement(1, 1) - this->getElement(0, 1)*this->getElement(1, 0);
}

bool Matrix::isSquare() {
	return this->m == this->n;
}

bool Matrix::isIdentity() {
	int i, j;
	for (int k = 0; k < this->m*this->n; k++) {
		i = k / this->n;
		j = k - i * this->n;
		if (i == j && this->matrix[k] != 1) {
			return false;
		}
		else if (i != j && this->matrix[k] != 0) {
			return false;
		}
	}
	return true;
}

bool Matrix::isNull() {
	for (int k = 0; k < this->m*this->n; k++) {
		if (this->matrix[k] != 0) {
			return false;
		}
	}
	return true;
}



string Matrix::toString() {
	string matrix = "";
	for (int i = 0; i < this->m; i++) {
		matrix += "|";
		for (int j = 0; j < this->n; j++) {
			// K is the current position of the matrix
			int k = i * this->n + j;
			matrix += " " + to_string(this->matrix[k]) + " ";
		}
		matrix += "|\n";
	}
	return matrix;
}

/* MATRIX OPERATIONS */

// Return sum of two matrices
Matrix* Matrix::sum(Matrix *b) {
	if (this->m != b->getRows() || this->n != b->getColumns()) {
		// Operation cannot be done
		return NULL;
	}
	int k = 0;
	// Declare row-major-order array to store sum
	double *sum = new double[this->m*this->n];
	for (int i = 0; i < this->m; i++) {
		for (int j = 0; j < this->n; j++) {
			k = i * n + j;
			sum[k] = this->getElement(i, j) + b->getElement(i, j);
		}
	}
	// Create new Matrix
	Matrix *A = new Matrix(this->m, this->n, sum);
	delete[] sum;
	return A;
}

// Multiply the current matrix by the parameter
Matrix* Matrix::multiply(Matrix *B) {
	if (this->n != B->getRows()) {
		// Operation cannot be performed
		return NULL;
	}
	double sum;
	int index;
	// Declare row-major-order array to store mult
	double *mult = new double[this->m*B->getColumns()];
	for (int i = 0; i < this->m; i++) {
		for (int k = 0; k < B->getColumns(); k++) {
			// For each column k of B
			// Cik = sum(Aij*Bjk)
			sum = 0;
			for (int j = 0; j < this->n; j++) {
				sum += this->getElement(i, j)*B->getElement(j, k);
			}
			// sum now contains the value of Cik
			index = i * B->getColumns() + k;
			mult[index] = sum;
		}
	}
	// Create new matrix
	Matrix *C = new Matrix(this->m, B->getColumns(), mult);
	delete[] mult;
	return C;
}

// Multiply the parameter matrix by the current matrix
Matrix* Matrix::preMultiply(Matrix *B) {
	if (B->getColumns() != this->m) {
		// Operation cannot be performed
		return NULL;
	}
	double sum;
	int index;
	// Declare row-major-order array to store mult
	double *mult = new double[B->getRows()*this->n];
	for (int i = 0; i < B->getRows(); i++) {
		for (int k = 0; k < this->n; k++) {
			// For each column k of A
			// Cik = sum(Bjk*Aij)
			sum = 0;
			for (int j = 0; j < B->getColumns(); j++) {
				sum += B->getElement(i, j)*this->getElement(j, k);
			}
			// sum now contains the value of Cik
			index = i * this->n + k;
			mult[index] = sum;
		}
	}
	// Create new matrix
	Matrix *C = new Matrix(B->getRows(), this->n, mult);
	delete[] mult;
	return C;
}

/* DESTRUCTOR */
Matrix::~Matrix() {
	delete[] this->matrix;
}
int m, n;
double *matrix;