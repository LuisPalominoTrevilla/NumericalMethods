#include <iostream>
#include <string>
#include "myFunctions.h"

int main() {
	string name;
	cout << "Mombre:";
	cin >> name;
	sayHello(name);	// Llamada a la funci�n
	WINPAUSE;
	return 0;
}
