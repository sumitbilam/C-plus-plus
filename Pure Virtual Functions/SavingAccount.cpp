#include "SavingAccount.h"
#include"BankAccount.h"
#include "Freezable.h"
#include "logable.h"
#include <iostream>
using namespace std;
#include <string>

//we are not including bool frozen as a parameter here since we didn't add that in our SavingAccount.h file either
SavingAccount::SavingAccount(double initialBalance, double interestRate) :BankAccount(initialBalance)
{
	interestRate = interestRate;
	frozen = false;
}

SavingAccount ::~SavingAccount()
{

}

void SavingAccount::earnInterest()
{
	if (!frozen) //if the account isn't frozen
	{
		double interest = balance * (interestRate / 100);
		deposit(interest);
	}
}

void SavingAccount::deposit(double amount)
{
	if (!frozen)
	{
		BankAccount::deposit(amount); //calling BankAccount deposit method
		log("Deposit: " + to_string(amount)); //to_string method converts numerical value and return them as sequence of
											  //character, note + sign is mandatory here
	}
}

void SavingAccount::withdraw(double amount)
{
	if (!frozen && amount <= balance) //looks like we can just direct access the balance here even though it is declared as protected
	{
		BankAccount::withdraw(amount); //calling BankAccount class withdraw method
		log("Withdraw: " + to_string(amount));
	}
}

string SavingAccount::getTermAndCondition()
{
	return "This is the saving account. You can not over draw, you earn interest ";
}

double SavingAccount::getGuaranteedLimit()
{
	return 7500;
}

void SavingAccount::freeze()
{
	frozen = true;
}

void SavingAccount::unfreeze()
{
	frozen = false;
}

void SavingAccount::log(const string &message) const
{
	cout << message << endl;
}