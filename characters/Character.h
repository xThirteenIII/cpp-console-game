#ifndef _CHARACTER_H_
#define _CHARACTER_H_

class Character{
    protected:
        int x;
        int y;
    public:
        Character();
        Character(int x, int y);
        virtual void move(int deltaX, int deltaY) = 0;

        // Getters
        int getX() const {return x;}
        int getY() const {return y;}

        // Insert other common methods as development goes on
};
#endif
