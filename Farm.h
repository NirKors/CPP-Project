#ifndef FARM_H
#define FARM_H
#include "Animal.h"
#include <vector>
#include "string"
#include <iostream>
using namespace std;

class Farm
{
protected:
    int money;
    static int ID_count;
    std::vector<Animal*> animals;
    std::vector<int> products; // 0 - milk, 1 - wool, 2 - eggs
    std::vector<Farm*> clients;
public:
    int ID;
    Farm();
    virtual ~Farm();
    virtual void yield()=0;
    virtual void buyAnimals()=0;
    virtual void printinfo() const=0;
    virtual void addClient(Farm *check)=0;
    virtual int purchaseProducts(int selling_amount)=0;
    virtual void sellProducts()=0;

    virtual void handleCowFarm(Farm *f)=0;
    virtual void handleSheepFarm(Farm *f)=0;
    virtual void handleChickenFarm(Farm *f)=0;
    bool inClients(const Farm *f) const;
    void subscribe(Farm *f);
};
#endif