#ifndef POINT_H_
#define POINT_H_
#include<stdio.h>
#include<cmath>
#include<string>

using namespace std;


namespace ariel{

class Point{


    double _lx;
    double _ly;

    public:
    
    explicit Point(double _lx,double _ly);
    Point(Point const &point);
    Point();
    ~Point();
    Point& operator=(Point const  &other);
    bool operator!=(const Point &other);
    bool operator==(const Point &other);
    double const  &getX()const;
    double const &getY()const;

    void setX(const double &_lx);
    void setY(const double &_ly);

    double distance(Point point);
    string Print();

    bool equals(const Point &other);

    Point moveTowards(const Point &dist,double distance);





};


};

#endif