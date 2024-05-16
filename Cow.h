#ifndef COW_H
#define COW_H
#include "Animal.h"

class Cow : public Animal
{
public:
    static const int price = 10;
    Cow();
    ~Cow();
};


#endif