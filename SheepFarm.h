#ifndef SHEEPFARM_H
#define SHEEPFARM_H
#include "Farm.h"
#include <vector>

class SheepFarm : public Farm
{
 
public:
    SheepFarm();
    ~SheepFarm();
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