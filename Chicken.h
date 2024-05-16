#ifndef CHICKEN_H
#define CHICKEN_H
#include "Animal.h"

class Chicken : public Animal
{
public:
    static const int price = 3;
    Chicken();
    ~Chicken();
};


#endif