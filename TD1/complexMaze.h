#ifndef COMPLEXMAZE_
#define COMPLEXMAZE_

#include "maze.h"

#include <iostream>
#include <vector>

class robot;

class complexMaze : public maze {
private:
	int row, col;

public:
	//contructor
	complexMaze(int row, int col, std::vector<robot*> rblist);
	
	//destructor
	~complexMaze();

	void visit(int x, int y);
	
	void mazeStructure() override;
	void display() override;

	void generateWall() override;

	friend class robot;
};

#endif