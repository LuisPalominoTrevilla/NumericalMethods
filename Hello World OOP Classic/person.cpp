#include <iostream>
#include <string>
#include "person.h"
using namespace std;

Person::Person() {
		this->name = "no-name";
	}
Person::Person(string name) {
		this->name = name;
	}
void Person::sayHello() {
	cout << "Hello World " << this->name << " C/C++!" << endl;
}