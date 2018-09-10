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

	Polynomial* derivative() {
		double* dCoeficientes = new double[this->order];
		for (int i = 0; i < this->order; i++) {
			dCoeficientes[i] = this->coeficients[i + 1] * (i + 1);
		}
		Polynomial* dpol = new Polynomial(this->order - 1, dCoeficientes);
		delete[] dCoeficientes;
		return dpol;
	}

	double evaluate(double x) {
		double result = 0;
		for (int i = 0; i <= this->order; i++) {
			result += this->coeficients[i] * pow(x, i);
		}
		return result;
	}

	bool newtonRaphson(double x0, double tol, int iterMax, int &solutionType, double &xRoot, int &iter) {
		double x1, fx0, dfx0, en;

		Polynomial *dpol = this->derivative();
		for (int i = 1; i <= iterMax; i++) {
			fx0 = this->evaluate(x0);
			dfx0 = dpol->evaluate(x0);
			if (abs(dfx0) <= tol) {
				iter = i;
				xRoot = x1;
				solutionType = 3;
				return false;
			}
			x1 = x0 - fx0 / dfx0;
			en = abs((x1 - x0) * 100 / x1);
			if (en <= tol) {
				xRoot = x1;
				iter = i;
				solutionType = 0;
				return true;
			}
			x0 = x1;
		}
		xRoot = x1;
		iter = iterMax;
		solutionType = 1;
		return false;
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
		Polynomial* polQ = new Polynomial(this->order - 1, tmp);
		delete[] tmp;
		return polQ;
	}
};

int main() {
	int n;
	double* coef;
	double x0, tol, xRoot;
	/*	Solution Type values: 
		0 - Raíz real
		1 - No converge
		2 - falsa raíz
		3 - Indeterminación
	*/
	int iterMax, solutionType, iter;
	x0 = .6;
	tol = .000001;
	iterMax = 100000;

	// P(X) = 2x^5-2.236x^4+2x-2.236
	Polynomial* p;	// P(X)
	n = 5;
	coef = new double[n + 1];
	coef[0] = -2.236;
	coef[1] = 2;
	coef[2] = 0;
	coef[3] = 0.;
	coef[4] = -2.236;
	coef[5] = 2;
	
	p = new Polynomial(n, coef);

	cout << "P(x) = " << p->toString() << " = 0 " << endl;
	if (p->newtonRaphson(x0, tol, iterMax, solutionType, xRoot, iter))
	{
		// Se encontró una raiz
		cout << "Real root at\n xRoot " << to_string(xRoot) + " in " + to_string(iter) + " iteration" << endl;
	}
	else {
		cout << "No real root, See solution type for more details! " << to_string(solutionType) << endl;
	}

	delete p;
	delete[] coef;

	WINPAUSE;
	return 0;
}