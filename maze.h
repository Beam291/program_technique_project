#ifndef MAZE_
#define MAZE_

#include "Point2D.h"
#include <vector>

class maze {
protected:
	int row, col; // column, row
	std::vector<std::vector<char>> grid; 
public:
	maze(int row, int col);
	~maze();

	virtual void display();
	virtual void generateWall();
	virtual void generateExit();
};

#endif