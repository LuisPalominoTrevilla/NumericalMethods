#pragma once
#include <string>

using namespace std;

template <class T>
class Matrix {
public:
	/* CONSTRUCTORS */
	Matrix(int rows, int cols, T* matrix);
	/* SETTERS */
	void setMatrix(int m, int n, T* matrix);
	void setElement(int i, int j, T value);
	/* GETTERS */
	int getRows();
	int getColumns();
	T getElement(int i, int j);
	/* ANALYZERS */
	void toString();
	T getDeterminant();
	Matrix<T>* getInverse();
	/* OPERATIONS */
	void exchangeRows(int r1, int r2);
	void RREF(bool &consistent);
	Matrix<T>* transposed();
	Matrix<T>* sum(Matrix<T> *b);
	Matrix<T>* subtract(Matrix<T> *b);
	Matrix<T>* multiply(Matrix<T> *b);
	~Matrix();
private:
	int m, n;
	T* matrix;
};