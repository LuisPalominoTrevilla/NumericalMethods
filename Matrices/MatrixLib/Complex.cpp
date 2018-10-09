#include <iostream>
#include "Complex.h"
#include "Rational.h"

using namespace std;

Complex::Complex(int real1, int reald1, int i1, int id1) {
	this->real = new Rational(real1, reald1);
	this->imaginary = new Rational(i1, id1);
}

Complex::Complex(int real1, int i1) {
	this->real = new Rational(real1);
	this->imaginary = new Rational(i1);
}

Complex::Complex(Rational *real, Rational *imag) {
	this->real = real;
	this->imaginary = imag;
}

Rational Complex::getReal() {
	return *this->real;
}

Rational Complex::getImaginary() {
	return *this->imaginary;
}

Complex* Complex::operator+(const Complex&cmp) {
	Rational *real = *this->real + *cmp.real;
	Rational *imag = *this->imaginary + *cmp.imaginary;
	Complex *cm = new Complex(real, imag);
	return cm;
}

Complex* Complex::operator-(const Complex&cmp) {
	Rational *real = *this->real - *cmp.real;
	Rational *imag = *this->imaginary - *cmp.imaginary;
	Complex *cm = new Complex(real, imag);
	return cm;
}

Complex* Complex::operator*(const Complex&cmp) {
	Rational *real = *this->real * *cmp.real;
	Rational *imag = *this->imaginary * *cmp.imaginary;
	Complex *cm = new Complex(real, imag);
	return cm;
}

Complex* Complex::operator/(const Complex&cmp) {
	Rational *real = *this->real / *cmp.real;
	Rational *imag = *this->imaginary / *cmp.imaginary;
	Complex *cm = new Complex(real, imag);
	return cm;
}

ostream& operator<<(ostream& os, const Complex & cmp) {
	os << *cmp.real << " + " << *cmp.imaginary << "i";
	return os;
}

Complex::~Complex() {
	delete this->real;
	delete this->imaginary;
}