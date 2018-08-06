#pragma once
#include "Person.h"


class Student : public Person
{
private:
	string course;

public:
	Student();

	Student(string name, int age, string course);

	virtual const void display();

	virtual ~Student();
};
