#include <iostream>
#include "Matrix.h"

using namespace std;

template <class T>
Matrix<T>::Matrix(int rows, int cols, T* matrix) {
	this->m = rows;
	this->n = cols;
	this->matrix = new T[this->m*this->n];
	for (int i = 0; i < this->m * this->n; i++) {
		this->matrix[i] = matrix[i];
	}
}

template <class T>
void Matrix<T>::setMatrix(int rows, int cols, T* matrix) {
	this->m = rows;
	this->n = cols;
	this->matrix = new T[this->m*this->n];
	for (int i = 0; i < this->m * this->n; i++) {
		this->matrix[i] = matrix[i];
	}
}

template <class T>
int Matrix<T>::getRows() {
	return this->m;
}

template <class T>
int Matrix<T>::getColumns() {
	return this->n;
}

template <class T>
void Matrix<T>::setElement(int i, int j, T val) {
	int k = i * this->n + j;
	this->matrix[k] = val;
}

template <class T>
T Matrix<T>::getElement(int i, int j) {
	int k = i * this->n + j;
	return this->matrix[k];
}

template <class T>
void Matrix<T>::exchangeRows(int r1, int r2) {
	for (int j = 0; j < this->n; j++) {
		T tmp = this->getElement(r1, j);
		this->setElement(r1, j, this->getElement(r2, j));
		this->setElement(r2, j, tmp);
	}
}

template <class T>
Matrix<T>* Matrix<T>::getInverse() {
	double tol = 1.e-7;
	if (this->m != this->n) {
		// Matrix doesn't have an inverse
		return NULL;
	}
	T det = this->getDeterminant();
	if (det <= T(tol) && det >= T(-tol)) {
		// Matrix has determinant 0
		return NULL;
	}
	// Start getting the inverse
	T *augmented = new T[this->m*this->n*2];
	int pos1 = 0;
	for (int i = 0; i < this->m; i++) {
		for (int j = 0; j < this->n*2; j++) {
			int k = i * this->n*2 + j;
			if (j < this->n) {
				augmented[k] = this->getElement(i, j);
			}
			else {
				if (pos1++ % (this->n + 1) == 0) {
					augmented[k] = T(1);
				}
				else {
					augmented[k] = T(0);
				}
			}
		}
	}
	Matrix<T> *aug = new Matrix<T>(this->m, this->n*2, augmented);
	bool pos = true;
	aug->RREF(pos);
	T *inv = new T[this->m*this->n];
	int k = 0;
	for (int i = 0; i < this->m; i++) {
		for (int j = this->n; j < this->n * 2; j++) {
			inv[k++] = aug->getElement(i, j);
		}
		cout << endl;
	}
	Matrix<T> *inverse = new Matrix<T>(this->m, this->n, inv);
	delete[] augmented;
	delete[] inv;
	delete aug;
	return inverse;
}

template <class T>
T Matrix<T>::getDeterminant() {
	Matrix <T> *tmp = new Matrix<T>(this->m, this->n, this->matrix);
	T pivote;
	T factor;
	T determinant(1);
	double tol = 1.e-7;
	for (int i = 0; i < tmp->m; i++) {
		// Get a pivot
		pivote = tmp->getElement(i, i);
		// Exchange rows if pivot is 0
		if (pivote <= T(tol) && pivote >= T(-tol)) {
			int k;
			// Try to interchange a row
			for (k = i + 1; k < tmp->m; k++) {
				if (tmp->getElement(k, i) >= T(tol) or tmp->getElement(k, i) <= T(-tol)) {
					// Intercambio de renglones
					determinant = determinant * T(-1);
					tmp->exchangeRows(i, k);
					pivote = tmp->getElement(i, i);
					break;
				}
			}
			if (k == tmp->m) {
				delete tmp;
				return T(0);
			}
		}
		determinant = determinant * pivote;
		for (int j = 0; j < tmp->n; j++) {
			tmp->setElement(i, j, tmp->getElement(i, j) / pivote);
		}
		for (int k = 0; k < tmp->m; k++) {
			if (k != i) {
				factor = tmp->getElement(k, i) * T(-1);
				for (int j = 0; j < tmp->n; j++) {
					tmp->setElement(k, j, tmp->getElement(i, j) * factor + tmp->getElement(k, j));
				}
			}
		}
	}
	delete tmp;
	return determinant;
}

