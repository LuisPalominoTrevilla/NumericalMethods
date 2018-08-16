#include <iostream>
#include <cmath>

using namespace std;

#define WINPAUSE system("pause")

class Point {
private:
	double x, y;
public:
	Point() {
		this->x = 0;
		this->y = 0;
	}
	Point(double const &x, double const &y) {
		this->x = x;
		this->y = y;
	}
	double getX() {
		return this->x;
	}
	double getY() {
		return this->y;
	}
	double distanceBetweenPoints(Point p2) {
		return sqrt(pow(p2.y - this->y, 2) + pow(p2.x - this->x, 2));
	}
	bool isEqual(Point p2) {
		return p2.x == this->x && p2.y == this->y;
	}
	void moveTo(double const &x, double const &y) {
		this->x = x;
		this->y = y;
	}
	void move() {
		this->x++;
		this->y++;
	}
};

int main () {

	Point p1;
	Point p2(4.0, 3.0);
	cout << p1.distanceBetweenPoints(p2) << endl;
	cout << p1.isEqual(p2) << endl;
	p1.moveTo(4, 3);
	cout << p1.distanceBetweenPoints(p2) << endl;
	WINPAUSE;
	return 0;
}