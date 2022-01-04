#ifndef POINT2D_
#define POINT2D_

class Point2D
{
   public :

     // Constructors
     Point2D();
     Point2D(float x, float y);
     Point2D(const Point2D &P);

     // Destructor
     ~Point2D();

     // Getters
     float getX() const;
     float getY() const;

     // Setter
     void setX(float x);
     void setY(float y);

     void display();

     inline bool operator==(const Point2D& p)
     {
         return (x == p.x && y == p.y);
     }

   private :

     // Attributes
     float x;
     float y;

};
#endif
