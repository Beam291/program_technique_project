#include "maze.h"

maze::maze() {
}

maze::maze(int row, int col) {
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
	std::vector<std::vector<int>> map (row, std::vector<int>(col, 0));
	this->map = map;
}

void maze::generateWall() {
}

void maze::display(){
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			std::cout << map[i][j] << " ";
		}
		std::cout << std::endl;
	}
	//std::cout << map.size();
}