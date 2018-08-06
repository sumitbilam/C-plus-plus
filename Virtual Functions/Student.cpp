#include "Student.h"
#include <string>

Student::Student():Person()
{
}

Student::Student(string name, int age, string course):Person(name, age)
{
	this->course = course;
}

//don't do const void Student::display():Person::display() this only works for constructor and destructor 
//now overriding the display method
const void Student::display()
{
	cout << "You are in Student version of display method" << endl;
	//call base class version of display to show Person related info
	Person::display();

	//now display derived class or student related info
	cout << course << endl;
}

/*
	You cannot invoke Person destructor, Person destrutor gets call automatically once the Student destructor get called
	Destructor goes in reverse order than constructor I mean when we call constructor of Student, Person constructor get
	called first then Student constructor but in destructor case Student destructor get called first then Person
	destructor
*/
Student::~Student()
{
	cout << "Goodbye fro Student destructor " << endl;
}
