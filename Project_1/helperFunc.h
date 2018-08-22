#pragma once

/*
 This function will print Board as box being marked with players
*/
void board(char box[]);

/*
 This fucntion tell us which player is the winner
 returns 1 if game is over with result
 returns -1 if game is still in progress
 returns 0 if game is tie
*/
int winLoseTie(char box[]);

