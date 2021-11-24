#include "Point2D.h"
#include "maze.h"
#include "randomMaze.h"
#include "robot.h"
#include "crazyRobot.h"

#include <iostream>
#include <vector>

int main() {
	std::vector<robot*> robots;
	std::vector<int> init_list;

	std::cout << "EXERCISE1 - CREATE A MAZE" << std::endl;
	maze* m = new randomMaze(15, 20, 7,14);
	m->display();

	std::cout << std::endl << "Press ENTER to continue..." << std::endl;
	getchar();

	std::system("cls");

	std::cout << "EXERCISE2 - Generate Wall" << std::endl;
	m->generateWall();
	m->generateExit();

	std::cout << std::endl << "Press ENTER to continue..." << std::endl;
	getchar();

	//std::system("cls");
	
	
}
