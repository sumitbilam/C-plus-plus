#pragma once
#include<iostream>
using namespace std;

class logable
{
public:
	/*This is the Pure virtual const func. constant func are those func which don't change the data members of the class and 
	they can only call the other const func. Also this function take the constant reference string arguement it means 
	whatever string we will pass to this function we can not change/modify its value in this function.

	Note if you put const in front of the function it means it will return the const value
	for ex: const string &getName()
			{
				return name;
			}
	this function will return const reference string 
	*/
	virtual void log(const string &message) const = 0;
};
