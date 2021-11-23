#include "robot.h"
#include <iostream>

robot::robot() {
	this->initPos = Point2D(0, 0);
	this->covered.clear();
}

robot::robot(Point2D(initPos)) {
	this->initPos = initPos;
}

robot::robot(Point2D(initPost), std::vector<Point2D> covered) {
	this->initPos = initPos;
	this->covered = covered;
}

robot::~robot(){};

Point2D robot::getInitPos() const {
	return this->initPos;
}

std::vector<Point2D> robot::getCovered() const {
	return this->covered;
}

void robot::setInitPos()
{
    bool spawned = false;
    while (spawned != true)
    {
        int x = rand() % (recieve.size() - 1);
        int y = rand() % (recieve[0].size() - 1);
        if (recieve[x][y] == '.')
        {
            this->initPos.setX(x);
            this->initPos.setY(y);
            spawned = true;
        }
    }
}

void robot::setInitPos(Point2D initPos)
{
    this->initPos = initPos;
}

void robot::setCovered(Point2D initPos)
{
    this->covered.push_back(initPos);
}

void robot::randGo()
{
    int dx[4] = { 1,0,0,-1 };
    int dy[4] = { 0,-1,1,0 };

    bool check = true;         /* Check if the robot is stand in the border of the maze */
    int z = 0;
    int visited = 0;

    while (check == true)
    {
        z = rand() % 4;

        if (z == 0 && initPos.getX() == (int)recieve.size() - 1) continue;
        if (z == 1 && initPos.getY() == 0) continue;
        if (z == 2 && initPos.getY() == (int)recieve[0].size() - 1) continue;
        if (z == 3 && initPos.getX() == 0) continue;

        if (recieve[initPos.getX() + dx[z]][initPos.getY() + dy[z]] == 1) continue;

        Point2D newPos(initPos.getX() + dx[z], initPos.getY() + dy[z]);
        if (std::count(covered.begin(), covered.end(), newPos) && visited < 3)
        {
            visited += 1;
            continue;
        }

        check = false;
    }

    covered.push_back(initPos);
    recieve[initPos.getX()][initPos.getY()] = 0; /* Clear old position */

    initPos.setX(initPos.getX() + dx[z]);
    initPos.setY(initPos.getY() + dy[z]);
}
