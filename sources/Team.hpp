#ifndef TEAM_H_
#define TEAM_H_
#include<stdio.h>
#include<cmath>
#include"Point.hpp"
#include"Cowboy.hpp"
#include"OldNinja.hpp"
#include"YoungNinja.hpp"
#include"TrainedNinja.hpp"
#include"Character.hpp"
#include<vector>
#include"Ninja.hpp"
#include<bits/stdc++.h>

namespace ariel{


    class Team{

            vector<Character*> team;

            Character *leader;

            public: 
            Team(Character *character);
            void add(Character *character);
            void print();
            void attack(Team *team);
            int stillAlive();
            Character *getNewLeader();
            Character& CloserToLeader(Team *enemy);
            void AllShoot(Character *enemy);
            Character* getCurrentLeader();




    };



};

#endif




















