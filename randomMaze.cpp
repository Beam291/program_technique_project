#include "randomMaze.h"

#include <iostream>

randomMaze::randomMaze(int row, int col, int wallNumber, int wallLength)
	: maze(row, col) {
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
	//std::cout << map.size() << std::endl;
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

	int vw = 0; // number of vertical wall 
	int hw = 0; // number of horizontal wall
	srand(time(NULL));
	for (int i = 0; i < wallNumber; ++i) { // genenrate number of vw and hw
		if (i % 2 == 0) {
			vw += 1;
		}
		else {
			hw += 1;
		}
	}

	//std::cout << vw << " " << hw << std::endl << std::endl;

	int valid = true; //valid position, object can't get through valid

	//main function
	int cvw = 0; //current vw
	if (vw != 0) {
		do {
			//random wall starter position
			int x = rand() % (map.size() - 1);
			int y = rand() % (map[0].size() - 1);
			int vos = x + wallLength; // vertical wall oversize
			if (vos > map.size()) { //checking
				continue; //vertical wall cannot be outsize of maze
			}
			else {
				for (int j = 0; j < wallLength; j++) {
					if (map[x + j][y] == valid) {
						break;
					}
				}
				for (int k = 0; k < wallLength; k++) {
					map[x + k][y] = valid;
				}
			}
			++cvw; //increase vw each time create a vertical wall
		} while (cvw < vw);
	}

	int chw = 0; //current hw
	if (hw != 0) {
		do {
			//random wall starter position
			int x = rand() % (map.size() - 1);
			int y = rand() % (map[0].size() - 1);
			int hos = y + wallLength; // horizontal wall oversize
			if (hos > map.size()) { //checking
				continue; //horizontal wall cannot be outsize of maze
			}
			else {
				for (int j = 0; j < wallLength; j++) {
					if (map[x][y + j] == valid) {
						break;
					}
				}
				for (int k = 0; k < wallLength; k++) {
					map[x][y + k] = valid;
				}
			}
			++chw; //increase hw each time create a horizontal wall
		} while (chw < vw);
	}
}

void randomMaze::generateExit() {
	srand(time(NULL));
	for(int i = 0; i < row; i++){
		for (int j = 0; j < col; j++) {
			int x = rand() % (row - 1);
			int y = rand() % (col - 1);
			if (map[x][y] != true) {
				map[x][y] = 2;
				std::cout << "Exit at x = " << x << ", y = " << y << std::endl << std::endl;
				break;
			}
		}
		break;
	}
}