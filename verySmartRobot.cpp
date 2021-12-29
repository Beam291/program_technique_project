#include "verySmartRobot.h"
#include <algorithm>

verySmartRobot::verySmartRobot() : robot() {
}

verySmartRobot::verySmartRobot(Point2D initPos) : robot(initPos) {

}

verySmartRobot::verySmartRobot(Point2D initPos, std::vector<Point2D> covered) :
	robot(initPos, covered) {
}

verySmartRobot::~verySmartRobot() {

}

Point2D verySmartRobot::getInitPos() const {
	return this->initPos;
}

std::vector<Point2D> verySmartRobot::getCovered() const {
	return this->covered;
}

void verySmartRobot::setInitPos() {

}

void verySmartRobot::setInitPos(Point2D initPos) {
	this->initPos.setX(initPos.getX());
	this->initPos.setX(initPos.getX());
}

void verySmartRobot::setCovered(Point2D newPos) {
	this->covered.push_back(newPos);
}

void verySmartRobot::go() {
	if (map_r[initPos.getX()][initPos.getY()] == 2) {
		//std::cout << "verySmartRobot have been escaped" << std::endl;
	}
	else {
		setRobotInitPos(Point2D(initPos.getX(), initPos.getY()));
		setScoreMap(map_r);
		potentialSensor_lv1();
		potentialSensor_lv2();

		covered.push_back(initPos);
		map_r[initPos.getX()][initPos.getY()] = 0; //clear old position 

		initPos.setX(getPotential_lv2().getX());
		initPos.setY(getPotential_lv2().getY());

		map_r[initPos.getX()][initPos.getY()] = 10;

		//security measure if there is some change public_map
		if (public_map_r != map_r) {
			public_map_r = map_r;
		}
	}
}