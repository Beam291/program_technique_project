#ifndef MAZE_
#define MAZE_

#include <vector>
#include <iostream>

class robot;

class maze {
protected:
	int row, col; // row and column
	std::vector<std::vector<int>> map; //use vector of vector to contain maze info
	std::vector<robot*> rblist; //list of robot

public:
	//contructor
	maze();
	maze(int row, int col, std::vector<robot*> rblist);

	//destructor
	~maze();

	//getters
	int getRow() const;
	int getCol() const;
	std::vector<robot*> getRblist() const;

	//setter
	void setRow(int row);
	void setCol(int col);
	void setRblist(std::vector<robot*> rblist);

	virtual void mazeStructure(); //create maze
	virtual void generateWall(); //generate wall
	virtual void display(); //display

	friend class robot;
};

#endif
