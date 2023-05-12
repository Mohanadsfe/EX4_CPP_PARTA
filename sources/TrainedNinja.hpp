#include"Point.hpp"
#include<string.h>
#include"Character.hpp"
#include"Ninja.hpp"
#include<iostream>

namespace ariel{

class TrainedNinja:public Ninja{

    Point point;
    string name;
    int speed;
    int NumHits;

    public:
    TrainedNinja(string name,Point point);
    void move(Character *character)override;
    string print() override;
    string getName()const override;
    int getSpeed();
    void setName(const std::string &name)override;
    void shoot(Character *character);
    int getNumhits();



};

};