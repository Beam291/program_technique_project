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
	//the robot can only go up, down, left, right
	std::vector<int> dx = { 1, 0, -1, 0 };
	std::vector<int> dy = { 0, 1, 0, -1 };

	bool check = true; //check if the place robot stands is valid or not (0 in maze)
	int rp = 0; //random movement
	int visited = 0; //visted place

	while (check == true) {
		rp = rand() % 4;

		//condition which robot cannot move any more, so it has to find another way around
		if (rp == 0 && initPos.getX() == (map_r.size() - 1)) {
			continue;
		} //robot cannot move down
		if (rp == 1 && initPos.getY() == (map_r[0].size() - 1)) {
			continue;
		} //robot cannot move right
		if (rp == 2 && initPos.getX() == 0) {
			continue;
		} //robot cannot move left
		if (rp == 3 && initPos.getY() == 0) {
			continue;
		} //robot cannot move up
		if (map_r[initPos.getX() + dx[rp]][initPos.getY() + dy[rp]] == 1) {
			continue;
		} //robot cannot step in wall

		//If the robot pass these condition, robot can move normally 
		Point2D newPos(initPos.getX() + dx[rp], initPos.getY() + dy[rp]); //move to new position
		if (std::count(covered.begin(), covered.end(), newPos) && visited < 3)  
			//the new position cannot be visited 3 times so the robot can move to many different position
		{
			visited += 1;
			continue;
		}

		check = false; //if not valid, stop moving (outside maze or step on 1)
	}

	covered.push_back(initPos);
	map_r[initPos.getX()][initPos.getY()] = 0; /* Clear old position */

	initPos.setX(initPos.getX() + dx[rp]);
	initPos.setY(initPos.getY() + dy[rp]);
}