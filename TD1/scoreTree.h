#ifndef SCORETREE_
#define SCORETREE_

#include <iostream>
#include <vector>
#include <algorithm>

#include "point2D.hpp"

class scoreTree{
protected:
	Point2D robotInitPos;
	Point2D finalDirection; //After checking checking with two potential, it will decide with path its will move
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
	Point2D getFinalDirection() const;
	std::vector<std::vector<int>> getScoreMap() const;

	//setter
	void setRobotInitPos(Point2D robotInitPos);
	void setFinalDirection(Point2D finalDrection);
	void setScoreMap(std::vector<std::vector<int>> score_map);

	void potentialSensor(); //throw sensors and find the best way
};

#endif

