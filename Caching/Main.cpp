#include<iostream>
#include<vector>
#include<ctime> //for clock functionality
using namespace std;

int main()
{
	vector<int> myvec;
	vector<int> myvec2;
	clock_t clock_time;

	clock_time = clock();

	for (int i = 0; i < 99999; i++)
	{
		myvec.push_back(99);
	}
	clock_time = clock() - clock_time;
	printf("Loop without index in register took %f seoonds \n", ((float)clock_time / CLOCKS_PER_SEC));

	myvec.clear();

	clock_time = clock();
	for (register int i = 0; i < 99999; i++)
	{
		myvec2.push_back(99);
	}
	clock_time = clock() - clock_time;

	myvec2.clear();

	printf("Loop with index in register took %f seconds", ((float)clock_time / CLOCKS_PER_SEC));

	alignas(16) int a[4];
	alignas(1024) int b[4];

	printf("%p\n", a);
	printf("%p\n", b);

	if (_alignof(a) == 16)
	{
		cout << "int a is aligned to 16 bytes" << endl;
	}
	if (_alignof(b) == 1024)
	{
		cout << "int b is aligned to 1024 bytes" << endl;
	}



	system("pause");
	return 0;
}