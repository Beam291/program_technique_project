//#include "crazyRobot.h"
//#include <stdlib.h>
//#include <time.h>
//#include <iostream>
//
//crazyRobot::crazyRobot() : robot() {}
//
//crazyRobot::crazyRobot(Point2D initPos) : robot(initPos) {}
//
//crazyRobot::crazyRobot(Point2D initPos, std::vector<Point2D> covered) : robot(initPos, covered) {}
//
//crazyRobot::~crazyRobot()
//{
//}
//
//Point2D crazyRobot::getInitPos() const
//{
//    return this->initPos;
//}
//
//std::vector<Point2D> crazyRobot::getCovered() const
//{
//    return this->covered;
//}
//
//void crazyRobot::setInitPos()
//{
//}
//
//void crazyRobot::setInitPos(Point2D initPos)
//{
//    this->initPos.setX(initPos.getX());
//    this->initPos.setY(initPos.getY());
//}
//
//void crazyRobot::setCovered(Point2D newPos)
//{
//    this->covered.push_back(newPos);
//}
//
//void crazyRobot::go()
//{
//    /* Get robot initialize position */
//    if (recieve[initPos.getX()][initPos.getY()] == 2)
//    {
//        // std::cout << "A crazyRobot has escaped with " << covered.size() << " step(s)!" << std::endl;
//    }
//    else
//    {
//        this->randGo();
//        recieve[initPos.getX()][initPos.getY()] = 3;
//
//        if (read_recieve != recieve) read_recieve = recieve; /* Undate and anti-hack the Broadcast postiion */
//    }
//}
