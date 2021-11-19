#include "randomMaze.h"
#include <iostream>

randomMaze::randomMaze(int row, int col, int wallLength, int wallNumber)
	: maze(row, col) {
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
	int xw = 0; //vertical
	int yw = 0; //horizontal

	if (wallLength < 0) {
		std::cout << "Cannot generate wall since wall length less than 0" << std::endl;;
	}

	if (wallLength > grid.size()) {
		std::cout << "Your wall length is bigger than the maze" << std::endl;
		if (wallLength > grid[0].size()) {
			return;
		}
		else {
			yw = wallNumber;
		}
	}
	if (wallLength > grid[0].size()) {
		std::cout << "Your wall length is bigger than the maze" << std::endl;
		xw = wallNumber;
	}

	srand(time(NULL));
	if (xw == 0 && yw == 0)
		for (int i = 0; i < wallNumber; ++i) (rand() % 2) != 0 ? xw += 1 : yw += 1;




}