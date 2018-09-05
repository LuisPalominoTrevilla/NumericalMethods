#include <iostream>
#include "errors.h"
#include <iomanip>
#include <math.h>
#define PI 3.141592654

using namespace std;

#define WINPAUSE system("pause")

void testErrors();
void sumLargeSmall();
void sumLargeSmallV2();
void sumLargeSmallV3();
void sumExpression();
void sumExpressionV2();
void trigExpression();
void calculateY(float, float);
void firstGradeEq(float, float);

int main() {
	/**sumLargeSmall();
	sumLargeSmallV2();
	sumLargeSmallV3();**/
	/**sumExpression();
	sumExpressionV2();**/
	//trigExpression();
	//calculateY(10.4, 3.4);
	firstGradeEq(0, 7);
	WINPAUSE;
	return 0;
}

void firstGradeEq(float a, float b) {
	float epsilon = 1.e-7;
	if (abs(a) <= epsilon) {
		cout << "Indeterminate solution" << endl;
		return;
	}
	float x = -b / a;
	cout << "result is " << x << endl;
}

void calculateY(float r, float h){
	float y = (sqrt(8)*PI*pow(r, 2)*h + 3 * sqrt(32)*PI*pow(r, 3)*pow(h, 2) + sqrt(50)*PI) / sqrt(2)*PI*(r + pow(h, 5));
	cout << "Result of y without simplifying is: " << y << endl;
	y = (2 * pow(r, 2)*h + 12 * pow(r, 3)*pow(h, 2) + 5) * (r + pow(h, 5));
	cout << "Result of y after simplifying is: " << y << endl;
}

void trigExpression() {
	double A2, x2, y2;
	float A, x, y;
	A = .31;
	A2 = .31;
	// Inciso a
	x = .01*PI/180;
	x2 = .01*PI / 180;
	y = A / (1 - cos(x));
	y2 = (A2*(1+cos(x2))) / (1 - pow(cos(x2), 2));
	cout << "The single presision result for incise a is: " << y << " and the other one : " << y2 << endl;
}

void sumExpression() {
	float sum = 0;
	int n = 1000;
	for (int i = 1; i <= n; i++) {
		sum += (1 / pow(i, 2));
	}
	float rel = getRelativeError(1.64393456668, sum);
	cout << setprecision(15) << "The sum 1/i^2 without optimization gives: " << sum << " and has error " << rel <<  endl;
}
void sumExpressionV2() {
	float sum = 0;
	int n = 1000;
	for (int i = n; i >= 1; i--) {
		sum += (1 / pow(i, 2));
	}
	float rel = getRelativeError(1.64393456668, sum);
	cout << "Adding 1/i^2; i < 1000 but in reversed order:" << endl;
	cout << setprecision(15) << "The sum 1/i^2 with optimization gives: " << sum << " and has error " << rel << endl;
}

void sumLargeSmall() {
	float sum = 10000;
	for (int i = 0; i < 10000; i++) {
		sum += .0001;
	}
	float rel = getRelativeError(1001, sum);
	cout << "Adding ten thousands .0001 to 10000 gives: " << endl;
	cout << "The sum is " << sum << " and the relative error is " << rel << endl;
}
void sumLargeSmallV2() {
	float sum = 0;
	for (int i = 0; i < 10000; i++) {
		sum += .0001;
	}
	sum += 10000;
	float rel = getRelativeError(10001, sum);
	cout << "Adding 10000 to ten thousands .0001 gives: " << endl;
	cout << "The sum is " << sum << " and the relative error is " << rel << endl;
}
void sumLargeSmallV3() {
	float sum = 10000;
	float group;
	for (int i = 0; i < 10; i++) {
		group = 0;
		for (int j = 0; j < 1000; j++) {
			group += .0001;
		}
		sum += group;
	}
	float rel = getRelativeError(10001, sum);
	cout << "Grouping values of .0001 to 10000 gives: " << endl;
	cout << "The sum is " << sum << " and the relative error is " << rel << endl;
}

void testErrors() {
	double normalizedError = getNormalizedError(3.349, 3.345);
	cout << "NormalizedError = " << normalizedError << endl;
}