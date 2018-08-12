#include"tempStat.h"
#include<iostream>
#include<fstream>
using namespace std;

void simpleWriteToFile();
void displayAllStat();
void updateTemp(int index);
void getMonthTemp(int index);

int main()
{
	int index;
	simpleWriteToFile();
	displayAllStat();

	cout << "which month you want to change the temperature:";
	cin >> index;
	updateTemp(index);
	displayAllStat();

	cout << "For what month you need the data for:";
	cin >> index;
	getMonthTemp(index);

	system("pause");
	return 0;
}

//-----------------------helper methods-------------------------------

void simpleWriteToFile()
{
	ofstream ofile("temp.bin", ios_base::binary);//this creates the temp.bin file

	if (ofile.is_open())
	{
		tempStat(1.0, 10.0).writeToFile(ofile);
		tempStat(2.0, 11.0).writeToFile(ofile);
		tempStat(3.0, 12.0).writeToFile(ofile);
		tempStat(4.0, 13.0).writeToFile(ofile);
		tempStat(5.0, 14.0).writeToFile(ofile);
		tempStat(6.0, 15.0).writeToFile(ofile);
		tempStat(7.0, 16.0).writeToFile(ofile);
		tempStat(8.0, 17.0).writeToFile(ofile);
		tempStat(9.0, 18.0).writeToFile(ofile);
		tempStat(10.0, 18.0).writeToFile(ofile);
		tempStat(11.0, 19.0).writeToFile(ofile);
		tempStat(12.0, 20.0).writeToFile(ofile);

		ofile.close();
		cout << "Finished writing to temp.bin file" << endl;
	}
	else
	{
		cerr << "Error opening temp.bin file. This is simpleWriteToFile func" << endl;
	}
	
}
void displayAllStat()
{
	cout << "This is the current data" << endl;
	//Note we used fstream here because we have to do both read and write 
	fstream ifile("temp.bin", ios_base::binary|ios_base::in|ios_base::out); 

	if (ifile.is_open())
	{
		int index = 0;
		while (!ifile.eof())
		{
			tempStat ts;
			ts.readFromFile(ifile);

			if (ifile.gcount() == 0)
			{
				break; //can't read anymore bytes
			}
			cout << "index " << index;
			cout << ",Temperature   " << ts.minimum << "," << ts.maximum << endl;
			index++;
		}
		ifile.close();
	}
	else
	{
		cerr << "error opening file" << endl;
	}
}

void updateTemp(int index)
{
	tempStat ts;
	cout << "Enter min temp for" << index<< "month";
	cin >> ts.minimum;
	cout << "Enter max temp for" << index << "month";
	cin >> ts.maximum;

	fstream ofile("temp.bin", ios_base::binary |ios_base::in |ios_base::out); //opening in binary mode again
	if (ofile.is_open())
	{
		ts.writeToFile(ofile, index);

		ofile.close();
	}
	else
	{
		cerr << "not being able to update" << endl;
	}
}

void getMonthTemp(int index)
{
	fstream ifile("temp.bin", ios_base::binary |ios_base::in |ios_base::out);

	if (ifile.is_open())
	{
		tempStat ts;
		ts.readFromFile(ifile, index);
		cout << "index " << index;
		cout << ",Temperature   " << ts.minimum << "," << ts.maximum << endl;

		ifile.close();
	}
	else
	{
		cerr << "error opening file" << endl;
	}
}
