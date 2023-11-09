#ifndef _WARRIORFACTORY_H_
#define _WARRIORFACTORY_H_
#include "AbstractEntityFactory.h"
#include "AbstractEntity.h"

class WarriorFactory: public EntityFactory{
    public:
        AbstractEntity* createCharacter() const override;
        AbstractEntity* createEnemy() const override;

};
#endif
