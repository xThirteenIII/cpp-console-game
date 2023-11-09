#ifndef _WIZARDFACTORY_H_
#define _WIZARDFACTORY_H_

#include "AbstractEntityFactory.h"
#include "AbstractEntity.h"

class WizardFactory: public EntityFactory{
    public:
        AbstractEntity* createCharacter() const override;
        AbstractEntity* createEnemy() const override;

};
#endif
