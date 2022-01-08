#include "genericPoint2D.hpp"
#include "genericMaze.h"
#include "genericRandomMaze.h"

#include <iostream>
#include <vector>

int main() {
	std::vector<robot*> robots;
	std::vector<bool> check_list;

	std::cout << "EXERCISE 7: TEST MAZE." << std::endl;

	maze<int> M (15, 20, robots);
	M.mazeStructure();
	M.display();

	/*randomMaze<int> RM(15, 20, 6, 5, robots);
	RM.mazeStructure();
	RM.generateWall();
	RM.display();*/
}