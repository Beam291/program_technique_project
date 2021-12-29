#ifndef VERYSMARTROBOT_
#define VERYSMARTROBOT_

#include "robot.h"
#include "scoreTree.h"

class verySmartRobot : public robot, public scoreTree {
private:
public:
	//constructor
	verySmartRobot();
	verySmartRobot(Point2D initPos);
	verySmartRobot(Point2D initPos, std::vector<Point2D> covered);

	//destructor
	~verySmartRobot();

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