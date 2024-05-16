#ifndef ANIMAL_H
#define ANIMAL_H


class Animal
{
    int current_age;
protected:
    int death_age;
public:
    Animal();
    ~Animal();
    bool age();
    int getAge() const;
};







#endif