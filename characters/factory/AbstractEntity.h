#ifndef _ABSTRACTENTITY_H_
#define _ABSTRACTENTITY_H_

#include <utility>
#include "../states/CharacterState.h"
#include "../../combat/Attack.h"

class AbstractEntity{
    public:
        // Defining a default virtual destructor for an abstract class is a good practice when you have virtual
        // functions or any other virtual methods.
        // This ensures that the correct destructors are called when objects 
        // are deleted through pointers to the base class.
        virtual ~AbstractEntity(){};

        // Getters
        // Coommon methods between entities
        virtual int getHealthPoints() const = 0;
        virtual int getArmorPoints() const = 0;
        virtual Attack* getCurrentAttack() const = 0;
        virtual CharacterState* getCurrentState() const = 0;
        virtual CharacterState* getPreviousState() const = 0;
        virtual std::pair<int, int> getPosition() const = 0;
        virtual void setAttackType(AttackType type) = 0;
        virtual void addAttack(Attack* attack) = 0;

        virtual void takeDamage(int damage) = 0;

        // Attack is not passed as parameter since it's changed based on the 
        // user selection
        virtual void performAttack(AbstractEntity* entity) = 0;

        virtual void setState(CharacterState* newState) = 0;
        virtual void move(int deltaX, int deltaY) = 0;
        virtual bool isAlive() const = 0;
        
        /** 
         * std::pair is defined as follows:
         * namespace std {
         *  template <class T1, class T2>
         *   struct pair {
         *       T1 first;
         *       T2 second;
         *       // Constructors and member functions...
         *   };
         * }
         * std::pair<int, int> position = {3, 4};
         * int x = position.first;  // Access the X coordinate
         * int y = position.second; // Access the Y coordinate
         *
         */
};

#endif
