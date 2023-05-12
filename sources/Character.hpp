#ifndef CHARACTER_H_
#define CHARACTER_H_
#include<stdio.h>
#include<cmath>
#include<string>
#include"Point.hpp"
// #define INIT_BULLTS 6
constexpr unsigned int INIT_BULLTS = 6;
using namespace std;


namespace ariel{

class Character{


    Point point;
    string name;
    int Numhits; // number to live
    int StackOfGun=INIT_BULLTS;
    int in_team; // This var is to indicate that the character is already in team.

    public:

    Character(const string &name,Point &point,int Numhits);
    Character(const Character &other);
    Character();
    virtual ~Character();
    Character& operator=(Character  const &other);
    bool operator!=(const Character &other);




    bool isAlive(); // if Numhits>0 then alive else feneto.
    int getSizeStack(); // How much bullts in the gun.
    void reload(); // add 6 bullets to the stack of gun.
    void updateStackGun(); // decrese one bullt from the stack f the gun.
    Point getLocation()const;
    virtual string getName()const;
    virtual void setName(const string &name);
    virtual string print()=0;
    virtual void move(Character *character)=0;
    bool hasboolets(); // check if there more bullets in the stack of the gun.
    double distance(Character *character);
    void shoot(Character *enemy);
    virtual int getNumHits();
    void hit(int hits);
    int get_in_team();
    void set_in_team(int in_team);
    void setLocation(const Point &point);

};


};

#endif