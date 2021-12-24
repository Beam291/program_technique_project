#include "crazyRobot.h"

crazyRobot::crazyRobot() : robot() {
}

crazyRobot::crazyRobot(Point2D initPos) : robot(initPos) {

}

crazyRobot::crazyRobot(Point2D initPos, std::vector<Point2D> covered) :
	robot(initPos, covered) {
}

crazyRobot::~crazyRobot() {

}

Point2D crazyRobot::getInitPos() const {
	return this->initPos;
}

std::vector<Point2D> crazyRobot::getCovered() const {
	return this->covered;
}

void crazyRobot::setInitPos() {

}

void crazyRobot::setInitPos(Point2D initPos) {
	this->initPos.setX(initPos.getX());
	this->initPos.setX(initPos.getX());
}

void crazyRobot::setCovered(Point2D newPos) {
	this->covered.push_back(newPos);
}

void crazyRobot::go() {
	if (map_r[initPos.getX()][initPos.getY()] == 2) {
		//std::cout << "crazyRobot have been escaped" << std::endl;
	}
	else {
		this->randGo();
		map_r[initPos.getX()][initPos.getY()] = 3;

		//security measure if there is some change public_map
		if (public_map_r != map_r) {
			public_map_r = map_r;
		}
	}
}