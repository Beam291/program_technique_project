#include "leftRobot.h"

leftRobot::leftRobot() : robot() {
}

leftRobot::leftRobot(Point2D initPos) : robot(initPos) {

}

leftRobot::leftRobot(Point2D initPos, std::vector<Point2D> covered) :
	robot(initPos, covered) {
}

leftRobot::~leftRobot() {

}

Point2D leftRobot::getInitPos() const {
	return this->initPos;
}

std::vector<Point2D> leftRobot::getCovered() const {
	return this->covered;
}

void leftRobot::setInitPos() {

}

void leftRobot::setInitPos(Point2D initPos) {
	this->initPos.setX(initPos.getX());
	this->initPos.setX(initPos.getX());
}

void leftRobot::setCovered(Point2D newPos) {
	this->covered.push_back(newPos);
}

void leftRobot::go() {
	if (map_r[initPos.getX()][initPos.getY()] == 2) {
		//std::cout << "leftRobot have been escaped" << std::endl;
		//robot will disspear
	}
	else {
		//in case robot spawned in (n,0), robot can't not move, so Y always != 0
		if (initPos.getY() != 0) {
			if (map_r[initPos.getX()][initPos.getY() - 1] == 0 || map_r[initPos.getX()][initPos.getY() - 1] == 2) {
				covered.push_back(initPos);
				map_r[initPos.getX()][initPos.getY()] = 0;  //Clear old position 

				initPos.setX(initPos.getX());
				initPos.setY(initPos.getY() - 1);
			}
		}

		map_r[initPos.getX()][initPos.getY()] = 4;

		//security measure if there is some change public_map
		if (public_map_r != map_r) {
			public_map_r = map_r;
		}
	}
}