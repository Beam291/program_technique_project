#include "robot.h"

#include <iostream>

robot::robot() {
	this->initPos = Point2D(0, 0);
	this->covered.clear();
}

robot::robot(Point2D initPos) {
	this->initPos = initPos;
}

robot::robot(Point2D initPos, std::vector<Point2D> covered) {
	this->initPos = initPos;
	this->covered = covered;
}

robot::~robot() {

}

Point2D robot::getInitPos() const {
	return this->initPos;
}

std::vector<Point2D> robot::getCovered() const {
	return this->covered;
}

int robot::getJumpStep() const {
	return this->jumpStep;
}

void robot::setInitPos(){
	bool spawned = false;
	while (spawned != true) {
		int x = rand() % (map_r.size() - 1);
		int y = rand() % (map_r[0].size() - 1);
		if (map_r[x][y] == 0) {
			this->initPos.setX(x);
			this->initPos.setY(y);
			spawned = true;
		}
	}
}

void robot::setInitPos(Point2D initPos) {
	this->initPos = initPos;
}

void robot::setCovered(Point2D initPos) {
	this->covered.push_back(initPos);
}

void robot::setJumpStep(int jumpStep) {
	this->jumpStep = jumpStep;
}

void robot::go() {
	
}
