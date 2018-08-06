#include "Person.h"
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

void demoFucntion1(Person *ptr);
void demoFunction2(Person &pref);

int main()
{
	//This p pointer is of type Person so it can point to both either Person object or Student object
	//it is pointing to Student object here
	Person *p = new Student("Jai", 25, "Phyics");

	p->display(); // this will invoke Student version of display

	//let see some polymorphism

	demoFucntion1(p);
	demoFunction2(*p); //sending p as a reference 

	//This delete will call Student destructor first then Person destructor since destructor for both have been 
	//declared virtually
	delete p;

	system("pause");
	return 0;
}

/*
This fucntion take Pointer of type Person but since we have would pass p from main which is pointing to Student object,
it will call Student version of display
*/
void demoFucntion1(Person *ptr)
{
	ptr->display();
}

/*
	Reference is basically a pointer in disguise in c++, so basically it is referring to the same location where pointer is 
	refering since it is the reference to the pointer and since it is the Person type ref and we would pass *p which is
	Person type pointer but pointing to Student object, it will also invoke Student version of display
	method.
*/
void demoFunction2(Person &pref)
{
	pref.display();
}