#ifndef RANDOMMAZE_
#define RANDOMMAZE_

#include "maze.h"

class randomMaze : public maze {
private:
	int wallNumber, wallLength;
	int col, row;

public:
	//Constructor
	randomMaze(int row, int col, int wallNumber, int wallLength);
	
	//Destructor
	~randomMaze();

	//Getter
	int getWallNumber() const;
	int getWallLength() const;

	//Setter
	void setWallNumber(int wallNumber);
	void setWallLength(int wallLength);

	void mazeStructure() override;
	void display() override;

	void generateWall() override;
};

#endif