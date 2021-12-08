#include "randomMaze.h"

#include <iostream>

randomMaze::randomMaze(int col, int row, int wallNumber, int wallLength)
	: maze(col, row) {
	this->row = row;
	this->col = col;
	this->wallNumber = wallNumber;
	this->wallLength = wallLength;
}

randomMaze::~randomMaze() {
}

int randomMaze::getWallLength() const {
	return this->wallLength;
}

int randomMaze::getWallNumber() const {
	return this->wallNumber;
}

void randomMaze::setWallNumber(int wallNumber) {
	this->wallNumber = wallNumber;
}

void randomMaze::setWallLength(int wallLength) {
	this->wallLength = wallLength;
}

void randomMaze::mazeStructure() {
	maze::mazeStructure();
}

void randomMaze::display() {
	maze::display();
}

void randomMaze::generateWall() {
	if (wallLength < 0) { //wallLength cannot negative
		std::cout << "Your input is invalid" << std::endl;
		return;
	}
	if (wallLength > map.size()){ //wallLength cannot larger than row
		std::cout << "Your input is invalid" << std::endl;
		return;
	}
	if (wallLength > map[0].size()) { //wallLength cannot larger than col
		std::cout << "Your input is invalid" << std::endl;
		return;
	}

	int x, y; //find wall starter point
	int vw, hw; //Vertical wall, horizontal wall, below to find how many vw and hw
	srand(time(NULL));
	for (int i = 0; i < wallNumber; ++i) {
		std::cout << i;
	}
	int ranX = rand() % (map.size() - 1);
	int ranY = rand() % (map[0].size() - 1);

	//std::cout << ranX << " " << ranY ;
	//if(x + wallLength > grid)

}

void randomMaze::generateExit() {

}