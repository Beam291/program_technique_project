#ifndef ROBOT_
#define ROBOT_

#include <vector>
#include <iostream>
#include "Point2D.h"
#include "randomMaze.h"

class robot {
protected:
	Point2D initPos;
	std::vector<Point2D> covered;
	std::vector<std::vector<char>> recieve;

public:
	robot();
	robot(Point2D (initPos));
	robot(Point2D (initPos), std::vector<Point2D> covered);
	~robot();

	//Getter
	Point2D getInitPos() const;
	std::vector<Point2D> getCovered() const;

	//Setter
	void setInitPos(); //random position
	void setInitPos(Point2D initPos); //position has been defind before that
	void setCovered(Point2D newPos);

	virtual void go() = 0;
	void randGo();

	std::vector<std::vector<char> > read_recieve;

	void readMaze(maze* rm) {
		recieve = rm->grid; //recieved information from maze 
		read_recieve = recieve;
	}
};

#endif
