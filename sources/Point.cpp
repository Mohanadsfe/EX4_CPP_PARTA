#include "Point.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

namespace ariel{


    double x;
    double y;

    Point::Point(double _lx ,double _ly):_lx(_lx),_ly(_ly){}


    Point::Point(Point const &point){

        this->setX(point.getX());
        this->setY(point.getY());

    }

    bool Point::operator!=(const Point &other){

        return (this->getX()!=other.getX() || this->getY()!=other.getY());

    }

    bool Point::operator==(const Point &other){

        return !this->operator!=(other);
    }


    Point& Point::operator=(Point const  &other){
            if(*this != other){
                this->setX(other.getX());
                this->setY(other.getY());
            }
          
            return *this;

        }

    Point::Point():_lx(0),_ly(0){}

    Point::~Point(){

    }

    double const &Point::getX()const{
        return this->_lx;
     }

    double const &Point::getY()const{
        return this->_ly;
     }

    void Point::setX(const double &_lx){
        this->_lx= _lx;
     }

     void Point::setY(const double &_ly){
        this->_ly= _ly;
     }

    double Point::distance(Point point){

        double _dx = pow(point.getX()-this->getX(),2);
        double _dy = pow(point.getY()-this->getY(),2);

    return sqrt(_dx+_dy);

    }


    string Point::Print(){

        string output = "(x,y)= (" ;

         output += to_string(this->getX()) + "," + to_string(this->getY()) + ")" ;

         return output;

    }


    bool Point::equals(const Point &other){

        return this->getX()==other.getX() && this->getY()==other.getY();

    }


    Point Point::moveTowards(const Point &dist, double distance){



        while(distance>0){
                       

        if(this->getX()>dist.getX() && this->getY()>dist.getY()){
                this->setX(this->getX()-0.1);
                this->setY(this->getY()-0.1);
           }

        if(this->getX()>dist.getX() && this->getY()<dist.getY()){
                this->setX(this->getX()-0.1);
                this->setY(this->getY()+0.1);
           }

        if(this->getX()<dist.getX() && this->getY()<dist.getY()){
                this->setX(this->getX()+0.1);
                this->setY(this->getY()+0.1);
           }

        if(this->getX()<dist.getX() && this->getY()>dist.getY()){
                this->setX(this->getX()+0.1);
                this->setY(this->getY()-0.1);
           }
/**************************************************/
         if(this->getX()<dist.getX() && this->getY()==dist.getY()){
                this->setX(this->getX()+0.1);
           }

        if(this->getX()>dist.getX() && this->getY()==dist.getY()){
                this->setX(this->getX()-0.1);
           }

      if(this->getX()==dist.getX() && this->getY()<dist.getY()){
                this->setY(this->getY()+0.1);
           }

        if(this->getX()==dist.getX() && this->getY()>dist.getY()){
                this->setY(this->getY()-0.1);
           }


            distance = distance - sqrt(2*pow(0.1,2));

        }


        return *this;

     }

  





};
