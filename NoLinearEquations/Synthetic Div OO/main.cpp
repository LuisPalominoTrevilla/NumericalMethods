#include <iostream>
#include <string>

using namespace std;

#define WINPAUSE system("pause")

class Polynomial {
private:
	int order;
	double* coeficients;
public:
	Polynomial()
	{
		this->order = 0;
		// Guardar el termino independiente
		this->coeficients = new double[1];
		this->coeficients[0] = 0;
	}
	Polynomial(int n, double* coef)
	{
		this->order = n;
		this->coeficients = new double[n + 1];
		for (int i = 0; i <= this->order; i++) {
			this->coeficients[i] = coef[i];
		}
	}
	~Polynomial()
	{
		delete[] this->coeficients;
	}

	string toString()
	{
		string msg = "";
		for (int i = 0; i <= this->order; i++) {
			if (this->coeficients[i] == 0) {
				continue;
			}
			msg += ((this->coeficients[i] > 0 && i != 0) ? " + " : " ") + ((this->coeficients[i] == 1 && i > 0) ? "" : to_string(this->coeficients[i])) + ((i == 0) ? "" : (i == 1) ? "x" : ("x^" + to_string(i)));
		}
		return msg;
	}

	Polynomial* divByMonomial(double a, double &reminder)
	{
		double* q = new double[this->order];
		q[0] = this->coeficients[this->order];
		for (int i = 1; i < this->order; i++) {
			q[i] = q[i - 1] * a + this->coeficients[this->order - i];
		}
		reminder = q[this->order - 1] * a + this->coeficients[0];
		double* tmp = new double[this->order];
		for (int i = 0; i < this->order; i++) {
			tmp[i] = q[this->order - i - 1];
		}
		delete[] q;
		Polynomial* polQ = new Polynomial(this->order-1, tmp);
		delete[] tmp;
		return polQ;
	}
};

int main() {
	int n;
	double* coef;
	Polynomial* p;	// P(X)
	Polynomial* q;	// Q(x)
	double r;	// R
	double a;	// x-a

	n = 4;
	coef = new double[n + 1];
	coef[0] = 24.;
	coef[1] = -10.;
	coef[2] = -15.;
	coef[3] = 0.;
	coef[4] = 1.;
	a = -4;

	p = new Polynomial(n, coef);

	cout << "P(x) = " << p->toString() << " = 0 " << endl;
	q = p->divByMonomial(a, r);

	cout << "Q(x) = " << q->toString() << " = 0 " << endl;
	cout << "R = " << r << endl;

	delete p;
	delete q;
	delete[] coef;
	
	WINPAUSE;
	return 0;
}