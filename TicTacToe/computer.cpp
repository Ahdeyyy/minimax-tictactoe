#include "computer.h"

Computer::Computer(char computer)
{
	if (computer == 'x')
	{
		 this -> comp = 'x';
		 this -> human = 'o';
	}
	else if (computer == 'o')
	{
		this -> comp = 'o';
		this -> human = 'x';
	}
}
int Computer::randomMove(Board board)
{
	int emptyCells[9] ;
	int emptySize = 0;
	for (int i = 0; i < 9; i++)
	{
		if (board.isEmpty(i + 1))
		{
			emptyCells[i] = i + 1;
			emptySize++;
		}
	}
	int randPos = rand() % emptySize;
	return emptyCells[randPos];
}
int Computer::bestMove(Board board , char nextPlayer)
{
	int bestVal = MIN;
	int bestMove = 0;
	for (int i = 1; i < 10; i++)
	{
		if (board.isEmpty(i))
		{
			board.writeInPos(i, comp, false);
			int posVal = minimax(board, 0, false);
			board.undo(i);
			if (posVal > bestVal)
			{
				bestMove = i;
				bestVal = posVal;
			}
		}
	}
	return bestMove;
}
int Computer::minimax(Board board, int depth,bool isMaxer)
{
	if (board.Winner(comp) == true)
	{
		return 10 - depth;
	}
	if (board.Winner(human) == true)
	{
		return -10 + depth;
	}
	if (board.Draw() == true)
	{
		return 0;
	}
	
		if (isMaxer)
		{
			int best = MIN;
			for (int i = 1; i < 10; i++)
			{
				if (board.isEmpty(i) == true)
				{
					board.writeInPos(i,comp, false);
					best = std::max(best,minimax(board, depth + 1,false));
					board.undo(i);
				}
			}
			return best;
		}
		else
		{
			int best = MAX;
			for (int i = 1; i < 10; i++)
			{
				if (board.isEmpty(i) == true)
				{
					board.writeInPos(i,human, false);					
					best = std::min(best,minimax(board, depth + 1,true));
					board.undo(i);
				}
			}
			return best;
		}
	
}
