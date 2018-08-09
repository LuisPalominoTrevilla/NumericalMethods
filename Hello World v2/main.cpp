#include <iostream>
#include <string>

#define WINPAUSE system("pause")

using namespace std;

void sayHello(string);	// Prototipo de la función

int main() {
	string name;
	cout << "Mombre:";
	cin >> name;
	sayHello(name);	// Llamada a la función
	WINPAUSE;
	return 0;
}

// Implementación de la función
void sayHello(string name) {
	cout << "Hello World " << name << " C/C++!" << endl;
}