#include <iostream>
#include "board.h"

Board::Board() 
{
	for (int i = 0; i < 10; i++) 
	{		
		board[i] = ' ' ;		
	}
}
bool Board::isEmpty(int pos) 
{
	if (size == 0) 
	{
		return true;
	}
	else
	{
		if (board[pos] == ' ')
		{
			return true;
		}
		else if (board[pos] == 'x' || board[pos] == 'o')
		{
			return false;
		}
	}
}
void Board::undo(int pos)
{
	board[pos] = ' ';
	size--;
	sizeEmpty++;
}
void Board::writeInPos(int pos, char player, bool _display) 
{
	if (player == 'x' || player == 'o')
	{
		if (isEmpty(pos) && pos != 0)
		{
			board[pos] = player;
			size++;
			sizeEmpty--;
		};

		if (_display == true)
		{
			display();
		}
		checkWinner(_display);
	}
}
void Board::checkWinner(bool _display)
{
	if (board[1] == 'x' && board[2] == 'x' && board[3] == 'x') { isWinner = true;	winner = 'x'; }
	if (board[1] == 'o' && board[2] == 'o' && board[3] == 'o') { isWinner = true;	winner = 'o'; }

	if (board[1] == 'x' && board[4] == 'x' && board[7] == 'x') { isWinner = true;	winner = 'x'; }
	if (board[1] == 'o' && board[4] == 'o' && board[7] == 'o') { isWinner = true;	winner = 'o'; }

	if (board[2] == 'x' && board[5] == 'x' && board[8] == 'x') { isWinner = true;	winner = 'x'; }
	if (board[2] == 'o' && board[5] == 'o' && board[8] == 'o') { isWinner = true;	winner = 'o'; }

	if (board[3] == 'x' && board[6] == 'x' && board[9] == 'x') { isWinner = true;	winner = 'x'; }
	if (board[3] == 'o' && board[6] == 'o' && board[9] == 'o') { isWinner = true;	winner = 'o'; }

	if (board[4] == 'x' && board[5] == 'x' && board[6] == 'x') { isWinner = true;	winner = 'x'; }
	if (board[4] == 'o' && board[5] == 'o' && board[6] == 'o') { isWinner = true;	winner = 'o'; }

	if (board[7] == 'x' && board[8] == 'x' && board[9] == 'x') { isWinner = true;	winner = 'x'; }
	if (board[7] == 'o' && board[8] == 'o' && board[9] == 'o') { isWinner = true;	winner = 'o'; }

	if (board[1] == 'x' && board[5] == 'x' && board[9] == 'x') { isWinner = true;	winner = 'x'; }
	if (board[1] == 'o' && board[5] == 'o' && board[9] == 'o') { isWinner = true;	winner = 'o'; }

	if (board[3] == 'x' &&  board[5] == 'x' && board[7] == 'x') { isWinner = true;	winner = 'x'; }
	if (board[3] == 'o' && board[5] == 'o' && board[7] == 'o') { isWinner = true;	winner = 'o'; }

	if (size == 9 && isWinner == false ) { isDraw = true; }

	if (isWinner == true || isDraw == true)
	{
		if(_display == true)
		{ 
		displayWinner();
		}
	}
}
void Board::displayWinner()
{
	if (isWinner == false && isDraw == false)
	{
		return ;
	}
	if (isWinner == true)
	{
		std::cout << "the winner is " <<winner<< std::endl;
		std::cout<<std::endl;
	}
	else if (isDraw == true)
	{
		std::cout << "the match is a draw " << std::endl;
	}
}
bool Board::finished()
{
	if (isWinner == true || isDraw == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int Board::getSize()
{
	return size;
}
bool Board::Draw()
{
	return isDraw;
}
int Board::SizeOfEmpty()
{
	return sizeEmpty;
}
bool Board::Winner(char player)
{
	if (winner == player)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Board::clearBoard()
{
	for (int i = 0; i < 10; i++)
	{
		board[i] =  ' ' ;
		size--;
		sizeEmpty++;
	}
	isWinner = false ;
	isDraw = false ;
	winner = ' ' ;
}
void Board::display()

{
	std::cout << board[1] << "|" << board[2] << "|" << board[3] << std::endl;
	std::cout << "------" << std::endl;
	std::cout << board[4] << "|" << board[5] << "|" << board[6] << std::endl;
	std::cout << "------" << std::endl;
	std::cout << board[7] << "|" << board[8] << "|" << board[9] << std::endl;
	std::cout << "         " << std::endl;
	

}


