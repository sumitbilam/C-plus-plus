#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount(double initialBalance)
{
	initialBalance = initialBalance;
}

BankAccount::~BankAccount()
{

}

double BankAccount:: getBalance() const
{
	return this->balance;
}

void BankAccount::deposit(double amount)
{
	balance += amount;
}

void BankAccount::withdraw(double amount)
{
	balance -= amount;
}

