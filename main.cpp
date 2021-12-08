#include "maze.h"
#include "randomMaze.h"

#include <iostream>
#include <Windows.h>

int main() {
	/*std::cout << "EXERCISE 1: CREATE MAZE" << std::endl << std::endl;

	maze* M = new maze(15, 9);
	M->mazeStructure();
	M->display();

	std::cout << std::endl;

	std::cout << "Press ENTER to continue..." << std::endl;
	getchar();

	std::system("cls");*/

	std::cout << "EXERCISE 2: CREATE RANDOMMAZE WITH WALL" << std::endl << std::endl;
	//wallLength restrict: it's can't be larger than row or col
	//col, row, wallNumber, wallLength
	maze* RM = new randomMaze(15, 10, 6, 4);
	RM->mazeStructure();
	RM->generateWall();
	//RM->display();

	std::cout << std::endl;

	std::cout << "Press ENTER to continue..." << std::endl;
	getchar();
}