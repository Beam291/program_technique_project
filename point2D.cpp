#include "point2D.hpp"
#include <iostream>

Point2D::Point2D()
{
   x = y = 0;
}
Point2D::Point2D(float x, float y)
{
   this->x = x;
   this->y = y;
}
Point2D::Point2D(const Point2D &P)
{
   this->x = P.x;
   this->y = P.y;
}
Point2D::~Point2D()
{
}
float Point2D::getX() const
{
   return this->x;
}
float Point2D::getY() const 
{
   return this->y;
}
void Point2D::setX(float x)
{
   this->x = x;
}
void Point2D::setY(float y)
{ 
   this->y = y;
}
void Point2D::display()
{
   std::cout << "x = " << this->x << " y = " << this->y << std::endl;
}