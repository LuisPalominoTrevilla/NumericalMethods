#include <iostream>
#include <string>
#include "myFunctions.h"

int main() {
	string name;
	cout << "Mombre:";
	cin >> name;
	sayHello(name);	// Llamada a la función
	WINPAUSE;
	return 0;
}
