#ifndef CHICKENFARM_H
#define CHICKENFARM_H
#include "Farm.h"
#include <vector>

class ChickenFarm : public Farm
{
public:
    ChickenFarm();
    ~ChickenFarm();
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