#include"stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	char box[10] = { 'o','1','2','3','4','5','6','7','8','9' };
	int player = 1;
	int result, choice, markBox;

	board(box);

	do
	{
		player = (player % 2 == 1) ? 1 : 2;
		cout << "Its player " << player << " turn...";
		cout << "  Enter your choice: ";
		cin >> choice;

		if (isalpha(box[choice]) == 0)
		{
			markBox = (player % 2 == 1) ? 'X' : 'O';
			box[choice] = markBox;
			board(box);
		}
		else
		{
			cout << "This box has been marked previously" << endl;
		}

		result = winLoseTie(box);
		if (result == 1)
		{
			cout << "Player " << player << " won the game!!!" << endl;
		}
		else if (result == 0)
		{
			cout << "Nobody won. Game Tie" << endl;
		}
		else
		{
			result = -1;
		}
		
		player++;

	} while (result == -1);
	


	system("pause");
	return 0;
}