#ifndef LEFTROBOT_
#define LEFTROBOT_

#include "point2D.hpp"
#include "robot.h"

class leftRobot : public robot {
private:

public:
	//constructor
	leftRobot();
	leftRobot(Point2D initPos);
	leftRobot(Point2D initPos, std::vector<Point2D> covered);

	//destructor
	~leftRobot();

	//getter
	Point2D getInitPos() const;
	std::vector<Point2D> getCovered() const;

	//setter
	void setInitPos(); //random position
	void setInitPos(Point2D initPos); //position which has been pre-defined
	void setCovered(Point2D newPos); //covered will get new position which cover all point of robot

	void go() override;
};

#endif LEFTROBOT_

