#include<iostream>
#include<vector>
#include<iterator>
#include<list>
#include<map>

using namespace std;
const double PI = 3.14;

class Circle
{
private:
	int radius;
	double area;

public:
	Circle(int rad)
	{
		radius = rad;
		area = PI * radius*radius;
	}
	//we have to over write < operator to use it in generic fucntion, you will see below
	const bool operator < (const Circle &r) const
	{
		return (area < r.area);
	}

	friend::ostream& operator << (ostream &stream, const Circle& cir)
	{
		stream << cir.area << "\n";
		return stream;
	}
};

//This is a generic function, can be used for different data type as long as < operator has been overridden
template <typename TContainer>

void bubbleSort(TContainer begin, TContainer end)
{
	TContainer i, j;
	for (i = begin; i != end; i++)
	{
		for (j = begin; j != i; j++)
		{
			if (*i < *j) // this is sorting in ascending order but fliping the sign will make it descending
			{
				swap(*i, *j);
			}
		}
	}
}

int main()
{
	vector<int> intvec;
	vector<double> doublevec;
	vector<Circle> cirvec;

	intvec.push_back(5);
	intvec.push_back(1);
	intvec.push_back(3);
	intvec.push_back(8);

	doublevec.push_back(2.5);
	doublevec.push_back(6.0);
	doublevec.push_back(3.7);
	doublevec.push_back(1.3);

	cirvec.push_back(Circle(3));
	cirvec.push_back(Circle(2));
	cirvec.push_back(Circle(9));
	cirvec.push_back(Circle(5));

	cout << "intvec before bubble sort" << endl;
	for (vector<int>::iterator it = intvec.begin(); it != intvec.end(); it++)
	{
		cout << *it<<" ";
	}
	cout << endl << endl;

	cout << "intvec after bubble sort" << endl;
	bubbleSort(intvec.begin(), intvec.end()); //bubleSort has done his job and returned us a sorted vector
	for (vector<int>::iterator it = intvec.begin(); it != intvec.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl << endl;

	cout << "doublevec before bubble sort" << endl;
	for (vector<double>::iterator it = doublevec.begin(); it != doublevec.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl; endl:
	cout << "doublevec after bubblesort" << endl;
	bubbleSort(doublevec.begin(), doublevec.end());
	for (vector<double>::iterator it = doublevec.begin(); it != doublevec.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl << endl;
	cout << "cirvec before bubble sort" << endl;
	for (vector<Circle>::iterator it = cirvec.begin(); it != cirvec.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl << endl;

	cout << "cirvec after bubble sort" << endl;
	bubbleSort(cirvec.begin(), cirvec.end());
	for (vector<Circle>::iterator it = cirvec.begin(); it != cirvec.end(); it++)
	{
		cout << *it << " ";
	}

	system("pause");
	return 0;
}
