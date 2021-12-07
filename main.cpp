#include "maze.h"

#include <iostream>
#include <Windows.h>

int main() {
	std::cout << "EXERCISE 1: CREATE MAZE" << std::endl << std::endl;

	maze* M = new maze(9, 9);
	M->mazeStructure();
	M->display();

	std::cout << std::endl;

	std::cout << "Press ENTER to continue..." << std::endl;
	getchar();

	std::system("cls");
}