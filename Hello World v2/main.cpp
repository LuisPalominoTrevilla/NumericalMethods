#include <iostream>
#include <string>

#define WINPAUSE system("pause")

using namespace std;

void sayHello(string);	// Prototipo de la funci�n

int main() {
	string name;
	cout << "Mombre:";
	cin >> name;
	sayHello(name);	// Llamada a la funci�n
	WINPAUSE;
	return 0;
}

// Implementaci�n de la funci�n
void sayHello(string name) {
	cout << "Hello World " << name << " C/C++!" << endl;
}