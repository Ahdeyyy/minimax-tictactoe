#include "board.h"
#include "computer.h"
#include <stdlib.h>
#include <iostream>

char togglePlayer(char player)
{

	if (player == 'x')
	{
		return 'o';
	}
	else
	{
		return 'x';
	}

};

int main()
{
	Board board;
	bool run{ true };
	char player;
	char computer = ' ';
	int turn{ 0 };
	int position;
	bool done{ true };
	bool multiplayer;
	char multiSelect;
	const int MIN = -1000;
	const int MAX = 1000;

	std::cout << "the numbers correspond to the position to be played on" << std::endl;
	std::cout << "1 2 3" << std::endl;
	std::cout << "4 5 6" << std::endl;
	std::cout << "7 8 9" << std::endl;


	while (done)
	{

		std::cout << "multiplayer (y/n)" << std::endl;
		std::cin >> multiSelect;

		if (multiSelect == 'y')
		{
			multiplayer = true;
			player = 'x';
			done = false;
		}
		else if (multiSelect == 'n')
		{
			multiplayer = false;
			done = false;
		}
		else
		{
			std::cout << "enter y for yes or n no" << std::endl;
		}
	}
	done = true;
	if (multiplayer == false)
	{
		std::cout << "play as x or o" << std::endl;
		while (done)
		{
			std::cin >> player;
			if (player == 'x' || player == 'o')
			{
				if (player == 'x')
				{
					computer = 'o';

				}
				else
				{
					computer = 'x';

				}
				done = false;
			}
			else
			{
				std::cout << "enter x or o" << std::endl;
			}
		}
	}

	board.display();
start:
	while (run)
	{
		//RandomAi comp;
		Computer comp(computer);
		//multiplayer on
		if (multiplayer == true)
		{
			std::cout << "choose a postion to play" << std::endl;
			std::cin >> position;
			turn++;
			system("CLS");
			board.writeInPos(position, player, true);
			player = togglePlayer(player);
			if (turn != board.getSize())
			{
				player = togglePlayer(player);
				turn--;
			}
			if (board.finished())
			{
				run = false;
			}
		}

		//multiplayer off and player is x
		if (multiplayer == false && player == 'x')
		{
		playerRetryX:

			std::cout << "choose a postion to play" << std::endl;
			std::cin >> position;
			turn++;
			system("CLS");
			board.writeInPos(position, player, true);

			if (turn != board.getSize())
			{
				turn--;
				goto playerRetryX;
			}

			if (board.finished())
			{
				run = false;
				goto start;
			}

		computerRetryX:

			system("CLS");

			board.writeInPos(comp.bestMove(board, computer), computer, true);
			turn++;

			if (turn != board.getSize())
			{
				turn--;
				goto computerRetryX;
			}

			if (board.finished())
			{
				run = false;
			}
		}

		//multiplayer off and player is o
		if (multiplayer == false && player == 'o')
		{
		computerRetryO:

			system("CLS");
			int play = comp.bestMove(board, computer);
			board.writeInPos(play, computer, true);
			turn++;

			if (turn != board.getSize())
			{
				turn--;
				goto computerRetryO;
			}

			if (board.finished())
			{
				run = false;
				goto start;
			}

		playerRetryO:

			std::cout << "choose a postion to play" << std::endl;
			std::cin >> position;
			turn++;
			//system("CLS");
			board.writeInPos(position, player, true);

			if (turn != board.getSize())
			{
				turn--;
				goto playerRetryO;
			}

			if (board.finished())
			{
				run = false;
				goto start;
			}
		}
	}
	system("PAUSE");
	return 0;
}
