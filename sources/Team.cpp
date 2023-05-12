#include "Team.hpp"

using namespace std;

namespace ariel{


    Team::Team(Character *character){

        team = vector<Character*>();
        add(character);
        leader = character; // get the leader 

    }

    Character& Team::CloserToLeader(Team *enemy){ // Search the soldier from enemy team that closer to the leader of this->team.

        Character *leader = this->leader; 

        Character* closer_Senemy; 
        int index_S = -1;
        Character *helper;
        bool flag = true;

         for (size_t i = 0; i < enemy->team.size() && flag; i++) // get soldier alive. (dose not matter who's).
        {
           if(enemy->team[i]!=nullptr){
            if(enemy->team[i]->isAlive()){
                helper = enemy->team[i];
                index_S = i;
                flag =false;
            }
           }
        }// After get soldoer alive , Asumme that this soldier closer to the leader (that die).

        double dist = helper->distance(leader); // get the distance from this soldier to the die leader.

        for (size_t i = 0; i < enemy->team.size(); i++) // Search for new leader (alive), that closer to the leader right now.
        {
          if(enemy->team[i]!=nullptr){
            if(enemy->team[i]->isAlive()&& i!=index_S){
                if(enemy->team[i]->distance(leader)<dist)
                    closer_Senemy = enemy->team[i];
            }
        }
        }

        return *closer_Senemy;

    }


    Character* Team::getNewLeader(){ // Search the soldier that have a maximum bullts in stack of her gun , and have maximum NumHits. This one will be the leader.

         Character *leader ; 
         int index_S = -1;

         for (size_t i = 0; i < this->team.size(); i++) // get soldier alive. (dose not matter who's).
        {
           if(team[i]!=nullptr){
            if(team[i]->isAlive()){
                leader = team[i];
                index_S = i;
            }
           }
        }// After get soldoer alive , Asumme that this soldier closer to the leader (that die).

        double dist = leader->distance(this->leader); // get the distance from this soldier to the die leader.

        for (size_t i = 0; i < team.size(); i++) // Search for new leader (alive), that closer to the leader right now.
        {
            if(team[i]!=nullptr){
                if(team[i]->isAlive()&& i!=index_S){
                    if(team[i]->distance(this->leader)<dist)
                        leader = team[i];
                }
            }
        }
        
        return leader; // finally, we return the soldier that closer to the die leader, then who will be the new leader.

    }


    void Team::add(Character *character){

      
      if(!(character->get_in_team())){

            character->set_in_team(1);
    //         team.push_back(character); // add the soldier to the team (vector).
         
         }else{

              throw runtime_error("Can't add the same soldier twice to same team!");

         }
        
    }


    void Team::print(){

        for (int i = 0; i <team.size(); i++)
        {
          if(team[(unsigned int)i]!=NULL){
           cout << "Soldier Number " + to_string(i+1) << std::endl;
          cout <<  team[(unsigned int)i]->print();
           
           cout << endl;

            }
        }

    }

    void Team::attack(Team *enemy){


    //  Character *closer_enemy ;
    //  closer_enemy = &this->CloserToLeader(enemy);

    // if(this->leader->isAlive()){ // should build function getLeader.
                
    //     if(closer_enemy->isAlive()){

    //           this->AllShoot(closer_enemy); // All the team shoot the closer_enemy.

    //      }else{

    //         cout << endl;
    //         closer_enemy = &this->CloserToLeader(enemy);
          

    //      }
    // }else{

    //      leader = getNewLeader(); // should build function setLeader.       
    // }

    }

    int Team::stillAlive(){

        int counter = 0;

        for (size_t i = 0; i <team.size(); i++)
        {
          if(team[i]!=nullptr){
            if(team[i]->isAlive())
                counter++;
            }
        }
          return counter;
    }


    void Team::AllShoot(Character *enemy){

        for (size_t i = 0; i < this->team.size(); i++)
        {
          if(team[i]!=nullptr){
           this->team[i]->shoot(enemy);
          }      
        }
        
    }



    Character* Team::getCurrentLeader(){

        return this->leader;

    }



};


