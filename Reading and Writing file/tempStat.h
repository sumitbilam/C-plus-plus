#pragma once
#include<iostream>
using namespace std;


class tempStat
{
public:
	double minimum, maximum;
	static const size_t RECORD_SIZE = 2 * sizeof(double); //created const so we can move around in file

	tempStat(double min = 0.0, double max = 0.0)
		:minimum(min), maximum(max)
	{}

	/*writeToFile method: write to the file. Actually we wont be using this method, it is just for your understanding
	that how write() mehtod works because we will be overloading it and that method we will use*/
	void writeToFile(ostream &os)
	{
		os.write((char*)&minimum, sizeof(double)); //writing minimum variable to file, Note: write() is in build method
												   //write() writes the 8byte variable and bring the cursor position at the end of the 8byte
		os.write((char*)&maximum, sizeof(double)); //writing maximum variable to file
	}

	/*readToFile method: write to the file. Actually we wont be using this method, it is just for your understanding
	that how read() mehtod works because we will be overloading it and that method we will use*/
	void readFromFile(istream &is)
	{
		is.read((char*)&minimum, sizeof(double)); //reading from minimum variable from the file and reading position is now at the end of 8byte 
		is.read((char*)&maximum, sizeof(double)); //reading fromm maximum variable from file
	}

	//now will go the the actual position we want to write at
	//overloading writeToFile
	void writeToFile(ostream &os, int index)
	{
		streampos pos(index * RECORD_SIZE); //streampos is in build method in <iostream>, Remember we defined RECORD_SIZE = 16 byte
		os.seekp(pos); //now going to the pos position so that we can write

		cout << "Now writing the temperature at" << os.tellp() << endl; //os.tellp() gives you the current position
		os.write((char*)&minimum, sizeof(double)); //now calling write() in build method
		os.write((char*)&maximum, sizeof(double));
	}
	//now will go the the actual position we want to read from 
	//overloading readFromFile
	void readFromFile(istream &is, int index)
	{
		streampos pos(index * RECORD_SIZE);
		is.seekg(pos); //Note:here we using seekg() not seekp() to get the position to read from

		cout << "Reading from the position: " << is.tellg() << endl; // again tellg() not tellp()
		is.read((char*)&minimum, sizeof(double));
		is.read((char*)&maximum, sizeof(double));

	}
};
