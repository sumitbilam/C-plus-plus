#include "BankAccount.h"
#include"Freezable.h"
#include "logable.h"
#include "SavingAccount.h"
#include <iostream>
#include <string>
using namespace std;

void freezeMe(Freezable & f)
{   
	//we don't know what type of object f refers to, all we know it implements "Freezable"
	f.freeze();
}

int main()
{
	SavingAccount acc(1000, 10);

	cout << "Term and conditions are:" << acc.getTermAndCondition() << endl;
	cout << "Guranteed limit is: " << acc.getGuaranteedLimit() << endl;

	acc.deposit(500);
	acc.withdraw(200);
	acc.earnInterest();

	acc.freeze();




	system("pause");
	return 0;
}
