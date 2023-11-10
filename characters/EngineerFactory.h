#ifndef _ENGINEERFACTORY_H_
#define _ENGINEERFACTORY_H_
#include "AbstractEntityFactory.h"
#include "AbstractEntity.h"

class EngineerFactory: public EntityFactory{
    public:
        AbstractEntity* createCharacter() const override;
        AbstractEntity* createEnemy() const override;

};
#endif
