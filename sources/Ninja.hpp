#ifndef NINJA_H_
#define NINJA_H_
#include<stdio.h>
#include<cmath>
#include<string>
#include"Ninja.hpp"
#include"Character.hpp"
#include"iostream"
namespace ariel{

class Ninja:public Character{


    string name;
    Point point;
    int speed;
    int NumHits;

    public:
    Ninja(string &name,Point &point,int speed,int Numhunts);
    // void move(Character *character);
    //virtual void print();
    void slash(Character *character);
    //virtual bool equals(Ninja *Ninja);
    void setNumHits(int num_hits);
    


};

};

#endif