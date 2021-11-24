#ifndef MAZE_
#define MAZE_

#include "Point2D.h"
#include <vector>

class robot;

class maze {
protected:
	int row, col; // column, row
	std::vector<std::vector<char>> grid; 
	std::vector<robot*> rblst; // Robot list

public:
	maze(int row, int col, std::vector<robot*> rblst);
	~maze();

	std::vector<robot*> getRblst() const
	{
		return this->rblst;
	}

	void setRblst(std::vector<robot*> rl)
	{
		this->rblst = rl;
	}

	virtual void display();
	virtual void generateWall();
	virtual void generateExit();

	friend class robot;
};

#endif