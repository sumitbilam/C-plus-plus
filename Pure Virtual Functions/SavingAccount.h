#pragma once
#include"BankAccount.h"
#include"Freezable.h"
#include "logable.h"
#include <iostream>
#include <list>
using namespace std;

/*
This is polymorphism here, we are doing multiple inheritance
if you dont use public key word here then complier will default them as private 
*/
class SavingAccount:public BankAccount, public Freezable, public logable
{
private:
	double interestRate;
	bool frozen;

public:
	SavingAccount(double initialBalance, double interestRate = 0.0);
	virtual ~SavingAccount();

	void earnInterest();

	//we chose to override these two, we would not have to by the way
	virtual void deposit(double amount); 
	virtual void withdraw(double amount);

	/*But these ones we have to override since they declared as Pure virtual methods
	Remember dont set "virtual string getTermAndCondition();" = 0 here, We know this is pure virtual function and it is
	set to zero in base class already. You can not do that in derived class. Just declare it here as normal virtual
	function like "virtual void deposit(double amount);" which is just normal virtual function in base class as well
	*/
	virtual string getTermAndCondition();
	virtual double getGuaranteedLimit();

	//Implement pure virtual func from freezable class
	virtual void freeze();
	virtual void unfreeze();

	//Implement pure virtual func from logable class
	virtual void log(const string &message) const;


};
