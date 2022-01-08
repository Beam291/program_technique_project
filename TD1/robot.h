#ifndef ROBOT_
#define ROBOT_

#include "point2D.hpp"
#include "maze.h"

#include <iostream>
#include <vector>


class robot {
protected:
	Point2D initPos;
	std::vector<Point2D> covered;
	std::vector<std::vector<int>> map_r; //copy a map for robot to read
	int jumpStep;
	
public:
	std::vector<std::vector<int>> public_map_r;

	//contructor
	robot();
	robot(Point2D initPos);
	robot(Point2D initPos, std::vector<Point2D> covered);

	void readMaze(maze* rm) {
		map_r = rm->map; //recived information about maze structure
		public_map_r = map_r;
	}

	//destructor
	~robot();

	//getter
	Point2D getInitPos() const;
	std::vector<Point2D> getCovered() const;
	int getJumpStep() const;
	
	//setter
	void setInitPos(); //random position
	void setInitPos(Point2D initPos); //position which has been pre-defined
	void setCovered(Point2D newPos); //covered will get new position 
	void setJumpStep(int jumpStep); //For jump robot

	virtual void go();
};
#endif

