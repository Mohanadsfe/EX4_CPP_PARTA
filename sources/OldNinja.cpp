#include"OldNinja.hpp"


namespace ariel{


      OldNinja::OldNinja(std::string name, Point point):Ninja(name,point,8,150){

        this->speed=8;
        this->setName(name);
        this->setNumHits(150);

      }

      void OldNinja::move(Character *character){

         this->getLocation().moveTowards(character->getLocation(),this->getSpeed());

      }

  void OldNinja::setName(const std::string &name){

        this->name = name;

    }


  void OldNinja::shoot(Character *character){
        cout << "hello100 " << endl;
        this->slash(character);

    }


    
      string OldNinja::print(){
            
            string str = "N Name:-  " + this->getName() + "Point:- " + this->getLocation().Print() + "Speed:- " + to_string(this->getSpeed());
            str +=  " NumHits:- " + to_string(this->getNumHits());

            return  str;

      }


      int OldNinja::getSpeed(){

        return this->speed;

    }

    std::string OldNinja::getName() const {

        return this->name;

    }
     
    int OldNinja::getNumhits(){

      return this->NumHits;

    }
    
    

  bool OldNinja::operator==(const OldNinja &other){

    return this->getName().compare(other.getName())==0 && 
    this->getLocation().equals(other.getLocation());

  }

  bool OldNinja::operator!=(const OldNinja &other){

    return !this->operator==(other);

  }






};