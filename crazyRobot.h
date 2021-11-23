#ifndef CRAZYROBOT_
#define CRAZYROBOT_

#include "Point2D.h"
#include "robot.h"
#include <vector>

class RandomMaze;

class CrazyRobot : public robot
{
public:
    CrazyRobot();
    CrazyRobot(Point2D initPos);
    CrazyRobot(Point2D initPos, std::vector<Point2D> C);
    ~CrazyRobot();

    Point2D getInitPos() const;
    std::vector<Point2D> getCovered() const;

    void setInitPos();                  // random start position
    void setInitPos(Point2D initPos);   //position has been defind before that
    void setCovered(Point2D newPos);

    virtual void go() override;

};
#endif