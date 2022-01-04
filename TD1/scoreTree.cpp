#include "scoreTree.h"

scoreTree::scoreTree() {

}

scoreTree::~scoreTree() {

}

Point2D scoreTree::getRobotInitPos() const {
	return this->robotInitPos;
}

Point2D scoreTree::getFinalDirection() const {
	return this->finalDirection;
}

std::vector<std::vector<int>> scoreTree::getScoreMap() const {
	return this->score_map;
}

void scoreTree::setRobotInitPos(Point2D robotInitPos) {
	this->robotInitPos = robotInitPos;
}

void scoreTree::setFinalDirection(Point2D finalDirection) {
	this->finalDirection = finalDirection;
}

void scoreTree::setScoreMap(std::vector<std::vector<int>> score_map) {
	this->score_map = score_map;
}

void scoreTree::potentialSensor() {
	std::vector<Point2D> potentialSensor_lv1;

	//find potential direction
	for (int i = 0; i < 4; i++) {
		if (i == 0 && robotInitPos.getX() == (score_map.size() - 1)) {
			continue;
		} //robot cannot move down
		if (i == 1 && robotInitPos.getY() == (score_map[0].size() - 1)) {
			continue;
		} //robot cannot move right
		if (i == 2 && robotInitPos.getX() == 0) {
			continue;
		} //robot cannot move left 
		if (i == 3 && robotInitPos.getY() == 0) {
			continue;
		} //robot cannot move up
		if (score_map[robotInitPos.getX() + dx[i]][robotInitPos.getY() + dy[i]] == 1) {
			continue;
		} //robot cannot step in wall

		Point2D potential_direction(robotInitPos.getX() + dx[i], robotInitPos.getY() + dy[i]);

		potentialSensor_lv1.push_back(potential_direction);
	}

	std::vector<int> score_list_lv1; //list of score

	//checking neighbor position
	for (auto i : potentialSensor_lv1) {
		int sum_score = 0; //sum score of a potential direction
		std::vector<int> score; //score of a neighbor

		for (int j = 0; j < 4; j++) {
			if (j == 0 && i.getX() == (score_map.size() - 1)) {
				score.push_back(0);
				continue;
			} //robot cannot move down
			if (j == 1 && i.getY() == (score_map[0].size() - 1)) {
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
			if (score_map[i.getX() + dx[j]][i.getY() + dy[j]] == 1) {
				score.push_back(0);
				continue;
			} //robot cannot step in wall
			if (i.getX() + dx[j] == robotInitPos.getX() &&
				i.getY() + dy[j] == robotInitPos.getY()) {
				score.push_back(0);
				continue;
			}//robot can't go back to start position

			if (score_map[i.getX() + dx[j]][i.getY() + dy[j]] == 0) {
				score.push_back(1);
			}//free cell, add 1
			if (score_map[i.getX() + dx[j]][i.getY() + dy[j]] != 0) {
				score.push_back(0);
			}//if not free cell, add 0
			if (score_map[i.getX() + dx[j]][i.getY() + dy[j]] == 2) {
				score.push_back(2);
			}//exit point, add 2
			if (score_map[i.getX()][i.getY()] == 2) {
				score.push_back(2);
			}//exit point, add 2 (default position)
		}

		for (int n : score) {
			sum_score += n; //sum
		}

		score_list_lv1.push_back(sum_score); //put it to list score
	}

	std::vector<int> potentialSensor_lv2_score;

	//potential lv2
	for (auto i : potentialSensor_lv1) {
		std::vector<Point2D> potential_lv2;

		//find potential direction
		for (int j = 0; j < 4; j++) {
			if (j == 0 && i.getX() == (score_map.size() - 1)) {
				continue;
			} //robot cannot move down
			if (j == 1 && i.getY() == (score_map[0].size() - 1)) {
				continue;
			} //robot cannot move right
			if (j == 2 && i.getX() == 0) {
				continue;
			} //robot cannot move left 
			if (j == 3 && i.getY() == 0) {
				continue;
			} //robot cannot move up
			if (score_map[i.getX() + dx[j]][i.getY() + dy[j]] == 1) {
				continue;
			} //robot cannot step in wall
			if (i.getX() + dx[j] == robotInitPos.getX() &&
				i.getY() + dy[j] == robotInitPos.getY()) {
				continue;
			}//can't come back to the first point

			Point2D potential_direction(i.getX() + dx[j], i.getY() + dy[j]);

			potential_lv2.push_back(potential_direction);
		}

		std::vector<int> score_list_lv2;

		for (auto k : potential_lv2) {
			int sum_score = 0; //sum score of a potential direction
			std::vector<int> score; //score of a neighbor

			for (int n = 0; n < 4; n++) {
				if (n == 0 && k.getX() == (score_map.size() - 1)) {
					score.push_back(0);
					continue;
				} //robot cannot move down
				if (n == 1 && k.getY() == (score_map[0].size() - 1)) {
					score.push_back(0);
					continue;
				} //robot cannot move right
				if (n == 2 && k.getX() == 0) {
					score.push_back(0);
					continue;
				} //robot cannot move left
				if (n == 3 && k.getY() == 0) {
					score.push_back(0);
					continue;
				} //robot cannot move up
				if (score_map[k.getX() + dx[n]][k.getY() + dy[n]] == 1) {
					score.push_back(0);
					continue;
				} //robot cannot step in wall
				if (k.getX() + dx[n] == i.getX() &&
					k.getY() + dy[n] == i.getY()) {
					score.push_back(0);
					continue;
				}//robot can't go back to start position

				if (score_map[k.getX() + dx[n]][k.getY() + dy[n]] == 0) {
					score.push_back(1);
				}//free cell, add 1
				if (score_map[k.getX() + dx[n]][k.getY() + dy[n]] != 0) {
					score.push_back(0);
				}//if not free cell, add 0
				if (score_map[k.getX() + dx[n]][k.getY() + dy[n]] == 2) {
					score.push_back(2);
				}//exit point, add 2
				if (score_map[k.getX()][k.getY()] == 2) {
					score.push_back(2);
				}//exit point, add 2 (potential direction)
			}

			for (int n : score) {
				sum_score += n; //sum
			}

			score_list_lv2.push_back(sum_score); //put it to list score
		}

		//int rand_max; //random max number
		int max_score = *max_element(score_list_lv2.begin(), score_list_lv2.end()); //find max score

		potentialSensor_lv2_score.push_back(max_score);
	}

	std::transform(score_list_lv1.begin(), score_list_lv1.end(), potentialSensor_lv2_score.begin(), score_list_lv1.begin(), std::plus<int>());

	int rp; //random direction index
	int max_score_final = *max_element(score_list_lv1.begin(), score_list_lv1.end()); //find max score
	int count_max_final = std::count(score_list_lv1.begin(), score_list_lv1.end(), max_score_final); //count max in case there are more than 1 number max
	std::vector<int>max_index; //index of max number
	int mi_rand; //max index random

	for (int i = 0; i < score_list_lv1.size(); i++) {
		if (score_list_lv1[i] == max_score_final) {
			max_index.push_back(i);
		}
	}

	if (count_max_final == 1) { //if max = 1 robot will only that index;
		rp = max_index[0];

	}
	else if (count_max_final > 1) { //if max more than 1 robot will random it
		mi_rand = rand() % count_max_final;
		rp = max_index[mi_rand];
	}

	int newX = potentialSensor_lv1[rp].getX();
	int newY = potentialSensor_lv1[rp].getY();

	setFinalDirection(Point2D(newX, newY));
}

