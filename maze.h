#ifndef MAZE_
#define MAZE_

#include <vector>
#include <iostream>

class maze {
private:
	int row, col; // row and column
	std::vector<std::vector<int>> mazeContainer; //use vector of vector to contain maze info

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

	void mazeStructure();
	virtual void display();
};

#endif
