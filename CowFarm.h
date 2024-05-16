#ifndef COWFARM_H
#define COWFARM_H
#include "Farm.h"

class CowFarm : public Farm
{
public:
    CowFarm();
    ~CowFarm();
    void addAnimal(int amount = 1);
    void yield();
    void buyAnimals();
    void printinfo() const;
    int purchaseProducts(int selling_amount);
    void addClient(Farm *check);
    void sellProducts();
    void handleCowFarm(Farm *f);
    void handleSheepFarm(Farm *f);
    void handleChickenFarm(Farm *f);
};

#endif