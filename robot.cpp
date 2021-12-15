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

void robot::go() {

}

void robot::randGo() {
	std::vector<int> dx = { -1,1 };
	std::vector<int> dy = { -1, 1 };

	bool check = true; //check if the place robot stands is valid or not
	int rx = 0; //random from dx
	int ry = 0; //random from dy
	int visited = 0;

	while (check == true) {
		rx = rand() % 2;
		ry = rand() % 2;

		//condition which robot cannot move any more, so it has to find another way around
		if (rx == 0 && initPos.getX() == 0) {
			continue;
		}
		if (rx == 1 && initPos.getX() == (map_r.size() - 1)) {
			continue;
		}
		if (ry == 0 && initPos.getY() == 0) {
			continue;
		}
		if (ry == 1 && initPos.getY() == (map_r[0].size() - 1)) {
			continue;
		}
		if (map_r[initPos.getX() + dx[rx]][initPos.getY() + dy[ry]] == 1) {
			continue;
		} //robot cannot step in wall

		//If the robot pass these condition, robot can move normally 
		Point2D newPos(initPos.getX() + dx[rx], initPos.getY() + dy[ry]); //move to new position
		if (std::count(covered.begin(), covered.end(), newPos) && visited < 3)
		{
			visited += 1;
			continue;
		}

	check = false;
	}

	covered.push_back(initPos);
	map_r[initPos.getX()][initPos.getY()] = 0; /* Clear old position */

	initPos.setX(initPos.getX() + dx[rx]);
	initPos.setY(initPos.getY() + dy[ry]);
}