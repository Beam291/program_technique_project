#include "Point2D.h"
#include "maze.h"
#include "randomMaze.h"
#include <iostream>
#include <vector>

int main() {
	std::cout << "EXERCISE1 - CREATE A MAZE" << std::endl;
	maze* m = new randomMaze(15, 15, 15, 3);
	m->display();
}
