#ifndef YOUNTNINJA_H_
#define YOUNTNINJA_H_
#include<stdio.h>
#include<cmath>
#include<string>
#include"Character.hpp"
#include"Ninja.hpp"
using namespace std;

namespace ariel{

class YoungNinja:public Ninja{


    string name;
    Point point;
    int speed;
    int NumHits;

    public:
    YoungNinja(string name,Point point);
    string print() override;
    string getName()const override;
    int getSpeed();
    void setName(const std::string &name)override;
    void shoot(Character *character);
    void move(Character *character)override;
    int getNumhits();

};

};

#endif