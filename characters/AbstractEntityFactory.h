#ifndef _ENTITYFACTORY_H_
#define _ENTITYFACTORY_H_
#include "AbstractEntityStats.h"

class EntityFactory{
    public:
        // is the destructor necessary?
        // virtual ~EntityFactory() = default;
        virtual AbstractEntityStats* createCharacter() const = 0;
        virtual AbstractEntityStats* createEnemy() const = 0;

};

#endif
