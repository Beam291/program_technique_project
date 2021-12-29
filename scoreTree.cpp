#include "scoreTree.h"

scoreTree::scoreTree() {

}

scoreTree::~scoreTree() {

}

Point2D scoreTree::getRobotInitPos() const {
	return this->robotInitPos;
}

Point2D scoreTree::getPotential_lv1() const {
	return this->potential_lv1;
}

Point2D scoreTree::getPotential_lv2() const {
	return this->potential_lv2;
}

std::vector<std::vector<int>> scoreTree::getScoreMap() const {
	return this->score_map;
}

void scoreTree::setRobotInitPos(Point2D robotInitPos) {
	this->robotInitPos = robotInitPos;
}

void scoreTree::setPotential_lv1(Point2D potential_lv1) {
	this->potential_lv1 = potential_lv1;
}

void scoreTree::setPotential_lv2(Point2D potential_lv2) {
	this->potential_lv2 = potential_lv2;
}

void scoreTree::setScoreMap(std::vector<std::vector<int>> score_map) {
	this->score_map = score_map;
}

void scoreTree::potentialSensor_lv1() {
	std::vector<Point2D> potential;

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

		potential.push_back(potential_direction);
	}

	std::vector<int> score_list; //list of score

	//checking neighbor position
	for (auto i : potential) {
		int x = i.getX(); //X
		int y = i.getY(); //Y
		int sum_score = 0; //sum score of a potential direction
		std::vector<int> score; //score of a neighbor

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
			}//exit point, add 2
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

	setPotential_lv1(Point2D(newX, newY));

	potential.clear();
	score_list.clear();
	max_index.clear();
}

void scoreTree::potentialSensor_lv2() {
	std::vector<Point2D> potential;

	//find potential direction
	for (int i = 0; i < 4; i++) {
		if (i == 0 && potential_lv1.getX() == (score_map.size() - 1)) {
			continue;
		} //robot cannot move down
		if (i == 1 && potential_lv1.getY() == (score_map[0].size() - 1)) {
			continue;
		} //robot cannot move right
		if (i == 2 && potential_lv1.getX() == 0) {
			continue;
		} //robot cannot move left 
		if (i == 3 && potential_lv1.getY() == 0) {
			continue;
		} //robot cannot move up
		if (score_map[potential_lv1.getX() + dx[i]][potential_lv1.getY() + dy[i]] == 1) {
			continue;
		} //robot cannot step in wall
		if (potential_lv1.getX() + dx[i] == robotInitPos.getX() &&
			potential_lv1.getY() + dy[i] == robotInitPos.getY()) {
			continue;
		}//robot can't go back to start position

		Point2D potential_direction(potential_lv1.getX() + dx[i], potential_lv1.getY() + dy[i]);

		potential.push_back(potential_direction);
	}

	std::vector<int> score_list; //list of score

	//checking neighbor position
	for (auto i : potential) {
		int x = i.getX(); //X
		int y = i.getY(); //Y
		int sum_score = 0; //sum score of a potential direction
		std::vector<int> score; //score of a neighbor

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
			if (i.getX() + dx[j] == potential_lv1.getX() &&
				i.getY() + dy[j] == potential_lv1.getY()) {
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
			}//exit point, add 2
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

	setPotential_lv2(Point2D(newX, newY));
	
	potential.clear();
	score_list.clear();
	max_index.clear();
}

