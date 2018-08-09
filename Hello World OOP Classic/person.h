#pragma once
#include <string>

#define WINPAUSE system("pause")

using namespace std;

class Person {
private:
	string name;
public:
	Person();
	Person(string);
	void sayHello();
};