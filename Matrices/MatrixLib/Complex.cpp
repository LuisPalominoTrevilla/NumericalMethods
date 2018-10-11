#include <iostream>
#include "Complex.h"

using namespace std;

Complex::Complex() {
	this->real = 1.0;
	this->imaginary = 1.0;
}

Complex::Complex(double unique) {
	this->real = unique;
	this->imaginary = unique;
}

Complex::Complex(double real, double imag) {
	this->real = real;
	this->imaginary = imag;
}

double Complex::getReal() {
	return this->real;
}

double Complex::getImaginary() {
	return this->imaginary;
}

Complex Complex::operator+(const Complex&cmp) {
	double real = this->real + cmp.real;
	double imag = this->imaginary + cmp.imaginary;
	Complex cm(real, imag);
	return cm;
}

Complex Complex::operator-(const Complex&cmp) {
	double real = this->real - cmp.real;
	double imag = this->imaginary - cmp.imaginary;
	Complex cm(real, imag);
	return cm;
}

Complex Complex::operator*(const Complex&cmp) {
	double real = this->real * cmp.real;
	double imag = this->imaginary * cmp.imaginary;
	Complex cm(real, imag);
	return cm;
}

Complex Complex::operator/(const Complex&cmp) {
	double real = this->real / cmp.real;
	double imag = this->imaginary / cmp.imaginary;
	Complex cm(real, imag);
	return cm;
}

bool Complex::operator>=(const Complex&cmp) {
	return this->real >= cmp.real && this->imaginary >= cmp.imaginary;
}

bool Complex::operator<=(const Complex&cmp) {
	return this->real <= cmp.real && this->imaginary <= cmp.imaginary;
}

bool Complex::isZero() {
	return this->real <= 1.e-7 && this->imaginary <= 1.e-7;
}

ostream& operator<<(ostream& os, const Complex & cmp) {
	os << cmp.real << " + " << cmp.imaginary << "i";
	return os;
}