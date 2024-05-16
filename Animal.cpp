#include "Animal.h"

Animal::Animal()
{
    current_age = 0;
}
Animal::~Animal(){}


int Animal::getAge() const
{
    return current_age;
}


bool Animal::age()
{
    current_age++;
    if (current_age == death_age)
        return true;
    return false;
}