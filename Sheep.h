#ifndef SHEEP_H
#define SHEEP_H
#include "Animal.h"

class Sheep : public Animal
{
public:
    static const int price = 5;
    Sheep();
    ~Sheep();
};


#endif