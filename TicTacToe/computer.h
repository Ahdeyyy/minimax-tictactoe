#pragma once
#ifndef COMPUTER_H
#define COMPUTER_H
#include "board.h"

class Computer
{
public :
	Computer(char comp);
	int randomMove(Board board);
	int minimax(Board board, int depth,bool isMaxer );
	int bestMove(Board board, char nextPlayer);
	int results[9];

private:
	const int MAX = 1000;
	const int MIN = -1000;	
	char comp ;
	char human;

};

#endif // !COMPUTER_H