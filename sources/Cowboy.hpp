#ifndef COWBOY_H_
#define COWBOY_H_
#include<stdio.h>
#include<cmath>
#include<string>
#include <iostream>
#include <fstream>
#include <sstream>
#include"Character.hpp"

using namespace std;

namespace ariel{

class Cowboy: public Character{


    string name;
    Point point;
    int NumHits;

    public:
    explicit Cowboy(const string &name,Point &point);
    explicit Cowboy(const Cowboy &other);
    ~Cowboy() override;
    Cowboy& operator=(Cowboy  const &other);
    bool operator!=(const Cowboy &other);
    bool operator==(const Cowboy &other);
    string print() override;
    string getName()const override;
    void setName(string const &name)override;
    void setPoint(Point &point);
    bool equals(Character *character);
    void setNumHits(int num_hits);
    int getNumHits()override;
    void move(Character *character)override;
    
      


};

};

#endif