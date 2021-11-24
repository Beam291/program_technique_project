#include "maze.h"
#include <vector>
#include <iostream>

maze::maze(int row, int col, std::vector<robot*> rblst) {
	this->row = row;
	this->col = col;
	std::vector<std::vector<char>> grid(row, std::vector<char>(col, '.'));
	this->grid = grid;
    this->rblst = rblst;
}

maze::~maze() {}

void maze::display(){
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void maze::generateWall() {}
void maze::generateExit() {}