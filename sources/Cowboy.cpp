#include"Cowboy.hpp"
#include"stdlib.h"
#include<string.h>

using namespace std;

namespace ariel{

    

    Cowboy::Cowboy(const string &name, Point &point):Character(name,point,110){

        setName(name);
        setNumHits(110);
           
    }

    Cowboy::Cowboy(const Cowboy &other):Character(other){

        *this = other;
        
    }

    Cowboy::~Cowboy(){


        
    }

    int Cowboy::getNumHits(){

        return this->NumHits;
        
    }

    void Cowboy::setNumHits(int num_hits){

        this->NumHits = num_hits;

    }


    bool Cowboy::operator!=(const Cowboy &other){

        return (other.getName().compare(this->getName())==0 && this->point.equals(other.point));

    }

    bool Cowboy::operator==(const Cowboy &other){

        return !this->operator!=(other);

    }


    Cowboy& Cowboy::operator=(Cowboy const  &other){

            if(*this != other){
                this->setName(name);
                this->setLocation(other.getLocation());
            }

            return *this;

        }



    void Cowboy::print(){

        string output;

        output =+  "C  Name is: " + this->getName() + " Point is ";


        string outP =  getLocation().Print();
        output += outP;
        output += "NumHits:- " + to_string(this->getNumHits());

        cout << output <<endl;

    }


    string Cowboy::getName()const{
        return this->name;
    }

    void Cowboy::setName(const std::string &name){

        this->name = name;

    }

    void Cowboy::setPoint(Point &point){

        this->point = point;

    }

    bool Cowboy::equals(Character *character){
        
        return this->getName().compare(character->getName())==0 && this->getLocation().equals(character->getLocation()) && this->getNumHits()==character->getNumHits();

    }


     void Cowboy::move(Character *character){

            double dist = this->distance(character);
            Point new_point = this->getLocation().moveTowards(character->getLocation(),dist/2+1);
            //cout << "new new  " << new_point.Print() << endl;
           
            Cowboy new_cowboy (this->getName(),new_point);
            // //cout <<"nananna" << endl;
            // new_cowboy.print();
            // cout <<"nananna" << endl;



            *this = new_cowboy;
            // this->setPoint(new_point);
            // cout << "blabla " << endl;
            // this->print();
            // cout << "blabla " << endl;


     }



};