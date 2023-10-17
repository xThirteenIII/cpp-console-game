#ifndef _MONSTERS_H_
#define _MONSTERS_H_

  //Monsters class declaration

#include <string>
class Monsters{
  
  private:
    std::string name;
    int health;
    int defense;
    int attack;
    int velocity;
    int precision;
  public:
    void makeAttack();
    void killMonster();
};

#endif
