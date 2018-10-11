#pragma once
#include <iostream>
#include "Rational.h"

using namespace std;

class Complex {
public:
	Complex();
	Complex(double unique);
	Complex(double real, double imag);
	double getReal();
	double getImaginary();
	Complex operator+(const Complex&cmp);
	Complex operator-(const Complex&cmp);
	Complex operator*(const Complex&cmp);
	Complex operator/(const Complex&cmp);
	bool operator>=(const Complex&cmp);
	bool operator<=(const Complex&cmp);
	friend ostream& operator<<(ostream& os, const Complex & cmp);
	bool isZero();
private:
	double real, imaginary;
};

ostream& operator<<(ostream& os, const Complex & cmp);