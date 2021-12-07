#include "maze.h"

maze::maze() {
}

maze::maze(int col, int row) {
	this->row = row;
	this->col = col;
}

maze::~maze() {
}

int maze::getRow() const {
	return this->row;
}

int maze::getCol() const {
	return this->col;
}

void maze::setRow(int row) {
	this->row = row;
}

void maze::setCol(int col) {
	this->col = col;
}

void maze::mazeStructure() {
	std::vector<std::vector<int>> mazeContainer (row, std::vector<int>(col, 0));
	this->mazeContainer = mazeContainer;
}

void maze::display(){
	for (int i = 0; i < mazeContainer.size(); i++)
	{
		for (int j = 0; j < mazeContainer[i].size(); j++)
		{
			std::cout << mazeContainer[i][j] << " ";
		}
		std::cout << std::endl;
	}
}