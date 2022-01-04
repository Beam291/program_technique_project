#ifndef SMARTROBOT_
#define SMARTROBOT_

#include "robot.h"

class smartRobot : public robot{
private:
public:
	//constructor
	smartRobot();
	smartRobot(Point2D initPos);
	smartRobot(Point2D initPos, std::vector<Point2D> covered);

	//destructor
	~smartRobot();

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