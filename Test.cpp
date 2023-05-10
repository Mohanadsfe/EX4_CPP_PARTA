#include "doctest.h"
#include <stdexcept>
#include "sources/Team.hpp"
using namespace std;
using namespace ariel;



TEST_SUITE("Class Point"){

TEST_CASE("Create Point"){

    Point p = Point(1.0,2.5);
    CHECK_EQ(p.getX(),1.0);
    CHECK_EQ(p.getY(),2.5);

}

TEST_CASE("Distance FTPoint"){

    Point p1 = Point(10,2);
    Point p2 = Point(3,4);
    
    double dist = p1.distance(p2);
    CHECK_EQ(dist,sqrt(53));

    Point p3 = Point(3.0,4.0);
    dist = p2.distance(p3);
    CHECK_EQ(dist,0);


    Point a(32.3,44),b(1.3,3.5);
    dist = a.distance(b);
    CHECK_EQ(dist,sqrt(2601.25));

}


}


TEST_SUITE("Create Soldiers"){

    TEST_CASE("Cowboys"){

    Point a(32.3,44),b(32.2,44),c(50,100);
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *mor = new OldNinja("mor", b);
    Cowboy *rami = new Cowboy("rami", a);


    CHECK_EQ(tom->getName().compare("Tom"),0);
    CHECK_EQ(tom->getLocation().equals(a),1);
    CHECK_EQ(tom->getLocation().equals(b),0);
    CHECK_EQ(tom->getNumHits(),110);
    CHECK_EQ(tom->getSizeStack(),6);
    CHECK_EQ(tom->isAlive(),1);
    CHECK_EQ(mor->isAlive(),1);

    for(int i=0; i<6; i++){
        tom->shoot(mor);
    }

    CHECK_EQ(mor->getNumHits(),84);
    CHECK_EQ(tom->getSizeStack(),0);
    tom->shoot(mor);
    CHECK_EQ(tom->getSizeStack(),6);
    CHECK_EQ(mor->getNumHits(),84);

    rami->shoot(tom);
    CHECK_EQ(rami->getSizeStack(),5);
    CHECK_EQ(tom->getNumHits(),99);


    }

    TEST_CASE("Ninja"){

    Point b(1.3,3.5);
    OldNinja *sushi = new OldNinja("sushi", b);
    YoungNinja *mushi = new YoungNinja("mushi", b);
    TrainedNinja *kushi = new TrainedNinja("kushi", b);

    CHECK_EQ(sushi->getName(),"sushi");
    CHECK_EQ(sushi->getSpeed(),8);
    CHECK_EQ(sushi->getNumHits(),150);


    CHECK_EQ(mushi->getName(),"mushi");
    CHECK_EQ(mushi->getSpeed(),14);
    CHECK_EQ(mushi->getNumHits(),100);


    CHECK_EQ(kushi->getName(),"kushi");
    CHECK_EQ(kushi->getSpeed(),12);
    CHECK_EQ(kushi->getNumHits(),120);

    
     }



}

TEST_SUITE("The War"){



TEST_CASE("Check correct save  pointer of leader") 
{
    
    Point b(1.3,3.5);
    TrainedNinja *yafgine = new TrainedNinja("yafgine", b);
    Team team_A(yafgine);

    CHECK_EQ(yafgine->getName(),team_A.getCurrentLeader()->getName());
      
}


TEST_CASE("Create team & Add soldiers to team"){

    Point a(32.3,44),b(1.3,3.5);
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
   
    Team team_A(tom);

    team_A.add(sushi);
    
    CHECK_EQ(team_A.getCurrentLeader()->getName(),tom->getName());
     
}

TEST_CASE("Add same Soldier twice in same team"){

    Point a(32.3,44);
    Cowboy *tom = new Cowboy("Tom", a);
    Team team_A(tom);
    CHECK_THROWS(team_A.add(tom));

}

TEST_CASE("Add same Soldier twice in diff team"){

    Point a(32.3,44);
    Cowboy *tom = new Cowboy("Tom", a);
    Cowboy *rami = new Cowboy("rami", a);
    Cowboy *dan = new Cowboy("dan", a);

    Team team_A(tom);
    CHECK_NOTHROW(team_A.add(dan));

    Team team_B(rami);
    CHECK_THROWS(team_B.add(tom));

    CHECK_THROWS(Team(rami));
    
}

TEST_CASE("Shoot & Slash"){

    Point a(32.3,44),b(160.3,350.5),c(160.3,341);
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    TrainedNinja *mushi = new TrainedNinja("mushi", b);
    YoungNinja *yogi = new YoungNinja("Yogi", c);

    CHECK_EQ(sushi->getNumHits(),150);
    CHECK_EQ(tom->getSizeStack(),6);
    tom->shoot(sushi);
    CHECK_EQ(sushi->getNumHits(),139);
    CHECK_EQ(tom->getSizeStack(),5);
    
    sushi->slash(tom);
    CHECK_EQ(sushi->getNumHits(),139);
    CHECK_EQ(tom->isAlive(),1);

    mushi->slash(sushi);
    CHECK_EQ(sushi->getNumHits(),108);

    CHECK_EQ(tom->getNumHits(),110);

    sushi->slash(mushi);
    CHECK_EQ(mushi->getNumHits(),89);

    CHECK_EQ(yogi->getNumHits(),100);
    mushi->slash(yogi);
    CHECK_EQ(yogi->getNumHits(),69);



}

// TEST_CASE("Change leader"){


//     Point a(32.3,44),b(1.3,3.5),c(70.5,60.0);
//     Cowboy *tom = new Cowboy("Tom", a);
//     OldNinja *sushi = new OldNinja("sushi", b);
//     YoungNinja *mushi = new YoungNinja("mushi", b);

//     Team team_A(tom);

// }


}

