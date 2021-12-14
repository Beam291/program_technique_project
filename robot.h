#ifndef ROBOT_
#define ROBOT_

#include "point2D.hpp"
#include "randomMaze.h"

#include <iostream>
#include <vector>


class robot {
protected:
	Point2D initPos;
	std::vector<Point2D> covered;
	std::vector<std::vector<int>> map_r;
	
public:
	//contructor
	robot();
	robot(Point2D initPos);
	robot(Point2D initPos, std::vector<Point2D> covered);

	void readMaze(maze* rm) {
		map_r = rm->map; //recived information about maze structure
	}

	//destrucor
	~robot();

	//getter
	Point2D getInitPos() const;
	std::vector<Point2D> getCovered() const;
	
	//setter
	void setInitPos(); //random position
	void setInitPos(Point2D initPos); //position which has been pre-defined
	void setCovered(Point2D newPos); //covered will get new position which cover all point of robot

	virtual void go();
	void randGo();
};


#endif

