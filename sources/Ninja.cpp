#include"Ninja.hpp"


namespace ariel{

using namespace std;


    Ninja::Ninja(std::string &name, Point &point, int speed, int NumHits):Character(name,point,NumHits),speed(speed){

    }

    void Ninja::slash(Character *character){

        if(this->isAlive() && character->isAlive()){
            if(this->getLocation().distance(character->getLocation())<=100){
            character->hit(13);
        }else{
            this->move(character);
        }
        }
    }


    void Ninja::setNumHits(int num_hits){

        this->NumHits = num_hits;

    }





  


}