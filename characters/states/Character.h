#include "CharacterState.h"

class Character{
    private:
        CharacterState* currentState_;
        CharacterState* previousState_;
    public:
        Character();
        ~Character();

        void setState(CharacterState* newState);
};
