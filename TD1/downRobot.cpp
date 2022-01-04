#include "downRobot.h"

downRobot::downRobot() : robot() {
}

downRobot::downRobot(Point2D initPos) : robot(initPos) {

}

downRobot::downRobot(Point2D initPos, std::vector<Point2D> covered) :
	robot(initPos, covered) {
}

downRobot::~downRobot() {

}

Point2D downRobot::getInitPos() const {
	return this->initPos;
}

std::vector<Point2D> downRobot::getCovered() const {
	return this->covered;
}

void downRobot::setInitPos() {

}

void downRobot::setInitPos(Point2D initPos) {
	this->initPos.setX(initPos.getX());
	this->initPos.setX(initPos.getX());
}

void downRobot::setCovered(Point2D newPos) {
	this->covered.push_back(newPos);
}

void downRobot::go() {
	if (map_r[initPos.getX()][initPos.getY()] == 2) {
		//std::cout << "downRobot have been escaped" << std::endl;
	}
	else {
		//in case robot spawned in (max X, n), robot can't not move, so X always != max X
		if (initPos.getX() != (map_r.size() - 1)) {
			if (map_r[initPos.getX() + 1][initPos.getY()] == 0 || map_r[initPos.getX() + 1][initPos.getY()] == 2)
			{
				covered.push_back(initPos);
					map_r[initPos.getX()][initPos.getY()] = 0;  // Clear old position 

					initPos.setX(initPos.getX() + 1);
					initPos.setY(initPos.getY());
			}
		}

		map_r[initPos.getX()][initPos.getY()] = 7;

		//security measure if there is some change public_map
		if (public_map_r != map_r) {
			public_map_r = map_r;
		}
	}
}