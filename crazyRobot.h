#ifndef crazyRobot_
#define crazyRobot_

#include "Point2D.h"
#include "robot.h"
#include <vector>

class RandomMaze;

class crazyRobot : public robot
{
public:
    crazyRobot();
    crazyRobot(Point2D initPos);
    crazyRobot(Point2D initPos, std::vector<Point2D> covered);
    ~crazyRobot();

    Point2D getInitPos() const;
    std::vector<Point2D> getCovered() const;

    void setInitPos();                  // random start position
    void setInitPos(Point2D initPos);   //position has been defind before that
    void setCovered(Point2D newPos);

    virtual void go() override;

};
#endif