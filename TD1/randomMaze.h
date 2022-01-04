#ifndef RANDOMMAZE_
#define RANDOMMAZE_

#include "maze.h"
#include "robot.h"

class robot;

class randomMaze : public maze {
private:
	int wallNumber, wallLength;
	int col, row;

public:
	//Constructor
	randomMaze(int row, int col, int wallNumber, int wallLength, std::vector<robot*> rblist);
	
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

	friend class robot;
};

#endif