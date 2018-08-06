#include "Person.h"
#include <iostream>
using namespace std;
#include <string>

Person::Person()
{

}

Person::Person(string n, int a)
{
	this->name = n;
	this->age = a;
}

//Remeber in implementation of virtual function you don't need to use key work virtual
const void Person::display()
{
	cout << name << "," << age << endl;
}

Person::~Person()
{
	cout << "Good Bye from the Person destructor" << endl;
}