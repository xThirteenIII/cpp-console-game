#ifndef _ABSTRACTMENU_H_
#define _ABSTRACTMENU_H_

#include <utility>
#include <vector>
#include <string>

class AbstractMenu{
    public:
        // Defining a default virtual destructor for an abstract class is a good practice when you have virtual
        // functions or any other virtual methods.
        // This ensures that the correct destructors are called when objects 
        // are deleted through pointers to the base class.
        virtual ~AbstractMenu(){};

        // Getters
        // Coommon methods between menus
        virtual std::vector<std::string> getItems() const = 0;
        virtual int getSelected() = 0;
        virtual void display() const = 0;
};

#endif
