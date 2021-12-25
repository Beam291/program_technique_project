#ifndef DOWNROBOT_
#define DOWNROBOT_

#include "robot.h"

class downRobot : public robot {
private:

public:
	//constructor
	downRobot();
	downRobot(Point2D initPos);
	downRobot(Point2D initPos, std::vector<Point2D> covered);

	//destructor
	~downRobot();

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

