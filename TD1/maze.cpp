#include "maze.h"
#include <Windows.h>
maze::maze() {
}

maze::maze(int row, int col, std::vector<robot*> rblist) {
	this->row = row;
	this->col = col;
	this->rblist = rblist;
}

maze::~maze() {
}

int maze::getRow() const {
	return this->row;
}

int maze::getCol() const {
	return this->col;
}

std::vector<robot*> maze::getRblist() const {
	return this->rblist;
}

void maze::setRow(int row) {
	this->row = row;
}

void maze::setCol(int col) {
	this->col = col;
}

void maze::setRblist(std::vector<robot*> rblist) {
	this->rblist = rblist;
}

void maze::mazeStructure() {
	std::vector<std::vector<int>> map(row, std::vector<int>(col, 0));
	this->map = map;
}

void maze::generateWall() {
}

void maze::display(){
	char dot = '.';
	char plus = '+';
	char x = 'x';

	for (auto i : map) {
		for (int j : i) {
			if (j == 0) {
				std::cout << dot << " ";
			}
			else if (j == 1) {
				std::cout << plus << " ";
			}
			else if (j == 2) {
				std::cout << x << " ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}