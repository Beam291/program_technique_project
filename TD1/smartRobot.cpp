#include "smartRobot.h"
#include <algorithm>

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
		//robot will disspear
	}
	else {
		//the robot can only go up, down, left, right
		std::vector<int> dx = { 1, 0, -1, 0 };
		std::vector<int> dy = { 0, 1, 0, -1 };
		std::vector<Point2D> potential;

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

			potential.push_back(potential_direction);
		}

		std::vector<int> score_list; //list of score

		//checking neighbor position
		for (auto i : potential) {
			int sum_score = 0; //sum score of a potential direction
			std::vector<int> score; //score of a neighbor

			for (int j = 0; j < 4; j++) {
				if (j == 0 && i.getX() == (map_r.size() - 1)) {
					score.push_back(0);
					continue;
				} //robot cannot move down
				if (j == 1 && i.getY() == (map_r[0].size() - 1)) {
					score.push_back(0);
					continue;
				} //robot cannot move right
				if (j == 2 && i.getX() == 0) {
					score.push_back(0);
					continue;
				} //robot cannot move left
				if (j == 3 && i.getY() == 0) {
					score.push_back(0);
					continue;
				} //robot cannot move up
				if (map_r[i.getX() + dx[j]][i.getY() + dy[j]] == 1) {
					score.push_back(0);
					continue;
				} //robot cannot step in wall
				if (i.getX() + dx[j] == initPos.getX() && 
					i.getY() + dy[j] == initPos.getY()){
					score.push_back(0);
					continue;
				}//robot can't go back to start position

				if (map_r[i.getX() + dx[j]][i.getY() + dy[j]] == 0) {
					score.push_back(1);
				}//free cell, add 1
				if (map_r[i.getX() + dx[j]][i.getY() + dy[j]] != 0) {
					score.push_back(0);
				}//if not free cell, add 0
				if (map_r[i.getX() + dx[j]][i.getY() + dy[j]] == 2) {
					score.push_back(2);
				}//exit point, add 2
				if (map_r[i.getX()][i.getY()] == 2) {
					score.push_back(2);
				}//exit point, add 2 (potential direction)
			}

			for (int n : score) {
				sum_score += n; //sum
			}

			score_list.push_back(sum_score); //put it to list score
		}

		int rp; //random direction index
		int max_score = *max_element(score_list.begin(), score_list.end()); //find max score
		int count_max = std::count(score_list.begin(), score_list.end(), max_score); //count max in case there are more than 1 number max
		std::vector<int>max_index; //index of max number
		int mi_rand; //max index random


		for (int i = 0; i < score_list.size(); i++) {
			if (score_list[i] == max_score) {
				max_index.push_back(i);
			}
		}
		
		if (count_max == 1) { //if max = 1 robot will only that index;
			rp = max_index[0];
		}
		else if (count_max > 1) { //if max more than 1 robot will random it
			mi_rand = rand() % count_max;
			rp = max_index[mi_rand];
		}

		int newX = potential[rp].getX();
		int newY = potential[rp].getY();

		covered.push_back(initPos);
		map_r[initPos.getX()][initPos.getY()] = 0; //clear old position 

		initPos.setX(newX);
		initPos.setY(newY);

		potential.clear();
		score_list.clear();
		max_index.clear();

		map_r[initPos.getX()][initPos.getY()] = 9;

		//security measure if there is some change public_map
		if (public_map_r != map_r) {
			public_map_r = map_r;
		}
	}
}