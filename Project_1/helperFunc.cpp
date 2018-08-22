#include"stdafx.h"
#include <iostream>
using namespace std;

void board(char box[])
{
	system("cls"); //clear screen
	cout << "Welcome to TIC TAC TOE" << endl;
	cout << "Player 1 (X)            Player 2  (O)" << endl << endl;

	cout << "    |    |    " << endl;
	cout << " "<< box[1] << "  | " << box[2] << "  | " << box[3]<<"  " << endl;
	cout << "____|____|____" << endl;
	cout << " " << box[4] << "  | " << box[5] << "  | " << box[6] << "  " << endl;
	cout << "____|____|____" << endl;
	cout << " " << box[7] << "  | " << box[8] << "  | " << box[9] << "  " << endl;
	cout << "    |    |    " << endl;
}

int winLoseTie(char box[])
{
	if (box[1] == box[2] && box[2] == box[3])
	{
		return 1;
	}
	else if (box[4] == box[5] && box[5] == box[6])
	{
		return 1;
	}
	else if (box[7] == box[8] && box[8] == box[9])
	{
		return 1;
	}
	else if (box[1] == box[4] && box[4] == box[7])
	{
		return 1;
	}
	else if (box[2] == box[5] && box[5] == box[8])
	{
		return 1;
	}
	else if (box[3] == box[6] && box[6] == box[9])
	{
		return 1;
	}
	else if (box[1] == box[5] && box[5] == box[9])
	{
		return 1;
	}
	else if (box[3] == box[5] && box[5] == box[7])
	{
		return 1;
	}
	else if (box[1] != '1' && box[2] != '2' && box[3] != '3' && box[4] != '4' && box[5] != '5' && box[6] != '6'
		&& box[7] != '7' && box[8] != '8' && box[9] != '9')
	{
		return 0;
	}
	else
	{
		return -1;
	}
	
}