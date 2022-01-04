#ifndef GENERICPOINT2D_
#define GENERICPOINT2D_
#include <iostream>

template <class X, class Y>
class point2D
{
   public :

     // Constructors
     point2D(){
         x = 0;
         y = 0;
     }
     point2D(X x, Y y) {
        this->x = x;
        this->y = y;
     }
     point2D(const point2D &P) {
         this->x = P.x;
         this->y = P.y;
     }

     // Destructor
     ~point2D(){};

     // Getters
     X getX() const {
         return this->x;
     }
     Y getY() const {
         return this->y;
     }

     // Setter
     void setX(X x) {
         this->x = x;
     }
     void setY(Y y) {
         this->y = y;
     }

     void display() {
        std::cout << "x = " << this->x << " y = " << this->y << std::endl;
     }

   private :

     // Attributes
     X x;
     Y y;
};
#endif
