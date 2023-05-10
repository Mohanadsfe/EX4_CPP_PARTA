#include"TrainedNinja.hpp"



namespace ariel{


    TrainedNinja::TrainedNinja(string name,Point point):Ninja(name,point,12,120){

        this->speed=12;
        this->setName(name);
        this->setNumHits(120);

    }

  void TrainedNinja::setName(const std::string &name){

        this->name = name;

    }
    
    
     void TrainedNinja::print(){

          
            string str = "N Name:-  " + this->getName() + " Point:- " + this->getLocation().Print() + " Speed:- " + to_string(this->getSpeed());
            str +=  " NumHits:- " + to_string(this->getNumHits());
            cout << str;

    }


     int TrainedNinja::getSpeed(){

        return this->speed;

    }

    std::string TrainedNinja::getName() const {

        return this->name;

    }


    void TrainedNinja::shoot(Character *character){

        this->slash(character);

    }

     void TrainedNinja::move(Character *character){

         this->getLocation().moveTowards(character->getLocation(),this->getSpeed());

      }


    int TrainedNinja::getNumhits(){

        return this->NumHits;

     }
    



};