#ifndef CRAZYROBOT_
#define CRAZYROBOT_

#include "robot.h"

#include <iostream>

class crazyRobot : public robot {
private:
	
public:
	//constructor
	crazyRobot();
	crazyRobot(Point2D initPos);
	crazyRobot(Point2D initPos, std::vector<Point2D> covered);

	//destructor
	~crazyRobot();

	//getter
	Point2D getInitPos() const;
	std::vector<Point2D> getCovered() const;

	//setter
	void setInitPos(); //random position
	void setInitPos(Point2D initPos); //position which has been pre-defined
	void setCovered(Point2D newPos); //covered will get new position which cover all point of robot
	
	void go() override;
};

#endif

