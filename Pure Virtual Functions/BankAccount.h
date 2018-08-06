#pragma once
#include<iostream>
using namespace std;

class BankAccount
{
protected:
	double balance; 

public:
	//constructor and destructor
	BankAccount(double initialBalance);
	virtual ~BankAccount();

	double getBalance() const; //this is not overrideable. Also constant func are those func which don't change the
							   //data members of the class and they can only call the other const func

	//virtual function means can be overrideable only if user want 
	virtual void deposit(double amount);
	virtual void withdraw(double amount);

	/*Pure vitural function. 
	= 0 makes them pure virtual function, this mean this function are not implemented in the base class at all.
	they are abstract methods it means they must be overridden in sub-classes. Which makes it abstract class. C++ does
	not have abstract key word like Java does.
	*/
	virtual string getTermAndCondition() = 0;
	virtual double getGuaranteedLimit() = 0;

};
