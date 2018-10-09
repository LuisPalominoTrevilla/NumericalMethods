#pragma once
#include <iostream>
#include "Rational.h"

using namespace std;

class Complex {
public:
	Complex(int real1, int reald1, int i1, int id1);
	Complex(int real1, int i1);
	Complex(Rational *real, Rational *imag);
	Rational getReal();
	Rational getImaginary();
	Complex* operator+(const Complex&cmp);
	Complex* operator-(const Complex&cmp);
	Complex* operator*(const Complex&cmp);
	Complex* operator/(const Complex&cmp);
	~Complex();
	friend ostream& operator<<(ostream& os, const Complex & cmp);
private:
	Rational *real, *imaginary;
};

ostream& operator<<(ostream& os, const Complex & cmp);