#ifndef _WARRIORFACTORY_H_
#define _WARRIORFACTORY_H_
#include "AbstractEntityFactory.h"
#include "AbstractEntityStats.h"

class WarriorFactory: public EntityFactory{
    public:
        AbstractEntityStats* createCharacter() const override;
        AbstractEntityStats* createEnemy() const override;

};
#endif
