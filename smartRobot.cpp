#include "smartRobot.h"

smartRobot::smartRobot() : robot() {
}

smartRobot::smartRobot(Point2D initPos) : robot(initPos) {

}

smartRobot::smartRobot(Point2D initPos, std::vector<Point2D> covered) :
	robot(initPos, covered) {
}

smartRobot::~smartRobot() {

}

Point2D smartRobot::getInitPos() const {
	return this->initPos;
}

std::vector<Point2D> smartRobot::getCovered() const {
	return this->covered;
}

void smartRobot::setInitPos() {

}

void smartRobot::setInitPos(Point2D initPos) {
	this->initPos.setX(initPos.getX());
	this->initPos.setX(initPos.getX());
}

void smartRobot::setCovered(Point2D newPos) {
	this->covered.push_back(newPos);
}

void smartRobot::go() {
	if (map_r[initPos.getX()][initPos.getY()] == 2) {
		//std::cout << "smartRobot have been escaped" << std::endl;
	}
	else {
		//the robot can only go up, down, left, right
		std::vector<int> dx = { 1, 0, -1, 0 };
		std::vector<int> dy = { 0, 1, 0, -1 };
		std::vector<Point2D> poteintial;

		//find potential direction
		for (int i = 0; i < 4; i++) {
			if (i == 0 && initPos.getX() == (map_r.size() - 1)) {
				continue;
			} //robot cannot move down
			if (i == 1 && initPos.getY() == (map_r[0].size() - 1)) {
				continue;
			} //robot cannot move right
			if (i == 2 && initPos.getX() == 0) {
				continue;
			} //robot cannot move left
			if (i == 3 && initPos.getY() == 0) {
				continue;
			} //robot cannot move up
			if (map_r[initPos.getX() + dx[i]][initPos.getY() + dy[i]] == 1) {
				continue;
			} //robot cannot step in wall

			Point2D potential_direction(initPos.getX() + dx[i], initPos.getY() + dy[i]);

			poteintial.push_back(potential_direction);
		}

		std::vector<int> score_list; //list of score

		//checking neighbor position
		for (auto i : poteintial) {
			int x = i.getX();
			int y = i.getY();
			int sum_score = 0;
			std::vector<int> score;

			for (int j = 0; j < 4; j++) {
				if (j == 0 && initPos.getX() == (map_r.size() - 1)) {
					continue;
				} //robot cannot move down
				if (j == 1 && initPos.getY() == (map_r[0].size() - 1)) {
					continue;
				} //robot cannot move right
				if (j == 2 && initPos.getX() == 0) {
					continue;
				} //robot cannot move left
				if (j == 3 && initPos.getY() == 0) {
					continue;
				} //robot cannot move up
				if (map_r[i.getX() + dx[j]][i.getY() + dy[j]] == 1) {
					continue;
				} //robot cannot step in wall
				if (i.getX() + dx[j] == initPos.getX() &&
					i.getY() + dy[j] == initPos.getY()) {
					continue;
				}
				if (map_r[i.getX() + dx[j]][i.getY() + dy[j]] == 0) {
					score.push_back(1);
				}
			}

			for (int n : score) {
				sum_score += n;
			}

			score_list.push_back(sum_score);
		}

		for (int i : score_list) {
			std::cout << i << " ";
		}

		/*for (auto i : poteintial) {
			i.display();
		}*/

		//std::vector<int> neighbor = { 1, 1, 1 };

		//bool check = true; //check if the place robot stands is valid or not (0 in maze)
		//int rp = 0; //random movement
		//int visited = 0; //visted place
		//int pd = 0; // potential direction
		//int sensor = 1; // sensor will check position around it

		//while (check == true) {
		//	bool check_score = true;
		//	int score = 0; //score
		//	rp = rand() % 4;

		//	//condition which robot cannot move any more, so it has to find another way around
		//	if (rp == 0 && initPos.getX() == (map_r.size() - 1)) {
		//		continue;
		//	} //robot cannot move down
		//	if (rp == 1 && initPos.getY() == (map_r[0].size() - 1)) {
		//		continue;
		//	} //robot cannot move right
		//	if (rp == 2 && initPos.getX() == 0) {
		//		continue;
		//	} //robot cannot move left
		//	if (rp == 3 && initPos.getY() == 0) {
		//		continue;
		//	} //robot cannot move up
		//	if (map_r[initPos.getX() + dx[rp]][initPos.getY() + dy[rp]] == 1) {
		//		continue;
		//	} //robot cannot step in wall

		//	check = false; //if not valid, stop moving (outside maze or step on 1 or just out of place to move)
		//}

		//std::cout << rp;

		//covered.push_back(initPos);
		//map_r[initPos.getX()][initPos.getY()] = 0; //clear old position 

		//initPos.setX(initPos.getX() + dx[rp]);
		//initPos.setY(initPos.getY() + dy[rp]);

		map_r[initPos.getX()][initPos.getY()] = 9;

		//security measure if there is some change public_map
		if (public_map_r != map_r) {
			public_map_r = map_r;
		}
	}
}