#pragma once

#include <iostream>
using namespace std;

class Person
{
private:
	string name;

protected:
	int age;

public:
	Person();

	Person(string name, int age);

	virtual const void display() ; //This is overridable function, derived class can override it if they want to

	virtual ~Person();
};
