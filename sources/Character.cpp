#include"Character.hpp"

namespace ariel{



   Character::Character(const string &name,Point &point,int Numhits):name(name),point(point),Numhits(Numhits){
       
     
       this->set_in_team(0);

    }

    Character::Character(const Character &other){

         *this = other;

    }



   Character::Character():name("None"),point(Point(0,0)){

   }

   string Character::getName()const{

      return this->getName();

   }

    void Character::setName(const string &name){

      this->name = name;

    }


   Character::~Character(){
      
    }

    bool Character::operator!=(const Character &other){

        return (other.getName().compare(this->getName())==0 && this->point.equals(other.point));

    }

    Character &Character::operator=(Character const &other){

         if(*this != other){
                this->setName(other.getName());
                this->point.setX(other.getLocation().getX());
                this->point.setY(other.getLocation().getY());
            }

            return *this;

    }


   int Character::get_in_team(){

      return this->in_team;

   }

   void Character::set_in_team(int in_team){

      this->in_team = in_team;

   }


   bool Character::isAlive(){ // Check if the character Alive, if the Numhits is bigget than zero ,then he alive else die.


      return this->Numhits>0 ? 1 : 0;

   }

   Point Character::getLocation()const{ // Get the location of the character.

      return this->point;

   }

   void Character::setLocation(const Point &other){
      
      this->point.setX(other.getX());
      this->point.setY(other.getY());

   }

   int Character::getSizeStack(){// How much bullts in the gun.

      return this->StackOfGun; 

   }

   void Character::updateStackGun(){ // Decrease one bullt from the stack of the gun.

      this->StackOfGun-=1;

   }

   void Character::reload(){ // Update the stack of gun for the character, with add 6 bullts.

      this->StackOfGun+=INIT_BULLTS;

   }

   void Character::hit(int hits){ // Update the Numhits for the character.

      this->Numhits-=hits;

   }

   bool Character::hasboolets(){ // Check if there a bullts in the stack of the gun, for the character.

      return StackOfGun>0 ? true : false;

   }

   // void Character::print(){ // print the data of the character ,helping with print function of the speceif character (print).abstacrt method.


   // }


   double Character::distance(Character *character){ // Mesuare the distance from point of first character to the second character.

      return (this->getLocation()).distance(character->getLocation());

   }


   void Character::shoot(Character *enemy){

        if(this->isAlive()&& enemy->isAlive()){
            if(this->hasboolets()){
            enemy->hit(11);
            this->updateStackGun(); //decrese the number of the bullts from the stack of the gun.
            }else{
               this->reload(); // if there no bullts in the gun, then reload...
            }
        }
        
    };


    int Character::getNumHits(){

      return this->Numhits;

    }




};