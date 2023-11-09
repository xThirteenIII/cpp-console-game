#ifndef _WIZARDFACTORY_H_
#define _WIZARDFACTORY_H_

#include "AbstractEntityFactory.h"
#include "AbstractEntityStats.h"

class WizardFactory: public EntityFactory{
    public:
        AbstractEntityStats* createCharacter() const override;
        AbstractEntityStats* createEnemy() const override;

};
#endif
