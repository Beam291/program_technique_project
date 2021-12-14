#ifndef MAZE_
#define MAZE_

#include <vector>
#include <iostream>

class maze {
protected:
	int row, col; // row and column
	std::vector<std::vector<int>> map; //use vector of vector to contain maze info

public:
	//contructor
	maze();
	maze(int row, int col);

	//destructor
	~maze();

	//getters
	int getRow() const;
	int getCol() const;

	//setter
	void setRow(int row);
	void setCol(int col);

	virtual void mazeStructure(); //create maze
	virtual void generateWall(); //generate wall
	virtual void display(); //display

	friend class robot;
};

#endif
