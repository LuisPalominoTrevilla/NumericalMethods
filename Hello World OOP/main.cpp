#include <iostream>
#include <string>

#define WINPAUSE system("pause")

using namespace std;

class Person {
private: 
	string name;
public:
	Person() {
		this->name = "no-name";
	}
	Person(string name) {
		this->name = name;
	}
	void sayHello() {
		cout << "Hello World " << this->name << " C/C++!" << endl;
	}
};

int main() {
	string name;
	cout << "Mombre:";
	cin >> name;
	Person p1(name);	// Construye un objeto estático de la clase Person
	p1.sayHello();
	WINPAUSE;
	return 0;
}
