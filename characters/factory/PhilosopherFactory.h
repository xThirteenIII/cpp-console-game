#ifndef _PHILOSOPHERFACTORY_H_
#define _PHILOSOPHERFACTORY_H_

#include "AbstractEntityFactory.h"
#include "AbstractEntity.h"

class PhilosopherFactory: public EntityFactory{
    public:
        AbstractEntity* createCharacter() const override;
        AbstractEntity* createEnemy() const override;

};
#endif
