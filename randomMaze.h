#ifndef RANDOMMAZE_
#define RANDOMMAZE_

#include "maze.h"

class randomMaze : public maze {
private:
	int wallNumber, wallLength;

public:
	//Constructor
	randomMaze(int col, int row, int wallNumber, int WallLength);
	
	//Destructor
	~randomMaze();

	//Getter
	int getWallNumber() const;
	int getWallLength() const;

	//Setter
	void setWallNumber(int wallNumber);
	void setWallLength(int wallLength);

	void display() override;

};

#endif