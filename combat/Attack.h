#ifndef _ATTACK_H_
#define _ATTACK_H_
#include "AttackType.h"

class Attack{
    public:
        AttackType type;
        int damage;
        int hitChance;
};
#endif
