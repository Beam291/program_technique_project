#ifndef SCORETREE_
#define SCORETREE_

#include <iostream>
#include <vector>
#include <algorithm>

#include "point2D.hpp"

class scoreTree{
protected:
	Point2D robotInitPos;
	Point2D potential_lv1; //potential direction lv1
	Point2D potential_lv2; //potential direction lv2
	std::vector<int> dx = { 1, 0, -1, 0 };
	std::vector<int> dy = { 0, 1, 0, -1 };
	std::vector<std::vector<int>> score_map;

public:
	//contructor
	scoreTree();

	//destructor
	~scoreTree();

	//getter
	Point2D getRobotInitPos() const;
	Point2D getPotential_lv1() const;
	Point2D getPotential_lv2() const;
	std::vector<std::vector<int>> getScoreMap() const;

	//setter
	void setRobotInitPos(Point2D robotInitPos);
	void setPotential_lv1(Point2D potential_lv1);
	void setPotential_lv2(Point2D potential_lv2);
	void setScoreMap(std::vector<std::vector<int>> score_map);

	void potentialSensor_lv1(); //throw sensors and find the best way
	void potentialSensor_lv2(); //throw sensors again and find the best way
};

#endif

