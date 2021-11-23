#include "Point2D.h"
#include "maze.h"
#include "randomMaze.h"
#include <iostream>
#include <vector>

int main() {
	std::cout << "EXERCISE1 - CREATE A MAZE" << std::endl;
	maze* m = new randomMaze(15, 20, 7,14);
	m->display();

	std::cout << std::endl << "EXERCISE2 - Generate Wall" << std::endl;
	m->generateWall();
	m->generateExit();
}