// Convert Matrix into RREF
template <class T>
void Matrix<T>::RREF(bool &consistent) {
	T pivote;
	T factor;
	double tol = 1.e-7;
	for (int i = 0; i < this->m; i++) {
		// Get a pivot
		pivote = this->getElement(i, i);
		// Exchange rows if pivot is 0
		if (pivote <= T(tol) && pivote >= T(-tol)) {
			int k;
			// Try to interchange a row
			for (k = i + 1; k < this->m; k++) {
				if (this->getElement(k, i) >= T(tol) or this->getElement(k, i) <= T(-tol)) {
					// Intercambio de renglones
					this->exchangeRows(i, k);
					pivote = this->getElement(i, i);
					break;
				}
			}
			if (k == this->m) {
				consistent = false;
				return;
			}
		}
		for (int j = 0; j < this->n; j++) {
			this->setElement(i, j, this->getElement(i, j) / pivote);
		}
		for (int k = 0; k < this->m; k++) {
			if (k != i) {
				factor = this->getElement(k, i) * T(-1);
				for (int j = 0; j < this->n; j++) {
					this->setElement(k, j, this->getElement(i, j) * factor + this->getElement(k, j));
				}
			}
		}
	}
	consistent = true;
}

template <class T>
Matrix<T>* Matrix<T>::transposed() {
	T *transposed = new T[this->m*this->n];
	int k = 0;
	for (int i = 0; i < this->m; i++) {
		for (int j = 0; j < this->n; j++) {
			k = j * this->m + i;
			transposed[k] = this->getElement(i, j);
		}
	}
	Matrix<T> *A = new Matrix<T>(this->n, this->m, transposed);
	delete[] transposed;
	return A;
}

// Return sum of two matrices
template <class T>
Matrix<T>* Matrix<T>::sum(Matrix<T> *b) {
	if (this->m != b->getRows() || this->n != b->getColumns()) {
		// Operation cannot be done
		return NULL;
	}
	int k = 0;
	// Declare row-major-order array to store sum
	T *sum = new T[this->m*this->n];
	for (int i = 0; i < this->m; i++) {
		for (int j = 0; j < this->n; j++) {
			k = i * n + j;
			sum[k] = this->getElement(i, j) + b->getElement(i, j);
		}
	}
	// Create new Matrix
	Matrix<T> *A = new Matrix<T>(this->m, this->n, sum);
	delete[] sum;
	return A;
}

// Return subtraction of two matrices
template <class T>
Matrix<T>* Matrix<T>::subtract(Matrix<T> *b) {
	if (this->m != b->getRows() || this->n != b->getColumns()) {
		// Operation cannot be done
		return NULL;
	}
	int k = 0;
	// Declare row-major-order array to store sum
	T *sum = new T[this->m*this->n];
	for (int i = 0; i < this->m; i++) {
		for (int j = 0; j < this->n; j++) {
			k = i * n + j;
			sum[k] = this->getElement(i, j) - b->getElement(i, j);
		}
	}
	// Create new Matrix
	Matrix<T> *A = new Matrix<T>(this->m, this->n, sum);
	delete[] sum;
	return A;
}

// Multiply the current matrix by the parameter
template <class T>
Matrix<T>* Matrix<T>::multiply(Matrix *B) {
	if (this->n != B->getRows()) {
		// Operation cannot be performed
		return NULL;
	}
	T sum;
	int index;
	// Declare row-major-order array to store mult
	T *mult = new T[this->m*B->getColumns()];
	for (int i = 0; i < this->m; i++) {
		for (int k = 0; k < B->getColumns(); k++) {
			// For each column k of B
			// Cik = sum(Aij*Bjk)
			sum = *(new T(0));
			for (int j = 0; j < this->n; j++) {
				sum = sum + this->getElement(i, j)*B->getElement(j, k);
			}
			// sum now contains the value of Cik
			index = i * B->getColumns() + k;
			mult[index] = sum;
		}
	}
	// Create new matrix
	Matrix<T> *C = new Matrix<T>(this->m, B->getColumns(), mult);
	delete[] mult;
	return C;
}

template <class T>
void Matrix<T>::toString() {
	for (int i = 0; i < this->m; i++) {
		cout << "|";
		for (int j = 0; j < this->n; j++) {
			// K is the current position of the matrix
			int k = i * this->n + j;
			cout << " " << this->matrix[k] << " ";
		}
		cout << "|"<<endl;
	}
	cout << endl;
}

template <class T>
Matrix<T>::~Matrix() {
	delete this->matrix;
}