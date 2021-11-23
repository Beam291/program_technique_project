#ifndef RANDOMMAZE_
#define RANDOMMAZE_

#include "maze.h"

class randomMaze : public maze {
private: 
	int row, col;
	int wallLength, wallNumber;

public:
	//constructor
	randomMaze(int row, int col, int wallLength, int wallNumber);
	
	//destructor
	~randomMaze();

	//getter
	int getWallNumber() const;
	int getWallLength() const;

	//setter
	void setWallNumber(int wallNumber);
	void setWallLength(int wallLength);

	void display() override;
	void generateWall() override;
	void generateExit() override;

};

#endif
