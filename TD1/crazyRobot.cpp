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
		//the robot can only go up, down, left, right
		std::vector<int> dx = { 1, 0, -1, 0 };
		std::vector<int> dy = { 0, 1, 0, -1 };

		bool check = true; //check if the place robot stands is valid or not (0 in maze)
		int rp = 0; //random movement
		int visited = 0;

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

			check = false; //if not valid, stop moving (outside maze or step on 1 or just out of place to move)
		}

		covered.push_back(initPos);
		map_r[initPos.getX()][initPos.getY()] = 0; //clear old position 

		initPos.setX(initPos.getX() + dx[rp]);
		initPos.setY(initPos.getY() + dy[rp]);

		map_r[initPos.getX()][initPos.getY()] = 3;

		//security measure if there is some change public_map
		if (public_map_r != map_r) {
			public_map_r = map_r;
		}
	}
}