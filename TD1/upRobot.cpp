#include "upRobot.h"

upRobot::upRobot() : robot() {
}

upRobot::upRobot(Point2D initPos) : robot(initPos) {

}

upRobot::upRobot(Point2D initPos, std::vector<Point2D> covered) :
	robot(initPos, covered) {
}

upRobot::~upRobot() {

}

Point2D upRobot::getInitPos() const {
	return this->initPos;
}

std::vector<Point2D> upRobot::getCovered() const {
	return this->covered;
}

void upRobot::setInitPos() {

}

void upRobot::setInitPos(Point2D initPos) {
	this->initPos.setX(initPos.getX());
	this->initPos.setX(initPos.getX());
}

void upRobot::setCovered(Point2D newPos) {
	this->covered.push_back(newPos);
}

void upRobot::go() {
	if (map_r[initPos.getX()][initPos.getY()] == 2) {
		//std::cout << "upRobot have been escaped" << std::endl;
		//robot will disspear
	}
	else {
		//in case robot spawned in (0, n), robot can't not move, so X always != 0
		if (initPos.getX() != 0) {
			if (map_r[initPos.getX() - 1][initPos.getY()] == 0 || map_r[initPos.getX() - 1][initPos.getY()] == 2)
			{
				covered.push_back(initPos);
				map_r[initPos.getX()][initPos.getY()] = 0;  // Clear old position 

				initPos.setX(initPos.getX() - 1);
				initPos.setY(initPos.getY());
			}
		}

		map_r[initPos.getX()][initPos.getY()] = 6;

		//security measure if there is some change public_map
		if (public_map_r != map_r) {
			public_map_r = map_r;
		}
	}
}