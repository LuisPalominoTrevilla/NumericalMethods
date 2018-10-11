#include "Rational.h"
#include <iostream>

using namespace std;

Rational::Rational() {
	this->numerator = 1;
	this->denominator = 1;
}

Rational::Rational(int n) {
	this->numerator = n;
	this->denominator = 1;
}

Rational::Rational(int n, int d) {
	int a = this->gcd(n, d);
	this->numerator = n/a;
	this->denominator = (d != 0) ? d/a : 1;
}

int Rational::getNumerator() {
	return this->numerator;
}
int Rational::getDenominator() {
	return this->denominator;
}

Rational Rational::operator+(const Rational& rat) {
	int n = this->numerator*rat.denominator + rat.numerator*this->denominator;
	int d = this->denominator*rat.denominator;
	int a = this->gcd(n, d);
	Rational r(n / a, d / a);
	return r;
}

Rational Rational::operator-(const Rational& rat) {
	int n = this->numerator*rat.denominator - rat.numerator*this->denominator;
	int d = this->denominator*rat.denominator;
	int a = this->gcd(n, d);
	Rational r(n / a, d / a);
	return r;
}

Rational Rational::operator*(const Rational& rat) {
	int n = this->numerator * rat.numerator;
	int d = this->denominator * rat.denominator;
	int a = this->gcd(n, d);
	Rational r(n / a, d / a);
	return r;
}

Rational Rational::operator/(const Rational& rat) {
	int n = this->numerator * rat.denominator;
	int d = this->denominator * rat.numerator;
	int a = this->gcd(n,d);
	Rational r(n / a, d / a);
	return r;
}

int Rational::gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

bool Rational::operator>=(const Rational&rat) {
	return this->numerator >= rat.numerator;
}

bool Rational::operator<=(const Rational&rat) {
	return this->numerator <= rat.numerator;
}

bool Rational::isZero() {
	return this->numerator == 0;
}

ostream& operator<<(ostream& os, const Rational& rat) {
	if (rat.denominator != 1) {
		os << rat.numerator << "/" << rat.denominator;
	}
	else {
		os << rat.numerator;
	}
	return os;
}