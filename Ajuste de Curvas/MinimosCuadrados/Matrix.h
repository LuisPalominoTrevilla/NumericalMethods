#pragma once
#include <string>

using namespace std;

class Matrix {
public:
	/* CONSTRUCTORS */
	Matrix(int row, int col, bool isRandom);		// Default matrix constructor
	Matrix(int n);									// Creates identity matrix
	Matrix(int rows, int cols, double **matrix);	// Create matrix using a bidimensional array
	Matrix(int rows, int cols, double* matrix);		// Creates matrix using row-major-order array
	/* MODIFIERS */
	void deleteRow(int row);						// Delete row from Matrix
	void appendRow();								// Appends a row full of 0 at the end of the matrix
	void exchangeRows(int r1, int r2);
	/* ANALIZERS */
	int getRows();
	int getColumns();
	double getElement(int i, int j);
	void setElement(int i, int j, double val);
	Matrix* getRREF();
	double getDeterminant();						// Returns the determinant of the square matrix
	bool isSquare();
	bool isIdentity();
	bool isNull();
	string toString();
	/* MATRIX OPERATIONS */
	Matrix* sum(Matrix *b);							// Return sum of two matrices
	Matrix* multiply(Matrix *B);					// Multiply the current matrix by the parameter
	Matrix* preMultiply(Matrix *B);					// Multiply the parameter matrix by the current matrix
	/* DESTRUCTOR */
	~Matrix();
private:
	int m, n;
	double *matrix;
};