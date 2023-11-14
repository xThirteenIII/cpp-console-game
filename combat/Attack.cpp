#include "Attack.h"
#include "AttackType.h"

Attack::Attack():type(AttackType::BASIC),
                 damage(1),
                 hitChance(100){

}

Attack::Attack(AttackType type, int damage, int hitChance)
        :type(type),
        damage(damage),
        hitChance(hitChance){
    
}
