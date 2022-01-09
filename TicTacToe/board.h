#pragma once
#ifndef BOARD_H
#define BOARD_H
#include <string>
class Board 
{
public:
	Board();
	bool isEmpty(int pos);
	void writeInPos(int pos, char player , bool _display);
	void checkWinner(bool _display);
	void displayWinner();
	bool finished();
	void display();
	void clearBoard();
	int getSize();
	void undo(int pos);
	bool Winner(char player);
	bool Draw();
	int SizeOfEmpty();
	int sizeEmpty = 9;
	
private:
	char board[10];
	
	int size = 0;
	bool isWinner{ false };
	bool isDraw{ false };
	char winner{ ' ' };
};
#endif // !BOARD_H
