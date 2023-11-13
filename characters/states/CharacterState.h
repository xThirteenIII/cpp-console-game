#ifndef _CHARACTERSTATE_H_
#define _CHARACTERSTATE_H_

class AbstractEntity;

class CharacterState{
    public:
        // By making the destructor of CharacterState virtual,
        // it ensures that when you delete an object of a derived class through a pointer to the base class,
        // the correct destructor is called, preventing memory leaks and undefined behavior.
        virtual ~CharacterState() = default;

        virtual void enter() = 0;
        virtual void update() = 0;
        virtual void exit() = 0;
};
#endif

