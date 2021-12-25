#include "rightRobot.h"

rightRobot::rightRobot() : robot() {
}

rightRobot::rightRobot(Point2D initPos) : robot(initPos) {

}

rightRobot::rightRobot(Point2D initPos, std::vector<Point2D> covered) :
	robot(initPos, covered) {
}

rightRobot::~rightRobot() {

}

Point2D rightRobot::getInitPos() const {
	return this->initPos;
}

std::vector<Point2D> rightRobot::getCovered() const {
	return this->covered;
}

void rightRobot::setInitPos() {

}

void rightRobot::setInitPos(Point2D initPos) {
	this->initPos.setX(initPos.getX());
	this->initPos.setX(initPos.getX());
}

void rightRobot::setCovered(Point2D newPos) {
	this->covered.push_back(newPos);
}

void rightRobot::go() {
	if (map_r[initPos.getX()][initPos.getY()] == 2) {
		//std::cout << "rightRobot have been escaped" << std::endl;
	}
	else {
		//in case robot spawned in (n,max Y), robot can't not move, so Y always != max Y
		if (initPos.getY() != (map_r[0].size() - 1)
			&& map_r[initPos.getX()][initPos.getY()+1] == 0)
		{
			covered.push_back(initPos);
			map_r[initPos.getX()][initPos.getY()] = 0;  //Clear old position 

			initPos.setX(initPos.getX());
			initPos.setY(initPos.getY() + 1);
		}

		map_r[initPos.getX()][initPos.getY()] = 5;

		//security measure if there is some change public_map
		if (public_map_r != map_r) {
			public_map_r = map_r;
		}
	}
}