#ifndef OLDNINJA_H_
#define OLDNINJA_H_
#include<stdio.h>
#include<cmath>
#include"stdlib.h"
#include<string.h>
#include"Ninja.hpp"
#include"iostream"

namespace ariel{

class OldNinja:public Ninja{


    string name;
    Point point;
    int speed;
    int NumHits;
   

    public:
    OldNinja(string name,Point point);
    void move(Character *character)override;
    string print() override;

    string getName()const override;
    int getSpeed();
    void setName(const std::string &name)override;
    void shoot(Character *character);
    int getNumhits();

    bool operator!=(const OldNinja &other);
    bool operator==(const OldNinja &other);

};

};

#endif