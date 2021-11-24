#include "randomMaze.h"
#include <iostream>

randomMaze::randomMaze(int row, int col, int wallLength, int wallNumber)
	: maze(row, col, rblst) {
	this->row = row;
	this->col = col;
	this->wallLength = wallLength;
	this->wallNumber = wallNumber;
}

randomMaze::~randomMaze(){}

int randomMaze::getWallLength() const {
	return this->wallLength;
}

int	randomMaze::getWallNumber() const {
	return this->wallNumber;
}

void randomMaze::setWallLength(int wallLength) {
	this->wallLength = wallLength;
}

void randomMaze::setWallNumber(int wallNumber) {
	this->wallNumber = wallNumber;
}

void randomMaze::display() {
	maze::display();
}

void randomMaze::generateWall() {
	//checking if the input legit or not
	if (wallLength < 0) {
		std::cout << "Cannot generate wall since wall length less than 0" << std::endl;
		return;
	}
	else if (wallLength > grid.size() || wallLength > grid[0].size()) {
		std::cout << "Your wall length is too long for the maze" << std::endl;
		return;
	}

	//two type of wall, vertical wall and horizontal wall
	int vw = 0;
	int hw = 0;

	srand(time(NULL));
	if (vw == 0 && hw == 0)
		for (int i = 0; i < wallNumber; ++i) {
			if ((rand() % 2) != 0) { //odd number will generate vertical wall
				vw += 1;
				
			}
			else {	//even number will generate horizontal wall
				hw += 1;
			}
		} 

	//random position of X and Y
	bool valid = true;

	//Generate Wall, wall maybe cross each other
	if (vw != 0) {
		for (int wall = 0; wall < vw; wall++) {
			int flag = 0; //checkpoint, check if this position is clear or not so wall can generate from there
			int x = rand() % (grid.size() - 1);
			int y = rand() % (grid[0].size() - 1);
			if ((x + wallLength) > grid.size()) {
				continue;
			}
			else {
				for (int i = 0; i < wallLength; i++) {
					if (flag == 0) {
						for (int j =0; j < wallLength; j++) {
							grid[x + j][y] = true;
						}
					}
					if (grid[x + i][y] == true) { //check if that start position has wall or not
						flag = 1;
						break;
					}
				}
			}
		}
	}

	if (hw != 0) {
		for (int wall = 0; wall < hw; wall++) {
			int flag = 0; //checkpoint, check if this position is clear or not so wall can generate from there
			int x = rand() % (grid.size() - 1);
			int y = rand() % (grid[0].size() - 1);
			if ((y + wallLength) > grid[0].size()) {
				continue;
			}
			else {
				for (int i = 0; i < wallLength; i++) {
					if (flag == 0) {
						for (int j = 0; j < wallLength; j++) {
							grid[x][y+j] = true;
						}
					}
					if (grid[x][y + i] == true) { //check if that start position has wall or not
						flag = 1;
						break;
					}
				}
			}
		}
	}
	
}

void randomMaze::generateExit()
{
	srand(time(NULL));
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			int x = rand() % (row - 1);
			int y = rand() % (col - 1);
			if (grid[x][y] != 1)
			{
				grid[x][y] = 'x';
				std::cout << "exit at (" << x << "," << y << ")" << std::endl;
				break;
			}

		}
		break;
	}
	display();
}