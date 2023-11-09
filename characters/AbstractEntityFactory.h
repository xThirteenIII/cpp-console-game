#ifndef _ENTITYFACTORY_H_
#define _ENTITYFACTORY_H_
#include "AbstractEntity.h"

class EntityFactory{
    public:
        // is the destructor necessary?
        // virtual ~EntityFactory() = default;
        virtual AbstractEntity* createCharacter() const = 0;
        virtual AbstractEntity* createEnemy() const = 0;

};

#endif
