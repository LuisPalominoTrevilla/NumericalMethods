#include <iostream>
#include <string>
#include"person.h"

using namespace std;

int main() {
	string name;
	cout << "Mombre:";
	cin >> name;
	Person p1(name);	// Construye un objeto estático de la clase Person
	p1.sayHello();
	WINPAUSE;
	return 0;
}
