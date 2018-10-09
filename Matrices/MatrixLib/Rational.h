#pragma once
#include <iostream>
using namespace std;

class Rational {
public:
	Rational(int n);
	Rational(int n, int d);
	int getNumerator();
	int getDenominator();
	friend ostream& operator<<(ostream& os, const Rational & rat);
	Rational* operator+(const Rational&rat);
	Rational* operator-(const Rational&rat);
	Rational* operator*(const Rational&rat);
	Rational* operator/(const Rational&rat);
private:
	int numerator, denominator;
	int gcd(int a, int b);
};

ostream& operator<<(ostream& os, const Rational & rat);