#include"Cowboy.hpp"
#include"Point.hpp"
#include"stdlib.h"
#include"YoungNinja.hpp"
#include<string.h>
using namespace std;

namespace ariel{


    YoungNinja::YoungNinja(string name, Point point):Ninja(name,point,14,100){
        
        this->speed=14;
        this->setName(name);
        this->setNumHits(100);
        
        }   

    void YoungNinja::setName(const std::string &name){

        this->name = name;

    }

     void YoungNinja::shoot(Character *character){
        cout << "shoot younggggg " <<endl;
        this->slash(character);

    }


  void YoungNinja::move(Character *character){

         this->getLocation().moveTowards(character->getLocation(),this->getSpeed());

      }

 
  int YoungNinja::getNumhits(){

        return this->NumHits;

     }
    
    void YoungNinja::print(){

            string outP = " Point:- " + this->getLocation().Print();

            string str = "N Name:-  " + this->getName() + outP
             + " Speed:- " + to_string(this->getSpeed());
            str +=  " NumHits:- " + to_string(this->getNumHits());

            cout << str;

    }

    int YoungNinja::getSpeed(){

        return this->speed;

    }

    std::string YoungNinja::getName() const {

        return this->name;

    }


    





};