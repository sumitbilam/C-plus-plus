#include <iostream>
#include <vector>	
using namespace std;

/*Now consider the following situation.we want to update two vectors using the push_back function and either we update 
both vectors or neither of them to keep them synchronised.If we look at the std::vector documentation we will see 
push_back can throw an exception if the allocation fails.So If the first vector update succeeds but the second vector 
update fails then we have to roll back the update to the first vector.We could write some code like the following.*/

void updateVector(vector<string> &firstvector, vector<string> &secondvector, string newstring)
{
	firstvector.push_back(newstring); //firstvector push_back successfully happened
	try
	{
		secondvector.push_back(newstring); //if second.push_back failed 
	}
	catch (...) //catch all exception
	{
		firstvector.pop_back(); //then undo the firstvector.push_back()
		cout << "second vector update failed" << endl;
	}
}

void updateVector2(vector<string> &firstvector, vector<string> &secondvector, string newstring)
{
	firstvector.push_back(newstring); //here firstvector vector size became 2 because from main we called this fucntio
									// after we called the above func
	try
	{
		bad_alloc excep; //but purposely we threw this exception 
		throw excep;
		secondvector.push_back(newstring);// and we made secodvector update failed
	}
	catch (...) //shouldn't it be catch(exception &e) since we are throwing exception library bad_alloc excep
	{
		firstvector.pop_back(); //This is the fix, it poped back the firstvector and bring back the size of 1 and
								//obviously second vector never get updated
		cout << "second vector update failed" << endl;
	}
}

int main()
{
	vector<string> firstvector;
	vector<string> secondvector;
	string newstring = "hello world";

	cout << "Calling updatevector" << endl;
	updateVector(firstvector, secondvector, newstring);
	cout << "fistvector size is" << firstvector.size() << " " << "secondvector size is: " << secondvector.size() << endl;

	cout << "Calling updateVector2" << endl;
	updateVector2(firstvector, secondvector, newstring);
	cout << "fistvector size is" << firstvector.size() << " " << "secondvector size is: " << secondvector.size() << endl;


	system("pause");
	return 0;
}